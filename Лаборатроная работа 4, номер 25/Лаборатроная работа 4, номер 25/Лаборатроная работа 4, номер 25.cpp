#include <conio.h>
#include <locale>
#include <iostream>
using namespace std;

double sumN(double, int);
double sumE(double x, double E, int* n);

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Вычисление значений функции log((x+1)/(x-1))\n\n";
    double x; // Значение аргумента
    double func; // Точное значение функции
    double sum; // Значение частичной суммы
    int n; // Число слагаемых в частичной сумме

    cout << "Задание 1" << endl;
    cout << "Введите значение аргумента > ";
    cin >> x;
    cout << "Задайте число слагаемых > ";
    cin >> n;
    func = log((x+1)/(x-1));// Вычисление "точного" значения
    sum = sumN(x, n);
    cout << "Точное значение функции равно " << func << endl;
    cout << "Частичная сумма ряда равна " << sum << endl;
    cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
    cout << "Последнее слагаемое равно " << (2 / ((2*n-1) * pow(x, 2*n-1))) << endl;

    cout << "\nЗадание 2" << endl;
    double E;
    cout << "Введите значение аргумента > ";
    cin >> x;
    cout << "Задайте точность вычислений > ";
    cin >> E;
    func = log((x + 1) / (x - 1));// Вычисление "точного" значения
    sum = sumE(x, E, &n);
    cout << "Точное значение функции равно " << func << endl;
    cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
    cout << "Учтено " << n << " членов ряда" << endl;
    sum = sumE(x, E / 10, &n);
    cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
    cout << "Учтено " << n << " членов ряда" << endl;
    _getch();
    return 0;
}

//функция для вычисления частичной суммы ряда
double sumN(double x, int n)
{
    //инициализация переменных
    double sum = 0;
    int r;
    //цикл вычисления и суммирования членов ряда
    for (int i = 0; i < n; ++i)
    {
        r = 2 * i + 1; //вспомогательная переменная, представляющая собой нечётные значения
        sum += 2/(r*pow(x,r)); //вычисление частичной суммы ряда
    }
    return sum;
}

double sumE(double x, double E, int *n)
{
    int r = 0;
    *n = 0;
    double t = 0, sum = 0;
    do {
        sum += t;
        r = 2 * (*n) + 1;
        t = 2 / (r * pow(x, r));
        n += 1;
    } while (fabs(t) > E);
    return sum;
}