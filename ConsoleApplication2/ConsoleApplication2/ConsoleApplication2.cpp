/*Создать динамическую вещественную матрицу NxM (N и M ввести с клавиатуры). 
Создать функцию для вычисления среднего арифметического заштрихованной области(+)
+oo
++o
*/
#define _CRT_SECURE_NO_WARNINGS //для использования функции strcpy
#include <clocale>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>

using namespace std;
float  sum(int** q, int N1, int M1) {
    float s = 0;
    int calc = 0;
    for (int i = 0; i < N1; i++)
        for (int j = 0; j <= i; j++)
        {
            s = s + q[i][j];
            calc = calc + 1;
        }
    return s / calc;
}

int main()
{
    setlocale(0, "Russian");
    srand(time(NULL));
    int M;
    int N;
    int i, j;
    

    cout << "Введите N" << endl;
    cin >> N;
    cout << "Введите M" << endl;
    cin >> M;


    int **matrix = new int* [N];
    for (i = 0; i < N; i++)
        matrix[i] = new int[M];
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
        {
            matrix[i][j] = rand() % 100;
        }

    cout << endl;


    for (i = 0; i < N; i++)
    {
        cout << endl;
        for (j = 0; j < M; j++)
            cout << matrix[i][j] << " ";
    }
    cout << endl;
    cout << "Среднее ариметическое заштрихованной области = " << sum(matrix, N, M) << endl;

    for (i = 0; i < N ; i++) delete matrix[i];
    delete[] matrix;

    system("pause");
    return 0;
}