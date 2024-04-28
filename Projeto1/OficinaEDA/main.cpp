#include "Ficheiros.h"
#include "Carro.h"
#include "Oficina.h"
#include "Gestao.h"
#include <iostream>
#include <string>




int main(int argc, char* argv[])
{
    srand(time(0));
    /* Inicilizar as structs */
    /* Com as marcas e modelos a utilizar */

    LinhasFicheiro marcas = CarregarFicheirosLista("marcas.txt");
    
    LinhasFicheiro modelos = CarregarFicheirosLista("modelo.txt");

    /* Inicilizar a Oficina */

    Oficina METAL = Oficina();

    if (argc == 2) {

        string caminho = argv[1];
        carregar_oficina(METAL, caminho);
     
    }
    else {
        
        /*limpar os couts*/
        system("CLS");

        METAL = criarOficina(marcas, modelos);

        colocarprioritario(METAL);
    }

    MenuInfo(METAL, marcas, modelos);

    Menu(METAL, marcas, modelos);


    return 0;
}
