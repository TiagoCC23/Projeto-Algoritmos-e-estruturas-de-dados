#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tk_tf_node {
    int *tokens; // vetor com os IDs
    int *term_frequency; // vetor com as frequências
    int length; // tamanho destes vetores
    struct tk_tf_node *next; // apontador para o proximo nó
    struct tk_tf_node *prev; // apontador para o nó anterior
} TK_TF_NODE;

typedef struct {
    TK_TF_NODE *head; // apontador para o primeiro nó
    TK_TF_NODE *tail; // apontador para o ultimo nó
    int count; // numero de frases/nós na lista
} LL_TK_TF; // para armazenar as TF de todo o texto

/**
 * @brief cria e inicializa uma nova lista ligada vazia
 * @return ponteiro para a lista criada
 */
LL_TK_TF *create_linked_list();

TK_TF_NODE *create_node(int *tk, int *tf, int len);

void insert_node(LL_TK_TF *list, int *tk, int *tf, int len, int id);

void delete_node(LL_TK_TF *list, int id);

TK_TF_NODE *peep_node(LL_TK_TF *list, int pos);

LL_TK_TF *search_node(LL_TK_TF *list, int *search_ids, int search_len);

/**
 * @brief imprime todos os nós da lista ligada na consola
 * * @param ponteiro para a lista a imprimir
 */
void print_linked_list(LL_TK_TF *list);

/**
 * @brief Liberta toda a memória associada à lista (nós e vetores internos)
 * * @param ponteiro para a lista a destruir
 */
void free_linked_list(LL_TK_TF *list);

void test_r2_1();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H