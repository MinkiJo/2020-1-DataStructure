//2016115921 ���α�
//������ �� �ҽ������� �ٸ������ �ҽ��� ���������ʰ� ���� �ۼ��Ͽ����ϴ�
#include<stdio.h>
#include<stdlib.h>


int* func1()
{
	return (int*)malloc(sizeof(int));
}
int* func2(int* pNum)
{
	*pNum = 100;
	return pNum;
}
int** func3(int** pNum)
{
	**pNum = 200;
	return pNum;
}
int main()
{
	int* pNum = func1();
	printf("%d\n", *pNum);
	printf("%d\n", *func2(pNum));
	printf("%d\n", **func3(&pNum));
	free(pNum);

	return 0;
}