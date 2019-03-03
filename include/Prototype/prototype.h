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
//shallow copy is always not agood option as if there is a pointer kind of thing it can lead to many problems
//(if you copy pointer instead of its content it may create more problems)
//deep copy is copy the content to a new memory location can be more safe

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
	static unique_ptr<Person> newEmployeee(string name,int roomNo,Person& proto){
		auto result= make_unique<Person>(proto);
		result->name = name;
		result->work_address->roomNo = roomNo;
		return result;
	}

};
//c++ all the static iplimentations has to be outside of the class
Person PersonFactory::main{ "",new Address{"galle road","colombo",0} };
Person PersonFactory::aux{ "",new Address{ "kandy road","colombo",0 } };


//add below part to main to run above code also make sure to include header

/*
//main clause related to this implimentation
int main()
{
auto auxEmployee1=PersonFactory::auxOfficeEmployee("kamal", 10);
auto mainEmployee1 = PersonFactory::mainOfficeEmployee("kusum", 11);
}
*/

