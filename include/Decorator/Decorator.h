#pragma once
#include<memory>
#include<iostream>
#include<string>
#include<vector>
#include <functional>

//decorator pattern is for adding functionality to a single object with out affecting to a anither object of the same class

struct Logger
{
	std::function<void()> func;//store a void function
	std::string name;

	Logger(std::function<void()>& function, std::string& n)
		:func(function), name(n)
	{
	}
	//function call operator
	void operator()() const
	{
		std::cout << "Entering" << std::endl;
		func();
		std::cout << "Exiting" << std::endl;
	}
};

template<typename Func>
struct Logger2
{
	Func func;//store a void function
	std::string name;

	Logger2(Func function, std::string& n)//constructor can not directly initialize with a lambda
		:func(function), name(n)
	{
	}
	//function call operator
	void operator()() const
	{
		std::cout << "Entering" << std::endl;
		func();
		std::cout << "Exiting" << std::endl;
	}
};

template<typename Func>
auto make_Logger(Func func, const string& name)
{
	return Logger<Func>{func, name};
}

template<typename> struct Logger3;

template<typename R, typename ...Args>//here typename for return value and additional argumants
struct Logger3
{
	std::function<R(Args...)> func;
	std::string name;

	Logger3(std::function<R(Args...)>& function, std::string& n)
		:func(function), name(n)
	{
	}
	R operator ()(Args ...args)
	{
		std::cout << "entering" << std::endl;
		R result = func(args...);
		std::cout << "exiting" << std::endl;
		return result;
	}
};

template<typename R, typename... Args>
auto make_logger3(R(*func)(Args...), const std::string& name)
{
	return Logger3<R(Args...)>{std::function<R(Args...)>(func), name};
}

double add(double a, double b) 
{ 
	return a + b; 
}

//# exmple 2

