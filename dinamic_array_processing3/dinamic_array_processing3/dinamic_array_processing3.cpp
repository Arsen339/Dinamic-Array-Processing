/*Создать динамическую вещественную матрицу NxM (N и M ввести с клавиатуры). 
Создать функцию, которая возвращает 2 значения : максимум в верхней заштрихованной области и минимум в нижней*/




#define _CRT_SECURE_NO_WARNINGS //для использования функции strcpy
#include <clocale>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;
void sum(int** q, int N1, int M1, int& max, int& min) {

    for (int i = 0; i < N1; i++) {
        for (int j = 0; j <= i; j++)
        {
            if (q[i][j] < min)
                min = q[i][j];
        }
        for (int i = 0; i < N1; i++)
            for (int j = i; j < M1; j++)
            {
                if (q[i][j] > max)
                    max = q[i][j];
            }

    }
}

int main()
{
    setlocale(0, "Russian");
    srand(time(NULL));
    int M;
    int N;
    int i, j;
    int** matrix;

    cout << "Введите N" << endl;
    cin >> N;
    cout << "Введите M" << endl;
    cin >> M;


    matrix = new int* [N];
    for (i = 0; i < N; i++)
        matrix[i] = new int[M];
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
        {
            matrix[i][j] = rand() % 100;
        }

    int max = -1000;
    int min = 1000;

    cout << endl;

    for (i = 0; i < N; i++)
    {
        cout << endl;
        for (j = 0; j < M; j++)
            cout << matrix[i][j] << " ";
    }
    cout << endl;
    sum(matrix, N, M, max, min);


    cout << "Max =" << max << endl;
    cout << "Min =" << min << endl;
    for (i = 0; i < N - 1; i++) delete matrix[i];
    delete[] matrix;

    system("pause");
    return 0;
}
