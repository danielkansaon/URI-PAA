//Utilizar o merge-sorte nlogn. Paradigma: dividir para conquistar
#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int *v1 int inicio, int meio, int fim, int *qtd_trocas)
{
    int vetor_aux [fim + 1] = {};
    int pos_v1 = inicio, pos_v2 = meio, pos_aux = 0;

    cout << v1[0];
    while (pos_aux <= fim)
    {
        if (pos_v1 <= meio && v1[pos_v1] < v1[pos_v2])
        {
            vetor_aux[pos_aux] = v1[pos_v1];
            pos_v1++;
        }
        else
        {
            vetor_aux[pos_aux] = v1[pos_v2];
            pos_v2++;

            *qtd_trocas += (meio - pos_v1);
        }

        pos_aux++;
    }

    for(i = inicio; i <= posicaoFim; i++) {
        v1[i] = vetor_aux[i - inicio];
    }
}

void merge_sort(int v*, int inicio, int fim, int *qtd_trocas)
{
    int meio = 0;
    if ((fim == inicio)) // Caso base (1 posicoes)
    {
        //return 0;
    }
    else if (fim - inicio == 1) // Caso base (2 posicoes)
    {
        merge(v, 0, 0, 1, qtd_trocas);
    }
    else
    {
        meio = (inicio + fim) / 2;
        merge_sort(v, inicio, meio, qtd_trocas);
        merge_sort(v, meio + 1, fim, qtd_trocas);        
        merge(v, inicio, meio, fim, qtd_trocas);
    }
}

int main()
{
    int qtd = 0;
    int trocas = 0;

    cin >> qtd;

    int numbers[qtd];
    for (int i = 0; i < qtd; i++)
    {
        cin >> numbers[i];
    }

    merge_sort(numbers, 0, (qtd - 1) , &trocas);

    cout << trocas;

    system("PAUSE");
}