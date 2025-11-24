//
// Created by tiago on 15/11/2025.
//

#include "R1.3 - Cálculo do alfabeto de tokens do corpus textual.h"

void analisarCaracteresUnicos(int lines,  char **matr, int CaracteresAnalisados[256]) {

    for (int i = 0; i < lines; i++) {
            char *string = matr[i];
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

char **caracteresUnicos(int lines, char **matr, int *tamTokens) {
    if (matr == NULL) {
        return NULL;
    }
    int CaracteresAnalisados[256] = {0};                           // cria o array com os caracteres que serao analisados
    int contadorUnico = 0;                                         // cria o contador que ve quantos caracteres sao unicos
    int j = 0;
    analisarCaracteresUnicos(lines,  matr, CaracteresAnalisados);
    for (int i = 0; i < 256; i++) {
        if (CaracteresAnalisados[i] == 1) {
            contadorUnico++;
        }
    }
    char **string = (char **) malloc(sizeof(char*) * contadorUnico);
    if (string == NULL) {
        return NULL;
    }

    for (int i = 0; i < 256; i++) {
        if (CaracteresAnalisados[i] == 1) {
            string[j] = (char *) malloc(sizeof(char));
            string[j][0] = (char) i;
            string[j][1] = '\0';
            j++;
        }
    }
    *tamTokens=contadorUnico;
    return string;
}

int encontrarIndicePar(char **listaPars[], char *parProcurado, int totalPares) {
    for (int i = 0; i < totalPares; i++) {
        if (strcmp(listaPars[i], parProcurado) == 0) {             // compara com a lista de pares existentes
            return i;                                              // caso exista, ele devolve a posiçao onde se encontra o par
        }
    }
    return -1;
}
void atualizarPares(char ***listaPars[], char *novoPar,int **frequencias,  int *total ) {
    int indicePar= encontrarIndicePar(*listaPars, novoPar, *total);
    if (indicePar != -1) {
        (*frequencias)[indicePar]++;
    }

}

char *tokenLongo(char *tokens[],int tamanhoToken)//1.4
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
    return tokens[endereco];
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


                /*----------/ funçoes de teste /----------*/
void testeColeta() {
    char *textMatrix[] = {"bar par"};
    int lines=1;
    int tamTokens=0;
    char **caracterUnicos = caracteresUnicos(lines, textMatrix, &tamTokens);
    imprimirAlfabeto(caracterUnicos, tamTokens);
    for (int i = 0; i < tamTokens; i++) {
        free(caracterUnicos[i]);
    }
    free(caracterUnicos);
}
void testeFrequencias() {
    char *textMatriz[3][2]={{"hello", "ola"}, {"conheces", "mario"}, {"aquele", "armarioo"}};

}
void testeImprimirAlfabetos() {
    char *tokens[]={"Ola", "Mundo", "Planeta", " ", "."};
    int tamTokens=strlen(tokens)-1;
    imprimirAlfabeto(tokens, tamTokens);
}

void testeTokenMaisLongo()
{
    char *tokens[]={"Ola", "Mundo", "Planeta", " ", "."};
    int tamTokens=strlen(tokens)-1;
    char *subtoken=tokenLongo(tokens, tamTokens);
    for (int i=0; i<strlen(subtoken); i++)
    {
        printf("%c", subtoken[i]);
    }
}