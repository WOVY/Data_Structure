#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[30] = { 0 };
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    printf("���ڿ� �Է� : ");
    gets_s(s, sizeof(s));

    printf("������ �빮�ڷ� ��ȯ ��� : ");
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

    printf("\n��ȯ�� ������ ���� : ");
    printf("%d", cnt1);
}