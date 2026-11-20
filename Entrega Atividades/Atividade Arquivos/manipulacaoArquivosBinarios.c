#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define MAX_PRATOS 20
#define ARQ_PRATOS "pratos.bin"
#define ARQ_PEDIDOS "pedidos.bin"

struct Prato {
    int id;
    char nome[TAM_NOME];
    double preco;
};

struct Pedido {
    int id;
    char cliente[TAM_NOME];
    int idsPratos[MAX_PRATOS];
    int qtdPratos;
};

void lerStr(char str[], int tamMax);
int lerInteiro(char mensagem[]);
double lerReal(char mensagem[]);
int buscarPrato(int id, struct Prato *p);
int buscarPedido(int id, struct Pedido *p);
int pratoEmPedido(int idPrato);
void imprimirPrato(struct Prato p);
void imprimirPedido(struct Pedido p);
void cadastrarPrato();
void cadastrarPedido();
void consultarPrato();
void cardapio();
void consultarPedido();
void relatorioPedidos();
void atualizarPrato();
void atualizarPedido();
void excluirPrato();
void excluirPedido();

int main() {
    int opcao = -1;

    while (opcao != 0) {
        printf("\n===== SISTEMA RESTAURANTE =====\n");
        printf("1 - Cadastrar prato.\n");
        printf("2 - Cadastrar pedido.\n");
        printf("3 - Consultar prato por ID.\n");
        printf("4 - Cardápio.\n");
        printf("5 - Consultar pedido por ID.\n");
        printf("6 - Relatório de pedidos.\n");
        printf("7 - Atualizar prato.\n");
        printf("8 - Atualizar pedido.\n");
        printf("9 - Excluir prato.\n");
        printf("10 - Excluir pedido.\n");
        printf("0 - Sair.\n");
        opcao = lerInteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                cadastrarPrato();
                break;
            case 2:
                cadastrarPedido();
                break;
            case 3:
                consultarPrato();
                break;
            case 4:
                cardapio();
                break;
            case 5:
                consultarPedido();
                break;
            case 6:
                relatorioPedidos();
                break;
            case 7:
                atualizarPrato();
                break;
            case 8:
                atualizarPedido();
                break;
            case 9:
                excluirPrato();
                break;
            case 10:
                excluirPedido();
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    }
    return 0;
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

int lerInteiro(char mensagem[]) { // aceita apenas inteiros positivos
    int valor = -1;
    while (valor < 0) {
        printf("%s", mensagem);
        valor = -1;
        scanf("%d", &valor);
        getchar();
        if (valor < 0) {
            printf("Digite um número inteiro maior ou igual a zero.\n");
        }
    }
    return valor;
}

double lerReal(char mensagem[]) { // aceita apenas numeros positivos (double)
    double valor = -1;
    while (valor < 0) {
        printf("%s", mensagem);
        valor = -1;
        scanf("%lf", &valor);
        getchar();
        if (valor < 0) {
            printf("Digite um número maior ou igual a zero.\n");
        }
    }
    return valor;
}

int buscarPrato(int id, struct Prato *p) { // buscar prato recebendo id, retorna 1 se achar e 0 se não
    FILE *arq = fopen(ARQ_PRATOS, "rb"); // arqv pratos
    int status;
    if (arq == NULL) {
        return 0;
    }
    status = fread(p, sizeof(struct Prato), 1, arq);
    while (status == 1) {
        if ((*p).id == id) {
            fclose(arq);
            return 1;
        }
        status = fread(p, sizeof(struct Prato), 1, arq);
    }
    fclose(arq);
    return 0;
}

int buscarPedido(int id, struct Pedido *p) { // buscar pedido recebendo id, retorna 1 se achar e 0 se não
    FILE *arq = fopen(ARQ_PEDIDOS, "rb"); // arqv pedidos
    int status;
    if (arq == NULL) {
        return 0;
    }
    status = fread(p, sizeof(struct Pedido), 1, arq);
    while (status == 1) {
        if ((*p).id == id) {
            fclose(arq);
            return 1;
        }
        status = fread(p, sizeof(struct Pedido), 1, arq);
    }
    fclose(arq);
    return 0;
}

int pratoEmPedido(int idPrato) { // procura um id de prato dentro de todos os pedidos, retorna 1 se achar e 0 se não
    FILE *arq = fopen(ARQ_PEDIDOS, "rb");
    struct Pedido p;
    int i, status;
    if (arq == NULL) {
        return 0;
    }
    status = fread(&p, sizeof(struct Pedido), 1, arq);
    while (status == 1) {
        for (i = 0; i < p.qtdPratos; i += 1) {
            if (p.idsPratos[i] == idPrato) {
                fclose(arq);
                return 1;
            }
        }
        status = fread(&p, sizeof(struct Pedido), 1, arq);
    }
    fclose(arq);
    return 0;
}

void imprimirPrato(struct Prato p) {
    printf("ID: %d | Nome: %s | Preço: R$ %.2f.\n", p.id, p.nome, p.preco);
}

void imprimirPedido(struct Pedido p) {
    struct Prato prato;
    int i;
    double total = 0;
    printf("\nPedido %d | Cliente: %s.\n", p.id, p.cliente);
    for (i = 0; i < p.qtdPratos; i += 1) {
        if (buscarPrato(p.idsPratos[i], &prato)) { // mostra todos os pratos pedidos
            printf("  - %s: R$ %.2f.\n", prato.nome, prato.preco);
            total += prato.preco;
        } else {
            printf("  - Prato de ID %d não encontrado.\n", p.idsPratos[i]);
        }
    }
    printf("Total: R$ %.2f.\n", total);
}

void cadastrarPrato() {
    FILE *arq;
    struct Prato p, existente;
    int status;

    p.id = lerInteiro("Digite o ID do prato: ");
    if (buscarPrato(p.id, &existente)) {
        printf("Já existe um prato com esse ID.\n");
        return;
    }
    printf("Digite o nome do prato: ");
    lerStr(p.nome, TAM_NOME);
    p.preco = lerReal("Digite o preço do prato: ");

    arq = fopen(ARQ_PRATOS, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de pratos.\n");
        return;
    }
    status = fwrite(&p, sizeof(struct Prato), 1, arq);
    if (status == 1) {
        printf("Prato cadastrado com sucesso.\n");
    } else {
        printf("Erro ao gravar prato.\n");
    }
    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao fechar o arquivo.\n");
    }
}

