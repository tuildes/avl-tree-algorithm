#include "principal.h"

int main (void) {

    // Variaveis
    Nodo *root = NULL;
    bool started = false;
    char choose;
    int value;

    // Faz todas as iteracoes da AVL
    do {
        scanf("%c %d", &choose, &value);
        getchar(); // Limpar buffer de char
    } while (!operate_tree(choose, value, &root, &started));

    view_avl(root);

    // Libera memoria armazenada
    destroy_avl(root);

    return 0;
}
