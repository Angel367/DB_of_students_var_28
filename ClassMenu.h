#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class ClassMenu
{
public:
    string items[30][40];
    int selectedItem;
    int count;

    ClassMenu() {
        selectedItem = 0;
    }
    void setDown() {
        selectedItem++;
        if (selectedItem > count - 1)
            selectedItem = 0;
    }
    void setUp() {
        selectedItem--;
        if (selectedItem < 0)
            selectedItem = count - 1;
    }

    //��� <A> � <B> � ����������������� ����� � ������ ������ ���� ����, � ������ � ���� ��������� �����(���� ������).
    //    �������� ����
    //    0 � ������
    //    1 � �����
    //    2 � �������
    //    3 � �������
    //    4 � �������
    //    5 � �������
    //    6 � ������
    //    7 � �����
    //    8 � �����
    //    9 � ����� - �����
    //    A � ������ - �������
    //    B � ������ - �������
    //    � � ������ - �������
    //    E � ������ - ������
    //    F � ���� - �����
    //system("Color 15");
    void draw() {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int i = 0; i < 5; i++) {

            if (i == selectedItem) {
                SetConsoleTextAttribute(hConsole, 13);
                cout << " * " << items[i]->c_str() << endl;
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);
                cout << "   " << items[i]->c_str() << endl;
            }

        }
    }

    void run() {
        char ch = ' ';
        while (ch != 13) {
            draw();
            Sleep(100);
            ch = _getch();
            //cout << endl << ch <<endl;
            if (ch == 80)  // ����
                setDown();
            if (ch == 72)
                setUp();
        }

    }

};