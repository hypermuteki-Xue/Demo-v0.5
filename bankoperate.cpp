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
	node->prev = head;
	node->next = NULL;
}
bankaccount* selbankac(string temp, bankaccount* head)
{
	if (temp[0] >= '0' && temp[0] <= '9')//²éÕËºÅ
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
	return head;
}
bool delbankac(int ID, bankaccount* &head)//É¾³ýÕË»§ºÅÂë
{
	while (head != NULL)
	{
		if (head->getID() == ID)
		{
			bankaccount* temp = head;
			if (head->prev == NULL)
			{
				head = head->next;
			}
			else if (head->next == NULL)
			{
				head->prev->next = NULL;
			}
			else { head->prev->next = head->next; }
			delete temp;
			temp = NULL;
			return 1;
		}
		else head = head->next;
	}
	return 0;
}