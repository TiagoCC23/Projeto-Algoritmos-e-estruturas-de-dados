//
// Created by tiago on 03/12/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_6_SIMILARITY_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_6_SIMILARITY_H
#include "r1_1_text_matrix.h"
#include "r1_4_tokenization.h"
#include "r1_5_term_frequency.h"
#include "math.h"

/**
 * @brief esta funçao permite converter as frequencias vindas do requisito 1.5, para um unico array facilitando o cosseno de similaridade
 * @param ids array de ids de tokens, que contem os ids dos tokens
 * @param freqs frequencia dos ids de tokens que aparecem no array vindo do requisito 1.5
 * @param size quantidade de ids de tokens presentes na frase
 * @param alfabetoTokens o tamanho do alfabeto de todos os tokens que sao adicionados a string
 * @return array convertido para a funçao de teste
 */
int* converterFrequencias(int *ids, int *freqs, int size, int alfabetoTokens);

/**
 * @brief esta funçao calcula o cosseno de similaridade, fazendo produto interno/produto das normas
 * @param a frase/array a
 * @param b frase/array b
 * @param size tamanho do array
 * @return resultado da operaçao
 */
float cossenoSimilaridade_TF(int *a, int *b, int size );

/**
 * @brief esta funçao permite calcular o produto interno
 * @param a frase/array a
 * @param b frase/array b
 * @param size tamanho do array
 * @return resultado da operaçao
 */
float produtoInterno_TF(int *a, int *b, int size);

/**
 * @brief esta funçao permite calcular a normal da frase. Ou seja a raiz quadrada da soma dos tokens das frases ao quadrado
 * @param a frase/array
 * @param size tamanho do array
 * @return resultado da operaçao
 */
float normalCossenoSimilaridade_TF(int *a, int size );

/**
 * @brief esta funçao permite calcular o cosseno de similaridade de um array para fins de teste
 */
void testeSimilaridade();

/**
 * @brief esta função permite calcular o produto interno de um array para fins de teste
 */
void testeprodInterno();

/**
 * @brief esta funçao calcula o cosseno de similaridade e diz com base no resultado, se estas sao ou nao sao muito semelhantes
 * @param ids matriz de ints que contem os dados sobre os ids dos tokens
 * @param tf matriz de ints que contem os dados sobre a frequencia dos tokens
 * @param idA a frase A a ser escolhida para comparar
 * @param idB a frase B a ser escolhida para comparar
 * @param alfabetoTokens a quantidade de tokens
 * @return o valor que corresponde ao cosseno de similaridade
 */
float testeCompararFrases(const MATRIX_INT *ids, const MATRIX_INT *tf, const int idA, const int idB, int alfabetoTokens);

/**
 * @brief funçao que permite simplificar o calculo do cosseno de similaridade de uma frase
 */
void testeComFrases();

/**
 * @brief funçao de testes geral
 */
void test_r1_6();
#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_6_SIMILARITY_H