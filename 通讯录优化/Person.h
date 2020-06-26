#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person
{
public:
	Person() {};
	Person(string name, string number);
	void show_info() const;
	string name;
	string   number;
};