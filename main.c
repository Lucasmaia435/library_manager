#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "definitions.h"
#include "funcs.h"

int main(int argc, char *argv[])
{
    // Configurar o locale para UTF-8
    setlocale(LC_ALL, "pt_BR.UTF-8");

    No *raiz = inicializar_arvore();

    raiz = carregar_livros("livros.csv", raiz);

    int command = 0;

    do
    {
        printf("\n\n+========================+\n");
        printf("|| 1 - Inserir livro    ||\n");
        printf("|| 2 - Buscar por autor ||\n");
        printf("|| 3 - Exibir arvore    ||\n");
        printf("|| 4 - Sair             ||\n");
        printf("+========================+\n\n");
        printf("Digite o comando: ");

        scanf("%d", &command);

        switch (command)
        {
        case 1:
        {
            livro livro;
            printf("Digite o codigo do livro: ");
            scanf("%d", &livro.codigo);
            printf("Digite o titulo do livro: ");
            scanf(" %[^\n]", livro.titulo);
            printf("Digite o autor do livro: ");
            scanf(" %[^\n]", livro.autor);
            printf("Digite o genero do livro: ");
            scanf(" %[^\n]", livro.genero);
            printf("Digite o ano do livro: ");
            scanf("%d", &livro.ano);
            printf("Digite a editora do livro: ");
            scanf(" %[^\n]", livro.editora);
            printf("Digite o numero de paginas do livro: ");
            scanf("%d", &livro.paginas);
            printf("Livro inserido com sucesso!\n");
            inserir_livro(&raiz, livro);
        }
        break;
        case 2:
        {
            char autor[40];
            printf("Digite o autor que deseja buscar: ");
            scanf(" %[^\n]", autor);
            buscar_por_autor(raiz, autor);
        }
        break;
        case 3:
            exibir_arvore(raiz);
            break;
        case 4:
            liberar_arvore(raiz);
            break;
        default:
            printf("Comando invalido\n");
        }
    } while (command != 4);

    return 0;
}