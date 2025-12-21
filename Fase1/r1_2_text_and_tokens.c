#include "r1_2_text_and_tokens.h"


void loadFile(char* fileName, MATRIX_STR *mx) {
    FILE *fp = fopen(fileName, "r");
    if (fp==NULL) {
        printf("File Not Found\n");
        return;
    }
    char buffer[1024];

 while (fgets(buffer, 1024, fp) != NULL) {   // le ate ser NULL
     buffer[strcspn(buffer, "\n")] = 0;    // vai ate a posiçao do \n e remove-o (transforma em 0)
     add_string(mx, buffer);
 }
    fclose(fp);
}


int stringSearch(const MATRIX_STR *str, const char *subStr)
{
    int contadorPalavras=0;
    for (int i=0; i< str->count; i++)
    {
    if (strstr(str->strings[i],subStr)!=NULL)
    {
        contadorPalavras++;
    }
    }
    return contadorPalavras;
}
void testeSearchC() {
    MATRIX_STR *str=create_matrix(4);
    add_string(str, "ola");
    add_string(str, "planeta");
    add_string(str, "idk");
    add_string(str, "placa");
    char *search="idk";
    printf("%d\n",stringSearch( str, search));
    free_matrix_str(str);
}
void testeSearchTXT() {
    MATRIX_STR *str=create_matrix(4);
    char file[]="../strings.txt";
    char *search="idk";
    loadFile(file, str);
    printf("%d\n",stringSearch( str, search));
    free_matrix_str(str);
}
void test_r1_2() {
    testeSearchC();
    testeSearchTXT();
}
