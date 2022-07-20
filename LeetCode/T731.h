#pragma once
#ifndef T731_H_
#define T731_H_

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct BookTime {
	int start;
	int end;
}BookTime, * Time;

class T731
{
private:
	vector<Time> Times;

public:
	bool book(int start, int end);
	void test();
};

#endif // !T731_H_