#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    struct node *right;
    int data;
} * temp, *node1, *new1, *root;

struct node *createnode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

struct node createTree(struct node *node1)
{
    node1->left = NULL;
    node1->right = NULL;
    printf("Enter the data:");
    int data;
    scanf("%d", &data);
    node1->data = data;
    printf("Do you wish to create left node? Enter 1 or 0");
    int vl;
    scanf("%d", &vl);
    if (vl)
    {
        new1 = createnode();
        node1->left = new1;
        createTree(new1);
    }
    printf("Do you wish to create right node? Enter 1 or 0");
    int vr;
    scanf("%d", &vr);
    if (vr)
    {
        new1 = createnode();
        node1->right = new1;
        createTree(new1);
    }
}
void preorder(struct node *node1)
{
    if (node1 != NULL)
    {
        printf("%d ", node1->data);
        preorder(node1->left);
        preorder(node1->right);
    }
}
int main()
{
    root = createnode();
    createTree(root);
    preorder(root);
    return 0;
}