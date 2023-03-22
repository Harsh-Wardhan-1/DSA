#include <stdio.h>
#define max 5
struct stack
{
    int st[max];
    int sp;
} S;

void init()
{
    S.sp = -1;
}

void push(int n)
{
    if (S.sp == max - 1)
        printf("Overflow");
    else
        S.st[++S.sp] = n;
}

int pop()
{
    if (S.sp == -1)
        printf("Underflow");
    else
        return S.st[S.sp--];
}

void display()
{
    for (int i = S.sp; i >= 0; i--)
    {
        printf("%d\n", S.st[i]);
    }
}

int main()
{
    struct stack S;
    init();
    push(1);
    push(2);
    push(3);
    int r = pop();
    printf("%d\n", r);
    display();
}