// O algoritmo trata da resolução do problema 1642 - Teclado Quebrado do URI.
// Para a resolução foi utilizado a ideia de subsequência, aumentando conforme possível. i até j

#include <iostream>

using namespace std; 

char vetor_texto_input[1000001];
int vetor_qtd_caractere[128]; //Array que armazena a ocorrência de um caractere em uma subsequência.
int qtd_teclas_funcionando = 0;

int retornar_maior_sequencia() {
	int qtd_letras_distintas = 0, maior_sequencia = 0, i = 0, j = 0;
	
	//Se j estiver na última posição do vetor, não há como encontrar uma sequência maior do que a atual.
	for (i = 0; vetor_texto_input[j] != '\0'; i++)
	{
		while ((qtd_teclas_funcionando - qtd_letras_distintas) >= 0)
		{
			if (vetor_texto_input[j] == '\0') break;

			//Verifica se o próximo caractere já está na sequência analisada (i até j)
			if (vetor_qtd_caractere[int(vetor_texto_input[j])] == 0) {
				if (qtd_teclas_funcionando - (qtd_letras_distintas + 1) >= 0) qtd_letras_distintas++;
				else break;
			}

			vetor_qtd_caractere[int(vetor_texto_input[j])] += 1; //Aumenta a qtd de ocorrencia do caractere
			j++;
		}

		maior_sequencia = (j - i) > maior_sequencia ? (j - i) : maior_sequencia;

		if (vetor_qtd_caractere[int(vetor_texto_input[i])] == 1)
			qtd_letras_distintas += -1;
		
		vetor_qtd_caractere[int(vetor_texto_input[i])] += -1; //Decrementa o caractere pois a subsequencia irá mudar
	}

	return maior_sequencia;
}

int main()
{
	cin >> qtd_teclas_funcionando;
	
	//Executa até digitar 0
	while (qtd_teclas_funcionando != 0)
	{
		cin.ignore(128, '\n');
		cin.getline(vetor_texto_input, sizeof(vetor_texto_input));
		cout << retornar_maior_sequencia() << endl;

		cin >> qtd_teclas_funcionando;
		fill_n(vetor_texto_input, 1000001, 0);
		fill_n(vetor_qtd_caractere, 128, 0);
	}

	return 0;
}