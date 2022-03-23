// 066CStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class String {
public:
	String() {
		strData = NULL; // 포인터에서는 0보다는 주로 NULL을 사용한다.
		len = 0;
	}//기본 생성자
	String(const char *str) {
		//strData=str 이렇게 할 경우에는 얕은 복사일 뿐만 아니라 대입도 되지 않는다.
		//형식이 char*와 chat이기 때문에
		len = strlen(str);// str만큼의 문자열 길이를 len에 넣어줌
		strData = new char[len+1]; // +1를 해주는 이유는 맨 마지막에 null값이 추가되기 때문에
		//Ex) char a[] = "abc\0"; 
		strcpy(strData, str);//덮어씌워질 문자열, 복사할 데이터
	}

	~String() {
		delete[] strData; //문자열을 해제할때는 delete[]를 써주기
	}// 소멸자

	char* GetStrData() const{
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
	String s; //선언만 해놓은 경우에는 동적할당 X



}


