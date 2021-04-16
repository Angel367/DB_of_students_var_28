#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "StringBuilderClass.h"
using namespace std;

class FileManagerClass: public StringBuilderClass
{
public:
    string FileName = "";

    FileManagerClass() {
        FileName = "";
    }

     void AddRecord() {
        std::ofstream outFile;          // ����� ��� ������
        outFile.open(FileName, std::ios::app); // �������� ���� ��� ������
        if (outFile.is_open())
        {
            outFile << "### Start Record" << std::endl;

            outFile << "### End Record" << std::endl;
        }
        outFile.close();
	}
     void GetRecordCount() {

     }

    static void display(string FileName) {
        string line;
        ifstream inFile(FileName); // �������� ���� ��� ������
        if (inFile.is_open())
            while (getline(inFile, line))
                std::cout << line << std::endl;
        inFile.close();     // ��������� ����
    }
};

