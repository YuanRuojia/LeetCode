#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L1706
{
public:
    static vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            int col = j; // ��ĳ�ʼ��
            for (auto& row : grid) {
                int dir = row[col];
                col += dir; // �ƶ���
                if (col < 0 || col == n || row[col] != dir) { // �����߻� V ��
                    col = -1;
                    break;
                }
            }
            ans[j] = col; // col >= 0 Ϊ�ɹ�����ײ�
        }
        return ans;
    }
};

