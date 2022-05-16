#include<Windows.h>
#include<iostream>
#include"writing.h"
using namespace std;
void writing(string a)
{
	for (int i = 0; i <= a.length() - 1; i++)
	{
		cout << a[i];
		Sleep(50);
	}
	cout << endl;
}