#pragma once  //防止头文件重复
#include <iostream>
#include "Person.h"
#include <fstream>
#define File_Name  "data.txt"
using namespace std;
class Addressbooks
{
public:
	Addressbooks();
	~Addressbooks();
	void show_menu();
	void exit_system();
	//记录数据 数组
	Person** p_array;
	//记录人数
	int m_num;
	//添加数据函数
	void add_Person();
	//写入本地数据
	void save_data();
	//记录文件状态
	bool file_empty;
	//获取文件中的数据量
	int get_num();
	//初始化
	void init();
	//显示
	void show();
	//删除信息
	void del_person();
	//查找职工
	int is_exist();
	//查找显示
	void find();
	//清空
	void destory();
private:

};


