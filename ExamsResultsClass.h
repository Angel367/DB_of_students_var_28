#pragma once
struct ExamsRecords {
	string Name;
	int Mark; // 1 - �����
			  // 0 - �� �����    
			  // 2,3,4,5 - ������
	bool isEmpty; // ��������� �� ����?
};
class ExamsResultsClass
{
//private:
//	ExamsRecords data[9][10];
public:
	//ExamsRecords data[9][10];
	ExamsResultsClass() {
		//for (int i = 0; i < 9; i++)
		//	for (int j = 0; j < 10; j++)
		//		data[i][j].isEmpty = true;
	}
	ExamsRecords add(string Item, int Mark) {  //��� ������
		ExamsRecords er;
		er.isEmpty = false;
		er.Name = Item;
		er.Mark = Mark;
		return er;
	}
	ExamsRecords add(string Item, bool zach) { //��� �������
		ExamsRecords er;
		er.isEmpty = false;
		er.Name = Item;
		if (zach)
			er.Mark = 1;
		else
			er.Mark = 0;
		return er;
	}
	//bool isEmpty(int sem, int num) {
	//	return data[sem][num].isEmpty;
	//}
	//string getName(int sem, int num) {
	//	return data[sem][num].Name;
	//}	
	//int getMark(int sem, int num) {
	//	return data[sem][num].Mark;
	//}
};

