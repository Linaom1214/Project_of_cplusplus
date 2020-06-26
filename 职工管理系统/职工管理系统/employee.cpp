#include <iostream>
#include "employee.h"

Employee::Employee(int id,string name,int did)
{
	this-> m_ID= id;
	this->m_Name= name;
	this-> m_Deptid = did ;  //部门编号

}
//获取个人信息
void Employee::showinof ( ) 
{

	cout<<"职工编号"<<this->m_ID 
		<<"\t职工姓名"<<this->m_Name
		<<"\t岗位"<<this->getDeptName() 
		<<"\t岗位职责：员工"<<endl;
}
//获取岗位信息
string Employee::getDeptName() 
{
	return "员工";
}