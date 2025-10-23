//
// Created by tiago on 23/10/2025.
//

#include "PesquisaSubstrings.h"

void pesquisa(char* mtr[], char substrg[], int line, int column)
{
    int contador_palavras=0;
    int subStringSize=strlen(substrg);
    if (subStringSize==0) // Caso não haja uma substring
    {
        return;
    }
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            char string = mtr[i][j];
            for (int k = 0; k < strlen(string); k++)
            {
            }
        }
    }
}

void teste()
{
    char* matriz[2][3] = {{"abc", "fte", "aaa"}, {"abc", "fae", "abaa"}}; // Com o ponteiro, o tamanho
    char substr[] = "abc"; // passa a ser dinâmico
    pesquisa(matriz, substr, 2, 3); // Com o *, passa a ser o conteúdo da matriz
}
