#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Exception
{
protected:
	int error;
public:
	Exception()
	{
		error = 0;
	}
	Exception(int _error)
	{
		error = _error;
	}
	~Exception()
	{

	};
	void Print()
	{
		if (this->error == 0)
		{
			cout << "Input error! Enter int!" << endl;
		}
		if (this->error == 1)
		{
			cout << "Opening error!" << endl;
		}
		if (this->error == 2)
		{
			cout << "Input category! A, B or C" << endl;
		}
	}
};

class Product
{
	char category;
	string name;
	string workshop;
	int amount;
public:
	Product(char _category = char(), string _name = string(), string _workshop = string(), int _amount = int(), Product* pNext = nullptr)
	{
		category = _category;
		name = _name;
		workshop = _workshop;
		amount = _amount;
		this->pNext = pNext;
	}
	friend ostream& operator<<(ostream& out, const Product& pr);
	friend class File;
	Product* pNext;
};

class Stack :public Product
{
public:
	Stack();
	~Stack();
	void pop();
	void clear();
	int GetSize()
	{
		return Size;
	}
	Product& operator[](const int index);
	void push(char _category, string _name, string _workshop, int _amount);
private:
	int Size;
	Product* head;
	friend ostream& operator<<(ostream& out, const Product& pr);
};

class File
{
	string path;
public:
	File()
	{
		this->path = " ";
	}
	File(string _path)
	{
		this->path = _path;
	}
	void ReadText();
	void ReadBin(int n);
	void WriteText();
	void WriteBin(Product pr);
	void Search();
	void Sort(int n, Stack& st);
	void ReadTextBin();
	int Del(int index, int n, Stack& st);
};