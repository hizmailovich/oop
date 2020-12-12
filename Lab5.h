#pragma once
#include <iostream>
#include <string>
using namespace std;

class History //class B
{
public:
	virtual void Print() = 0;
	virtual void Check() = 0;
	virtual ~History()
	{

	}
};

class NaturalPhenomenon : public History //class P1
{
protected:
	int* naturalArr;
	int n;
public:
	NaturalPhenomenon()
	{
		this->n = 1;
		this->naturalArr = new int[n];
	}
	NaturalPhenomenon(int* ms, int _n)
	{
		this->n = _n;
		this->naturalArr = new int[n];
		for (int i = 0; i < n; i++)
		{
			this->naturalArr[i] = ms[i];
		}
	}
	void Check() override
	{
		int S;
		S = n * n;
		cout << "Check() Natural phenomenon S = Size*Size = " << S << endl;
	}
	void Print() override
	{
		cout << "Natural phenomenon: " <<  endl;
		cout << "Size = " << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << this->naturalArr[i] << " " << endl;
		}
	}
	~NaturalPhenomenon()
	{
		delete[] naturalArr;
	}
};

class Scale : public NaturalPhenomenon //class P11
{
protected:
	int* ScaleArr;
	int m;
public:
	Scale() 
	{
		this->m = 1;
		this->ScaleArr = new int[m];
	}
	Scale(int* ms1, int _m)
	{
		this->m = _m;
		this->ScaleArr = new int[m];
		for (int i = 0; i < m; i++)
		{
			this->ScaleArr[i] = ms1[i];
		}
	}
	void Check() override
	{
		int S;
		S = m * m;
		cout << "Check() Scale  S = Size*Size = " << S << endl;
	}
	void Print() override
	{
		cout << "Scale: " << endl;
		cout << "Size = " << m << endl;
		for (int i = 0; i < m; i++)
		{
			cout << this->ScaleArr[i] << " " << endl;
		}
	}
	~Scale()
	{
		delete[] ScaleArr;
	}
};

class HistoricalFigure : public History //class P2
{
protected:
	int* FigureArr;
	int k;
public:
	HistoricalFigure() 
	{
		this->k = 1;
		this->FigureArr = new int[k];
	}
	HistoricalFigure(int*ms2, int _k) 
	{
		this->k = _k;
		this->FigureArr = new int[k];
		for (int i = 0; i < k; i++)
		{
			this->FigureArr[i] = ms2[i];
		}
	}
	void Check() override
	{
		int S;
		S = k * k;
		cout << "Check() HistoricalFigure S = Size*Size = " << S << endl;
	}
	void Print() override
	{
		cout << "Historical figure: " << endl;
		cout << "Size = " << k << endl;
		for (int i = 0; i < k; i++)
		{
			cout << this->FigureArr[i] << " " << endl;
		}
	}
	~HistoricalFigure()
	{
		delete[] FigureArr;
	}
};

