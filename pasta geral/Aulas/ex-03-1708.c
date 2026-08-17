#include <stdio.h>

#define QTD_MAX_VALORES 5

int main() {
    int num, soma = 0, qtd = 0, qtd_Acima_Media = 0;
    int numeros[QTD_MAX_VALORES];
    double media;
    printf("Digite um valor inteiro positivo: ");
    scanf("%d", &num);
    while (num > 0) {
        numeros[qtd] = num;
        qtd += 1;
        soma += num;
        if (qtd >= QTD_MAX_VALORES) {
            printf("Quantidade máxima de valores atingida!\n");
            break;
        }
        printf("Digite um valor inteiro positivo (<= 0 para finalizar): ");
        scanf("%d", &num);
    }

    if (qtd > 0) {
        media = (double) soma / (double) qtd;
        printf("\n-- Números digitados:\n");
        printf("\nForam digitados %d números e a média é %lf\n", qtd, media);
        for (int i = 0; i < qtd; i += 1) {
        printf("numeros[%d] = %d", i + 1, numeros[i]);
        if (numeros[i] > media) {
            qtd_Acima_Media += 1;
            printf(" --> Este número está acima da média!\n");
        } else {
            printf("\n");
        }
    }

    if (qtd_Acima_Media == 0) {
        printf("\nNão há números acima da média\n");
    } else {
        printf("\nExistem %d números acima da média.\n", qtd_Acima_Media);
    }

    } else {
        printf("Nenhum número válido foi digitado!\n");
    }
    return 0;
}
