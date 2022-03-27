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
		alloc(len);
		strcpy(strData, str);

	}
	String(const String& rhs)//복사 생성자
	{
		cout << "String(String &rhs) 생성자 호출" << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}

	~String() {
		cout << "String() 소멸자 호출" << endl;
		release();
		strData = NULL;

	}// 소멸자

	//연산자 오버로딩 시작 (복사 대입 생성자)
	String& operator=(const String& rhs) {//레퍼런스 변수를 사용하지 않고 const String rhs를 해주면 복사생성자 방식으로 객체를 또 생성하게 됨
		//call by reference
		if (this != &rhs)// rhs객체의 주소값
		{

			cout << "strData 해제 : " << (void*)strData << endl;

			delete[] strData; // 연산자 오버로딩을 통한 깊은 복사의 경우에는 기존의 strData에 값이 들어가있을 수도 있기 때문에 delete[]를 통해 초기화시켜준다.
			cout << "String 복사대입생성자 호출" << endl;

			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);

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

	void alloc(int len) {
		strData = new char[len + 1];
		cout << "strData 할당 : " << (void*)strData << endl;
	}
	void release() {
		delete[] strData;
		cout << "strData 해제 : " <<(void*)strData << endl;
	}
	char* strData;
	int len;

};
String getName() {
	cout << "=2=" << endl;
	String res("Doodle");
	cout << "=3=" << endl;

	return res;
}

int main()
{
	//String a;
	//cout << "=1=" << endl;
	//a = getName();
	// 연산자 오버로딩을 사용한 복사 대입 생성자만 실행되어야하는데 복사생성자까지 실행되는 이유
	// getName()함수의 return res부터 a에 대입되는 실행과정 중간에 복사 생성자가 실행되는데
	// return을 하는 과정에서 리턴한 값을 저장하는 임시객체가 만들어지는 과정에서 복사 생성자가 실행이 된다.

	//cout << "=4=" << endl;
	
	// R-Value(Right) 우변에만 올 수 있는 value (주로 상수)
	// L-Value(Left)	좌변,우변 둘 다 올 수 있는 value

	//임시 객체는 R-Value이다.!! 메모리상에 저장됨
	cout << "=1=" << endl;

	String&& r = getName();//R-Value Reference
	cout << &r <<" "<<"생성완료" << endl;
	cout << "=4=" << endl;

}



