#pragma once
#ifndef LISTFUNCTION_H_
#define LISTFUNCTION_H_

#include <string>
#include <vector>
#include "MyList.h"

using namespace std;

namespace ListFunction {
	vector<string> Split(string input, const char delim);
	MyList* ListMerge(MyList* A, MyList* B);
	MyList* KListMerge(vector<MyList*> Lists);
}

#endif // !LISTFUNCTION_H_