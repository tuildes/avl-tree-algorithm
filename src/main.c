#include "avl.h"

int main(void) { 
    
    // Variaveis
    Node *avl = NULL, *temp;
    char modeInput;
    int valueInput;

    while(scanf("%c %d", &modeInput, &valueInput) != EOF) {
        getchar(); // Limpar buffer
        if (modeInput == 'i') {
            // Se nao tiver sido criada, cria a arvore
            if (avl == NULL) {
                avl = create_avl(valueInput);
                if (avl == NULL) return 1; // Erro de criacao de AVL
                continue;
            }

            // Insere na arvore ja criada
            if (insert_avl(valueInput, &avl) == NULL) {
                destroy_avl(avl);
                return 1;
            }

            // printf(" %p (real)\n", avl);
        } else if (modeInput == 'r') {
            temp = delete_avl(valueInput, avl);
            if ((temp == NULL) && (avl->left == NULL) && (avl->right == NULL))
                avl = NULL;
            else if(temp->father == NULL)
                avl = temp;

        } else {
            break; // Acaba as iteracoess
        }
    }

    // Finalizacao
    view_avl(avl);
    destroy_avl(avl);
    return 0; 
}