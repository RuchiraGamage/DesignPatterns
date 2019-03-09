#pragma once
#include<string>
//here actually can use to split interface with actual implimentation hierachy
//that is decoupling abstrction and implimentation

class Person 
{
	//here we dont change the interface but hide the implimentation
public:
	std::string name;

	struct PersonImpl;
	PersonImpl * impl;

	Person();
	~Person()
	{
		delete impl;
	}

	void greed();
};
