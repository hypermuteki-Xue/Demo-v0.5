#include<Windows.h>
#include<iostream>
#include"writing.h"
using namespace std;
void writing(string a)
{
	for (auto item:a)
	{
		cout << item;
		Sleep(50);
	}
	cout << endl;
}