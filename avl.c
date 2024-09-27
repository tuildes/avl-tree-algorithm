#include "avl.h"

Nodo* search_binary(Nodo *root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->value)
        return search_binary(root->left, value);

    else if (value > root->value)
        return search_binary(root->right, value);

    return root;
}

Nodo* _create_nodo(Nodo *father, int value) {
    Nodo *n;

    if ((n = (Nodo *) malloc(sizeof(Nodo))) == NULL)
        return NULL;

    n->value = value;
    n->level = (father != NULL) ? (father->level + 1) : 0;
    n->father = father;
    n->left = NULL;
    n->right = NULL;

    return n; 
}

Nodo* create_tree(int value) { return _create_nodo(NULL, value); }

// Destruir NODO
void destroy_tree(Nodo *n) {
    if (n == NULL) return;
    destroy_tree(n->left);
    destroy_tree(n->right);
    free(n);
}

// Imprimir ARVORE (ordenado)
void _print_tree(Nodo *n) {
    if (n == NULL) return;

    _print_tree(n->left);
    printf("%4d,%4u\n", n->value, n->level);
    _print_tree(n->right);
}

void print_tree(Nodo *n) {
    printf("\x1b[1mTree:\n\x1b[0m");
    _print_tree(n);
    printf("\n");
}

int _insert_tree(Nodo *actual, Nodo *father, int value) {
    if (actual == NULL) {
        Nodo *new;

        // ERRO: raiz NULA
        if (!father) return 1;
        // Erro: nao foi possivel criar nodo
        if ((new = _create_nodo(father, value)) == NULL) return 1;

        // Coloca no PAI os ponteiros
        if (value < father->value)
            father->left = new;
        else
            father->right = new;

        return 0;
    }

    // Insere no local apropriado
    // Insere o mesmo valor na frente (direita)
    if (value < actual->value)
        return _insert_tree(actual->left, actual, value);
    return _insert_tree(actual->right, actual, value); 
}

int insert_tree(Nodo *root, int value) { 
    return _insert_tree(root, NULL, value); 
}

int operate_tree(char c, int value, Nodo *root) {
    switch(c) {
        case 'i':
        case 'r':
            return !insert_tree(root, value);
        default:
            return 0;
    }
}
