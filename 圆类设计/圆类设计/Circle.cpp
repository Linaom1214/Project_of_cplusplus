#pragma once 
#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;


// Circle(/* args */)
//  {
// 	 c_x =0.0;
// 	 c_y = 0.0;
// 	 r = 0;
//  }
// ~Circle() {}
void Circle::set_c(Point &C)
{
	c= C;
}
void Circle::set_R(double R)
{
	r =R;
}

double Circle::get_c_x()
{
		
	return c.get_p_x();
}

double Circle::get_c_y()
{
	return c.get_p_y();
}

void Circle::detectPosition(Point *p)
{
	double range =sqrt(
		pow(abs(p->get_p_x()-get_c_x()),2)+pow(abs(p->get_p_y()-get_c_y()),2)
		);
	if (range < r)
		cout<<"该点在圆内"<<endl;
	else if (range == r)
	{
		cout<<"该点在圆上"<<endl;
	}
	else
	{
		cout<<"该点在圆外"<<endl;
	}
}
