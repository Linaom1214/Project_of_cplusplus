#pragma once 
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"


#include <fstream>
#define  FILENAME   "empfile.txt"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	//显示菜单
	void show_Menu() ;
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker **m_EmpArray ;
	//添加函数
	void Add_Emp();

	void save();

	//
	bool m_FileisEmpty;

	int getNum( ) ;

	void  init_Emp();


	void show();


	int  isExist(int id);
	//删除联系人
	void deleteEmp();

	void Mod_Emp();


	void Find_Emp();

	//选择排序

	void Sort_Emp();


	void Clear_File();
protected:
	
private:
};

