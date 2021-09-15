#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int func1();
int func2(int* pNum);
int func3(int** pNum);
int func4(int n);

int main()
{
	int* pNum;
	char* pChar;


	pNum = func1();
	printf("%d\n", *pNum);

	func2(pNum);
	printf("%d\n", *pNum);

	func3(&pNum);
	printf("%d\n\n", *pNum);

	pChar = func4(100);

	printf("�Է��� ���ڿ� : ");
	scanf_s("%s", pChar, _msize(pChar));

	printf("pChar contents = %s\n", pChar);

	free(pNum);
	free(pChar);

	return 0;
}

int func1()
{
	int* n = malloc(sizeof(int));

	*n = 10;

	return n;
}

int func2(int* pNum)
{
	*pNum = 200;

	return 0;
}

int func3(int** pNum)
{
	**pNum = 300;

	return 0;
}

int func4(int n)
{
	char* arr = malloc(sizeof(char) * n);

	return arr;
}
