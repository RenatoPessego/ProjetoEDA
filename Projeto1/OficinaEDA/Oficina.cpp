#include "Oficina.h"


int numero_de_et() {
    int et_numero = 3 + (rand() % 5); // numero de ET por oficina random
    return et_numero;
}

Oficina criarOficina(LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
    Oficina nova = Oficina();
    nova.ciclos = 0; //dias de trabalho
    nova.numero_ets = numero_de_et();
    nova.ets = new EstacaoTrabalho[nova.numero_ets];
    nova.fila_espera = new Carro[0];
	nova.carrostotais = 0;
    nova.fila_espera_tamanho = 0;


    /* Criar os mecanicos conforme o numero de ets gerado*/
    for (int i = 0; i < nova.numero_ets; i++) {
        nova.ets[i] = CriarET(i+1);
        nova.ets[i].mecanico = CriarMecanico(marcas);
    }
    /*Criar 10 carros random*/
    CriarCarrosNaFila(nova,marcas,modelos,10);


    //Criar ET; criar os mecanicos; encher a fila ; criar os carros (lista das marcas e dos modelos);
    return nova;
}






bool MarcaPresente(Oficina &Of, string marca) {
	bool temp = false;
	for (int i = 0; i < Of.numero_ets; i++) {
		temp = (marca == Of.ets[i].mecanico.marca);
		if (temp) {
			break;
		}
	}

	return temp;
}


void CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num) {
	for (int i = 0; i < num; i) {
		Carro novo = CriarCarro(marcas, modelos);
		novo.ID = Of.carrostotais + 1;
		if (MarcaPresente(Of, novo.marca)) {
				Adiciona(Of.fila_espera, Of.fila_espera_tamanho, novo);
				Of.carrostotais = Of.carrostotais + 1;
				i++;
		}
	}
	system("CLS");
}

void ColocarCarrosET(Oficina& Of, int num) {
	int colocados = 0;
	while (colocados < num) {
		for (int i = 0; i < Of.numero_ets; i++) {
			for (int t = 0; t < Of.fila_espera_tamanho; t++) {
				if ((Of.ets[i].mecanico.marca == Of.fila_espera[t].marca) && (Of.ets[i].capacidade > Of.ets[i].num_carros_a_ser_reparados) &&(colocados < num)) {
					for (int z = 0; z < Of.ets[i].capacidade; z++) {
						if (Of.ets[i].carros_a_ser_reparados[z].ID == 0) {
							Of.ets[i].carros_a_ser_reparados[z] = Of.fila_espera[t];
							colocados++;
							Of.ets[i].num_carros_a_ser_reparados++;
							Remove(Of.fila_espera, Of.fila_espera_tamanho, t);
							break;
						}
					}

					
				}

			}
		}
		break;
	}
}

void colocarprioritario(Oficina& Of) {
	for (int i = 0; i < Of.fila_espera_tamanho; i++) {
		if (Of.fila_espera[i].prioritario) {
			Transportar(Of, i);
		}
	}
}

void Transportar(Oficina& Of, int ind) {
	int tamanho = Of.fila_espera_tamanho;
	int indice = 0;
	for (int z = 0; z < ind; z++) {
		if (Of.fila_espera[z].prioritario) {
			indice = indice + 1;
		}
	}
	Carro* novo = new Carro[tamanho];
	novo[indice] = Of.fila_espera[ind];
	for (int k = 0; k < indice; k++) {
		novo[k] = Of.fila_espera[k];
	}
	for (int i = indice; i < ind; i++) {
		novo[i + 1] = Of.fila_espera[i];
	}
	for (int j = ind + 1; j < tamanho; j++) {
		novo[j] = Of.fila_espera[j];
	}
	
	for (int i = 0; i < tamanho; i++) {
		Of.fila_espera[i] = novo[i];
	}
	delete[] novo;
}

void seguinte(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos)
{
	for (int i = 0; i < Of.numero_ets; i++) {
		reparacao(Of.ets[i]);

	}
	Of.ciclos++;
	CriarCarrosNaFila(Of, marcas, modelos, 10);
	colocarprioritario(Of);
	ColocarCarrosET(Of, 8);
	
}