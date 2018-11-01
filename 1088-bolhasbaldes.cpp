//Utilizar o merge-sorte nlogn. Paradigma: dividir para conquistar
#include <iostream>
using namespace std;

int main()
{
    int qtd, qtd_trocas;

    cin >> qtd;

    int numbers[qtd];
    for (int i = 0; i < qtd; i++)
    {
        cin >> numbers[i];
    }

    merge_sort(numbers, 0, qtd - 1, &qtd_trocas);
    cout << "teste";
}

int *merge(int v1[], int v2[], int meio, int fim, int *qtd_trocas)
{
    int vetor_aux[fim + 1];
    int pos_v1 = 0, pos_v2 = 0, pos_aux = 0;

    while (pos_aux <= fim)
    {
        if (pos_v1 <= meio && v1[pos_v1] < v2[pos_v2])
        {
            vetor_aux[pos_aux] = v1[pos_v1];
            pos_v1++;
        }
        else
        {
            vetor_aux[pos_aux] = v2[pos_v2];
            pos_v2++;

            *qtd_trocas += (meio - pos_v1);
        }

        pos_aux++;
    }

    return vetor_aux;
}

int *merge_sort(int v[], int inicio, int fim, int *qtd_trocas)
{
    int meio;

    if ((fim - inicio) == 1)
    {
        return v;
    }
    else if (fim - inicio == 2)
    {
        int v1[1] = {v[0]};
        int v2[1] = {v[1]};
        return merge(v1, v2, 1, 2, qtd_trocas);
    }
    else
    {
        meio = (inicio + fim) / 2;
        int *v1 = merge_sort(v, inicio, meio, qtd_trocas);
        int *v2 = merge_sort(v, meio + 1, fim, qtd_trocas);
        return merge(v1, v2, meio, fim, qtd_trocas);
    }

    return v;
}