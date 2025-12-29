#include "r2_2_dynamic_matrix.h"

DOC *create_doc() {
    DOC *doc = (DOC *) malloc(sizeof(DOC));

    if (doc == NULL) {
        return NULL;
    }

    doc->text = NULL;
    doc->tokens = NULL;
    doc->ids = NULL;
    doc->term_frequency = NULL;

    return doc;
}

void free_doc(DOC *doc) {
    if (doc == NULL) {
        return;
    }

    if (doc->text) {
        free_matrix_str(doc->text);
    }

    if (doc->tokens) {
        free_matrix_str(doc->tokens);
    }

    if (doc->ids) {
        free_matrix_int(doc->ids);
    }

    if (doc->term_frequency) {
        free_linked_list(doc->term_frequency);
    }

    free(doc);
    printf("\nDOC liberado!!!!!!");
}

void test_r2_2() {
    DOC *doc = create_doc();

    doc->text = create_matrix(5);
    add_string(doc->text, "the cat sleeps");
    add_string(doc->text, "the dog runs");

    doc->tokens = create_matrix(10);
    add_string(doc->tokens, "the");
    add_string(doc->tokens, "cat");
    add_string(doc->tokens, "dog");
    add_string(doc->tokens, "sleeps");
    add_string(doc->tokens, "runs");

    doc->ids = create_matrix_int(5);
    int ex1[] = {0, 1, 3};
    int ex2[] = {0, 2, 4};

    doc->term_frequency = create_linked_list();

    int tf[] = {1, 1, 1};
    insert_node(doc->term_frequency, ex1, tf, 3, 0);
    insert_node(doc->term_frequency, ex2, tf, 3, 1);

    printf("\no que foi carregado no DOC:\n");
    printf("texto:\n");
    print_matrix_str(doc->text);
    printf("tokens:\n");
    print_matrix_str(doc->tokens);
    printf("lista ligada:\n");
    print_linked_list(doc->term_frequency);

    free_doc(doc);
}