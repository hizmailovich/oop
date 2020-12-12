#pragma once
#include <iostream>
#include <string>
using namespace std;

class History //class B
{
protected:
	int year;
	int century;
	string era;
public:
	History()
	{
		this->year = 0;
		this->century = 0;
		this->era = "Nothing";

	}
	History(int _year, int _century, string _era)
	{
		this->year = _year;
		this->century = _century;
		this->era = _era;
	}
	void PrintHistory()
	{
		cout << "Year: " << this->year << endl;
		cout << "Century: " << this->century << endl;
		cout << "Era: " << this->era << endl;
	}
	~History()
	{

	}
};

class NaturalPhenomenon : virtual public History //class P1
{
protected:
	string appearance1;
	string appearance2;
	int level;

public:
	NaturalPhenomenon() :History()
	{
		this->appearance1 = "Nothing";
		this->appearance2 = "Nothing";
		this->level = 0;
	}
	NaturalPhenomenon(string _appear1, int _year, int _century, string _era, string _appear2, int _level)
	{
		this->era = _era;
		this->appearance1 = _appear1;
		this->appearance2 = _appear2;
		this->century = _century;
		this->year = _year;
		this->level=_level;
	}
	void PrintNaturalPhenomenon()
	{
		cout << "Year: " << this->year << endl;
		cout << "Century: " << this->century << endl;
		cout << "Era: " << this->era << endl;
		cout << "Natural phenomenon 1: " << this->appearance1 << endl;
		cout << "Natural phenomenon 2: " << this->appearance2 << endl;
		cout << "Level: " << this->level << endl;
	}
	~NaturalPhenomenon()
	{

	}
};

class Scale : virtual public NaturalPhenomenon //class P11
{
protected:
	int score;
public:
	Scale() :NaturalPhenomenon()
	{
		this->score = 0;
	}
	Scale(int _score, string _appear1, int _year, int _century, string _era, string _appear2, int _level)
	{
		this->appearance1 = _appear1;
		this->year = _year;
		this->appearance2 = _appear2;
		this->century = _century;
		this->year = _year;
		this->level = _level;
		this->score = _score;
	}
	void PrintScale()
	{
		cout << "Year: " << this->year << endl;
		cout << "Century: " << this->century << endl;
		cout << "Era: " << this->era << endl;
		cout << "Natural phenomenon 1: " << this->appearance1 << endl;
		cout << "Natural phenomenon 2: " << this->appearance2 << endl;
		cout << "Level: " << this->level << endl;
		cout << "Scale: " << this->score << endl;
	}
	~Scale()
	{

	}
};

class HistoricalFigure :virtual public History //class P2
{
protected:
	string name1;
	string name2;
	int age;
public:
	HistoricalFigure() :History()
	{
		this->name1 = "Nobody";
		this->name2 = "Nobody";
		this->age = 0;
	}
	HistoricalFigure(string _name1, string _name2, int _age,int _year, int _century, string _era)
	{
		this->name1 = _name1;
		this->name2 = _name2;
		this->age = _age;
		this->year = _year;
		this->century = _century;
		this->era = _era;
	}

	void PrintHistoricalFigure()
	{
		cout << "Year: " << this->year << endl;
		cout << "Century: " << this->century << endl;
		cout << "Era: " << this->era << endl;
		cout << "Historical figure1: " << this->name1 << endl;
		cout << "Historical figure2: " << this->name1 << endl;
		cout << "Age: " << this->age << endl;
	}
	~HistoricalFigure()
	{

	}
};

class Action :virtual public HistoricalFigure //class P21
{
protected:
	string act;
public:
	Action() :HistoricalFigure()
	{
		this->act = "Nothing";
	}
	Action(string _act, string _name1, string _name2, int _age, int _year, int _century, string _era)
	{
		this->name1 = _name1;
		this->name2 = _name2;
		this->age = _age;
		this->year = _year;
		this->century = _century;
		this->era = _era;
		this->act = _act;
	}
	void PrintAction()
	{
		cout << "Year: " << this->year << endl;
		cout << "Century: " << this->century << endl;
		cout << "Era: " << this->era << endl;
		cout << "Historical figure1: " << this->name1 << endl;
		cout << "Historical figure2: " << this->name1 << endl;
		cout << "Age: " << this->age << endl;
		cout << "Action: " << this->act << endl;
	}
	~Action()
	{

	}
};

class Result : public Scale, public Action //class P3
{
protected:
	string res;
public:
	Result()
	{
		this->name1 = " ";
		this->name2 = " ";
		this->age = 0;
		this->year = 0;
		this->century = 0;
		this->era = " ";
		this->act = " ";
		this->res = " ";
		this->appearance1 = " ";
		this->appearance2 = " ";
		this->level = 0;
	}
	Result(string _res, int _score, string _appear1, int _year, int _century, string _era, string _appear2, int _level, string _act, string _name1, string _name2, int _age)
	{
		this->res = _res;
		this->name1 = _name1;
		this->name2 = _name2;
		this->age = _age;
		this->century = _century;
		this->era = _era;
		this->act = _act;
		this->appearance1 = _appear1;
		this->year = _year;
		this->appearance2 = _appear2;
		this->level = _level;
		this->score = _score;

	}
	void PrintResult()
	{
		cout << "Year: " << this->year << endl;
		cout << "Century: " << this->century << endl;
		cout << "Era: " << this->era << endl;
		cout << "Historical figure1: " << this->name1 << endl;
		cout << "Historical figure2: " << this->name1 << endl;
		cout << "Age: " << this->age << endl;
		cout << "Action: " << this->act << endl;
		cout << "Natural phenomenon 1: " << this->appearance1 << endl;
		cout << "Natural phenomenon 2: " << this->appearance2 << endl;
		cout << "Level: " << this->level << endl;
		cout << "Scale: " << this->score << endl;
	}
	~Result()
	{

	}
};
