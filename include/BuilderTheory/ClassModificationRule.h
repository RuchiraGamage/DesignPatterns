#pragma once

#include<string>
#include<vector>
#include<iostream>

enum Color { Green, blue, Yellow };
enum Size { Large, Small };

struct Product
{
	std::string name;
	Color colour;
	Size size;
};


//normally classes are not modified after it define but through abstract interfaces
//we can create that ability for the classes

/*

struct ProductFilter
{
//returmn the products with specified color
typedef std::vector<Product*> Items;
static Items items_by_color(Items items, Color color) {
Items result;
for (auto& i : items)
{
if (i->colour == color)
result.push_back(i);
}
return result;
}

//if customer need to filter by  size then you have to write a another function
//which takes a list of products and return the filtered list

static Items items_by_size(Items item, Size size) {
Items result;
for (auto& i : item)
{
if (i->size == size)
result.push_back(i);
}

return result;
}
//if customer want to return by checking both item color and size then need to write a another function
static Items items_by_size_color(Items item, Size size, Color color) {
Items result;
for (auto& i : item) {
if (i->colour == color && i->size == size)
result.push_back(i);
}
return result;
}
};
//but here above implementation is hard as we need to add multiple time when the customer wants
//the best way to implement that is use abstract classes sperately

*/

//abstract class for specification
template<typename T> struct ISpecification
{
	virtual bool is_satisfied(T* item) = 0;
};

//seperated out each specifications with the implimentation of is_satisfied
struct ColourSpecification :ISpecification<Product>
{
	Color colour;
	explicit ColourSpecification(const Color specificColour) :colour{ specificColour }
	{}
	virtual bool is_satisfied(Product* item) {
		return item->colour == colour;
	}

};

struct SizeSpecification :ISpecification<Product>
{
	Size size;
	explicit SizeSpecification(const Size specificSize) :size(specificSize)
	{
	}

	virtual bool is_satisfied(Product* item) {
		return item->size == size;
	}
};

//this one is a another way to impelment it but you can use above 2 specifications
struct ColorAndSizeSpecification :ISpecification<Product>
{
	Color color;
	Size size;
	explicit ColorAndSizeSpecification(const Color specificColor, const Size specificSize)
		:size(specificSize)
		, color(specificColor)
	{}

	virtual bool is_satisfied(Product* item) {
		return item->colour == color && item->size == size;
	}
};

//use above specifications to build colorAndSizeSpecification
template <typename T> struct AndSpecification : ISpecification<T>
{
	ISpecification<T> first;
	ISpecification<T> second;

	explicit AndSpecification(ISpecification<T>& first, ISpecification<T>& second) :first(first), second(second) {}

	bool is_satisfied(T* item) {
		return (first.is_satisfied(item) && second.is_satisfied(item));
	}

};

template <typename T> struct IFilter
{
	typedef std::vector<T*> Items;
	virtual Items filter(Items item, ISpecification<T>& spec) = 0;
};

struct BetterFilter :IFilter<Product>
{
	Items result;
	virtual Items filter(Items item, ISpecification<Product>& spec) {
		for (auto& i : item)
		{
			if (spec.is_satisfied(i))
				result.push_back(i);
		}
		return result;
	}
};


//btw it is better to know littlebit about 'explicit' key word in c++
/*
when a class is having one private member and within the constructor initialize the variable,suppose we have
a method want that kind of object but you can just pass the method parameter as just the variable value
which you want to pass to the object it implicitly initialize it and pass object to the method

class A{
private:int i;
A(int value):i(value){}
};

void foo(A a);

can call the method-->void(5) //implicitly create the object with value 5 and pass to the method
but this can lead to some problems

ex- suppose you have
class String{int size; return string(with size 3)}

also you have function which print a string object

void printString(const String& s);

suppose you want to really print "3" so you pass 3 to the function so what happen now is it implicitly create a string with size of 3
and print which is not expected by me
to avoid that can use 'explicit'  key word in constructor
you need to create and pass the object by forcely

*/