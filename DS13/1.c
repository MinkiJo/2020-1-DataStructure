//2016115921
//본인은 이 소스파일을 복사 없이 직접 작성하였습니다
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100
#define MAX_STACK_SIZE 100
typedef struct node* treePointer;
typedef struct node {
	char data; // 문자출력
	treePointer leftChild, rightChild;
}node;
treePointer root;
treePointer stack[MAX_STACK_SIZE];
int top = -1;
char expr[81];
typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;

void push(treePointer ptr);
treePointer pop();
treePointer makeNode(char a);
treePointer createBinTree(void);
precedence getToken(char* symbol, int* n);
treePointer stackEmpty();
void stackFull();

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
treePointer createBinTree(void)
{
	precedence token;
	char symbol;
	
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
		{			
			push(makeNode(symbol));
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
precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
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
void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}

}

int main()
{
	char a;
	int i = 0;
	FILE* fp = fopen("input.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%c", &expr[i++]);		
	}
	printf("The length of input string should be less than 80 \n");
	printf("input string <postfix expression> : %s\n", expr);
	
	printf("creating its binary tree\n\n");
	root = createBinTree();
	
	
	printf("inorder traversal   :");inorder(root);printf("\n");
	printf("preorder traversal   :");preorder(root);printf("\n");
	printf("postorder traversal   :");postorder(root);printf("\n");
}