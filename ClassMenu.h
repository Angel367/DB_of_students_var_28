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
    string items[30][50];
    int selectedItem;
    int count;

    ClassMenu() {
        selectedItem = 0;
        count = 0;
    }
    int getSelectedItem() {
        return selectedItem;
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
        int maxLength = getMaxLength();
        drawLineUP(maxLength + 6);
        for (int i = 0; i < 5; i++) {

            if (i == selectedItem) {
                
                SetConsoleTextAttribute(hConsole, 15);
                cout << "|";
                SetConsoleTextAttribute(hConsole, 13);
                cout << " * " << items[i]->c_str();
                SetConsoleTextAttribute(hConsole, 15);
                string tmpString = "";
                while (tmpString.length() < maxLength - items[i]->length() + 3)
                    tmpString += " ";
                tmpString += "|";
                cout << tmpString << endl;
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);
                string tmpString = "";
                tmpString = "|   ";
                tmpString = tmpString  + items[i]->c_str();
                while (tmpString.length() < maxLength+7)
                    tmpString += " ";
                tmpString += "|";
                cout << tmpString << endl;
            }
        }
        drawLineDown(maxLength + 7);
        //cout << getMaxLength() <<  endl;
    }
    void drawLineUP(int size) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        string tmpString = " ";
        for (int i = 0; i < size; i++)
            tmpString += "_";
        SetConsoleTextAttribute(hConsole, 15);
        cout << tmpString << endl;
    }    
    void drawLineDown(int size) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        string tmpString = "|";
        for (int i = 0; i < size-1; i++)
            tmpString += "_";
        SetConsoleTextAttribute(hConsole, 15);
        tmpString += "|";
        cout << tmpString << endl;
    }
    int getMaxLength() {
        int maxLength = 0;
        for (int i = 0; i < 30; i++)
            if (items[i]->length() > maxLength)
                maxLength = items[i]->length();
        return maxLength;
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