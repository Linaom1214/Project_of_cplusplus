#pragma once 
#include <iostream>

using namespace std;
class Point
{
private:
	double p_x ;
	double p_y;
	/* data */
public:
	Point(/* args */);

	void set_p_x(double y);

	void set_p_y(double y);


	double get_p_x();

	double get_p_y();

};

