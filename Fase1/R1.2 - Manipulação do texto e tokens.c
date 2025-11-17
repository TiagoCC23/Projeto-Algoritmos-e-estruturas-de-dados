//
// Created by tiago on 23/10/2025.
//

#include "R1.2 - Manipulação do texto e tokens.h"

int pesquisa(int line, int column,char* mtr[line][column], char substrg[]) // primeiro vem as linhas e depois as colunas, para o
{                                                                          // compilador saber como e que vai saltar
    int contador_palavras=0;
    int subStringSize=strlen(substrg);
    if (subStringSize==0) // caso nao haja uma substring.
    {
        return 0;
    }
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            char* string = mtr[i][j];
            for (int k = 0; k < strlen(string); k++)
            {
                int contadorLetras=0;
                for (int l = 0; l < subStringSize; l++) {
                    if (string[k+l] == substrg[l]) {
                        contadorLetras++;
                    } else {
                        break;
                    }
                }
                if (contadorLetras==subStringSize) {
                    contador_palavras++;
                }
            }

        }
    }
    return contador_palavras;
}

void teste()
{
    char* matriz[2][3] = {{"cbc", "fte", "aaa"}, {"abc", "fae", "abaa"}}; // com o ponteiro, (*) o tamanho passa a ser dinâmico.
    char substr[] = "f";
    printf("%d",pesquisa(2, 3,matriz, substr));              // com o (*), passa a ser o conteúdo da matriz.
}
