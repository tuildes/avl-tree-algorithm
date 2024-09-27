#include "avl.h"

int main (void) {

    Nodo *root;
    char choose;
    int value;

    root = create_tree(1);

    do {
        scanf("%c %d", &choose, &value);
        getchar(); // Limpar buffer de char
    } while (operate_tree(choose, value, root));

    print_tree(root);

    // Libera memoria armazenada
    destroy_tree(root);

    return 0;
}
