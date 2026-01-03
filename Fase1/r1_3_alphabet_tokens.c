#include "r1_3_alphabet_tokens.h"

/* ---------- funções necessárias  ---------- */

void substituirParNoTexto(MATRIX_STR *text, char *par, char novoIdToken) {

    for (int i = 0; i < text->count; i++) {
        char *subStr = text->strings[i];
        int tam = strlen(subStr);
        char *newSubStr = malloc(tam * 2 + 1); // aloca memoria para uma substring para substituir o par

        int p = 0, j = 0;

        while (j < tam) {
            if (j < tam - 1 && subStr[j] == par[0] && subStr[j + 1] == par[1]) {
                newSubStr[p++] = novoIdToken;  // se encontrou o par, ele insere o novo id do token
                j += 2;                        // avança duas posiçoes por causa do par

            } else {
                newSubStr[p++] = subStr[j++]; // caso nao encontre o par ele avança ate encontrar (se encontrar)
            }
        }
        newSubStr[p] = '\0';
        free(text->strings[i]);
        text->strings[i] = newSubStr;

    }
}


char* contarFreq(char **pares, int totalPares) {
    if (pares == NULL || totalPares <= 0) {
        return NULL;
    }
    int maior = 0;
    int endereco = 0;

    for (int i = 0; i < totalPares; i++) {
        int contador = 0;
        for (int j = 0; j < totalPares; j++) {
            if (strcmp(pares[i], pares[j]) == 0) {
                contador++;
            }
        }

        if (contador > maior) {
            maior = contador;
            endereco = i;

        }
    }

    if (maior == 0){
        return NULL;
}
    return pares[endereco];
}

                /* ---------- build_tokens ---------- */

void build_tokens(MATRIX_STR *text, MATRIX_STR *tokens, int newTokens) {

    caracteresUnicos(tokens, text);

    printf("\n-----------Original------------\n");
    imprimirAlfabeto(tokens);

    while (tokens->count < newTokens) {
        merge(tokens, text);
    }
    printf("\n-----------Final---------------\n");
    imprimirAlfabeto(tokens);
    printf("\n-------------------------------\n");

}

                /* ---------- funções do projeto ---------- */

void caracteresUnicos(MATRIX_STR *tokens, MATRIX_STR *matr) {
    if (matr->strings == NULL) {
        printf("Erro\n");
        return;
    }

    int CaracteresAnalisados[256] = {0};

    for (int i = 0; i < matr->count; i++) {
        char *string = matr->strings[i];
        for (int j = 0; j < strlen(string); j++) {
            unsigned char c = (unsigned char)string[j];
            if (CaracteresAnalisados[c] == 0) {
                CaracteresAnalisados[c] = 1;
                char *newStr = (char *)malloc(2);
                if (newStr == NULL) return;

                newStr[0] = string[j];
                newStr[1] = '\0';

                add_string(tokens, newStr);
                free(newStr);
            }
        }
    }
}

void merge(MATRIX_STR *tokens, MATRIX_STR *matr) {

    int pos = 0;
    char auxSubStr[3];
    char **freqString = NULL;


    for (int i = 0; i < matr->count; i++) {                                               // criar os pares consecutivos
        char *string = matr->strings[i];
        int tam = (int)strlen(string);
        for (int j = 0; j < tam - 1; j++) {

            auxSubStr[0] = string[j];          // substring atual
            auxSubStr[1] = string[j + 1];      // substring seguinte
            auxSubStr[2] = '\0';               // fim da substring dando um par

            char **temp = (char **)realloc(freqString, (pos + 1) * sizeof(char *));

            freqString = temp;

            freqString[pos] = (char *)malloc(3);
            strcpy(freqString[pos], auxSubStr);
            pos++;
        }
    }
    //---------- Encontrar o mais frequente ----------//
    char *maiorFreq = contarFreq(freqString, pos); // vemos qual eh o par com maior frequecia

    if (maiorFreq == NULL) {
        for (int k = 0; k < pos; k++) free(freqString[k]);
        free(freqString);
        return;
    }

    //---------- Controi o novo token ----------//
    char *parte1=NULL, *parte2=NULL;                                 // partes para dividir a letra caso seja necessario
    unsigned char idToken1 = maiorFreq[0];                  // ambos sao unsigned porque os ids dos tokens sao positivos
    unsigned char idToken2 = maiorFreq[1];

    if (idToken1 < tokens->count) {                                          // verifica se o ID representa um token já existente no dicionário
        parte1=strdup(tokens->strings[idToken1]);                                  // se for letra ele copia diretamente
    } else {
        parte1=malloc(2);                                                     // caso contrario ele trata como um ASCII normal
        parte1[0] = (char)idToken1;
        parte1[1] = '\0';
    }

    if (idToken2 < tokens->count) {
        parte2=strdup(tokens->strings[idToken2]);
    } else {
        parte2=malloc(2);
        parte2[0] = idToken2;
        parte2[1] = '\0';
    }

    char *tokenFinal = malloc(strlen(parte1) + strlen(parte2) + 1);          // junta num unico caracter
    strcpy(tokenFinal, parte1);
    strcat(tokenFinal, parte2);
    free(parte1);
    free(parte2);

    char novoIDToken = (char)tokens->count;                                       // atualizar o id para o proximo token

    for (int i = 0; i < pos; i++) {
        free(freqString[i]);
    }
    free(freqString);

    substituirParNoTexto(matr, maiorFreq, novoIDToken);                            // atualiza-se a string com o novo id
    add_string(tokens, tokenFinal);

    free(tokenFinal);
}

void imprimirAlfabeto(const MATRIX_STR *tokens) {
        printf("_____________________________\n");
        printf("|  ID   |  Token            |\n");
        printf("|-------|-------------------|\n");
        for (int i = 0; i < tokens->count; i++) {
            char *token = tokens->strings[i];

            if (*token == ' ') {
                printf("|  %-3d  |  ' '%-12s  |\n", i, token);
            } else {
                printf("|  %-3d  |  %-15s  |\n", i, token);
            }
        }
        printf("|_______|___________________|\n");
}

                 /*----------/ funçoes de teste /----------*/

void tokensFinais() {
    MATRIX_STR *string = create_matrix(10);
    add_string(string, "bar par");
    MATRIX_STR *tokens = create_matrix(10);
    build_tokens(string, tokens, 10);
}

void testeColeta() {
    MATRIX_STR *string = create_matrix(10);
    add_string(string, "bar par");

    MATRIX_STR *tokens = create_matrix(10);
    caracteresUnicos(tokens, string);
    imprimirAlfabeto(tokens);
}

void testeFrequencias() {
    MATRIX_STR *string = create_matrix(10);
    add_string(string, "bar par");

    MATRIX_STR *tokens = create_matrix(10);

    merge(tokens, string);
    imprimirAlfabeto(tokens);
}
void test_r1_3() {
     tokensFinais();
    // testeColeta();
    // testeFrequencias();
}