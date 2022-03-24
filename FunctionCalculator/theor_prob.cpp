#include "Change.h"
#include "theor_prob.h"
int veroyatn(int row, int column, double** dispers, double lim);
int dispersion();
int math_expectation();


int probability_nm() {
	int n, m;
	std::cout << "������� ����� ������������\n";
	do {
		std::cin >> m;
		if (m < 1)std::cout << "������� ����� ������ 0\n";
	} while (m < 1);
	std::cout << "������� ���������� ���������, ��������������� �������\n";
	do {
		std::cin >> n;
		if (n < 0)std::cout << "������� ����� ������ ��� ����� 0\n";
		if (n > m)std::cout << "���-�� ��������� �� ����� ���� ������ ���������� ������������\n";
	} while (n < 0 || n>m);
	std::cout << "����������� ������ ������� ������� ����� " << 1.0 * n / m << std::endl;
	system ("PAUSE");
	return 0;
}
int dispersion() {
	int num, flag=1;
	double lim = 1.0,M1=0,M2=0,D;
	do {
		std::cout << "������� ���������� ��������� ���������\n";
		do {
			std::cin >> num;
			if (num < 1)std::cout << "������� ����� ��������� ������ ��� 0" << std::endl;

		} while (num < 1);
		double** dispers = new double*[num];
		for (int i = 0; i < num; i++) {
			dispers[i] = new double[2];
		}
		for (int row = 0; row < num; row++) {
			std::cout << "������� �������� " << row + 1 << "-� ���� � �������:\n�����\t��� �����������\n";
			for (int column = 0; column < 2; column++) {
				if (column == 1) {
					flag = veroyatn(row, column, dispers, lim);
					if (flag == 0)break;
					lim = lim - dispers[row][column];
				}
				else {
					std::cin >> dispers[row][column];
				}
			}
			if (flag == 0) {
				lim = 1.0;
				break;
			}
		}
		if (lim != 0) {
			std::cout << "��������� ����������� ������ ��������� 1, ������� ����� ������\n";
			flag = 0;
			lim = 1.0;
		}
		else {
			for (int row = 0; row < num; row++) {
				M1 += (dispers[row][0] * dispers[row][1]);
				M2 += (dispers[row][0] * dispers[row][1] * dispers[row][0]);
			}
			D = M2 - M1 * M1;
			std::cout << "��������� ����� " << D << std::endl;
			for (int count = 0; count < num; count++)
				delete[]dispers[count];
		}
	} while (flag == 0);
	system("PAUSE");
	return 0;
}
int veroyatn(int row, int column,double **dispers,double lim) {
	do {
		std::cin >> dispers[row][column];
		if (dispers[row][column] <= 0)std::cout << "����������� ������ ���� ������ 0\n";
	} while (dispers[row][column] <= 0);
	if (lim - dispers[row][column] < 0) {
		std::cout << "�� ����� ������������ �� ����� ����� ������� 1, ���������� ������� ������ ������\n";
		std::cout << "�������� ���������� ��������:\n1-�������� ����������� ��������� ����\n2-�������� ��� ����� ���������\n";
		int vib;
		do {
			std::cin >> vib;
			if (vib != 1 && vib != 2)std::cout << "������� ������� �� ������";
		} while (vib != 1 && vib != 2);
		if (vib == 2)return 0;
		if (vib == 1) {
			std::cout << "������� ����� �����������\n";
			veroyatn(row, column, dispers, lim);
		}
	}
	return 1;
}
int math_expectation() {
	int num, flag = 1;
	double lim = 1.0, M1 = 0;
	do {
		std::cout << "������� ���������� ��������� ��� �������� ���. ��������\n";
		do {
			std::cin >> num;
			if (num < 1)std::cout << "������� ����� ��������� ������ ��� 0" << std::endl;

		} while (num < 1);
		double** dispers = new double* [num];
		for (int i = 0; i < num; i++) {
			dispers[i] = new double[2];
		}
		for (int row = 0; row < num; row++) {
			std::cout << "������� �������� " << row + 1 << "-� ���� � �������:\n�����\t��� �����������\n";
			for (int column = 0; column < 2; column++) {
				if (column == 1) {
					flag = veroyatn(row, column, dispers, lim);
					if (flag == 0)break;
					lim = lim - dispers[row][column];
				}
				else {
					std::cin >> dispers[row][column];
				}
			}
			if (flag == 0) {
				lim = 1.0;
				break;
			}
		}
		if (lim != 0) {
			std::cout << "��������� ����������� ������ ��������� 1, ������� ����� ������\n";
			flag = 0;
			lim = 1.0;
		}
		else {
			for (int row = 0; row < num; row++) {
				M1 += (dispers[row][0] * dispers[row][1]);
			}
			std::cout << "�������������� �������� ����� " << M1 << std::endl;
			for (int count = 0; count < num; count++)
				delete[]dispers[count];
		}
	} while (flag == 0);

	system("PAUSE");
	return 0;
}

int Theor_prob()
{
	setlocale(LC_ALL, "Russian");
	int menu_choise;
	do
	{
		menu_choise = Change(
			{
				{ probability_nm, "����������� n/m"},
				{ dispersion,"��������� ��� ����������� ������������� �������" },
				{ math_expectation,"���. �������� ��� ����������� ������������� �������" },
			},
			ONETIME
			);
	} while (menu_choise != 0);
	return 0;
}
