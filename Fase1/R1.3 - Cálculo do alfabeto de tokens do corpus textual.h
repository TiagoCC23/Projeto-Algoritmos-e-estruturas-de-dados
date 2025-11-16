//
// Created by tiago on 15/11/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 *
 * @param lines numero de linhas na matriz
 * @param columns numero de colunas na matriz
 * @param matr matriz de apontadores para strings
 * @return
 */

char *caracteresUnicos(int lines, int columns, char *matr[lines][columns]);

void analisarCaracteres(int lines, int columns, char *matr[lines][columns], int CaracteresAnalisados[256]);

void testeColeta();


#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
