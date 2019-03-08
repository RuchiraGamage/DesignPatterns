#include<vector>
#include<boost/algorithm/string.hpp>
#include<iostream>

using namespace std;

//this is the interface for the new string
class String 
{
	string s;
public:
	String(string cs):s(cs)
	{
	}

	String to_lower()
	{
		boost::to_lower(s);
		return String{ s };
	}

	vector<string> split(const string& delemeter=" ")
	{
		vector<string> result;
		boost::split(result, s, boost::is_any_of(delemeter));
		return result;
	}
};

/*
int main(int ac,char* av[])
{
String s("Hello world");
auto parts = s.to_lower().split();
for (const auto& p : parts)
cout << "<" << p << ">" << endl;

getchar();
return 0;
}
*/


/*
we can getrid of this using above implimented interface

vector<string> parts;
boost::split(parts, s, boost::is_any_of(" "));//here we dont know actual functions in boost
//but by creating an adapter we can achieve that with some global functions
for (const auto& p : parts)
cout << "<" << p << ">" << endl;
*/