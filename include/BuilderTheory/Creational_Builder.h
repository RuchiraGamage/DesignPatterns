#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//suppose you need to create a builder to generate HTML code
struct HtmlElement
{
	string name;
	string text;
	vector<HtmlElement> elements;
	const size_t intdent_size = 2;

	HtmlElement() {}

	HtmlElement(const string& name, const string& text) :name{ name }, text{ text }
	{}

	string str(int intdent = 0)const
	{
		ostringstream oss;
		string i(intdent_size*intdent, ' ');

		oss << i << "<" << name << ">" << endl;

		if (text.size() > 0)
			oss << string(intdent_size*(intdent + 1), ' ') << text << endl;

		for (const auto& e : elements)
			oss << e.str(intdent + 1);

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}
};


struct HtmlBuilder
{
	HtmlBuilder(string name) {
		root.name = name;
	}
	HtmlElement root;

	HtmlBuilder& add_child(string child_name, string child_text)
	{
		HtmlElement e{ child_name,child_text };
		root.elements.emplace_back(e);
		//here it's better to knoow littlebit about empace_back bcz when compare with push_back
		//it is optimized
		//empace_back(Arg&&....)it can take variable argument and can create object like things inside it
		//it avoid unnessary copies like push_back()

		//it can forword the argument--that means not doing something here but do latter

		//as aexample lot of unnessary copies happen std::map<>
		//ex- 

		/*
		std::map<int, Complicated> m;
		int anInt = 4;
		double aDouble = 5.0;
		std::string aString = "C++";

		// cross your finger so that the optimizer is really good
		m.insert(std::make_pair(4, Complicated(anInt, aDouble, aString)));

		//here copy happen few times from object to std::pair then to inser() to map it is terrible

		// should be easier for the optimizer
		m.emplace(4, anInt, aDouble, aString);
		*/
		return *this;
	}

};

struct Tag {
	string name;
	string test;
	vector<Tag> children;
	vector<pair<string, string>> attribute;

	friend ostream& operator<<(ostream& oss, const Tag& tag) {

		oss << "<" << tag.name << " ";

		for (const auto& i : tag.attribute)
			oss << " " << i.first << "=" << i.second;


		if (tag.children.size() == 0 && tag.test.length() == 0)
		{
			oss << ">" << endl;
		}
		else {
			oss << ">" << tag.test << endl;

			for (const auto& i : tag.children) {
				oss << i;
			}

			oss << "<" << tag.name << ">" << endl;
		}

		return oss;
	}
protected:
	Tag(const string& name, const string& text)
		:name{ name },
		test{ text }
	{}
	Tag(const string& name, const vector<Tag>& children)
		:name{ name },
		children{ children }
	{}

};

struct  P :Tag
{
	explicit P(const string& text)
		:Tag("P", text)
	{
	}

	P(initializer_list<Tag> children)
		:Tag("p", children) {  //initializer_list actually can feed to a vector 
	}


};

struct IMG :Tag {
	explicit IMG(const string& url)
		:Tag("img", "")
	{
		attribute.emplace_back(make_pair("src", url));
	}
};


//it is better to know about initializer list directly array of objects pass
//to a member variable ex-{obj1,obj2,obj3...]
/*

#include <iostream>
#include <vector>
#include <initializer_list>

template <class T>
struct S {
std::vector<T> v;
S(std::initializer_list<T> l) : v(l) {
std::cout << "constructed with a " << l.size() << "-element list\n";
}
void append(std::initializer_list<T> l) {
v.insert(v.end(), l.begin(), l.end());
}
};

int main()
{
S<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
s.append({6, 7, 8});      // list-initialization in function call
getchar();
return 0;
}
*/
