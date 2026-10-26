#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_ENDERECO 100

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    char endereco[TAM_ENDERECO];
};

void lerStr(char str[], int tamMax);
void preencherPessoa(struct Pessoa *p);
void imprimirPessoa(struct Pessoa p);

int main() {
    struct Pessoa pessoa;
    preencherPessoa(&pessoa);
    imprimirPessoa(pessoa);
    return 0;
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void preencherPessoa(struct Pessoa *p) {
    printf("\nREGISTRO DE PESSOA");
    printf("\nDigite o nome: ");
    lerStr((*p).nome, TAM_NOME);
    printf("Digite a idade: ");
    scanf("%d", &(*p).idade);
    getchar(); // Limpa o '\n' deixado pelo scanf no buffer do teclado
    printf("Digite o endereço: ");
    lerStr((*p).endereco, TAM_ENDERECO);
}

void imprimirPessoa(struct Pessoa p) {
    printf("\nNome: %s.\nIdade: %d.\nEndereço: %s\n", p.nome, p.idade, p.endereco);
}