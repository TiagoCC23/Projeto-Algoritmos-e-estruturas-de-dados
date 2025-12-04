//
// Created by tiago on 03/12/2025.
//

#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_6_SIMILARITY_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_6_SIMILARITY_H
#include "r1_1_text_matrix.h"
#include "r1_4_tokenization.h"
//#include "r1_5_"
#include "math.h"

float cossenoSimilaridade_TF(int *a, int *b, int size ); // Depois mudo para struct
// float produtoInterno_TF(MATRIX_INT *a, MATRIX_INT *b );     // Depois mudo para struct
float produtoInterno_TF(int *a, int *b, int size);
float normalCossenoSimilaridade_TF(int *a, int size );
void testeSimilaridade();
void testeprodInterno();
void test_r1_6();
#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R1_6_SIMILARITY_H