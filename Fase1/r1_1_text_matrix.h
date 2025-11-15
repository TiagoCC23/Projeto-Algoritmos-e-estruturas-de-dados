//
// Created by rayss on 23/10/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_1_TEXT_MATRIX_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_1_TEXT_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **strings;  // matriz dinamico de strings -> o ** eh para apontar para outras strings!!
    int size;        // tamanho
    int count;       // conta o numero de strings armazenadas (atual)
} MATRIX_STR;

MATRIX_STR *create_matrix(int size);                // cria a matriz
void resize_matrix(MATRIX_STR *m, int new_size);    // reajusta a matriz
void add_string(MATRIX_STR *m, const char *str);    // adiciona a
void print_matrix(MATRIX_STR *m);                   // imprime a lista de strings

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_1_TEXT_MATRIX_H