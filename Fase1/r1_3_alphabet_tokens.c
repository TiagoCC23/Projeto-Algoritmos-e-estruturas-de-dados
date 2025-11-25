//
// Created by tiago on 15/11/2025.
//

#include "r1_3_alphabet_tokens.h"

void analisarCaracteres(int lines, int columns, char *matr[lines][columns], int CaracteresAnalisados[256]) {

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            char *string = matr[i][j];
            if (string == NULL) {
                continue;                                           // se receber uma string apontada for vazia, ele avança para a proxima iteraçao
            }
            for (int k = 0; string[k] != '\0'; k++) {
                unsigned char caracter = (unsigned char) string[k];
                CaracteresAnalisados[caracter]=1;                   // quando ele vê um caracter ele marca como visto, sendo a marcaçao um 1
                                                                    //-> CaracteresAnalisados[a]=1
            }
        }
    }
}

char *caracteresUnicos(int lines, int columns, char *matr[lines][columns]) {
    if (matr == NULL) {
        return NULL;
    }
    int CaracteresAnalisados[256] = {0};                           // cria o array com os caracteres que serao analisados
    int contadorUnico = 0;                                         // cria o contador que ve quantos caracteres sao unicos
    int j = 0;
    analisarCaracteres(lines, columns, matr, CaracteresAnalisados);
    for (int i = 0; i < 256; i++) {
        if (CaracteresAnalisados[i] == 1) {
            contadorUnico++;
        }
    }
    char *string = (char *) malloc(sizeof(char) * contadorUnico + 1);
    if (string == NULL) {
        return NULL;
    }

    for (int i = 0; i < 256; i++) {
        if (CaracteresAnalisados[i] == 1) {
            string[j++] = (char)i;
        }
    }
    string[j] = '\0';
    return string;
}

void test_r1_3() {
    char *textMatrix[3][2] = {{"ola", "adeus"}, {"cansei", "escrever"}, {"sugestoes", "doidas"}};
    char *caracterUnicos = caracteresUnicos(3, 2, textMatrix);
    for (int i = 0; i < strlen(caracterUnicos); i++) {
        printf("%c ", caracterUnicos[i]);
    }
    free(caracterUnicos);
}
