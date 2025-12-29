//
// Created by tiago on 19/12/2025.
//

#include "r2_4_binary_files.h"

MATRIX_STR* loadDocBinText(FILE *fp) {

    int total=0;

    if(fread(&total, sizeof(int), 1, fp)!=1){

        return NULL;
    }
    MATRIX_STR *text=create_matrix(total);
    for (int i=0; i<total; i++)
    {
        int strSize=0;
        fread(&strSize, sizeof(int), 1, fp);

        char *strTextTemp=(char*)malloc(strSize*sizeof(char));

        fread(strTextTemp, sizeof(char), strSize, fp);
        add_string(text, strTextTemp);
        free(strTextTemp);
    }
    return text;
}
MATRIX_STR* loadDocBinTokens(FILE *fp) {

    int total=0;
    if (fread(&total, sizeof(int), 1, fp)!=1)
    {
        return NULL;
    }
    MATRIX_STR *tokens=create_matrix(total);
    for (int i=0; i<total; i++)
    {
        int tokensSize=0;
        fread(&tokensSize, sizeof(int), 1, fp);

        char *strTokensTemp=(char*)malloc(tokensSize*sizeof(char));

        fread(&strTokensTemp, sizeof(char), tokensSize, fp);
        add_string(tokens, strTokensTemp);
        free(strTokensTemp);
    }
    return tokens;
}
MATRIX_INT* loadDocBinTokensIDs(FILE *fp) {

    int total=0;
    if(fread(&total, sizeof(int), 1, fp)!=1)
    {
        return NULL;
    }
    MATRIX_INT *tokensID=create_matrix_int(total);
    for (int i=0; i<total; i++)
    {
        int tokensIDSize=0;
        fread(&tokensIDSize, sizeof(int), 1, fp);
        int *strTokensIDsTemp=(int*)malloc(tokensIDSize*sizeof(int));
        fread(strTokensIDsTemp, sizeof(char), tokensIDSize, fp);
        add_int_array(tokensID, strTokensIDsTemp, tokensIDSize);
        free(strTokensIDsTemp);
    }
    return tokensID;
}
LL_TK_TF* loadDocBinTermFreq(FILE *fp)
{
    int total=0;
    if (fread(&total, sizeof(int), 1, fp)!=1)
    {
        return NULL;
    }
    LL_TK_TF *nodes=create_linked_list(total);
    for (int i=0; i<total; i++)
    {
        int length=0;
        fread(&length, sizeof(int),1, fp);
        int *strFreqTemp=(int*)malloc(length*sizeof(int));
        int *strTokensTemp = (int*)malloc(length * sizeof(char));
        fread(strFreqTemp, sizeof(int),length, fp);
        fread(strTokensTemp, sizeof(int),length, fp);
        insert_node(nodes, strTokensTemp, strFreqTemp, length, i);
        free(strFreqTemp);
        free(strTokensTemp);
    }
    return nodes;
}
void loadDocBin(char *fileName, DOC *doc) {
    FILE *fp=fopen(fileName,"rb");
    if (fp==NULL) {
        printf("File Not Found\n");
        return;
    }
    loadDocBinText(fp);
    loadDocBinTokens(fp);
    loadDocBinTokensIDs(fp);
    loadDocBinTermFreq(fp);

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
    fwrite(&doc->text->count,sizeof(int), 1, fp);                        // grava o numero de Strings
    for (int i = 0; i < doc->text->count; i++) {
        char *strText=doc->text->strings[i];
        int sizeText=strlen(strText)+1;
        fwrite(&sizeText, sizeof(int), 1, fp);
        fwrite(strText,sizeof(char), sizeText, fp);                     // grava o conteudo da String
    }

                //----------TOKENS----------//
    fwrite(&doc->tokens->count, sizeof(int), 1, fp);
    for (int i = 0; i < doc->tokens->count; i++) {
        char *strToken=doc->tokens->strings[i];
        int sizeToken=strlen(strToken)+1;
        fwrite(&sizeToken, sizeof(int), 1, fp);
        fwrite(strToken, sizeof(char), sizeToken, fp);                          // grava o o conteudo do Token
    }

                //----------TOKENSIDS----------//
    fwrite(&doc->ids->count, sizeof(int), 1, fp);
    for (int i = 0; i < doc->ids->count; i++) {
        fwrite(&doc->ids->lengths[i], sizeof(int), 1, fp);          // grava a quantidade de IDs
        for (int j = 0; j < doc->ids->lengths[i]; j++) {
            fwrite(&doc->ids->strings[i][j], sizeof(int), 1, fp);   // grava o ID que pertence a linha
        }
    }

                //----------TOKENSFREQ----------//
    int totalNodes=0;
    if (doc->term_frequency!=NULL)
    {
    totalNodes=doc->term_frequency->count;
    }
    fwrite(&totalNodes, sizeof(int), 1, fp);
    if (doc->term_frequency!=NULL && totalNodes>0)
    {
        TK_TF_NODE *current=doc->term_frequency->head;
        while (current!=NULL)
        {
            fwrite(&current->length, sizeof(int), 1, fp);

                fwrite(&current->term_frequency, sizeof(int), 1, fp);

                fwrite(&current->tokens, sizeof(int), 1, fp);
        }
    }



    fclose(fp);
    printf("File saved with success\n");
}




void test_r2_r4()
{

}
