#include <stdio.h>
#include <limits.h>
int mat[10][10], p[10], s[10][10], n;
#define INFY 9999999

void matrix()
{
    int x, i, j, k;
    for (i = n; i > 0; i--)
    {
        for (j = i; j <= n; j++)
        {
            if (i == j)
                mat[i][j] = 0;
            else
            {
                for (k = i; k < j; k++)
                {
                    x = mat[i][k] + mat[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (x < mat[i][j])
                    {
                        mat[i][j] = x;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
}

int main()
{
    int i, j, k;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
        {
            mat[i][i] = 0;
            mat[i][j] = INFY;
            s[i][j] = 0;
        }
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    matrix();
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}