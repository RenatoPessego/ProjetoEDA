#include "Gestao.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	LinhasFicheiro modelos = CarregarFicheirosLista("modelos.txt");
	LinhasFicheiro marcas = CarregarFicheirosLista("marcas.txt");

	Oficina Of = Oficina();
	if (argc == 2) {

		string caminho = argv[1];
		//carregar_oficina(Of, caminho);

	}
	else {

		/*limpar os couts*/
		system("CLS");

		Of = CriarOficina(marcas);
		criarcarrosaserreparados(Of.ets);
		Of.listaespera = new Carro;
		Of.listaespera->seguinte = CriarCarrosNaFila(Of, marcas, modelos, 10);
		organizarprioritario(Of.listaespera);

	}

	MenuInfo(Of);

	Menu(Of,marcas, modelos);

	return 0;

}

