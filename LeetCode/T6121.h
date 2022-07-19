#pragma once
#ifndef T6121_H_
#define T6121_H_

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class T6121
{
private:
	vector<string> nums;
	vector<vector<int>> queries;

public:
	void M6121();
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries);
};

#endif // !T6121_H_