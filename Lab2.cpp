#include <iostream>
using namespace std;

class DeathStranding
{
	int id;
	int time;
	int level;
public:
	DeathStranding()
	{
		this->id = 0;
		this->level = 0;
		this->time = 0;
	}
	DeathStranding(int _id,  int _level)
	{
		this->id = _id;
		this->level = _level;
		this->time = 0;
	}
	~DeathStranding()
	{

	}
	friend class Gamer;
	friend void Print(DeathStranding& d);
};
void Print(DeathStranding& d)
{
	cout << "ID: " << d.id << "\nLevel: " << d.level << "\nTime: " << d.time << endl;
}
class Gamer
{
	int time1;
public:
	Gamer()
	{
		this->time1 = 0;
	}
	Gamer(int _time1)
	{
		this->time1 = _time1;
	}
	void Settime(DeathStranding& d)
	{
		d.time = time1;
	}
};

int main()
{
	system("color F3");
	int _id, _level, _time;
	bool fail1 = true;
	bool fail2 = true;
	bool fail3 = true;
	do
	{
		cout << "Enter id: ";
		cin >> _id;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail1 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail1);
	do
	{
		cout << "Enter level: ";
		cin >> _level;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail2 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail2);
	DeathStranding d(_id, _level);
	cout << "Before setting the time: "<< endl;
	Print(d);
	do
	{
		cout << "Enter time in minutes: ";
		cin >> _time;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail3 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail3);
	Gamer g(_time);
	g.Settime(d);
	cout << "After setting the time: " << endl;
	Print(d);
	cout << "----------------------------------------------" << endl;
	DeathStranding ds[3] =
	{
		DeathStranding(35425589, 8),
		DeathStranding(98752221, 47),
		DeathStranding(13789524, 11),
	};
	Gamer gg[3] =
	{
		Gamer(85),
		Gamer(300),
		Gamer(425),
	};
	cout << "Before setting the time: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Number " << i + 1 << endl;
		Print(ds[i]);
		gg[i].Settime(ds[i]);
	}
	cout << "After setting the time: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Number " << i + 1 << endl;
		Print(ds[i]);
	}
	return 0;
}