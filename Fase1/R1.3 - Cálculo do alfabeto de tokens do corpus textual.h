//
// Created by tiago on 15/11/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "r1_1_text_matrix.h"




/**
 *
 * @param lines numero de linhas na matriz
 * @param matr matriz de apontadores para strings
 * @param tamTokens tamanho de tokens
 * @return retorna a string final so com os caracteres unicos
 */
void build_tokens(MATRIX_STR *text,MATRIX_STR *tokens,int newTokens);
void caracteresUnicos(MATRIX_STR *tokens, MATRIX_STR matr, int *tamTokens);
char *tokenLongo(char *tokens[],int tamanhoToken);
void testeTokenMaisLongo();
/**
  *
  *
  * funçao que ve todos os caracteres existente e "guarda-os"
  *
  */
void analisarCaracteresUnicos(int lines,  char **matr, int CaracteresAnalisados[256]);

/**
 * funçao teste para a coleta de caracteres
 */
void testeColeta();
void insertString(MATRIX_STR *matr, char *newStr);
void testeFrequencias();
void testeImprimirAlfabetos();
void imprimirAlfabeto(char *tokens[], int tamTokens, int *frequencias);

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
