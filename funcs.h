#include "definitions.h"

No* inicializar_arvore();
void inserir_livro(No** raiz, livro livro);
void buscar_por_autor(No* raiz, char autor[]);
No* carregar_livros(char* nome_arquivo, No* raiz);
void exibir_arvore(No* raiz);
void liberar_arvore(No* raiz);