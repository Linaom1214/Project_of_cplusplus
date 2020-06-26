#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker 
{
public:
	//获取个人信息
	virtual void showinof () = 0;
	//获取岗位信息
	virtual string getDeptName () =0;

	int m_ID;
	string m_Name;
	int m_Deptid ;  //部门编号
protected:
	

private:
};


