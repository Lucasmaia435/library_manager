# Gerenciador de Biblioteca

Este projeto é um gerenciador de biblioteca simples que utiliza uma árvore binária para armazenar e buscar informações sobre livros.

## Estrutura do Projeto

- `definitions.h`: Contém as definições das estruturas de dados utilizadas.
- `funcs.h`: Declaração das funções utilizadas no projeto.
- `funcs.c`: Implementação das funções declaradas em `funcs.h`.
- `main.c`: Arquivo principal que utiliza as funções para gerenciar a biblioteca.
- `livros.csv`: Arquivo CSV contendo os dados dos livros.
- `Makefile`: Arquivo para compilar o projeto.

## Como Executar

1. Certifique-se de ter o compilador GCC instalado.
2. Navegue até o diretório do projeto.
3. Compile o projeto utilizando os comandos:
    
    ```bash
    gcc -c funcs.c
    gcc -o funcs funcs.o main.c -o main
    ```
4. Caso possua a ferramenta make instalada, basta executá-la:

    ```bash
    mingw32-make.exe
    ```