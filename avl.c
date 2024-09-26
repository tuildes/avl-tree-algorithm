#include "avl.h"

Nodo* search_binary(Nodo *n, int value) {
    if (n == NULL)
        return NULL;

    if (value < n->value)
        return search_binary(n->left, value);

    else if (value > n->value)
        return search_binary(n->right, value);

    return n;
}

Nodo* create_nodo(int value) {
    Nodo *n;

    if ((n = (Nodo *) malloc(sizeof(Nodo))) == NULL)
        return NULL;

    n->value = value;
    n->level = 0;
    n->father = NULL;
    n->left = NULL;
    n->right = NULL;

    return n;
}

// Destruir NODO
void destroy_nodo(Nodo *n) {
    if (n == NULL) return;
    destroy_nodo(n->left);
    destroy_nodo(n->right);
    free(n);
}

// Imprimir ARVORE (ordenado)
void _print_tree(Nodo *n) {
    if (n == NULL) return;

    _print_tree(n->left);
    printf("%d ", n->value);
    _print_tree(n->right);
}
void print_tree(Nodo *n) {
    printf("Tree: \n");
    _print_tree(n);
    printf("\n");
}

int insert_tree(Nodo *n, int value, Nodo *f) {
    if (n == NULL) {
        Nodo *new;

        if ((new = (Nodo *) malloc(sizeof(Nodo))) == NULL)
            return 1;

        new->value = value;
        new->level = (f->level + 1);
        new->father = f;
        new->left = NULL;
        new->right = NULL;

        if (value < f->value)
            f->left = new;
        else
            f->right = new;

        return 0;
    }

    if (value < n->value)
        return insert_tree(n->left, value, n);
    return insert_tree(n->right, value, n);
}
