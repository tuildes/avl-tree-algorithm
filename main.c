#include "avl.h"

int main (/* int argc, char *argv[] */) {

    Nodo *root;

    root = create_nodo(1);
    insert_tree(root, 2, NULL);
    insert_tree(root, 10, NULL);
    insert_tree(root, 200, NULL);
    insert_tree(root, 5, NULL);
    insert_tree(root, -12, NULL);
    insert_tree(root, 1, NULL);
    
    print_tree(search_binary(root, 10));

    destroy_nodo(root);

    return 0;
}
