//�й� : 2016115921 �̸� :���α�
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>

int main()
{
	int arr[2][3] = { {4,2,3},{5,2,3} };
	int(*p)[3] = arr;


	printf("ary�� �̿���  ���\n");
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	printf("p�� �̿���  ���\n");

	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("%d", (*(p + i))[j]);
		}
		printf("\n");
	}
}