#pragma once

//we can use serialization for copy a obect as text stream or byte order and deserialize to again a object 
//using boost::serialize:: functions like
//text_oarchive()
//text_iarchive() etc...

//this is the example code which used to serialize a object

/*
#include<iostream>
#include <vector>
#include <string>
#include <sstream>
#include<boost/serialization/serialization.hpp>
#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/text_oarchive.hpp>

using namespace std;

struct Address
{
string street, city;
int suit;

friend ostream& operator<<(ostream& oss, Address& address)
{
return oss << " city :" << address.city << " street :" << address.street << " suit :" << address.suit;
}
private:
friend class boost::serialization::access;

template<class Ar>void serialize(Ar& ar, const unsigned int version)
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
jane.addr = Address{ "colombo road","Galle",10 };

auto clone = [](Contact c)
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
*/
