#include <iostream>
#include "StringBuilderClass.h"
#include "FileManagerClass.h"
#include "ClassMenu.h"
#include "StudentDBClass.h"
#include "StudentClass.h"
#include "ClassEdit.h"
#include "list.hpp"
//#include <algorithm>
using namespace std;

void var57(StudentDBClass* sdb) {
    ClassMenu* varMenu = new ClassMenu();
    int resultSelectedItem = 1;
    const int exitItem = 0;
    varMenu->addTitleItem("�������� �������: ");
    for (auto item : sdb->DataBase) {
        string tmpString = "";
        tmpString = item.surName + " " + item.name + " " + item.middleName +  " " + std::to_string(item.countMarks5) + " " + std::to_string(item.countMarks4) + " " + std::to_string(item.countMarks3) + " " + item.birthDateString;
        varMenu->addTitleItem(tmpString);
    }
    varMenu->addItem("�����"); //0
    varMenu->addItem("�) 3;"); //1
    varMenu->addItem("�) 3 � 4;"); //2
    varMenu->addItem("�) 5;"); //3
    varMenu->addItem("�) 3 � 5;"); //4
    varMenu->addItem("�) 4 � 5."); //5
    StudentDBClass* sdb1 = new StudentDBClass();
    while (resultSelectedItem != exitItem) {
        varMenu->run();
        resultSelectedItem = varMenu->getSelectedItem();
        if (resultSelectedItem == 1) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if (item.countMarks3 > 0.25) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 2) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if ((item.countMarks3 > 0.25) and (item.countMarks4 > 0.25)){
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 3) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if (item.countMarks5 > 0.25) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 4) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if ((item.countMarks3 > 0.25) and (item.countMarks5 > 0.25)) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
        if (resultSelectedItem == 5) {
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase) {
                if ((item.countMarks4 > 0.25) and (item.countMarks5 > 0.25)) {
                    sdb1->DataBase.push_front(item);
                }
            }
            sdb1->printAllSurName_Name_MName_bYaear_Marks543();
            _getch();
        }
    }
}


