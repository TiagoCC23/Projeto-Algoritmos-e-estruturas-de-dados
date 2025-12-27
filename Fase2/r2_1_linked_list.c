#include "r2_1_linked_list.h"

LL_TK_TF *create_linked_list() {
    LL_TK_TF *list = (LL_TK_TF *) malloc(sizeof(LL_TK_TF));
    if (list != NULL) {
        list->count = 0;
        list->head = list->tail = NULL;
    }
    return list;
}

TK_TF_NODE *create_node(int *tk, int *tf, int len) {
    TK_TF_NODE *node = (TK_TF_NODE *) malloc(sizeof(TK_TF_NODE));
    if (node == NULL) {
        return NULL;
    }

    node->tokens = (int *) malloc(sizeof(int) * len);
    node->term_frequency = (int *) malloc(sizeof(int) * len);
    node->length = len;
    node->next = NULL;
    node->prev = NULL;

    if (node->tokens == NULL || node->term_frequency == NULL) {
        free(node->tokens);
        free(node->term_frequency);
        free(node);
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        node->tokens[i] = tk[i];
        node->term_frequency[i] = tf[i];
    }
    return node;
}

void insert_node(LL_TK_TF *list, int *tk, int *tf, int len, int id) {
    if (list == NULL) {
        return;
    }

    TK_TF_NODE *new_node = create_node(tk, tf, len);
    if (new_node == NULL) {
        return;
    }

    if (list->count == 0) { // 1: lista vazia
        list->head = new_node;
        list->tail = new_node;
    } else if (id <= 0) { // 2: inicio
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    } else if (id >= list->count) { // 3: fim
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    } else { // 4: meio
        TK_TF_NODE *current = list->head;

        for (int i = 0; i < id; i++) {
            current = current->next;
        }

        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
    }

    list->count++;
}

void delete_node(LL_TK_TF *list, int id) {
    if (list == NULL || list->count == 0 || id < 0 || id >= list->count) {
        printf("nao pode fazer delete_node!!!!!\n");
        return;
    }

    TK_TF_NODE *remove = NULL;

    if (list->count == 1) { // 1: remove o unico elemento
        remove = list->head;
        list->head = list->tail = NULL;
    } else if (id <= 0) { // 2: remove do inicio
        remove = list->head;
        list->head = remove->next;
        if (list->head) { // se nao for NULL, ele coloca o prev como NULL
            list->head->prev = NULL;
        }
    } else if (id >= list->count - 1) { // 3: remove do fim
        remove = list->tail;
        list->tail = remove->prev;
        if (list->tail) {
            list->tail->next = NULL;
        }
    } else { // 4: remove no meio
        remove = list->head;
        for (int i = 0; i < id; i++) {
            remove = remove->next;
        }
        remove->prev->next = remove->next;
        remove->next->prev = remove->prev;
    }

    if (remove) {
        free(remove->tokens);
        free(remove->term_frequency);
        free(remove);
        list->count--;
    }
}

TK_TF_NODE *peep_node(LL_TK_TF *list, int idx) { // só um nó!
    if (list == NULL || idx < 0 || idx >= list->count) {
        return NULL;
    }

    TK_TF_NODE *curr;

    if (idx < list->count / 2) { // se for menor que a metade, comeca no incio
        curr = list->head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
    } else { // se nao comeca pelo fim
        curr = list->tail;
        for (int i = list->count - 1; i > idx; i--) {
            curr = curr->prev;
        }
    }

    return curr;
}

LL_TK_TF *search_node(LL_TK_TF *list, int *search_ids, int search_len) { // todos os nós!
    if (list == NULL || search_ids == NULL) {
        return NULL;
    }

    LL_TK_TF *result = create_linked_list();
    TK_TF_NODE *current = list->head;

    while (current != NULL) {
        int found = 1;
        for (int i = 0; i < search_len; i++) {
            int search = 0;
            for (int j = 0; j < current->length; j++) {
                if (current->tokens[j] == search_ids[i]) {
                    search = 1;
                    break;
                }
            }
            if (!search) {
                found = 0;
                break;
            }
        }

        if (found) { // se encontrou, adiciona na lista
            insert_node(result, current->tokens, current->term_frequency, current->length, result->count);
        }

        current = current->next;
    }
    return result;
}

void print_linked_list(LL_TK_TF *list) {
    TK_TF_NODE *current = list->head;
    int idx = 0;
    while (current != NULL) {
        printf("[%d] -> {", idx);
        for (int i = 0; i < current->length; i++) {
            printf("%d:%d", current->tokens[i], current->term_frequency[i]);
            if (i < current->length - 1) {
                printf(", ");
            }
        }
        printf("}\n");
        current = current->next;
        idx++;
    }
}

void free_linked_list(LL_TK_TF *list) {
    if (list == NULL) {
        return;
    }

    TK_TF_NODE *current = list->head;

    while (current != NULL) {
        TK_TF_NODE *next = current->next;

        free(current->tokens);
        free(current->term_frequency);
        free(current);

        current = next;
    }
    free(list);
}

void test_r2_1() {
    LL_TK_TF *list = create_linked_list();

    int tk1[] = {0, 2, 3, 2, 5}, tf1[] = {1, 2, 1, 0, 1};
    int tk2[] = {0, 2, 4, 2, 6}, tf2[] = {1, 2, 1, 0, 1};
    int tk3[] = {1, 2, 3, 2, 7}, tf3[] = {1, 2, 1, 0, 1};

    printf("\nlista (antes):\n");
    print_linked_list(list);

    insert_node(list, tk1, tf1, 5, 0); // insere no inicio
    insert_node(list, tk2, tf2, 5, 1); // insere no fim
    insert_node(list, tk3, tf3, 5, 1); // insere no meio

    printf("\nlista (depois):\n");
    print_linked_list(list);

    printf("\npeep [2]: ");
    TK_TF_NODE *node = peep_node(list, 2);
    if (node) {
        for (int i = 0; i < node->length; i++) {
            printf("%d:%d ", node->tokens[i], node->term_frequency[i]);
        }
        printf("\n");
    }

    int search_ids[] = {2, 3};
    LL_TK_TF *result = search_node(list, search_ids, 2);

    printf("\npesquisa (ids 2 e 3):\n");
    print_linked_list(result);

    printf("\nremove um indice (id 3 -> ERRO):\n");
    delete_node(list, 3);
    printf("\nremove um indice (id 1):\n");
    delete_node(list, 1);
    print_linked_list(list);

    free_linked_list(result);
    free_linked_list(list);
}