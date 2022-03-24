#include <iostream>
#include "Change.h"
using namespace std;

struct Elem {
	double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
};
void vivodMnog(Elem& elem) {
	cout << "(" << elem.a << ")x^4 + (" << elem.b << ")x^3 + (" << elem.c << ")x^2 + (" << elem.d << ")x + (" << elem.e << ")";
}
void vivodMnog2(Elem& elem) {
	cout << "(" << elem.a << ")x^2 + (" << elem.b << ")x + (" << elem.c << ")";
}
void vivodMnog3(Elem& elem1) {
	cout << "(" << elem1.a << ")x^6 + (" << elem1.b << ")x^5 + (" << elem1.c << ")x^4 + (" <<
		elem1.d << ")x^3 + (" << elem1.e << ")x^2 + (" << elem1.f << ")x + (" << elem1.g << ")";
}
void vivodMnog4(Elem& elem) {
	cout << "(" << elem.a << ")x^3 + (" << elem.b << ")x^2 + (" << elem.c << ")x + (" << elem.d << ") + (" << elem.e << ")";
}
void vivodMnog5(Elem& elem) {
	cout << endl << "Полученное выражение: " << endl << "(" << elem.a << ")x^2 + (" << elem.b << ")x + (" << elem.c << ")";
	if (elem.d != 0 && elem.e != 0) cout << "Остаток от деления: " << endl << "(" << elem.d << ")x + (" << elem.e << ")" << endl;
	else if (elem.d == 0 && elem.e != 0) cout << "Остаток от деления: " << endl << "(" << elem.e << ")" << endl;
	else if (elem.d != 0 && elem.e == 0) cout << "Остаток от деления: " << endl << "(" << elem.d << ")x" << endl;
	else cout << "Деление произошло без остатка\n\n";
}

void vvodMnog1(Elem& elem) {
	cout << "Введите a:"; cin >> elem.a;
	cout << "Введите b:"; cin >> elem.b;
	cout << "Введите c:"; cin >> elem.c;
	cout << "Введите d:"; cin >> elem.d;
	cout << "Введите e:"; cin >> elem.e;
}
void vvodMnog3(Elem& elem) {
	cout << "Введите a1:"; cin >> elem.a;
	cout << "Введите b1:"; cin >> elem.b;
	cout << "Введите c1:"; cin >> elem.c;
}

