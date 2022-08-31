#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L746
{
public:
	static int minCostClimbingStairs(vector<int>& cost) {
		int prepre = 0;
		int pre = 0;
		int length = cost.size();

		for (int i = 2; i <= length; i++) {
			int next = min(prepre + cost[i - 2], pre + cost[i - 1]);
			prepre = pre;
			pre = next;
		}

		return pre;
	}
};

