#include <iostream>
#include <string>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
 using namespace std;
int main()
{
	////实例化对象
	//Worker *worker = NULL;
	//worker = new Boss(1,"张三",1);
	//worker->showinof();
	WorkerManager  wm;
	

	int choice = 0;
 
	while (true)
	{
		wm.show_Menu();
		cout<<"输入你的选择"<<endl;
		cin>>choice;
		
		switch (choice)
		{
		case 0:  //退出
			{
				wm.ExitSystem();
				break;
			}
		case 1: //增加    保存信息到文件
			wm.Add_Emp();
			break;
		case 2: //显示
			wm.show();
			break; 
		case 3: //删除
		{
			wm.deleteEmp();
			//cout<<"输入要离职的职工编号"<<endl;
			//int  id = 0;
			//cin >>id;
			//cout<<((wm.isExist(id) ==-1)?"不存在 ":"存在")<<endl;
			break;
		}
		case 4: //修改
			wm.Mod_Emp();
			break;
		case 5: //查找
			wm.Find_Emp();
			break;
		case 6://排序
			wm.Sort_Emp();
			break;
		case 7: //清空
			wm.Clear_File();
			break;
		default:
			system("CLS");
			break;
		}
	}
	return 0;
}

