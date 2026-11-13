#include <stdio.h>
#include <string.h>

#define TAM_CONTA 100
#define TAM_NOME 50

struct Contas {
    int numero;
    char nome[TAM_NOME];
    int cpf;
    int telefone;
    double saldo;
};

int buscaConta(struct Contas v[], int n, int x); // (a)

void cadastrarConta(struct Contas v[], int *n, int x); // (b)
void lerStr(char str[], int tamMax);

void consultarSaldo(struct Contas v[], int n, int x); // (c)

void depositoConta(struct Contas v[], int n, int x); // (d)

void saqueConta(struct Contas v[], int n, int x); // (e)

void impressaoCadastro(struct Contas v[], int n); // (f)

int main() {
    // CONTAS PARA TESTES:
    struct Contas correntes[TAM_CONTA] = {
        {1001, "Ana Sofia", 111111111, 987654321, 3500.00},
        {1002, "André Pontual", 222222222, 987654322, 6300.50},
    };

    struct Contas poupancas[TAM_CONTA] = {
        {2001, "Heloisa Lira", 333333333, 987654323, 2.00},
        {2002, "Pedro Lucas", 444444444, 987654324, 3200.00}
    };

    int qtdCorrentes = 2;
    int qtdPoupancas = 2;
    
    // RESPOSTAS

    printf("Posição da conta: %d\n", buscaConta(correntes, qtdCorrentes, 1002)); // (a)
    printf("Posição da conta: %d\n", buscaConta(poupancas, qtdPoupancas, 2001)); // (a)

    cadastrarConta(correntes, &qtdCorrentes, 1003); // (b)

    printf("\nConsulta de saldo de conta de número 1001:");
    consultarSaldo(correntes, qtdCorrentes, 1001); // (c)

    printf("\nDepósito de saldo de conta de número 1001:");
    depositoConta(correntes, qtdCorrentes, 1001); // (d)

    printf("\nSaque de saldo de conta de número 1001:");
    saqueConta(correntes, qtdCorrentes, 1001); // (e)

    impressaoCadastro(correntes, qtdCorrentes); // (f)

    return 0;
}

int buscaConta(struct Contas v[], int n, int x) { 
    if (n == 0) {
        return -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (v[i].numero == x) {
            return i;
        }
    }

    return -2;
} 

void cadastrarConta(struct Contas v[], int *n, int x) {
    printf("\n=== CADASTRO DE NOVA CONTA ===\n");

    if (buscaConta(v, *n, x) < 0 && *n < TAM_CONTA) {
        v[*n].numero = x;

        printf("\nDigite nome da nova conta:\n");
        lerStr(v[*n].nome, TAM_NOME);

        printf("\nDigite CPF da nova conta:\n");
        scanf("%d", &v[*n].cpf);

        printf("\nDigite telefone da nova conta:\n");
        scanf("%d", &v[*n].telefone);

        printf("\nDigite saldo da nova conta:\n");
        scanf("%lf", &v[*n].saldo);

        (*n)++;
    } else {
        printf("\nConta já cadastrada ou cadastro cheio.\n");
    }
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void consultarSaldo(struct Contas v[], int n, int x) {
    int pos = buscaConta(v, n, x);
    if (pos >= 0) {
        printf("\nO saldo desta conta é: %lf\n", v[pos].saldo);
    } else {
        printf("\nConta não cadastrada.\n");
    }
}

void depositoConta(struct Contas v[], int n, int x) {
    int pos = buscaConta(v, n, x);
    double saldoAdicional;
    if (pos >= 0) {
        printf("\nDigite valor que deseja depositar à conta:\n");
        scanf("%lf", &saldoAdicional);

        v[pos].saldo += saldoAdicional;
        printf("\nValor depositado com sucesso.\n");
    } else {
        printf("\nConta não cadastrada.\n");
    }
}

void saqueConta(struct Contas v[], int n, int x) {
    int pos = buscaConta(v, n, x);
    double saldoSaque;
    if (pos >= 0) {
        printf("\nDigite valor que deseja saquear da conta:\n");
        scanf("%lf", &saldoSaque);

        if (v[pos].saldo >= saldoSaque) {
            v[pos].saldo -= saldoSaque;
            printf("\nValor saqueado com sucesso.\n");
        } else {
            printf("\nNão há saldo suficiente.\n");
        }

    } else {
        printf("\nConta não cadastrada.\n");
    }
}

void impressaoCadastro(struct Contas v[], int n) {
    printf("\n=== IMPRESSÃO CADASTROS ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nNúmero: %d\n", v[i].numero);
        printf("\nNome do titular: %s\n", v[i].nome);
        printf("\nTelefone para contato: %d\n", v[i].telefone);
        printf("\n=================================\n");
    }
}