void cadastrarPedido() {
    FILE *arq;
    struct Pedido p, existente;
    struct Prato prato;
    int i, id, status;

    p.id = lerInteiro("Digite o ID do pedido: ");
    if (buscarPedido(p.id, &existente)) {
        printf("Já existe um pedido com esse ID.\n");
        return;
    }
    printf("Digite o nome do cliente: ");
    lerStr(p.cliente, TAM_NOME);
    p.qtdPratos = lerInteiro("Digite a quantidade de pratos (1 a 20): ");
    if (p.qtdPratos < 1 || p.qtdPratos > MAX_PRATOS) {
        printf("Quantidade inválida.\n");
        return;
    }
    for (i = 0; i < p.qtdPratos; i += 1) {
        id = lerInteiro("Digite o ID do prato: ");
        if (!buscarPrato(id, &prato)) {
            printf("Prato não encontrado. Tente novamente.\n");
            i -= 1;
        } else {
            p.idsPratos[i] = id;
        }
    }
    arq = fopen(ARQ_PEDIDOS, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de pedidos.\n");
        return;
    }
    status = fwrite(&p, sizeof(struct Pedido), 1, arq);
    if (status == 1) {
        printf("Pedido cadastrado com sucesso.\n");
    } else {
        printf("Erro ao gravar pedido.\n");
    }
    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao fechar o arquivo.\n");
    }
}

void consultarPrato() {
    struct Prato p;
    int id = lerInteiro("Digite o ID do prato: ");
    if (buscarPrato(id, &p)) {
        imprimirPrato(p);
    } else {
        printf("Prato não encontrado.\n");
    }
}

