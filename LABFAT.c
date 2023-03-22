#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *l;
    struct node *r;
} *root = NULL, *temp = NULL;

struct node *createNode(int key);
void insert(int key);
void pos(struct node *b, int key);
void preorder(struct node *b);
void postorder(struct node *b);
void inorder(struct node *b);

struct node *createNode(int key)
{
    temp = (struct node *)malloc(1 * sizeof(struct node));
    temp->value = key;
    temp->l = temp->r = NULL;
    return temp;
}

void pos(struct node *b, int key)
{
    if ((key > b->value) && (b->r != NULL))
    {
        pos(b->r, key);
    }
    else if ((key > b->value) && (b->r == NULL))
    {
        b->r = temp;
    }
    else if ((key < b->value) && (b->l != NULL))
    {
        pos(b->l, key);
    }
    else if ((key < b->value) && (b->l == NULL))
    {
        b->l = temp;
    }
}

void insert(int key)
{
    temp = createNode(key);
    if (root == NULL)
        root = temp;
    else
        pos(root, key);
}

void inorder(struct node *b)
{
    if (root == NULL)
    {
        printf("Empty Tree");
        return;
    }
    if (b->l != NULL)
        inorder(b->l);
    printf("%d ", b->value);
    if (b->r != NULL)
        inorder(b->r);
}

void preorder(struct node *b)
{
    printf("%d ", b->value);
    if (b->l != NULL)
        preorder(b->l);
    if (b->r != NULL)
        preorder(b->r);
}

void postorder(struct node *b)
{
    if (b->l != NULL)
        postorder(b->l);
    if (b->r != NULL)
        postorder(b->r);
    printf("%d ", b->value);
}

void main()
{
    insert(8);
    insert(3);
    insert(1);
    insert(6);
    insert(4);
    insert(7);
    insert(10);
    insert(14);
    insert(13);
    printf("Printing in INORDER:\n");
    inorder(root);
    printf("\nPrinting in POSTORDER:\n");
    postorder(root);
    printf("\nPrinting in PREORDER:\n");
    preorder(root);
}
