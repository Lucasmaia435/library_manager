#include "funcs.h"
#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para inicializar a árvore
No *inicializar_arvore()
{
    return NULL;
}

// Função para inserir um livro na árvore
void inserir_livro(No **raiz, livro livro)
{
    if (*raiz == NULL)
    {
        *raiz = (No *)malloc(sizeof(No));
        (*raiz)->livro = livro;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else if (livro.codigo < (*raiz)->livro.codigo)
    {
        inserir_livro(&(*raiz)->esquerda, livro);
    }
    else
    {
        inserir_livro(&(*raiz)->direita, livro);
    }
}

// Função para buscar livros por autor
void buscar_por_autor(No *raiz, char autor[])
{
    if (raiz != NULL)
    {
        buscar_por_autor(raiz->esquerda, autor);
        if (strcmp(raiz->livro.autor, autor) == 0)
        {
            printf("Codigo: %d, Titulo: %s, Autor: %s, Genero: %s, Ano: %d, Editora: %s, Paginas: %d\n",
                   raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor, raiz->livro.genero,
                   raiz->livro.ano, raiz->livro.editora, raiz->livro.paginas);
            exibir_arvore(raiz->direita);
        }
        buscar_por_autor(raiz->direita, autor);
    }
}

// Função para carregar livros de um arquivo
No *carregar_livros(char *nome_arquivo, No *raiz)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return raiz;
    }

    livro livro;
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo))
    {
        sscanf(linha, "%d,%50[^,],%40[^,],%20[^,],%d,%30[^,],%d", &livro.codigo, livro.titulo, livro.autor, livro.genero, &livro.ano, livro.editora, &livro.paginas);
        inserir_livro(&raiz, livro);
    }

    fclose(arquivo);
    return raiz;
}

// Função para exibir a árvore
void exibir_arvore(No *raiz)
{
    if (raiz != NULL)
    {
        exibir_arvore(raiz->esquerda);
        printf("Codigo: %d, Titulo: %s, Autor: %s, Genero: %s, Ano: %d, Editora: %s, Paginas: %d\n",
               raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor, raiz->livro.genero,
               raiz->livro.ano, raiz->livro.editora, raiz->livro.paginas);
        exibir_arvore(raiz->direita);
    }
}

// Função para liberar a memória da árvore
void liberar_arvore(No *raiz)
{
    if (raiz != NULL)
    {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}
