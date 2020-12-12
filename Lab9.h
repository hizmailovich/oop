#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <stack>
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
				cout << "Stack is empty!" << endl;
			}
		}
	};

	class DeathStranding
	{
		int id;
		int time;
		int level;
	public:
		DeathStranding(int _id = int(), int _level = int(), int _time = int())
		{
			this->id = _id;
			this->level = _level;
			this->time = _time;
		}
		~DeathStranding()
		{

		}
		friend ostream& operator<<(ostream& out, const DeathStranding& d);
		friend vector<DeathStranding>::iterator Algorithm2(vector<DeathStranding> v1);
		friend void Algorithm3(vector<DeathStranding> v);
	};

