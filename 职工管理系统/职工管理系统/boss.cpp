#include "boss.h"

Boss::Boss(int id,string name,int did)
{
	this-> m_ID= id;
	this->m_Name= name;
	this-> m_Deptid = did ;  //部门编号

}
//获取个人信息
void Boss::showinof ( ) 
{

	cout<<"职工编号"<<this->m_ID 
		<<"\t职工姓名"<<this->m_Name
		<<"\t岗位"<<this->getDeptName() 
		<<"\t岗位职责：老板"<<endl;
}
//获取岗位信息
string Boss::getDeptName() 
{
	return "老板";
}