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

	auto_ptr<int> aptr2 = aptr; // aptr2剥夺aptr的所有权
	cout << *aptr2 << endl;
	//cout << *aptr << endl; // 程序报错

	aptr.release();
	aptr2.release();


	// 替换auto_ptr，实现独占式拥有或严格拥有
	unique_ptr<int> uniptr(new int(10));
	cout << *uniptr << endl;

	//unique_ptr<int> uniptr2 = uniptr; //编译器报错，语句非法，资源为严格占有
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
	cout << sharedptr1.use_count() << endl; // 资源的引用计数
	
	cout << boolalpha;
	cout << sharedptr1.unique() << endl;;
	
	sharedptr1.reset(); // 无参数则将当前智能指针
	cout << weakptr1.use_count() << endl;
}