int SuM()
{
	Elem elem1, elem2;
	cout << "Начинается ввод многочлена =)" << endl;
	cout << "Многочлен имеет вид: a * x4 + b * x3 + c * x2 + d * x + e" << endl;
	vvodMnog1(elem1);
	cout << endl << "Многочлен имеет вид" << endl;
	vivodMnog(elem1);
	cout << endl << endl << "Введите второй многочлен:";
	vvodMnog1(elem2);
	cout << endl << "2-й многочлен имеет вид" << endl;
	vivodMnog(elem2);
	elem1.a = elem2.a + elem1.a; elem1.b = elem1.b + elem2.b; elem1.c += elem2.c; elem1.d += elem2.d; elem1.e += elem2.e;
	cout << endl;
	cout << endl << "Сумма имеет вид" << endl;
	vivodMnog(elem1);
	system("pause");
	return 1;
}
int raznost() {
	Elem elem1, elem2;
	cout << "Начинается ввод многочлена =)" << endl;
	cout << "Многочлен имеет вид: a * x4 + b * x3 + c * x2 + d * x + e" << endl;
	vvodMnog1(elem1);
	cout << endl << "Многочлен имеет вид" << endl;
	vivodMnog(elem1);
	cout << endl << endl << "Введите второй многочлен:";
	vvodMnog1(elem2);
	cout << endl << "2-й многочлен имеет вид" << endl;
	vivodMnog(elem2);
	elem1.a = elem2.a - elem1.a; elem1.b = elem1.b - elem2.b; elem1.c -= elem2.c; elem1.d -= elem2.d; elem1.e -= elem2.e;
	cout << endl;
	cout << endl << "Разность имеет вид" << endl;
	vivodMnog(elem1);
	system("pause");
	return 1;
}
int ProizvedNaMnog() {
	int a2, b2, c2, d2, e2, f2, g2;
	Elem elem1, elem2;
	cout << "Начинается ввод многочлена =)" << endl;
	cout << "Многочлен имеет вид: a * x4 + b * x3 + c * x2 + d * x + e" << endl;
	vvodMnog1(elem1);
	cout << endl << "Многочлен имеет вид" << endl;
	vivodMnog(elem1);
	cout << endl << endl << "Введите второй многочлен (a * x2 + b * x + c):";
	vvodMnog3(elem2);
	a2 = elem1.a * elem2.a; b2 = elem1.a * elem2.b + elem2.a * elem1.b; c2 = elem1.a * elem2.c + elem1.b * elem2.b + elem2.a * elem1.c;
	d2 = elem1.b * elem2.c + elem2.b * elem1.c + elem1.d * elem2.a; e2 = elem1.c * elem2.c + elem1.d * elem2.b + elem1.e * elem2.a;
	f2 = elem1.d * elem2.c + elem1.e * elem2.b; g2 = elem1.e * elem2.c;
	elem1.a = a2; elem1.b = b2; elem1.c = c2; elem1.d = d2; elem1.e = e2; elem1.f = f2; elem1.g = g2;
	system("pause");
	return 1;
}
int ProizvedNaChisl() {
	Elem elem1; double i;
	cout << "Начинается ввод многочлена =)" << endl;
	cout << "Многочлен имеет вид: a * x4 + b * x3 + c * x2 + d * x + e" << endl;
	vvodMnog1(elem1);
	cout << endl << "Многочлен имеет вид" << endl;
	vivodMnog(elem1);
	cout << "Введи i: "; cin >> i;
	elem1.a *= i; elem1.b *= i; elem1.c *= i; elem1.d *= i; elem1.e *= i;
	system("pause");
	return 1;
}
int Proizvod() {
	Elem elem1;
	cout << "Начинается ввод многочлена =)" << endl;
	cout << "Многочлен имеет вид: a * x4 + b * x3 + c * x2 + d * x + e" << endl;
	vvodMnog1(elem1);
	cout << endl << "Многочлен имеет вид" << endl;
	vivodMnog(elem1);
	elem1.a = elem1.a * 4; elem1.b = elem1.b * 3; elem1.c = elem1.c * 2; elem1.d = elem1.d * 1; elem1.e = 0;
	system("pause");
	return 1;
}
int Delenie() {
	double k1, k2, k3, k4, k5;
	Elem elem1, elem2;
	cout << "Начинается ввод многочлена =)" << endl;
	cout << "Многочлен имеет вид: a * x4 + b * x3 + c * x2 + d * x + e" << endl;
	vvodMnog1(elem1);
	cout << endl << "Многочлен имеет вид" << endl;
	vivodMnog(elem1);
	cout << endl << endl << "Введите второй многочлен (a * x2 + b * x + c):";
	vvodMnog3(elem2);
	cout << endl << "2-й многочлен имеет вид" << endl;
	vivodMnog2(elem2);
	k1 = elem1.a / elem2.a; elem1.a -= k1 * elem2.a; elem1.b -= k1 * elem2.b; elem1.c -= k1 * elem2.c;
	k2 = elem1.b / elem2.a; elem1.b -= k2 * elem2.a; elem1.c -= k1 * elem2.b; elem1.d -= k1 * elem2.c;
	k3 = elem1.c / elem2.a; elem1.c -= k3 * elem2.a; elem1.d -= k3 * elem2.b; elem1.e -= k3 * elem2.c;
	elem1.a = k1; elem1.b = k2; elem1.c = k3;
	system("pause");
	return 1;
}
int Mnogochleni() {
	setlocale(0, "");
	Elem elem1, elem2;


	int menu_choise;
	do
	{
		menu_choise = Change(
			{
				{SuM,"Сумма"},
				{raznost,"Вычитание"},
				{ProizvedNaMnog,"Умножение многочленов"},
				{ProizvedNaChisl,"Умножение на число"},
				{Proizvod,"Вычисление производной"},
				{Delenie,"Деление"}
			},
			ONETIME
		);
	} while (menu_choise != 0);

	system("pause");
	return 1;
}