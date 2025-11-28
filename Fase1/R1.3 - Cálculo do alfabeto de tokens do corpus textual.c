//
// Created by tiago on 15/11/2025.
//

#include "R1.3 - Cálculo do alfabeto de tokens do corpus textual.h"

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
    if (indicePar != -1) {                                        // se o par exisitir, ele incrementa o conteúdo do indice desse par
        (*frequencias)[indicePar]++;
    } else
    {
        int novoSize= *total+1;                                   // cria-se um novo tamanho para realocar os pares
        *listaPars= (char***)realloc(*listaPars,novoSize*sizeof(char *));
        *frequencias = (int*)realloc(*frequencias, novoSize*sizeof(int));
        (*frequencias)[*total]=1;                                 // seta-se o contador de frequências em 1
        (*listaPars)[*total]=strdup(novoPar);                     // copia-se a substring, que corresponde ao par, para a listaPars
        (*total)++;
    }
}
void contarFrequencia(char ** string,char ** outPars, int ** outFreq, int * outTotal, int lines)
{
char aux[3];
    for (int i=0; i<lines; i++)
    {
        char *substring= string[i];
        for (int j=0; substring[j+1]!='\0'; j++)
        {
            aux[0]=substring[i];
            aux[1]=substring[i+1];
            aux[2]='\0';
            atualizarPares(outPars,aux, outFreq,outTotal);
        }
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

    insertString(&string, "bar ");
    insertString(&string, " par");

int tamTokens=0;

    MATRIX_STR tokens;
    initMatrStruct(&tokens);
    caracteresUnicos(&tokens, string, &tamTokens);
    imprimirAlfabeto(&tokens, 0);
}
void testeFrequencias() {
    char *textMatriz[]={"bar"," ", "par"};
    int lines=3;

    char **pares=NULL;
    int *outFreq=NULL;
    int total=0;

    contarFrequencia(textMatriz,&pares, &outFreq, &total, lines);
    //imprimirAlfabeto(pares, total, outFreq);
    for(int i=0; i<total; i++)
    {
        free(pares[i]);
    }
    free(pares);
    free(outFreq);
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