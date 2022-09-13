#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class L43
{
public:
    string singlemulti(string a, char b) {
        string ans = "";
        bool add = false;
        int temp = 0;
        int carry = 0;
        reverse(a.begin(), a.end());
        for (int i = 0; i < a.length(); i++) {
            temp = (a[i] - '0') * (b - '0');
            if (add) {
                temp += carry;
                add = false;
            }
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
                add = true;
            }

            ans.append(to_string(temp));
        }
        if (add) {
            ans.append(to_string(carry));
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string singleadd(string a, string b) {
        string ans = "";
        bool add = false;
        int temp = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string L;
        string S;
        if (a.length() > b.length()) {
            L = a;
            S = b;
        }
        else {
            L = b;
            S = a;
        }
        int num0 = L.length() - S.length();
        for (int i = 0; i < num0; i++)
            S.append("0");

        for (int i = 0; i < L.length(); i++) {
            temp = (L[i] - '0') + (S[i] - '0');
            if (add) {
                temp += 1;
                add = false;
            }
            if (temp >= 10) {
                temp %= 10;
                add = true;
            }

            ans.append(to_string(temp));
        }
        if (add) {
            ans.append("1");
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string ADD(vector<string> input) {
        string ans = "";
        for (int i = 0; i < input.size(); i++) {
            ans = singleadd(ans, input[i]);
        }

        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        string first = num1.length() < num2.length() ? num1 : num2;
        string second = num1.length() < num2.length() ? num2 : num1;
        vector<string> multi(10, "");
        vector<string> add;

        for (int i = second.length() - 1; i >= 0; i--) {
            if (multi[second[i] - '0'] == "") {
                multi[second[i] - '0'] = singlemulti(first, second[i]);
            }
            string temp = multi[second[i] - '0'];
            for (int j = second.length() - 1; j > i; j--) {
                temp.append("0");
            }
            add.push_back(temp);
        }

        return ADD(add);
    }
};

