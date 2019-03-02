#pragma once
#include"Builder/Person.h"
#include"Builder/Person.h"

class PersonAddreeBuilder;
class PersonJobBuilder;

class PersonBuilder {
	Person p;

protected:
	Person& person;

	explicit PersonBuilder(Person& person)
		:person{person}{}
public:
	 operator Person(){
		return move(person);
	}
	PersonBuilder()
		:person{p}
	{}
	PersonAddreeBuilder live();
	PersonJobBuilder work();
};
