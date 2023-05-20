#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Assinatura da função.
void cadastro();
void remover();
void decisaocontinuar();
//Armazem: estrutura global a onde serão armazenado os objetos, como os nomes e a quantidade.
struct armazem
{
    char produto[5000][200];
    int qtdestoque[5000][1];
    int indice[5000][1];
};
//Variaveis globais.
int options;

//Preenchimento do indice.
void indice(){
    struct armazem arm;
    memset(arm.indice,0,sizeof(arm.indice));

    for(int i = 0; i < 5000; i++){
        arm.indice[i][0] = i;
    }
}

//Função principal a onde esta localizado as opções.
int main/*opções*/(){
    options = 0;
    printf("Opcoes de gerenciamento: ");
        printf("\n1 - Cadastrar produtos.");
        printf("\n2 - Remover produtos.");
        printf("\n3 - Listar produtos.");
        printf("\n4 - Conferir produtos.");
        printf("\n5 - Sair.");

    int option;
    printf("\nSelecione uma opcao: ");
    scanf("%i",&option);

        if(option == 1){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n1 - Cadastrar produtos.");
            printf("\n");
                options = 1;
            cadastro(&options);
        }else if (option == 2){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n2 - Remover produtos.");
            printf("\n");
                options = 2;
            remover(&options);
        }else if (option == 3){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n3 - Listar produtos.");
            printf("\n");
                options = 3;
        }else if(option == 4){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n4 - Conferir produtos.");
            printf("\n");
                options = 4;
        }else if(option == 5){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n5 - Sair.");
            printf("\n");
                exit(0);
        }else{
            printf("Nenhuma opcao selecionada.");
        }

    return 0;

}
//Decisaocontinuar: um texto que sera exibido apos o processamento das outras funcoes.
void decisaocontinuar(){
    options = 0;
    printf("\n");
    printf("Deseja continuar a gerenciar o estoque? ");
        printf("\n1 - Sim.");
        printf("\n2 - Não.");
    printf("\nSelecione uma opcao: ");
    scanf("%i",&options);

    if(options == 1){
        printf("\n");
        main();
    }else if(options == 2){
        exit(0);
    }
}
//Cadastro: sera realizado o cadastro dos nomes dos objetos e quantidade de cada um.
void cadastro(){
    struct armazem arm;
    int qtd;

    if(options == 1){
        printf("\nQuantos produtos deseja cadastrar? ");
        scanf("%i",&qtd);

        for(int l=0;l<qtd;l++){
                printf("Produto: ");
                scanf(" %s", arm.produto[l]);

                printf("Quantidade: ");
                scanf("%i", arm.qtdestoque[l]);
        }
    decisaocontinuar();
    }


}

//Remove: sera realizado a remoção de objetos do array.
void remover(){
    struct armazem arm;
    char produto[200];
    int options = -10, qtd, pos;

        if(options == 2){
            printf("Deseja remover qual produto? ");
            scanf(" %s", produto);

            for(int l=0;l<5000;l++){
                options = strcmp(produto, arm.produto[l]);
                if(options==0){
                    pos = l;
                    break;
                }
            }
            if(options == -10){
                printf("\n");
                printf("Produto nao encontrado.");
                printf("\n");
            }
        }

            qtd = 0;
            if(options == 0){
                printf("Produto encontrado.\n");
                printf("Qual a quantidade que deseja remover? ");
                scanf("%i", &qtd);
                if(qtd != 0){
                    arm.qtdestoque[pos][0] -= qtd;
                }
            }
    decisaocontinuar();
}