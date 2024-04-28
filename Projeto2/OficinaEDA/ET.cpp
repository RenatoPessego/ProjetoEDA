#include "ET.h"

EstacaoTrabalho * CriarET(int numeroETs,LinhasFicheiro& marcas) {
	EstacaoTrabalho* primeiraET = new EstacaoTrabalho;
	primeiraET->mecanico = CriarMecanico(marcas);
	primeiraET->capacidade = 2 + (rand() % 3);
	primeiraET->faturacao = 0;
	primeiraET->ID = 1;
	primeiraET->Carrosreparados = new Arvore;
	primeiraET->carros_a_ser_reparados = new Carro;
	primeiraET->num_carros_a_ser_reparados = 0;
	primeiraET->num_carros_reparados = 0;
	primeiraET->seguinte = NULL;
	EstacaoTrabalho* ETauxiliar = primeiraET;
	for (int i = 1; i < numeroETs; i++) {
		EstacaoTrabalho* novo = new EstacaoTrabalho;
		novo->mecanico = CriarMecanico(marcas);
		novo->capacidade = 2 + (rand() % 3);
		novo->faturacao = 0;
		novo->ID = i + 1;
		novo->Carrosreparados = new Arvore;
		novo->carros_a_ser_reparados = new Carro;
		novo->num_carros_a_ser_reparados = 0;
		novo->num_carros_reparados = 0;
		ETauxiliar->seguinte = novo;
		ETauxiliar = ETauxiliar->seguinte;
		if (i == numeroETs - 1)
			novo->seguinte = NULL;
		
	}
	return primeiraET;
}


void reparacao(EstacaoTrabalho *& ET) {
	bool reparar = false;
	EstacaoTrabalho* primeiraET = ET;
	EstacaoTrabalho* percorrerET = primeiraET;
	
	while (percorrerET != NULL) {
			Carro* primeirocarroaserreparado = percorrerET->carros_a_ser_reparados;
			Carro* percorreraserreparados = primeirocarroaserreparado;
			int n = percorrerET->capacidade;
			Carro* aux = percorreraserreparados;
			for (int i = 0; i < n; i ++) {
				reparar = GerarProbalidades(0.15);
				
				if (aux != NULL && aux->ID != 0 && aux->dias_em_reparacao < aux->tempo_reparacao_max) {
					if ((reparar) && aux->dias_em_reparacao > 0) {

						aux->custoreparacao = aux->dias_em_reparacao * percorrerET->mecanico.preco_reparacao_por_dia;
						percorrerET->faturacao = percorrerET->faturacao + aux->custoreparacao;
						adicionarar(percorrerET->Carrosreparados, aux);
						percorrerET->num_carros_a_ser_reparados = percorrerET->num_carros_a_ser_reparados - 1;
						percorrerET->num_carros_reparados = percorrerET->num_carros_reparados + 1;
						aux->ID = 0;
						
					}
					else {
						aux->dias_em_reparacao = aux->dias_em_reparacao + 1;
					}
				}
				else if (aux != NULL && aux->ID != 0 && aux->dias_em_reparacao > 0 && aux->dias_em_reparacao >= aux->tempo_reparacao_max) {
					aux->custoreparacao = aux->dias_em_reparacao * percorrerET->mecanico.preco_reparacao_por_dia;
					percorrerET->faturacao = percorrerET->faturacao + aux->custoreparacao;
					adicionarar(percorrerET->Carrosreparados, aux);
					percorrerET->num_carros_a_ser_reparados = percorrerET->num_carros_a_ser_reparados - 1;
					percorrerET->num_carros_reparados = percorrerET->num_carros_reparados + 1;
					aux->ID = 0;

				}
				aux = aux->seguinte;
			}
		
			percorrerET = percorrerET->seguinte;
		
	}
	
}

