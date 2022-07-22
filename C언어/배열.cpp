/*
	배열 : 동일한 데이터형 변수의 집합 -> 배열의 한 요소의 메모리사이즈는 데이터형에 따라 구분된다.
	배열을 선언하면 메모리상에 연속적인 공간에 할당된다.
	배열의 시작주소 상수의 차원을 알고 싶으면 배열 구성요소 중 가장 큰 요소의 차원보다 한 차원 높게 지정하면 된다.

	Error가 발생하는 다양한 코드들
	1. int a[]; -> 배열의 첨자를 생략하고 선언하기 위해서는 선언과 동시에 초기화를 해주어야한다.
	2. int ary[4]; ary = 7; -> ary는 배열의 시작주소 상수를 의미하고 int* type이므로 상수 7을 대입할 수 없다.
	3. int ary[3] = {1,2,3,4}; -> 선언한 배열 요소의 개수보다 초기화한 데이터가 더 많으면 안된다.

	** 다차원 배열
	2차원 배열[행][열]
	3차원 배열[면][행][열]

	다차원 배열의 시작주소 상수의 type을 알고 싶다면 배열의 구성요소를 정확하게 파악해야한다.
	가장 큰 구성요소의 차원에 +1 = 배열의 시작주소 상수
	ex) int ary[2][3];
	ary배열의 구성요소 1.) int형 요소 6개 2.) int[3]형 요소 2개 -> 시작주소 상수의 type은 int[3]에 +1차원을 한 int(*)[3] type

	** 문자 배열
*/

#include <stdio.h>
#pragma warning(disable:4996)

void array1_output(const char* msg, int* p, int size);
void array2_output(const char* msg, int(*p)[3], int size);
void array3_output(const char* msg, int(*p)[2][2], int size);
void char1_output();
void char2_output();


int main(void)
{
	
	int ary1[5] = { 1,2,3,4,5 };
	// 1차원배열 요소의 개수 = 배열 전체의 메모리 사이즈 / 배열 한 요소의 메모리 사이즈
	int ary1Size = sizeof(ary1) / sizeof(ary1[0]);

	int ary2[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	// 2차원배열 행의 개수 = 배열 전체의 메모리 사이즈 / 배열 한 행의 메모리 사이즈
	int ary2Row = sizeof(ary2) / sizeof(ary2[0]);

	int ary3[2][2][2] = { {{1,2}, {3,4}}, {{5,6}, {7,8}} };
	// 3차원배열 면의 개수 = 배열 전체의 메모리 사이즈 / 배열 한 면의 메모리 사이즈
	int ary3Face = sizeof(ary3) / sizeof(ary3[0]);

	char charAry1[] = "Hello World!";

	// 각 문자열이 하나의 행을 이루고 data가 할당된 메모리size보다 작다면 남는 부분은 0으로 채운다.
	char charAry2[][6] = { "Hello", "World" };
	// 문자열을 구분해주는 공백문자를 강제로 다른 문자로 바꾸기
	charAry2[0][5] = 'a';
	// "Hello"를 출력하려고 했지만 공백문자가 'a'로 바뀌는 바람에 "HelloaWorld"가 출력된다.
	printf("%s\n", charAry2[0]);
	
	array1_output("1차원 배열", ary1, ary1Size);
	array2_output("2차원 배열", ary2, ary2Row);
	array3_output("3차원 배열", ary3, ary3Face);
	
	return 0;
}

// 배열명은 곧 그 배열의 시작주소 상수
// 아래 함수에서 1차원 배열의 시작주소 상수를 받기 위해 파라미터로 int*형 변수를 선언
void array1_output(const char*msg, int* p, int size) {
	int i;
	printf("%s\n", msg);
	for (i = 0; i < size; i++) {
		// 포인터 변수 p에 인자로 받은 배열의 주소 상수가 담겨 있으므로 배열처럼 사용가능
		printf("%d열 : %d ", i, p[i]);
	}
	printf("\n");
	return;
}

// 2차원 배열의 시작주소 상수를 받기 위해 파라미터로 int(*)[3]형 변수를 선언
void array2_output(const char* msg, int(*p)[3], int size) {
	int i, j;
	printf("%s\n", msg);
	for (i = 0; i < size; i++) {
		printf("%d행\n", i);
		for (j = 0; j < 3; j++) {
			printf("%d열 : %d ", j, p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

// 3차원 배열의 시작주소 상수를 받기 위해 파라미터로 int(*)[2][2]형 변수를 선언
void array3_output(const char* msg, int(*p)[2][2], int size) {
	int i, j, k;
	printf("%s\n", msg);
	for (i = 0; i < size; i++) {
		printf("%d면\n", i);
		for (j = 0; j < 2; j++) {
			printf("%d행\n", j);
			for (k = 0; k < 2; k++) {
				printf("%d열 : %d ", k, p[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void char1_output() {

}

void char2_output() {

}