void cardapio() {
    FILE *arq = fopen(ARQ_PRATOS, "rb");
    struct Prato p;
    int qtd = 0, status;
    if (arq == NULL) {
        printf("Arquivo de pratos não encontrado.\n");
        return;
    }
    printf("\n===== CARDÁPIO =====\n");
    status = fread(&p, sizeof(struct Prato), 1, arq);
    while (status == 1) {
        imprimirPrato(p);
        qtd += 1;
        status = fread(&p, sizeof(struct Prato), 1, arq);
    }
    if (qtd == 0) {
        printf("Nenhum prato cadastrado.\n");
    }
    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao fechar o arquivo.\n");
    }
}

void consultarPedido() {
    struct Pedido p;
    int id = lerInteiro("Digite o ID do pedido: ");
    if (buscarPedido(id, &p)) {
        imprimirPedido(p);
    } else {
        printf("Pedido não encontrado.\n");
    }
}

void relatorioPedidos() {
    FILE *arq = fopen(ARQ_PEDIDOS, "rb");
    struct Pedido p;
    int qtd = 0, status;
    if (arq == NULL) {
        printf("Arquivo de pedidos não encontrado.\n");
        return;
    }
    printf("\n===== RELATÓRIO DE PEDIDOS =====\n");
    status = fread(&p, sizeof(struct Pedido), 1, arq);
    while (status == 1) {
        imprimirPedido(p);
        qtd += 1;
        status = fread(&p, sizeof(struct Pedido), 1, arq);
    }
    if (qtd == 0) {
        printf("Nenhum pedido cadastrado.\n");
    }
    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao fechar o arquivo.\n");
    }
}

void atualizarPrato() {
    FILE *arq = fopen(ARQ_PRATOS, "r+b");
    struct Prato p;
    int id, status, encontrou = 0;
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de pratos.\n");
        return;
    }
    id = lerInteiro("Digite o ID do prato a atualizar: ");
    status = fread(&p, sizeof(struct Prato), 1, arq);
    while (status == 1) {
        if (p.id == id) {
            encontrou = 1;
            printf("Digite o novo nome do prato: ");
            lerStr(p.nome, TAM_NOME);
            p.preco = lerReal("Digite o novo preço: ");
            status = fseek(arq, -(long)sizeof(struct Prato), SEEK_CUR);
            if (status != 0) {
                printf("Erro ao posicionar no arquivo.\n");
                break;
            }
            status = fwrite(&p, sizeof(struct Prato), 1, arq);
            if (status == 1) {
                printf("Prato atualizado com sucesso.\n");
            } else {
                printf("Erro ao atualizar prato.\n");
            }
            break;
        }
        status = fread(&p, sizeof(struct Prato), 1, arq);
    }
    if (encontrou == 0) {
        printf("Prato não encontrado.\n");
    }
    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao fechar o arquivo.\n");
    }
}

void atualizarPedido() {
    FILE *arq = fopen(ARQ_PEDIDOS, "r+b");
    struct Pedido p;
    struct Prato prato;
    int id, i, idPrato, status, encontrou = 0;
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de pedidos.\n");
        return;
    }
    id = lerInteiro("Digite o ID do pedido a atualizar: ");
    status = fread(&p, sizeof(struct Pedido), 1, arq);
    while (status == 1) {
        if (p.id == id) {
            encontrou = 1;
            printf("Digite o novo nome do cliente: ");
            lerStr(p.cliente, TAM_NOME);
            p.qtdPratos = lerInteiro("Digite a nova quantidade de pratos (1 a 20): ");
            if (p.qtdPratos < 1 || p.qtdPratos > MAX_PRATOS) {
                printf("Quantidade inválida.\n");
                break;
            }
            for (i = 0; i < p.qtdPratos; i += 1) {
                idPrato = lerInteiro("Digite o ID do prato: ");
                if (!buscarPrato(idPrato, &prato)) {
                    printf("Prato não encontrado. Tente novamente.\n");
                    i -= 1;
                } else {
                    p.idsPratos[i] = idPrato;
                }
            }
            status = fseek(arq, -(long)sizeof(struct Pedido), SEEK_CUR);
            if (status != 0) {
                printf("Erro ao posicionar no arquivo.\n");
                break;
            }
            status = fwrite(&p, sizeof(struct Pedido), 1, arq);
            if (status == 1) {
                printf("Pedido atualizado com sucesso.\n");
            } else {
                printf("Erro ao atualizar pedido.\n");
            }
            break;
        }
        status = fread(&p, sizeof(struct Pedido), 1, arq);
    }
    if (encontrou == 0) {
        printf("Pedido não encontrado.\n");
    }
    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao fechar o arquivo.\n");
    }
}

