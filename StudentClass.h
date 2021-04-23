#include <string>
#include "BirthDateClass.h"
#include "ExamsResultsClass.h"
#include "StringBuilderClass.h"
#include "StringMasClass.h"
using namespace std;
class StudentClass
{
private:
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
	StringMasClass stringMas;

public:


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

	void UpdateMasString() {

		stringMas.Erase();
		StringBuilderClass sb = StringBuilderClass();
		string tmpString = sb.setParam("surName", surName);
		stringMas.Add(tmpString);
		string tmpString = sb.setParam("name", name);
		stringMas.Add(tmpString);		
		string tmpString = sb.setParam("middleName", middleName);
		stringMas.Add(tmpString);		
		string tmpString = sb.setParam("faculty", faculty);
		stringMas.Add(tmpString);
		string tmpString = sb.setParam("department", department);
		stringMas.Add(tmpString);
		string tmpString = sb.setParam("group", group);
		stringMas.Add(tmpString);		
		int intSex = 1;
		if (sex)
			intSex = 1;
		else
			intSex = 0;
		string tmpString = sb.setParam("sex", intSex);
		stringMas.Add(tmpString);		
		string tmpString = sb.setParam("startYear", startYear);
		stringMas.Add(tmpString);




	}
};
