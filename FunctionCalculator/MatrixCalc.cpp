#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "MatrixCalc.h"
#include <cmath>
#include "Change.h"
#include <locale.h>

using namespace std;

int MatrixCalc() {

    setlocale(LC_ALL, "Russian");
    int menu_choise;
    do
    {
        menu_choise = Change(
            {
                {matrixSum,"Сумма матриц"},
                {matrixDifference,"Разность матриц"},
                {matrixMultiply,"Умножение матриц"},
                {matrixMultiplyNum,"Умножение матрицы на число"},
                {matrixSumNum,"Сложение матрицы с числом"},
                {matrixDifNum,"Вычитание числа из матрицы"},
                {matrixTranspose,"Транспонирование матрицы"},
                {matrixDeterminant,"Определитель матрицы"},
                {matrixInversion,"Обратная матрица"},
            },
            ONETIME
            );
    } while (menu_choise != 0);
    return 1;
}

    int matrixInversion() {
        int N;

        do {
            cout << "Введите размерность матрицы: ";
            cin >> N;
            if (N <= 0) {
                cout << "Некорректный ввод!\n";
            }

        } while (N <= 0);

        double** matrix = new double* [N];

        for (int i = 0; i < N; i++)

            matrix[i] = new double[N];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cout << "matrix[" << i << "][" << j << "] = ";
                cin >> matrix[i][j];
            }
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        double tmp, d;

        for (int k = 0; k < N - 1; k++) {
            for (int i = k + 1; i < N; i++) {
                tmp = -matrix[i][k] / matrix[k][k];
                for (int j = 0; j < N; j++) {
                    matrix[i][j] += matrix[k][j] * tmp;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

            }

        }
        d = 1;
        for (int i = 0; i < N; i++) {
            d *= matrix[i][i];
        }

        if (d == 0) {
            printf("Матрица вырожденная. Определитель равен нулю.\n");
            system("PAUSE");
            return 1;
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        matrixInversionRealise(matrix, N);
        printf("\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << matrix[i][j] << "  ";

            cout << endl;
        }

        for (int i = 0; i < N; i++)
            delete[] matrix[i];

        delete[] matrix;

        cin.get();
        system("PAUSE");

        return 1;
    }



void matrixInversionRealise(double** A, int N)
{
    double temp;

    double** E = new double* [N];

    for (int i = 0; i < N; i++)
        E[i] = new double[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            E[i][j] = 0.0;

            if (i == j)
                E[i][j] = 1.0;
        }

    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];

        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = E[i][j];

    for (int i = 0; i < N; i++)
        delete[] E[i];

    delete[] E;

}

int matrixDeterminant() {
    int n;
    double tmp, d;


    do {
        cout << "Введите размер матрицы: ";
        cin >> n;
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    double** a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }
    cout << "Введите матрицу:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] += a[k][j] * tmp;
            }
        }
    }
    //  cout << "\nМатрица:\n\n";
    cout.precision(2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(8);
            //    cout << fixed << a[i][j] << " ";
        }
        // cout << "\n";
    }
    d = 1;
    for (int i = 0; i < n; i++) {
        d *= a[i][i];
    }
    cout << fixed << "\nОпределитель матрицы: " << d << "\n";
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    system("PAUSE");
    return 1;
}

