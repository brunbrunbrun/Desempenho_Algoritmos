#include "header.h"

#include <iostream>
using namespace std;

//inserir um valor na arvore
no_b* insertNode_b(int v, no_b*& node)
{
    if(node == NULL)
    {
        node = new no_b(v);
    }
    else
    {
        if(v < node->data)
        {
            node->left = insertNode_b(v, node->left);
        }
        else
        {
            node->right = insertNode_b(v, node->right);
        }
    }
    return node;
}

//busca na arvore binaria
no_b* searchNode_b(int v, no_b* node)
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
        return searchNode_b(v, node->left);
    }
    return searchNode_b(v, node->right);
}
