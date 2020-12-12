#include "Lab5.h"


int main()
{
	int size1, size2, size3;
	int* mas1;
	int* mas2;
	int* mas3;
	History* pointer[3];
	cout << "Enter size 1: " << endl;
	cin >> size1;
	mas1 = new int[size1];
	cout << "Enter array 1: " << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << "[" << i << "] ";
		cin >> mas1[i];
	}
	cout << "Enter size 2: " << endl;
	cin >> size2;
	mas2 = new int[size2];
	cout << "Enter array 2: " << endl;
	for (int i = 0; i < size2; i++)
	{
		cout << "[" << i << "] ";
		cin >> mas2[i];
	}
	cout << "Enter size 3: " << endl;
	cin >> size3;
	mas3 = new int[size3];
	cout << "Enter array 3: " << endl;
	for (int i = 0; i < size3; i++)
	{
		cout << "[" << i << "] ";
		cin >> mas3[i];
	}
	NaturalPhenomenon nat(mas1, size1);
	Scale sc(mas2, size2);
	HistoricalFigure his(mas3, size3);
	pointer[0] = &nat;
	pointer[1] = &sc;
	pointer[2] = &his;
	for (int i = 0; i < 3; i++)
	{
		pointer[i]->Print();
		pointer[i]->Check();
	}
	delete[] mas1;
	delete[] mas2;
	delete[] mas3;
	return 0;
}