#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Assinatura da função
void cadastro(int *verifi);
void remover(int *verifi);
void decisaocontinuar();

//Armazem: estrutura global a onde serão armazenado os objetos, como os nomes e a quantidade
struct armazem
{
    char produto[5000][200];
    int qtdestoque[5000][1];
    int indice[5000][1];
};
//Variaveis globais
int options;

//Preenchimento do indice
void indice(){
    struct armazem arm;
    memset(arm.indice,0,sizeof(arm.indice));

    for(int i = 0; i < 5000; i++){
        arm.indice[i][0] = i;
    }
}
//Função principal a onde esta localizado as opções
int main(){

    printf("Opcoes de gerenciamento: ");
        printf("\n1 - Cadastrar produtos.");
        printf("\n2 - Remover produtos.");
        printf("\n3 - Listar produtos.");
        printf("\n4 - Conferir produtos.");
        printf("\n5 - Sair.");

    int option;
    printf("\nSelecione uma opcao: ");
    scanf("%i",&option);

        int verified;
        if(option == 1){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n1 - Cadastrar produtos.");
            printf("\n");
                verified = 1;
        }else if (option == 2){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n2 - Remover produtos.");
            printf("\n");
                verified = 2;
        }else if (option == 3){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n3 - Listar produtos.");
            printf("\n");
                verified = 3;
        }else if(option == 4){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n4 - Conferir produtos.");
            printf("\n");
                verified = 4;
        }else if(option == 5){
            printf("\n");
            printf("opcao selecionada: ");
            printf("\n5 - Sair.");
            printf("\n");
                verified = 5;
        }else{
            printf("Nenhuma opcao selecionada.");
        }

    cadastro(&verified);
    remover(&verified);
    return 0;

}

void decisaocontinuar(){
    printf("Deseja continuar a gerenciar o estoque? ");
        printf("\n1 - Sim.");
        printf("\n2 - Não.");
    printf("\nSelecione uma opcao: ");
    scanf("%i",&options);

    if(options == 1){
        main();
    }
}

//Cadastro: sera realizado o cadastro dos nomes dos objetos e quantidade de cada um.
void cadastro(int *verifi){
    struct armazem arm;
    if(*verifi == 1){
        printf("\n");
        int qtd;
        
        printf("\nQuantos produtos deseja cadastrar? ");
        scanf("%i",&qtd);

        for(int l=0;l<qtd;l++){
                printf("Produto: ");
                scanf("%s", arm.produto[l]);

                printf("Quantidade: ");
                scanf("%i", arm.qtdestoque[l]);
        }
    decisaocontinuar();
    }


}

//Remove: sera realizado a remoção de objetos do array
void remover(int *verifi){
    struct armazem arm;
    char produto[200];
    int verified, qtd, pos;
        if(*verifi == 2){
            printf("Deseja remover qual produto? ");
            scanf("%s", produto);

            for(int l=0;l<5000;l++){
                verified = strcmp(produto, arm.produto[l]);
                if(verified==0){
                    pos = l;
                    break;
                }
            }
        }

            qtd = 0;
            if(verified == 0){
                printf("Produto encontrado.\n");
                printf("Qual a quantidade que deseja remover? ");
                scanf("%i", &qtd);
                if(qtd != 0){
                    arm.qtdestoque[pos][0] -= qtd;
                }
            }
    decisaocontinuar();
}