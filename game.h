#pragma once
#include<iostream>
class three
{
public:
	virtual void gamestarting()=0;
	std::string b;
};
template<typename T>
class sci :public three
{
public:
	T a = "����";
	void gamestarting()
	{
		std::cout << "���Գ�����"<<a << std::endl;
	}
};
template<typename T>
class rock :public three
{
public:
	T a = "ʯͷ";
	void gamestarting()
	{
		std::cout << "���Գ�����" << a << std::endl;
	}
};
template<typename T>
class cloth :public three
{
public:
	T a = "��";
	void gamestarting()
	{
		std::cout << "���Գ�����" << a << std::endl;
	}
};
void gaming(three* a)
{
	a->gamestarting();
}