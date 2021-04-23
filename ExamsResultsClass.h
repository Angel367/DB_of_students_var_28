#pragma once
class ExamsResultsClass
{
	struct ExamsRecords {
		string Name;
		int Mark; // 1 - �����
				  // 0 - �� �����    
				  // 2,3,4,5 - ������
		bool isEmpty; // ��������� �� ����?
	};
//private:
//	ExamsRecords data[9][10];
public:
	ExamsRecords data[9][10];
	ExamsResultsClass() {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				data[i][j].isEmpty = true;
	}
	bool add(int sem, int num, string Item, int Mark) {
		data[sem][num].isEmpty = false;
		data[sem][num].Name = Item;
		data[sem][num].Mark = Mark;
		return true;
	}
	bool add(int sem, int num, string Item, bool zach) {
		data[sem][num].isEmpty = false;
		data[sem][num].Name = Item;
		if (zach)
			data[sem][num].Mark = 1;
		else
			data[sem][num].Mark = 0;
		return true;
	}
	bool isEmpty(int sem, int num) {
		return data[sem][num].isEmpty;
	}
	string getName(int sem, int num) {
		return data[sem][num].Name;
	}	
	int getMark(int sem, int num) {
		return data[sem][num].Mark;
	}
};

