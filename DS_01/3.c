#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	int low = 0;
	int high = n - 1;
	int mid;

	int key;
	printf("\n\nEnter the number to search : ");
	scanf("%d", &key);

	while (low <= high)
	{
		mid = (low + high) / 2 + 0.5;

		if (key == random[mid]) {
			printf("\nThe search number is present in list[%d]\n", mid);
			return 0;
		}

		else if (key < random[mid]) {
			high = mid - 1;
		}

		else {
			low = mid + 1;
		}
	}
}