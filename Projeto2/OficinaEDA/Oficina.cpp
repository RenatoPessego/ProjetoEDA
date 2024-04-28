#include "Oficina.h"

Oficina CriarOficina(LinhasFicheiro& marcas) {
	Oficina novaof = Oficina();
	novaof.numero_ets = numero_de_et();
	novaof.ets = CriarET(novaof.numero_ets,marcas);

	novaof.carrostotais = 0;
	novaof.ciclos = 0;
	novaof.fila_espera_tamanho = 0;
	novaof.listaespera = new Carro();
	return novaof;
}
Carro* CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num) {
	Carro* primeirocarro = new Carro();
	while (!MarcaPresente(Of.ets, primeirocarro->marca)) {
		primeirocarro = CriarCarro(marcas, modelos);
		primeirocarro->ID = Of.carrostotais + 1;
	}
	Of.carrostotais = Of.carrostotais + 1;

	Carro* Carroauxiliar = primeirocarro;
	for (int i = 0; i < num-1; i) {
		Carro* novo = new Carro();
		while (!MarcaPresente(Of.ets, novo->marca)) {
			novo = CriarCarro(marcas, modelos);
			novo->ID = Of.carrostotais + 1;
			Carroauxiliar->seguinte = novo;
		}
		Carroauxiliar->seguinte = novo;
		Carroauxiliar = Carroauxiliar->seguinte;
		Of.carrostotais = Of.carrostotais + 1;
		i++;
		}
	Carroauxiliar->seguinte = NULL;
	system("CLS");
	return primeirocarro;
}


bool MarcaPresente(EstacaoTrabalho * primeiraET, string marca) {
	bool temp = false;
	EstacaoTrabalho* atual = primeiraET;
	while (atual != NULL) {
		temp = (marca == atual->mecanico.marca);
		if (temp) {
			break;
		}
		atual = atual->seguinte;
	}
	
	return temp;

}

int numero_de_et() {
	int et_numero = 3 + (rand() % 5); // numero de ET por oficina random
	return et_numero;
}



void organizarprioritario(Carro*& listaespera) {
	Carro* primeirocarro = listaespera;
	Carro* percorrerlistaespera1 = primeirocarro;
	percorrerlistaespera1 = percorrerlistaespera1->seguinte;
	Carro* novolistaespera = new Carro;
	novolistaespera->seguinte = NULL;
	Carro* finalprioritario = novolistaespera;
	Carro* alterarfinal = finalprioritario;

	Carro* novolistaesperanp = new Carro;
	novolistaesperanp->seguinte = NULL;
	Carro* finalnp = novolistaesperanp;
	Carro* alterarfinalnp = finalnp;


	while (percorrerlistaespera1 != NULL) {
		Carro* proximoCarro = percorrerlistaespera1->seguinte; // guardar o próximo carro da lista de espera

		if (percorrerlistaespera1->prioritario) {
				alterarfinal->seguinte = percorrerlistaespera1;
				alterarfinal = alterarfinal->seguinte;

		}
		else {
			alterarfinalnp->seguinte = percorrerlistaespera1;
			alterarfinalnp = alterarfinalnp->seguinte;
		}

		percorrerlistaespera1 = proximoCarro; // percorrer a lista
	}

	alterarfinal->seguinte = finalnp->seguinte;
	alterarfinalnp->seguinte = NULL; // Para ter a certeza que não é cíclico


	listaespera = finalprioritario; // Se o ultimo carro nao for prioritario, a lista de espera sera a lista prioritaria completa
	
}


void criarcarrosaserreparados(EstacaoTrabalho *& et){
	EstacaoTrabalho* primeiraet = et;
	EstacaoTrabalho* percorreret = primeiraet;
	while (percorreret != NULL) {
		Carro* primeirocarro = percorreret->carros_a_ser_reparados;
		Carro* atualcarro = primeirocarro;
		for (int i = 0; i < percorreret->capacidade-1; i++) {
			atualcarro->seguinte = new Carro;
			atualcarro = atualcarro->seguinte;
		}
		percorreret = percorreret->seguinte;
	}

}

void ColocarCarrosET(Oficina& Of, int num) {
	int colocados = 0;
	bool colocado = false;
	Carro* primeirocarro = Of.listaespera;
	Carro* percorrerespera = primeirocarro;
	percorrerespera = percorrerespera->seguinte;


	while (colocados < num) {
		while (percorrerespera != NULL) {
			colocado = false;
			EstacaoTrabalho* primeiraet = Of.ets;
			EstacaoTrabalho* percorreret = primeiraet;
			while (percorreret != NULL) {
				if ((percorreret->mecanico.marca == percorrerespera->marca) && (colocados < num)) {
					Carro* primeirocarrroaserreparado = percorreret->carros_a_ser_reparados;
					Carro* percorreraserreparados = primeirocarrroaserreparado;
					for (int i = 0; i < percorreret->capacidade; i++) {
						if (percorreraserreparados->ID == 0) {
							percorreraserreparados->custoreparacao = percorrerespera->custoreparacao;
							percorreraserreparados->dias_em_reparacao = percorrerespera->dias_em_reparacao;
							percorreraserreparados->ID = percorrerespera->ID;
							percorreraserreparados->marca = percorrerespera->marca;
							percorreraserreparados->modelo = percorrerespera->modelo;
							percorreraserreparados->prioritario = percorrerespera->prioritario;
							percorreraserreparados->seguinte = percorreraserreparados->seguinte;
							percorreraserreparados->tempo_reparacao_max = percorrerespera->tempo_reparacao_max;
							removercarro(Of.listaespera, percorrerespera->ID);
							colocados++;
							colocado = true;
							percorreret->num_carros_a_ser_reparados++;
							break;
						}
						percorreraserreparados = percorreraserreparados->seguinte;
					}
					if (colocado) {
						break;
					}
				}
				percorreret = percorreret->seguinte;
			}
			percorrerespera = percorrerespera->seguinte;
		}
		break;
	}
}
