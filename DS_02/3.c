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

	FILE* fp;
	fopen_s(&fp, "out_3.txt", "w");
	if (fp == NULL)
		exit(1);

	fprintf(fp, "  n      repetitions     time\n");
	printf("  n      repetitions     time\n");
	for (n = 0; n <= 2000; n += step)
	{
		long repetition = 0;
		clock_t start = clock();
		do
		{
			repetition++;

			for (i = 0; i < n; i++)
				a[i] = n - i;

			sort(a, n);
		} while (clock() - start < 1000);

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetition;

		fprintf(fp, "%4d      %9d    %7f\n", n, repetition, duration);
		printf("%4d      %9d    %7f\n", n, repetition, duration);

		if (n == 100) step = 100;
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