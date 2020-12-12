#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	system("color B0");
    double a;
    double b;
    double c;
    double x;
    cout << "Для уравнения вида ax^2+bx+c=0" << endl;
    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;
    cout << "Введите значение c: ";
    cin >> c;
    if ((b * b - 4 * a * c) >= 0) 
    {
        x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << setw(4) << setfill('#');
        cout << fixed << setprecision(4) << "x=" << x;
        x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << setw(4) << setfill('#') <<endl;
        cout << fixed << setprecision(4) << "x=" << x<<endl;
    }
    else
    {
        cout << "Дискриминант меньше 0, корни невещественные." << endl;
    }
	return 0;
}

