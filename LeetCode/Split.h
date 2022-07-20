#pragma once
#ifndef SPLIT_H_
#define SPLIT_H_

#include <string>
#include <vector>

using namespace std;

namespace Split {
	vector<string> Split(string input, const char delim);
}

#endif // !SPLIT_H_