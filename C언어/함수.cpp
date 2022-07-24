/*
	�Լ��� Ư������� �����ϱ� ���� �ڵ� ��{}�̴� -> �Լ��� �ϳ��� ��ɸ� �����ϵ��� �ϴ� ���� ���� �ٶ����ϴ�.
	�Լ� ���ο��� �Լ��� ȣ���ϴ� ����� �ʹ� ���� ���� ���� �ʴ�. main�Լ����� call�ϰ� return�� �Ͼ�� ���� ���� �� ����
	�Լ��� ������� : �����, ȣ���, ���Ǻ�
	����Ŀ���� �����ϴ� SLF���� ����� -> �������, ȣ��� -> �ڵ��ۼ�����, ���Ǻ� -> ���̺귯����ƾ�� ����

	�Լ��� ������ ����� �� ������ ���Ǻο� ����Ǿ��ִ� �� Ȯ���ϰ� ����x��� extern������ ����Ǿ��ִ� �� Ȯ���Ѵ�.

	argument�� �����ϴ� ���� �� Ȯ�� �� Ȯ���� call by value���� call by pointer���� ����

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

	// call by pointer������ p�� ����� '��'�� a�� �ּҸ� �������Ƿ� call by value�̴�.
	// call by pointer�̷��� callByPointer(&a)�� ���ָ� �ȴ�.
	callByPointer(p);

	return 0;
}

void callByValue(int p) {
	printf("call by value : %d\n", p);
}

void callByPointer(int* p) {
	printf("call by pointer : %d\n", *p);
}