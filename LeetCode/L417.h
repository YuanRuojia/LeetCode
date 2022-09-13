#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class L417
{
    int dirx[5] = { 0, -1, 0, 1, 0 };
    int diry[5] = { 0, 0, 1, 0, -1 };

public:
    static inline bool getPacific(int x, int y) {
        if (x == 0)
            return true;
        else if (y == 0)
            return true;
        else
            return false;
    }

    static inline bool getAtlantic(int x, int y, int xlen, int ylen) {
        if (x == xlen - 1)
            return true;
        else if (y == ylen - 1)
            return true;
        else
            return false;
    }

    static inline bool inrange(int xlen, int ylen, int x, int y) {
        return x >= 0 && x < xlen&& y >= 0 && y < ylen;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int xlen = heights.size();
        int ylen = heights[0].size();

        for (int x = 0; x < heights.size(); x++) {
            for (int y = 0; y < heights[0].size(); y++) {
                bool Pacific = false;
                bool Atlantic = false;
                stack<pair<int, int>> rainpath;
                rainpath.push(make_pair(x, y));
                vector<vector<int>> visited(xlen, vector<int>(ylen, 0));

                while (!rainpath.empty()) {
                    pair<int, int> cur = rainpath.top();
                    rainpath.pop();

                    for (int i = 0; i < 5; i++) {
                        if (inrange(xlen, ylen, cur.first + dirx[i], cur.second + diry[i]) && visited[cur.first + dirx[i]][cur.second + diry[i]] == 0) {
                            if (i == 0) {
                                if (getPacific(cur.first + dirx[i], cur.second + diry[i]))
                                    Pacific = true;
                                if (getAtlantic(cur.first + dirx[i], cur.second + diry[i], xlen, ylen))
                                    Atlantic = true;
                                visited[cur.first + dirx[i]][cur.second + diry[i]] = 1;
                                continue;
                            }

                            if (heights[cur.first][cur.second] >= heights[cur.first + dirx[i]][cur.second + diry[i]]) {
                                rainpath.push(make_pair(cur.first + dirx[i], cur.second + diry[i]));

                                if (getPacific(cur.first + dirx[i], cur.second + diry[i]))
                                    Pacific = true;

                                if (getAtlantic(cur.first + dirx[i], cur.second + diry[i], xlen, ylen))
                                    Atlantic = true;

                                visited[cur.first + dirx[i]][cur.second + diry[i]] = 1;
                            }
                        }
                    }
                }

                if (Pacific && Atlantic)
                    ans.push_back({ x, y });
            }
        }

        return ans;
    }
};

/*
08,13,11,18,14,16,16,04,04,08,10,11,01,19,07
02,09,15,16,14,05,08,15,09,05,14,06,10,15,05
15,16,17,10,03,06,03,04,02,17,00,12,04,01,03
13,06,13,15,15,16,04,10,07,04,19,19,04,09,13
07,01,09,14,09,11,05,04,15,19,06,00,00,13,05
09,09,15,12,15,05,01,01,18,01,02,16,15,18,09
13,00,04,18,12,00,11,00,01,15,01,15,04,02,00
11,13,12,16,09,18,06,08,18,01,05,12,17,13,05
07,17,02,05,00,17,09,18,04,13,06,13,07,02,01
02,03,09,00,19,06,06,15,14,04,08,01,19,05,09
03,10,05,11,07,14,01,05,03,19,12,05,02,13,16
00,08,10,18,17,05,05,08,02,11,05,16,04,09,14
15,09,16,18,09,05,02,05,13,03,10,19,09,14,03
12,11,16,01,10,12,06,18,06,06,18,10,09,05,02
17,09,06,06,14,09,02,02,13,13,15,17,15,03,14
18,14,12,06,18,16,04,10,19,05,06,08,09,01,06
*/