//2016115921 ���α�
//������ �� �ҽ������� �ٸ������ �ҽ��� ���������ʰ� ���� �ۼ��Ͽ����ϴ�

#include<stdio.h>

int count;
float rsum(float list[], int n)
{

	count++;
	if (n) {
		count++;
		return rsum(list, n - 1) + list[n - 1];
	}
	count++;
	return 0;
}

int main()
{
	float arr[5] = { 1,2,3,4,5 };
	printf("�迭 ������ ��:%f\n", rsum(arr, sizeof(arr) / sizeof(float)));
	printf("step count:%d", count);
}