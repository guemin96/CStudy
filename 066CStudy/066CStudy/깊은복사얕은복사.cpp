
#include <iostream>

using namespace std;

void Test1() {

	int* a = new int(5);
	int* b = new int(6);

	cout << a << endl;
	cout << b << endl;
	cout << *a << endl;
	cout << *b << endl;

	// a = b(���� ����) �̷��� �ϸ� �ȵ� -> a�� b�� ���� �ּҸ� ���ϱ� ������ 
	// �������� �����Ͱ� ������ �ʰ� delete���� �����͸� �������� ���Ѵ�. 
	*a = *b; //(���� ����) �����͸� ����ؼ� ��������� ��.

	delete a;
	delete b;

}

