//�й� : 2016115921 �̸� :���α�
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>

int main()
{
	int a = 2, b = 3, c = 4;
	int* ary[3] = { &a, &b, &c };
	
	printf("������ �迭�� �迭��Ҹ� �̿��� a,b,c���");printf("\n");
	printf("a:%d  ", *(ary[0]));
	printf("b:%d  ", *(ary[1]));
	printf("c:%d  ", *(ary[2]));
}