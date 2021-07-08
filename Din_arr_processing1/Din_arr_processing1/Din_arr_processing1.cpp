/*Создать функцию для определения количества прописных, заглавных букв, а также цифр в строке (вернуть массив результатов). Тестовая программа: Ввести с клавиатуры 2 динамические строки, содержащие по нескольку слов.
Определить в какой строке прописных букв больше. Все заглавные буквы заменить на прописные.*/






#define _CRT_SECURE_NO_WARNINGS //для использования функции strcpy
#include <clocale>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#define N 80
#define M 80
using namespace std;

int checkline(char* q, int& h, int& s, int& n) {
    for (int i = 0; q[i] != 0; i++)
    {
        if (isdigit(q[i])) n++;  //подсчет заглавных, прописных букв и цифр	
        if (islower(q[i])) s++;
        if (isupper(q[i])) {
            h++;
            q[i] = tolower(q[i]);
        }
    }
    printf("\n Замена заглавных на прописные : %s \n", q);
    return n;
}

int main()
{
    setlocale(0, "Russian");
    int s1 = 0;
    int s2 = 0;
    int h = 0;
    int s = 0;
    int n = 0;
    char buff[N];
    char* din_str;
    char buff1[M];
    char* din_str1;

    printf("Введите строку 1 на латинице : ");
    gets_s(buff);
    din_str = (char*)malloc(strlen(buff) + 1);
    strcpy(din_str, buff);
    printf("\n Печать динамической строки номер 1 : %s \n", din_str);
    checkline(din_str, h, s, n);
    cout << "Заглавных: " << h << endl;
    cout << "Строчных: " << s << endl;
    cout << "Цифр: " << n << endl;
    s1 = s;
    h = 0;
    s = 0;
    n = 0;

    printf("Введите строку 2 на латинице : ");
    gets_s(buff1);
    din_str1 = (char*)malloc(strlen(buff1) + 1);
    strcpy(din_str1, buff1);
    printf("\n Печать динамической строки номер 2 : %s \n", din_str1);
    checkline(din_str1, h, s, n);
    cout << "Заглавных: " << h << endl;
    cout << "Строчных: " << s << endl;
    cout << "Цифр: " << n << endl;
    s2 = s;
    if (s1 > s2)
        cout << "В 1 строке прописных букв больше " << endl;
    else if (s2 > s1)
        cout << "В 2 строке прописных букв больше " << endl;
    else
        cout << "В 1 и во второй строках одинаково прописных букв " << endl;

    system("pause");
    return 0;
}
