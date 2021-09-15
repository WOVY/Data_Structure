#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[30] = { 0 };
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    printf("문자열 입력 : ");
    gets_s(s, sizeof(s));

    printf("자음만 대문자로 변환 결과 : ");
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
            {
                printf("%c", toupper(*(s + i)));
                cnt1++;
            }

            else
                printf("%c", *(s + i));
        }

        else
            printf("%c", *(s + i));
    }

    printf("\n변환된 문자의 개수 : ");
    printf("%d", cnt1);
}