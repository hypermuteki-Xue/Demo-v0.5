#include"bankoperate.h"
#include"menu.h"
#include"file.h"
#include"bankaccount.h"
#include<Windows.h>
#include"writing.h"
using namespace std;
void menu1(bankaccount* key);
void menu2(bankaccount* key);
void menu3(bankaccount* &key);
//���ӳ���ʹ�õĲ���
void showmenu(bankaccount *&key)
{
	writing("\t������������еĲ���");
	std::cout << "******************************************************" << endl;
	std::cout << "                ��������Ҫ���еĲ���                      " << endl;
	std::cout << "                 1.ע���˻�                             " << endl;
	std::cout << "                 2.��¼�˻�                             " << endl;
	std::cout << "                 3.ɾ���˻�                           " << endl;
	std::cout << "                 4.�˳�ϵͳ                         " << endl;
	std::cout << "******************************************************" << endl;
	int typenum;
	cin >> typenum;
	switch (typenum)
	{
	case 1:
	{
		menu2(key); cout << endl;
		Sleep(700);
		system("cls");
		showmenu(key);
	}break;
	case 2:
	{ 
		menu1(key); cout << endl;
		Sleep(700);
		system("cls");
		showmenu(key);
	}break;
	case 3:
	{
		menu3(key); cout << endl;
		Sleep(700);
		system("cls");
		showmenu(key);
	}break;
	case 4:
	{
		break;
	}break;
	default:
	{
		showmenu(key);
	}
	}
}
void showmenu2()
{
	writing("\t������������еĲ���");
	std::cout << "******************************************************" << endl;
	std::cout << "                ��������Ҫ���еĲ���                      " << endl;
	std::cout << "                 1.���                             " << endl;
	std::cout << "                 2.ȡ��                             " << endl;
	std::cout << "                 3.ת��                             " << endl;
	std::cout << "                 4.��ѯ                             " << endl;
	std::cout << "                 5.�޸�                             " << endl;
	std::cout << "******************************************************" << endl;
}
int typenum;
string password;
string name;
string PIN;
string phone;
string workp;
string address;
void menu3(bankaccount* &key)//ɾ��
{
	writing("\t���������Ա���룬�����ϼ�Ŀ¼������0" );
	cin >> password;
	if (password == "123")
	{
		cout << "����������ɾ���˻���ID" << endl;
		int ID;
		cin >> ID;
		bankaccount** temp = &key;
		if (delbankac(ID, key))cout << "ɾ���ɹ�" << endl;
		else cout << "ɾ��ʧ��";
	}
	else if (password == "0")showmenu(key);
	else
	{
		cout << "����Ա�������" << endl;
		menu3(key);
	}
}
void menu2(bankaccount* key)//��ӽ��
{
	writing("\t���������Ա���룬�����ϼ�Ŀ¼������0");
	cin >> password;
	if (password == "123")
	{
		cout << "\t������������������֤���롢�ֻ��š���λ����ַ" << endl;
		cin >> name >> PIN >> phone >> workp >> address;
		addbankac(name,PIN,phone,key,0,0,workp,address);
		cout << "��ӳɹ�" << endl;
	}
	else if (password == "0")showmenu(key);
	else
	{
		cout << "����Ա�������" << endl;
		menu2(key);
	}
}
void menu1(bankaccount* key)
{
	cout << "�����������������˺ţ���������Ĭ��Ϊ����˻��е�һ����";
	string temp; bankaccount* t;
	cin >> temp;
	t = selbankac(temp, key);
	if (t == NULL)
	{
		cout << "�����ڴ��˺�" << endl;
		return;
	}
	showmenu2();
	cin >> typenum;
	switch (typenum)
	{
	case 1:
	{
		cout << "��������Ĵ����Ŀ" << endl;
		int num;
		cin >> num;
		t->changeremain(num);
		cout << "���ɹ�" << endl;
	}break;
	case 2:
	{
		cout << "����������ȡ�����Ŀ" << endl;
		int num;
		cin >> num;
		if (t->getremain() >= num)
		{
			t->changeremain(-num);
			cout << "ȡ��ɹ�" << endl;
		}
		else cout << "�Բ�����������" << endl;
	}break;
	case 3:
	{
		cout << "����������ת�˵�ID,���" << endl;
		string ID; int money;
		cin >> ID >> money;
		bankaccount* a = selbankac(ID, key);
		t->changeremain(-money);
		a->changeremain(money);
		cout << "ת�˳ɹ�" << endl;
	}break;
	case 4:
	{
		cout << "�����˻�ID�ǣ�" << t->getID() << endl;
		cout << "�����˻������ǣ�" << t->getname() << endl;
		cout << "�����˻����֤�����ǣ�" << t->getPIN() << endl;
		cout << "�����˻�����ǣ�" << t->getremain() << endl;
		cout << "���Ŀ��������ǣ�" << t->getopdate() << endl;
		cout << "��û�йػ�" << endl;
	}break;
	case 5:
	{
		cout << "�����������޸ĵ����ݣ�����(name) ���֤����(PIN) �����ص�(workp) �ֻ�����(phone) ��ַ(address)" << endl;
		string temp,word;
		cin >> word;
		cout << "�����������޸ĵ�ֵ" << endl;
		cin >> temp;
		cinfo(temp,word,key);
		cout << "�޸ĳɹ�" << endl;
	}break;
	default:
	{
		cout << "�������,���ٴ�����" << endl;
		menu1(key);
	}
	}
}
