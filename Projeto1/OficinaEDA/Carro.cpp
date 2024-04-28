#include "Carro.h"
#include <string>

/*Fazer probalidades--rand() vai retornar um valor entre 0 e rand_max*/
/*https://stackoverflow.com/questions/20309009/get-true-or-false-with-a-given-probability*/

bool  GerarProbalidades(double probalidade) {
	bool probalidade_final =  rand() < (probalidade * (RAND_MAX + 1.0));
	return probalidade_final;
}


Carro CriarCarro(LinhasFicheiro &marcas, LinhasFicheiro &modelos) {
	Carro novo_carro = Carro();
	novo_carro.marca = marcas.linhas[rand() % marcas.tamanho];
	novo_carro.modelo = modelos.linhas[rand() % modelos.tamanho];
	novo_carro.ID = 0;
	novo_carro.tempo_reparacao_max = 2 + (rand() % 3);
	novo_carro.dias_em_reparacao = 0;
	novo_carro.prioritario = GerarProbalidades(0.05);
	novo_carro.custoreparacao = 0;

	return novo_carro;
}

/*Recebe o array de carros, o tamanho e o carro a receber*/
/*Adiciona elemento no final do array*/
void Adiciona(Carro*& v, int& tamanho, Carro& carro)
{
	int tamanho_novo = tamanho + 1;
	Carro* novo = new Carro[tamanho_novo];
	for (int i = 0; i < tamanho; i++) {
		novo[i] = v[i];
	}
	novo[tamanho] = carro;

	delete[] v;

	v = novo;
	tamanho = tamanho_novo;
}
/*Recebe o array de carros, o tamanho e o indice a ser removido*/
/*Verifica que o array nao fica vazio com o if*/
/*Copia os itens até o indice a ser removido e pega nos itens que estao na direita do el. a remover*/
/*Deslocando-os para a esquerda*/
void Remove(Carro*& v, int& tamanho, int& ind)
{
	int tamanho_novo = tamanho - 1;
	Carro* novo = new Carro[tamanho_novo];
	if (tamanho_novo > 0) {
		for (int i = 0; i < ind; i++) {
			novo[i] = v[i];
		}
		for (int i = ind; i < tamanho_novo; i++) {
			novo[i] = v[i + 1];
		}
	}
	v = novo;
	tamanho = tamanho_novo;

}

