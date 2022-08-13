#pragma once
#include <iostream>
#include <vector>

using namespace std;

class D807
{
public:
	static int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto itr1 = find(nums.begin() + i, nums.end(), nums[i] + diff);
            while (itr1 != nums.end()) { // 能查询到下一组
                auto itr2 = find(itr1, nums.end(), *itr1 + diff);
                while (itr2 != nums.end()) {
                    ans++;
                    itr2 = find(itr2 + 1, nums.end(), *itr1 + diff);
                }

                itr1 = find(itr1 + 1, nums.end(), nums[i] + diff);
            }
        }

        return ans;
    }
};

