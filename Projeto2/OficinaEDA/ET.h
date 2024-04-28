#pragma once
#include "Arvore.h"


struct EstacaoTrabalho {
	Mecanico mecanico = Mecanico();
	int ID = 0;
	int capacidade = 0;
	int faturacao = 0;
	Carro* carros_a_ser_reparados = new Carro;
	int num_carros_a_ser_reparados = 0;
	Arvore* Carrosreparados = new Arvore;
	int num_carros_reparados = 0;
	EstacaoTrabalho* seguinte = NULL;
};

EstacaoTrabalho* CriarET(int numeroETs, LinhasFicheiro& marcas);
void reparacao(EstacaoTrabalho*& ET);

