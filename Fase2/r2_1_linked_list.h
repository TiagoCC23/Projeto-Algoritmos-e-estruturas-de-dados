#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H

typedef struct tk_tf_node {
    int *token_ids; // vetor com os IDs
    int *tf_values; // vetor com as frequências
    int length; // tamanho destes vetores
    struct tk_tf_node *next; // apontador para o proximo nó
    struct tk_tf_node *prev; // apontador para o nó anterior
} TK_TF_NODE;

typedef struct {
    TK_TF_NODE *head; // apontador para o primeiro nó
    TK_TF_NODE *tail; // apontador para o ultimo nó
    int count; // numero de frases/nós na lista
} LL_TK_TF; // para armazenar as TF de todo o texto

void test_r2_1();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H