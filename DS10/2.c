//2016115921 ���α�
//������ �� �ҽ������� ���� ���� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACKS 3
#define MALLOC(p,s) p = malloc(s)
typedef struct {
	int id;
	int grade;
}element;

typedef struct stack* stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
}Node;

stackPointer top[MAX_STACKS];

void push(int i, element item)
{
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}
element stackEmpty(){
	
	element empty;
	empty.id = -1;
	return empty;	
}
element pop(int i)
{
	stackPointer temp = top[i];
	element item;
	if (!temp)
		return stackEmpty();
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}

int main()
{
	FILE* fp = fopen("input.txt", "r");
	
	int i; element t;
	while (!feof(fp)) {
		fscanf(fp, "%d", &i);
		fscanf(fp, "%d",&t.id);
		fscanf(fp, "%d", &t.grade);
		push(i, t);		
	}
	
	printf("�����ȣ �й� ����\n");
	
	for (int i = 0;i <= 2;i++)
	{
		printf("*******************\n");
		element p = pop(i);
		while(p.id != -1) //stackEmpty�� �ƴҶ�����
		{	 	
			printf("  %3d %3d  %3d\n", i, p.id, p.grade);
			p = pop(i);
		}
	}
		
	
}