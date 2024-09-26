#ifndef AVL_H_
#define AVL_H_

// Includes de todo o projeto
#include <stdio.h>
#include <stdlib.h>

// Struct NODO
struct Nodo {
    unsigned int level;
    int value;

    // Ponteiros para outros NODOs
    struct _nodo *father,
                 *left,
                 *right;
};
typedef struct Nodo Nodo;

// Imprime a ARVORE de forma recursiva
// Imprime de forma ordenada
void _print_tree(Nodo *n); // Função indireta
void print_tree(Nodo *n); // Você deve usar esta árvore

// Deleta um NODO especifico da arvore
// Se não encontrar 
Nodo* delete_nodo(Nodo *root, int target);

// Cria a árvore AVL
// Retorna o ponteiro da arvore criada
Nodo* create_tree(int value);

// Insere na arvore
Nodo* _insert_tree(Nodo *actual, Nodo *father, int value);
Nodo* insert_tree(Nodo *root, int value);

// Destroi a arvore e livra a memoria alocada
void destroy_tree(Nodo *root);

// Entrada do tipo: I/R value
// I - inserir valor
// R - remover valor
int operate_tree(char c, int value, Nodo *root);

// Rotacao de arvore
void rotate_tree(Nodo *n);

// Retorna NULL para nao encontrado
// Retorna o PONTEIRO para o nodo com o valor encontrado
Nodo* search_binary(Nodo *root, int value);

int insert_tree(Nodo *n, int value, Nodo *f);

#endif // AVL_H_
