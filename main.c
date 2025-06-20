#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000  // Quantidade de números no vetor

// Função que cria o vetor com números aleatórios
void gerarVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % 10000;  // Cada posição recebe um número de 0 a 9999
    }
}

// Função que faz uma cópia de um vetor pra outro
void copiarVetor(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *(destino + i) = *(origem + i);  // Copia cada número de uma posição pra outra
    }
}

// Função que imprime só os 20 primeiros e os 20 últimos números do vetor
void imprimirVetor(int *vetor, int tamanho) {
    printf("Primeiros 20 numeros: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\nUltimos 20 numeros: ");
    for (int i = tamanho - 20; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\n\n");
}

// Função que organiza os números usando o Selection Sort
void selectionSort(int *vetor, int tamanho, int crescente) {
    for (int i = 0; i < tamanho - 1; i++) {
        int idx = i;  // Salva a posição atual

        for (int j = i + 1; j < tamanho; j++) {
            // Se for pra organizar em ordem crescente
            if (crescente && *(vetor + j) < *(vetor + idx)) {
                idx = j;  // Achei um número menor
            }
            // Se for pra organizar em ordem decrescente
            else if (!crescente && *(vetor + j) > *(vetor + idx)) {
                idx = j;  // Achei um número maior
            }
        }

        // Troca de lugar se precisar
        if (idx != i) {
            int temp = *(vetor + i);
            *(vetor + i) = *(vetor + idx);
            *(vetor + idx) = temp;
        }
    }
}

// Função que organiza os números usando o Bubble Sort
void bubbleSort(int *vetor, int tamanho, int crescente) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            // Se for pra organizar em ordem crescente
            if (crescente && *(vetor + j) > *(vetor + j + 1)) {
                int temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
            }
            // Se for pra organizar em ordem decrescente
            else if (!crescente && *(vetor + j) < *(vetor + j + 1)) {
                int temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));  // Faz os números aleatórios mudarem toda vez que o programa roda

    // Criando os vetores de forma dinâmica (alocando espaço na memória)
    int *original = (int*) malloc(N * sizeof(int));
    int *copia1 = (int*) malloc(N * sizeof(int));
    int *copia2 = (int*) malloc(N * sizeof(int));
    int *copia3 = (int*) malloc(N * sizeof(int));
    int *copia4 = (int*) malloc(N * sizeof(int));

    // Gera os números aleatórios no vetor original
    gerarVetor(original, N);

    // Faz as 4 cópias do vetor original (uma pra cada ordenação)
    copiarVetor(original, copia1, N);
    copiarVetor(original, copia2, N);
    copiarVetor(original, copia3, N);
    copiarVetor(original, copia4, N);

    // Mostra o vetor original
    printf("Vetor Original:\n");
    imprimirVetor(original, N);

    // Aqui ordena usando Selection Sort - Crescente
    selectionSort(copia1, N, 1);
    printf("Selection Sort - Crescente:\n");
    imprimirVetor(copia1, N);

    // Aqui ordena usando Selection Sort - Decrescente
    selectionSort(copia2, N, 0);
    printf("Selection Sort - Decrescente:\n");
    imprimirVetor(copia2, N);

    // Aqui ordena usando Bubble Sort - Crescente
    bubbleSort(copia3, N, 1);
    printf("Bubble Sort - Crescente:\n");
    imprimirVetor(copia3, N);

    // Aqui ordena usando Bubble Sort - Decrescente
    bubbleSort(copia4, N, 0);
    printf("Bubble Sort - Decrescente:\n");
    imprimirVetor(copia4, N);

    //opa professor lucas, tudo certo?

    return 0;
}
