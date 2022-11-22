#include <iostream>
#include <cstdlib>
#include <time.h>

#include <chrono>

#include "header.h"

using namespace std;

int main()
{
    int tamanho_v_1 = 100000;
    int tamanho_b_1 = 5000;

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

    auto t1_comeco = chrono::high_resolution_clock::now();
    //unsync entrada/saida
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < tamanho_b_1; i++)
    {
        if(busca_sequencial(vetor_dados_1, tamanho_v_1, vetor_busca_1[i]) >= 0)
        {
            n_achados++;
        }
    }
    auto t1_fim = chrono::high_resolution_clock::now();

    auto t1_ms = chrono::duration_cast<chrono::milliseconds>(t1_fim - t1_comeco);

    double t1_seg = chrono::duration_cast<chrono::nanoseconds>(t1_fim - t1_comeco).count();
    t1_seg *= 1e-9;


    cout << n_achados << endl;
    cout << t1_ms.count() << "ms\n";
    cout << "Tempo demorado em segundos: " << t1_seg;
    cout << " segundos" << endl;


return 0;
}
