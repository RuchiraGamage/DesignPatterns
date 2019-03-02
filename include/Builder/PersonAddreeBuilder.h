#pragma once
#include<string>
#include"Builder/PersonBuilder.h"
using namespace std;

class PersonAddreeBuilder  :PersonBuilder
{
	typedef PersonAddreeBuilder self;

public:
	explicit PersonAddreeBuilder(Person& person)
	:PersonBuilder(person)
	{}

	self& at(string street_address){
		person.street_address = street_address;
		return *this;
	}
	self& with_postcode(string post_code) {
		person.position = post_code;
		return *this;
	}
	self& city(string city) {
		person.city = city;
		return *this;
	}
};