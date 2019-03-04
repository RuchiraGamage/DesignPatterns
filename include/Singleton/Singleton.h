#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<boost/lexical_cast.hpp>
//to make design siple here onwords i use heder for the perticular design pattern and its imlimentation and 
//main function also within the same folde under cpp file

//singleton allow us to intantiate a object once,we can achieve that by making constructor private,deleting copy
//constructor and assignment operator

class Database 
{
public:
	virtual int get_population(const std::string& name) = 0;
};


class SingletonDatabase: public Database
{
	SingletonDatabase() //private constructor we cant really instantiate
	{
		std::cout << "initializing database" << std::endl;
		std::ifstream ifs("cityPopulation.txt");

		std::string s, s2;

		while (std::getline(ifs,s))
		{
			std::getline(ifs, s2);
			int pop = boost::lexical_cast<int>(s2);
			capitals[s] = pop;
		}

		for (std::map<std::string, int>::iterator itr=capitals.begin();itr!=capitals.end();itr++)
		{
			std::cout << itr->first << std::endl;
		}
		instance_count++;
	}
	std::map<std::string, int> capitals;

	//static SingletonDatabase* instance;
public:
	SingletonDatabase(SingletonDatabase const&) = delete;
	void operator=(SingletonDatabase const&) = delete;

	static int instance_count;

	//belove problem (not thread safety can achieve by using static implimentation of c++)
	//c++ allow allocation within functions,not like java or c#

	static SingletonDatabase& get()
	{
		static SingletonDatabase db;//statically allocate singletondatabase object within a function 
		//which happen only once which is more thread safety,this invocation only happen once
		return db;
	}

	int get_population(const std::string& name)override
	{
		return capitals[name];
	}

/*
	static SingletonDatabase* get_instance()
	{
	if (!instance)
	instance = new SingletonDatabase;
	return instance;
	//the problem here with singleton is this is not thread safety
	}
*/
};

int SingletonDatabase::instance_count = 0;

class DummyDatabase: public Database
{
public:
	std::map<std::string, int> capitals;

	DummyDatabase()
	{
		capitals["city1"] = 100;
		capitals["city2"] = 300;
		capitals["city3"] = 400;
	}

	int get_population(const std::string& name)override
	{
		return capitals[name];
	}
};

struct SingletonRecordFinder 
{
	int total_population(std::vector<std::string> names)
	{
		int total_population = 0;
		for(auto& name:names)
		{
			total_population += SingletonDatabase::get().get_population(name);//here the problem is we 
			//have to  hardcord the database here to avoid that below implimentation can apply
		}
		return total_population;
	}
};


//this anyDBRecordFinder is much more flexible,we can feed any database here
struct anyDBRecordFinder
{
	Database& db;
	explicit anyDBRecordFinder(Database& DB)
	:db(DB)
	{
	}
	int total_population(std::vector<std::string> names)
	{
		int total_population = 0;
		for (auto& name : names)
		{
			total_population += db.get_population(name);
		}
		return total_population;
	}
};

//btw most cases dependancy injection can be used rather than manually create object and past,
//ex:- using c++ boost DI library

//the point is safe singleton is easy ,just make a static variable and return a reference to it