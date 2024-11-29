#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct livro {
    int codigo;
    char titulo[50];
    char autor[40];
    char genero[20];
    int ano;
    char editora[30];
    int paginas;
} livro;

typedef struct No {
    livro livro;
    struct No* esquerda;
    struct No* direita;
} No;

#endif // DEFINITIONS_H