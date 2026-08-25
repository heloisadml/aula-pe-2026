#include <stdio.h>

#define QTD_ALUNOS 30

int main() {
    double nota1[QTD_ALUNOS];
    double nota2[QTD_ALUNOS];
    double media[QTD_ALUNOS];
    double totalNotasTurma = 0;

    for (int i = 0; i < QTD_ALUNOS; i += 1) {
        printf("REGISTRANDO NOTAS DE ALUNO %d/%d\n", i + 1, QTD_ALUNOS);
        printf("Digite a primeira nota: ");
        scanf("%lf", &nota1[i]);

        printf("Digite a segunda nota: ");
        scanf("%lf", &nota2[i]);

        media[i] = (nota1[i] * 2 + nota2[i] * 3) / 5;

        totalNotasTurma += media[i];
    }

    double mediaTurma = totalNotasTurma / QTD_ALUNOS;

    printf("\nREGISTRO DE NOTAS\n");
    printf("A média da turma foi: %.2lf\n", mediaTurma);

    printf("Alunos com média acima ou igual à média da turma:\n");

    for (int i = 0; i < QTD_ALUNOS; i +=1) {
        if (media[i] >= mediaTurma) {
            printf("Aluno %d -> Nota 1: %.2lf; Nota 2: %.2lf; Média: %.2lf\n", i + 1, nota1[i], nota2[i], media[i]);
        }
    }
    return 0;
}