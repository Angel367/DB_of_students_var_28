#pragma once
struct ExamsRecords {
	string name;
	int mark; // 1 - �����
			  // 0 - �� �����    
			  // 2,3,4,5 - ������
	bool isEmpty; // ��������� �� ����?
};
class ExamsResultsClass
{
private:
	ExamsRecords data[9][10];
public:
	//ExamsRecords data[9][10];
	ExamsResultsClass() {
		emptpy();
	}
	void emptpy() {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				data[i][j].isEmpty = true;
	}
	bool add(int sess, string item, int mark) {  //��� ������
		int firstEmptyRow = getFirstEmptyRow(sess);
		if (firstEmptyRow < 9) {
			data[sess][firstEmptyRow].isEmpty = false;
			data[sess][firstEmptyRow].name = item;
			data[sess][firstEmptyRow].mark = mark;
			return true;
		}
		else
			return false;
	}
	bool add(int sess, string itemName, bool zach) { //��� �������
		int mark = 0;
		if (zach)
			mark = 1;
		else
			mark = 0;
		int firstEmptyRow = getFirstEmptyRow(sess);
		if (firstEmptyRow < 9) {
			data[sess][firstEmptyRow].isEmpty = false;
			data[sess][firstEmptyRow].name = itemName;
			data[sess][firstEmptyRow].mark = mark;
			return true;
		}
		else
			return false;
	}
	void setData(ExamsRecords* er) {	
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++) {
				er->isEmpty=data[i][j].isEmpty;
				er->mark=data[i][j].mark;
				er->name=data[i][j].name;
			}	
	}
	int getFirstEmptyRow(int sessNum) {
		for (int i = 0; i < 10; i++) {
			bool flag = data[sessNum][i].isEmpty;
			if (flag)
				return i;
		}
		return -1;
	}

};

