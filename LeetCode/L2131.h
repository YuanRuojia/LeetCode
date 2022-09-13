#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L2131
{
public:
    //给用hash表维护出现过的字符串
    static int longestPalindrome(vector<string>& words) {
        int ans = 0;
        bool palstr = true;
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            reverse(str.begin(), str.end());

            if (words[i] != str) {
                auto itr = find(words.begin(), words.end(), str);
                if (itr != words.end()) {
                    ans += 4;
                    swap(*itr, words[words.size() - 1]);
                    words.pop_back();
                    swap(words[i], words[words.size() - 1]);
                    words.pop_back();
                    i--;
                }
            }
            else {
                auto itr = find(words.begin() + i + 1, words.end(), str);
                if (itr != words.end()) {
                    ans += 4;
                    swap(*itr, words[words.size() - 1]);
                    words.pop_back();
                    swap(words[i], words[words.size() - 1]);
                    words.pop_back();
                    i--;
                }
                else {
                    if (palstr) {
                        ans += 2;
                        palstr = false;
                        swap(words[i], words[words.size() - 1]);
                        words.pop_back();
                        i--;
                    }
                }
            }
        }

        return ans;
    }
};

