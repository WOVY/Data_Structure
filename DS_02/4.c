/*

selection sort 알고리즘은 worst-case, best-case, average-case 모두 시간 복잡도는는 O(n²), 공간 복잡도는 O(1)으로 구분이 없다.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 2001

void sort(int list[], int n);
void SWAP(int x, int y);

void main(void)
{
	int i, n, step = 10;
	int reverse[MAX_SIZE];
	int order[MAX_SIZE];
	int random[MAX_SIZE];
	double reverse_duration;
	double order_duration;
	double random_duration;

	FILE* fp;
	fopen_s(&fp, "out_4.txt", "w");
	if (fp == NULL)
		exit(1);

	fprintf(fp, "  n    역정렬    순정렬     랜덤\n");
	printf("  n      역정렬    순정렬     랜덤\n");
	for (n = 0; n <= 2000; n += step)
	{
		//reverse

		long reverse_repetition = 0;

		clock_t reverse_start = clock();

		do
		{
			reverse_repetition++;

			for (i = 0; i < n; i++)
				reverse[i] = n - i;

			sort(reverse, n);
		} while (clock() - reverse_start < 1000);

		reverse_duration = ((double)(clock() - reverse_start)) / CLOCKS_PER_SEC;
		reverse_duration /= reverse_repetition;


		//order
		
		long order_repetition = 0;

		clock_t order_start = clock();

		do
		{
			order_repetition++;

			for (i = 0; i < n; i++)
				order[i] = i + 1;

			sort(order, n);
		} while (clock() - order_start < 1000);

		order_duration = ((double)(clock() - order_start)) / CLOCKS_PER_SEC;
		order_duration /= order_repetition;

		
		//random

		long random_repetition = 0;

		srand(time(NULL));
		clock_t random_start = clock();

		do
		{
			random_repetition++;

			for (int i = 0; i < n; i++)
			{
				random[i] = rand() % n + 1;
			}

			sort(random, n);
		} while (clock() - random_start < 1000);

		random_duration = ((double)(clock() - random_start)) / CLOCKS_PER_SEC;
		random_duration /= random_repetition;



		fprintf(fp, "%4d  %7f  %7f  %7f\n", n, reverse_duration, order_duration, random_duration);
		printf("%4d	%7f  %7f  %7f\n", n, reverse_duration, order_duration, random_duration);

		if (n == 100) step = 100;
	}
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