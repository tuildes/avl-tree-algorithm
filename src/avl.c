#include "avl.h"

/* Assinaturas de funções indiretas */
Node* __create_node(int v, Node* father);
void __fix_height(Node* n, size_t h);

/* Implementação de AVL */
Node* __create_node(int v, Node* father) {
    Node *n;

    // Malloc e tratamento de erro
    if ((n = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;

    n->value = v;
    n->father = father;
    n->left = NULL;
    n->right = NULL;
    if (n->father == NULL) n->level = 0;
    else n->level = (father->level + 1);

    return n;
}

void __fix_height(Node* n, size_t h) {
    if(n == NULL) return;
    n->level = h;
    __fix_height(n->left, (h+1));
    __fix_height(n->right, (h+1));
}

int __balance_value(Node* n) {
    if (n == NULL) return 0;
    size_t hl = height_avl(n->left);
    size_t hr = height_avl(n->right);
    return (int)(hl - hr);
}

Node* __adjustment_avl(Node *n) {
    if (n == NULL) return NULL;

    // int bv = __balance_value(n);
    Node* adj = n;

    // if (bv < -1) { // Desbalanceado na direita
    //     // Direita-esquerda
    //     if (__balance_value(n->right) > 1) {
    //         n->right = rotate_tree_avl_right(n->right);
    //         __fix_height(n->right,n->right->value);
    //     }
    //     adj = rotate_tree_avl_left(n); 
    //     __fix_height(n,n->value);
    // } 
    // else if (bv > 1) { // Desbalanceado na esquerda
    //     // Esquerda-direita
    //     if (__balance_value(n->left) < -1)
    //         n->left = rotate_tree_avl_left(n->left);
    //     adj = rotate_tree_avl_right(n);
    // }

    return adj;
}

Node* create_avl(int v) { return __create_node(v, NULL); }

Node* insert_avl(int v, Node **root) {
    
    *root = __adjustment_avl(*root);

    // Achar posicao para inserir
    if ((v < (*root)->value) && ((*root)->left != NULL))
        return insert_avl(v, &(*root)->left); // Menor
    if ((v >= (*root)->value) && ((*root)->right != NULL))
        return insert_avl(v, &(*root)->right); // Maior igual

    // Criar a posicao e inserir na AVL
    Node* n = __create_node(v, *root);
    if (n == NULL) return NULL; // Erro ao criar

    if (v < (*root)->value) {
        (*root)->left = n;
    } else {
        (*root)->right = n;
    }

    // Rotações
    return *root;
}

Node* rotate_tree_avl_left(Node *n) {
    Node *temp = n->right;

    n->right = temp->left;
    temp->father = n->father;
    n->father = temp;
    
    if(temp->left != NULL)
        temp->left->father = n;
    temp->left = n;

    __fix_height(temp, n->level);

    return temp;
}

Node* rotate_tree_avl_right(Node *n) {
    Node *temp = n->left;

    n->left = temp->right;
    temp->father = n->father;
    n->father = temp;
    
    if(temp->right != NULL)
        temp->right->father = n;
    temp->right = n;

    __fix_height(temp, n->level);

    return temp;
}

void view_avl(Node *root) {
    if(root == NULL) return;

    view_avl(root->left);
    printf("%d, %lu, %d\n", root->value, root->level, __balance_value(root));
    view_avl(root->right);
}

Node* search_avl(int v, Node *root) {
    if (root == NULL) return NULL; // Nao encontrado
    if (v < root->value) return search_avl(v, root->left);
    else if (v > root->value) return search_avl(v, root->right);
    return root;
}

size_t height_avl(Node *n) {
    if (n == NULL) return 0;

    size_t hl, hr;
    hl = height_avl(n->left);
    hr = height_avl(n->right);

    if (hl > hr) return hl + 1;
    return hr + 1;
}

void destroy_avl(Node *root) {
    if (root == NULL) return;

    destroy_avl(root->left);
    destroy_avl(root->right);
    free(root);
}