//
// Created by tiago on 15/11/2025.
//

#include "R1.3 - Cálculo do alfabeto de tokens do corpus textual.h"

void analisarCaracteresUnicos(int lines, int columns, char *matr[lines][columns], int CaracteresAnalisados[256]) {

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

void analisarCaracteresPares(int lines, int columns, char *matr[lines][columns], int CaracteresAnalisados[256]) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            char *string = matr[i][j];
            if (string == NULL) {
                continue;
            }
            for (int k = 0; string[k+1] != '\0'; k++) {
                unsigned char caracter = (unsigned char) string[k];

            if (string[k] ==string[k+1]) {
                CaracteresAnalisados[caracter]++;
            }
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
    analisarCaracteresUnicos(lines, columns, matr, CaracteresAnalisados);
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

void contarFrequencias(int lines, int columns, char *matr[lines][columns]) {
    int CaracteresAnalisados[256] = {0};

    analisarCaracteresPares(lines, columns, matr, CaracteresAnalisados);

    for (int i = 0; i < 256; i++) {
        if (CaracteresAnalisados[i] > 0) {
            printf("O par '%c%c' apareceu %d vezes.\n", (char)i, (char)i, CaracteresAnalisados[i]);
        }
    }
}
char tokenLongo(char *tokens[],int tamanhoToken)
{
    int endereco=0,  maior=0;
    for (int i=0; i<tamanhoToken; i++)
    {
        int contador=0;
        char *token=tokens[i];
        for (int j=0; j<strlen(token); j++ )
        {
            contador++;
        }
        if (contador>maior)
        {
            endereco=i;
            maior=contador;
        }
    }
    return *tokens[endereco];
}
void imprimirAlfabeto(char *tokens[], int tamTokens) {
    printf("_____________________________\n");
    printf("|  ID   |  Token            |\n");
    printf("|-------|-------------------|\n");
    for (int i = 0; i<tamTokens; i++) {
        char *token = tokens[i];
        if (*token==' ')
        {
            printf("|  %-3d  |  ' '%-12s  |\n", i, token);
        } else
        {
            printf("|  %-3d  |  %-15s  |\n", i, token);
        }
    }
    printf("|_______|___________________|\n");
}
void testeColeta() {
    char *textMatrix[3][2] = {{"ola", "adeus"}, {"cansei", "escrever"}, {"sugestoes", "doidas"}};
    char *caracterUnicos = caracteresUnicos(3, 2, textMatrix);
    for (int i = 0; i < strlen(caracterUnicos); i++) {
        printf("%c ", caracterUnicos[i]);
    }
    free(caracterUnicos);
}
void testeFrequencias() {
    char *textMatriz[3][2]={{"hello", "ola"}, {"conheces", "mario"}, {"aquele", "armarioo"}};
    contarFrequencias(3, 2, textMatriz);
}
void testeImprimirAlfabetos() {
    char *tokens[]={"Ola", "Mundo", "Planeta", " ", "."};
    int tamTokens=strlen(tokens)-1;
    imprimirAlfabeto(tokens, tamTokens);
}

void testeTokenMaisLongo()
{
    char *tokens[]={"Ola", "Mundo", "Planeta", " ", "."};
    char subtoken=tokenLongo(tokens, 5);
    for (int i=0; i<5; i++)
    {
        printf("%c",  subtoken[i]);
    }
}