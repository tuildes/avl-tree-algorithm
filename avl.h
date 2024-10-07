#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>

// TAD DE ARVORE AVL
//
// Operacoes: 
//  0. CREATE TREE
//  1. ADD VALUE
//  2. ROTATE TREE (LEFT)
//  3. VIEW TREE
//  4. SEARCH VALUE
//  5. TREE SIZE
//  5. DELETE VALUE,
//  6. DESTROY

// Struct NODO
struct NODO_STRUCT {
    int value;

    // Ponteiros para outros NODOs
    struct NODO_STRUCT *father,
                       *left,
                       *right;
};
typedef struct NODO_STRUCT Nodo;

Nodo* create_avl(int value);

int insert_avl(Nodo *n, int value);

Nodo* rotate_avl_left(Nodo *n);
Nodo* rotate_avl_right(Nodo *n);

void view_avl(Nodo *n); // Imprime de forma ORDENADA (EM ORDEM)

Nodo* search_avl(Nodo *root, int value);

int size_avl(Nodo *root);

void delete_avl();

void destroy_avl(Nodo *n);

#endif // AVL_H_
