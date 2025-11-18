//
// Created by rayss on 23/10/2025.
//

#include "r1_1_text_matrix.h"

MATRIX_STR *create_matrix(int size) { // numero de linhas!
    MATRIX_STR *mx = malloc(sizeof(MATRIX_STR));
    mx->strings = malloc(size * sizeof(char*)); // matrix->strings eh o mesmo que (*matrix).strings
    for (int i = 0; i < size; i++) {
        mx->strings[i] = NULL;
    }
    mx->size = size;
    mx->count = 0;
    return mx;
}

void resize_matrix(MATRIX_STR *mx, int new_size) {
    mx->strings = realloc(mx->strings, new_size * sizeof(char*));
    for (int i = mx->size; i < new_size; i++) {
        mx->strings[i] = NULL;
    }
    mx->size = new_size;
}

void add_string(MATRIX_STR *mx, const char *str) {
    if (mx->count >= mx->size)
        resize_matrix(mx, mx->size * 2);

    mx->strings[mx->count] = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(mx->strings[mx->count], str);
    mx->count++;
}

void remove_line(MATRIX_STR *mx, int idx) { // caso seja para remover a linha
    free(mx->strings[idx]);
    mx->strings[idx] = mx->strings[idx+1];
    mx->strings[idx+1] = NULL;
    mx->count--;
}

void remove_strings(MATRIX_STR *mx, int start, int end) {
    for (int i = start; i < end; i++) {
        free(mx->strings[i]);
        mx->count--;
    }
}

void print_matrix(MATRIX_STR *mx) {
    for (int i = 0; i < mx->count; i++) {
        printf("[%d] -> %s\n", i, mx->strings[i]);
    }
}

void free_matrix(MATRIX_STR *mx) {
    for (int i = 0; i < mx->count; i++) {
        free(mx->strings[i]); // liberta as linhas
    }
    free(mx->strings); // liberta a matrix
    free(mx);
}

void test_r1_1() {
    MATRIX_STR *textMatrix = create_matrix(3);

    add_string(textMatrix, "o rato roeu a roupa do rei de roma");
    add_string(textMatrix, "tres pratos de trigo para tres triges");
    add_string(textMatrix, "o pelo do pe do pedro eh petro");

    printf("matrix completa:\n");
    print_matrix(textMatrix);

    printf("apos remover a linha 1:\n");
    remove_line(textMatrix, 1);
    print_matrix(textMatrix);

    MATRIX_STR *tokenMatrix = create_matrix(5);

    add_string(tokenMatrix, "o");
    add_string(tokenMatrix, "a");
    add_string(tokenMatrix, "do");
    add_string(tokenMatrix, "rei");
    add_string(tokenMatrix, "trigo");

    printf("tokens:\n");
    print_matrix(tokenMatrix);

    free_matrix(textMatrix);
    free_matrix(tokenMatrix);
}