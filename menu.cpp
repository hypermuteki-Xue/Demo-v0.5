#include"bankoperate.h"
#include"menu.h"
#include"file.h"
#include"bankaccount.h"
#include<Windows.h>
#include"writing.h"
#include"errors.h"
#include<setjmp.h>
using namespace std;
int Password::times = 0;//�������ﶨ��ᱨ��
jmp_buf env;
void showmenu(bankaccount *&key)
{
	if (setjmp(env) == 2||true)
	{
		label:writing("\t������������еĲ���");
		std::cout << "******************************************************" << endl;
		std::cout << "                ��������Ҫ���еĲ���                      " << endl;
		std::cout << "                 1.ע���˻�                             " << endl;
		std::cout << "                 2.��¼�˻�                             " << endl;
		std::cout << "                 3.ɾ���˻�                           " << endl;
		std::cout << "                 4.�˳�ϵͳ                         " << endl;
		std::cout << "******************************************************" << endl;
		try {
			string typenum;
			cin >> typenum;
			if (typenum[0] >= '0' && typenum[0] <= '4' && typenum.length() == 1)throw stoi(typenum);
			else if (typenum.length() != 1) { errors* a = new _length(); throw a; }
			else if (typenum[0] >= '0' && typenum[0] <= '9') { errors* a = new _range(); throw a; }
			else { errors* a = new _string(); throw a; }
		}
		catch (int e)
		{
			switch (e)
			{
			case 1:
			{
				menu2(key); cout << endl;
				Sleep(700);
				system("cls");
				goto label;
			}break;
			case 2:
			{
				menu1(key); cout << endl;
				Sleep(1000);
				system("cls");
				goto label;
			}break;
			case 3:
			{
				menu3(key); cout << endl;
				Sleep(700);
				system("cls");
				goto label;
			}break;
			case 4:
			{
				return;
			}break;
			case 0:
			{
				cout << R"(         _   _      _ _      __         __           _     _ 
        | | | | ___| | | __  \ \       / / __   _ __| | __| |
        | |_| |/ _ \ | |/ _ \ \ \ /\  / // _  \| '__| |/ _` |
        |  _  |  __/ | | (_)   \ V  V  /  (_)  | |  | | (_| |
        |_| |_|\___|_|_|\___/   \_/ \_/  \___ /|_|  |_|\__,_|)" << endl << endl;
				longjmp(env, 2);
			}break;
			default:
			{
				cout << "�����������������" << endl;
				longjmp(env, 2);
			}break;
			}
		}
		catch (errors* a)
		{
			a->souterr();
			delete a;
			longjmp(env, 2);
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
Password password;
 string name;
 string PIN;
 string phone;
 string workp;
 string address;
void menu3(bankaccount* &key)//ɾ��
{
label:
	if (Password::times > 3) { cout << "��������̫��������" << endl; return; };
	writing("\t���������Ա���룬�����ϼ�Ŀ¼������0" );
	cin >> password;
	if (password.con==1)
	{
		cout << "����������ɾ���˻���ID" << endl;
		int ID;
		cin >> ID;
		bankaccount** temp = &key;
		if (delbankac(ID, key))cout << "ɾ���ɹ�" << endl;
		else cout << "ɾ��ʧ��";
	}
	else if (password.con==0)longjmp(env,2);
	else
	{
		Password::times++;
		cout << "�����������" << Password::times << "��" << endl;
		goto label;
	}
}
void menu2(bankaccount* key)//��ӽ��
{
label:
	if (Password::times > 3) { cout << "��������̫��������" << endl; return; };
	writing("\t���������Ա���룬�����ϼ�Ŀ¼������0");
	cin >> password;
	if (password .con==1)
	{
		cout << "\t������������������֤���롢�ֻ��š���λ����ַ" << endl;
		cin >> name >> PIN >> phone >> workp >> address;
		addbankac(name,PIN,phone,key,0,0,workp,address);
		cout << "��ӳɹ�" << endl;
	}
	else if (password.con==0)longjmp(env, 2);//�Թ�showmenu
	else
	{
		Password::times++;
		cout << "�����������"<<Password::times<<"��" << endl;
		goto label;
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
	label:showmenu2();
	try {
		string typenum;
		cin >> typenum;
		if (typenum[0] >= '0' && typenum[0] <= '5' && typenum.length() == 1)throw stoi(typenum);
		else if (typenum.length() != 1) { errors* a = new _length(); throw a; }
		else if (typenum[0] >= '0' && typenum[0] <= '9') { errors* a = new _range(); throw a; }
		else { errors* a = new _string(); throw a; }
	}
	catch (int e)
	{
		switch (e)
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
			string temp, word;
			cin >> word;
			cout << "�����������޸ĵ�ֵ" << endl;
			cin >> temp;
			cinfo(temp, word, key);
			cout << "�޸ĳɹ�" << endl;
		}break;
		default:
		{
			cout << "�������,���ٴ�����" << endl;
			goto label;
		}
		}
	}
	catch (errors* a)
	{
		a->souterr();
		delete a;
		goto label;
	}
}
