#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

class L202
{
public:
    static bool isHappy(int n) {
        unordered_set<double> nums;
        nums.insert(n);

        int next = 0;
        while (n != 1) {
            while (n != 0) {
                int temp = n % 10;
                n /= 10;
                next += temp * temp;
            }
            n = next;
            next = 0;

            auto itr = find(nums.begin(), nums.end(), n);
            if (itr == nums.end()) {
                nums.insert(n);
            }
            else {
                return false;
            }
        }

        return true;
    }
};

