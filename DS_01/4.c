#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int random[], int key, int left, int right);
int compare(int x, int y);

int main()
{
	int n = 0;

	printf("Enter the number of numbers to generate : ");
	scanf_s("%d", &n);

	srand(time(NULL));

	int random[100] = { 0 };

	for (int i = 0; i < n; i++)
	{
		random[i] = rand() % 1000 + 1;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d	", random[i]);
	}

	int tmp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (random[i] > random[j])
			{
				tmp = random[i];
				random[i] = random[j];
				random[j] = tmp;
			}
		}
	}

	printf("\n\nSorted array :\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d	", random[i]);
	}

	int left = 0;
	int right = n - 1;
	int key;

	printf("\n\nEnter the number to search : ");
	scanf_s("%d", &key);

	binsearch(random, key, left, right);

}

int binsearch(int random[], int key, int left, int right)
{
	int mid;

	printf("\ncall binsearch_recur, left = %d, right = %d", left, right);

	if (left <= right) {
		mid = (left + right) / 2;

		switch (compare(random[mid], key)) {
		case -1:
			return binsearch(random, key, mid + 1, right);
		case 0:
			printf("\nThe search number is present in list[%d]", mid);
			return 0;
		case 1:
			return binsearch(random, key, left, mid - 1);
		}
	}

	return -1;
}

int compare(int x, int y)
{
	if (x < y)
		return -1;

	else if (x == y)
		return 0;

	else
		return 1;

}