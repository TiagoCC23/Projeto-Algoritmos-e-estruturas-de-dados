//
// Created by tiago on 19/12/2025.
//

#include "r2_4_binary_files.h"

void saveDocBin(char *fileName, DOC *doc) {
    FILE *fp=fopen(fileName,"wb");
    if (fp==NULL) {
        printf("File Not Found\n");
        return;
    }

    fwrite(&doc->text.count,sizeof(int), 1, fp);                        // printa Strings que sera a tabela
    for (int i = 0; i < doc->text.count; i++) {
       fwrite(doc->text.strings[i],)   // printa os textos que estao na linha da string
    }

    fprintf(fp, "#Tokens\n");
    fprintf(fp, "%d", doc->tokens.count);
    for (int i = 0; i < doc->tokens.count; i++) {
        fprintf(fp, "%s\n", doc->tokens.strings[i]);  // printa os tokens que estao na linha da string
    }

    fprintf(fp, "#IDs\n");
    fprintf(fp, "%d",doc->tokensID.count);
    for (int i = 0; i < doc->tokensID.count; i++) {
        fprintf(fp,"%d ",doc->tokensID.lengths[i]);                 // printa o tamanho da linha dos IDs
        for (int j = 0; j < doc->tokensID.lengths[i]; j++) {
            fprintf(fp,"%d ",doc->tokensID.strings[i][j]);           // printa os tokens pertecentes a linha
        }
        fprintf(fp,"\n");
    }

    //Struct que falta que vem do cook de Ray Santos


    fclose(fp);
    printf("File saved with success\n");
}




void test_r2_r4();
