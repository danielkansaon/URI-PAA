// O código trata da resolução do desafio do URI 2446 - Troco
// Para a resolução foi utilizado o paradigma de programação dinâmica.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vetor_moedas;
vector<vector<int>> matriz;

int calcular_moedas(int qtd_moedas, int valor) {
	int i, j, pos = 0, moeda = 0;

	for (i = 1; i <= qtd_moedas; ++i)
	{
		for (j = 1; j <= valor; ++j)
		{
			moeda = vetor_moedas[i - 1];

			//Lógica que verifica a quantidade de moedas necessárioas
			if (moeda <= j) {
				pos = (j - moeda) < 0 ? 0 : j - moeda;
				matriz[i][j] = max(max(moeda + matriz[i - 1][pos], moeda), matriz[i - 1][j]);
			}
			else {
				matriz[i][j] = matriz[i - 1][j];
			}
		}
	}

	//Última posição da matriz. = Qtd moedas máxima.
	return matriz[i - 1][j - 1];
}

int main()
{
	int valor_desejado = 0, qtd_moedas = 0, moeda = 0;
	cin >> valor_desejado;
	cin >> qtd_moedas;

	//Lendo input
	for (int i = 0; i < qtd_moedas; ++i)
	{
		cin >> moeda;

		if (moeda <= valor_desejado)
			vetor_moedas.push_back(moeda);
	}

	matriz.assign(vetor_moedas.size() + 1, vector<int>(valor_desejado + 1)); // Inicializando a matriz.
	int valorfinal = calcular_moedas(vetor_moedas.size(), valor_desejado);

	if (valorfinal == valor_desejado)
		cout << "S" << endl;
	else
		cout << "N" << endl;

	return 0;
}