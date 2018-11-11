// O problema 1966 - Volta para casa do URI. Foi resolvido utilizando o paradigma guloso.
// Primeiramente a entrada é ordenada e posteriormente é selecionado os queijos com menor preço/volume por queijo.
// O problema é semelhante a mochila fracionária.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long orcamento = 0;
vector<int> vetor_volume = {};
vector<int> vetor_preco = {};
vector<int> vetor_volume_aux = {};
vector<int> vetor_preco_aux = {};

int retornar_qtd_cubos_base_piramide(int qtd_queijo_comprado) {
	int qtd_queijo_usado = 0;
	int nivel_piramide = 0;

	//A quantidade de queijo na base da pirâmide é exatamente o mesmo que no valor do nivel da pirâmide
	while (qtd_queijo_usado < qtd_queijo_comprado)
	{
		qtd_queijo_usado += nivel_piramide + 1;

		if (qtd_queijo_usado <= qtd_queijo_comprado)
			nivel_piramide++;
	}

	return nivel_piramide;
}

//Compra a maior quantidade de queijo possível com o orçamento existente
int comprar_maior_qtd_queijo() {
	long long valor_gasto = 0;
	int qtd_queijo = 0;

	for (size_t i = 0; i < vetor_preco.size() && valor_gasto < orcamento; i++)
	{
		//Verifica se é possível comprar o queijo inteiro ou só a fração
		if ((valor_gasto + vetor_preco[i]) <= orcamento) {
			valor_gasto += vetor_preco[i];
			qtd_queijo += vetor_volume[i];
		}
		else {//Compra fração do queijo: sempre arredonda a fração para baixo			
			qtd_queijo += ((orcamento - valor_gasto) * vetor_volume[i]) / vetor_preco[i];
			valor_gasto = orcamento;
		}
	}

	return qtd_queijo;
}

//Função ordenação por: preço/volume por queijo.
bool function_order(int i, int j) {
	return ((double)vetor_preco_aux[i] / vetor_volume_aux[i]) < ((double)vetor_preco_aux[j] / vetor_volume_aux[j]);
}

void ordenar_input() {
	vector<int> vetor_posicao_elementos;

	for (size_t i = 0; i < vetor_preco_aux.size(); i++)
		vetor_posicao_elementos.push_back(i);

	//Ordenação com base na: porcentagem de preço/volume por queijo
	sort(vetor_posicao_elementos.begin(), vetor_posicao_elementos.end(), function_order);

	//Preenchendo o vetor pela ordem
	for (size_t i = 0; i < vetor_posicao_elementos.size(); i++)
	{
		vetor_preco.push_back(vetor_preco_aux[vetor_posicao_elementos[i]]);
		vetor_volume.push_back(vetor_volume_aux[vetor_posicao_elementos[i]]);
	}
}

int main()
{
	int qtd_pecas = 0, read_input = 0, qtd_queijos_comprados = 0, qtd_base_piramide = 0;
	cin >> qtd_pecas;
	cin >> orcamento;

	//Lendo Input
	for (int i = 0; i < qtd_pecas; i++)
	{
		cin >> read_input;
		vetor_volume_aux.push_back(read_input);
	}

	//Lendo Input
	for (int i = 0; i < qtd_pecas; i++)
	{
		cin >> read_input;
		vetor_preco_aux.push_back(read_input);
	}

	ordenar_input();
	qtd_queijos_comprados = comprar_maior_qtd_queijo();
	qtd_base_piramide = retornar_qtd_cubos_base_piramide(qtd_queijos_comprados);
	cout << qtd_base_piramide << endl;

	return 0;
}