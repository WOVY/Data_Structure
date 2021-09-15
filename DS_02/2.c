#include <stdio.h>
#include <time.h>
#define MAX_SIZE 2001

void sort(int list[], int n);
void SWAP(int x, int y);

void main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;

	FILE* fp;

	fopen_s(&fp, "out_2.txt", "w");
	if (fp == NULL)
		exit(1);

	printf("  n        time\n");
	fprintf(fp, "  n        time\n");
	for (n = 0; n <= 2000; n += step)
	{
		for (i = 0; i < n; i++)
			a[i] = n - i;

		start = clock();
		sort(a, n);	
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

		printf("%4d     %7f\n", n, duration);
		fprintf(fp, "%4d     %7f\n", n, duration);
		if (n == 100)	step = 100;
	}

	fclose(fp);
}

void sort(int list[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[min], list[i]);
	}
}

void SWAP(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}