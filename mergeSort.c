#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {

        arr[k] = L[i];

        i++;

        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        printf("Hi: l=%d m=%d r=%d\n", l, m, r);
        mergeSort(arr, l, m);

        printf("Hello: l=%d m=%d r=%d\n", l, m, r);
        mergeSort(arr, m + 1, r);

        printf("Merge: l=%d m=%d r=%d\n", l, m, r);
        merge(arr, l, m, r);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int n1, i;
    printf("enter the no.of elements : ");
    scanf("%d", &n1);
    int arr[n1];
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr[i]);
    }
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is :");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("Sorted array is :");
    printArray(arr, arr_size);
    return 0;
}