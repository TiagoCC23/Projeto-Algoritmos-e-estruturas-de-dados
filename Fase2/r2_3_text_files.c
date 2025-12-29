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
        if (fgets(buffer,sizeof(buffer),fp)==NULL)  // le a linha inteira
        {
            break;
        }
        char *ptr=buffer;                                    // ponteiro que aponta para o buffer para percorrer os ids
        int sizeLine=strtol(ptr, &ptr, 10);             // funciona como um atoi, mas mais seguro e o radix eh 10, porque eh decimal
                                                             // le o size da linha e percorre o pointer
        int *idstemp = (int*) malloc(sizeLine* sizeof(int));
        for (int j=0; j<sizeLine; j++)
        {
            idstemp[j]=strtol(ptr, &ptr, 10);
        }
        add_int_array(tokensID, idstemp, sizeLine);
        free(idstemp);
    }
}
void loadDocTokensFrequency(FILE *fp, LL_TK_TF *term_frequency, const char *first_line)
{
    int n=atoi(first_line);
    char buffer[1024];
    for (int i=0; i<n; i++)
    {
        if (fgets(buffer, sizeof(buffer), fp)==NULL)
        {
            break;
        }
        int length = atoi(buffer);
        int *tempTokens = (int*)malloc(length*sizeof(int));
        int *tempFreqs = (int*)malloc(length*sizeof(int));
        parseIntArray(fp, tempTokens, length);
        parseIntArray(fp, tempFreqs, length);
        insert_node(term_frequency, tempTokens, tempFreqs, length, i);
        free(tempTokens);
        free(tempFreqs);
    }

}
void parseIntArray(FILE *fp, int *des, int size)
{
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer),fp)==NULL)
    {
        return;
    }
    char *ptr=buffer;
    for (int i=0; i<size; i++)
    {
        des[i]=strtol(ptr, &ptr, 10);
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
            } if (strcmp(buffer, "#Tokens")==0) {
                seccao=2;
                continue;
            } if (strcmp(buffer, "#IDs")==0) {
                seccao=3;
                continue;
            } if (strcmp(buffer, "#Nodes")==0)
            {
                seccao=4;
                continue;
            }
            switch (seccao) {
                case 1:
                    loadDocText(fp, doc->text, buffer);
                    seccao=0;
                    break;
                case 2:
                    loadDocTokens(fp, doc->tokens, buffer);
                    seccao=0;
                    break;
                case 3:
                    loadDocTokensIDs(fp, doc->ids, buffer);
                    seccao=0;
                    break;
                case 4:
                    loadDocTokensFrequency(fp, doc->term_frequency, buffer);
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
    fprintf(fp, "%d\n", doc->text->count);                              // grava o numero de strings
    for (int i = 0; i < doc->text->count; i++) {
        fprintf(fp, "%s\n", doc->text->strings[i]);                   // grava o conteudo da String
    }

    fprintf(fp, "#Tokens\n");
    fprintf(fp, "%d", doc->tokens->count);
    for (int i = 0; i < doc->tokens->count; i++) {
        fprintf(fp, "%s\n", doc->tokens->strings[i]);                 // grava o conteudo do Token
    }

    fprintf(fp, "#IDs\n");
    fprintf(fp, "%d",doc->ids->count);
    for (int i = 0; i < doc->ids->count; i++) {
        fprintf(fp,"%d ",doc->ids->lengths[i]);                  // grava a quantidade de IDs
        for (int j = 0; j < doc->ids->lengths[i]; j++) {
            fprintf(fp,"%d ",doc->ids->strings[i][j]);           // grava o ID que pertence a linha
        }
        fprintf(fp,"\n");
    }
    fprintf(fp, "#Nodes\n");
    if (doc->term_frequency!=NULL)
    {
        fprintf(fp, "%d\n", doc->term_frequency->count);
        TK_TF_NODE *current=doc->term_frequency->head;
        while (current!=NULL)
        {
            fprintf(fp, "%d\n", current->length);
            for (int i=0; i<current->length; i++)
            {
                fprintf(fp, "%d ", current->term_frequency[i]);
            }
                fprintf(fp, "\n");

            for (int i=0; i<current->length; i++)
            {
                fprintf(fp,"%d", current->tokens[i]);
            }
            fprintf(fp, "\n");

            current=current->next;
        }
    } else
    {
        fprintf(fp, "0\n");
    }
    fclose(fp);
    printf("File saved with success\n");
}


void test_r2_r3() {

}