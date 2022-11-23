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

#endif
