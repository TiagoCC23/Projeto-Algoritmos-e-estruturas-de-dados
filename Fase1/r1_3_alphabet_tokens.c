#include "r1_3_alphabet_tokens.h"

#include <ctype.h>

                /*----------/ funçoes necessarias /----------*/

char* contarFreq(char **pares, int totalPares) {
    int maior=0, endereco=0;
    for (int i = 0; i < totalPares; i++) {
        int contador=0;
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
return pares[endereco];
}

void insertString(MATRIX_STR *matr, char *newStr)
{
    for (int i=0; i<((*matr).count); i++)                  // neste ciclo verifica-se se a string a ser inserida ja existe ou nao
    {
        if (strcmp((*matr).strings[i], newStr)==0)
        {
            printf("Ja existe");
            return;
        }
    }
if ((*matr).count>=(*matr).size)                          // se haver mais strings alocadas do que tamanho da string, realoca-se tamanho
{
    int newSize=(*matr).size*2;                           // para o tamanho da string ficar dinamico
    (*matr).strings= (char**) realloc((*matr).strings,newSize*sizeof(char*));
}
    (*matr).strings[(*matr).count]=(char *) malloc(strlen(newStr)+1);  // aloca-se memoria para a nova string, somando +1 para o \0
    strcpy((*matr).strings[(*matr).count], newStr);

    (*matr).count++;                                                        // atualiza-se a contagem de strings
}
void initMatrStruct(MATRIX_STR *str)
{
    (*str).count=0;
    (*str).size=1;
    (*str).strings=(char**)calloc((*str).count,sizeof(char*));
}

void build_tokens(MATRIX_STR *text,MATRIX_STR *tokens,int newTokens);

                /*----------/ funçoes do projeto /----------*/

void caracteresUnicos(MATRIX_STR *tokens, MATRIX_STR matr, int *tamTokens) {
    if (matr.strings == NULL) {
        printf("Erro");
        return;
    }

    int CaracteresAnalisados[256] = {0};                           // cria o array com os caracteres que serao analisados
for (int i=0; i<matr.count; i++)
{
    char *string=matr.strings[i];
    for (int j=0; j<strlen(string); j++)
    {
        if (CaracteresAnalisados[(unsigned char)string[j]]==0)
        {
            CaracteresAnalisados[(unsigned char)string[j]]=1;
            char *newStr= (char*)malloc(2*sizeof(char*));
            newStr[0]=string[j];
            newStr[1]='\0';
            insertString(tokens,newStr);

        }
    }
}
    *tamTokens=(*tokens).count;
}
void merge(MATRIX_STR *tokens, MATRIX_STR matr, int *tamTokens) {
    if (matr.strings == NULL) {
        printf("Erro");
        return;
    }
    int pos=0;
    char auxSubStr[3]={0,0,0};
    char **freqString = NULL;                                  // começa a NULL se realocar a memoria
    for (int i=0; i<matr.count; i++) {
        char *string=matr.strings[i];
        for (int j=0; j<strlen(string)-1; j++){
            auxSubStr[0]=tolower(string[j]);
            auxSubStr[1]=tolower(string[j+1]);
            auxSubStr[2]='\0';
            char **temp = realloc(freqString, (pos + 1) * sizeof(char*));
            freqString = temp;

            freqString[pos] = (char*)malloc(3 * sizeof(char));
            strcpy(freqString[pos], auxSubStr);
            pos++;

        }
    }
    char *maiorFreq= contarFreq(freqString, pos);
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



void imprimirAlfabeto(MATRIX_STR *tokens, int *frequencias)
{
    if (frequencias==0){
        printf("_____________________________\n");
        printf("|  ID   |  Token            |\n");
        printf("|-------|-------------------|\n");
        for (int i = 0; i<(*tokens).count; i++) {
            char *token = (*tokens).strings[i];
            if (*token==' ')
            {
                printf("|  %-3d  |  ' '%-12s  |\n", i, token);
            } else
            {
                printf("|  %-3d  |  %-15s  |\n", i, token);
            }
        }
        printf("|_______|___________________|\n");
    } else
    {
        printf("___________________________________\n");
        printf("|  ID   |  Token  |  Frequencias  |\n");
        printf("|-------|---------|---------------|\n");
        for (int i = 0; i<(*tokens).count; i++) {
            char *token = (*tokens).strings[i];
            if (*token==' ')
            {
                printf("|  %-3d  |  ' '%-6s  |  %-12d  |\n", i, token, frequencias[i]);
            } else
            {
                printf("|  %-3d  |  %-5s  |  %-11d  |\n", i, token, frequencias[i]);
            }
        }
        printf("|_______|_________|_______________|\n");
    }
}


                /*----------/ funçoes de teste /----------*/

void testeColeta() {
    MATRIX_STR string;
    initMatrStruct(&string);

    insertString(&string, "bar par");

int tamTokens=0;

    MATRIX_STR tokens;
    initMatrStruct(&tokens);
    caracteresUnicos(&tokens, string, &tamTokens);
    imprimirAlfabeto(&tokens, 0);
}
void test_r1_3() {
    char *textMatrix[3][2] = {{"ola", "adeus"}, {"cansei", "escrever"}, {"sugestoes", "doidas"}};
    char *caracterUnicos = caracteresUnicos(3, 2, textMatrix);
    for (int i = 0; i < strlen(caracterUnicos); i++) {
        printf("%c ", caracterUnicos[i]);
    }
    printf("\n");
    free(caracterUnicos);
}
void testeFrequencias() {
MATRIX_STR string;
    initMatrStruct(&string);
    insertString(&string, "bar par");
    int tamTokens=0;
    MATRIX_STR tokens;
    initMatrStruct(&tokens);
    merge(&tokens, string, &tamTokens);
    imprimirAlfabeto(&tokens, 0);

}
void testeImprimirAlfabetos() {
    char *tokens[]={"Ola", "Mundo", "Planeta", " ", "."};
    int tamTokens=strlen(tokens)-1;
    //imprimirAlfabeto(tokens, tamTokens,0);
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