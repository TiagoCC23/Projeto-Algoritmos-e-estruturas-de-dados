//
// Created by tiago on 23/10/2025.
//
#include "R1.2 - Manipulação do texto e tokens.h"

int tabelaKMP (char* pattern,int length, int dfa[R_KMP][length]) {
    int X, c, j;  // X is restart state

    if (length == 0) {
        return 0; // caso nao haja nada para procurar
    }
    // reset dfa[][] col 0 to zeros
    for (c = 0; c < R_KMP; c++) {
        dfa[c][0] = 0;
    }

    // constroi so o primeiro estado da tabela e inclui todos os caracteres do codigo ASCII
    dfa[(unsigned char) pattern[0]][0] = 1;  // tem de ser um unsigned char, porque podia acontecer um overflow e um caracter positivo ser negativo pelo complemento para 2

    for (X = 0, j = 1; j < length; j++) {
        for (c = 0; c < R_KMP; c++){
            dfa[c][j] = dfa[c][X];     // copia os casos em que nao corresponde
        }

            dfa[(unsigned char) pattern[j]][j] = j+1; // quando acha um caso correspondente, ele avança até ao proximo
            X = dfa[(unsigned char) pattern[j]][X]; // atualiza o estado de x para depois de percorrido a substring, ele devolva o caso
    }
    return X;
}

int KMPesquisa(char* text, int size, int MatchSize, int dfa[R_KMP][MatchSize], int XReset) {
    int contadordeMatch=0;
    int j=0;

    for (int i=0; i<size; i++) {
        j=dfa[(unsigned char)text[i]][j]; // vai atualizar o estado na variavel j

        if (j==MatchSize) {
            contadordeMatch++;
            j=XReset;
        }
    }
    return contadordeMatch;
}

int pesquisa(int line, int column,char* mtr[line][column], char substrg[]) // primeiro vem as linhas e depois as colunas, para o
{
    // compilador saber como e que vai saltar
    int contadorPalavras=0;
    int subStringSize=strlen(substrg);

    if (subStringSize==0) // caso nao haja uma substring.
    {
        return 0;
    }
    int dfa[R_KMP][subStringSize];

    int XReset=tabelaKMP(substrg, subStringSize, dfa);
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            char* string = mtr[i][j];
            int stringSize=strlen(string);
            contadorPalavras=contadorPalavras+KMPesquisa(string, stringSize,subStringSize,dfa,XReset);
        }
    }
    return contadorPalavras;
}

void testeSubPesquisa()
{
    char* matriz[2][3] = {{"cbc", "fte", "aaa"}, {"abc", "fae", "abaa"}}; // com o ponteiro, (*) o tamanho da string passa a ser dinâmico.
    char substr[] = "f";
    printf("%d",pesquisa(2, 3,matriz, substr));              // com o (*), passa a ser o conteúdo da matriz.
}
