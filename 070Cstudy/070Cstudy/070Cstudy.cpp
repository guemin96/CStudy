#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
//visual Studio 2019에서는 strcpy 함수를 사용하면 오류가 발생한다. 그렇기 때문에 위의 코드를 사용하여 오류를 무시해준다.
using namespace std;

//이동생성자, 이동 대입 연산자 
//다시 공부하기 
class String {
public:
	String() {
		cout << "String() 생성자 호출 : " << this << endl;
		strData = NULL;

		len = 0;
	}//기본 생성자

	String(const char* str) {
		cout << "String(const char* str) : " << this << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	String(const String &rhs)  {
		cout << "String(const String &rhs) : " << this << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}
	String& operator=(const String &rhs) {
		cout << "String& operator=(const String &rhs)"<<this << endl;
		if (this!=&rhs)
		{

			delete[] strData;
			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);
		}
		return *this;
	}

	~String() {
		cout << "String() 소멸자 호출 : " << this << endl;
		cout << "String() 소멸자 호출 : "<<strData << endl;
		release();
		strData = NULL;

	}// 소멸자

	char* GetStrData() const {
		return strData;
	}

	int GetLen() const {
		return len;
	}
private:
	void alloc(int len) {
		strData = new char[len + 1];
		cout << "strData allocated : " << (void*)strData << endl; 
		// void* 
		// 기본적으로 C언어는 자료형이 다른 포인터끼리 메모리 주소를 저장하면 컴파일 경고가 발생
		// 하지만 void* 는 자료형이 정해지지 않은 특성때문에 어떤 자료형으로 된 포인터든 모두 저장할 수 있다.
		// 반대로 다양한 자료형으로 된 포인터에도 void*를 저장할 수 있다.
	}
	void release() {
		delete[] strData;
		if(strData) cout << "strData released : " << (void*)strData << endl;
	}
	char* strData;
	int len;

};

int main()
{
	String a;
	String b;
	String a1("Hello");
	b = a1;
	cout << a1.GetStrData() << endl;
	cout << b.GetStrData() << endl;



}



