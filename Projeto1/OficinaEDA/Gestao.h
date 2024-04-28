#pragma once
#include <iostream>
#include "Oficina.h"

void MenuInfo(Oficina& METAL,LinhasFicheiro& marcas,LinhasFicheiro& modelos);
void Menu(Oficina& METAL, LinhasFicheiro& marcas, LinhasFicheiro& modelos);

void gestao(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void reparacao_manual(Oficina& Of);
void atualizar_tempo_reparacao(Oficina& Of);
void adicionar_prioridade(Oficina& Of);
void remover_mecanico(Oficina& Of, LinhasFicheiro& marcas);
void gravar_oficina(Oficina& Of);
void carregar_oficina(Oficina& Of, string caminho);
void OrdenarCarrosAlfabeticamenteEPorDiasReparacao(Carro*& carros, int num_carros);
void OrdenarCarrosPorDiasReparacao(Carro*& carros, int num_carros);
void imprimir_oficinaportempo(Oficina& Of);
void imprimir_oficinaalfabeticamente(Oficina& Of);