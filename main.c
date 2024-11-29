

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include "funcs.h"

int main (int argc, char* argv[]){

    No* raiz = inicializar_arvore();

    raiz = carregar_livros("livros.csv", raiz);
    
    exibir_arvore(raiz);

    return 0;
}