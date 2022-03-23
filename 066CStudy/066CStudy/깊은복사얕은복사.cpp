
#include <iostream>

using namespace std;

void Test1() {

	int* a = new int(5);
	int* b = new int(6);

	cout << a << endl;
	cout << b << endl;
	cout << *a << endl;
	cout << *b << endl;

	// a = b(얕은 복사) 이렇게 하면 안됨 -> a와 b는 현재 주소를 뜻하기 때문에 
	// 실질적인 데이터가 변하지 않고 delete에서 데이터를 지워주지 못한다. 
	*a = *b; //(깊은 복사) 포인터를 사용해서 복사해줘야 함.

	delete a;
	delete b;

}

