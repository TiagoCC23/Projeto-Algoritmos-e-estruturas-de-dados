cmake_minimum_required(VERSION 4.0)
project(Projeto_Algoritmos_e_estruturas_de_dados C)

set(CMAKE_C_STANDARD 17)

include_directories(Fase1)
include_directories(Fase2)

add_executable(Projeto_Algoritmos_e_estruturas_de_dados main.c
        "Fase1/r1_2_text_and_tokens.c"
        "Fase1/r1_2_text_and_tokens.h"
        "Fase1/r1_1_text_matrix.c"
        "Fase1/r1_1_text_matrix.h"
        "Fase1/r1_3_alphabet_tokens.c"
        "Fase1/r1_3_alphabet_tokens.h"
        Fase1/r1_4_tokenization.c
        Fase1/r1_4_tokenization.h
        Fase1/r1_6_similarity.c
        Fase1/r1_6_similarity.h
)
