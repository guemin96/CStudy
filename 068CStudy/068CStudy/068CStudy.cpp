#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
//visual Studio 2019에서는 strcpy 함수를 사용하면 오류가 발생한다. 그렇기 때문에 위의 코드를 사용하여 오류를 무시해준다.
using namespace std;

class String {
public:
	String() {
		cout << "String() 생성자 호출" << endl;
		strData = NULL;
		len = 0;
	}//기본 생성자
	String(const char* str) {
		cout << "String(const char*) 생성자 호출" << endl;

		len = strlen(str);
		strData = new char[len + 1];

		cout << "strData 할당 :" << (void*)strData << endl; 

		strcpy(strData, str);

	}
	String(const String& rhs)
	{
		cout << "String(String &rhs) 생성자 호출" << endl;
		strData = new char[rhs.len + 1];
		cout << "strData 할당 : " << (void*)strData << endl;
		strcpy(strData, rhs.strData);
		len = rhs.len;
	}

	~String() {
		cout << "String() 소멸자 호출" << endl;
		delete[] strData; 
		cout << "strData 해제 : " << (void*)strData << endl;

		strData = NULL;

	}// 소멸자

	//연산자 오버로딩 시작
	String &operator=(const String &rhs) {//레퍼런스 변수를 사용하지 않고 const String rhs를 해주면 복사생성자 방식으로 객체를 또 생성하게 됨
		//call by reference
		if (this!=&rhs)// rhs객체의 주소값
		{

			cout << "strData 해제 : " << (void*)strData << endl;

			delete[] strData; // 연산자 오버로딩을 통한 깊은 복사의 경우에는 기존의 strData에 값이 들어가있을 수도 있기 때문에 delete[]를 통해 초기화시켜준다.
			strData = new char[rhs.len + 1];
			cout << "strData 할당 : " << (void*)strData << endl;
			strcpy(strData, rhs.strData);
			len = rhs.len;

		}
		return *this;

		//rhs의 경우에는 반환타입이 const String이기 때문에 *this를 통해 반환시켜준다.
	}
	//연산자 오버로딩 끝


	char* GetStrData() const {
		return strData;
	}

	int GetLen() const {
		return len;
	}
private:
	char* strData;
	int len; 

};

int main()
{
	String s1("hello");
	String s2(s1); // 복사 생성자 String(String &rhs)
	String s3("heeell");
	s3.operator=(s1);
	//String s4;
	s3.operator=(s3);

	s3 = s1;  // 

	int a = 5;
	int b;
	int c = b = a;//등호 연산자의 경우 오른쪽부터 계산

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	cout << "gd" << endl;
	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	cout << s3.GetStrData() << endl;

}



