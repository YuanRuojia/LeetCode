#pragma once
#include <iostream>
#include <vector>

using namespace std;

class BinarySearch
{
public:
	static int search(vector<int>& nums, int target); // ��ͨ���ֲ���
	static int firstbigger(vector<int>& nums, int target); // ��һ������Ŀ��
	static int firstbiggerequal(vector<int>& nums, int target); // ��һ�����ڵ���Ŀ��
	static int firstsmaller(vector<int>& nums, int target); // ���һ��С��Ŀ��
	static int firstsmallerequal(vector<int>& nums, int target); // ���һ��С�ڵ���Ŀ��
};