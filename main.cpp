#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

#include "header.h"

using namespace std;

int main()
{
    int tamanho_v_1 = 100000;
    int tamanho_b_1 = 100000;

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

    //busca sequencial

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


    cout << "--------------" << endl;

    //busca binaria
    int ordenado_vetor_dados_1[tamanho_v_1];
    for(int i = 0; i < tamanho_v_1; i++)
    {
        ordenado_vetor_dados_1[i] = vetor_dados_1[i];
    }

    //ordenando o vetor para poder aplicar a busca binaria
    mergeSort(ordenado_vetor_dados_1, 0, tamanho_v_1 - 1);

    n_achados = 0;

    auto t2_comeco = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < tamanho_b_1; i++)
    {
        if(busca_binaria(ordenado_vetor_dados_1, 0, tamanho_v_1 - 1, vetor_busca_1[i]) >= 0)
        {
            n_achados++;
        }
    }
    auto t2_fim = chrono::high_resolution_clock::now();

    auto t2_ms = chrono::duration_cast<chrono::milliseconds>(t2_fim - t2_comeco);

    double t2_seg = chrono::duration_cast<chrono::nanoseconds>(t2_fim - t2_comeco).count();
    t2_seg *= 1e-9;


    cout << n_achados << endl;
    cout << t2_ms.count() << "ms\n";
    cout << "Tempo demorado em segundos: " << t2_seg;
    cout << " segundos" << endl;



    //arvore binaria de busca
    cout << "---------" << endl;
    no_b* arvore_b_b = NULL;

    //inserindo o vetor aleatorio na arvore
    for(int i = 0; i < tamanho_v_1; i++)
    {
        insertNode_b(vetor_dados_1[i], arvore_b_b);
    }


    n_achados = 0;

    auto t3_comeco = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < tamanho_b_1; i++)
    {
        if(searchNode_b(vetor_busca_1[i], arvore_b_b) != NULL)
        {
            n_achados++;
        }
    }
    auto t3_fim = chrono::high_resolution_clock::now();

    auto t3_ms = chrono::duration_cast<chrono::milliseconds>(t3_fim - t3_comeco);

    double t3_seg = chrono::duration_cast<chrono::nanoseconds>(t3_fim - t3_comeco).count();
    t3_seg *= 1e-9;

    cout << n_achados << endl;
    cout << t3_ms.count() << "ms\n";
    cout << "Tempo demorado em segundos: " << t3_seg;
    cout << " segundos" << endl;


    //arvore AVL
    cout << "---------" << endl;
    no_avl* arvore_avl = NULL;

    //inserindo o vetor na arvore avl
    for(int i = 0; i < tamanho_v_1; i++)
    {
        arvore_avl = insertNode_avl(arvore_avl, vetor_dados_1[i]);
    }


    n_achados = 0;

    auto t4_comeco = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < tamanho_b_1; i++)
    {
        if(searchNode_avl(vetor_busca_1[i], arvore_avl) != NULL)
        {
            n_achados++;
        }
    }
    auto t4_fim = chrono::high_resolution_clock::now();

    auto t4_ms = chrono::duration_cast<chrono::milliseconds>(t4_fim - t4_comeco);

    double t4_seg = chrono::duration_cast<chrono::nanoseconds>(t4_fim - t4_comeco).count();
    t4_seg *= 1e-9;

    cout << n_achados << endl;
    cout << t4_ms.count() << "ms\n";
    cout << "Tempo demorado em segundos: " << t4_seg;
    cout << " segundos" << endl;


return 0;
}
