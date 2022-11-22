#include <iostream>
#include <cstdlib>
#include <time.h>

#include "header.h"

using namespace std;

int main()
{
    int tamanho_v_1 = 10000;
    int tamanho_b_1 = 500;

    srand(time(0));

    int vetor_dados_1[tamanho_v_1];
    for(int i = 0; i < tamanho_v_1; i++)
    {
        vetor_dados_1[i] = rand();
    }


    int vetor_busca_1[tamanho_b_1];
    for(int i = 0; i < tamanho_b_1; i++)
    {
        vetor_busca_1[i] = rand();
    }


    int n_achados = 0;

    for(int i = 0; i < tamanho_b_1; i++)
    {
        if(busca_sequencial(vetor_dados_1, tamanho_v_1, vetor_busca_1[i]) >= 0)
        {
            n_achados++;
        }
    }


cout << n_achados << endl;


cout << "yey2" << endl;

return 0;
}
