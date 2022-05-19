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
	T a = "剪刀";
	void gamestarting()
	{
		std::cout << "电脑出的是"<<a << std::endl;
	}
};
template<typename T>
class rock :public three
{
public:
	T a = "石头";
	void gamestarting()
	{
		std::cout << "电脑出的是" << a << std::endl;
	}
};
template<typename T>
class cloth :public three
{
public:
	T a = "布";
	void gamestarting()
	{
		std::cout << "电脑出的是" << a << std::endl;
	}
};
void gaming(three* a)
{
	a->gamestarting();
}