#include "Lab4.h"


int main()
{
	int _year, _score, _century, _level, _age;
	string _res, _appear1, _appear2, _act,  _era, _name1, _name2;
	bool fail1 = true;
	bool fail2 = true;
	bool fail3 = true;
	bool fail4 = true;
	bool fail5 = true;
	system("color F3");
	do
	{
		cout << "Enter century: ";
		cin >> _century;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail1 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail1);
	do
	{
		cout << "Enter year: ";
		cin >> _year;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail2 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail2);
	cout << "Enter natural phenomenon1: ";
	cin >> _appear1;
	cout << "Enter natural phenomenon2: ";
	cin >> _appear2;
	do
	{
		cout << "Enter scale: ";
		cin >> _score;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail3 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail3);
	cout << "Enter level: ";
	cin >> _level;
	cout << "Enter era: ";
	cin >> _era;
	cout << "Enter age: ";
	cin >> _age;
	cout << "Enter historical figure1: ";
	cin >> _name1;
	cout << "Enter historical figure2: ";
	cin >> _name2;
	cout << "Enter action: ";
	cin >> _act;
	cout << "Enter result: ";
	cin >> _res;
	Result r(_res,_score, _appear1, _year, _century, _era, _appear2, _level, _act, _name1, _name2, _age);
	cout << "--------------------------------------" << endl;
	cout << "Class P3: " << endl;
	r.PrintResult();
	cout << "--------------------------------------" << endl;
	cout << "Class P11" << endl;
	Scale s(_score, _appear1,_year,_century, _era, _appear2,_level);
	s.PrintScale();
	cout << "--------------------------------------" << endl;
	cout << "Class P21" << endl;
	Action ac( _act, _name1, _name2, _age, _year, _century, _era);
	ac.PrintAction();
	return 0;
}