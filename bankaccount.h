#pragma once
#include<cstring>
#include<string>
#include<time.h>
using namespace std;
inline std::string getTime() {
	time_t timep;
	time(&timep);
	char tmp[64];
	struct tm nowTime;
	localtime_s(&nowTime, &timep);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d", &nowTime);
	return std::string(tmp);
}
class bankaccount
{
private:
	friend void cinfo(string temp, string word, bankaccount*key);
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
	bankaccount(string name, string PIN,string phone,int remain=0,int ID = 0,string workposition="NULL", string address="NULL", string opendate="NULL", string closedate="NULL")
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
		if (ID == 0)this->ID =((rand()%90000)+10000);//Ëæ»ú
	}
	bankaccount* next=NULL;
	bankaccount* prev=NULL;
};