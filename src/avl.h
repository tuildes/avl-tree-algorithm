/*
    TAD de árvore AVL

    OperaÇões:
    1. Create tree
    2. Add Value
    3. Rotate Tree (left)
    4. Rotate Tree (right)
    5. View tree
    6. Search Value
    7. Tree size
    8. Delete value
    9. Destroy tree
*/

#ifndef __AVL_H__
#define __AVL_H__

// Includes
#include <stdio.h>
#include <stdlib.h>

// Defines

// Estrutura de dados tipo NODO
struct NODE_STRUCT {
    int value;
    struct NODE_STRUCT *father,
                       *left,
                       *right;
};
typedef struct NODE_STRUCT Node;

/* ------------------------------------------------------------------------- */

// Inicializa a avl com valor V
Node* create_avl(int v);

// Insere um valor V na arvore
Node* insert_avl(int v, Node *root);

// Rotaciona o nodo atual em um sentido
void rotate_tree_avl(Node *n);
void rotate_tree_avl(Node *n);

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