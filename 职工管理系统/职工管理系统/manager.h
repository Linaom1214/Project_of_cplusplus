#pragma  once
#include "worker.h"
using namespace std;
#include <iostream>

class Manager:public Worker
{
public:
	Manager(int id,string name,int did);
	~Manager();
	//获取个人信息
	void showinof ( ) ;
	//获取岗位信息
	string getDeptName() ;


protected:
	
private:
};