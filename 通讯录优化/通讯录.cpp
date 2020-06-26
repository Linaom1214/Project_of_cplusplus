//#include <iostream>
//#include <string>
////#include <fstream>
////#define File_name "data.txt"
////添加
////显示
////删除
////修改
////排序 按手机号
//using namespace std;
//
//class Person
//{
//public:
//	Person(string name, string number);
//	void show_info() const;
//	string name;
//	string   number;
//};
//Person::Person(string name, string number)
//{
//	this->name = name;
//	this->number = number;
//}
//void Person::show_info() const
//{
//	cout << "姓名： " << this->name << " 号码: "<<this->number << endl;
//}
//
//class Addressbooks
//{
//public:
//	Addressbooks();
//	~Addressbooks();
//	int m_mun;
//	Person** p_array;  //指针数组
//	void add_person();
//	bool is_empty;
//};
//
//Addressbooks::Addressbooks()
//{
//	
//	this->is_empty = false;
//	string name = "默认";
//	string muber = "120";
//	Person  p1(name,muber);
//	p1.show_info();
//	this->m_mun = 1;
//	this->p_array = new Person * [this->m_mun];
//	this->p_array[0] = &p1;
//
//	//this->is_empty = true;
//	//this->m_mun = 0;
//	//this->p_array = NULL;
//	//cout << this->is_empty;
//	//ifstream ifs;
//	//ifs.open(File_name, ios::in);
//	//if (!ifs.is_open())s
//	//{
//	//	cout << "文件不存在" << endl;
//	//	this->m_mun = 0;
//	//	this->p_array = NULL;
//	//	this->is_empty = true;
//	//	ifs.close();
//	//	return;
//	//}
//
//	//if (ifs.eof())
//	//{
//	//	cout << "文件为空" << endl;
//	//	this->m_mun = 0;
//	//	this->p_array = NULL;
//	//	this->is_empty = true;
//	//	ifs.close();
//	//	return;
//	//}
//
//}
//
//Addressbooks::~Addressbooks()
//{
//	//if (this->p_array != NULL)
//	//{
//	//	delete[] this->p_array;
//	//	this->is_empty = true;
//	//}
//}
//
//void Addressbooks::add_person()
//{
//	cout << "add 函数调用"<< endl;
//	//cout << this->m_mun << endl;
//	int num = this->m_mun+1;
//	Person** newspace = new Person* [5];
//	//newspace = NULL;
//
//	if (this->p_array != NULL)
//	{
//		for (int i = 0;i < this->m_mun;i++)
//		{
//			newspace[i] = this->p_array[i];
//		}
//	}
//	else
//	{
//		cout << "array 为空" << endl;
//	}
//
//	string name;
//	string number;
//	cout << "请输入姓名__";
//	cin >> name;
//	cout << "请输入 号码__";
//	cin >> number;
//
//	Person p(name ,number);
//	//p.show_info();
//	/*newspace[this->m_mun ]->name = name;
//	newspace[this->m_mun ]->number = number;*/
//	
//	newspace[0] = &p;
//	delete[] this->p_array;
//	//newspace[num ]->name = p.name;
//	//newspace[num ]->number =p.number;
//
//
//	this->p_array = newspace;
//	//cout << newspace[0]->name << endl;
//	//cout << newspace[0]->number << endl;
//	//cout << p_array[0]->name << endl;
//	//cout << p_array[0]->number << endl;
//	this->m_mun = num;
//	this->is_empty = false;
//}
//
//void show()
//{
//	cout << "1增加" << endl;
//	cout << "2删除" << endl;
//	cout << "3修改" << endl;
//	cout << "4显示" << endl;
//	cout << "5查找" << endl;
//}
//
//int main()
//{
//	using namespace std;
//
//	cout << "1增加" << endl;
//	cout << "2删除" << endl;
//	cout << "3修改" << endl;
//	cout << "4显示" << endl;
//	cout << "5查找" << endl;
//
//	//Person p;
//	//p.name = "默认";
//	//p.number = "120";
//	//p.show_info();
//
//	Addressbooks  abs  ;
//	//cout << abs->is_empty << endl;
//	//cout << abs->m_mun << endl;
//	abs.add_person();
//
//	cout << abs.m_mun << endl;
//	abs.p_array[1]->show_info();
//
//	//for (int i = 0;i < abs->m_mun;i++)
//	//{
//	//	cout << abs->p_array[i]->name << endl;
//	//	cout<< abs->p_array[i]->number << endl;
//	//	cout << "显示 函数调用" << endl;
//	//}
//	//while (true)
//	//{
//	//	
//	//	int select= 1;
//	//	cin >> select;
//	//	switch (select)
//	//	{
//	//	case 1:
//	//	{
//	//		abs->add_person();
//	//	}
//	//	{
//
//	//	}
//
//	//	default:
//	//		break;
//	//	}
//	//}
//	return 0;
//	
//}
