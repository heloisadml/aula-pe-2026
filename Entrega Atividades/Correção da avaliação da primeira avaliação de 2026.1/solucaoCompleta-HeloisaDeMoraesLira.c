#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_COLUNAS 5

void imprimirVetor(int v[], int tam);
void preencherVetorAleatorio(int v[], int tam);
void imprimirMatriz(int m[][QTD_COLUNAS], int lin, int col);

int removerRepetidos(int v[], int tam);
void ordenar(int v[], int tam);
void preencherPrimos(int v[], int tam);
void maiorPorLinha(int m[][QTD_COLUNAS], int lin, int col, int v[]);


// MAIN

int main() {

    srand(time(NULL));


    // QUESTÃO A

    int v1[] = {3, 3, 4, 5, 6, 6, 6, 7};
    int tam1 = 8;
    int novoTam;

    printf("QUESTAO A\n");

    printf("Antes: ");
    imprimirVetor(v1, tam1);

    novoTam = removerRepetidos(v1, tam1);

    printf("Depois: ");
    imprimirVetor(v1, tam1);

    printf("Novo tamanho: %d\n", novoTam);


    // QUESTÃO B

    int v2[10];

    preencherVetorAleatorio(v2, 10);

    printf("\nQUESTAO B\n");

    printf("Antes: ");
    imprimirVetor(v2, 10);

    ordenar(v2, 10);

    printf("Depois: ");
    imprimirVetor(v2, 10);


    // QUESTÃO C

    int v3[10];

    printf("\nQUESTAO C\n");

    preencherPrimos(v3, 10);

    imprimirVetor(v3, 10);


    // QUESTÃO D

    int matriz[3][QTD_COLUNAS] = {
        {10, 5, 20, 3, 8},
        {7, 15, 2, 9, 4},
        {30, 1, 12, 18, 6}
    };

    int maiores[3];

    printf("\nQUESTAO D\n");

    imprimirMatriz(matriz, 3, QTD_COLUNAS);

    maiorPorLinha(matriz, 3, QTD_COLUNAS, maiores);

    printf("Maiores: ");
    imprimirVetor(maiores, 3);


    return 0;
}


// AUXILIARES

void imprimirVetor(int v[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}


void preencherVetorAleatorio(int v[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        v[i] = rand() % 20;
    }
}


void imprimirMatriz(int m[][QTD_COLUNAS], int lin, int col) {

    int l, c;

    for (l = 0; l < lin; l++) {

        for (c = 0; c < col; c++) {
            printf("%3d ", m[l][c]);
        }

        printf("\n");
    }
}


// QUESTÃO A

int removerRepetidos(int v[], int tam) {

    int pos = 0, i;

    for (i = pos + 1; i < tam; i++) {

        if (v[i] == v[pos]) {

            v[i] = -1;

        } else {

            pos = i;
        }
    }

    ordenar(v, tam);

    for (i = 0; i < tam; i++) {

        if (v[i] != -1) {

            return tam - i;
        }
    }

    return 0;
}


// QUESTÃO B

void ordenar(int v[], int tam) {

    int trocou = 1, aux, i;

    while (trocou) {

        trocou = 0;

        for (i = 0; i < tam - 1; i++) {

            if (v[i] > v[i + 1]) {

                aux = v[i + 1];

                v[i + 1] = v[i];

                v[i] = aux;

                trocou = 1;
            }
        }
    }
}


// QUESTÃO C

void preencherPrimos(int v[], int tam) {

    int primoInicial = 2, primo = 0;
    int i, j;

    v[0] = primoInicial;
    v[1] = primoInicial + 1;

    for (i = 2; i < tam; i++) {

        primo = 0;

        v[i] = v[i - 1] + 2;

        while (!primo) {

            primo = 1;

            for (j = 0; j < i; j++) {

                if (v[i] % v[j] == 0) {

                    primo = 0;
                }
            }

            if (!primo) {

                v[i] += 2;
            }
        }
    }
}


// QUESTÃO D

void maiorPorLinha(
    int m[][QTD_COLUNAS],
    int lin,
    int col,
    int v[]
) {

    int maior;
    int l, c;

    for (l = 0; l < lin; l++) {

        maior = m[l][0];

        for (c = 1; c < col; c++) {

            if (m[l][c] > maior) {

                maior = m[l][c];
            }
        }

        v[l] = maior;
    }
}