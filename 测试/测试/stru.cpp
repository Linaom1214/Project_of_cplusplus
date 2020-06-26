#include <iostream>
#include <set>
#include <string>
using namespace std;
//set容器的排序
//内置数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = age;
		this->m_age = age;
	}
	string m_Name;
	int m_age;
};
//自定义数据
class ComparePerson
{
public:
	bool operator()(const Person &p1 ,const Person &p2)
	{
		//年龄降序
		return p1.m_age>p2.m_age ;
	}
};
void test02( )
{
	set<Person,ComparePerson> s;
	Person p1("张三", 20);
	Person p2("李四", 21);
	Person p3("王五", 60);
	Person p4("赵六", 24);
	Person p5("老吴", 50);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	for (set<Person,ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout<<"姓名："<<it->m_Name<<" 年龄："<<it->m_age<<endl;
	}
}
int main()
{
	test02();
	return 0;
}