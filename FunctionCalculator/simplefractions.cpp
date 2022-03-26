#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Change.h"
#include"simplefractions.h"


int FractionSimplifying2(int& number, int& fraction)
{
	if (fraction < number)
	{
		for (int i = fraction; i >= 1; i--)
		{
			if (fraction % i == 0 && number % i == 0)
			{
				number /= i;
				fraction /= i;
			}
		}
	}
	else
	{
		if (fraction != number)
		{
			for (int i = number; i >= 1; i--)
			{
				if (fraction % i == 0 && number % i == 0)
				{
					number /= i;
					fraction /= i;
				}
			}
		}
	}
	
	return 0;
}
int FractionSumm()
{
	int Number_of_fractions;
	do 
	{
		printf("Введите число дробей (от 2 до 15): ");
		scanf("%d", &Number_of_fractions);
	} while (Number_of_fractions<2 || Number_of_fractions> 15);

	int number[15], fraction[15];
	for (int i = 0; i < Number_of_fractions; i++)
	{
		do
		{
			printf("Введите дробь №%d:\n", i+1);
			fraction[i] = 1;
			scanf("%d/%d", &number[i], &fraction[i]);
			if (fraction[i] == 0) printf("Ошибка. Повторите ввод\n");
		} while (fraction[i] == 0);

		if (fraction[i] < 0)
		{
			fraction[i] *= -1;
			number[i] *= -1;
		}
	}
	
	int summ_number = number[0];
	int summ_fraction = fraction[0];
	for (int i = 0; i < Number_of_fractions-1; i++)
	{
		if (number[i + 1] == 0) continue;
		if (summ_fraction != fraction[i+1])
		{
			if (summ_fraction % fraction[i + 1] == 0)
			{
				summ_number += number[i + 1] * (summ_fraction / fraction[i + 1]);
			}
			else
			{
				if (fraction[i + 1] % summ_fraction == 0)
				{
					summ_number = summ_number * (fraction[i + 1]/summ_fraction) + number[i + 1];
					summ_fraction = fraction[i + 1];
				}
				else
				{
					summ_number = summ_number * fraction[i + 1] + number[i + 1] * summ_fraction;
					summ_fraction *= fraction[i + 1];
				}
			}
		}
		else
		{
			summ_number += number[i + 1];
		}
	}
	if (summ_number == summ_fraction) printf("Сумма дробей = 1\n");
	else
	{
		if (summ_number ==-summ_fraction) printf("Сумма дробей = -1\n");
		else
		{
			FractionSimplifying2(summ_number, summ_fraction);
			if (summ_fraction == 1) printf("Сумма дробей = %d\n", summ_number);
			else
			{
				if (summ_number == 0) printf("Сумма дробей = 0\n");
				else printf("Сумма дробей = %d/%d\n", summ_number, summ_fraction);
			}
		}
	}
	return 0;
}
int FractionSubtraction()
{
	int number[2], fraction[2];
	for (int i = 0; i <= 1; i++)
	{
		do
		{
			printf("Введите дробь №%d:\n", i + 1);
			fraction[i] = 1;
			scanf("%d/%d", &number[i], &fraction[i]);
			if (fraction[i] == 0) printf("Ошибка. Повторите ввод\n");
		} while (fraction[i] == 0);

		if (fraction[i] < 0)
		{
			fraction[i] *= -1;
			number[i] *= -1;
		}
	}


	int subtract_number= number[0];
	int subtract_fraction= fraction[0];

	if (subtract_fraction != fraction[1])
	{
		if (subtract_fraction % fraction[1] == 0)
		{
			subtract_number -= number[1] * (subtract_fraction / fraction[1]);
		}
		else
		{
			if (fraction[1] % subtract_fraction == 0)
			{
				subtract_number = subtract_number * (fraction[1] / subtract_fraction) - number[1];
				subtract_fraction = fraction[1];
			}
			else
			{
				subtract_number = subtract_number * fraction[1] - number[1] * subtract_fraction;
				subtract_fraction *= fraction[1];
			}
		}
	}
	else
	{
		subtract_number -= number[1];
	}
	if (subtract_number == subtract_fraction) printf("Разница дробей = 1\n");
	else
	{
		if (subtract_number == -subtract_fraction) printf("Разница дробей = -1\n");
		else
		{
			FractionSimplifying2(subtract_number, subtract_fraction);
			if (subtract_fraction == 1) printf("Разница дробей = %d\n", subtract_number);
			else
			{
				if (subtract_number == 0) printf("Разница дробей = 0\n");
				else printf("Разница дробей = %d/%d\n", subtract_number, subtract_fraction);
			}
		}
	}
	return 0;
}
int FractionMultiplication()
{
	int Number_of_fractions;
	do
	{
		printf("Введите число дробей (от 2 до 15): ");
		scanf("%d", &Number_of_fractions);
	} while (Number_of_fractions<2 || Number_of_fractions> 15);

	int number[15], fraction[15];
	for (int i = 0; i < Number_of_fractions; i++)
	{
		do
		{
			printf("Введите дробь №%d:\n", i + 1);
			fraction[i] = 1;
			scanf("%d/%d", &number[i], &fraction[i]);
			if (fraction[i] == 0) printf("Ошибка. Повторите ввод\n");
		} while (fraction[i] == 0);

		if (fraction[i] < 0)
		{
			fraction[i] *= -1;
			number[i] *= -1;
		}
	}

	int multi_number = 1, multi_fraction = 1;
	for (int i = 0; i < Number_of_fractions; i++)
	{
		multi_number *= number[i];
		multi_fraction *= fraction[i];
	}

	if (multi_number == multi_fraction) printf("Произведение дробей = 1\n");
	else
	{
		if (multi_number == -multi_fraction) printf("Произведение дробей = -1\n");
		else
		{
			FractionSimplifying2(multi_number, multi_fraction);
			if (multi_fraction == 1) printf("Произведение дробей = %d\n", multi_number);
			else
			{
				if (multi_number == 0) printf("Произведение дробей = 0\n");
				else printf("Произведение дробей = %d/%d\n", multi_number, multi_fraction);
			}
		}
	}
	return 0;
}
int FractionDivision()
{
	int number[2], fraction[2];
	for (int i = 0; i <= 1; i++)
	{
		do
		{
			printf("Введите дробь №%d:\n", i + 1);
			fraction[i] = 1;
			scanf("%d/%d", &number[i], &fraction[i]);
			if (fraction[i] == 0) printf("Ошибка. Повторите ввод\n");
		} while (fraction[i] == 0);

		if (fraction[i] < 0)
		{
			fraction[i] *= -1;
			number[i] *= -1;
		}
	}

	int division_number, division_fraction;
	division_number = number[0]*fraction[1];
	division_fraction = fraction[0]*number[1];

	if (division_number == division_fraction) printf("Деление дробей = 1\n");
	else
	{
		if (division_number == -division_fraction) printf("Деление дробей = -1\n");
		else
		{
			FractionSimplifying2(division_number, division_fraction);
			if (division_fraction == 1) printf("Деление дробей = %d\n", division_number);
			else
			{
				if (division_number == 0) printf("Деление дробей = 0\n");
				else printf("Деление дробей = %d/%d\n", division_number, division_fraction);
			}
		}
	}
	return 0;
}
int FractionCompare()
{
	int number[2], fraction[2];
	for (int i = 0; i <= 1; i++)
	{
		do
		{
			printf("Введите дробь №%d:\n", i + 1);
			fraction[i] = 1;
			scanf("%d/%d", &number[i], &fraction[i]);
			if (fraction[i] == 0) printf("Ошибка. Повторите ввод\n");
		} while (fraction[i] == 0);

		if (fraction[i] < 0)
		{
			fraction[i] *= -1;
			number[i] *= -1;
		}
	}

	if (double(number[0]) / fraction[0] > double(number[1]) / fraction[1]) printf("%d/%d>%d/%d\n", number[0], fraction[0], number[1], fraction[1]);
	else
	{
		if (double(number[0]) / fraction[0] < double(number[1]) / fraction[1]) printf("%d/%d<%d/%d\n", number[0], fraction[0], number[1], fraction[1]);
		else printf("%d/%d=%d/%d\n", number[0], fraction[0], number[1], fraction[1]);
	}
	return 0;
}
int FractionSimplifying()
{
	int number, fraction;
	do
	{
		printf("Введите дробь:\n");
		fraction = 1;
		scanf("%d/%d", &number, &fraction);
		if (fraction == 0) printf("Ошибка. Повторите ввод\n");
	} while (fraction == 0);

	FractionSimplifying2(number, fraction);
	printf("Упрощённая дробь = %d/%d", number, fraction);
	return 0;
}
int FractionDecimal()
{
	int number, fraction;
	do
	{
		printf("Введите дробь:\n");
		fraction = 1;
		scanf("%d/%d", &number, &fraction);
		if (fraction == 0) printf("Ошибка. Повторите ввод\n");
	} while (fraction == 0);
	printf("Десятичный вид дроби: %.5lf", double(number) / fraction);
	return 0;
}
int simplefractions()
{
	setlocale(LC_ALL, "Russian");
	int menu_choise;
	do
	{
	menu_choise = Change(
		{
			{FractionSumm,"Сложение дробей"},
			{FractionSubtraction,"Вычитание дробей"},
			{FractionMultiplication,"Умножение"},
			{FractionDivision,"Деление"},
			{FractionCompare,"Сравнение"},
			{FractionSimplifying,"Сокращение"},
			{FractionDecimal,"Представление в виде десятичной дроби"}
		},
		ONETIME
	);
	} while (menu_choise != 0);
	return 1;
}