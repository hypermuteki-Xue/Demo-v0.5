#pragma once
#ifndef MY_H_FILE
#define MY_H_FILE
#include<cstring>
#include<string>
#include<time.h>
#include<iostream>
using namespace std;
inline std::string getTime()//不加link2005
{ 
	time_t timep;
	time(&timep);
	char tmp[64];
	struct tm nowTime;
	localtime_s(&nowTime, &timep);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d", &nowTime);
	return std::string(tmp);
}
class Password
{
public:
	Password() {}
	const string getpass()const
	{
		return pass;
	}
    static int times;//link2001
	int con=0;
protected:
	const string pass="123456";
};
inline istream& operator >>(istream& cin, Password& a)
{
	string b;
	cin >> b;
	if (b == a.getpass())a.con = 1;
	else if (b == "0")a.con = 0;
	else a.con = -1;
	return cin;

}
class banker
{
protected:
	string name;
	string PIN;
	string workposition;
	string phone;
	int remain;
	string address;
	string opendate;
	string closedate;
	int ID;
	int condition;
	banker(string name, string PIN, string phone, int remain = 0, int ID = 0, string workposition = "NULL", string address = "NULL", string opendate = "NULL", string closedate = "NULL")
	{
		this->name = name;
		this->PIN = PIN;
		this->remain = remain;
		this->phone = phone;
		this->workposition = workposition;
		this->address = address;
		this->opendate = getTime();
		this->closedate = closedate;
		this->ID = ID;
		if (ID == 0)this->ID = ((rand() % 90000) + 10000);//随机
	}
};
class bankaccount:protected banker//继承
{
private:
	template<typename T>
	friend void cinfo(T temp, T word, bankaccount* key)
	{
		if (word == "name") { key->name = temp; }
		else if (word == "PIN")key->PIN = temp;
		else if (word == "workp")key->workposition = temp;
		else if (word == "phone")key->workposition = temp;
		else if (word == "address")key->address = temp;
		else cout << "输入的值不存在" << endl;
	}
public:
	const void changeremain(int a) 
	{
		remain += a;
	}
	const string getname () const
	{
		return name;
	}
	const string getPIN() const
	{
		return PIN;
	}
	const string getworkp()const
	{
		return workposition;
	}
	const string getphone() const
	{
		return phone;
	}
	const int getremain() const
	{
		return remain;
	}
	const string getopdate() const
	{
		return opendate;
	}
	const string getclose() const
	{
		return closedate;
	}
	const string getaddr() const
	{
		return address;
	}
	const int getID() const
	{
		return ID;
	}
	bankaccount(string name, string PIN, string phone, int remain, int ID, string workposition, string address, string opendate, string closedate) :banker(name, PIN, phone, remain, ID, workposition, address, opendate, closedate){ }
	bankaccount* next=NULL;
	bankaccount* prev=NULL;
};
#endif