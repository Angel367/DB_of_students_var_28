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
		examsResults.add(0, 0, "���� ���������������� 1", 5);
		examsResults.add(0, 1, "���������� 1", 5);
		examsResults.add(0, 2, "����������� 1", true);
		examsResults.add(1, 0, "���� ���������������� 2", 5);
		examsResults.add(1, 1, "���������� 2", 5);
		examsResults.add(1, 2, "����������� 2", true);
	}

	void UpdateMasString() {
		stringMas.Erase();
		StringBuilderClass sb = StringBuilderClass();
		stringMas.Add(sb.setParam("surName", surName));
		stringMas.Add(sb.setParam("name", name));
		stringMas.Add(sb.setParam("middleName", middleName));
		stringMas.Add(sb.setParam("faculty", faculty));
		stringMas.Add(sb.setParam("department", department));
		stringMas.Add(sb.setParam("group", group));
		int intSex = 1;
		if (sex)
			intSex = 1;
		else
			intSex = 0;
		stringMas.Add(sb.setParam("sex", intSex));
		stringMas.Add(sb.setParam("startYear", startYear));
		stringMas.Add(sb.setParam("birthDate", birthDate.getString())); //27_12_1984
		int sem = 0;
		int num = 0;
		for (int sem=0;sem<9;sem++)
			for (int num=0;num<10;num++)
				if (not examsResults.isEmpty(sem,num)){
					//examsResults_sem_num_n - �������� �������� ��� ������
					stringMas.Add(sb.setParam("examsResults_" + std::to_string(sem) + "_" + std::to_string(num) + "_n", examsResults.getName(sem, num)));
					//examsResults_sem_num_m - ������
					stringMas.Add(sb.setParam("examsResults_" + std::to_string(sem) + "_" + std::to_string(num) + "_m", std::to_string(examsResults.getMark(sem, num))));
				}
		//stringMas.dislay();
	}

	string getStringRecord() {
		return stringMas.getNext();
	}

	bool getInitStringRecord() {
		return stringMas.getInit();
	}

};
