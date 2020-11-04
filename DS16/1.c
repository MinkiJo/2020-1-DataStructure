//2016115921 ���α�
//�������� �ҽ������� ������� ���� �ۼ��Ͽ����ϴ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
#define INF_NUM 10000
// min - winner tree
int nums[MAX_SIZE + 1][12] = { 0 }; // keys to sort
int winTree[2 * MAX_SIZE] = { NULL }; // winner tree -->���������� ���
int sorted[MAX_SIZE * 10 + 1] = { 0 }; // sorted result
int sortedIdx[MAX_SIZE] = { 0 };

int initWinner(int cur, int k);
void adjustWinner(int min, int k);


int initWinner(int cur, int k) {

	if (cur >= k) return 0;
	initWinner(2 * cur, k);
	initWinner(2 * cur + 1, k);
	
	if (nums[sortedIdx[winTree[2 * cur]]][winTree[2 * cur]] < nums[sortedIdx[winTree[2 * cur + 1]]][winTree[2 * cur + 1]]) //sorted�� ��� winTree�� ���� ���� nums �迭�� ��
		winTree[cur] = winTree[2 * cur];
	else winTree[cur] = winTree[2 * cur + 1];

}

void adjustWinner(int min, int k) {

	sortedIdx[min]++; //adjustWinner�� ���� ���� ����Ű�� ���� �ε����� ����	
	initWinner(1, k); //����Ʈ�� �籸��
}
int main()
{
	int key;
	printf("<<<<<<<<<<sorting with winner tree >>>>>>>>>>>>\n");
	printf("the number of keys(8,16, or 32 as a power of 2) >>");scanf("%d", &key);



	int seed;
	printf("seed>>>>"); scanf("%d", &seed);
	srand(seed);

	printf("random numbers to use as key values(1~100)\n");
	for (int i = 1;i <= 11;i++) //2�����迭 nums����
	{
		for (int j = 1;j <= key;j++)
		{
			nums[i][j] = INF_NUM; //���� ũ����Ҷ� ���
		}
	}
	for (int i = 1;i <= key;i++)
	{
		nums[1][i] = (rand() % 100) + 1;
	}

	for (int i = 1;i <= 9;i++) //��� �����
	{
		for (int j = 1;j <= key;j++)
		{
			nums[i + 1][j] = nums[i][j] + 1;
		}
	}
	for (int i = 1;i <= key;i++)
	{
		printf("%d-th records:\n", i);
		for (int j = 1;j <= 10;j++)
		{
			printf("%d  ", nums[j][i]);
		}
		printf("\n");
	}


	int a = key;
	printf("\n<<<initialization of min-winner tree>>>\n"); //winnerƮ�� �ʱ�ȭ
	for (int i = 1;i <= key;i++)
	{
		winTree[a++] = i;
	}


	/*for (int i = 0;i < key * 2;i++) //winnertree Ȯ��
	{

		printf("%d  ", winTree[i]);
	}printf("\n");*/

	for (int i = 1;i <= key;i++)
		sortedIdx[i] = 1; //sortedIdx�� �����ؾ��� ���� ����Ŵ. ó���� 1�� �ʱ�ȭ



	initWinner(1, key);
	printf("\nsolting with min-winner tree");
	for (int i = 0;i < 10 * key;i++) //key*80 ��ü����ŭ 
	{
		int min = winTree[1];
		
		sorted[i] = nums[sortedIdx[min]][min];	 //sorted�迭�� ����
	
		adjustWinner(winTree[1], key); 
			
	}printf("\n\n");

	int count = 0;
	printf("sorted result\n");
	for (int i = 0;i < 10 * key;i++)
	{
		printf("%d  ", sorted[i]);
		if (++count % key == 0)
			printf("\n");
	}

}