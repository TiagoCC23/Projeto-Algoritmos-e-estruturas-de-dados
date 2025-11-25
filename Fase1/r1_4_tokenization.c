//
// Created by rayss on 25/11/2025.
//

#include "r1_4_tokenization.h"

MATRIX_INT *create_matrix_int(int size) {
    MATRIX_INT *mi = malloc(sizeof(MATRIX_INT));
    mi->strings = malloc(size * sizeof(int *));
    mi->lengths = malloc(size * sizeof(int));
    mi->size = size;
    mi->count = 0;
    return mi;
}

void add_int_array(MATRIX_INT *mi, int *arr, int len) {
    mi->strings[mi->count] = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        mi->strings[mi->count][i] = arr[i];
    mi->lengths[mi->count] = len;
    mi->count++;
}

void print_matrix_int(MATRIX_INT *mi) {
    for (int i = 0; i < mi->count; i++) {
        printf("[%d] -> ", i);
        for (int j = 0; j < mi->lengths[i]; j++)
            printf("%d ", mi->strings[i][j]);
        printf("\n");
    }
}

void free_matrix_int(MATRIX_INT *mi) {
    for (int i = 0; i < mi->count; i++)
        free(mi->strings[i]);
    free(mi->strings);
    free(mi->lengths);
    free(mi);
}

void test_r1_4() {
    //free_matrix_int();
}