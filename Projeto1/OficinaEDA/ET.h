#pragma once
#include "Mecanico.h"
#include "Carro.h"
#include <string>
#include <iostream>
struct EstacaoTrabalho {
	Mecanico mecanico = {};
	int ID = 0;
	int capacidade = 0;
	float faturacao = 0;
	Carro* carros_a_ser_reparados = {}; //arrays de carros
	int num_carros_a_ser_reparados = 0;
	Carro* Carrosreparados = {};
	int num_carros_reparados = 0;

};

EstacaoTrabalho CriarET(int ID);
void reparacao(EstacaoTrabalho& ID1);

