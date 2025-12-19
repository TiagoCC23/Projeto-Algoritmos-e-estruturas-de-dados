#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "r1_1_text_matrix.h"


/**
 * @brief esta funçao serve para substituir todas as ocorrencias de um par por um id, diminuindo o tamanho da string e possibilitando o merge
 * @param text matriz que contem o corpus do texto
 * @param par par de maior frequencia que vai para a funçao e depois substituido
 * @param novoTokenID o token atualizado para depois substituir no par, para diminuir a string
 */
void substituirParNoTexto(MATRIX_STR *text, char *par, char novoTokenID);

/**
 * @brief esta funçao serve para ver qual par e o mais repetido. Caso a frequencia seja igual, retorna o primeiro par
 * @param pares pares que existem nas strings
 * @param totalPares quantidade de pares
 * @return par com maior frequencia
 */
char* contarFreq(char **pares, int totalPares);

/**
 * @brief esta funçao permite criar os tokens finais. Nela temos os caracteres unicos e por fim temos os caracteres unicos mais os pares ate ao numero de tokens desejados
 * @param text matriz que contem o corpus do texto que sera comprimido
 * @param tokens matriz usada para armazenar os tokens
 * @param newTokens a quantidade de tokens desejada
 */
void build_tokens(MATRIX_STR *text,MATRIX_STR *tokens,int newTokens);

/**
 * @brief funçao que ira apanhar os caracteres que sao unicos na frase
 * @param tokens matriz que vai guardar os tokens
 * @param matr a mesma struct onde vai ser passada a matriz
 */
void caracteresUnicos(MATRIX_STR *tokens, MATRIX_STR *matr);

/**
 * @brief esta funçao permite fazer a junçao dos tokens. Assim sendo, ela pega nos pares consecutivos, ve qual e o mais frequente e funde-o.
 * @param tokens matriz que vai guardar os tokens
 * @param matr matriz que contem o corpus do texto que ira diminuir apos os merges substituindo o par pelo novo id do par
 */
void merge(MATRIX_STR *tokens, MATRIX_STR *matr);

/**
 * @brief esta funçao serve para formatar e imprimir o alfabeto de tokens
 * @param tokens matriz de tokens usada para formatar e imprimir o alfabeto
 */
void imprimirAlfabeto(const MATRIX_STR *tokens);

/**
 * @brief funçao client que mostra os tokens todos
 */
void tokensFinais();

/**
 * @brief funçao que mostra os caracteres unicos
 */
void testeColeta();

/**
 * @brief funçao que mostra o par mais frequente apos o primeiro merge
 */
void testeFrequencias();

/**
 * @brief client de teste das funçoes todas deste requisito
 */
void test_r1_3();




#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_3_CÁLCULO_DO_ALFABETO_DE_TOKENS_DO_CORPUS_TEXTUAL_H
