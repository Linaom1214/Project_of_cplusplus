#include <iostream>
#include <string> 
#define MAX 1000
using namespace std;

struct Person   //联系人结构体
{
	string name;
	int gender; // 1 男  2 女
	string number; 
	int age;
	string address;
};

struct Addressbooks  //通讯录结构体
{
	//保存联系人数组
	struct Person personarr[MAX];
	//通讯录中的联系人个数
	int size ;   
};
void showMenu()
{
		cout<<"*****1.添加联系人***********"<<endl;
		cout<<"*****2.显示联系人***********"<<endl;
		cout<<"*****3.删除联系人**********"<<endl;
		cout<<"*****4.查找联系人**********"<<endl;
		cout<<"*****5.修改联系人**********"<<endl;
		cout<<"*****6.清空通讯录**********"<<endl;
		cout<<"*****0.退出通讯录**********"<<endl;
}
void addperson(Addressbooks *abs)
{
	//判断
	if (abs->size == MAX)
	{
		cout<<"通讯录已满"<<endl;
	}
	else 
	{	
		cout<<"输入姓名："<<endl;
		string  name;
		cin>>name;
		abs->personarr[abs->size].name =name;
		while(1)
		{
			int gender =0;
			cout<<"输入性别：\n1----男    2----女"<<endl;
			cin>>gender;
			if (gender==1||gender==2)
			{
				abs->personarr[abs->size].gender =gender;
				break;
			}
			else 
				cout<<"输入有误"<<endl;
		}
		cout<<"请输入手机号"<<endl;
		string number;
		cin>>number;
		abs->personarr[abs->size].number = number;

		cout<<"请输入年龄"<<endl;
		int age;
		cin>>age;
		abs->personarr[abs->size].age = age;

		cout<<"请输入住址"<<endl;
		string address;
		cin>>address;
		abs->personarr[abs->size].address = address;

		abs->size++;
		cout<<"添加成功"<<endl;
		//清屏
		system("pause");
		system("cls");
	}
}
void display(Addressbooks *abs,int size)    //为了节省内存
{
	if (size != 0)
	{
		for (int i = 0; i < size ;i++)
		{
			cout<<" 姓名："<<abs->personarr[i].name<<" 性别："<<(abs->personarr[i].gender==1?"男":"女")<<" 联系方式："<<abs->personarr[i].number
			<<" 住址："<<abs->personarr[i].address<<" 年龄："<<abs->personarr[i].age<<endl;
		}
	}
	else 
		cout<<"记录为空"<<endl;

	system("pause");
	system("cls"); //清屏
}
//检测联系人是否存在  存在返回位置 否则返回 -1

int isExist(Addressbooks *abs , string name)
{
	for (int i = 0; i<abs->size;i++)
	{
		if (abs->personarr[i].name == name)   
			return i;		
	}
	return -1;
}

//删除联系人
void deleteperson(Addressbooks *abs )
{
	cout<<"输入要删除的联系人"<<endl;
	string name;
	 cin >>name;
	 int index  = isExist(abs,name);  //这里的abs 就是指针
	 if (index != -1)
	 {
		for (int i =index;i<abs->size;i++)
		{
			abs->personarr[i] = abs->personarr[i+1];   //逻辑删除 数据前移
		}
		abs->size--;   //更新数组长度
		cout<<"删除成功"<<endl;
	 }
	 else 
		  cout<<"查无此人"<<endl;

	 system("pause");
	system("cls"); //清屏

}
void findperson (Addressbooks  *abs )   //查找联系人
{
	cout<<"输入要查找的联系人"<<endl;
	string name;
	cin>>name;
	int index  = isExist(abs ,name);
	if (index !=-1)
				cout<<" 姓名："<<abs->personarr[index].name<<" 性别："<<(abs->personarr[index].gender==1?"男":"女")<<" 联系方式："<<abs->personarr[index].number
			<<" 住址："<<abs->personarr[index].address<<" 年龄："<<abs->personarr[index].age<<endl;
	else
		cout<<"查无此人"<<endl;
	
	system("pause");
	system("cls"); //清屏
}
//修改联系人
void modifyperson (Addressbooks *abs )
{
	cout<<"输入要修改的联系人姓名"<<endl;

	string name ;
	cin >> name ;
	int index  = isExist(abs,name);
	if (index != -1)
	{
		cout<<"当前信息:"<<endl;
		cout<<"*********************************************************\t"<<endl;
		cout<<" 姓名："<<abs->personarr[index].name<<" 性别："<<(abs->personarr[index].gender==1?"男":"女")<<" 联系方式："<<abs->personarr[index].number
			<<" 住址："<<abs->personarr[index].address<<" 年龄："<<abs->personarr[index].age<<endl;
		cout<<"*********************************************************\t"<<endl;
		cout<<"输入姓名："<<endl;
		string  name;
		cin>>name;
		abs->personarr[index].name =name;
		while(1)
		{
			int gender =0;
			cout<<"输入性别：\n1----男    2----女"<<endl;
			cin>>gender;
			if (gender==1||gender==2)
			{
				abs->personarr[index].gender =gender;
				break;
			}
			else 
				cout<<"输入有误"<<endl;
		}
		cout<<"请输入手机号"<<endl;
		string number;
		cin>>number;
		abs->personarr[index].number = number;

		cout<<"请输入年龄"<<endl;
		int age;
		cin>>age;
		abs->personarr[index].age = age;

		cout<<"请输入住址"<<endl;
		string address;
		cin>>address;
		abs->personarr[index].address = address;

		cout<<"修改成功"<<endl;


	}
	else
		cout<<"查无此人"<<endl;

	system("pause");
	system("cls"); //清屏
}
//清空联系人
void clearPerson(Addressbooks *abs)
{
	cout<<"是否确定清空联系人【Y/N】"<<endl;
	char str;
	cin >>str;
	if (str =='Y' || str =='y')
		{
			abs->size =0;
			cout<<"通讯录已清空"<<endl;
		}	
	else 
		cout<<"删除失败"<<endl;

	system("pause");
	system("cls"); //清屏
}



int main( )
{
	Addressbooks abs;
	abs.size = 0;
	int x = 0;
	while(1)
	{
		showMenu();
	
		cin>>x;

		switch(x)
		{
			case 1: //添加
				addperson(&abs); //地址传递
				break;
			case 2: // 显示
				display(&abs,abs.size);
				break;
			case 3: //删除
				{
					//cout <<"输入要删除的联系人"<<endl;
					//string name;
					//cin >> name;
					// if (isExist(&abs,name)==-1)
					// {
					//	 cout<<"查无此人"<<endl;
					// }
					// else 
					// {
					//	 cout<<"找到联系人"<<endl;
					// }
					deleteperson(&abs);
					break;
				}
			case 4: //查找
				findperson(&abs);
				break;
			case 5://修改
				modifyperson(&abs);
				break;
			case 6: //清空
				clearPerson(&abs);
				break;
			case 0:
					cout<<"退出系统成功"<<endl;
					system("pause");
					return 0;
					break;
			default:
				cout<<"输入错误"<<endl;
			}
		}
		return 0;
}