#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *l;
    struct node *r;
} *root = NULL, *temp = NULL, *t2, *t1;

void createNode(int key);
void delete1(struct node *t);
void insert(int key);
void delete (int key);
void find(struct node *t, int key);
int smallest(struct node *t);
int largest(struct node *t);
void pos(struct node *t, int key);
void preorder(struct node *t);
void postorder(struct node *t);
void inorder(struct node *t);

int flag = 1;

void createNode(int key)
{
    temp = (struct node *)malloc(1 * sizeof(struct node));
    temp->value = key;
    temp->l = temp->r = NULL;
}

void insert(int key)
{
    createNode(key);
    if (root == NULL)
        root = temp;
    else
        pos(root, key);
}

void pos(struct node *t, int key)
{
    if ((key > t->value) && (t->r != NULL)) /* value more than root node value insert at right */
        pos(t->r, key);
    else if ((key > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((key < t->value) && (t->l != NULL)) /* value less than root node value insert at left */
        pos(t->l, key);
    else if ((key < t->value) && (t->l == NULL))
        t->l = temp;
}

void delete (int key)
{
    if (root == NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    t1 = root;
    t2 = root;
    find(root, key);
}

void find(struct node *t, int key)
{
    if ((key > t->value))
    {
        t1 = t;
        find(t->r, key);
    }
    else if ((key < t->value))
    {
        t1 = t;
        find(t->l, key);
    }
    else if ((key == t->value))
    {
        delete1(t);
    }
}

void delete1(struct node *t)
{
    int k;
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
    else if ((t->r == NULL))
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }
    else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t == NULL;
        free(t);
        return;
    }
    /* To delete node having two child */
    else if ((t->l != NULL) && (t->r != NULL))
    {
        t2 = root;
        if (t->r != NULL)
        {
            k = smallest(t->r);
            flag = 1;
        }
        else
        {
            k = largest(t->l);
            flag = 2;
        }
        find(root, k);
        t->value = k;
    }
}

int smallest(struct node *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return (smallest(t->l));
    }
    else
        return (t->value);
}

int largest(struct node *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return (largest(t->r));
    }
    else
        return (t->value);
}

void search(struct node *t, int key)
{
    //printf("1");
    if (t != NULL)
    {
        if ((key > t->value))
        {
            search(t->r, key);
        }
        else if ((key < t->value))
        {
            search(t->l, key);
        }
        else if ((key == t->value))
        {
            printf("%d is present.\n", key);
            return;
        }
    }
    else
    {
        printf("%d is not present.\n", key);
        return;
    }
}

void inorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}

void preorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    printf("%d ", t->value);
    if (t->l != NULL)
        preorder(t->l);
    if (t->r != NULL)
        preorder(t->r);
}

void postorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->l != NULL)
        postorder(t->l);
    if (t->r != NULL)
        postorder(t->r);
    printf("%d ", t->value);
}

struct node *rlrotation(struct node *t)
{
    struct node *p;
    struct node *tp;
    struct node *tp2;
    struct node *f;
    f = t;
    p = t->r;
    tp = p->r;
    tp2 = p->r->l;

    p->r = tp2->l;
    tp->l = tp2->r;
    tp2->l = p;
    tp2->r = tp;
    f->r = tp2;
}

struct node *lrrotation(struct node *t)
{
    struct node *p;
    struct node *tp;
    struct node *tp2;
    struct node *f;
    f = t;
    p = f->l;
    tp = p->l;
    tp2 = p->l->r;

    p->l = tp2->r;
    tp->r = tp2->l;
    tp2->r = p;
    tp2->l = tp;
    f->l = tp2;
}

void main()
{
    insert(25);
    insert(20);
    insert(10);
    insert(5);
    insert(12);
    insert(22);
    insert(36);
    insert(30);
    insert(28);
    insert(40);
    insert(38);
    insert(48);
    delete (30);
    delete (28);
    delete (20);

    lrrotation(root);
    rlrotation(root);
    printf("INORDER:\n");
    inorder(root);
    printf("\nPOSTORDER:\n");
    postorder(root);
    printf("\nPREORDER:\n");
    preorder(root);
    printf("\n");
}
