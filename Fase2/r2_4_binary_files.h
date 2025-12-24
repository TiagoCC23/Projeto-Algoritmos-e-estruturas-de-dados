//
// Created by tiago on 19/12/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_4_BINARY_FILES_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_4_BINARY_FILES_H
#include "r2_3_text_files.h"

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro binario para a struct text
 * @param fp eh o ponteiro para o ficheiro
 * @param text a struct que contem o texto
 */
void loadDocBinText(FILE *fp, MATRIX_STR *text);

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro binario para a struct tokens
 * @param fp eh o ponteiro para o ficheiro
 * @param tokens a struct que contem os tokens
 */
void loadDocBinTokens(FILE *fp, MATRIX_STR *tokens);

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro binario para a struct tokensID
 * @param fp eh o ponteiro para o ficheiro
 * @param tokensID a struct que contem os ids dos tokens
 */
void loadDocBinTokensIDs(FILE *fp, MATRIX_INT *tokensID);

/**
 * @brief esta funçao eh a funçao principal para o carregamento vindo dos ficheiros. Esta eh responsavel por analisar e dependendo do que encontrar mandar paras as funçoes respetivas
 * @param fileName o nome do ficheiro de texto
 * @param doc a struct que contem tudo sobre o texto
 */
void loadDocBin(char *fileName, DOC *doc);

/**
 * @brief esta funçao permite guardar o que tiver na struct doc para o ficheiro binario
 * @param fileName nome do ficheiro de texto
 * @param doc a struct que contem tudo sobre o texto
 */
void saveDocBin(char *fileName, DOC *doc);

/**
 * @brief funçao de testes
 */
void test_r2_r4();
#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_4_BINARY_FILES_H