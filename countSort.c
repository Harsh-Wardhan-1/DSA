#include <stdio.h>
#include <conio.h>
//int countSort(int a[], int c[], int k, int n)
int main()
{
    int n;
    printf("Enter the length:");
    int k = 0;
    scanf("%d", &n);
    printf("\nEnter the array:");
    int a[n + 1];
    int c[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > k)
        {
            k = a[i];
        }
    }
    //countSort(a, c, m, n);
    int b[k + 1];

    for (int i = 0; i <= k; i++)
    {
        b[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        b[a[i]] = b[a[i]] + 1;
    }

    for (int j = 1; j <= k; j++)
    {
        b[j] = b[j] + b[j - 1];
    }

    for (int i = n; i > 0; i--)
    {
        c[b[a[i]]] = a[i];
        b[a[i]] = b[a[i]] - 1;
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", c[i]);
    }
}