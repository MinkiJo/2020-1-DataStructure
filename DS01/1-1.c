//�й� : 2016115921 �̸� :���α�
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>
int main()
{
	int arr[3] = { 8,2,8 };
	int* p = arr;


	printf("ary�� �̿���  ���\n");
	for (int i = 0;i < 3;i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("p�� �̿���  ���\n");
	for (int i = 0;i < 3;i++)
	{
		printf("%d", *(p + i));
	}

}