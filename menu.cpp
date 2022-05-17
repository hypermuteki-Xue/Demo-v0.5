#include"bankoperate.h"
#include"menu.h"
#include"file.h"
#include"bankaccount.h"
#include<Windows.h>
#include"writing.h"
using namespace std;
void menu1(bankaccount* key);
void menu2(bankaccount* key);
void menu3(bankaccount* &key);
//增加初次使用的操作
void showmenu(bankaccount *&key)
{
	writing("\t请输入你想进行的操作");
	std::cout << "******************************************************" << endl;
	std::cout << "                请输入你要进行的操作                      " << endl;
	std::cout << "                 1.注册账户                             " << endl;
	std::cout << "                 2.登录账户                             " << endl;
	std::cout << "                 3.删除账户                           " << endl;
	std::cout << "                 4.退出系统                         " << endl;
	std::cout << "******************************************************" << endl;
	int typenum;
	cin >> typenum;
	switch (typenum)
	{
	case 1:
	{
		menu2(key); cout << endl;
		Sleep(700);
		system("cls");
		showmenu(key);
	}break;
	case 2:
	{ 
		menu1(key); cout << endl;
		Sleep(700);
		system("cls");
		showmenu(key);
	}break;
	case 3:
	{
		menu3(key); cout << endl;
		Sleep(700);
		system("cls");
		showmenu(key);
	}break;
	case 4:
	{
		break;
	}break;
	default:
	{
		showmenu(key);
	}
	}
}
void showmenu2()
{
	writing("\t请输入你想进行的操作");
	std::cout << "******************************************************" << endl;
	std::cout << "                请输入你要进行的操作                      " << endl;
	std::cout << "                 1.存款                             " << endl;
	std::cout << "                 2.取款                             " << endl;
	std::cout << "                 3.转账                             " << endl;
	std::cout << "                 4.查询                             " << endl;
	std::cout << "                 5.修改                             " << endl;
	std::cout << "******************************************************" << endl;
}
int typenum;
string password;
string name;
string PIN;
string phone;
string workp;
string address;
void menu3(bankaccount* &key)//删除
{
	writing("\t请输入管理员密码，返回上级目录请输入0" );
	cin >> password;
	if (password == "123")
	{
		cout << "请输入你想删除账户的ID" << endl;
		int ID;
		cin >> ID;
		bankaccount** temp = &key;
		if (delbankac(ID, key))cout << "删除成功" << endl;
		else cout << "删除失败";
	}
	else if (password == "0")showmenu(key);
	else
	{
		cout << "管理员密码错误" << endl;
		menu3(key);
	}
}
void menu2(bankaccount* key)//添加结点
{
	writing("\t请输入管理员密码，返回上级目录请输入0");
	cin >> password;
	if (password == "123")
	{
		cout << "\t请输入你的姓名、身份证号码、手机号、单位、地址" << endl;
		cin >> name >> PIN >> phone >> workp >> address;
		addbankac(name,PIN,phone,key,0,0,workp,address);
		cout << "添加成功" << endl;
	}
	else if (password == "0")showmenu(key);
	else
	{
		cout << "管理员密码错误" << endl;
		menu2(key);
	}
}
void menu1(bankaccount* key)
{
	cout << "请输入您的姓名或账号（输入姓名默认为多个账户中的一个）";
	string temp; bankaccount* t;
	cin >> temp;
	t = selbankac(temp, key);
	if (t == NULL)
	{
		cout << "不存在此账号" << endl;
		return;
	}
	showmenu2();
	cin >> typenum;
	switch (typenum)
	{
	case 1:
	{
		cout << "请输入你的存款数目" << endl;
		int num;
		cin >> num;
		t->changeremain(num);
		cout << "存款成功" << endl;
	}break;
	case 2:
	{
		cout << "请输入你想取款的数目" << endl;
		int num;
		cin >> num;
		if (t->getremain() >= num)
		{
			t->changeremain(-num);
			cout << "取款成功" << endl;
		}
		else cout << "对不起您的余额不足" << endl;
	}break;
	case 3:
	{
		cout << "请输入你想转账的ID,金额" << endl;
		string ID; int money;
		cin >> ID >> money;
		bankaccount* a = selbankac(ID, key);
		t->changeremain(-money);
		a->changeremain(money);
		cout << "转账成功" << endl;
	}break;
	case 4:
	{
		cout << "您的账户ID是：" << t->getID() << endl;
		cout << "您的账户姓名是：" << t->getname() << endl;
		cout << "您的账户身份证号码是：" << t->getPIN() << endl;
		cout << "您的账户余额是：" << t->getremain() << endl;
		cout << "您的开户日期是：" << t->getopdate() << endl;
		cout << "您没有关户" << endl;
	}break;
	case 5:
	{
		cout << "请输入你想修改的内容：姓名(name) 身份证号码(PIN) 工作地点(workp) 手机号码(phone) 地址(address)" << endl;
		string temp,word;
		cin >> word;
		cout << "请输入你想修改的值" << endl;
		cin >> temp;
		cinfo(temp,word,key);
		cout << "修改成功" << endl;
	}break;
	default:
	{
		cout << "输入错误,请再次输入" << endl;
		menu1(key);
	}
	}
}
