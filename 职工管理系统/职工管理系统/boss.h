#pragma  once
#include "worker.h"
using namespace std;
#include <iostream>

class Boss:public Worker
{
public:
	Boss(int id,string name,int did);
	~Boss();
	//获取个人信息
	void showinof ( ) ;
	//获取岗位信息
	string getDeptName() ;


protected:

private:
};