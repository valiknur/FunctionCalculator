#ifndef matrixCalc_h
#define matrixCalc_h
#include <cmath>
using std::cout;
using std::cin;
using std::fixed;
using std::endl;
int MatrixCalc();
void matrixInput(int a[100][100], int n, int m);


//����� ������
int  matrixSum();
//�������� ������
int matrixDifference();
//��������� ������
int matrixMultiply();
//��������� ������� �� �����
int matrixMultiplyNum();


//�������� ������� � ������
int matrixSumNum();
//��������� ����� �� �������
int matrixDifNum();
//����������������
int matrixTranspose();
//������������ �������
int matrixDeterminant();

void matrixInversionRealise(double** A, int N);
//�������� �������
int matrixInversion();
#endif

