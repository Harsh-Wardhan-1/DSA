#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main()
{

    int n, i, j, *ptr, sum = 0;

    printf("Enter the order of the matrix ");

    scanf("%d", &n);

    ptr = calloc(n * n, sizeof(int));

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            scanf("%d", (*(ptr + i) + j));

            if (i != j)
            {

                sum += (*(ptr + i) + j);
            }
        }
    }

    printf("%d", sum);
    printf("1");
    free(ptr);
}