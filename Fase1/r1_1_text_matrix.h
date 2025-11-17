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
    int size;        // tamanho da matriz
    int count;       // conta o numero de strings armazenadas (atual)
} MATRIX_STR;

typedef MATRIX_STR MATRIX_TOKENS;   // uma estrutura semelhante ao MATRIX_STR

MATRIX_STR *create_matrix(int size);                // cria a matriz
void resize_matrix(MATRIX_STR *mx, int new_size);    // reajusta a matriz
void add_string(MATRIX_STR *mx, const char *str);    // adiciona strings
void print_matrix(MATRIX_STR *mx);                   // imprime a lista de strings

void test_r1_1();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_1_TEXT_MATRIX_H