#include "Person.h"
Person::Person(string name, string number)
{
	this->name = name;
	this->number = number;
}
void Person::show_info() const
{
	cout << "ÐÕÃû£º " << this->name << " ºÅÂë: "<<this->number << endl;
}