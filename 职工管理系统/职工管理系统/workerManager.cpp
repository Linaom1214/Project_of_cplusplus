#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//初始化

	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in ) ; //读文件

	if (!ifs.is_open( ))
	{
		cout<<"文件不存在"<<endl;

		//文件不存在
		this->m_EmpNum =0;
		this->m_EmpArray = NULL;

		this->m_FileisEmpty =true;
		ifs	.close();
		return ;
	}

	//文件存在 为空

	char ch;
	ifs>>ch;
	if (ifs.eof())
	{
		cout<<"文件为空"<<endl;

		//文件存在
		this->m_EmpNum =0;
		this->m_EmpArray = NULL;

		this->m_FileisEmpty =true;
		ifs	.close();
		return ; 
	}

	//文件存在 
	int  num = this ->getNum();
	// cout<<"职工数位："<<num<<endl;
	this ->m_EmpNum = num;

	this->m_EmpArray = new Worker *[this->m_EmpNum] ;
	//开辟空间  存到数组

	this->init_Emp();

	this->m_FileisEmpty =false;
	//

	//for (int i =0; i<this->m_EmpNum;i++)
	//{
	//	cout<<this->m_EmpArray[i]->m_Name<<endl;
	//}





};

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray!=NULL)
	{
		for (int i = 0; i<this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]!=NULL)
				delete this->m_EmpArray[i];
		}
		delete [] this ->m_EmpArray ;
		this ->m_EmpArray =NULL;

	}

};

void WorkerManager::show_Menu()
{
	cout<<"************************************"<<endl;
	cout<<"*******欢迎使用职工管理系统*****"<<endl;
	cout<<"*********0.退出系统****************"<<endl;
	cout<<"*********1.增加职工信息***********"<<endl;
	cout<<"*********2.显示职工信息***********"<<endl;
	cout<<"*********3.删除职工信息***********"<<endl;
	cout<<"*********4.修改职工信息***********"<<endl;
	cout<<"*********5.查找职工信息***********"<<endl;
	cout<<"*********6.按照编号排序***********"<<endl;
	cout<<"*********7.清空所有文档***********"<<endl;
	cout<<"************************************"<<endl;
}

void WorkerManager::ExitSystem()
{
	cout<<"Next Time"<<endl;
	system("pause");
	exit(0);

}

void WorkerManager::Add_Emp()
{
	cout<<"输入要添加的人数"<<endl;

	int addNum= 0;

	cin>>addNum;

	if (addNum>0)
	{
		//添加
		//计算添加空间大小
		int newSize = this->m_EmpNum+addNum;

		//开辟空间
		Worker** newspace  = new Worker*[newSize] ;

		//将来空间数据拷贝

		if (this ->m_EmpArray != NULL)
		{
			for (int i = 0 ; i <this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//添加数据

		for (int i =0; i<addNum;i++)
		{
			int id;
			string name;
			int dSelect;

			cout<<"输入第"<<i+1<<"个 职工的 ID"<<endl;
			cin >>id;

			 while (this->isExist(id) != -1)
			 {
				 cout<<"职工编号已存在，请重新输入"<<endl;	
				 system("pause");
				 system("CLS");
				 cout<<"输入第"<<i+1<<"个 职工的 ID"<<endl;
				 cin >>id;
			 }

			cout<<"输入第"<<i+1<<"个 职工的 姓名"<<endl;
			cin >>name;

			cout<<"请选择该职工的岗位："<<endl;
			cout<<"1.普通员工"<<endl;
			cout<<"2.经理"<<endl;
			cout<<"3.老板"<<endl;

			cin >>dSelect;

			Worker  *worker  =NULL;
			switch(dSelect)
			{
			case 1:
				worker  =new Employee(id,name,1);
				break;
			case 2:
				worker  =new Manager(id,name,2);
				break;
			case 3:
				worker  =new Boss(id,name,3);
				break;
			default:
				{
					cout<<"输入错误"<<endl;
					system("CLS");
					break;
				}
			}
			//保存在数组中

			newspace[this->m_EmpNum+i] = worker;
		}


		delete [] this ->m_EmpArray;

		this->m_EmpArray = newspace;

		this->m_EmpNum = newSize;

		this->m_FileisEmpty =false;  //文件不为空

		this->save();

		cout<<"成功添加"<<addNum<<endl;	

	} 
	else
	{
		cout<<"输入错误"<<endl;
	}
	system("pause");
	system("cls");

}


void WorkerManager::save()
{
	ofstream ofs;
	ofs.open( FILENAME ,ios::out) ;//写文件
	for (int i = 0 ; i<this->m_EmpNum;i++)
	{
		ofs<<this->m_EmpArray[i]->m_ID<<" "
			<<this->m_EmpArray[i]->m_Name<<" "
			<<this->m_EmpArray[i]->m_Deptid<<endl;
	}

	ofs.close();
}

int WorkerManager::getNum( ) 
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int  id;
	string name;
	int Did;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>Did)
	{
		//
		num ++;
	}

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int  id;
	string name;
	int Did;

	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>Did)
	{
		Worker * worker  =NULL ;
		if (Did ==1)
		{
			worker =new Employee(id,name,Did);
		}
		if (Did ==2)
		{
			worker =new Manager(id,name,Did);
		}
		if (Did ==3)
		{
			worker =new Boss(id,name,Did);
		}

		this->m_EmpArray[index]  =worker;
		index++;
	}
	//
	ifs.close();

}

void WorkerManager::show()
{
	//判断文件

	if (this->m_FileisEmpty ==true)
	{
		cout<<"文件不存在或者为空"<<endl;
	}
	else	
	{
		for (int i = 0 ;i<this->m_EmpNum;i++)
		{

			this->m_EmpArray[i]->showinof();
		}

	}
	//
	system("pause");
	system("CLS");
}


