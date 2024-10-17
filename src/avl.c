#include "avl.h"

/* Assinaturas de funções indiretas */
Node* __create_node(int v, Node* father); // Criacao de nodo
int __balance_value(Node* n); // Descobre o valor de balanceamento
Node* __adjustment_avl(Node *n); // Faz o ajuste de AVL

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

    return n;
}

int __balance_value(Node* n) {
    if (n == NULL) return 0;

    size_t hl = height_avl(n->left);
    size_t hr = height_avl(n->right);

    return (int)(hl - hr);
}

Node* __adjustment_avl(Node *n) {
    if (n == NULL) return NULL;

    int bv = __balance_value(n);
    Node* adj = n;

    if (bv < -1) { // Desbalanceado na direita
        // Direita-esquerda
        if (__balance_value(n->right) > 0) {
             n->right = rotate_tree_avl_right(n->right);
        }
        adj = rotate_tree_avl_left(n); 
    } else if (bv > 1) { // Desbalanceado na esquerda
        // Esquerda-direita
        if (__balance_value(n->left) < 0)
            n->left = rotate_tree_avl_left(n->left);
        adj = rotate_tree_avl_right(n);
    }

    return adj;
}

Node* create_avl(int v) { return __create_node(v, NULL); }

Node* insert_avl(int v, Node **root) {

    // Achar posicao para inserir
    if ((v < (*root)->value) && ((*root)->left != NULL))
        insert_avl(v, &(*root)->left); // Menor
    else if ((v >= (*root)->value) && ((*root)->right != NULL))
        insert_avl(v, &(*root)->right); // Maior igual
    else {
        Node* n = __create_node(v, *root);
        if (n == NULL) return NULL; // Erro ao criar

        if (v < (*root)->value) {
            (*root)->left = n;
        } else {
            (*root)->right = n;
        }

        return *root;
    }
    
    *root = __adjustment_avl(*root);
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

    return temp;
}

size_t inverse_height(Node *n) {
    size_t i = 0;
    for(Node *t = n; t != NULL; t = t->father)
        i++;
    return i - 1;
}

void view_avl(Node *root) {
    if(root == NULL) return;

    view_avl(root->left);
    printf("%d,%lu\n", root->value, inverse_height(root));
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

Node* max_avl(Node *n) {
    if (n->right != NULL) return max_avl(n->right);
    return n;
}

Node* delete_avl(int v, Node *root) {
    // Nao encontrado
    if (root == NULL) return NULL;

    // Acessar o lugar certo de delete
    if (v < root->value) {
        root->left = delete_avl(v, root->left);

    } else if (v > root->value) {
        root->right = delete_avl(v, root->right);

    // Deletar
    } else {
        Node *temp;
        if (root->left == NULL) { // Filho direito apenas
            Node *rightChild = root->right;
            free(root);
            return rightChild;
        } else if (root->right == NULL) { // Filho esquerdo apenas
            Node *leftChild = root->left;
            free(root);
            return leftChild;

        } else { // Dois filhos (nos)
            temp = max_avl(root->left); // Find max in left subtree
            root->value = temp->value;
            root->left = delete_avl(temp->value, root->left);
        }
    }

    // Ajuste da árvore AVL
    return __adjustment_avl(root);
}

void destroy_avl(Node *root) {
    if (root == NULL) return;

    destroy_avl(root->left);
    destroy_avl(root->right);
    free(root);
}