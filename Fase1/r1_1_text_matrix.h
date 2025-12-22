#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_1_TEXT_MATRIX_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_1_TEXT_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief estrutura para armazenar uma matriz dinamica de strings
 *
 * essa estrutura permite armazenar e manipular um conjunto dinamico de strings
 */
typedef struct {
    char **strings; // matriz dinamico de strings -> o ** eh para apontar para outras strings!!
    int size; // tamanho da matriz
    int count; // conta o numero de strings armazenadas (atual)
} MATRIX_STR;

/**
 * @brief estrutura para armazenar uma matriz de tokens
 *
 * estrutura semelhante ao MATRIX_STR, utilizada especificamente para armazenar tokens
 */
typedef MATRIX_STR MATRIX_TOKENS; // uma estrutura semelhante ao MATRIX_STR

/**
 * @brief cria uma nova matriz de strings
 *
 * aloca memoria para uma nova matriz de strings com um tamanho inicial especificado
 *
 * @param size tamanho inicial da matriz
 * @return ponteiro para a matriz criada
 *
 */
MATRIX_STR *create_matrix(int size); // cria a matriz

/**
 * @brief redimensiona uma matriz de strings
 *
 * ajusta o tamanho da matriz para o novo tamanho especificado
 * caso
 *
 * o novo tamanho for menor que o count atual, as strings que estao a mais sao perdidas
 *
 * @param mx ponteiro para a matriz que vai ser redimensionada
 * @param new_size novo tamanho desejado para a matriz
 */
void resize_matrix(MATRIX_STR *mx, int new_size); // reajusta a matriz

/**
 * @brief adiciona uma string a matriz
 *
 * adiciona uma nova string a matriz
 *
 * @param mx ponteiro para a matriz que vai ser adicionada a string
 * @param str string a ser adicionada
 */
void add_string(MATRIX_STR *mx, const char *str); // adiciona strings

/**
 * @brief imprime todas as strings da matriz
 *
 * exibe no console todas as strings armazenadas na matriz
 *
 * @param mx ponteiro para a matriz a ser impressa
 */
void print_matrix_str(MATRIX_STR *mx); // imprime a lista de strings

/**
 * @brief remove uma linha especifica da matriz
 *
 * remove a string no indice especificado, deslocando as strings subsequentes
 *
 * @param mx ponteiro para a matriz
 * @param idx indice da string a ser removida
 */
void remove_line(MATRIX_STR *mx, int idx); // remove uma linha que o utilizador quiser

/**
 * @brief remove um intervalo especifico de strings da matriz
 *
 * remove todas as strings começando pelo start e terminando no end
 * e por fim, desloca-se as strings restantes
 *
 * @param mx ponteiro para a matriz
 * @param start indice inicial do intervalo (inclusive)
 * @param end indice final do intervalo (inclusive)
 */
void remove_strings(MATRIX_STR *mx, int start, int end); // remove um intervalo de linhas que o utilizador quer

/**
 * @brief liberta a matriz escolhida da memoria
 *
 * liberta todas as strings armazenadas
 *
 * @param mx ponteiro para a matriz a ser libertada
 */
void free_matrix_str(MATRIX_STR *mx); // liberta a matrix toda

/**
 * @brief funçao de teste para o requisito R1.1
 */
void test_r1_1(); // funcao de teste

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_1_TEXT_MATRIX_H