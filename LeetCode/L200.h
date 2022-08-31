#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int directionx[4] = {-1, 0, 1, 0};
int directiony[4] = {0, 1, 0, -1};

class L200
{
    void DFS(vector<vector<char>>& grid, int x, int y) {
        int xlen = grid.size();
        int ylen = grid[0].size();

        grid[x][y] = '0';

        for (int i = 0; i < 4; i++) {
            if (x + directionx[i] >= 0 && x + directionx[i] < xlen && y + directiony[i] >= 0 && y + directiony[i] < ylen)
                if(grid[x + directionx[i]][y + directiony[i]] == '1')
                    DFS(grid, x + directionx[i], y + directiony[i]);
        }
    }

    void BFS(vector<vector<char>>& grid, int x, int y) {
        int xlen = grid.size();
        int ylen = grid[0].size();
        queue<pair<int, int>> points;
        points.push(make_pair(x, y));

        while (!points.empty()) {
            pair<int, int> cur = points.front();
            points.pop();

            grid[cur.first][cur.second] = '0';
            for (int i = 0; i < 4; i++) {
                int x = cur.first + directionx[i];
                int y = cur.second + directiony[i];

                if (x >= 0 && x < xlen && y >= 0 && y < ylen) {
                    if (grid[x][y] == '1') {
                        points.push(make_pair(x, y));
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int xlen = grid.size();
        int ylen = grid[0].size();
        int ans = 0;

        for (int x = 0; x < xlen; x++) {
            for (int y = 0; y < ylen; y++) {
                if (grid[x][y] == '0') {
                    DFS(grid, x, y);
                    ans++;
                }
            }
        }

        return ans;
    }

    void test() {
        int x;
        int y;
        cin >> x >> y;
        vector<vector<char>> grid;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cin >> grid[x][y];
            }
        }
    }
};

