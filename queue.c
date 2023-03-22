#include <stdio.h>
#define max 5
struct queue
{
    int q[max];
    int f, r;
} Q;
void init()
{
    Q.f = Q.r = 0;
}
void enqueue(int n)
{
    if (Q.r == max)
        printf("Overflow");
    else
        Q.q[Q.r++] = n;
}
int dequeue()
{
    if (Q.r < Q.f)
        printf("Underflow");
    else
        return Q.q[Q.f++];
}
void display()
{
    for (int i = Q.f; i < Q.r; i++)
    {
        printf("%d\n", Q.q[i]);
    }
}
int main()
{
    struct queue Q;
    init();
    enqueue(5);
    enqueue(3);
    enqueue(1);
    enqueue(2);
    enqueue(4);
    enqueue(4);
    printf("%d\n", dequeue());
    display();
}