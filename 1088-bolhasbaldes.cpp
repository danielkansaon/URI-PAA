//Utilizar o merge-sorte nlogn. Paradigma: dividir para conquistar
#include <iostream>
using namespace std;

void merge(int *vetor, int inicio, int meio, int fim, int *qtd_trocas)
{
	int vetor_aux[100000] = {};
	int pos_vetor1 = inicio, pos_vetor2 = meio, pos_aux = inicio;

	while (pos_aux <= fim)
	{
		if ((pos_vetor2 > fim) || (pos_vetor1 <= meio && vetor[pos_vetor1] < vetor[pos_vetor2]))
		{
			vetor_aux[pos_aux] = vetor[pos_vetor1];
			pos_vetor1++;
		}
		else
		{
			vetor_aux[pos_aux] = vetor[pos_vetor2];
			pos_vetor2++;

			*qtd_trocas += (meio - pos_vetor1) < 0 ? 0 : (meio - pos_vetor1);
		}

		pos_aux++;
	}

	for (int i = inicio; i <= fim; i++) {
		vetor[i] = vetor_aux[i];
	}
}

void merge_sort(int *v, int inicio, int fim, int *qtd_trocas)
{
	int meio = 0;

	if ((fim == inicio) || fim <= 0) // Caso base (1 posicoes)
		return;

	if (fim - inicio == 1) // Caso base (2 posicoes)
	{
		meio = ((fim - inicio) / 2) + inicio + 1;
		merge(v, inicio, meio, fim, qtd_trocas);
	}
	else
	{
		meio = (inicio + fim) / 2;
		merge_sort(v, inicio, meio, qtd_trocas);
		merge_sort(v, meio + 1, fim, qtd_trocas);
		merge(v, inicio, meio + 1, fim, qtd_trocas);
	}
}

int main()
{
	int tam_entrada = 0, n = 0;
	int qtd_trocas = 0;
	int entrada[100000];
	
	while (cin >> tam_entrada, tam_entrada != 0) { // Lendo entrada (executa até digitar n != 0)
		for (int i = 0; i < tam_entrada; i++)
			cin >> entrada[i];

		merge_sort(entrada, 0, (tam_entrada - 1), &qtd_trocas);

		if (qtd_trocas > 0 && qtd_trocas % 2 == 1)
			cout << "Marcelo";
		else
			cout << "Carlos";
	}	

	system("PAUSE");
	return 0;
}