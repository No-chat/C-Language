/*
	함수는 특정기능을 수행하기 위한 코드 블럭{}이다 -> 함수는 하나의 기능만 수행하도록 하는 것이 제일 바람직하다.
	함수 내부에서 함수를 호출하는 방식을 너무 많이 쓰면 좋지 않다. main함수에서 call하고 return이 일어나는 것이 좋은 것 같다
	함수의 구성요소 : 선언부, 호출부, 정의부
	메이커에서 제공하는 SLF들은 선언부 -> 헤더파일, 호출부 -> 코드작성파일, 정의부 -> 라이브러리루틴에 존재

	함수는 변수를 사용할 때 본인의 정의부에 선언되어있는 지 확인하고 선언x라면 extern변수가 선언되어있는 지 확인한다.

	argument로 전달하는 값을 잘 확인 잘 확인후 call by value인지 call by pointer인지 구분

*/
#include <stdio.h>

void callByValue(int);
void callByPointer(int*);


int main()
{
	int a = 10;
	int* p = &a;

	// call by value
	callByValue(a);

	// call by pointer같지만 p에 저장된 '값'인 a의 주소를 보냈으므로 call by value이다.
	// call by pointer이려면 callByPointer(&a)로 써주면 된다.
	callByPointer(p);

	return 0;
}

void callByValue(int p) {
	printf("call by value : %d\n", p);
}

void callByPointer(int* p) {
	printf("call by pointer : %d\n", *p);
}