# Ordenação em C com Ponteiros (Atualização do Trabalho Anterior)

Este projeto é uma atualização do trabalho anterior da disciplina **Fundamentos de Algoritmos e Programação** da **Unochapecó**.

Agora o programa utiliza **ponteiros** e **alocação dinâmica de memória**.

## Como funciona

- O programa gera um vetor com **1000 números aleatórios** (valores entre 0 e 9999).
- O vetor original é **copiado para outros vetores**.
- Cada cópia é **ordenada** com um tipo de algoritmo e em uma ordem diferente.
- Os algoritmos usados são:
  - **Selection Sort**
  - **Bubble Sort**
- Cada algoritmo ordena o vetor em:
  - **Ordem crescente**
  - **Ordem decrescente**
- O programa mostra os **20 primeiros** e os **20 últimos números** de cada vetor.

- ## Exemplo Visual dos Algoritmos de Ordenação

### Bubble Sort

<p align="center">
  <img src="https://github.com/user-attachments/assets/eaf3ccc2-ff74-48e8-890b-52f5a8c7aec4" alt="Bubble Sort Animation" width="300"/>
</p>

### Selection Sort

<p align="center">
  <img src="https://github.com/user-attachments/assets/315b4f98-f4dc-4b43-8691-42614a00d381" alt="Selection Sort Animation" width="300"/>
</p>


## Principais mudanças em relação ao trabalho anterior

- Uso de **malloc** para criar os vetores de forma dinâmica.
- Manipulação dos vetores usando **ponteiros**.
- Parâmetro nas funções para escolher a **ordem de classificação (crescente ou decrescente)**.

## Autor

Gustavo Desordi  
Ciência da Computação - Unochapecó
