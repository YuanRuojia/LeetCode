#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L1592
{
public:
    static string reorderSpaces(string text) {
        int spacenum = 0;
        vector<string> words;
        bool word = false;
        int wordstart = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ') {
                if(!word) {
                    word = true;
                    wordstart = i;
                }
            }
            else {
                if (word) {
                    word = false;
                    words.push_back(text.substr(wordstart, i - wordstart));
                }

                spacenum++;
            }
        }

        int avg = spacenum / (words.size() - 1);
        int more = spacenum % (words.size() - 1);

        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans.append(words[i]);
            for (int s = 0; s < avg; s++)
                ans.append(" ");
        }
        for (int i = 0; i < more; i++) {
            ans.append(" ");
        }

        return ans;
    }
};

