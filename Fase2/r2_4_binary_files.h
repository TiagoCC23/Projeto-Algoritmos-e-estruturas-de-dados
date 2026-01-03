//
// Created by tiago on 19/12/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_4_BINARY_FILES_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_4_BINARY_FILES_H
#include "r2_3_text_files.h"

/**
 * @brief esta funçao carrega as strings de texto do ficheiro binário para a struct MATRIX_STR
 * @param fp eh o ponteiro para o ficheiro
 * @return ponteiro para a struct MATRIX_STR
 * @note complexidade O(N)
 */
MATRIX_STR* loadDocBinText(FILE *fp);

/**
 * @brief esta funçao carrega os tokens do ficheiro binário para a struct MATRIX_STR
 * @param fp eh o ponteiro para o ficheiro
 * @return ponteiro para a struct MATRIX_STR
 * @note complexidade O(N)
 */
MATRIX_STR* loadDocBinTokens(FILE *fp);

/**
 * @brief esta funçao carrega os ids dos tokens do ficheiro binário para a struct MATRIX_STR
 * @param fp eh o ponteiro para o ficheiro
 * @return ponteiro para a struct MATRIX_INT
 * @note complexidade O(N)
 */
MATRIX_INT* loadDocBinTokensIDs(FILE *fp);

/**
 * @brief esta funçao carrega os as frequencias dos ids do ficheiro binário para a struct LL_TK_TF
 * @param fp eh o ponteiro para o ficheiro
 * @return ponteiro para a struct LL_TK_TF
 * @note complexidade O(N)
 */
LL_TK_TF* loadDocBinTermFreq(FILE *fp);

/**
 * @brief esta funçao eh a funçao principal para o carregamento vindo dos ficheiros. Esta eh responsavel por analisar e dependendo do que encontrar mandar para as funçoes respetivas
 * @param fileName o nome do ficheiro de binario
 * @param doc a struct que contem tudo sobre o binario
 * @note complexidade O(N)
 */
void loadDocBin(char *fileName, DOC *doc);

/**
 * @brief esta funçao permite guardar o que tiver na struct doc para o ficheiro binario
 * @param fileName nome do ficheiro binario
 * @param doc a struct que contem tudo sobre o binario
 * @note complexidade O(N)
 */
void saveDocBin(char *fileName, DOC *doc);

/**
 * @brief funçao de testes
 */
void test_r2_r4();
#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_4_BINARY_FILES_H