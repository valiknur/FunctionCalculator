#ifndef matrixCalc_h
#define matrixCalc_h
#include <cmath>
using std::cout;
using std::cin;
using std::fixed;
using std::endl;
int MatrixCalc();
void matrixInput(int a[100][100], int n, int m);


//сумма матриц
int  matrixSum();
//разность матриц
int matrixDifference();
//умножение матриц
int matrixMultiply();
//умножение матрицы на число
int matrixMultiplyNum();


//сложение матрицы с числом
int matrixSumNum();
//вычитание числа из матрицы
int matrixDifNum();
//транспонирование
int matrixTranspose();
//определитель матрицы
int matrixDeterminant();

void matrixInversionRealise(double** A, int N);
//обратная матрица
int matrixInversion();
#endif

