#include "Resourse.h"
#ifndef COMBINATORICS // Начнем с директив препроцессора.
#define COMBINATORICS  // Они предотвращают вызов заголовочного файла больше одного раза из одного и того же файла
long long int Factorial(long long int a)
{
	long long int fact = 1;
	while (a != 0) { fact *= a; a -= 1; }
	return fact;
}
void Smena(long long int &n,long long int &k)//смена значений местами
{
	long long int t = 0;
	t = n;
	n = k;
	k = t;
	printf("Количество элементов, которые нужно выбрать, не может быть больше количества\n");
	printf("всех элементов из-за чего программа поменяла эти значения местами\n");
}
int Razm_bez_pov()
{
	long long int k = 0,n=0;
	printf("Введите количество элементво из которых нужно выбирать\n");
	scanf_s("%lld",&n);
	while (n<1||n>20) 
	{
		if (n<1) printf("Количество элементво из которых нужно выбирать не может быть неположительным числом\n");
		else printf("Программа не может вычислить факториал от числа больше 20\n");
		printf("Введите количество элементво из которых нужно выбирать еще раз\n");
		scanf_s("%lld", &n);
	}
	printf("Введите количество элементво которые нужно выбрать\n");
	scanf_s("%lld", &k);
	while (k < 1||k>20)
	{
		if (k<1)
		printf("Количество элементво которые нужно выбрать не может быть неположительным числом\n");
		else printf("Программа не может вычислить факториал от числа больше 20\n");
		printf("Введите количество элементво которые нужно выбрать еще раз\n");
		scanf_s("%lld", &k);
	}
	if (k > n) Smena(n, k);
	printf("Количество размещений без повторений из %lld по %lld равно %lld\n", n, k, Factorial(n) / Factorial(n - k));
	system("pause");
		return 1;
}
int Razm_s_pov()
{
	long long int k = 0, n = 0;
	printf("Введите количество элементво из которых нужно выбирать\n");
	scanf_s("%lld", &n);
	while (n < 1)
	{
		printf("Количество элементво из которых нужно выбирать не может быть неположительным числом\n");
		printf("Введите количество элементво из которых нужно выбирать еще раз\n");
		scanf_s("%lld", &n);
	}
	printf("Сколько раз эти элементы повторяются?\n");
	scanf_s("%lld", &k);
	while (k < 1)
	{
		printf("Элементы не могут повторятся неположительные число раз\n");
		printf("Введите количество повторений элементов еще раз еще раз\n");
		scanf_s("%lld", &k);
	}
	if (pow(n,k)<= 9 223 372 036 854 775 807)
	printf("Количество размещений с повторениями из %lld по %lld равно %lld\n", n, k, long long int(pow(n,k)));
	else printf("Число слишком большое, то есть больше 9 223 372 036 854 775 807, из-за чего типом long long int не поддерживается\n");
	system("pause");
	return 1;
}
int Coch_bez_pov()
{
	long long int k = 0, n = 0;
	printf("Введите количество элементво из которых нужно выбирать\n");
	scanf_s("%lld", &n);
	while (n < 1||n>20)
	{
		if (n<1)
		printf("Количество элементво из которых нужно выбирать не может быть неположительным числом\n");
		else printf("Программа не может вычислить факториал от числа больше 20\n");
		printf("Введите количество элементво из которых нужно выбирать еще раз\n");
		scanf_s("%lld", &n);
	}
	printf("Введите количество элементво которые нужно выбрать\n");
	scanf_s("%lld", &k);
	while (k < 1||k>20)
	{
		if (k<1) printf("Количество элементов которые нужно выбрать не может быть неположительным числом\n");
		else printf("Программа не может вычислить факториал от числа больше 20\n");
		printf("Введите количество элементво которые нужно выбрать еще раз\n");
		scanf_s("%lld", &k);
	}
	if (k > n) Smena(n, k);
	printf("Количество сочетаний без повторений из %lld по %lld равно %lld\n", n, k, Factorial(n) / (Factorial(k)* Factorial(n - k)));
	system("pause");
	return 1;
}
int Coch_s_pov()
{
	long long int k = 0, n = 0;
	printf("Введите количество элементво из которых нужно выбирать\n");
	scanf_s("%lld", &n);
	while (n < 1||n>20)
	{
		if (n<1) printf("Количество элементов из которых нужно выбирать не может быть неположительным числом\n");
		else printf("Программа не может вычислить факториал от числа больше 20\n");
		printf("Введите количество элементво из которых нужно выбирать еще раз\n");
		scanf_s("%lld", &n);
	}
	printf("Введите количество элементво которые нужно выбрать\n");
	scanf_s("%lld", &k);
	while (k < 1||n+k-1>20)
	{
		if (k<1)
		printf("Количество элементов которые нужно выбрать не может быть неположительным числом\n");
		else printf("Программа не может вычислить факториал от числа больше 20, а n+k-1 является числом больше 20\n");
		printf("Введите количество элементво которые нужно выбрать еще раз\n");
		scanf_s("%lld", &k);
	}
	if (k > n) Smena(n, k);
	printf("Количество сочетаний с повторениями из %lld по %lld равно %lld\n", n, k, Factorial(n+k-1)/ (Factorial(k) * Factorial(n - 1)));
	system("pause");
	return 1;
}
int Perest_bez_pov()
{
	long long int n = 0;
	printf("Введите количество элементво из которых нужно выбирать\n");
	scanf_s("%lld", &n);
	while (n < 1||n>20)
	{
		if (n<1)
		printf("Количество элементво из которых нужно выбирать не может быть неположительным числом\n");
		else printf("Программа не может вычислить факториал от числа больше 20\n");
		printf("Введите количество элементво из которых нужно выбирать еще раз\n");
		scanf_s("%lld", &n);
	}
		printf("Количество перестановок без повторений из %lld равно %lld\n", n, Factorial(n));
		system("pause");
		return 1;
}
int Perest_s_pov()
{
	long long int koltip=0,kol=0,znam=1,n=0;
	printf("Введите количество видов элементов\n");
	scanf_s("%lld", &koltip);
	while (koltip< 1||koltip>20)
	{
		if (koltip < 1) printf("Количество видов элементов не может быть неположительным числом\n");
		else printf("Количество видов элементов не может быть большим 20\n");
		printf("Введите количество видов элементов еще раз\n");
		scanf_s("%lld", &koltip);
	}
	for (long long int i = 1; i <= koltip; i++)
	{
		printf("Введите количество элементов вида №%lld\n",i);
		scanf_s("%lld", &kol);
		while (kol < 1|| kol>20)
		{
			if (kol < 1)
				printf("Количество элементов не может быть неположительным числом\n");
			else
				printf("Программа не может вычислить факториал от числа больше 20\n");
			printf("Введите количество элементов еще раз\n");
			scanf_s("%lld", &kol);
		}
		n += kol;
		znam *= Factorial(kol);
		if (n > 20)
		{
			printf("Программа не может вычислить факториал от числа больше 20, из-за чего расчет данного количества перестановок с повторениями невозможен\n");
			system("pause");
			return -1;
		}
	}
	printf("Количество перестановок c повторениями из %lld равно %lld\n", n, Factorial(n) / znam);
	system("pause");
	return 1;
}
#endif // Заканчиваем директивой препроцессора