void excluirPrato() {
    FILE *arq, *novo;
    struct Prato p;
    int id, status, encontrou = 0, erro = 0;
    id = lerInteiro("Digite o ID do prato a excluir: ");
    if (pratoEmPedido(id)) {
        printf("Não é possível excluir um prato associado a um pedido.\n");
        return;
    }
    arq = fopen(ARQ_PRATOS, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de pratos.\n");
        return;
    }
    novo = fopen("pratos_temp.bin", "wb");
    if (novo == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arq);
        return;
    }
    status = fread(&p, sizeof(struct Prato), 1, arq);
    while (status == 1) {
        if (p.id == id) {
            encontrou = 1;
        } else {
            if (fwrite(&p, sizeof(struct Prato), 1, novo) != 1) {
                erro = 1;
                break;
            }
        }
        status = fread(&p, sizeof(struct Prato), 1, arq);
    }
    if (erro == 0 && !feof(arq)) {
        erro = 1;
    }
    if (fclose(arq) != 0) {
        erro = 1;
    }
    if (fclose(novo) != 0) {
        erro = 1;
    }
    if (erro == 1) {
        remove("pratos_temp.bin");
        printf("Erro durante a exclusão do prato.\n");
        return;
    }
    if (encontrou == 0) {
        remove("pratos_temp.bin");
        printf("Prato não encontrado.\n");
        return;
    }
    if (remove(ARQ_PRATOS) != 0) {
        printf("Erro ao apagar o arquivo antigo.\n");
        remove("pratos_temp.bin");
        return;
    }
    if (rename("pratos_temp.bin", ARQ_PRATOS) != 0) {
        printf("Erro ao renomear o arquivo. Os registros estão em pratos_temp.bin.\n");
        return;
    }
    printf("Prato excluído com sucesso.\n");
}

void excluirPedido() {
    FILE *arq, *novo;
    struct Pedido p;
    int id, status, encontrou = 0, erro = 0;
    id = lerInteiro("Digite o ID do pedido a excluir: ");
    arq = fopen(ARQ_PEDIDOS, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de pedidos.\n");
        return;
    }
    novo = fopen("pedidos_temp.bin", "wb");
    if (novo == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arq);
        return;
    }
    status = fread(&p, sizeof(struct Pedido), 1, arq);
    while (status == 1) {
        if (p.id == id) {
            encontrou = 1;
        } else {
            if (fwrite(&p, sizeof(struct Pedido), 1, novo) != 1) {
                erro = 1;
                break;
            }
        }
        status = fread(&p, sizeof(struct Pedido), 1, arq);
    }
    if (erro == 0 && !feof(arq)) {
        erro = 1;
    }
    if (fclose(arq) != 0) {
        erro = 1;
    }
    if (fclose(novo) != 0) {
        erro = 1;
    }
    if (erro == 1) {
        remove("pedidos_temp.bin");
        printf("Erro durante a exclusão do pedido.\n");
        return;
    }
    if (encontrou == 0) {
        remove("pedidos_temp.bin");
        printf("Pedido não encontrado.\n");
        return;
    }
    if (remove(ARQ_PEDIDOS) != 0) {
        printf("Erro ao apagar o arquivo antigo.\n");
        remove("pedidos_temp.bin");
        return;
    }
    if (rename("pedidos_temp.bin", ARQ_PEDIDOS) != 0) {
        printf("Erro ao renomear o arquivo. Os registros estão em pedidos_temp.bin.\n");
        return;
    }
    printf("Pedido excluído com sucesso.\n");
}