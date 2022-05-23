#include<iostream>
#include<fstream>
#include"menu.h"
#include"file.h";
#include"bankaccount.h"
#include"bankoperate.h"
#include"linksort.h"
#include"writing.h"
using namespace std;
bankaccount* openning()
{
	string name = "NULL";
	string PIN = "NULL";
	string workposition = "NULL";
	string phone = "NULL";
	int remain = 0;
	string address = "NULL";
	string opendate = "NULL";
	string closedate = "NULL";
	int ID = 0;
	writing("-----------------ϵͳ���ڳ�ʼ��-----------------");
	writing("\t��һ��ʹ������ע���˻�");
	writing("\t������������������֤���롢�ֻ��š���λ����ַ");
	cin >> name >> PIN >> phone >> workposition >> address;
	return  bankacinit(name, PIN, phone, remain, ID, workposition, address, opendate, closedate);
}
int main()
{
	fstream fs;
	bankaccount* key=NULL;
	fs.open("1.txt", ios::in);
	if (!fs.is_open())
	{
	    key = openning();
	}
	else
	{
		string name = "NULL";
		string PIN = "NULL";
		string workposition = "NULL";
		string phone = "NULL";
		int remain = 0;
		string address = "NULL";
		string opendate = "NULL";
		string closedate = "NULL";
		int ID = 0;
		fs >> name>>PIN>>phone>>remain>>ID>>workposition>>address>>opendate>>closedate;
		if (fs.eof())
		{
			key=openning();
		}
		else
		{
			key = new bankaccount(name, PIN, phone, remain, ID, workposition, address, opendate, closedate);
			key->prev = NULL;
			while (fs >> name >> PIN >> phone >> remain >> ID >> workposition >> address >> opendate >> closedate)
			{
				addbankac(name, PIN, phone, key, remain, ID, workposition, address, opendate, closedate);
			}
		}
	}
	fs.close();
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