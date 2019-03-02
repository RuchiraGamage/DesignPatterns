#pragma once
#include<string>

using namespace std;

class PersonBuilder;
//forward diclaration is kind of cheating compiler that this is exists so compilation is ok;

class Person {
	//address
	string street_address, post_code, city;

	//employment
	string company_name, position;

	int annual_income = 0;

	Person() {}

public:

	Person(Person&& other) //move constructor
		:street_address(move(other.street_address)), post_code(move(other.post_code)), city(move(other.city))
		, company_name(move(other.company_name)), position(move(other.position)), annual_income(other.annual_income)
	{}

	Person& operator=(Person&& other)//copy constructor
	{
		if (this == &other)
			return *this;
		street_address = move(other.street_address);
		post_code = move(other.post_code);
		city = move(other.city);
		company_name = move(other.company_name);
		position = move(other.position);
		annual_income = other.annual_income;
		return *this;
	}

	friend ostream& operator<<(ostream& oss,const Person& person)
	{
		oss << person.annual_income;
		oss << person.annual_income;
		oss << person.company_name;
		oss << person.post_code;
		oss << person.street_address;
	}

	static PersonBuilder create();

	friend class PersonBuilder;
	friend class PersonAddreeBuilder;
	friend class PersonJobBuilder;
};

