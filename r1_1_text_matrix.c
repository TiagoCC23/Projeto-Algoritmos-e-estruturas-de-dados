//
// Created by rayss on 23/10/2025.
//

#include "r1_1_text_matrix.h"

MATRIX_STR *create_matrix(int size) {
    MATRIX_STR *mx = malloc(sizeof(MATRIX_STR));
    mx->strings = malloc(size * sizeof(char)); // matrix->strings eh o mesmo que (*matrix).strings
    for (int i = 0; i < size; i++) {
        mx->strings[i] = NULL;
    }
    mx->size = size;
    mx->count = 0;
    return mx;
}

void resize_matrix(MATRIX_STR *mx, int new_size) {
    mx->strings = realloc(mx->strings, new_size * sizeof(char));
    mx->size = new_size;
    
}

void add_string(MATRIX_STR *mx, const char *str) {

}

void print_matrix(MATRIX_STR *mx) {

}