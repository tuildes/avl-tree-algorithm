#include "avl.h"

// Funcoes indiretas da TAD AVL
Nodo* __create_nodo(Nodo *father, int value);
int __insert_avl(Nodo *n, Nodo *father, int value);

Nodo* create_avl(int value) { return __create_nodo(NULL, value); }

Nodo* __create_nodo(Nodo *father, int value) {
    Nodo *n;

    if ((n = (Nodo*)malloc(sizeof(Nodo))) == NULL)
        return NULL;

    n->value = value;
    
    n->father = father;
    n->left = NULL;
    n->right = NULL;

    return n; 
}

int __get_balanced(Nodo *n) {
    if (n == NULL) return 0;

    return size_avl(n->left) - size_avl(n->right);
}

void __balance_avl(Nodo *n) {
    
    int b = __get_balanced(n);

    printf("Supostamente balancea (%d)\n", b);
}

int __insert_avl(Nodo *n, Nodo *father, int value) {

    if (n == NULL) {
        
        Nodo *new = __create_nodo(father, value);

        if (new == NULL) return 1; // ERRO DE ALOCACAO

        if (value < father->value) father->left = new;
        else father->right = new;

        __balance_avl(new->father);

        return 0; // SUCESSO
    }

    // BUSCA DE POSICAO
    // INSERE IGUAIS A DIREITA
    if (value < n->value) 
        return __insert_avl(n->left, n, value);
    return __insert_avl(n->right, n, value);
}

int insert_avl(Nodo *n, int value) {
    return __insert_avl(n, n->father, value);
}

Nodo* rotate_avl_right(Nodo *n) {
    Nodo *temp = n->left;
    n->left = temp->right;
    if(temp->right != NULL) temp->right->father = n;
    temp->father = n->father;
    n->father = temp;
    temp->right = n;

    return temp;
}

Nodo* rotate_avl_left(Nodo *n) {
    Nodo *temp = n->right;
    n->right = temp->left;
    if(temp->left != NULL) temp->left->father = n;
    temp->father = n->father;
    n->father = temp;
    temp->left = n;

    return temp;
}

void __view_avl(Nodo *n, unsigned int level) {
    if(n == NULL) return;

    __view_avl(n->left, (level + 1));
    printf("%d,%u\n", n->value, level);
    __view_avl(n->right, (level + 1));
}

void view_avl(Nodo *n) {
    if(n == NULL) return;
    return __view_avl(n, 0);
}

Nodo* search_avl(Nodo *root, int value);

int size_avl(Nodo *root) {
    int hl, hr;

    if (root == NULL) return -1;

    hl = size_avl(root->left);
    hr = size_avl(root->right);

    if (hl > hr) return (hl + 1);
    return (hr + 1);
}

void delete_avl();

void destroy_avl(Nodo *n) {
    if (n == NULL) return;
    destroy_avl(n->left);
    destroy_avl(n->right);
    free(n);
}

/*
Nodo* search_avl(Nodo *root, int value) {
    if (root == NULL) return NULL;

    if (value < root->value)
        return search_binary(root->left, value);

    else if (value > root->value)
        return search_binary(root->right, value);

    return root;
} */
