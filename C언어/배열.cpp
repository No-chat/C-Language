/*
	�迭 : ������ �������� ������ ���� -> �迭�� �� ����� �޸𸮻������ ���������� ���� ���еȴ�.
	�迭�� �����ϸ� �޸𸮻� �������� ������ �Ҵ�ȴ�.
	�迭�� �����ּ� ����� ������ �˰� ������ �迭 ������� �� ���� ū ����� �������� �� ���� ���� �����ϸ� �ȴ�.

	Error�� �߻��ϴ� �پ��� �ڵ��
	1. int a[]; -> �迭�� ÷�ڸ� �����ϰ� �����ϱ� ���ؼ��� ����� ���ÿ� �ʱ�ȭ�� ���־���Ѵ�.
	2. int ary[4]; ary = 7; -> ary�� �迭�� �����ּ� ����� �ǹ��ϰ� int* type�̹Ƿ� ��� 7�� ������ �� ����.
	3. int ary[3] = {1,2,3,4}; -> ������ �迭 ����� �������� �ʱ�ȭ�� �����Ͱ� �� ������ �ȵȴ�.

	** ������ �迭
	2���� �迭[��][��]
	3���� �迭[��][��][��]

	������ �迭�� �����ּ� ����� type�� �˰� �ʹٸ� �迭�� ������Ҹ� ��Ȯ�ϰ� �ľ��ؾ��Ѵ�.
	���� ū ��������� ������ +1 = �迭�� �����ּ� ���
	ex) int ary[2][3];
	ary�迭�� ������� 1.) int�� ��� 6�� 2.) int[3]�� ��� 2�� -> �����ּ� ����� type�� int[3]�� +1������ �� int(*)[3] type

	** ���� �迭
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
	// 1�����迭 ����� ���� = �迭 ��ü�� �޸� ������ / �迭 �� ����� �޸� ������
	int ary1Size = sizeof(ary1) / sizeof(ary1[0]);

	int ary2[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	// 2�����迭 ���� ���� = �迭 ��ü�� �޸� ������ / �迭 �� ���� �޸� ������
	int ary2Row = sizeof(ary2) / sizeof(ary2[0]);

	int ary3[2][2][2] = { {{1,2}, {3,4}}, {{5,6}, {7,8}} };
	// 3�����迭 ���� ���� = �迭 ��ü�� �޸� ������ / �迭 �� ���� �޸� ������
	int ary3Face = sizeof(ary3) / sizeof(ary3[0]);

	char charAry1[] = "Hello World!";

	// �� ���ڿ��� �ϳ��� ���� �̷�� data�� �Ҵ�� �޸�size���� �۴ٸ� ���� �κ��� 0���� ä���.
	char charAry2[][6] = { "Hello", "World" };
	// ���ڿ��� �������ִ� ���鹮�ڸ� ������ �ٸ� ���ڷ� �ٲٱ�
	charAry2[0][5] = 'a';
	// "Hello"�� ����Ϸ��� ������ ���鹮�ڰ� 'a'�� �ٲ�� �ٶ��� "HelloaWorld"�� ��µȴ�.
	printf("%s\n", charAry2[0]);
	
	array1_output("1���� �迭", ary1, ary1Size);
	array2_output("2���� �迭", ary2, ary2Row);
	array3_output("3���� �迭", ary3, ary3Face);
	
	return 0;
}

// �迭���� �� �� �迭�� �����ּ� ���
// �Ʒ� �Լ����� 1���� �迭�� �����ּ� ����� �ޱ� ���� �Ķ���ͷ� int*�� ������ ����
void array1_output(const char*msg, int* p, int size) {
	int i;
	printf("%s\n", msg);
	for (i = 0; i < size; i++) {
		// ������ ���� p�� ���ڷ� ���� �迭�� �ּ� ����� ��� �����Ƿ� �迭ó�� ��밡��
		printf("%d�� : %d ", i, p[i]);
	}
	printf("\n");
	return;
}

// 2���� �迭�� �����ּ� ����� �ޱ� ���� �Ķ���ͷ� int(*)[3]�� ������ ����
void array2_output(const char* msg, int(*p)[3], int size) {
	int i, j;
	printf("%s\n", msg);
	for (i = 0; i < size; i++) {
		printf("%d��\n", i);
		for (j = 0; j < 3; j++) {
			printf("%d�� : %d ", j, p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

// 3���� �迭�� �����ּ� ����� �ޱ� ���� �Ķ���ͷ� int(*)[2][2]�� ������ ����
void array3_output(const char* msg, int(*p)[2][2], int size) {
	int i, j, k;
	printf("%s\n", msg);
	for (i = 0; i < size; i++) {
		printf("%d��\n", i);
		for (j = 0; j < 2; j++) {
			printf("%d��\n", j);
			for (k = 0; k < 2; k++) {
				printf("%d�� : %d ", k, p[i][j][k]);
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