#pragma once
#include<iostream>
class errors
{
public:
	virtual void souterr() = 0;
};
class _string :public errors
{
public:
	void souterr()
	{
		std::cout << "输入了不正确的字符" << std::endl;
	}
};
class _length :public errors
{
public:
	void souterr()
	{
		std::cout << "输入了错误长度的数字" << std::endl;
	}
};
class _range :public errors
{
public:
	void souterr()
	{
		std::cout << "输入错误范围的数字" << std::endl;
	}
};
