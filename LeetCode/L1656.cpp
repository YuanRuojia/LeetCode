#include "L1656.h"

L1656::L1656(int n) {
    this->num = n;
    this->ptr = 1;
    this->stream.resize(n);
}

vector<string> L1656::insert(int idKey, string value) {
    vector<string> ans;
    this->stream[idKey - 1] = value;

    if (this->stream[this->ptr - 1] == "") {
        return ans;
    }
    else {
        while (this->ptr <= this->num && this->stream[this->ptr - 1] != "") {
            ans.emplace_back(this->stream[this->ptr++ - 1]);
        }

        return ans;
    }
}