//
// Created by tiago on 15/11/2025.
//

#include "R1.3 - Cálculo do alfabeto de tokens do corpus textual.h"

void insertString(MATRIX_STR *matr, char *newStr)
{
if ((*matr).count>=(*matr).size)
{
    char* *newPtr= (char*) realloc((*matr).strings,1+sizeof(MATRIX_STR));
}
    for (int i=0; i<((*matr).count); i++)
    {
        if (strcmp((*matr).strings[i], newStr)==0)
        {
            break;
        }
            strcpy((*matr).strings[i], newStr);

    }
    (*matr).count++;
}
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
void build_tokens(MATRIX_STR *text,MATRIX_STR *tokens,int newTokens);
void caracteresUnicos(MATRIX_STR *tokens, MATRIX_STR matr, int *tamTokens) {
    if (matr.strings == NULL) {
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
            CaracteresAnalisados[j]=1;
            char *newStr= (char*)malloc(2*sizeof(char));
            newStr[0]=string[j];
            newStr[1]='\0';
            insertString(tokens,newStr, 0);

        }
    }
    *tamTokens=matr.count;
}
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
void imprimirAlfabeto(char *tokens[], int tamTokens, int *frequencias)
{
    if (frequencias==0){
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
    } else
    {
        printf("___________________________________\n");
        printf("|  ID   |  Token  |  Frequencias  |\n");
        printf("|-------|---------|---------------|\n");
        for (int i = 0; i<tamTokens; i++) {
            char *token = tokens[i];
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
    char *textMatrix[] = {"bar par"};
    int lines=1;
    int tamTokens=0;
    char **caracterUnicos = caracteresUnicos(lines, textMatrix, &tamTokens);
    imprimirAlfabeto(caracterUnicos, tamTokens, 0);
    for (int i = 0; i < tamTokens; i++) {
        free(caracterUnicos[i]);
    }
    free(caracterUnicos);
}
void testeFrequencias() {
    char *textMatriz[]={"bar"," ", "par"};
    int lines=3;

    char **pares=NULL;
    int *outFreq=NULL;
    int total=0;

    contarFrequencia(textMatriz,&pares, &outFreq, &total, lines);
    imprimirAlfabeto(pares, total, outFreq);
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
    imprimirAlfabeto(tokens, tamTokens,0);
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