int matrixTranspose() {
    int C[100][100];
    int n, m;
    do {
        printf("Введите количество строк: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    do {
        printf("Введите количество столбцов: ");
        scanf_s("%d", &m);
        if (m <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (m <= 0);
    matrixInput(C, n, m);
    int C_T[100][100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            C_T[i][j] = C[j][i];

        }

    }
    printf("\nОтвет:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C_T[i][j]);
        }printf("\n");
    }
    system("PAUSE");
    return 1;
}

int matrixDifNum() {
    int num;//вводимое число
    printf("Введите число: ");
    scanf_s("%d", &num);
    int A[100][100];
    int C[100][100];
    int n, m;
    do {
        printf("Введите количество строк: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    do {
        printf("Введите количество столбцов: ");
        scanf_s("%d", &m);
        if (m <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (m <= 0);

    matrixInput(A, n, m);

    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] - num;
            printf("%d ", C[i][j]);
        }printf("\n");
    }
    system("PAUSE");
    return 1;
}

int matrixSumNum() {
    int num;//вводимое число
    printf("Введите число: ");
    scanf_s("%d", &num);
    int A[100][100];
    int C[100][100];
    int n, m;
    do {
        printf("Введите количество строк: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    do {
        printf("Введите количество столбцов: ");
        scanf_s("%d", &m);
        if (m <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (m <= 0);

    matrixInput(A, n, m);

    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + num;
            printf("%d ", C[i][j]);
        }printf("\n");
    }
    system("PAUSE");
    return 1;
}

int matrixMultiplyNum() {
    int num;//вводимое число
    printf("Введите множитель матрицы: ");
    scanf_s("%d", &num);
    int A[100][100];
    int C[100][100];
    int n, m;
    do {
        printf("Введите количество строк: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    do {
        printf("Введите количество ст#pragma onceолбцов: ");
        scanf_s("%d", &m);
        if (m <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (m <= 0);

    matrixInput(A, n, m);

    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] * num;
            printf("%d ", C[i][j]);
        }printf("\n");
    }
    system("PAUSE");
    return 1;
}

int matrixMultiply() {
    int A[100][100], B[100][100];
    int C[100][100];
    int n, m, n2, m2;
    do {
        printf("Введите количество строк первой матрицы: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    do {
        printf("Введите количество столбцов первой матрицы: ");
        scanf_s("%d", &m);
        if (m <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (m <= 0);
    do {
        printf("Введите количество строк второй матрицы: ");
        scanf_s("%d", &n2);
        if (n2 <= 0) { cout << "Некорректный ввод!\n"; }
        if (n2 != m) { cout << "Количество строк первой матрицы должно быть равно количеству столбцов второй матрицы!\n"; }

    } while (n2 <= 0 || n2 != m);

    do {
        printf("Введите количество столбцов второй матрицы: ");
        scanf_s("%d", &m2);
        if (m2 <= 0) { cout << "Некорректный ввод!\n"; }
        if (m2 != n) { cout << "Количество стобцов первой матрицы должно быть равно количеству строк второй матрицы!\n"; }

    } while (m2 <= 0 || m2 != n);

    matrixInput(A, n, m);
    matrixInput(B, n2, m2);
    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++)
                C[i][j] += A[i][k] * B[k][j];

            printf("%d ", C[i][j]);
        }printf("\n");
    }
    system("PAUSE");
    return 1;
}

int matrixDifference() {
    int A[100][100], B[100][100];
    int C[100][100];
    int n, m;
    do {
        printf("Введите количество строк: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    do {
        printf("Введите количество столбцов: ");
        scanf_s("%d", &m);
        if (m <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (m <= 0);

    matrixInput(A, n, m);
    matrixInput(B, n, m);
    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] - B[i][j];
            printf("%d ", C[i][j]);
        }printf("\n");
    }
    system("PAUSE");
    return 1;
}

int  matrixSum() {
    int A[100][100], B[100][100];
    int C[100][100];
    int n, m;
    do {
        printf("Введите количество строк: ");
        scanf_s("%d", &n);
        if (n <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (n <= 0);

    do {
        printf("Введите количество столбцов: ");
        scanf_s("%d", &m);
        if (m <= 0) {
            cout << "Некорректный ввод!\n";
        }

    } while (m <= 0);

    matrixInput(A, n, m);
    matrixInput(B, n, m);
    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }printf("\n");
    }
    system("PAUSE");
    return 1;

}
void matrixInput(int a[100][100], int n, int m) {

    int i, j;
    // Выделение памяти под указатели на строки
    //a = (int**)malloc(n * sizeof(int*));

    // Ввод элементов массива
    for (i = 0; i < n; i++)  // цикл по строкам
    {
        // Выделение памяти под хранение строк
      //  a[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            printf("a[%d][%d] = ", i, j);
            scanf_s("%d", &a[i][j]);
        }
    }

    // Вывод элементов массива
    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            printf("%d ", a[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }
}
