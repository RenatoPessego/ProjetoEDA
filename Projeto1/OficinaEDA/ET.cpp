#include "ET.h"

EstacaoTrabalho CriarET(int ID) {
	EstacaoTrabalho nova = EstacaoTrabalho();
	nova.mecanico;
	nova.capacidade = 2 + (rand() % 3);
	nova.faturacao = 0;
	nova.ID = ID;
	nova.Carrosreparados = new Carro[0];
	nova.carros_a_ser_reparados = new Carro[nova.capacidade];
	nova.num_carros_a_ser_reparados = 0;
	return nova;
}

void reparacao(EstacaoTrabalho& ID1) {
	int chance;

	for (int i = 0; i < ID1.capacidade; i++) {
		if ((ID1.carros_a_ser_reparados[i].dias_em_reparacao < ID1.carros_a_ser_reparados[i].tempo_reparacao_max) && (ID1.carros_a_ser_reparados[i].ID != 0)) {
			chance = rand() % 100 + 1;
			if ((chance >= 1 and chance <= 15) && (ID1.carros_a_ser_reparados[i].dias_em_reparacao > 0)) {
				int tamanho = (ID1.num_carros_reparados);
				Adiciona(ID1.Carrosreparados, tamanho, ID1.carros_a_ser_reparados[i]);
				
				ID1.num_carros_a_ser_reparados = ID1.num_carros_a_ser_reparados - 1;
				ID1.carros_a_ser_reparados[i].ID = 0;
				ID1.faturacao = ID1.faturacao + (ID1.carros_a_ser_reparados[i].dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia);
				ID1.Carrosreparados[ID1.num_carros_reparados].custoreparacao = ID1.mecanico.preco_reparacao_por_dia * ID1.Carrosreparados[ID1.num_carros_reparados].dias_em_reparacao;
				ID1.num_carros_reparados = ID1.num_carros_reparados + 1;

			}
			else
				ID1.carros_a_ser_reparados[i].dias_em_reparacao++;
		}

		else if ((ID1.carros_a_ser_reparados[i].dias_em_reparacao >= ID1.carros_a_ser_reparados[i].tempo_reparacao_max) && (ID1.carros_a_ser_reparados[i].ID != 0)) {
			int tamanho = (ID1.num_carros_reparados);
			Adiciona(ID1.Carrosreparados, tamanho, ID1.carros_a_ser_reparados[i]);
			
			ID1.num_carros_a_ser_reparados = ID1.num_carros_a_ser_reparados - 1;
			ID1.carros_a_ser_reparados[i].ID = 0;
			ID1.faturacao = ID1.faturacao + (ID1.carros_a_ser_reparados[i].dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia);
			ID1.Carrosreparados[ID1.num_carros_reparados].custoreparacao = ID1.mecanico.preco_reparacao_por_dia * ID1.Carrosreparados[ID1.num_carros_reparados].dias_em_reparacao;
			ID1.num_carros_reparados = ID1.num_carros_reparados + 1;
		}
	}

}
