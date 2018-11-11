//O algoritmo trata da solução do problema 2677 - Par ou Ímpar do URI.
//Para a solução foi utilizado o paradigma de programação dinâmica.

#include <iostream>
#include <vector>

using namespace std;

int vetor_input[10000];
vector<vector<int>> matriz_jogador1;
vector<vector<int>> matriz_jogador2;

//Gera a arvore de possibilidades para todos os números de entrada (TOP-DOWN)
void calcular_qtd_par(int i, int j, int *jogador1, int *jogador2) {
	int jogador1_esquerda = 0, jogador2_esquerda = 0, jogador1_direita = 0, jogador2_direita = 0;

	//Verifica se a solução já foi calculada
	if (matriz_jogador1[i][j] != -1) {
		*jogador1 = matriz_jogador1[i][j];
		*jogador2 = matriz_jogador2[i][j];
	}
	else if ((j - i) == 1) // Caso Base (2 elementos)
	{
		if ((vetor_input[i] % 2) == 0 && (vetor_input[j] % 2) == 0) {
			*jogador1 = 1;
			*jogador2 = 1;
		}
		else if ((vetor_input[i] % 2) == 0 || (vetor_input[j] % 2) == 0)
		{
			*jogador1 = 1;
			*jogador2 = 0;
		}
		else {
			*jogador1 = 0;
			*jogador2 = 0;
		}

		//Armazena o resultado na matriz
		matriz_jogador1[i][j] = *jogador1; 
		matriz_jogador2[i][j] = *jogador2;
	}
	else {
		calcular_qtd_par(i + 1, j, &jogador1_esquerda, &jogador2_esquerda); //Calcula a arvore selecionando o 1 numero
		calcular_qtd_par(i, j - 1, &jogador1_direita, &jogador2_direita); //Calcula a arvore selecionando o ultimo numero
		
		jogador2_esquerda += (vetor_input[i] % 2) == 0 ? 1 : 0; 
		jogador2_direita += (vetor_input[j] % 2) == 0 ? 1 : 0;

		//Obtêm a melhor escolha de número
		if (jogador2_esquerda >= jogador2_direita)
		{
			*jogador1 += jogador2_esquerda;
			*jogador2 += jogador1_esquerda;
		}
		else {
			*jogador1 += jogador2_direita;
			*jogador2 += jogador1_direita;
		}

		//Armazena o resultado na matriz
		matriz_jogador1[i][j] = *jogador1;
		matriz_jogador2[i][j] = *jogador2;
	}
}

void inicializar_vetor(int qtd) {

	vector<int> temp;
	int i = 0;
	
	for (i = 0; i < qtd; i++)
		temp.push_back(-1);

	for (i = 0; i < qtd; i++)
	{	
		matriz_jogador1.push_back(temp);
		matriz_jogador2.push_back(temp);
	}
}

int main()
{
	int qtd_n = 0, numero = 0, jogador1_qtd_par = 0, jogador2_qtd_par = 0;
	cin >> qtd_n;

	while (qtd_n != 0)
	{
		//Lendo segunda linha do input
		for (int i = 0; i < qtd_n * 2; i++)
		{
			cin >> numero;
			vetor_input[i] = (numero);
		}

		inicializar_vetor(qtd_n * 2);
		calcular_qtd_par(0, qtd_n * 2 - 1, &jogador1_qtd_par, &jogador2_qtd_par);

		cout << jogador1_qtd_par << endl; // Imprimindo resultado

		cin >> qtd_n;
		jogador1_qtd_par = 0;
		jogador2_qtd_par = 0;
		matriz_jogador1.clear();
		matriz_jogador2.clear();
	}

	return 0;
}