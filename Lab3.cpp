#include "Lab3.h"

 ostream& operator<<(ostream& out, const Matrix& matrix)
 {
	 for (int i = 0; i < matrix.n; i++)
	 {
		 for (int j = 0; j < matrix.m; j++)
		 {
			 out << matrix.mt[i][j] << " ";
		 }
		 out << endl;
	 }
	return out;
 }




int main()
{
	int _n, _m;
	int** mtr;
	cout << "Enter size n: " << endl;
	cin >> _n;
	cout << "Enter size m: " << endl;
	cin >> _m;
	mtr = new int* [_n];
	for (int i = 0; i < _n; i++)
	{
		mtr[i] = new int[_m];
	}
	cout << "Enter elements into matrix: " << endl;
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> mtr[i][j];
		}
	}
	cout << "Matrix: " << endl;
	Matrix matrix(_n, _m);
	Matrix a(_n, _m);
	Matrix b(_n, _m);
	matrix.SetMatrix(mtr, _n, _m);
	matrix.Print();
	Matrix matrix2(matrix);
	cout << "Copy constructor:" << endl;
	cout<<matrix2;
	cout << "Enter elements into matrix 2: " << endl;
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> mtr[i][j];
		}
	}
	cout << "Matrix: " << endl;
	Matrix matrix1(_n, _m);
	matrix1.SetMatrix(mtr, _n, _m);
	matrix1.Print();
	a = matrix + matrix1;
	//matrix.operator+(matrix1);
	cout << "+" << endl;
	matrix.Print();
	b = matrix2 - matrix1;
	//matrix2.operator-(matrix1);
	cout << "-" << endl;
	matrix2.Print();
	matrix.~Matrix();
	matrix2.~Matrix();
	matrix1.~Matrix();
	for (int i = 0; i < _n; i++)
	{
		delete[] mtr[i];
	}
	delete[]mtr;
	return 0;
}