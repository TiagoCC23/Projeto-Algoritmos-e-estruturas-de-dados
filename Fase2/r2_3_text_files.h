#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H

#include "r2_2_dynamic_matrix.h"

void loadDocText(FILE *fp, MATRIX_STR *text, const char *first_line);
void loadDocTokens(FILE *fp, MATRIX_STR *tokens, const char *first_line);
void loadDocTokensIDs(FILE *fp, MATRIX_INT *tokensID, const char *first_line);
void loadDoc(char *fileName, DOC *doc);
void saveDoc(char *fileName, DOC *doc);

void test_r2_r3();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_3_TEXT_FILES_H