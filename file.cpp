#include"file.h"
#include<fstream>
void changeFile(bankaccount* key)
{
	fstream  ofs;
	ofs.open("1.txt", ios::out);
	while (key!= NULL)
	{
		ofs <<key->getname() << " " << key->getPIN() << " " << key->getphone() << " " << key->getremain() << " " << key->getID() << " " << key->getworkp() << " " << key->getaddr() << " " << key->getopdate() << " " << key->getclose() << " "  << endl;
		key = key->next;
	}
}