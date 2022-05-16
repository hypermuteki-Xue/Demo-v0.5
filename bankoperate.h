#pragma once
#include"bankaccount.h"
void addbankac(string name, string PIN, string phone, bankaccount* head, int remain=0, int ID=0, string workposition="NULL", string address="NULL", string opendate="NULL", string closedate="NULL");
bankaccount* bankacinit(string name, string PIN, string phone, int remain, int ID , string workposition , string address, string opendate , string closedate);
bool delbankac(int ID, bankaccount* head);
bankaccount* selbankac(string temp, bankaccount* head);