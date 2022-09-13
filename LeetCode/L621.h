#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class L621
{
public:
    // ����map��������������˳�����Ȱ����ܹ�ִ�е�����

    static void findtasks(unordered_map<char, int>& gaptime, vector<char> tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            auto itr = gaptime.find(tasks[i]);
            if (itr == gaptime.end()) {
                gaptime[tasks[i]] = 0;
            }
        }
    }

    static char gettask(unordered_map<char, int>& gaptime) {
        for (auto itr : gaptime) {
            if (itr.second == 0)
                return itr.first;
        }

        return '0';
    }

    static void reducetime(unordered_map<char, int>& gaptime) {
        for (auto itr : gaptime) {
            if (itr.second > 0)
                gaptime[itr.first]--;
        }
    }

    static int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> gaptime;
        int time = 0;

        findtasks(gaptime, tasks);

        while(tasks.size() != 0) {
            char task = gettask(gaptime);
            if (task == '0') { // û������������
                reducetime(gaptime);
                time++;
                continue;
            }

            auto pos = find(tasks.begin(), tasks.end(), task);
            if (pos != tasks.end()) {
                reducetime(gaptime);
                gaptime[task] = n;

                swap(*pos, tasks[tasks.size() - 1]);
                tasks.pop_back();

                time++;
            }
            else { // ��ǰ��������������
                gaptime[task] = -1;
            }
        }

        return time;
    }
};

