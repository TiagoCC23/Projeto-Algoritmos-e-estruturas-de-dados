#include "r2_3_text_files.h"

void loadDocText(FILE *fp, MATRIX_STR *text, const char *first_line) {
    int n =  atoi(first_line);
    char buffer[1024];
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1024, fp);
        buffer[strcspn(buffer, "\n")] = 0;
        add_string(text, buffer);
    }
}
void loadDocTokens(FILE *fp, MATRIX_STR *tokens, const char *first_line) {
    int n =  atoi(first_line);
    char buffer[1024];
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1024, fp);
        buffer[strcspn(buffer, "\n")] = 0;
        add_string(tokens, buffer);
    }
}
void loadDocTokensIDs(FILE *fp, MATRIX_INT *tokensID, const char *first_line) {
    int n =  atoi(first_line);
    char buffer[1024];
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1024, fp);
        buffer[strcspn(buffer, "\n")] = 0;
        add_string(tokensID, buffer);
    }
}
void loadDoc(char *fileName, DOC *doc) {
    FILE *fp=fopen(fileName,"r");
    if (fp==NULL) {
        printf("File Not Found\n");
        return;
    }
        char buffer[1024];
        int seccao=0;
        while (fgets(buffer,1024,fp) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;    // vai ate a posiçao do \n e remove-o (transforma em 0)
            if (strcmp(buffer, "#Strings")==0) {
                seccao=1;
                continue;
            } if (strcmp(buffer, "#Tokens")) {
                seccao=2;
                continue;
            } if (strcmp(buffer, "#IDs")==0) {
                seccao=3;
                continue;
            }
            switch (seccao) {
                case 1:
                    loadDocText(fp, &doc->text, buffer);
                    seccao=0;
                    break;
                case 2:
                    loadDocTokens(fp, &doc->tokens, buffer);
                    seccao=0;
                    break;
                case 3:
                    loadDocTokensIDs(fp, &doc->tokensID, buffer);
                    seccao=0;
                    break;
                default:
                break;
            }
        }
fclose(fp);
    printf("Document loaded with succes");
}
void saveDoc(char *fileName, DOC *doc) {
    FILE *fp=fopen(fileName,"w");
    if (fp==NULL) {
        printf("File Not Found\n");
        return;
    }

    fprintf(fp,"#Strings\n");                                        // grava Strings que sera a tabela
    fprintf(fp, "%d", doc->text.count);                              // grava o numero de strings
    for (int i = 0; i < doc->text.count; i++) {
        fprintf(fp, "%s\n", doc->text.strings[i]);                   // grava o conteudo da String
    }

    fprintf(fp, "#Tokens\n");
    fprintf(fp, "%d", doc->tokens.count);
    for (int i = 0; i < doc->tokens.count; i++) {
        fprintf(fp, "%s\n", doc->tokens.strings[i]);                 // grava o conteudo do Token
    }

    fprintf(fp, "#IDs\n");
    fprintf(fp, "%d",doc->tokensID.count);
    for (int i = 0; i < doc->tokensID.count; i++) {
        fprintf(fp,"%d ",doc->tokensID.lengths[i]);                  // grava a quantidade de IDs
        for (int j = 0; j < doc->tokensID.lengths[i]; j++) {
            fprintf(fp,"%d ",doc->tokensID.strings[i][j]);           // grava o ID que pertence a linha
        }
        fprintf(fp,"\n");
    }

    //Struct que falta que vem do cook de Ray Santos


    fclose(fp);
    printf("File saved with success\n");
}


void test_r2_r3() {

}