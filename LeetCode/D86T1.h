#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class D86T1
{
public:
    static vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> merge;
        for (int i = 0; i < items1.size(); i++) {
            auto itr = merge.find(items1[i][0]);
            if (itr == merge.end()) { // 未合并元素
                merge.insert({ items1[i][0], items1[i][1] });
            }
            else {
                int value = itr->second;
                value += items1[i][1];
                merge.erase(itr);
                merge.insert({ items1[i][0], value });
            }
        }
        for (int i = 0; i < items2.size(); i++) {
            auto itr = merge.find(items2[i][0]);
            if (itr == merge.end()) { // 未合并元素
                merge.insert({ items2[i][0], items2[i][1] });
            }
            else {
                int value = itr->second;
                value += items2[i][1];
                merge.erase(itr);
                merge.insert({ items2[i][0], value });
            }
        }

        vector<vector<int>> ret;
        for (auto itr : merge) {
            vector<int> temp;
            temp.push_back(itr.first);
            temp.push_back(itr.second);
            ret.push_back(temp);
        }

        return ret;
    }

    static long long taskSchedulerII(vector<int>& tasks, int space) {
        long long days = 0;

        map<int, int> ongoing;
        for (int i = 0; i < tasks.size(); i++) {
            for (auto tempitr = ongoing.begin(); tempitr != ongoing.end(); ) {
                if (--tempitr->second == 0) {
                    tempitr = ongoing.erase(tempitr);
                    continue;
                }

                tempitr++;
            }

            auto itr = ongoing.find(tasks[i]);
            if (itr == ongoing.end()) {
                ongoing.insert({ tasks[i], space+1 });
            }
            else {
                i--;
            }

            days++;
        }

        return days;
    }
};

