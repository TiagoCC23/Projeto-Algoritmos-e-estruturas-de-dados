//
// Created by rayss on 25/11/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_4_TOKENIZATION_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_4_TOKENIZATION_H

#include "r1_1_text_matrix.h"

typedef struct {
    int **strings;
    int *lengths; // tamanho de cada linha (pq pode variar)
    int size; // tamanho da matrix
    int count;
} MATRIX_INT; // estrutura semelhante ao MATRIX_STR só que para os interios (index)

MATRIX_INT *create_matrix_int(int size);
void add_int_array(MATRIX_INT *mi, int *vec, int len);
void print_matrix_int(MATRIX_INT *mi);
void free_matrix_int(MATRIX_INT *mi);

void test_r1_4(); // funcao de teste

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_4_TOKENIZATION_H