#include <iostream>
#include "smartptr.h"

void smartptr::smartptrtest()
{
	//C++98,C11�����ã�����Ȩģʽ
	auto_ptr<int> aptr(new int(10));
	cout << *aptr << endl;

	int* originptr = aptr.get(); // ���ԭ��ָ��
	cout << *originptr << endl;

	aptr.reset(new int(20));
	cout << *aptr << endl;

	aptr.release();
}
