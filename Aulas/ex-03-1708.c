#include <stdio.h>

int main() {
    int num, soma = 0, qtd = 0;
    double media;
    printf("Digite um valor inteiro positivo: ");
    scanf("%d", &num);
    while (num > 0) {
        qtd += 1;
        soma += num;
        printf("Digite um valor inteiro positivo (<= 0 para finalizar): ");
        scanf("%d", &num);
    }
    
    if (qtd > 0) {
        media = (double) soma / (double) qtd;
        printf("Foram digitados %d números e a média é %lf", qtd, media);
        printf("\n");
    } else {
        printf("Nenhum número válido foi digitado!\n");
    }
    return 0;
}



