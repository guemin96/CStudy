// 066CStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//복사 생성자 파트
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

		len = strlen(str);// str만큼의 문자열 길이를 len에 넣어줌
		strData = new char[len + 1]; // +1를 해주는 이유는 맨 마지막에 null값이 추가되기 때문에
		//Ex) char a[] = "abc\0"; 
		
		cout << "strData 할당 :"<<(void*)strData << endl; // strData에 문자열 값뿐만 아니라 NULL도 들어갈 수 있기 때문에
		//void*를 사용해서 주소값만이라도 복사해서 저장할 수 있도록 한다.-> 대신 void*의 형식을 가진 변수는 안에 데이터를 변경할 수 없다.

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
		delete[] strData; //문자열을 해제할때는 delete[]를 써주기
		cout << "strData 해제 : " << (void*)strData << endl;

		strData = NULL;// delete를 해준 다음 NULL로 초기화를 해준다.

	}// 소멸자

	char* GetStrData() const {
		return strData;
	}//  strData를 반환하는데 이 변수의 형태가 char*이기 때문에 설정해준다.

	int GetLen() const {
		return len;
	}
private:
	char* strData;
	int len; // 실시간으로 문자열의 길이 변화

};

int main()
{
	String s1("hello");
	String s2(s1); // 복사 생성자 String(String &rhs)
	

	cout << "gd" << endl;
	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	


}



