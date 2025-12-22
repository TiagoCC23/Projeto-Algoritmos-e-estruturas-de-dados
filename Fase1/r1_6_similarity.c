//
// Created by tiago on 03/12/2025.
//

#include "r1_6_similarity.h"


float produtoInterno_TF(int *a, int *b, int size) {
    int soma = 0;
    for (int i = 0; i < size; i++) {
        soma += a[i] * b[i];
    }
    return (float) soma;
}

float normalCossenoSimilaridade_TF(int *a, int size) {
    float normal = 0.0f;
    for (int i = 0; i < size; i++) {
        normal += a[i] * a[i];
    }
    normal = sqrtf(normal);
    return normal;
}

float cossenoSimilaridade_TF(int *a, int *b, int size) {
    float produtoInt = produtoInterno_TF(a, b, size);
    float cossenoSim = 0.0f;
    cossenoSim = produtoInt / (normalCossenoSimilaridade_TF(a, size) * normalCossenoSimilaridade_TF(b, size));
    return cossenoSim;
}

void testeprodInterno() {
    int arrayAteste[] = {4, 2, 3, 4};
    int arrayBteste[] = {4, 1, 2, 5};
    int size = 4;
    printf("%.f\n", produtoInterno_TF(arrayAteste, arrayBteste, size));
}

void testeSimilaridade() {
    int arrayAteste[] = {4, 2, 3, 4};
    int arrayBteste[] = {4, 1, 2, 5};
    int size = 4;
    printf("%f\n", cossenoSimilaridade_TF(arrayAteste, arrayBteste, size));
}

float testeCompararFrases(const MATRIX_INT *a, const int idA, const int idB) {
    int *tfA = a->strings[idA];
    int *tfB = a->strings[idB];
    int size = a->lengths[idA];
    float resTeste = cossenoSimilaridade_TF(tfA, tfB, size);
    if (resTeste > 0.80) {
        printf("Elevada\n");
        return resTeste;
    }
    if (resTeste > 0.50 && resTeste < 0.80) {
        printf("Media\n");
        return resTeste;
    }
    printf("Baixa\n");
    return resTeste;
}

void test_r1_6() {
    MATRIX_STR *tokens = create_matrix(8);
    add_string(tokens, "the");      // 0
    add_string(tokens, "a");        // 1
    add_string(tokens, " ");        // 2
    add_string(tokens, "cat");      // 3
    add_string(tokens, "dog");      // 4
    add_string(tokens, "sleeps");   // 5
    add_string(tokens, "runs");     // 6
    add_string(tokens, "eats");     // 7
    MATRIX_STR *text = create_matrix(15);
    add_string(text, "the cat sleeps");
    add_string(text, "a cat eats");
    add_string(text, "the dog runs");
    MATRIX_INT *token_id = tokenizer(text, tokens);                   // mudar para tokens_freq ou algo do genero
    printf("%f", testeCompararFrases(token_id, 0, 1));  // mudar para tokens_freq ou algo do genero
    testeprodInterno();
    testeSimilaridade();
}
