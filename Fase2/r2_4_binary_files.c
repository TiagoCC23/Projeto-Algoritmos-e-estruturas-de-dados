//
// Created by tiago on 19/12/2025.
//

#include "r2_4_binary_files.h"

void loadDocBinText(FILE *fp, MATRIX_STR *text) {

    int total=text->count;
    fread(&total, sizeof(int), 1, fp);
    for (int i=0; i<total; i++)
    {
        int strSize=0;
        fread(&strSize, sizeof(int), 1, fp);
        char *strTextTemp=(char*)malloc(strSize*sizeof(char));
        fread(&strTextTemp, sizeof(char), strSize, fp);
        add_string(text, strTextTemp);
        free(strTextTemp);
    }
}
void loadDocBinTokens(FILE *fp, MATRIX_STR *tokens) {

    int total=tokens->count;
    fread(&total, sizeof(int), 1, fp);
    for (int i=0; i<total; i++)
    {
        int tokensSize=0;
        fread(&tokensSize, sizeof(int), 1, fp);
        int *strTokensTemp=(char*)malloc(tokensSize*sizeof(char));
        fread(&strTokensTemp, sizeof(char), tokensSize, fp);
        add_string(tokens, strTokensTemp);
        free(strTokensTemp);
    }
}
void loadDocBinTokensIDs(FILE *fp, MATRIX_INT *tokensID) {

    int total=tokensID->count;
    fread(&total, sizeof(int), 1, fp);
    for (int i=0; i<total; i++)
    {
        int tokensIDSize=0;
        fread(&tokensIDSize, sizeof(int), 1, fp);
        int *strTokensIDsTemp=(int*)malloc(tokensIDSize*sizeof(int));
        fread(strTokensIDsTemp, sizeof(char), tokensIDSize, fp);
        add_int_array(tokensID, strTokensIDsTemp, tokensIDSize);
        free(strTokensIDsTemp);
    }
}
void loadDocBin(char *fileName, DOC *doc) {
    FILE *fp=fopen(fileName,"rb");
    if (fp==NULL) {
        printf("File Not Found\n");
        return;
    }
    loadDocBinText(fp, &doc->text);
    loadDocBinTokens(fp, &doc->tokens);
    loadDocBinTokensIDs(fp, &doc->tokensID);

fclose(fp);
    printf("Document loaded with succes");
}


void saveDocBin(char *fileName, DOC *doc) {
    FILE *fp=fopen(fileName,"wb");
    if (fp==NULL) {
        printf("File Not Found\n");
        return;
    }

                //----------TEXTO----------//
    fwrite(&doc->text.count,sizeof(int), 1, fp);                        // grava o numero de Strings
    for (int i = 0; i < doc->text.count; i++) {
        char *strText=doc->text.strings[i];
        int sizeText=strlen(strText)+1;
        fwrite(&sizeText, sizeof(int), 1, fp);
        fwrite(strText,sizeof(char), sizeText, fp);                     // grava o conteudo da String
    }

                //----------TOKENS----------//
    fwrite(&doc->tokens.count, sizeof(int), 1, fp);
    for (int i = 0; i < doc->tokens.count; i++) {
        char *strToken=doc->tokens.strings[i];
        int sizeToken=strlen(strToken)+1;
        fwrite(&sizeToken, sizeof(int), 1, fp);
        fwrite(strToken, sizeof(char), 1, fp);                          // grava o o conteudo do Token
    }

                //----------TOKENSIDS----------//
    fwrite(&doc->tokensID.count, sizeof(int), 1, fp);
    for (int i = 0; i < doc->tokensID.count; i++) {
        fwrite(&doc->tokensID.lengths[i], sizeof(int), 1, fp);          // grava a quantidade de IDs
        for (int j = 0; j < doc->tokensID.lengths[i]; j++) {
            fwrite(&doc->tokensID.strings[i][j], sizeof(int), 1, fp);   // grava o ID que pertence a linha
        }
    }

    //Struct que falta que vem do cook de Ray Santos


    fclose(fp);
    printf("File saved with success\n");
}




void test_r2_r4()
{

}
