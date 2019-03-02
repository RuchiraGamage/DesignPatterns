#pragma once
#include<string>
using namespace std;

class PersonJobBuilder:PersonBuilder
{
	typedef PersonJobBuilder self;

public:

	explicit PersonJobBuilder(Person& person)
	:PersonBuilder(person){}

	self& at(string company_name) {
		person.company_name = company_name;
		return *this;
	}
	self& as_a(string position) {
		person.position = position;
		return *this;
	}

};