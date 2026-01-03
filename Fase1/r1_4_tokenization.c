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
        for (int j = 0; j < mi->lengths[i]; j++) {
            if (mi->strings[i][j] == -1) {
                printf("SD ");
            } else {
                printf("%d ", mi->strings[i][j]);
            }
        }
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

MATRIX_INT *tokenizer(MATRIX_STR *text, MATRIX_STR *tokens) {
    MATRIX_INT *mi = create_matrix_int(text->count); // mi = matrix of ints
    for (int i = 0; i < text->count; i++) {
        int *vec = NULL;
        int vec_count = 0;

        char *str = text->strings[i];
        int str_length = strlen(str);

        int j = 0;
        while (j < str_length) {
            int greater_length = -1;
            int greater_index = -1;

            for (int k = 0; k < tokens->count; k++) {
                int tok_length = strlen(tokens->strings[k]);
                if (tok_length <= greater_length) {
                    continue;
                }

                if (j + tok_length <= str_length && strncmp(&str[j], tokens->strings[k], tok_length) == 0) {
                    greater_length = tok_length;
                    greater_index = k;
                }
            }
            vec = (int*) realloc(vec, (vec_count + 1) * sizeof(int));

            if (greater_index == -1) {
                vec[vec_count++] = -1; // o tal do SD -> simbolo desconhecido
                j++;
            } else {
                vec[vec_count++] = greater_index;
                j += greater_length;
            }
        }
        add_int_array(mi, vec, vec_count);
        free(vec);
    }
    return mi;
}

void test_r1_4() {
    MATRIX_STR *tokens = create_matrix(7);
    add_string(tokens, "b");   // 0
    add_string(tokens, "a");   // 1
    add_string(tokens, "r");   // 2
    add_string(tokens, " ");   // 3
    add_string(tokens, "p");   // 4
    add_string(tokens, "ar");  // 5
    add_string(tokens, "bar"); // 6

    MATRIX_STR *text = create_matrix(4);
    add_string(text, "bar par"); // para dar certo
    add_string(text, "dar car"); // para aparecer o SD

    MATRIX_INT *token_id = tokenizer(text, tokens);

    printf("tokens que vao ser utilizados:\n");
    print_matrix_str(tokens);
    printf("\ntextos exemplos:\n");
    print_matrix_str(text);
    printf("\nIDs dos tokens respectivos:\n");
    print_matrix_int(token_id);

    free_matrix_str(tokens);
    free_matrix_str(text);
    free_matrix_int(token_id);
}