#include<iostream>
#include<fstream>
#include"menu.h"
#include"file.h";
#include"bankaccount.h"
#include"bankoperate.h"
#include"linksort.h"
using namespace std;
int main()
{
	string name="NULL";
	string PIN="NULL";
	string workposition="NULL";
	string phone="NULL";
	int remain=0;
	string address="NULL";
	string opendate="NULL";
	string closedate="NULL";
	int ID=0;
	fstream fs;
	bankaccount* key=NULL;
	fs.open("1.txt", ios::in);
	if (!fs.is_open())
	{
		cout << "-----------------系统正在初始化-----------------" << endl;
		cout << "\t第一次使用请先注册账户" << endl;
		cout << "\t请输入你的姓名、身份证号码、手机号、单位、地址" << endl;
		cin >> name >> PIN >> phone>>workposition>>address;
	    key = bankacinit( name,PIN,phone,remain,ID,workposition,address,opendate,closedate);
	}
	else
	{
		fs >> name >> PIN >> phone >> remain >> ID >> workposition >> address >> opendate >> closedate;
		key = new bankaccount(name, PIN, phone, remain, ID, workposition, address, opendate, closedate);
		while (fs >> name >> PIN >> phone >> remain >> ID >> workposition >> address >> opendate >> closedate)
		{
			addbankac(name, PIN, phone,key, remain, ID, workposition, address, opendate, closedate);
		}
	}
	fs.close();
	//添加字逐渐出来效果
	showmenu(key);
	key = sortList(key);
	changeFile(key);
	while (key != NULL)
	{
		bankaccount* node = key->next;
		delete key;
		key = node;
	}
}