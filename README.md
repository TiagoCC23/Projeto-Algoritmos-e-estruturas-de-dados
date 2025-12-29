# 📊 Smart Text Analyzer

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Course](https://img.shields.io/badge/Course-AED1%20%2F%20LP1-green.svg)
![University](https://img.shields.io/badge/University-UFP-orange.svg)
![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)

> **Projeto Prático de Desenvolvimento de Software em C**
> *Algoritmos e Estruturas de Dados 1 & Linguagens de Programação 1*

---

## 📖 Sobre o Projeto

O **Smart Text Analyzer** é um sistema eficiente de análise de texto desenvolvido em C. O objetivo principal é armazenar, processar e manipular grandes volumes de dados textuais, transformando-os em representações numéricas (vetores) para análise de similaridade.

O sistema utiliza estruturas de dados dinâmicas para realizar a **tokenização** (baseada em padrões recorrentes) e calcular a frequência de termos (**TF - Term Frequency**), permitindo encontrar frases semelhantes através de métricas como o **Cosseno de Similaridade**.

---

## 🚀 Funcionalidades Principais

* **Gestão Dinâmica de Memória:** Armazenamento de texto e tokens utilizando matrizes dinâmicas e listas ligadas.
* **Tokenização Inteligente:** Algoritmo *greedy* para identificar os tokens mais longos numa frase.
* **Vetorização (TF):** Cálculo da frequência de termos para cada frase do corpus.
* **Pesquisa de Similaridade:** Comparação entre uma frase de entrada e o texto armazenado (Cosseno e Produto Interno).
* **Persistência de Dados:** Leitura e escrita de dados em ficheiros de texto e binários.

---

## 🏗️ Estruturas de Dados

O projeto baseia-se nas seguintes estruturas principais:

* `MATRIX_STR`: Matriz dinâmica para armazenar strings (texto bruto e vocabulário).
* `MATRIX_INT`: Matriz dinâmica para armazenar IDs de tokens e frequências.
* `LL_TK_TF`: Lista Duplamente Ligada para armazenar pares de vetores (Tokens + Frequências).
* `DOC`: Estrutura agregadora que contém todo o contexto do documento.

---

## ✅ Estado de Implementação dos Requisitos

Conforme solicitado no enunciado do projeto, abaixo encontra-se a tabela de requisitos e o seu estado atual de desenvolvimento.

| ID | Descrição Resumida | Peso (AED1/LP1) | Estado |
| :--- | :--- | :---: | :---: |
| **R1.1** | Estruturas `MATRIX_STR` (Texto/Tokens) e funções base | 1.0 / 1.0 | ✅ |
| **R1.2** | Manipulação (Inserir/Remover) e Pesquisa de texto | 3.0 / 3.0 | ✅ |
| **R1.3** | Algoritmo de cálculo do alfabeto de tokens (Merge) | 3.0 / 3.0 | 🚧 |
| **R1.4** | Tokenização das frases (Vetor de IDs) | 1.0 / 1.0 | ✅ |
| **R1.5** | Vetorização TF (Frequência de Termos) | 1.0 / 1.0 | ✅ |
| **R1.6** | Cálculo de Similaridade (Cosseno/Produto Interno) | 1.0 / 1.0 | ❌ |
| **R2.1** | Estrutura `LL_TK_TF` (Lista Ligada) e gestão de nós | 3.0 / 3.0 | ✅ |
| **R2.2** | Estrutura agregadora `DOC` e `MATRIX_INT` | 2.0 / 2.0 | ✅ |
| **R2.3** | I/O com Ficheiros de Texto | 2.0 / 2.0 | 🚧 |
| **R2.4** | I/O com Ficheiros Binários | 1.5 / 1.5 | ❌ |
| **R2.5** | Documentação Doxygen, Git e README | 1.5 / 1.5 | ✅ |

> **Legenda:**
> * ✅ : Implementado
> * 🚧 : Parcialmente Implementado
> * ❌ : Não Implementado

---

## 🛠️ Como Compilar e Executar

### Pré-requisitos
* Compilador GCC
* Make (opcional, se tiver Makefile)

### Compilação
```bash
gcc -o smart_analyzer main.c r1_matrix.c r2_linked_list.c r2_doc.c -I.
