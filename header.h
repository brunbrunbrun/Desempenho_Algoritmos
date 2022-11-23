#ifndef HEADER_H_
#define HEADER_H_

#include <cstddef>
//funções em busca_sequencial.cpp
int busca_sequencial(int vetor[], int tamanho, int valor);

//funções em busca_binaria.cpp
void merge(int array[],int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
int busca_binaria(int arr[], int esquerda, int direita, int valor);

//estrutura de arvore binaria de busca
class no_b
{
    public:
    int data;
    no_b* left;
    no_b* right;

    no_b(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//funções em arvore_b_busca.cpp
no_b* insertNode_b(int v, no_b*& node);
no_b* searchNode_b(int v, no_b* node);

//estrutura de arvore avl
class no_avl
{
    public:
    int data;
    no_avl* left;
    no_avl* right;
    int height;

    no_avl(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

//funções em arvore_avl.cpp
int height(no_avl* n);
int max(int a, int b);
no_avl *rightRotate(no_avl *y);
no_avl *leftRotate(no_avl *x);
int getBalance(no_avl *n);
no_avl *insertNode_avl(no_avl* node, int data);
no_avl* searchNode_avl(int v, no_avl* node);

#endif
