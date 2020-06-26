#include "Addressbooks.h"

Addressbooks::Addressbooks()
{
	ifstream ifs;
	ifs.open(File_Name, ios::in);

	char ch; //用于接受一个字符判断文件是否有内容
	ifs >> ch;
	//文件不存在
	if (!ifs.is_open())
	{
		cout << " 文件不存在 " << endl;
		this->m_num = 0;
		this->p_array = NULL;
		this->file_empty = true;
		ifs.close();
		return;
	}
	else if (ifs.eof())
	{
		cout << "文件存在为空" << endl;
		this->m_num = 0;
		this->p_array = NULL;
		this->file_empty = true;
		ifs.close();
		return;
	}
	else
	{
		//文件存在有数据
		int num = this->get_num();
		//cout << "人数为" << num << endl;
		this->m_num = num;

		this->p_array =  new Person *[num]; //重要开辟空间
		this->init();
		//显示内容

		
	}
}

Addressbooks::~Addressbooks()
{
	if (this->p_array != NULL)
	{
		delete[] this->p_array;
		this->p_array = NULL;
	}
}

void Addressbooks::show_menu()
{
	cout << "*********************" << endl;
	cout << "0退出" << endl;
	cout << "1增加" << endl;
	cout << "2显示" << endl;
	cout << "3删除" << endl;
	cout << "4查找" << endl;
	cout << "5清空" << endl;
}

void Addressbooks::exit_system()
{
	cout << "退出系统" << endl;
	exit(0);
}
void Addressbooks::save_data()
{
	ofstream ofs;
	ofs.open(File_Name, ios::out);   //写文件
	for (int i = 0;i < this->m_num;i++)
	{
		ofs << this->p_array[i]->name << " " << this->p_array[i]->number << endl;
	}
	ofs.close();
}
void Addressbooks::add_Person()
{
		cout << "输入要添加的人数个数："<< endl;
		int add_num = 0;
		cin >> add_num;
		
		if (add_num > 0)
		{
			int new_size = this->m_num + add_num; //新空间大小
			//开辟空间
			Person** newspace = new Person * [new_size];
			if (this->p_array != NULL)
			{
				for (int i = 0;i < this->m_num;i++)
				{
					newspace[i] = this->p_array[i];
				}
			}
			else
			{
				cout << "array 为空" << endl;
			}

			//批量添加
			for (int  i = 0; i < add_num; i++)
			{
				string name;
				string number;
				cout << "请输入姓名__";
				cin >> name;
				cout << "请输入 号码__";
				cin >> number;
				Person * p = new Person;
				p->name = name;
				p->number = number;
				newspace[this->m_num+i] = p;
			}
			delete[] this->p_array;
			this->p_array = newspace;
			this->m_num = new_size;
			this->save_data();
			this->file_empty = false;
		}
		else
		{
			cout << "输入有误" << endl;
		}
}

int Addressbooks::get_num()
{
	ifstream ifs;
	ifs.open(File_Name, ios::in);
	string name;
	string number;
	int num = 0;
	while (ifs>>name&&ifs>>number)
	{
		//
		num++;
	}
	ifs.close();
	return num;
}

void Addressbooks::init()
{
	ifstream ifs;
	ifs.open(File_Name, ios::in);
	string name;
	string number;
	int num = 0;
	while (ifs >> name && ifs >> number)
	{
		//
		Person* p = new Person(name, number);
		this->p_array[num] = p;
		num++;
	}
	ifs.close();
}

void Addressbooks::show()
{
	if (this->file_empty)
	{
		cout << "文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num; i++)
		{
			this->p_array[i]->show_info();
		}
	}
}
int Addressbooks::is_exist()
{
	cout << "输入名字" << endl;
	string name;
	cin >> name;
	int index = -1;
	for (int i = 0; i < this->m_num; i++)
	{
		if (this->p_array[i]->name == name)
		{
			index = i;
			break;
		}
	}
	return index;
}

void Addressbooks::del_person()
{
	cout << "正在删除......" << endl;
	int index = this->is_exist();
	if (index== -1)
	{
		cout << "该职工 不存在" << endl;
	}
	else
	{
		for (int  i = index; i < this->m_num; i++)
		{
			this->p_array[i] = this->p_array[i + 1];
		}
		this->m_num--;
		this->save_data();
		cout << "删除成功" << endl;
	}
}

void Addressbooks::find()
{
	cout << "正在查找......" << endl;
	int index = this->is_exist();
	if (index == -1)
	{
		cout << "该职工不存在" << endl;
	}
	else
	{
		cout << "已找到,信息如下：" << endl;
		this->p_array[index]->show_info();
	}
}

void Addressbooks::destory()
{
	cout << "你确定删除吗? Y/N" << endl;
	char select = 'N';
	cin >> select;
	if (select == 'N' || select == 'n')
	{
		cout << "删除失败，你的选择是： " << select << endl;
	}
	else if (select == 'Y' || select == 'y')
	{
		delete[] this->p_array;
		for (int i = 0; i < this->m_num; i++)
		{
			this->p_array[i] = NULL;
		}
		this->m_num = 0;
		this->file_empty = true;
		//文件更新
		this->save_data();
		cout << "清空成功!" << endl;
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
	}


}