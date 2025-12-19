#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_PESQUISASUBSTRINGS_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_PESQUISASUBSTRINGS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "r1_1_text_matrix.h"
/**
 * @brief esta funçao serve para contar a quantidade de strings em que aparece determinada substring
 * @param str matriz que contem o corpus do texto
 * @param subStr substring que ira ser procurada nas substrings
 * @return a quantidade de vezes em que a substring apelidade de search aparece
 */
int stringSearch(const MATRIX_STR *str, const char *subStr);

/**
 * @brief seria o client da função teste para a subpesquisa
 */
void test_r1_2();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_PESQUISASUBSTRINGS_H