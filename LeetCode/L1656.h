#pragma once
#include <iostream>
#include <vector>

using namespace std;

class L1656
{
private:
    int num;
    int ptr;
    vector<string> stream;
public:
    L1656(int n);
    vector<string> insert(int idKey, string value);
};

