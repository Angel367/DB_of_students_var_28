#include <string>
#include "BirthDateClass.h"
#include "ExamsResultsClass.h"
#include "StringBuilderClass.h"
using namespace std;
class StudentClass
{
public:
	string surName;
	string name;
	string middleName;
	string faculty;
	string department;
	string group;
	string record�ardNumber;
	bool sex; // true - �������
			  // false - �������
	int startYear;
	BirthDateClass birthDate;
	ExamsResultsClass examsResults;

	void addRusakov() {
		surName = "�������";
		name = "�������";
		middleName = "����������";
		faculty = "10.05.04 �������������-������������� ������� ������������";
		department = "�������� ����������� ������������ � ������������ ���������������";
		group = "����-01-21";
		record�ardNumber = "20�0857";
		sex = true;
		startYear = 2021;
		birthDate.setDate(27, 12, 1984);
		examsResults.addData(0, 1, "���� ���������������� 1", 5);
		examsResults.addData(0, 2, "���������� 1", 5);
		examsResults.addData(0, 3, "����������� 1", true);
		examsResults.addData(1, 1, "���� ���������������� 2", 5);
		examsResults.addData(1, 2, "���������� 2", 5);
		examsResults.addData(1, 3, "����������� 2", true);
	}

	void a() {
		StringBuilderClass sb = StringBuilderClass();
		string s1 = sb.setParam("surName", "��������");
	}
};
