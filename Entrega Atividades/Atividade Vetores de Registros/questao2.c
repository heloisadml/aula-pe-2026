#include <stdio.h>
#include <string.h>

#define TAM_DESC 100
#define TAM_PRODUTOS 40

struct Produto {
    int codigo;
    char desc[TAM_DESC];
    double valor;
    int quantEstoque;
};

void cadastrarProdutos(struct Produto v[], int n); // cadastrar todos os produtos VETOR
void cadastrarProduto(struct Produto *p); // cadastra todas informações do produto
void lerStr(char str[], int tamMax);

int buscaPorCodigo(struct Produto v[], int n); // busca ordem no vetor do produto de codigo igual a digitado

void alterarValor(struct Produto v[]); // recebe codigo e altera valor para desejado
void valorProduto(struct Produto v[]); // recebe codigo e printa valor
int estoqueProduto(struct Produto v[]); // recebe codigo e retorna quantidade em estoque

void venda(struct Produto v[]);
int confirmacaoCompra(double valor);

void atualizarEstoque(struct Produto v[]); // Um procedimento para, dado um código, atualizar a quantidade em estoque do produto;

void imprimirCodigoDesc(struct Produto v[], int n); // Um procedimento para exibir o código e a descrição de todos os produtos
void imprimirCodigoDescEstoqueZero(struct Produto v[], int n); // Um procedimento para exibir o código e a descrição de todos os produtos com estoque zero. 

int main() {
    struct Produto produtos[TAM_PRODUTOS];
    cadastrarProdutos(produtos, TAM_PRODUTOS); // (a)

    valorProduto(produtos); // (c)
    alterarValor(produtos); // (b)
    int quantEstoqueTeste = estoqueProduto(produtos); // (d)
    printf("Há %d unidades deste produto no estoque.\n", quantEstoqueTeste);

    venda(produtos); // (e)
    atualizarEstoque(produtos); // (f)

    imprimirCodigoDesc(produtos, TAM_PRODUTOS); // (g)
    imprimirCodigoDescEstoqueZero(produtos, TAM_PRODUTOS); // (h)

    return 0;
}

void cadastrarProdutos(struct Produto v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nDADOS DO PRODUTO [%d]\n", i + 1);
        cadastrarProduto(&v[i]);
    }
}

void cadastrarProduto(struct Produto *p) {
    printf("Digite código do produto:\n");
    scanf("%d", &(*p).codigo);

    getchar();
    printf("Digite descrição do produto:\n");
    lerStr((*p).desc, TAM_DESC);
    
    printf("Digite o valor do produto:\n");
    scanf("%lf", &(*p).valor);

    printf("Digite a quantidade no estoque deste produto:\n");
    scanf("%d", &(*p).quantEstoque);
    getchar(); // Limpa \n
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void alterarValor(struct Produto v[]) {
    printf("\n=== ALTERAR VALOR UNITÁRIO DE PRODUTO ===\n");
    int pos = buscaPorCodigo(v, TAM_PRODUTOS);

    if (pos == -1) {
        return;
    }

    printf("Digite valor novo para o produto:\n");
    scanf("%lf", &v[pos].valor);
}

int buscaPorCodigo(struct Produto v[], int n) { // vai pedir codigo para buscar dentro do vetor dos produtos, retorna posição
    int CodigoBusca;
    printf("Digite código do produto:\n");
    scanf("%d", &CodigoBusca);

    for (int i = 0; i < n; i++) {
        if (v[i].codigo == CodigoBusca) {
            return i;
        }
    }
    return -1;
}

void valorProduto(struct Produto v[]) {
    printf("\n=== VISUALIZAR VALOR UNITÁRIO DE PRODUTO ===\n");
    int pos = buscaPorCodigo(v, TAM_PRODUTOS);
    
    if (pos == -1) {
        return;
    }

    printf("O valor do produto deste código é: %lf\n", v[pos].valor);
}

int estoqueProduto(struct Produto v[]) {
    printf("\n=== VISUALIZAR QUANTIDADE ESTOQUE DE PRODUTO ===\n");
    int pos = buscaPorCodigo(v, TAM_PRODUTOS);
    
    if (pos == -1) {
        return 0;
    }

    return v[pos].quantEstoque;
}

void venda(struct Produto v[]) {
    int quantCompra; 
    double valorPagar;
    printf("\n=== PROCEDIMENTO DE VENDA ===\n");
    int pos = buscaPorCodigo(v, TAM_PRODUTOS);

    if (pos == -1) {
        return;
    }

    if (v[pos].quantEstoque == 0) {
        printf("Produto sem estoque.\n");
        return;
    }

    printf("Digite quantos deste produto deseja comprar:\n");
    scanf("%d", &quantCompra);

    if (quantCompra <= v[pos].quantEstoque) {
        valorPagar = quantCompra * v[pos].valor;
        v[pos].quantEstoque -= quantCompra;
        if (!confirmacaoCompra(valorPagar)) {
            v[pos].quantEstoque += quantCompra;
        }
    } else {
        printf("\nNão há essa quantidade no estoque, há apenas %d produtos.\n", v[pos].quantEstoque);
    }
}

int confirmacaoCompra(double valor) {
    char confirmacao;
    printf("\nO valor a pagar é %lf reais\n", valor);
    printf("\nDeseja efetivar a compra? Sim: Y. Não: N.\n");
    scanf(" %c", &confirmacao);

    if (confirmacao == 'Y') {
        printf("\nCompra confirmada.\n");
        return 1;
    } else {
        printf("\nCompra não confirmada.\n");
        return 0;
    }
}

void atualizarEstoque(struct Produto v[]) {
    int quantAdicionar;
    printf("\n=== ATUALIZAR ESTOQUE ===\n");
    int pos = buscaPorCodigo(v, TAM_PRODUTOS);

    if (pos == -1) {
        return;
    }

    printf("\nEste produto tem %d unidades no estoque, digite valor a adicionar:\n", v[pos].quantEstoque);
    scanf("%d", &quantAdicionar);

    v[pos].quantEstoque += quantAdicionar;
}

void imprimirCodigoDesc(struct Produto v[], int n) {
    printf("\n=== IMPRESSÃO DE CÓDIGOS E DESCRIÇÕES ===\n");
    for (int i = 0; i < n; i++) {
        printf("CÓDIGO: %d\n", v[i].codigo);
        printf("DESCRIÇÃO: '%s'\n", v[i].desc);
        printf("\n===============================\n");
    } 
}

void imprimirCodigoDescEstoqueZero(struct Produto v[], int n) {
    printf("\n=== IMPRESSÃO DE PRODUTOS SEM ESTOQUE ===\n");
    for (int i = 0; i < n; i++) {
        if (v[i].quantEstoque == 0) {
            printf("CÓDIGO: %d\n", v[i].codigo);
            printf("DESCRIÇÃO: '%s'\n", v[i].desc);
            printf("\n===============================\n");
        }
    }
}