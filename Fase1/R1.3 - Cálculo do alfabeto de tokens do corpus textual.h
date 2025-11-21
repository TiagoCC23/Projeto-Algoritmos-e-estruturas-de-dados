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
 * @return retorna a string final so com os caracteres unicos
 */

char *caracteresUnicos(int lines, int columns, char *matr[lines][columns]);
char tokenLongo(char *tokens[],int tamanhoToken);
void analisarCaracteresPares(int lines, int columns, char *matr[lines][columns], int CaracteresAnalisados[256]);
/**
  *
  *
  * funçao que ve todos os caracteres existente e "guarda-os"
  *
  */
void analisarCaracteresUnicos(int lines, int columns, char *matr[lines][columns], int CaracteresAnalisados[256]);

/**
 * funçao teste para a coleta de caracteres
 */
void testeColeta();

void testeFrequencias();

void testeImprimirAlfabetos();
void imprimirAlfabeto(char *tokens[], int tamTokens);

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
