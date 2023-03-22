#include <stdio.h>

int hashFunQuad(int key, int len, int h[])
{
    int x = (key + 7) * (key + 7);
    x /= 16;
    x += key;
    x %= len;
    printf("key:%d x:%d\n", key, x);
    int k = x;
    for (int j = 1; h[k] != -1; j++)
    {
        printf("%d ", j);
        k = (x + (j * j + j) / 2) % len;
        printf("key:%d x:%d  j:%d\n", key, k, j);
    }
    x = k;
    return x;
}

int hashFunLin(int key, int len, int h[])
{
    int x = (key + 7) * (key + 7);
    x /= 16;
    x += key;
    x %= len;
    while (h[x] != -1)
    {
        x++;
    }
    return x;
}

int main()
{
    int ht[11], key, size = 11, a[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int n = (int)sizeof(a) / sizeof(int);

    for (int i = 0; i < size; i++)
        ht[i] = -1;
    for (int i = 0; i < n; i++)
        ht[hashFunLin(a[i], size, ht)] = a[i];
    for (int i = 0; i < size; i++)
        printf("%d ", ht[i]);
    printf("\n");

    for (int i = 0; i < size; i++)
        ht[i] = -1;
    for (int i = 0; i < n; i++)
        ht[hashFunQuad(a[i], size, ht)] = a[i];
    for (int i = 0; i < size; i++)
        printf("%d ", ht[i]);
    printf("\n");
}