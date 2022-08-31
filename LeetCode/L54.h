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
        int xlen = matrix.size();
        int ylen = matrix[0].size();
        vector<vector<int>> path(xlen + 1, vector<int>(ylen + 1, 0));

    }
};

