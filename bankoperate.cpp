#include"bankaccount.h";
#include"bankoperate.h"
#include"file.h"
#include<cstdlib>
#include<iostream>
using namespace std;
void addbankac(string name, string PIN, string phone,bankaccount* head, int remain, int ID, string workposition, string address, string opendate, string closedate)
{
	bankaccount* node = new bankaccount(name, PIN, phone,remain,ID,workposition,address,opendate,closedate);
	while (head->next != NULL)head = head->next;
	head->next = node;
	node->next = NULL;
}
bankaccount* selbankac(string temp, bankaccount* head)
{
	if (temp[0] >= '0' && temp[0] <= '9')//查账号
	{
		int t = stoi(temp);
		while (head!= nullptr)
		{
			if (head->getID() == t)return head;
			else head = head->next;
		}
	}
	else if (temp[0] >= 'a' && temp[0] <= 'z' || temp[0] >= 'A' && temp[0] <= 'Z')
	{
		while (head != nullptr)
		{
			if (head->getname() == temp)return head;
			else head = head->next;
		}
	}
	return NULL;
}
bankaccount* bankacinit(string name, string PIN, string phone,int remain = 0, int ID = 0, string workposition = "NULL", string address = "NULL", string opendate = "NULL", string closedate = "NULL")
{
	bankaccount* head;
	head = new bankaccount(name,PIN,phone,remain,ID,workposition,address,opendate,closedate);
	changeFile(head);
	/*fstream File;
	File.open("1.txt", ios::out);
	File << head->getname() << " " << head->getPIN() << " " << head->getphone() << " "<<head->getremain()<<" "<<head->getID() << " " <<head->getworkp()<<" "<<head->getaddr()<<" "<<head->getopdate()<<" "<<head->getclose()<<" "<<head->getcon()<<endl;
	File.close();*/
	return head;
}
bool delbankac(int ID, bankaccount* head)
{
	while (head != NULL)
	{
		if (head->getID() == ID)
		{
			head->next = head->next->next;
			return 1;
		}
		else head = head->next;
	}
	return 0;
}
void cinfo(string temp, string word, bankaccount* key)
{
	if (word == "name") { key->name = temp; cout << 1; }
	else if (word == "PIN")key->PIN = temp;
	else if (word == "workp")key->workposition = temp;
	else if (word == "phone")key->workposition = temp;
	else if (word == "address")key->address = temp;
	else cout << "输入的值不存在" << endl;
}