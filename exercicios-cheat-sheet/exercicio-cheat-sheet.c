#include <stdio.h> // Standard IO - printf e scanf

int main() {
    char nome[50];
    char curso[50];
    int disci;
    int carga;

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Digite nome do seu curso: ");
    scanf("%s", curso);

    printf("Digite quantas disciplinas você cursa: ");
    scanf("%d", &disci);

    printf("Digite a carga horária média: ");
    scanf("%d", &carga);

    int estud = disci * carga;

    printf("A quantidade de horas que você dedicará aos estudos nesse período é: %d", estud);
    printf("\n");

    return 0;
}