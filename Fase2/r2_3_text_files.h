#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H
#include "../Fase1/r1_3_alphabet_tokens.h"
#include "../Fase1/r1_4_tokenization.h"
#include "../Fase1/r1_5_term_frequency.h"

#include "r2_2_dynamic_matrix.h"

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro de texto para a struct text
 * @param fp eh o ponteiro para o ficheiro
 * @param text a struct que contem o corpus do texto
 * @param first_line a linha que mostra a quantidade de linhas na struct
 * @note complexidade O(N)
 */
void loadDocText(FILE *fp, MATRIX_STR *text, const char *first_line);

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro de texto para a struct tokens
 * @param fp eh o ponteiro para o ficheiro
 * @param tokens a struct que contem os tokens
 * @param first_line a linha que mostra a quantidade de linhas na struct
 * @note complexidade O(N)
 */
void loadDocTokens(FILE *fp, MATRIX_STR *tokens, const char *first_line);

/**
 * @brief esta funçao permite carregar o que tiver no ficheiro de texto para a struct tokensID
 * @param fp eh o ponteiro para o ficheiro
 * @param tokensID a struct que contem os ids dos tokens
 * @param first_line a linha que mostra a quantidade de linhas na struct
 * @note complexidade O(N)
 */
void loadDocTokensIDs(FILE *fp, MATRIX_INT *tokensID, const char *first_line);

/**
 * @brief esta funçao permite carregar as frequencias dos ids que tiverem no ficherido de texto para a struct term_frequency
 * @param fp eh o ponteiro para o ficheiro
 * @param term_frequency a struct que contem as frequencias dos ids
 * @param first_line a linha que mostra a quantidade de linhas na struct
 * @note complexidade O(N)
 */
void loadDocTokensFrequency(FILE *fp, LL_TK_TF *term_frequency, const char *first_line);

/**
 * @brief esta funçao permite converter os um inteio char em inteiro int
 * @param fp file pointer do ficheiro em que queremos fazer essa conversao
 * @param des apontador para o array de destino que vai levar com os ints convertidos
 * @param size tamanho do array do destino
 * @note complexidade O(N)
 */
void parseIntArray(FILE *fp, int *des, int size);

/**
 * @brief esta funçao eh a funçao principal para o carregamento vindo dos ficheiros. Esta eh responsavel por analisar e dependendo do que encontrar mandar paras as funçoes respetivas
 * @param fileName o nome do ficheiro de texto
 * @param doc a struct que contem tudo sobre o texto
 * @note complexidade O(N)
 */
void loadDoc(char *fileName, DOC *doc);

/**
 * @brief esta funçao permite guardar o que tiver na struct doc para o ficheiro de texto
 * @param fileName nome do ficheiro de texto
 * @param doc a struct que contem tudo sobre o texto
 * @note complexidade O(N)
 */
void saveDoc(char *fileName, DOC *doc);

/**
 * @brief funçao de testes
 */
void test_r2_r3();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H