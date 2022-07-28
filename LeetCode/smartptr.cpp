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

	auto_ptr<int> aptr2 = aptr; // aptr2����aptr������Ȩ
	cout << *aptr2 << endl;
	//cout << *aptr << endl; // ���򱨴�

	aptr.release();
	aptr2.release();


	// �滻auto_ptr��ʵ�ֶ�ռʽӵ�л��ϸ�ӵ��
	unique_ptr<int> uniptr(new int(10));
	cout << *uniptr << endl;

	//unique_ptr<int> uniptr2 = uniptr; //�������������Ƿ�����ԴΪ�ϸ�ռ��
	unique_ptr<int> uniptr2(new int(20));
	cout << *uniptr2 << endl;
	uniptr.swap(uniptr2);
	cout << *uniptr << " " << *uniptr2 << endl;

	uniptr.release();
	uniptr2.release();

	shared_ptr<int> sharedptr1(new int(10));
	shared_ptr<int> sharedptr2 = sharedptr1;
	weak_ptr<int> weakptr1 = sharedptr1;

	cout << *sharedptr1 << " " << *sharedptr2 << endl;
	cout << sharedptr1.use_count() << endl; // ��Դ�����ü���
	
	cout << boolalpha;
	cout << sharedptr1.unique() << endl;;
	
	sharedptr1.reset(); // �޲����򽫵�ǰ����ָ��
	cout << weakptr1.use_count() << endl;
}
