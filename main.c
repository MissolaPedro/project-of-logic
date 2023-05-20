#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct armazem
{
    char produto[5000][200];
    int qtdestoque[5000][1];
    int indice[5000][1];
};

void indice()
{
    struct armazem arm;
    memset(arm.indice, 0, sizeof(arm.indice));

    for (int i = 0; i < 5000; i++)
    {
        arm.indice[i][0] = i;
    }
}

void decisaocontinuar();

void cadastro()
{
    struct armazem arm;
    int qtd;

    printf("\nQuantos produtos deseja cadastrar? ");
    scanf("%i", &qtd);

    for (int l = 0; l < qtd; l++)
    {
        printf("Produto: ");
        scanf(" %s", arm.produto[l]);

        printf("Quantidade: ");
        scanf("%i", &arm.qtdestoque[l][0]);
    }

    decisaocontinuar();
}

void remover()
{
    struct armazem arm;
    char produto[200];
    int options = -10, qtd, pos;

    printf("Deseja remover qual produto? ");
    scanf(" %s", produto);

    for (int l = 0; l < 5000; l++)
    {
        options = strcmp(produto, arm.produto[l]);
        if (options == 0)
        {
            pos = l;
            break;
        }
    }

    if (options == -10)
    {
        printf("\n");
        printf("Produto nao encontrado.");
        printf("\n");
    }
    else if (options == 0)
    {
        printf("Produto encontrado.\n");
        printf("Qual a quantidade que deseja remover? ");
        scanf("%i", &qtd);
        if (qtd != 0)
        {
            arm.qtdestoque[pos][0] -= qtd;
        }
    }

    decisaocontinuar();
}

void decisaocontinuar()
{
    int options;
    printf("\n");
    printf("Deseja continuar a gerenciar o estoque? ");
    printf("\n1 - Sim.");
    printf("\n2 - Nao.");
    printf("\nSelecione uma opcao: ");
    scanf("%i", &options);

    if (options == 1)
    {
        printf("\n");
        return; // Retorna para a função chamadora (cadastro ou remover)
    }
    else if (options == 2)
    {
        exit(0);
    }
}

int main()
{
    while (true)
    {
        int option;
        printf("Opcoes de gerenciamento: ");
        printf("\n1 - Cadastrar produtos.");
        printf("\n2 - Remover produtos.");
        printf("\n3 - Listar produtos.");
        printf("\n4 - Conferir produtos.");
        printf("\n5 - Sair.");

        printf("\nSelecione uma opcao: ");
        scanf("%i", &option);

        switch (option)
        {
        case 1:
            printf("\n");
            printf("Opcao selecionada: ");
            printf("\n1 - Cadastrar produtos.");
            printf("\n");
            cadastro();
            break;
        case 2:
            printf("\n");
            printf("Opcao selecionada: ");
            printf("\n2 - Remover produtos.");
            printf("\n");
            remover();
            break;
        case 3:
            printf("\n");
            printf("Opcao selecionada: ");
            printf("\n3 - Listar produtos.");
            printf("\n");
            // Implemente a funcionalidade de listar produtos
            break;
        case 4:
            printf("\n");
            printf("Opcao selecionada: ");
            printf("\n4 - Conferir produtos.");
            printf("\n");
            // Implemente a funcionalidade de conferir produtos
            break;
        case 5:
            printf("\n");
            printf("Opcao selecionada: ");
            printf("\n5 - Sair.");
            printf("\n");
            exit(0);
            break;
        default:
            printf("Nenhuma opcao selecionada.\n");
            break;
        }
    }

    return 0;
}
