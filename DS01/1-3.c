//�й� : 2016115921 �̸� :���α�
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>

int main()
{
	int count = 1;
	int arr[2][2][3];
	int(*p)[2][3] = arr;
	arr[0][0][0] = 1;
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			for (int k = 0;k < 3;k++)
			{
				arr[i][j][k] = count++;
			}
		}
	}

	printf("ary�� �̿���  ���\n");
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			{
				for (int k = 0;k < 3;k++)
				{
					printf("%3d", arr[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}


	printf("p�� �̿���  ���\n");
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			{
				for (int k = 0;k < 3;k++)
				{
					printf("%3d", (*(p + i))[j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}

}