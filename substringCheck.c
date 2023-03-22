#include <stdio.h>

int main()
{
    char s1[100], s2[20];
    int c1 = 0, c2 = 0, f;
    printf("Enter a string:");
    gets(s1);
    printf("Enter search substring:");
    gets(s2);
    while (s1[c1] != '\0')
        c1++;
    while (s2[c2] != '\0')
        c2++;
    for (int i = 0; i <= c1 - c2; i++)
    {
        for (int j = i; j < i + c2; j++)
        {
            f = 1;
            if (s1[j] != s2[j - i])
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
            break;
    }
    if (f == 1)
        printf("yes");
    else
        printf("-1");
    return 0;
}