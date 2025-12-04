//
// Created by tiago on 03/12/2025.
//

#include "r1_6_similarity.h"


/*float produtoInterno_TF(MATRIX_INT *a, MATRIX_INT *b ) {
    int produtoInt=0;
    for (int i = 0; i < a->count; i++) {
            produtoInt += *a->strings[i] * *b->strings[i];
        }

    return (float) produtoInt;
    }*/
float produtoInterno_TF(int *a, int *b, int size) {
    int soma = 0;
    for (int i = 0; i < size; i++) {
        soma += a[i] * b[i];
    }
    return (float)soma;
}

float normalCossenoSimilaridade_TF(int *a, int size ) {
    float normal=0.0f;
    for (int i = 0; i < size; i++) {
    normal+=a[i]*a[i];
    }
    normal = sqrtf(normal);
    return normal;
}

float cossenoSimilaridade_TF(int *a, int *b, int size ) {
    float produtoInt=produtoInterno_TF(a, b, size);
    float cossenoSim=0.0f;
    cossenoSim=produtoInt / (normalCossenoSimilaridade_TF(a, size) * normalCossenoSimilaridade_TF(b, size));
    return cossenoSim;
}


void testeprodInterno() {
    int arrayAteste[]={4,2,3,4};
    int arrayBteste[]={4,1,2,5};
    int size=4;
    printf("%.f\n", produtoInterno_TF(arrayAteste, arrayBteste, size));
}

void testeSimilaridade() {
    int arrayAteste[]={4,2,3,4};
    int arrayBteste[]={4,1,2,5};
    int size=4;
    printf("2%f\n",cossenoSimilaridade_TF(arrayAteste, arrayBteste, size ));
}

void test_r1_6() {
    testeprodInterno();
    testeSimilaridade();
}