#pragma once 
#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(/* args */)
	{
		p_x =0.0;
		p_y =0.0;
	}

void Point::set_p_x(double y)
{
	p_y = y;
}
void Point::set_p_y(double y)
{
	p_y = y;
}

double Point::get_p_x()
{
	return p_x;
}
double Point::get_p_y()
{
	return p_y;
}


