#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L14
{
public:
    static string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int cur = 0;
        bool sta = true;
        while (true) {
            for (int i = 0; i < strs.size(); i++) {
                if (cur == strs[i].length()) {
                    sta = false;
                    break;
                }
                if (strs[i][cur] != strs[0][cur]) {
                    sta = false;
                    break;
                }
            }
            if (!sta) {
                break;
            }
            ans.append(strs[0].substr(cur, 1));
            cur++;
        }

        return ans;
    }
};

