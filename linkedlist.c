#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
} * new, *head, *tail, *temp;

void init()
{
    head = tail = NULL;
}

int l; //length of list

struct node *findAddr(int i)
{
    struct node *t;
    t = head;
    for (int k = 2; k <= i; k++)
        t = t->next;
    return t;
}

void create()
{
    printf("Enter the length of list:\n");
    scanf("%d", &l);
    for (int i = 1; i <= l; i++)
    {
        if (head == NULL)
        {
            new = (struct node *)malloc(sizeof(struct node));
            int value;
            printf("Enter the value:\n");
            scanf("%d", &value);
            new->value = value;
            new->next = NULL;
            head = tail = new;
        }
        else
        {
            new = (struct node *)malloc(sizeof(struct node));
            int value;
            printf("Enter the value:\n");
            scanf("%d", &value);
            new->value = value;
            new->next = NULL;
            tail->next = new;
            tail = new;
        }
    }
}

void display()
{
    struct node *i = head;
    while (i)
    {
        printf("%d\n", i->value);
        i = i->next;
    }
}

void insert()
{
    printf("Enter the positon and the vlaue:\n");
    int pos, value;
    scanf("%d%d", &pos, &value);
    new = (struct node *)malloc(sizeof(struct node));
    struct node *iAddr;
    iAddr = findAddr(pos - 1);
    if (pos == 1)
    {
        new->next = head;
        new->value = value;
        head = new;
    }
    else if (pos == l + 1)
    {
        new->value = value;
        new->next = NULL;
        tail->next = new;
        tail = new;
    }
    else
    {
        new->value = value;
        new->next = iAddr->next;
        iAddr->next = new;
    }
    l++;
}

void delete ()
{
    int pos;
    printf("\n Enter Position to Delete:");
    scanf("%d", &pos);
    struct node *iAddr;
    iAddr = findAddr(pos - 1);
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        temp = iAddr->next;
        iAddr->next = temp->next;
        temp->next = NULL;
    }
}
void search()
{
    struct node *t;
    t = head;
    int key;
    int flag = 0;
    printf("\n Element to Search: ");
    scanf("%d", &key);
    while (t)
    {
        if (t->value == key)
        {
            flag = 1;
            break;
        }
        else
        {
            t = t->next;
        }
    }
    if (flag == 1)
        printf("\n Element found ");
    else
        printf("\n Element is not found");
}

int main()
{
    int ch;
    init();
    while (1)
    {
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}