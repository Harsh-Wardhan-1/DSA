#include <stdio.h>
int main()
{
    int n, p;
    int a[6] = {1, 2, 3, 4, 5, 0};
    printf("Enter the no. and the postion:");
    scanf("%d%d", &n, &p);
    //printf("%d", p);
    for (int i = 5; i > p; i--)
    {
        a[i] = a[i - 1];
    }
    a[p] = n;
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}