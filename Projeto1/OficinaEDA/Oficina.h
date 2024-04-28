#pragma once
#include "ET.h"

struct Oficina {
	EstacaoTrabalho* ets;
	int numero_ets;
	Carro* fila_espera;
	int fila_espera_tamanho;
	int carrostotais;
	int ciclos;

};

Oficina criarOficina(LinhasFicheiro &marcas, LinhasFicheiro &modelos);

void seguinte(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);

void CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num);
bool  GerarProbalidades(double probalidade);
void ColocarCarrosET(Oficina& Of, int num);
void Transportar(Oficina& Of, int ind);

void colocarprioritario(Oficina& Of);
void ColocarCarrosET(Oficina& Of, int num);
