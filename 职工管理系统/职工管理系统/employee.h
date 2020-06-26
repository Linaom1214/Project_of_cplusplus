#pragma  once 
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id,string name,int did);
	//获取个人信息
	void showinof ( ) ;
	//获取岗位信息
	string getDeptName() ;

protected:
private:
};