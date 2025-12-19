#include "r1_2_text_and_tokens.h"

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
void test_r1_2() {
MATRIX_STR *str=create_matrix(4);
    add_string(str, "ola");
    add_string(str, "planeta");
    add_string(str, "idk");
    add_string(str, "placa");
    char *search="ia";
    printf("%d\n",stringSearch( str, search));
}
