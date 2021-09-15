#include <stdio.h>

int main()
{
    for (int i = 2; i < 6; i++)
    {
        printf("%d��\n", i);
        for (int j = 1; j < 10; j++)
        {
            int result = i * j;
            printf("%d * %d = %d\n", i, j, result);
        }
        printf("*********************************\n");
    }
}
