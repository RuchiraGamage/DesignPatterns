#pragma once
#include<memory>
#include<iostream>
#include<string>
#include<vector>

//a machanism for treating individual and composition of objects in a uniform manner
//suppose we want to impliment 2+(3+4) expression

using namespace std;

struct Expression 
{
	virtual double eval() = 0;
	virtual void collect(vector<double>& v) = 0;
};

struct Literal :Expression
{
	double value;
	Literal(const double& val)
		:value(val)
	{
	}

	double eval()override
	{
		return value;
	}
	void collect(vector<double>& v)override
	{
		v.push_back(value);
	}
};

struct AdditionExpression : Expression
{
	shared_ptr<Expression> left, right;
	AdditionExpression(const shared_ptr<Expression>& expression1,const shared_ptr<Expression> expression2)
		:left{expression1},right{expression2}
	{
	}

	double eval()override
	{
		return left->eval() + right->eval();
	}

	void collect(vector<double>& v)override
	{
		left->collect(v);
		right->collect(v);
	}
};

