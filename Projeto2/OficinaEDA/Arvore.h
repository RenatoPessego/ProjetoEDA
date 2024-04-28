#pragma once
#pragma once
#include "Carro.h"
#include "Mecanico.h"

struct Arvore {
    Carro* carros_reparados = new Carro;
    struct Arvore* esquerda, * direita = NULL;
};
Arvore* novoNodo(Carro* item);
void insert(Arvore*& nodo, Carro* chave);
void adicionarar(Arvore*& raiz, Carro* chave);
int numeroniveis(Arvore* raiz);
void imprimirarvore(Arvore* root, int niveis);
void organizarordem(Arvore* raiz, string*& A);
int percorrerdireita(Arvore* raiz);
void espinha(Arvore* root);
void printArray(string*& A, int n);
void printArray(Arvore* raiz);
Arvore* ordernar(Arvore* raiz);
