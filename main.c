#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUTOS 5000
#define TAM_NOME 200

typedef struct {
    char produto[TAM_NOME];
    int qtdestoque;
} Produto;

typedef struct {
    Produto produtos[MAX_PRODUTOS];
    int contador;
} Armazem;

void cadastrarProduto(Armazem *armazem) {
    if (armazem->contador >= MAX_PRODUTOS) {
        printf("O armazem esta cheio. Nao e possivel cadastrar mais produtos.\n");
        return;
    }

    Produto novoProduto;

    printf("Produto: ");
    scanf(" %s", novoProduto.produto);

    printf("Quantidade: ");
    scanf("%i", &novoProduto.qtdestoque);

    armazem->produtos[armazem->contador] = novoProduto;
    armazem->contador++;

    printf("Produto cadastrado com sucesso.\n");
}

void removerProduto(Armazem *armazem) {
    if (armazem->contador == 0) {
        printf("O armazem esta vazio. Nao ha produtos para remover.\n");
        return;
    }

    char nome[TAM_NOME];
    printf("Qual produto deseja remover? ");
    scanf(" %s", nome);

    for (int i = 0; i < armazem->contador; i++) {
        if (strcmp(nome, armazem->produtos[i].produto) == 0) {
            int quantidade;
            printf("Produto encontrado. Quantidade a remover: ");
            scanf("%i", &quantidade);

            if (quantidade <= armazem->produtos[i].qtdestoque) {
                armazem->produtos[i].qtdestoque -= quantidade;
                printf("Produto removido com sucesso.\n");
            } else {
                printf("Nao ha quantidade suficiente para remover.\n");
            }

            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

void listarProdutos(const Armazem *armazem) {
    if (armazem->contador == 0) {
        printf("O armazem esta vazio. Nao ha produtos para listar.\n");
        return;
    }

    printf("Produtos no armazem:\n");

    for (int i = 0; i < armazem->contador; i++) {
        printf("%d - %s (%d)\n", i + 1, armazem->produtos[i].produto, armazem->produtos[i].qtdestoque);
    }
}

void conferirProdutos(const Armazem *armazem) {
    if (armazem->contador == 0) {
        printf("O armazem esta vazio. Nao ha produtos para conferir.\n");
        return;
    }

    printf("Informe o numero do produto para conferir: ");
    int numero;
    scanf("%d", &numero);

    if (numero >= 1 && numero <= armazem->contador) {
        const Produto *produto = &armazem->produtos[numero - 1];
        printf("Produto: %s\nQuantidade em estoque: %d\n", produto->produto, produto->qtdestoque);
    } else {
        printf("Numero de produto invalido.\n");
    }
}

int main() {
    Armazem armazem;
    armazem.contador = 0;

    while (true) {
        printf("\nOpcoes de gerenciamento:\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Remover produtos\n");
        printf("3 - Listar produtos\n");
        printf("4 - Conferir produtos\n");
        printf("5 - Sair\n");
        printf("Selecione uma opcao: ");

        int opcao;
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
                printf("\nOpcao selecionada: Cadastrar produtos\n");
                cadastrarProduto(&armazem);
                break;
            case 2:
                printf("\nOpcao selecionada: Remover produtos\n");
                removerProduto(&armazem);
                break;
            case 3:
                printf("\nOpcao selecionada: Listar produtos\n");
                listarProdutos(&armazem);
                break;
            case 4:
                printf("\nOpcao selecionada: Conferir produtos\n");
                conferirProdutos(&armazem);
                break;
            case 5:
                printf("\nOpcao selecionada: Sair\n");
                exit(0);
                break;
            default:
                printf("Nenhuma opcao selecionada.\n");
                break;
        }
    }

    return 0;
}
