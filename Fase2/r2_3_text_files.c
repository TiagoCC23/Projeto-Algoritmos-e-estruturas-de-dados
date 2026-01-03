#include "r2_3_text_files.h"

void loadDocText(FILE *fp, MATRIX_STR *text, const char *first_line) {
    int n = atoi(first_line);
    char buffer[1024];
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1024, fp);
        buffer[strcspn(buffer, "\n")] = 0;
        add_string(text, buffer);
    }
}
void loadDocTokens(FILE *fp, MATRIX_STR *tokens, const char *first_line) {
    int n = atoi(first_line);
    char buffer[1024];
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1024, fp);
        buffer[strcspn(buffer, "\n")] = 0;
        add_string(tokens, buffer);
    }
}
// ... Mantém loadDocTokensIDs e loadDocTokensFrequency iguais ...
void loadDocTokensIDs(FILE *fp, MATRIX_INT *tokensID, const char *first_line) {
    int n =  atoi(first_line);
    char buffer[1024];
    for (int i = 0; i < n; i++) {
        if (fgets(buffer,sizeof(buffer),fp)==NULL) break;
        char *ptr=buffer;
        int sizeLine=strtol(ptr, &ptr, 10);
        int *idstemp = (int*) malloc(sizeLine* sizeof(int));
        for (int j=0; j<sizeLine; j++) {
            idstemp[j]=strtol(ptr, &ptr, 10);
        }
        add_int_array(tokensID, idstemp, sizeLine);
        free(idstemp);
    }
}
void loadDocTokensFrequency(FILE *fp, LL_TK_TF *term_frequency, const char *first_line) {
    int n=atoi(first_line);
    char buffer[1024];
    for (int i=0; i<n; i++) {
        if (fgets(buffer, sizeof(buffer), fp)==NULL) break;
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
void parseIntArray(FILE *fp, int *des, int size) {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer),fp)==NULL) {
        return;
    }
    char *ptr=buffer;
    for (int i=0; i<size; i++){
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
        buffer[strcspn(buffer, "\n")] = 0;
        if (strcmp(buffer, "#Strings")==0) {
            seccao=1;
            continue;
        }
        if (strcmp(buffer, "#Tokens")==0) {
            seccao=2;
            continue;
        }
        if (strcmp(buffer, "#IDs")==0) {
            seccao=3;
            continue;
        }
        if (strcmp(buffer, "#Nodes")==0) {
            seccao=4;
            continue;
        }

        switch (seccao) {
            case 1: loadDocText(fp, doc->text, buffer);
                seccao=0;
                break;
            case 2: loadDocTokens(fp, doc->tokens, buffer);
                seccao=0;
                break;
            case 3: loadDocTokensIDs(fp, doc->ids, buffer);
                seccao=0;
                break;
            case 4: loadDocTokensFrequency(fp, doc->term_frequency, buffer);
                seccao=0;
                break;
            default:
                break;
        }
    }
    fclose(fp);
    printf("Document loaded with success\n");
}


void saveDoc(char *fileName, DOC *doc) {
    FILE *fp = fopen(fileName, "w");
    if (!fp) { printf("Erro file\n"); return; }

    //----------TEXTO----------//
    fprintf(fp, "#Strings\n");
    if (doc->text) {
        fprintf(fp, "%d\n", doc->text->count); // grava a quantidade de strings
        for (int i=0; i<doc->text->count; i++) {
            fprintf(fp, "%s\n", doc->text->strings[i]); // grava a string por linha
        }
    } else fprintf(fp, "0\n");

    //----------TOKENS----------//
    fprintf(fp, "#Tokens\n");
    if (doc->tokens) {
        fprintf(fp, "%d\n", doc->tokens->count); // grava a quantidade de tokens
        for (int i=0; i<doc->tokens->count; i++) {
            fprintf(fp, "%s\n", doc->tokens->strings[i]); // grava os tokens por linha
        }
    } else fprintf(fp, "0\n");

    //----------TOKENSIDS----------//
    fprintf(fp, "#IDs\n");
    if (doc->ids) {
        fprintf(fp, "%d\n", doc->ids->count); // grava a quantidade de ids
        for (int i=0; i<doc->ids->count; i++) {
            fprintf(fp, "%d ", doc->ids->lengths[i]); //grava a linha de ids
            for (int j=0; j<doc->ids->lengths[i]; j++) {
                fprintf(fp, "%d ", doc->ids->strings[i][j]); // grava o id que pertence a linha
            }
            fprintf(fp, "\n");
        }
    } else fprintf(fp, "0\n");

    //----------TOKENSFREQ----------//
    fprintf(fp, "#Nodes\n");
    if (doc->term_frequency) {
        fprintf(fp, "%d\n", doc->term_frequency->count);
        TK_TF_NODE *current = doc->term_frequency->head;
        while (current) {
            fprintf(fp, "%d\n", current->length);


            for(int i=0; i<current->length; i++) {
                fprintf(fp, "%d ", current->tokens[i]);  // grava os ids
            }
                fprintf(fp, "\n");


            for(int i=0; i<current->length; i++) {
                fprintf(fp, "%d ", current->term_frequency[i]);  // grava as Frequências
            }
                fprintf(fp, "\n");

            current = current->next;
        }
    } else fprintf(fp, "0\n");

    fclose(fp);
    printf("Document saved with success\n");
}
void test_r2_r3() {
    DOC *newDocSave = create_doc();

    /*------------ criaçao das matrizes ------------*/

    if (newDocSave->text == NULL) {
        newDocSave->text = create_matrix(10);
    }

    if (newDocSave->tokens == NULL) {
        newDocSave->tokens = create_matrix(50);
    }
    if (newDocSave->ids == NULL) {
        newDocSave->ids = create_matrix_int(50);
    }
    if (newDocSave->term_frequency == NULL) {
        newDocSave->term_frequency = create_linked_list();
    }


    /*------------ adiçao das strings para o ficheiro ------------*/
    add_string(newDocSave->text, "Hello World");
    add_string(newDocSave->text, "Ola Mundo");


    char *fileName = "..\\Fase2\\Teste2_3.txt";

    printf("Build Tokens\n");
    build_tokens(newDocSave->text, newDocSave->tokens, 25);
    printf("Tokens Ids\n");
    newDocSave->ids=tokenizer(newDocSave->text, newDocSave->tokens);
    /*printf("Frequency\n");
    newDocSave->term_frequency=term_frequency(newDocSave->ids);*/

    saveDoc(fileName, newDocSave);


    DOC *newDocLoad = create_doc();
    newDocLoad->text = create_matrix(50);
    newDocLoad->tokens = create_matrix(50);
    newDocLoad->ids = create_matrix_int(50);
    newDocLoad->term_frequency = create_linked_list();

    loadDoc(fileName, newDocLoad);
    free_doc(newDocSave);
    free_doc(newDocLoad);

}