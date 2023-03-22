#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void prefix(char *P, int M, int *pr)
{
    int k = 0;
    pr[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (P[i] == P[k])
        {
            k++;
            pr[i] = k;
            i++;
        }
        else
        {
            if (k != 0)
                k = pr[k - 1];
            else
            {
                pr[i] = 0;
                i++;
            }
        }
    }
}
void KMPAlgorithm(char *str, char *pat)
{
    int m = strlen(pat);
    int n = strlen(str);
    int pr[m];
    prefix(pat, m, pr);
    int i = 0, j = 0, f = 0;
    while (i < n)
    {
        if (str[i] == pat[j])
        {
            i += 1;
            j += 1;
        }
        if (j == m)
        {
            f = 1;
            break;
        }
        else if (str[i] != pat[j] && i < n)
        {
            if (j != 0)
            {
                j = pr[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    if (f == 1)
        printf("%d", i - j);
    else
        printf("-1");
}
int main()
{
    char str[100];
    char pat[20];
    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", pat);
    KMPAlgorithm(str, pat);
    return 0;
}