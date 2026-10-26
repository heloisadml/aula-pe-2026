#include <stdio.h>

#define TAM_DESC 100

struct Horario {
    int hora;
    int minutos;
    int segundos;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Horario horario;
    struct Data data;
    char descricao[TAM_DESC];
};

int main() {
    // exemplo fixo
    struct Compromisso aula = {
        {7, 30, 0},
        {26, 10, 2026},
        "Aula Prog. Estruturada"
    };

    printf("Compromisso: %s\n", aula.descricao);
    printf("Data: %02d/%02d/%d\n", aula.data.dia, aula.data.mes, aula.data.ano);
    printf("Horario: %02d:%02d:%02d\n", aula.horario.hora, aula.horario.minutos, aula.horario.segundos);

    return 0;
}