/*
    TAD de árvore AVL

    Descrição

    @tuildes - Gustavo Frehse
    16/10/2024
*/

#ifndef __AVL_H__
#define __AVL_H__

// Includes
#include <stdio.h>
#include <stdlib.h>

// Defines
typedef enum { FALSE, TRUE } bool;

// Estrutura de dados tipo NODO
struct NODE_STRUCT {
    int value;
    size_t level;
    struct NODE_STRUCT *father,
                       *left,
                       *right;
};
typedef struct NODE_STRUCT Node;

/* ------------------------------------------------------------------------- */

// Inicializa a avl com valor V
Node* create_avl(int v);

// Insere um valor V na arvore
// Coloca iguais a direita
Node* insert_avl(int v, Node **root);

// Rotaciona o nodo atual em um sentido
Node* rotate_tree_avl_left(Node *n);
Node* rotate_tree_avl_right(Node *n);

// Imprime em pre ordem (ordenado)
void view_avl(Node *n);

// Procura um valor e retorna seu ponteiro (1 encontrado)                      
// Retorna NULL para não encontrado
Node* search_avl(int v, Node *root);

// Retorna o tamanho da arvore
size_t height_avl(Node *n);

// Deleta um valor da AVL
// Retorna o valor removido ou 0 para não encontrado
int delete_avl(int v, Node *root);

// Destroi a AVL atual e desaloca memória
void destroy_avl(Node *root);

#endif // __AVL_H__