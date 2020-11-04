//2016115921 ���α�
//������ �� �ҽ������� ���� ���� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MALLOC(p,s) p = malloc(s)
typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;
listPointer first = NULL;

void insert(listPointer* first, listPointer x, int data)
{
	
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	if (*first == NULL) //ù��° ������
	{
		MALLOC(*first, sizeof(listNode));	//first�� ���̳��(first �������� ������)
		(*first)->link = temp;
		temp->link = NULL;	
	}
	else {			 
			temp->link = x->link;
			x->link = temp;		
	}
}

void delete(listPointer* first, listPointer trail, listPointer x)
{
	if (trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}

void PrintList(listPointer first)
{
	printf("The ordered list contains: \n");
	for (;first->link;first = first->link)
		printf("%4d", first->link->data);
	printf("\n");
}
listPointer find(listPointer*first, int data)
{
	listPointer p = *first;
	
		while (p->link != NULL)
		{
			if (p->link->data > data)
				return p;
			p = p->link;
		}
		return p;	
}

int main()
{
	FILE* fp = fopen("input.txt", "r");
	int n;
	
	listPointer x = NULL;
	
	fscanf(fp, "%d", &n);
	insert(&first, x, n);//ù��° ��� ����
	
	while (!feof(fp)) {
		fscanf(fp, "%d", &n);
		x = find(&first, n);
		insert(&first, x, n);
	}

	PrintList(first);
	printf("\nAfter deleting nodes with data less than and equal to 50 \n");

	listPointer t = first;

	while (t->link) //50������ ����
	{
		if (t->link->data <= 50) {
			delete(&first, t, t->link);
			
		}
		else {
			t = t->link;
		}
	}
	
	PrintList(first);

	listPointer s = first;	
	while (first->link) // ����Ʈ���� ��� ��� ����
	{
		delete(&first, s, s->link);	
	}

	//PrintList(first);
	free(first);
	
}