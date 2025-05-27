#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

void gerarVetor(int vetor[], int tamanho) { // essa funcao vai gerar os numeros aleatorios
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10000;
    }
}

void copiarVetor(int origem[], int destino[], int tamanho) { // essa funcao vai gerar copias do vetor original
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void imprimirVetor(int vetor[], int tamanho) { // essa funcao vai imprimir os 20 primeiros e 20 ultimos numeros do vetor
    printf("Primeiros 20 elementos: ");
    for (int i = 0; i < 20; i++)
        printf("%d ", vetor[i]);

    printf("\nÚltimos 20 elementos: ");
    for (int i = tamanho - 20; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n\n");
}

void selectionSort(int vetor[], int tamanho, int crescente) { // selection sort, esta funcao procura o menor (ou maior) número do vetor e coloca ele na posição correta
    for (int i = 0; i < tamanho - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if ((crescente && vetor[j] < vetor[idx]) || (!crescente && vetor[j] > vetor[idx])) {
                idx = j;
            }
        }
        if (idx != i) {
            int temp = vetor[i];
            vetor[i] = vetor[idx];
            vetor[idx] = temp;
        }
    }
}

void bubbleSort(int vetor[], int tamanho, int crescente) { // bubble sort, esta funcao compara dois numeros no vetor que se estiverem na ordem errada, ela troca eles
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if ((crescente && vetor[j] > vetor[j + 1]) || (!crescente && vetor[j] < vetor[j + 1])) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // randomiza os numeros toda vez utilizando o srand ao inves do rand

    int original[N], copia1[N], copia2[N], copia3[N], copia4[N];

    gerarVetor(original, N); // gera os numeros aleatorios

    copiarVetor(original, copia1, N);
    copiarVetor(original, copia2, N);
    copiarVetor(original, copia3, N);
    copiarVetor(original, copia4, N);

    printf("Vetor Original:\n"); // a partir daqui o codigo vai imprimir os valores ate o fim
    imprimirVetor(original, N);

    selectionSort(copia1, N, 1);
    printf("Selection Sort Crescente:\n");
    imprimirVetor(copia1, N);

    selectionSort(copia2, N, 0);
    printf("Selection Sort Decrescente:\n");
    imprimirVetor(copia2, N);

    bubbleSort(copia3, N, 1);
    printf("Bubble Sort Crescente:\n");
    imprimirVetor(copia3, N);

    bubbleSort(copia4, N, 0);
    printf("Bubble Sort Decrescente:\n");
    imprimirVetor(copia4, N);

    return 0;
}