//�й� : 2016115921 �̸� :���α�
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>

int sumAry3D_f1(int ary[][2][3], int SEC, int ROW, int COL);
int sumAry3D_f2(int(*ary)[2][3], int SEC, int ROW, int COL);
int sumAry3D_f3(int ary[2][2][3], int SEC, int ROW, int COL);

int main(void)
{
	int ary3D[][2][3] = { {{1, 2, 3}, {4, 5, 6}},{{7, 8, 9}, {10, 11, 12} } };
	printf("sumAry3D_f1() %d\n", sumAry3D_f1(ary3D, 2, 2, 3));
	printf("sumAry3D_f2() %d\n", sumAry3D_f2(ary3D, 2, 2, 3));
	printf("sumAry3D_f3() %d\n", sumAry3D_f3(ary3D, 2, 2, 3));
	return 0;
}

int sumAry3D_f1(int ary[][2][3], int SEC, int ROW, int COL)
{
	int sum = 0;
	for (int i = 0;i < SEC;i++)
	{
		for (int j = 0;j < ROW;j++)
		{
			{
				for (int k = 0;k < COL;k++)
				{
					sum = sum + ary[i][j][k];
				}
			}
		}
	}
	return sum;
}
int sumAry3D_f2(int(*ary)[2][3], int SEC, int ROW, int COL)
{
	int sum = 0;
	for (int i = 0;i < SEC;i++)
	{
		for (int j = 0;j < ROW;j++)
		{
			{
				for (int k = 0;k < COL;k++)
				{
					sum = sum + ary[i][j][k];
				}
			}
		}
	}
	return sum;
}
int sumAry3D_f3(int ary[2][2][3], int SEC, int ROW, int COL)
{
	int sum = 0;
	for (int i = 0;i < SEC;i++)
	{
		for (int j = 0;j < ROW;j++)
		{
			{
				for (int k = 0;k < COL;k++)
				{
					sum = sum + ary[i][j][k];
				}
			}
		}
	}
	return sum;
}
