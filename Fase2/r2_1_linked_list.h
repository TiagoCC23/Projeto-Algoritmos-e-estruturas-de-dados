#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Nó da lista ligada contendo vetores de tokens e frequências TF
 *
 * Cada nó armazena os vetores de IDs de tokens e suas respectivas frequências TF
 * para uma frase do texto. Inclui também apontadores para navegação bidirecional.
 */
typedef struct tk_tf_node {
    int *tokens; // vetor com os IDs
    int *term_frequency; // vetor com as frequências
    int length; // tamanho destes vetores
    struct tk_tf_node *next; // apontador para o proximo nó
    struct tk_tf_node *prev; // apontador para o nó anterior
} TK_TF_NODE;

/**
 * @brief Lista ligada bidirecional para armazenar vetores TF de todo o texto
 *
 * Estrutura principal que organiza todos os vetores TF do documento,
 * permitindo navegação eficiente em ambas as direções.
 */
typedef struct {
    TK_TF_NODE *head; // apontador para o primeiro nó
    TK_TF_NODE *tail; // apontador para o ultimo nó
    int count; // numero de frases/nós na lista
} LL_TK_TF; // para armazenar as TF de todo o texto

/**
 * @brief cria e inicializa uma nova lista ligada vazia
 * Complexidade: O(1)
 * @return ponteiro para a lista criada
 */
LL_TK_TF *create_linked_list();

/**
 * @brief Cria um novo nó com vetores de tokens e frequências TF
 *
 * Aloca memória para um novo nó e copia os vetores fornecidos.
 * Complexidade: O(n) onde n é o comprimento dos vetores
 *
 * @param tk Vetor de IDs de tokens a copiar
 * @param tf Vetor de frequências TF a copiar
 * @param len Comprimento dos vetores tk e tf
 * @return Ponteiro para o nó criado, ou NULL em caso de erro
 */
TK_TF_NODE *create_node(int *tk, int *tf, int len);

/**
 * @brief Insere um novo nó na lista em uma posição específica
 *
 * Cria um novo nó com os vetores fornecidos e insere na posição
 * especificada pelo índice. Índices negativos inserem no início,
 * índices maiores que count inserem no final.
 * Complexidade: O(n) no pior caso (posição no meio da lista)
 *
 * @param list Ponteiro para a lista ligada
 * @param tk Vetor de IDs de tokens
 * @param tf Vetor de frequências TF
 * @param len Comprimento dos vetores
 * @param id Índice de inserção (0-based)
 */
void insert_node(LL_TK_TF *list, int *tk, int *tf, int len, int id);

/**
 * @brief Remove um nó da lista em uma posição específica
 *
 * Remove o nó na posição especificada pelo índice, libertando
 * toda a memória associada ao nó e seus vetores internos.
 * Complexidade: O(n) no pior caso (posição no meio da lista)
 *
 * @param list Ponteiro para a lista ligada
 * @param id Índice do nó a remover (0-based)
 */
void delete_node(LL_TK_TF *list, int id);

/**
 * @brief Acessa um nó da lista em uma posição específica
 *
 * Retorna o ponteiro para o nó na posição especificada sem removê-lo.
 * Complexidade: O(n) no pior caso (posição no meio da lista)
 *
 * @param list Ponteiro para a lista ligada
 * @param pos Índice do nó a acessar (0-based)
 * @return Ponteiro para o nó solicitado, ou NULL se índice inválido
 */
TK_TF_NODE *peep_node(LL_TK_TF *list, int pos);

/**
 * @brief Procura nós que contenham determinados IDs de tokens
 *
 * Retorna uma nova lista ligada contendo apenas os nós cujos
 * vetores de tokens contenham todos os IDs fornecidos.
 * Complexidade: O(n * m * k) onde n é número de nós, m é comprimento dos vetores, k é IDs de busca
 *
 * @param list Ponteiro para a lista original
 * @param search_ids Vetor de IDs de tokens a buscar
 * @param search_len Comprimento do vetor de busca
 * @return Nova lista ligada com os nós que correspondem à busca, ou lista vazia se nenhum
 */
LL_TK_TF *search_node(LL_TK_TF *list, int *search_ids, int search_len);

/**
 * @brief imprime todos os nós da lista ligada na consola
 * complexidade: O(n) -> n eh o número de nós
 * * @param ponteiro para a lista a imprimir
 */
void print_linked_list(LL_TK_TF *list);

/**
 * @brief Liberta toda a memória associada à lista (nós e vetores internos)
 * complexidade: O(n) -> n eh o número de nós
 * * @param ponteiro para a lista a libertar
 */
void free_linked_list(LL_TK_TF *list);

/**
 * @brief funcao de teste para o requisito R2.1
 */
void test_r2_1();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_R2_1_LINKED_LIST_H