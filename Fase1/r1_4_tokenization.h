#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_4_TOKENIZATION_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_4_TOKENIZATION_H

#include "r1_1_text_matrix.h"

/**
 * @brief estrutura para armazenar uma matriz dinamica de arrays de inteiros
 *
 * essa estrutura permite armazenar e manipular arrays de inteiros
 * e cada linha pode ter um tamanho diferente (matriz irregular)
 */
typedef struct {
    int **strings;
    int *lengths; // tamanho de cada linha (pq pode variar)
    int size; // tamanho da matrix
    int count;
} MATRIX_INT; // estrutura semelhante ao MATRIX_STR só que para os interios (index)

/**
 * @brief cria uma nova matriz de inteiros
 *
 * cria uma nova matriz de arrays de inteiros com o tamanho especificado
 *
 * @param size tamanho da matriz
 * @return ponteiro para a matriz criada
 */
MATRIX_INT *create_matrix_int(int size);

/**
 * @brief adiciona um array de inteiros a matriz
 *
 * adiciona um novo array de inteiros a matriz
 *
 * @param mi ponteiro para a matriz de destino
 * @param vec array de inteiros a ser adicionado
 * @param len tamanho do array de inteiros
 */
void add_int_array(MATRIX_INT *mi, int *vec, int len);

/**
 * @brief Imprime todos os arrays de inteiros da matriz
 *
 * imprime todos os arrays de inteiros armazenados na matriz
 * caso apareça -1 imprime "SD" (Simbolo Desconhecido)
 *
 * @param mi ponteiro para a matriz a ser impressa
 */
void print_matrix_int(MATRIX_INT *mi);

/**
 * @brief liberta toda a memoria associada a matriz de inteiros
 *
 * liberta todos os arrays de inteiros armazenados
 *
 * @param mi ponteiro para a matriz a ser libertada
 */
void free_matrix_int(MATRIX_INT *mi);

/**
 * @brief funçao de teste para o requisito R1.4
 */
void test_r1_4(); // funcao de teste

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_4_TOKENIZATION_H