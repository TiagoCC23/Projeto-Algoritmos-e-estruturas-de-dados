#include "r1_5_term_frequency.h"

MATRIX_INT *term_frequency(MATRIX_INT *tt) {
    if (tt == NULL) {
        return NULL;
    }

    MATRIX_INT *tf = malloc(sizeof(MATRIX_INT));
    tf->size = tt->size;
    tf->count = tt->count;

    tf->strings = malloc(sizeof(int *) * tf->count);
    tf->lengths = malloc(sizeof(int) * tf->count);

    if (!tf || !tf->strings || !tf->lengths) {
        return NULL;
    }

    for (int i = 0; i < tf->count; i++) {
        int len = tt->lengths[i];
        tf->lengths[i] = len;
        tf->strings[i] = malloc(sizeof(int) * len);

        for (int j = 0; j < len; j++) {
            int token = tt->strings[i][j];
            int count = 0;

            for (int k = 0; k < len; k++) {
                if (tt->strings[i][k] == token) {
                    count++;
                }
            }

            tf->strings[i][j] = count;
        }
    }
    return tf;
}

void print_tf_matrix(MATRIX_INT *ids, MATRIX_INT *tf) {
    if (ids == NULL || tf == NULL) return;

    for (int i = 0; i < ids->count; i++) {
        printf("[%d]: {", i);

        int len = ids->lengths[i];

        for (int j = 0; j < len; j++) {
            printf("%d:%d", ids->strings[i][j], tf->strings[i][j]);
            if (j < len - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

void test_r1_5() {
    MATRIX_STR *tokens = create_matrix(7);
    add_string(tokens, "b");   // 0
    add_string(tokens, "a");   // 1
    add_string(tokens, "r");   // 2
    add_string(tokens, " ");   // 3
    add_string(tokens, "p");   // 4
    add_string(tokens, "ar");  // 5
    add_string(tokens, "bar"); // 6

    MATRIX_STR *text = create_matrix(1);
    add_string(text, "bar par");

    MATRIX_INT *tokenized = tokenizer(text, tokens);
    MATRIX_INT *tf = term_frequency(tokenized);

    printf("frequencias:\n");
    print_tf_matrix(tokenized, tf);

    free_matrix_str(tokens);
    free_matrix_str(text);
    free_matrix_int(tokenized);
    free_matrix_int(tf);
}