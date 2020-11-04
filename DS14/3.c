#define _CRT_SECURE_NO_WARNINGS
//2016115921 ���α�
//������ �� �ҽ������� ���� ���� ���� �ۼ��Ͽ����ϴ�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 100
#define MAX_STACK_SIZE 100
typedef enum {
	 not, and, or, true, false, eos, operand
}logical;

typedef struct node* treePointer;
typedef struct node {
	treePointer leftChild;
	logical data;
	short int value;
	treePointer rightChild;
}node;


treePointer root;
treePointer stack[MAX_STACK_SIZE];
int top = -1;
char expr[81];

int testcase[10] = { 0 };


void push(treePointer ptr);
treePointer pop();
treePointer makeNode(char a);
treePointer makeNodeLeaf(int a);
treePointer createBinTree(void);
logical getToken(char* symbol, int* n);
void findComb(int n);
treePointer stackEmpty();
void stackFull();
void inorder(treePointer ptr);
void postOrderEval(treePointer node);

void stackFull()
{
	printf("Stack is Full!\n");
	exit(1);
}
treePointer stackEmpty() {
	return NULL;
}
void push(treePointer ptr)
{
	stack[++top] = ptr;
}
treePointer pop() {
	return stack[top--];
}

treePointer makeNode(char a)
{
	treePointer temp = (treePointer)malloc(sizeof(node));
	temp->data = a;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	return temp;
}

treePointer makeNodeLeaf(int a) 
{
	treePointer temp = (treePointer)malloc(sizeof(node));
	
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	
	if(a==1)
		temp->data = true;	
	else if(a==0)
		temp->data = false;
	return temp;
}

treePointer createBinTree(void)
{
	logical token;
	char symbol;

	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
		{
			if (symbol == 'a')
				push(makeNodeLeaf(testcase[0]));
			if (symbol == 'b')
				push(makeNodeLeaf(testcase[1]));
			if (symbol == 'c')
				push(makeNodeLeaf(testcase[2]));
			if (symbol == 'd')
				push(makeNodeLeaf(testcase[3]));
			if (symbol == 'e')
				push(makeNodeLeaf(testcase[4]));
			if (symbol == 'f')
				push(makeNodeLeaf(testcase[5]));
			if (symbol == 'g')
				push(makeNodeLeaf(testcase[6]));
			if (symbol == 'h')
				push(makeNodeLeaf(testcase[7]));
			if (symbol == 'i')
				push(makeNodeLeaf(testcase[8]));
			if (symbol == 'j')
				push(makeNodeLeaf(testcase[9]));

		}
		else if (token == not)
		{
			treePointer ptr = makeNode(symbol);
			ptr->rightChild = pop();
			push(ptr);
		}
		else {
			treePointer ptr = makeNode(symbol);
			ptr->rightChild = pop();
			ptr->leftChild = pop();
			push(ptr);
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

void findComb(int n) //testcase�迭�� ����� ���� ����ǥ������ �Է�
{	
	static int count; 
	count++;  
	if (n > 1)
		findComb(n / 2);

	count--; 
	testcase[count] = n % 2;
}

logical getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '~': return not;
	case '&': return and;
	case '|': return or ;
	case '\0': return eos;
	default: return operand;
	}
}

void postOrderEval(treePointer node)
{
	if (node)
	{
		postOrderEval(node->leftChild);
		postOrderEval(node->rightChild);
		switch (node->data)
		{
		case '~':
			node->value = !node->rightChild->value;
			break;
		case '&' :
			node->value = node->rightChild->value && node->leftChild->value;
			break;
		case '|':
			node->value = node->rightChild->value || node->leftChild->value;
			break;
		case true:
			node->value = TRUE;
			break;
		case false:
			node->value = FALSE;

		}
	}
}


void inorder(treePointer ptr) {
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}
int  main()
{	
	int n;
	FILE* fp = fopen("postfix.txt", "r");
	fscanf(fp, "%d", &n);
	while (!feof(fp)) {
		fscanf(fp, "%s", expr);
	}
	printf("input string <postfix expression> : %s\n", expr);

	for (int i = 0;i < pow(2, n);i++) //2�� n�� ��ŭ�� ����Ǽ� �ݺ�
	{
		findComb(i); //�������� ������ ����
		printf("���� testcase     "); //testcase�� �ǿ����ʺ��� a�̴�.
		for (int i = n-1;i >=0;i--)
		{
			printf("%d  ", testcase[i]);
		}	

		root = createBinTree();
		
		postOrderEval(root);		
		
		
		printf("[result] %d", root->value);
		printf("\n");
	}

}