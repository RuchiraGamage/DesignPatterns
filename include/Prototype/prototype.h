#pragma once
//prototype is copy or clone fully or partially created object and make use of it;
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Address
{
	string street;
	string city;
	int roomNo;
	//here default copy constructor is ok because it copy the content of variables no memory addresses
	//shallo copy ok here

	Address(const string& st,const string& cit,const int& room)
		:street{ st }, city{ cit }, roomNo{room} {}

	friend ostream& operator <<(ostream& oss,const Address& addr)
	{
		oss << " " << addr.roomNo << " " << addr.street << " " << addr.city << endl;
		return oss;
	}

};

struct Person {
	string name;
	Address* work_address;
	//here default copy constructor is not ok because it copy a same memory address for each copy
	//that can be lead to some faults

	Person(const string& name, Address* add) 
		:name{ name }, work_address{ new Address{*add} }//derectly not initialize the in comming address but copy the content of it to new heap memory location
	{
	}

	Person(Person& person) 
		:name{person.name}
		,work_address{new Address{*(person.work_address)}}
	{
	}

	friend ostream& operator <<(ostream& oss,Person& p)
	{
		oss << " " << p.name<< " " << *(p.work_address) << endl;
		return oss;
	}

	~Person()
	{
		delete work_address;
	}

};

struct PersonFactory
{
	static Person main, aux;//theese are prototypes which impliments outside the class 
	static unique_ptr<Person> mainOfficeEmployee(string name,int roomNo) {
		return newEmployeee(name, roomNo, main);
	}
	static unique_ptr<Person> auxOfficeEmployee(string name, int roomNo) {
		return newEmployeee(name, roomNo, aux);
	}
private:
	static unique_ptr<Person> newEmployeee(string name,int roomNo,Person proto){
		auto result= make_unique<Person>(proto);
		result->name = name;
		result->work_address->roomNo = roomNo;
		return result;
	}

};
Person PersonFactory::main{ "",new Address{"galle road","colombo",0} };
Person PersonFactory::aux{ "",new Address{ "kandy road","colombo",0 } };

