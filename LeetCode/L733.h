#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class L733
{
public:
	typedef struct point {
		int x;
		int y;
	};

	void test();
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color);
};

