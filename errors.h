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
		std::cout << "�����˲���ȷ���ַ�" << std::endl;
	}
};
class _length :public errors
{
public:
	void souterr()
	{
		std::cout << "�����˴��󳤶ȵ�����" << std::endl;
	}
};
class _range :public errors
{
public:
	void souterr()
	{
		std::cout << "�������Χ������" << std::endl;
	}
};
