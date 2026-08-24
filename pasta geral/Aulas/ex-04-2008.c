#include <stdio.h>

#define QTD 10

int maiorValorVetor(int vetor[], int elem);
int buscaSequencial(int vetor[], int elem, int x);
void digitacaoVetor(int vetor[], int elem);
void impressaoVetor(int vetor[], int elem);
int removerValor(int vetor[], int elem, int x);

int main() {
    int numeros[QTD];
    int x;
    int opcao;

    printf("DIGITAÇÃO VETOR:\n");
    digitacaoVetor(numeros, QTD);
    
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Imprimir o vetor\n");
        printf("2 - Buscar valor no vetor\n");
        printf("3 - Achar maior elemento do vetor\n");
        printf("4 - Remover valor do vetor\n");
        printf("0 - Sair\n");

        printf("Opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                impressaoVetor(numeros, QTD);
                printf("\n");
                break;
            case 2:
                printf("Digite o valor a buscar: ");
                scanf("%d", &x);
                {
                    int pos = buscaSequencial(numeros, QTD, x);
                    if (pos == -1) {
                        printf("Este valor não está no vetor.\n");
                    } else {
                        printf("Valor encontrado na posição %d.\n", pos + 1);
                    }
                }
                break;
            case 3:
                printf("\nO maior valor está na posição: %d\n", maiorValorVetor(numeros, QTD));
                break;
            case 4:
                impressaoVetor(numeros, QTD);
                printf("\n");
                printf("\nDigite o número que deseja remover: ");
                scanf("%d", &x);
                if (removerValor(numeros, QTD, x) == 0) {
                    printf("\nEste número não está no vetor.");
                } else {
                    printf("\nNúmero removido.\n");
                }
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (opcao != 0);
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
        if (vetor[i] == x) {
            return i;
        }
    }
    return -1;
}

int removerValor(int vetor[], int elem, int x) {
    int pos = buscaSequencial(vetor, elem, x);
    if (pos == -1) {
        return 0;
    }
    for (int i = pos + 1; i < elem; i += 1) {
        vetor[i - 1] = vetor[i];
    }

    vetor[elem - 1] = 0; // limpar ultimo (nao diminui vetor)

    return 1;
}