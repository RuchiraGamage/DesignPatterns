#pragma once
#include<memory>
#include<iostream>
#include<string>
#include<vector>

struct GeomatricShape
{
	virtual void draw() = 0;
};

struct Circle : GeomatricShape
{
	void draw()override
	{
		std::cout << "circle" << std::endl;
	}
};

struct Group :GeomatricShape
{
	std::string name;
	std::vector<GeomatricShape*> objects;

	Group(const std::string& n)
		:name(n)
	{}

	void draw()override
	{
		std::cout << "Group :" <<name.c_str()<< std::endl;
		for (auto&& x : objects)
			x->draw();
	}
};

//here it has simplified whether it is a composite objects or objects with pure vertual function draw()
//dont need to worry about which part of API to call

