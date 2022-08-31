#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L62
{
public:
    //µÝ¹é
    /*static int _uniquePaths(pair<int, int> limit, int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }

        if (0 < m && m < limit.first && 0 < n && n < limit.second) {
            return _uniquePaths(limit, m - 1, n) + _uniquePaths(limit, m, n - 1);
        }
        else {
            return 0;
        }
    }
    static int uniquePaths(int m, int n) {
        pair<int, int> limit;
        limit.first = m + 1;
        limit.second = n + 1;

        return _uniquePaths(limit, m - 1, n) + _uniquePaths(limit, m, n - 1);
    }*/

    //·ÇµÝ¹é
    static int uniquePaths(int m, int n) {
        vector<vector<int>> map(m, vector<int> (n));

        for (int i = 0; i < m; ++i) {
            map[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            map[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        return map[m - 1][n - 1];
    }
};

