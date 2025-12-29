#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H
#include "r2_2_dynamic_matrix.h"

/**
 * @brief esta struct contem as outras matrizes do projeto, sendo elas para a struct principal do ficheiro
 */
typedef struct {
    MATRIX_STR text;            // texto original
    MATRIX_STR tokens;          // tokens
    MATRIX_INT tokensID;        // matriz de ids
} DOC;



/**
 * @brief esta funçao permite carregar o que tiver no ficheiro de texto para a struct text
 * @param fp eh o ponteiro para o ficheiro
 * @param text a struct que contem o corpus do texto
 * @param first_line a linha que mostra a quantidade de linhas na struct
 */
void loadDocText(FILE *fp, MATRIX_STR *text, const char *first_line);

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro de texto para a struct tokens
 * @param fp eh o ponteiro para o ficheiro
 * @param tokens a struct que contem os tokens
 * @param first_line a linha que mostra a quantidade de linhas na struct
 */
void loadDocTokens(FILE *fp, MATRIX_STR *tokens, const char *first_line);

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro de texto para a struct tokensID
 * @param fp eh o ponteiro para o ficheiro
 * @param tokensID a struct que contem os ids dos tokens
 * @param first_line a linha que mostra a quantidade de linhas na struct
 */
void loadDocTokensIDs(FILE *fp, MATRIX_INT *tokensID, const char *first_line);

/**
 * @brief esta funçao eh a funçao principal para o carregamento vindo dos ficheiros. Esta eh responsavel por analisar e dependendo do que encontrar mandar paras as funçoes respetivas
 * @param fileName o nome do ficheiro de texto
 * @param doc a struct que contem tudo sobre o texto
 */
void loadDoc(char *fileName, DOC *doc);

/**
 * @brief esta funçao permite guardar o que tiver na struct doc para o ficheiro de texto
 * @param fileName nome do ficheiro de texto
 * @param doc a struct que contem tudo sobre o texto
 */
void saveDoc(char *fileName, DOC *doc);

/**
 * @brief funçao de testes
 */
void test_r2_r3();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H