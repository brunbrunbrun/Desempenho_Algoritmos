#ifndef HEADER_H_
#define HEADER_H_

//funções em busca_sequencial.cpp
int busca_sequencial(int vetor[], int tamanho, int valor);

//funções em busca_binaria.cpp
void merge(int array[],int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
int busca_binaria(int arr[], int esquerda, int direita, int valor);
#endif
