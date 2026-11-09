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
void alterarValor(struct Produto v[], int n); // recebe codigo e altera valor para desejado
double valorProduto(struct Produto p); // recebe codigo e retorna valor
int estoqueProduto(struct Produto p); // recebe codigo e retorna quantidade em estoque
// até a e

int main() {
    struct Produto produtos[TAM_PRODUTOS];
    cadastrarProdutos(produtos, TAM_PRODUTOS);

    return 0;
}

void cadastrarProdutos(struct Produto v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n=== DADOS DO PRODUTO [%d] ===\n", i + 1);
        cadastrarProduto(&v[i]);
    }
}

void cadastrarProduto(struct Produto *p) {
    printf("Digite código do produto:\n");
    scanf("%d", &(*p).codigo);

    char tmp[TAM_DESC];
    printf("Digite descrição do produto:\n");
    lerStr((*p).desc, TAM_DESC);
    
    printf("Digite o valor do produto:\n");
    scanf("%lf", &(*p).valor);

    printf("Digite a quantidade no estoque deste produto:\n");
    scanf("%d", &(*p).quantEstoque);
    lerStr(tmp, TAM_DESC); // Limpa \n
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void alterarValor(struct Produto v[], int n) { ///////////
    printf("\n=== ALTERAR VALOR UNITÁRIO DE PRODUTO ===\n");
    buscaPorCodigo() 
}

int buscaPorCodigo(struct Produto v[], int n) { /////////////
    int CodigoBusca;
    printf("Digite código do produto:\n");
    scanf("%d", &CodigoBusca);

    for (int i = 0; i < n; i++) {
        if (v[i].codigo == CodigoBusca) {
            return i;
        }
    }
}

/* 
A papelaria Escolar deseja automatizar o cadastro dos produtos
comercializados por ela. Faça o programa que irá realizar essa tarefa. O cadastro de
produtos deve ser implementado utilizando um vetor de 40 registros (estruturas). Sobre
cada produto deve-se manter as seguintes informações: código, descrição, valor unitário e
quantidade em estoque. O programa deverá apresentar os seguintes sub-programas:

(a) Um procedimento para cadastrar um novo produto;
(b) Um procedimento que, dado um código, permita alterar seu valor unitário;
(c) Uma função que, dado um código, informe o valor unitário do produto;
(d) Uma função que, dado um código, informe a quantidade em estoque do produto;
(e) Um procedimento de venda que, dado o código e a quantidade desejada, e caso
a quantidade exista no estoque, subtrai a quantidade vendida da quantidade
existente e informa o valor a ser pago. OBS1: Caso o produto esteja com estoque
zero, o procedimento de informar ao usuário. OBS2: Caso a quantidade desejada
seja inferior a quantidade existente o procedimento deve perguntar ao usuário se
deseja efetivar a compra. Caso afirmativo, o programa deve zerar o estoque e
informar o valor a ser pago.
(f) Um procedimento para, dado um código, atualizar a quantidade em estoque do
produto;
(g) Um procedimento para exibir o código e a descrição de todos os produtos;
(h) Um procedimento para exibir o código e a descrição de todos os produtos com
estoque zero. 

*/

