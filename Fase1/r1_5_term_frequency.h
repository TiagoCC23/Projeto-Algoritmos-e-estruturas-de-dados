#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_5_TERM_FREQUENCY_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_5_TERM_FREQUENCY_H

#include <stdio.h>
#include "r1_4_tokenization.h"

/**
 * @brief calcula as frequencias para todas as frases tokenizadas
 *
 * para cada frase tokenizada na matriz eh calculado um vetor com as frequencias de cada token na frase
 * a frequencia representa quantas vezes cada token aparece
 * complexidade: O(n * m) -> n eh o numero de frases e m eh o numero de tokens por frase
 *
 * @param tokenized_text matriz com as tokenizaçoes de todas as frases
 * @return MATRIX_INT* matriz com as frequencias de cada frase
 */
MATRIX_INT *term_frequency(MATRIX_INT *tt);

/**
 * @brief imprime os pares conforme o exemplo dado no R1.5
 * * Exemplo de output: [0]: {6:1, 3:1, 4:1, 5:1}
 * * @param ids matriz com os IDs dos tokens (output do tokenizer!!!)
 * @param tf matriz com as frequencias (output do term_frequency!!!)
 */
void print_tf_matrix(MATRIX_INT *ids, MATRIX_INT *tf);

/**
 * @brief funçao de teste para o requisito R1.5
 */
void test_r1_5();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_5_TERM_FREQUENCY_H