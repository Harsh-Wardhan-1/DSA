#include <stdio.h>

int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l;
    int j = l + 1;
    while (j <= r)
    {
        if (pivot > a[j])
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        j++;
    }
    int temp = a[l];
    a[l] = a[i];
    a[i] = temp;
    return i;
}
void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = partition(a, l, r);
        quicksort(a, l, m - 1);
        quicksort(a, m + 1, r);
    }
}
void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[14];
    for (int i = 0; i < 13; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, 13);
    printArray(a, 13);
    return 0;
}