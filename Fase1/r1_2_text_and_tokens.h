#ifndef PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_PESQUISASUBSTRINGS_H
#define PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_PESQUISASUBSTRINGS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define R_KMP 256 // macro para que ele inclua todos os caracteres do codigo ASCII

/**
 *
 * @param pattern Eh o padrao que ele vai usar para ver os estados
 * @param length Comprimento do padrao
 * @param dfa Eh o dfa classico usado para construir a tabela
 * @return X que seria o estado do dfa
 */
int tabelaKMP (char* pattern,int length, int dfa[R_KMP][length]);

/**
 *
 * @param text Eh o texto da string que ele vai querer pesquisar
 * @param size Eh o tamanho da string
 * @param MatchSize Eh o tamanho do padrao para quando der match
 * @param dfa Eh o dfa classico que vai usar para procurar
 * @param XReset Eh o estado de reset para quando o padrao eh encontrado
 * @return ContadorPalavras que eh a quantidade de vezes que achou o padrao
 */
int KMPesquisa(char* text, int size, int MatchSize, int dfa[R_KMP][MatchSize], int XReset);

/**
 *
 * @param line eh o numero de linhas da matriz
 * @param column eh o numero de colunas da matriz
 * @param mtr eh a matriz de apontadores para chars que eh passada
 * @param substrg eh a substring que queremos procurar
 * @return
 */
int pesquisa(int line, int column,char* mtr[line][column], char substrg[]);

/**
 * @brief funçao de teste para o requisito R1.2
 */
void test_r1_2();

#endif //PROJETO_ALGORITMOS_E_ESTRUTURAS_DE_DADOS_PESQUISASUBSTRINGS_H