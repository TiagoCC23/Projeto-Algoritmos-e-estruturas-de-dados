cmake_minimum_required(VERSION 4.0)
project(Projeto_Algoritmos_e_estruturas_de_dados C)

set(CMAKE_C_STANDARD 17)

include_directories(Fase1)
include_directories(Fase2)

add_executable(Projeto_Algoritmos_e_estruturas_de_dados main.c
        Fase1/PesquisaSubstrings.c
        Fase1/PesquisaSubstrings.h)
