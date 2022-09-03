#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L54
{
public:
    const int directionx[4] = {0, 1, 0, -1};
    const int directiony[4] = { 1, 0, -1, 0 };

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int xlen = matrix.size();
        int ylen = matrix[0].size();
        vector<vector<int>> path(xlen + 2, vector<int>(ylen + 2, 0));
        for (int i = 0; i < ylen + 2; i++) {
            path[0][i] = 1;
            path[xlen + 1][i] = 1;
        }
        for (int i = 0; i < xlen + 2; i++) {
            path[i][0] = 1;
            path[i][ylen + 1] = 1;
        }

        int x = 1;
        int y = 1;
        int dir = 0;
        int failtime = 0;
        while (true) {
            if (path[x][y] == 1) { // 方向改变
                if (++failtime == 4)
                    break;

                x -= directionx[dir];
                y -= directiony[dir];

                dir = (dir + 1) % 4;
                x += directionx[dir];
                y += directiony[dir];
                continue;
            }

            failtime = 0;

            path[x][y] = 1;
            ans.push_back(matrix[x-1][y-1]);

            x += directionx[dir];
            y += directiony[dir];
        }

        return ans;
    }
};

