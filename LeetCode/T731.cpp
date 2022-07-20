#include <iostream>
#include "T731.h"

void T731::test() {
	int choice = 0;

	while (choice != -1) {
		cout << "请输入开始和结束时间，使用空格隔开:" << endl;

		int start;
		int end;
		cin >> start >> end;

		if (this->book(start, end)) {
			cout << "添加成功！" << endl;
		}
		else {
			cout << "添加失败！" << endl;
		}

		cout << "结束请输-1:";
		cin >> choice;
	}
}

bool T731::book(int start, int end) {
	Time time = new BookTime;
	time->start = start;
	time->end = end;

	stable_sort(this->Times.begin(), this->Times.end(), [&](Time a, Time b) {
		return a->start < b->start;
		});

	int Lconflict = 0;
	int Rconflict = 0;
	int Mconflict = 0;
	for (int i = 0; i < this->Times.size(); i++) {
		if (this->Times[i]->start <= time->start && this->Times[i]->end >= time->end) {
			Mconflict++;
			continue;
		}
		if (this->Times[i]->start <= time->start && this->Times[i]->end > time->start) {
			Lconflict++;
			continue;
		}
		if (this->Times[i]->start >= time->start && this->Times[i]->start < time->end) {
			Rconflict++;
			continue;
		}
	}

	if (Lconflict >= 2 || Rconflict >= 2 || Mconflict >= 2)
		return false;

	this->Times.push_back(time);
	return true;
}

/*
24 40
1
43 50
1
27 43
1
5 21
1
30 40
1
14 29
1
3 19
1
3 14
1
25 39
1
6 19
*/