//�й� : 2016115921 �̸� :���α�
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h> 
#include<stdlib.h>
int main()
{
	int i, * pi;
	float f, * pf;
	pi = (int*)malloc(sizeof(int));
	pf = (float*)malloc(sizeof(float));

	if (!(pi = malloc(sizeof(int))) || !(pf = malloc(sizeof(float))))
	{
		fprintf(stderr, "Insufficient memory");
		exit(EXIT_FAILURE);
	}

	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi, *pf);
	free(pi);
	free(pf);



}