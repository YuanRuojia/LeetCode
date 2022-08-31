#pragma once
#include <iostream>
#include <queue>

using namespace std;

class L70
{
public:
    //递归
    /*int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }*/

    //非递归，由低向上
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prepre = 1;
        int pre = 2;
        int ans = 0;
        for (int cur = 3; cur <= n; cur++) {
            ans = prepre + pre;
            prepre = pre;
            pre = ans;
        }

        return ans;
    }
};

