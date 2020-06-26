#include "Addressbooks.h"
#include "Person.h"
#include <iostream>
using namespace std;

int main()
{
	//Person p("张三", "120");
	//p.show_info();
	Addressbooks ads;
	int index = -1; //接受查找状态
	while (true)
	{
		ads.show_menu();
		cout << "输入选择:" << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 0:
			//退出系统
			ads.exit_system();
			system("cls");
			break;
		case 1:
			ads.add_Person();
			//增加成员
			system("cls");
			break;
		case 2:
			//显示成员
			ads.show();
			system("pause");
			system("cls");
			break;
		case 3:
			//删除
			ads.del_person();
			system("pause");
			system("cls");
			break;
		case 4:
			//查找
			ads.find();
			system("pause");
			system("cls");
			break;
		case 5:
			//清空
			ads.destory();
			system("pause");
			system("cls");
			break;
		case 6:
			break;
		default:
			system("cls");
			break;
		}
	}
}