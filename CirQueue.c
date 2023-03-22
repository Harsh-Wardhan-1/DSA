#include <stdio.h>
#define max 6
struct queue
{
    int q[10];
    int f, r;
} Q;
void init()
{
    Q.f = Q.r = 0;
}
void enqueue(int n)
{
    if (Q.f == (Q.r + 1) % max)
        printf("Overflow");
    else
        Q.q[Q.r++] = n;
}
int dequeue()
{
    if (Q.f == (Q.r + 1) % max)
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
    enqueue(4);
    //printf("%d", dequeue());
    display();
}