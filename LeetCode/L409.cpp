#include "L409.h"

int L409::longestPalindrome(string s)
{
    vector<int> chars (58, 0);

    for (int i = 0; i < s.length(); i++) {
        chars[s[i] - 65]++;
    }

    bool even = true;
    int maxlen = 0;
    for (int i = 0; i < 58; i++) {
        if (chars[i] % 2 == 0) {
            maxlen += chars[i];
        }
        else {
            if (even) {
                maxlen += chars[i];
                even = false;
            }
            else {
                maxlen += chars[i] - 1;
            }
        }
    }

    return maxlen;
}