int  WorkerManager::isExist(int id)
{
	int flag = -1;
	for (int i = 0; i <this->m_EmpNum ;i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
			{
				return i;
				break ;
			}

	}
	return flag;
}

void WorkerManager::deleteEmp( )
{
	if (this->m_FileisEmpty )
	{
		cout<<"文件不存在"<<endl;
	}
	else	
	{
		cout<<"输入职工编号"<<endl;

		int id  =0;
		cin>>id;
		int index  = this->isExist(id);

		if (index != -1)
		{
			for (int i =index;i<this->m_EmpNum;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i+1];   //逻辑删除 数据前移
			}
			this->m_EmpNum--;   //更新数组长度

			this->save();  //同步更新到文件

			cout<<"删除成功"<<endl;
		}
		else 
			cout<<"删除失败，未找该职工"<<endl;
	}

	system("pause");
	system("CLS");
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileisEmpty )
	{
		cout<<"文件不存在,或记录为空"<<endl;
	}
	else	
	{
		cout<<"输入修改职工编号"<<endl;

		int id  =0;
		cin>>id;
		int index  = this->isExist(id);

		if (index != -1)
		{
			int id;
			string name;
			int dSelect;

			cout<<"更新职工的 ID"<<endl;
			cin >>id;
			cout<<"更新职工的 姓名"<<endl;
			cin >>name;
			cout<<"更新该职工的岗位："<<endl;
			cout<<"1.普通员工"<<endl;
			cout<<"2.经理"<<endl;
			cout<<"3.老板"<<endl;

			cin >>dSelect;
			Worker *worker = NULL;
			switch(dSelect)
			{
			case 1:
				worker  =new Employee(id,name,1);
				break;
			case 2:
				worker  =new Manager(id,name,2);
				break;
			case 3:
				worker  =new Boss(id,name,3);
				break;
			default:
				{
					cout<<"输入错误"<<endl;
					break;
				}
			}
				//保存在数组中

				this->m_EmpArray[index] = worker;

				this->save();
				cout<<"修改成功"<<endl;
			}
		else	
		{
			cout<<"查无此人"<<endl;
		}
	}
	system("pause");
	system("CLS");
}


void WorkerManager::Find_Emp()
{
	if (this->m_FileisEmpty == true)
	{
		cout<<"文件不存在或为空"<<endl;
	}
	else	
	{
		cout<<"输入查找方式"<<endl;
		cout<<"1.按照编号查找"<<endl;
		cout<<"2.按照姓名查找"<<endl;
		int select	 = 0;
		cin>>select;
		if (select == 1)
		{
			// 编号
			int id;
			cout<<"输入编号"<<endl;
			cin>>id;
			int ret = this->isExist(id);
			if (ret != -1)
			{
				this->m_EmpArray[ret]->showinof();
			}
			else
				cout<<"查无此人"<<endl;
		} 
		else if(select ==2)
		{
			//姓名
			string name;
			cout<<"输入要查找的姓名"<<endl;
			cin >>name;
			bool flag = false;
			for (int i = 0 ;i <this->m_EmpNum;i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					this->m_EmpArray[i]->showinof();
					flag = true;
				}
			}

			if (flag == false	)
				cout<<"查无此人"<<endl;
		}
		else
		{
			cout<<"输入有误"<<endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileisEmpty == true)
	{
		cout<<"文件不存在或为空"<<endl;
	}
	else	
	{
		cout<<"输入排序方法"<<endl;
		cout<<"1.升序"<<endl;
		cout<<"2.降序"<<endl;
		int select = 0;
		cin >>select;
		switch (select)
		{
		case 1:
			{
					for (int i = 0 ; i <this->m_EmpNum ;i++)
					{
						int  min = i;
							for (int j =i+1 ; j < this->m_EmpNum ;j++)
							{
								if (this->m_EmpArray[j] > this->m_EmpArray[min])  
								{
									min = j;
								}
							}
						if (i!=min)
						{

							Worker  *temp =this->m_EmpArray[i]; 
							this->m_EmpArray[i]=this->m_EmpArray[min];
							this->m_EmpArray[min] = temp;
						}
					}
				this->save();
				this->show();
				break;
			}
		case 2:
			{
				for (int i = 0 ; i <this->m_EmpNum ;i++)
				{
					int  min = i;
					for (int j =i+1 ; j < this->m_EmpNum ;j++)
					{
						if (this->m_EmpArray[j] < this->m_EmpArray[min])  
						{
							min = j;
						}
					}
					if (i!=min)
					{
						Worker  *temp =this->m_EmpArray[i]; 
						this->m_EmpArray[i]=this->m_EmpArray[min];
						this->m_EmpArray[min] = temp;
					}
				}
				this->show();
				this->save();
				//this->show();
				break;
			}
		}
		system("pause");
		system("cls");
	}
}


void WorkerManager::Clear_File()
{
	cout<<"确定清空？"<<endl;
	cout<<"1.确定"<<endl;
	cout<<"2.返回"<<endl;

	int select  =0;
	cin >>select;
	if (select ==1)
	{
		ofstream ofs(FILENAME ,ios::trunc)  ;//删除文件后重新创建
		ofs.close();
		for (int i = 0; i<this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]!=NULL)
				delete this->m_EmpArray[i];
		}
		delete [] this ->m_EmpArray ;
		this ->m_EmpArray =NULL;
		this->m_EmpNum =0;
		this->m_FileisEmpty = true;

		cout<<"清空成功"<<endl;
	} 
	system("pause");
	system("cls");
}