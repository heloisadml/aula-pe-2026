void lerStr(char str[], int tamMax) { // auxiliar pra 1
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void cadastrarConta(struct Conta v[], int *tam) { // 1
    int cadastroId;
    double cadastroLimite;

    if (*tam >= TAM_CONTAS) {
        return;
    }

    scanf("%d", &cadastroId);

    if (buscaId(v, *tam, cadastroId) != -1) {
        return;
    }

    v[*tam].id = cadastroId;

    getchar();
    lerStr(v[*tam].cliente, sizeof(v[*tam].cliente));

    scanf("%lf", &v[*tam].saldo);
    scanf("%lf", &cadastroLimite);

    if (cadastroLimite < 0) {
        return;
    }

    v[*tam].limite = cadastroLimite;

    (*tam)++;
}

int buscaBinariaNome(struct Conta v[], int tam, char x[]) { // 2
    for (int i = 0; i < tam; i++) {
        if (strcmp(v[i].cliente, x) == 0) {
            return i;
        }
    }

    return -1;
}

void filtraDevedores(struct Conta vContas[], int tamConta, struct Conta vDevedores[], int *tamDevedores) { // 3
    *tamDevedores = 0;

    for (int i = 0; i < tamConta; i++) {
        if (vContas[i].saldo < 0) {
            vDevedores[*tamDevedores] = vContas[i];
            (*tamDevedores)++;
        }
    }
}

int realizarSaque(struct Conta vContas[], int tamConta, struct Operacao vOp[], int *tamOp) { // 4
    int usuarioId;
    double usuarioSaque;
    int pos;
    double saldoLimite;

    scanf("%d", &usuarioId);
    scanf("%lf", &usuarioSaque);

    pos = buscaId(vContas, tamConta, usuarioId);

    if (pos == -1) {
        return 0;
    }

    saldoLimite = vContas[pos].saldo + vContas[pos].limite;

    if (usuarioSaque > saldoLimite) {
        return 0;
    }

    vContas[pos].saldo -= usuarioSaque;

    if (*tamOp == 0) {
        vOp[*tamOp].id = 1;
    } else {
        vOp[*tamOp].id = vOp[*tamOp - 1].id + 1;
    }

    vOp[*tamOp].idConta = vContas[pos].id;
    vOp[*tamOp].tipo = 'S';
    vOp[*tamOp].valor = 0 - usuarioSaque;

    (*tamOp)++;

    return 1;
}

void extrato(struct Conta vContas[], int tamConta, struct Operacao vOp[], int *tamOp) { // 5
    int extratoId;
    int pos;
    int encontrados = 0;
    double saldo;
    int indices[5];
    double saldos[5];

    scanf("%d", &extratoId);

    pos = buscaId(vContas, tamConta, extratoId);

    if (pos == -1) {
        return;
    }

    printf("\n ID da conta: %d \n", extratoId);
    printf("\n Nome: %s\n", vContas[pos].cliente);

    saldo = vContas[pos].saldo;

    for (int i = *tamOp - 1; i >= 0 && encontrados < 5; i--) {
        if (vOp[i].idConta == extratoId) {
            indices[encontrados] = i;
            saldos[encontrados] = saldo;
            saldo -= vOp[i].valor;
            encontrados++;
        }
    }

    printf("\n Saldo anterior: %.2lf\n", saldo);

    for (int j = encontrados - 1; j >= 0; j--) {
        int i = indices[j];

        printf("\n ID: %d |", vOp[i].id);

        if (vOp[i].tipo == 'D') {
            printf(" Deposito | %.2lf C", vOp[i].valor);
        } else if (vOp[i].tipo == 'S') {
            printf(" Saque | %.2lf D", -vOp[i].valor);
        } else if (vOp[i].tipo == 'T') {
            printf(" Transferencia | %.2lf", vOp[i].valor);
        }

        printf(" | Saldo: %.2lf", saldos[j]);
    }

    printf("\n Saldo atual: %.2lf\n", vContas[pos].saldo);
}

/*
Correção da prova no papel:
1: 1,0
2: 1,2 
3: 1,9
4: 2,3
5: 0,8

Total: 7,2
*/