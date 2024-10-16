#ifndef PRINCIPAL_H_
#define PRINCIPAL_H_

#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

// Tipo BOOLEANO
typedef enum { false, true } bool;

// Entrada do tipo: I/R value
// I - inserir valor
// R - remover valor
int operate_tree(char c, int value, Nodo **root, bool *started);

#endif // PRINCIPAL_H_
