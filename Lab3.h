#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix
{
	int m;
	int n;
	int** mt;
public:
	Matrix()
	{
		n = m = 1;
		mt = new int* [n];
		for (int i = 0; i < 1; i++)
		{
			mt[i] = new int[m];
		}
	}
	Matrix(int _n, int _m)
	{
		n = _n;
		m = _m;
		mt = new int* [n];
		for (int i = 0; i < n; i++)
		{
			mt[i] = new int[m];
		};
	}
	Matrix(const Matrix& other)
	{
		this->m = other.m;
		this->n = other.n;
		this->mt = new int* [other.n];
		for (int i = 0; i < other.n; i++)
		{
			this->mt[i] = new int[m];
		}
		for (int i = 0; i < other.n; i++)
		{
			for (int j = 0; j < other.m; j++)
			{
				this->mt[i][j] = other.mt[i][j];
			}
		}
	}
	void Print()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mt[i][j] << " ";
			}
			cout << endl;
		}
	}
	void SetMatrix(int** mtr, int _n, int _m)
	{
		this->n = _n;
		this->m = _m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				this->mt[i][j] = mtr[i][j];
			}
		}
	}
	Matrix operator +(const Matrix& other)
	{
		Matrix temp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				this->mt[i][j] += other.mt[i][j];
			}
		}
		return temp;
	}
	Matrix operator -(const Matrix& other)
	{
		Matrix temp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				this->mt[i][j] -= other.mt[i][j];
			}
		}
		return temp;
	}
	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] mt[i];
		}
		delete[]mt;
	}
	friend ostream& operator<<(ostream& out, const Matrix& matrix);
};