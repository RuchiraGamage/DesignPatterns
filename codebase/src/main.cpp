//#include"BuilderTheory/Creational_Builder.h"
//#include"BuilderTheory/ClassModificationRule.h"
#include<iostream>
#include <vector>
#include <string>
#include <sstream>
#include<boost/serialization/serialization.hpp>
#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

using namespace std;

/*
#include "Builder/Person.h"
#include "Builder/PersonBuilder.h"
#include "Builder/PersonAddreeBuilder.h"
#include"Builder/PersonJobBuilder.h"

#include"Factory/Point.h"

*/
//#include"Prototype/prototype.h"

struct Address
{
	string street, city;
	int suit;

	friend ostream& operator<<(ostream& oss,Address& address)
	{
		return oss << " city :" << address.city << " street :" << address.street << " suit :" << address.suit;
	}
private:
	friend class boost::serialization::access;

	template<class Ar>void serialize(Ar& ar,const unsigned int version)
	{
		ar & street;
		ar & city;
		ar & suit;
	}
};
struct  Contact
{
	string name;
	Address addr;

	friend ostream& operator<<(ostream& oss, Contact& contact)
	{
		return oss << " name :" << contact.name << " Address :" << contact.addr;
	}
private:
	friend class boost::serialization::access;

	template<class Ar>void serialize(Ar& ar, const unsigned int version)
	{
		ar & name;
		ar & addr;
	}
};


int main()
{
	Contact jane;
	jane.name = "jane";
	jane.addr=Address{ "colombo road","Galle",10};

	auto clone=[](Contact c)
	{
		ostringstream oss;
		boost::archive::text_oarchive oa(oss);
		oa << c;

		string s = oss.str();
		Contact result;
		istringstream iss(s);
		boost::archive::text_iarchive ia(iss);
		ia >> result;
		return result;
	};

	Contact john = clone(jane);

	john.name = "john";
	john.addr.suit = 125;

	cout << jane << john << endl;

	getchar();
	return 0;
}

/*

//BuilderTheory

1....
Product p1{ "alpple",Color::Green,Size::Large };
Product p2{ "orange",Color::Green,Size::Large };
Product p3{ "pinapple",Color::blue,Size::Small };

std::vector<Product*> p{&p1,&p2,&p3};

SizeSpecification s(Size::Large);
BetterFilter be;
auto result=be.filter(p,s);

for(auto& i:result){
std::cout << i->name << std::endl;
}

*/


/*
2....

HtmlBuilder eb("First");
eb.add_child("second", "text").add_child("third", "text");

auto str=eb.root.str();
std::cout << str << std::endl;

3....

cout<< P{
IMG{ "https//:-abcdefg.com" }
} << endl;

*/



/*

Builder

Person p = Person::create()
.live().at("galle").with_postcode("10101").city("galle")
.work().at("simcentric").as_a("software engineer");

cout << p << endl;

*/


/*
//prototype design pattern

Person protoTypePerson{ "",new Address{"galle road","galle",10}};//this is the phototype we can use it
//then as it does not duplicate the memory addresses as we impliments copy constructors.

Person mihili = protoTypePerson;
mihili.name = "Mihili";
mihili.work_address->city = "galle";
mihili.work_address->street = "ram part road";
mihili.work_address->roomNo = 10;

Person Ruchira = protoTypePerson;
Ruchira.name = "Ruchira";
Ruchira.work_address->city = "Sydney";
Ruchira.work_address->street = "melborn road";
Ruchira.work_address->roomNo = 10;

cout << mihili << endl;
cout << Ruchira << endl;

2)..

auto oo = PersonFactory::mainOfficeEmployee("Mihili", 10);
auto ru = PersonFactory::auxOfficeEmployee("Ruchira", 10);

cout << *oo << endl << *ru;

*/

//in c++ all the static things has to be outside of the class(actually implimentation)