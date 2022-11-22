#include "header.h"

#include <iostream>
using namespace std;


void merge(int array[],int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    //arrays temporarios
    auto *leftArray = new int[subArrayOne],*rightArray = new int[subArrayTwo];

    //copiar dados para os arrays temporarios
    for (auto i = 0; i < subArrayOne; i++)
    leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
    rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    //merge dos arrays
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    //copiar os elementos restantes de left[], se tiver algum
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    //copiar os elementos restantes de right[], se tiver
    while (indexOfSubArrayTwo < subArrayTwo)
    {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
    }

    //deletar os arrays temporarios
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
    return; // Retorna recursivamente

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


// algoritmo de busca binaria
int busca_binaria(int arr[], int esquerda, int direita, int valor)
{
    if(direita >= esquerda)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if(arr[meio] == valor)
            return meio;

        if(arr[meio] > valor)
            return busca_binaria(arr, esquerda, meio - 1, valor);

        return busca_binaria(arr, meio + 1, direita, valor);
    }
    return -1;
}