List<string>::iterator mMin(List <string> *_lst) {
    List<string>::iterator pos = _lst->begin();
    List<string>::iterator mMinPos = _lst->begin();
    string tmpString = *pos;
    while (pos != _lst->end()){
        if (*pos> tmpString)
            mMinPos = pos;
        ++pos;
    }
    return mMinPos;
   // return std::max_element(_lst->begin(), _lst->end());// #include <algorithm>
   
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // ���� � ������� � ��������� 1251
    SetConsoleOutputCP(1251);
    std::cout << "�������� ������ ��������...\n";
    StudentDBClass* sdb = new StudentDBClass();    
    StudentDBClass* sdb1 = new StudentDBClass();
    StudentDBClass* sdb2 = new StudentDBClass();
    StudentDBClass* sdb3 = new StudentDBClass();
    sdb->FileName = "C:/Users/1/CLionProjects/DB_of_students_var_28/DB.txt";    // ������ ����� �������� ������ "DB.txt"
    sdb->loadDataFromFile();

    bool debug = false;
    if (debug) {


        //���������� �����
        List <string> lst = { "���" , "����� ������", "�����","������", "�������" ,"�����" };
        //����������� ������
        for (auto item : lst) {
            cout << item << endl;
        }
        List <string> sortedLst;
        sortedLst.clear();
        //cout << *mMin(&lst);
        while (!lst.empty()) {
            sortedLst.push_front(*mMin(&lst));
            lst.erase(mMin(&lst));
        }
        //����������� ��������������� ������
        cout << endl << "------------" << endl;
        for (auto item : sortedLst) {
            cout << item<<endl;
        }
    }
    else {

    
    //cout << sdb->GetRecordCount() << endl;
    ClassMenu* mainMenu = new ClassMenu();
    mainMenu->addTitleItem("������� ����");
    mainMenu->addItem("����������� ������ ��������� (������� ��� �������� ������)"); //0
    mainMenu->addItem("�������� ������ � �������� � ��"); //1
    mainMenu->addItem("��������� �� ��������� � ����"); //2
    mainMenu->addItem("��������� ������� 77"); //3
    mainMenu->addItem("��������� ������� 71"); //4
    mainMenu->addItem("��������� ������� 31"); //5
    mainMenu->addItem("��������� ������� 27"); //6
    mainMenu->addItem("��������� ������� 57"); //7
    mainMenu->addItem("��������� ������� 43"); //8
    mainMenu->addItem("��������� ������� 28"); //9
    mainMenu->addItem("�����"); //10
    int resultSelectedItem = 0;
    int exitInt = 10;
    ClassMenu* studentsMenu = new ClassMenu();
    studentsMenu->addTitleItem("������ ���������");
    int resultStudentSelectedItem = 1;
    const int exitIntStudentMenu = 0;
    StudentNode* sn;
    StudentClass* st = new StudentClass();
    ClassMenu* delStudentsMenu = new ClassMenu();
    int curCount;
    ClassEdit* ce = new  ClassEdit();
    int startYear = 0;
    int endYear = 0;
    int year = 0;
    StringBuilderClass* sb = new StringBuilderClass();
    List<StudentNode>::iterator pos();
    List <StudentNode> printLst;
    string firstPartString;
    while (resultSelectedItem != exitInt) {
        mainMenu->run();
        resultSelectedItem = mainMenu->getSelectedItem();
        switch (resultSelectedItem) {
        case 0:
            resultStudentSelectedItem = 1;
            while (resultStudentSelectedItem != exitIntStudentMenu) {
                studentsMenu->eraseItem();
                studentsMenu->addItem("�����");
                studentsMenu->addItem("������� ������ � ��������");
                /*sn = sdb->getInit();*/
                for(int i=0;i<sdb->DataBase.size();i++)
                { // �������� ������ ���� ��� ���������
                    sn = &sdb->DataBase.at(i);
                    string tmpString = sn->surName + " " + sn->name + " " + sn->middleName + " " + sn->group;
                    studentsMenu->addItem(tmpString); //�������� � ���� ���������
                    //sn = sn->next;
                }
                studentsMenu->run();
                resultStudentSelectedItem = studentsMenu->getSelectedItem();
                if (resultStudentSelectedItem == exitIntStudentMenu) {
                    break;
                }
                if (resultStudentSelectedItem == 1) //�������� ������ � ��������
                {
                    delStudentsMenu->eraseAll();
                    delStudentsMenu->addTitleItem("�������� �������� ��� �������� ������");
                    delStudentsMenu->addItem("�����");
                    int resultDel = 1;
                    const int exitDel = 0;
                    for(int i=0; i<sdb->DataBase.size();i++)
                    { // �������� ������ ���� ��� ���������
                        sn = &sdb->DataBase.at(i);
                        string tmpString = sn->surName + " " + sn->name + " " + sn->middleName + " " + sn->group;
                        delStudentsMenu->addItem(tmpString); //�������� � ���� ���������
                        //sn = sn->next;
                    }
                    while (resultDel != exitDel) {
                        delStudentsMenu->run();
                        resultDel = delStudentsMenu->getSelectedItem();
                        if (resultDel == exitDel) {
                            break;
                        }
                        else {
                            int num = resultDel - 1;
                            sdb->DataBase.erase(std::next(sdb->DataBase.begin(), num));
                            break;
                        }
                    }
                }
                if (resultStudentSelectedItem>1)
                {
                    int num = resultStudentSelectedItem - 2; //!
                    sn = &sdb->DataBase.at(num);   
                    string oldRecordCardNumber = "";
                    oldRecordCardNumber = sn->recordCardNumber;
                    st->editStudent(sn);

                    if (sdb->getSameRecordCardNumber(sn->recordCardNumber)>1)
                    {
                        sn->recordCardNumber = oldRecordCardNumber;
                        cout << "������ ������ ����� �������� ������ ������� ��� ���� � ��";
                        _getch();
                    }
                }
            }
            //resultSelectedItem = exitInt;
            break;
        case 1:
            sn = new StudentNode();
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 10; j++)
                    sn->examsRecordsData[i][j].isEmpty = true;
            st->editStudent(sn);
            if (sdb->getSameRecordCardNumber(sn->recordCardNumber)>=1)
            {
                cout << "������ ������ ����� �������� ������ ������� ��� ���� � ��";
                _getch();
            }
            else
            {
                sdb->DataBase.push_front(*sn);
            }
            break;        
        case 2: //��������� � ����
            sdb->saveDataToFile(sdb->FileName);
            //sdb->saveDataToFile("d:\\db1.txt");
            break;
        case 3: //������� 77
            //ce->setLabel("������� ��������� ��� �������� ��� ��������� �������. ");
            //startYear = ce->setDataInt(1900, 2021);
            //ce->setLabel("������� rjytxysq ��� �������� ��� ��������� �������. ");
            //endYear = ce->setDataInt(1900, 2021);
            startYear = 1900;
            endYear = 2000;

            system("cls");
            cout << "������ ������ ���������" << endl;
            sdb->updateAvrMarks();  //������������� ���� ������� ���� 
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb->sortByAvrMarks();
            cout << "��������������� ������ ���������" << endl;
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb1->DataBase.clear();
            sdb2->DataBase.clear();
            for(auto item: sdb->DataBase)
            { 
                sn = &item;
                year = atoi(sb->split(sn->birthDateString, '.', 2).c_str());
                if (year >= startYear and year <= endYear)
                    sdb1->DataBase.push_front(*sn);
                else
                    sdb2->DataBase.push_front(*sn);
            }
            cout << "������ ��������� ����� 1 (��� �������� �� " + std::to_string(startYear) + " �� " + std::to_string(endYear) + " ): " << endl;
            sdb1->printAllSurName_Name_MName_bYaear_avrMarks();
            cout << "������ ��������� ����� 2 (��� �������� �� �� " + std::to_string(startYear) + " �� " + std::to_string(endYear) + " ): " << endl;
            sdb2->printAllSurName_Name_MName_bYaear_avrMarks();
            _getch();
            resultSelectedItem = -1;
            break;
        case 4: //������� 71

            startYear = 1900;
            endYear = 2005;
            system("cls");
            cout << "������ ������ ���������" << endl;
            sdb->updateMarks45(); //50% ������� � �������� �������
            sdb->printAllSurName_Name_MName_bYaear_Marks45();
            sdb->sortByMarks45();
            cout << "\n��������������� ������ ���������" << endl;
            sdb->printAllSurName_Name_MName_bYaear_Marks45();
            sdb1->DataBase.clear();
            sdb2->DataBase.clear();
            for (auto item : sdb->DataBase)
            {
                sn = &item;
                year = atoi(sb->split(sn->birthDateString, '.', 2).c_str());
                if (year >= startYear and year <= endYear){
                    if (sn->Marks45>=0.5)
                        sdb1->DataBase.push_front(*sn);
                    else
                        sdb2->DataBase.push_front(*sn);
                }
            }
            cout << "\n������ ��������� 4 � 5 > 50%: " << endl;
            sdb1->printAllSurName_Name_MName_bYaear_Marks45();
            cout << "\n������ ��������� 4 � 5 < 50%: " << endl;
            sdb2->printAllSurName_Name_MName_bYaear_Marks45();            
            cout << "\n������ ��������� 4 � 5 > 50%: ��� ������ " << endl;
            sdb3->DataBase.push_front(*sdb1->getMinMarks45());
            sdb1->DataBase.erase(sdb1->getMinMarks45());
            sdb3->DataBase.push_front(*sdb1->getMinMarks45());
            sdb3->printAllSurName_Name_MName_bYaear_Marks45();
            cout << "\n������ ��������� 4 � 5 < 50%: ��� ������" << endl;
            sdb3->DataBase.clear();
            sdb3->DataBase.push_front(*sdb2->getMaxMarks45());
            sdb1->DataBase.erase(sdb2->getMaxMarks45());
            sdb3->DataBase.push_front(*sdb2->getMaxMarks45());
            sdb3->printAllSurName_Name_MName_bYaear_Marks45();
            _getch();
            resultSelectedItem = -1;
            break;
        case 5: 
            //������� 31. ����������� ���� ��������� � ������� �������� 5 � �����, 
            //    ���������� ��� ���� ���������, ������� ���������� �� ������� ������������.
            //    ������������� ������������� ��� ������������� ����.
            system("cls");
            sdb->getRangeSem();
            cout << "������ ������ ���������" << endl;
            sdb->updateCountMarks5();
            sdb->printAllSurName_Name_MName_bYaear_countMarks5();
            sdb->sortByCountMarks5();
            cout << "\n��������������� ������ ���������" << endl;
            sdb->printAllSurName_Name_MName_bYaear_countMarks5();
            _getch();
            break;
        case 6:
            //������� 27. ������������� ������ �� ������������ � ������ ������ 
            // ��� �������� �� ���������� ������������
            system("cls");
            sdb->getRangeSem();
            cout << "������ ������ ���������" << endl;
            sdb->updateAvrMarksRangeSem();  //������������� ���� ������� ���� 
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb->sortByAvrMarks();
            cout << "\n��������������� ������ ���������" << endl;
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            _getch();
            break;
        case 7:
            //������� 57. ����������� ���� ���������, � ������� �� ��� ����� �������� �� ����� 25 % ������ 
            //�) 3 �) 3 � 4 �) 5 �) 3 � 5 �) 4 � 5. 
            //�������� � - � ���������� �� ������� ������������.
            //�� ����� ������� ��� 1, ��� � ��������� ��� ��� ��������, 
            //� ��������� ��������� ���� ��������...
            ce->setLabel("������� ��������� ��� �������� ��� ��������� �������. ");
            startYear = ce->setDataInt(1900, 2021);
            ce->setLabel("������� �������� ��� �������� ��� ��������� �������. ");
            endYear = ce->setDataInt(1900, 2021);
            //startYear = 1900;
            //endYear = 2005;
            sdb1->DataBase.clear();
            for (auto item : sdb->DataBase)           {
                sn = &item;
                year = atoi(sb->split(sn->birthDateString, '.', 2).c_str());
                if (year >= startYear and year <= endYear)
                    sdb1->DataBase.push_front(*sn);
            }
            sdb1->updateCountMarks543();  //������������� ���� 
            var57(sdb1);
            _getch();
            break;
        case 8:
            //������� 43. ������� ������ �� 2 �����, � ������� ����� ��� ������������� ����:
            //1) �� �������� �� � �� �;
            //2) �� �������� �� � �� �.
            //������ ����� ������������� � ������� ���������� �������� ���� �� ��� �����
            system("cls");
            cout << "������ ������ ���������" << endl;
            sdb->updateAvrMarks();  //������������� ���� ������� ���� 
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            sdb->sortByAvrMarks();
            cout << "\n��������������� ������ ���������" << endl;
            sdb->printAllSurName_Name_MName_bYaear_avrMarks();
            firstPartString = "������������������������������";
            sdb1->DataBase.clear();
            sdb2->DataBase.clear();
            for (auto item : sdb->DataBase) {
                for (int i = 0; i<firstPartString.length(); i++)
                    if (item.surName[0] == firstPartString[i]){
                        sdb1->DataBase.push_front(item);
                    }
            }
            cout << "\nC����� ��������� �� �������� �� � �� �" << endl;
            sdb1->printAllSurName_Name_MName_bYaear_avrMarks();     
            for (auto item : sdb->DataBase){
                bool isExist = false;
                for (auto item1 : sdb1->DataBase)
                    if (strcmp(item.surName.c_str(), item1.surName.c_str()) == 0)
                        isExist = true;
                if (isExist == false)
                    sdb2->DataBase.push_front(item);
            }

            cout << "\nC����� ��������� �� �������� �� � �� �" << endl;
            sdb2->printAllSurName_Name_MName_bYaear_avrMarks();
            _getch();
            break;
        case 9:
            /*
                ������������� ������ �� �������� ������������ �����
                ����� ��� ���������� ������ (� ��� �����, ��������, � ����), �������� ��
                ������� ������������. � ������� ���� ��������
             */
            break;
        case 10:
            resultSelectedItem = exitInt;
            break;
        default:
            break;
        }
    }
    //_getch();
    }
}

