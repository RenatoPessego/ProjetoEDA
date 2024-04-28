#pragma once
#include "Oficina.h"

void MenuInfo(Oficina& of);
void seguinte(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void gestao(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void Menu(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void atualizar_tempo_reparacao(Oficina& Of);
void adicionar_prioridade(Oficina& Of);
void adicionar_ET(Oficina& of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void remover_mecanico(Oficina& Of, LinhasFicheiro& marcas);
void imprimiroficinaporrerpresentacao(Oficina& of);
//void gravar_oficina(const Oficina& oficina);
void gravar_oficina(const Oficina& oficina);
//void carregar_oficina(Oficina& Of, string& caminho);
void carregar_oficina(Oficina& oficina, const string& caminho);
void imprimiralfabeticamente(Oficina& of);