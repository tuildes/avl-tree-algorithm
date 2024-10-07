#include "principal.h"

int operate_tree(char c, int value, Nodo **root, bool *started) {

    // Inicializa a arvore caso necessario
    if(!(*started)) {
        if (c != 'i') return 2; // ERRO DE ESCOLHA
        *root = create_avl(value);
        *started = true;

        if (root == NULL) return 1;

        return 0;
    }

    switch(c) {
        case 'r': // Remove
            return 1;
        case 'i': // Inserir na arvore
            return insert_avl(*root, value);
        default: // Default: break
            return 2; // ESCOLHA ERRADA
    }
}
