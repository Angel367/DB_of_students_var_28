#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManagerClass
{
public:
	string FileName;
    static void AddRecord() {
        std::ofstream outFile;          // ����� ��� ������
        outFile.open(FileName); // �������� ���� ��� ������
        if (outFile.is_open())
        {
            outFile << "### Start Record" << std::endl;
            outFile << "### End Record" << std::endl;
        }
        outFile.close();
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

