#include "Arvore.h"


Arvore* novoNodo(Carro* item){

    Arvore* temp = new Arvore();
    temp->carros_reparados->custoreparacao = item->custoreparacao;
    temp->carros_reparados->dias_em_reparacao = item->dias_em_reparacao;
    temp->carros_reparados->marca = item->marca;
    temp->carros_reparados->modelo = item->modelo;
    temp->carros_reparados->prioritario = item->prioritario;
    temp->carros_reparados->seguinte = NULL;
    temp->carros_reparados->tempo_reparacao_max = item->tempo_reparacao_max;
    temp->carros_reparados->ID = item->ID;
    temp->esquerda = temp->direita = NULL;
    return temp;
}
void insert(Arvore*& nodo, Carro* chave) {
    Arvore* novonodo = novoNodo(chave);
    Arvore* inicioarvore = nodo;
    Arvore* temp = inicioarvore;
    while (temp != NULL) {
        if (chave->modelo >= temp->carros_reparados->modelo) {
            if (temp->direita == NULL || temp->direita->carros_reparados->ID == 0) {
                temp->direita = novonodo;
                return;
            }
            else {
                temp = temp->direita;
            }
        }
        else {
            if (temp->esquerda == NULL || temp->esquerda->carros_reparados->ID == 0) {
                temp->esquerda = novonodo;
                return;
            }
            else {
                temp = temp->esquerda;
            }
        }
    }
    temp = novonodo;
}
void adicionarar(Arvore*& raiz, Carro* chave) {
    if (raiz->carros_reparados->ID == 0 || raiz == NULL) {
        raiz = novoNodo(chave);
        raiz->direita = NULL;
        raiz->esquerda = NULL;
    }
    else {
        insert(raiz, chave);
    }
}

int numeroniveis(Arvore* raiz){
    int h = 0;
    if (raiz != NULL )
    {
        if (raiz->carros_reparados->ID != 0) {
            int alturaesq = numeroniveis(raiz->esquerda);
            int alturadir = numeroniveis(raiz->direita);
            int alturamax = max(alturaesq, alturadir);
            h = alturamax + 1;
        }
    }
    return h;
}

void imprimirarvore(Arvore* no, int nivel) {
	if (no == NULL || no->carros_reparados->ID == 0){
		cout << endl;
		return;
	}
	imprimirarvore(no->direita, nivel + 1);
	for (int i = 1; i < nivel; i++)
	{
		cout << "\t";
	}
	cout << no->carros_reparados->ID << endl;
	imprimirarvore(no->esquerda, nivel + 1);
}


void espinha(Arvore* raiz)
{
    if (raiz->carros_reparados->ID == 0) {
        return;
    }
    if (raiz == NULL || raiz != NULL && raiz->esquerda == NULL && raiz->direita == NULL)
        return;


    if (raiz->esquerda != NULL) {

        espinha(raiz->esquerda);

        Arvore* temp = raiz->direita;
        raiz->direita = raiz->esquerda;
        raiz->esquerda = NULL;
        Arvore* t = raiz->direita;
        while (t->direita != NULL)
            t = t->direita;

        t->direita = temp;
    }

    espinha(raiz->direita);
}

Arvore* ordernar(Arvore* raiz)
{
    Arvore* i = raiz;

    while (i) {
        Arvore* j = raiz;
        Arvore* prev = raiz;
        while (j->direita) {
            Arvore* temp = j->direita;
            if (j->carros_reparados->modelo > temp->carros_reparados->modelo) {
                if (j == raiz) {
                    j->direita = temp->direita;
                    temp->direita = j;
                    prev = temp;
                    raiz = prev;
                }
                else {
                    j->direita = temp->direita;
                    temp->direita = j;
                    prev->direita = temp;
                    prev = temp;
                }
                continue;
            }
            prev = j;
            j = j->direita;

        }
        i = i->direita;
    }
    return raiz;
}

void printArray(Arvore* raiz)
{
    {
        Arvore* temp = raiz;
        Arvore* auxtemp = temp;
        if (auxtemp != NULL) {
            cout << auxtemp->carros_reparados->modelo << endl;
        }

        while (auxtemp->direita != NULL)
        {
            cout << auxtemp->direita->carros_reparados->modelo << endl;
            auxtemp = auxtemp->direita;
        }
        cout << endl;
    }
}