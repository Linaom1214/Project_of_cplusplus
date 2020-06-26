#pragma once 
#include <iostream>
#include "Point.h"
using namespace std;
class Circle
{
private:
	Point c;   //在一个类中可以用另一个类
	// double c_x;
	// double c_y;
	double r;
public:
	// Circle(/* args */)
	//  {
	// 	 c_x =0.0;
	// 	 c_y = 0.0;
	// 	 r = 0;
	//  }
	// ~Circle() {}
	void set_c(Point &C);

	void set_R(double R);


	double get_c_x();

	double get_c_y();


	void detectPosition(Point *p);

};
