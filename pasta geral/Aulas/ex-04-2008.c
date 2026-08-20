#include <stdio.h>

#define QTD 10

int maiorValorVetor(int vetor[], int elem);
int buscaSequencial(int vetor[], int elem, int x);
void digitacaoVetor(int vetor[], int elem);
void impressaoVetor(int vetor[], int elem);

int main() {
    int numeros[QTD];
    int x = 9; // qualquer numero

    digitacaoVetor(numeros, QTD);
    impressaoVetor(numeros, QTD);
    printf("\nO maior valor está na posição: %d\n", maiorValorVetor(numeros, QTD));
    
    if (buscaSequencial(numeros, QTD, x) = -1) {
        printf("Este número não está no vetor.")
    }
    printf("\n O número %d ")
    return 0;
}

void digitacaoVetor(int vetor[], int elem) {
    for (int i = 0; i < elem; i += 1) {
        printf("[%d] Digite um número: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void impressaoVetor(int vetor[], int elem) {
    printf("\nNúmeros digitados:\n");

    for (int i = 0; i < elem; i += 1) {
        if (i == elem - 1) {
            printf("%d.", vetor[i]);
        } else {
            printf("%d, ", vetor[i]);
        }
    }
}

int maiorValorVetor(int vetor[], int elem) {
    int maior = 0;

    for (int i = 1; i < elem; i += 1) {
        if (vetor[i] > vetor[maior]) {
        maior = i;
        }
    }
    return maior + 1;
}

int buscaSequencial (int vetor[], int elem, int x) {
    for (int i = 0; i < elem; i += 1) {
        if (vetor[i] = x) {
            return i;
        }
    }
    return -1;
}
