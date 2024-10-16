#include "avl.h"

int main(void) { 
    
    // Variaveis
    Node *avl;
    char modeInput;
    int valueInput;
    bool created = FALSE;

    while(scanf("%c %d", &modeInput, &valueInput) != EOF) {
        getchar(); // Limpar buffer
        if (modeInput == 'i') {
            // Se nao tiver sido criada, cria a arvore
            if (!created) {
                avl = create_avl(valueInput);
                if (avl == NULL) return 1; // Erro de criacao de AVL
                created = TRUE;
                continue;
            }

            // Insere na arvore ja criada
            if (insert_avl(valueInput, &avl) == NULL) {
                destroy_avl(avl);
                return 1;
            }

            // printf(" %p (real)\n", avl);
        } else {
            break; // Acaba as iteracoess
        }
    }

    // Finalizacao
    view_avl(avl);
    destroy_avl(avl);
    return 0; 
}