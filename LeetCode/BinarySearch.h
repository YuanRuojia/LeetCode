#pragma once
#include <iostream>
#include <vector>

using namespace std;

class BinarySearch
{
public:
	static int search(vector<int>& nums, int target); // 普通二分查找
	static int firstbigger(vector<int>& nums, int target); // 第一个大于目标
	static int firstbiggerequal(vector<int>& nums, int target); // 第一个大于等于目标
	static int firstsmaller(vector<int>& nums, int target); // 最后一个小于目标
	static int firstsmallerequal(vector<int>& nums, int target); // 最后一个小于等于目标
};