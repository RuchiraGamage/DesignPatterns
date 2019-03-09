#include"Bridge/Bridge.h"
#include<iostream>

struct Person::PersonImpl
{
	void greed(Person* p);
};

void Person::PersonImpl::greed(Person* p)
{
	std::cout << "impl implimentation :" <<p->name<< std::endl;
}

Person::Person()
	:impl(new PersonImpl)
{
}

void Person::greed()
{
	impl->greed(this);
}

int main()
{
	Person p;
	p.name = "kamal";
	p.greed();
	getchar();
	return 0;
}