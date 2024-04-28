#include "Mecanico.h"

Mecanico CriarMecanico(LinhasFicheiro& marcas) {
	Mecanico novo = Mecanico();
	string entrada;
	double precotemp = 0;
	int preco = 0;
	string marca;
	bool sair = false;

	while (!sair) {
		cout << "Insira uma marca valida do mecanico: " << endl;
		getline(cin, marca);
		for (int i = 0; i < marcas.tamanho; i++) {
			if (removerespacos(maiuscula(marca)) == removerespacos(maiuscula(marcas.linhas[i]))) {
				novo.marca = marcas.linhas[i];
				sair = true;
				break;
			}
		}

	}
	cout << "Introduza o nome do mecanico " << endl;
	cin >> ws;
	getline(cin, novo.nome);
	while ((precotemp > 100) || (precotemp <= 0)) {
		cout << "Introduza um preco por dia do mecanico valido (inteiro entre 0 e 100)" << endl;
		getline(cin, entrada);
		while (!verificarnumero(entrada)) {
			cout << "Entrada invalida!" << endl << "Introduza o preco por dia do mecanico (inteiro entre 0 e 100)" << endl;
			getline(cin, entrada);
		}
		precotemp = stod(entrada);
	}
	preco = (int)precotemp;
	novo.preco_reparacao_por_dia = preco;
	return novo;
}

bool verificarnumero(string n) {
	if (n.length() == 0) {
		return false;
	}
	for (int i = 0; i < n.length(); i++) {
		if (isdigit(n[i]) == false) {
			return false;
		}
	}
	return true;
}