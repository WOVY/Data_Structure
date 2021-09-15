#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct human {
	char name[10];
	int age;
	char gender;
}human;

int main()
{
	human* human = malloc(sizeof(human));
	int i, MAX, num;

	FILE* fp = fopen("input.txt", "r");

	for (i = 0; i < 4; i++)
	{
		fscanf_s(fp, "%s %d %c", human[i].name, sizeof(human[i].name), &human[i].age, &human[i].gender);
	}

	printf("이름 나이 성별\n");
	printf("*************************\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s %d %c\n", human[i].name, human[i].age, human[i].gender);
	}
	printf("*************************\n");

	for (i = 1; i < 4; i++)
	{

		if (human[i].age > human[i - 1].age)
		{
			MAX = human[i].age;
			num = i;
		}
		else if (human[i].age < human[i - 1].age)
		{
			MAX = human[i - 1].age;
			num = i - 1;
		}
	}

	printf("<<최고령 정보>>\n\n");
	
	printf("%s %d %c", human[num].name, human[num].age, human[num].gender);
}