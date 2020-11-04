//2016115921 ���α�
//������ �� �ҽ������� �ٸ������ �ҽ��� ���������ʰ� ���� �ۼ��Ͽ����ϴ�

#include<stdio.h>
#include<stdlib.h>

int* alloc(int num);
void increase(int* pNum, int num);
void input(int* pNum, int num, FILE* fpIn);
void output(int* pNum, int num, FILE* fpOut);



int main()
{
	int num, * pNum;

	FILE* fpIn = fopen("input.txt", "r");
	FILE* fpOut = fopen("output.txt", "w");

	fscanf(fpIn, "%d", &num);
	pNum = alloc(num);
	input(pNum, num, fpIn);
	increase(pNum, num);
	output(pNum, num, fpOut);

	free(pNum);
	fclose(fpIn);
	fclose(fpOut);

	return 0;

}

int* alloc(int num)
{
	return (int*)malloc(sizeof(int) * num);
}
void increase(int* pNum, int num)
{
	for (int i = 0;i < num;i++)
	{
		pNum[i] += 1;
	}
}
void input(int* pNum, int num, FILE* fpIn)
{
	for (int i = 0;i < num;i++)
	{
		fscanf(fpIn, "%d", &pNum[i]);
	}
}
void output(int* pNum, int num, FILE* fpOut)
{
	for (int i = 0;i < num;i++)
	{
		fprintf(fpOut, "%d", pNum[i]);
	}
}