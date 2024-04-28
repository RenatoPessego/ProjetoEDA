#pragma once
#pragma once
#include "ET.h"

struct Oficina {
	EstacaoTrabalho* ets = new EstacaoTrabalho;
	int numero_ets = 0;
	Carro* listaespera = new Carro;
	int fila_espera_tamanho = 0;
	int carrostotais = 0;
	int ciclos = 0;
};


//Funcoes 
Carro* CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num);
Oficina CriarOficina(LinhasFicheiro& marcas);
bool MarcaPresente(EstacaoTrabalho* Of, string marca);
int numero_de_et();
void ColocarCarrosET(Oficina& Of, int num);
void criarcarrosaserreparados(EstacaoTrabalho*& et);
void organizarprioritario(Carro*& listaespera);
