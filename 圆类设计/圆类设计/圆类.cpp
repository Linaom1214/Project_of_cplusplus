#include <iostream>
#include <string>
#include <cmath>
#include "Circle.h"
#include "Point.h"
using namespace std;
//
//class Point
//{
//private:
//	double p_x ;
//	double p_y;
//	/* data */
//public:
//	Point(/* args */)
//	 {
//		 p_x =0.0;
//		 p_y =0.0;
//	 }
//	~Point() {}
//
//	void set_p_x(double y)
//	{
//		p_y = y;
//	}
//	void set_p_y(double y)
//	{
//		p_y = y;
//	}
//
//	double get_p_x()
//	{
//		return p_x;
//	}
//	double get_p_y()
//	{
//		return p_y;
//	}
//};
//
//class Circle
//{
//private:
//	Point c;   //在一个类中可以用另一个类
//	// double c_x;
//	// double c_y;
//	double r;
//public:
//	// Circle(/* args */)
//	//  {
//	// 	 c_x =0.0;
//	// 	 c_y = 0.0;
//	// 	 r = 0;
//	//  }
//	// ~Circle() {}
//	void set_c(Point &C)
//	{
//		c= C;
//	}
//	void set_R(double R)
//	{
//		r =R;
//	}
//
//	double get_c_x()
//	{
//		
//		return c.get_p_x();
//	}
//
//	double get_c_y()
//	{
//		return c.get_p_y();
//	}
//
//	void detectPosition(Point *p)
//	{
//		double range =sqrt(
//			pow(abs(p->get_p_x()-get_c_x()),2)+pow(abs(p->get_p_y()-get_c_y()),2)
//			);
//		if (range < r)
//			cout<<"该点在圆内"<<endl;
//		else if (range == r)
//		{
//			cout<<"该点在圆上"<<endl;
//		}
//		else
//		{
//			cout<<"该点在圆外"<<endl;
//		}
//		
//		
//	}
//};

int main()
{	
	Circle c;
	Point center ;
	center.set_p_x(0.0);
	center.set_p_y(0.0);
	c.set_c(center);

	Point p;
	p.set_p_x(0.0);
	p.set_p_y(1.0);

	c.detectPosition(&p);

	return 0; 
}

