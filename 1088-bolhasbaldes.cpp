// Utilizar o merge-sorte O(n*logn). Paradigma: dividir para conquistar (merge sort).
// O algoritmo trata da resolução do problema 1088 do URI - Bolhas e Baldes.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//VARIAVEIS GLOBAIS
int qtd_trocas = 0;
vector<int> numeros_jogo;
//VARIAVEIS GLOBAIS

//Junta 2 vetores em ordem crescente
vector<int> merge(vector<int> v1, vector<int> v2) {
	int pos_v1 = 0, pos_v2 = 0, tam_v1 = v1.size(), tam_v2 = v2.size();
	vector<int> vetor_ordenado;

	//Iteração para ordenar os dois vetores
	while (pos_v1 < tam_v1 || pos_v2 < tam_v2) {
		//Verifica qual posição dos vetores é menor. V1 ou V2.
		if ((pos_v2 >= tam_v2) || (pos_v1 < tam_v1) && v1[pos_v1] < v2[pos_v2]) {
			vetor_ordenado.push_back(v1[pos_v1]);
			++pos_v1;
		}
		else if (pos_v2 < tam_v2) { 
			vetor_ordenado.push_back(v2[pos_v2]);
			qtd_trocas += (tam_v1)-pos_v1; // Conta quantos movimentos necessários para ordenar uma posição.
			++pos_v2;
		}
	}

	return vetor_ordenado;
}

//Divide o vetor em várias posições de forma recursiva.
vector<int> merge_sort(int inicio, int fim) {
	if ((fim - inicio) > 1) {
		int meio = ((inicio + fim) / 2);
		return merge(merge_sort(inicio, meio), merge_sort(meio, fim));
	}

	return vector<int>{ numeros_jogo[inicio] }; // Caso Base (n = 1)
}

int main()
{
	int tam_entrada = 0, valor_input = 0, i = 0;

	//Executa até digitar 0.
	while (true) {
		cin >> tam_entrada;
		if (tam_entrada == 0) break;

		for (i = 0; i < tam_entrada; ++i) {
			cin >> valor_input;
			numeros_jogo.push_back(valor_input);
		}

		merge_sort(0, tam_entrada);
			
		if (qtd_trocas % 2 != 0) cout << "Marcelo" << endl;
		else cout << "Carlos" << endl;

		qtd_trocas = 0;
		numeros_jogo.clear();
	}

	return 0;
}