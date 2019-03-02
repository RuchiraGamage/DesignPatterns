#pragma once

#include<math.h>
#include<ostream>

using namespace std;
/*
//this the normal way we develop same object for different parameters
enum PointType {
carticean,
polar
};

class Point {
public:
float x, y;
Point(const float a,const float b,const PointType p=PointType::carticean)
{
if (p == carticean)
{
x = a;
y = b;
}
else
{
x = a * cos(b);
y = b * sin(a);
}
}

};


*/


class Point 
{
	Point(float a, float b)
		:x{a},y{b}
	{}

	class PointFactory {//inner factory
	public:
		static Point createCarteseanPoint(float x, float y)
		{
			Point p(x, y);
			return p;
		}

		static Point createPolarPoint(float r, float theta)
		{
			Point p(r*cos(theta), r*sin(theta));
			return p;
		}
	};
public:
	float x, y;

	friend ostream& operator <<(ostream& oss,const Point& p)
	{
	
		oss << "x=" << p.x << " " << "y=" << p.y << endl;

		return oss;
	}

	static PointFactory factory;
};

//when we have multiple factories we can go for the abstrct factories which pase factory classes
//inherit from abstract factory 

/*
ex-

class AbstractDrinkFactory
{
public:
virtual unique_ptr<Drink> drink()=0;
}
*/

