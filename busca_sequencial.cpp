#include "header.h"

#include <iostream>
using namespace std;

int busca_sequencial(int vetor[], int tamanho, int valor)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(vetor[i] == valor)
        {
            return i;
        }
    }
    return -1;
}
