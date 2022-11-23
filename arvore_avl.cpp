#include "header.h"

#include <iostream>
using namespace std;

int height(no_avl* n)
{
    if(n == NULL)
    {
        return 0;
    }
    return n->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

no_avl *rightRotate(no_avl *y)
{
    no_avl *x = y->left;
    no_avl *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right) + 1);
    x->height = max(height(x->left), height(x->right) + 1);

    return x;
}

no_avl *leftRotate(no_avl *x)
{
    no_avl *y = x->right;
    no_avl *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right) + 1);
    y->height = max(height(y->left), height(y->right) + 1);

    return y;
}

int getBalance(no_avl *n)
{
    if(n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

no_avl *insertNode_avl(no_avl* node, int data)
{
    if(node == NULL)
        return(new no_avl(data));

    if(data < node->data)
        node->left = insertNode_avl(node->left,data);
    else if(data > node->data)
        node->right = insertNode_avl(node->right,data);
    else
        return node;


    node->height = 1 + max(height(node->left),height(node->right));

    int balance = getBalance(node);

    if(balance > 1 && data < node->left->data)
        return rightRotate(node);

    if(balance < -1 && data > node->right->data)
        return leftRotate(node);

    if(balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

no_avl* searchNode_avl(int v, no_avl* node)
{
    if(node == NULL)
    {
        return NULL;
    }
    if(v == node->data)
    {
        return node;
    }
    if(v < node->data)
    {
        return searchNode_avl(v, node->left);
    }
    return searchNode_avl(v, node->right);
}
