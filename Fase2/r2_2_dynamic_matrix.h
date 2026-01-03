#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_2_DYNAMIC_MATRIX_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_2_DYNAMIC_MATRIX_H

#include "r1_1_text_matrix.h"
#include "r1_4_tokenization.h"
#include "r2_1_linked_list.h"

/**
 * @brief esta struct contem as outras matrizes do projeto, sendo elas para a struct principal do ficheiro
 */

typedef struct {
    MATRIX_STR *text; // texto original
    MATRIX_STR *tokens; // tokens
    MATRIX_INT *ids; // matriz de IDs (resultado do tokenizer)
    LL_TK_TF *term_frequency; // lista ligada com as frequencias
} DOC;

DOC *create_doc();

void free_doc(DOC *doc);

/**
 * @brief funçao de teste para o requisito R2.2
 */
void test_r2_2();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_2_DYNAMIC_MATRIX_H