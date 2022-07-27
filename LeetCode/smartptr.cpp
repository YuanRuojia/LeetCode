#include <iostream>
#include "smartptr.h"

void smartptr::smartptrtest()
{
	//C++98,C11已弃用，所有权模式
	auto_ptr<int> aptr(new int(10));
	cout << *aptr << endl;

	int* originptr = aptr.get(); // 获得原生指针
	cout << *originptr << endl;

	aptr.reset(new int(20));
	cout << *aptr << endl;

	aptr.release();
}
