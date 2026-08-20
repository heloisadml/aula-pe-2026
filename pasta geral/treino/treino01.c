#include <stdio.h>

#define QTD_NOTAS 3

int main() {
    int nota, soma = 0;
    double media;

    for (int i = 1; i <= QTD_NOTAS;) {
        printf("Digite a nota %d:\n", i);
        scanf("%d", &nota);
        
        if (nota > 10 || nota < 0) {
            printf("Nota inválida, tente novamente.\n");
        } else {
            soma += nota;
            i += 1;
        }
    }
    
    media = (double) soma / QTD_NOTAS;
    printf("\nSua média foi: %.1f\n", media);

    if (media >= 7) {
        printf("Você passou!\n");
    } else {
        printf("Você não passou.\n");
    }
}