#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Assinatura da função
void cadastro(int *verifi);
//Armazem: estrutura global a onde serão armazenado os objetos, como os nomes e a quantidade
struct armazem
{
    char produto[5000][200];
    int qtdestoque[5000][1];
};
//Função principal a onde esta localizado as opções
int main(){

    printf("Opções de gerenciamento: ");
        printf("\n1 - Cadastrar produtos");
        printf("\n2 - Remover produtos");
        printf("\n3 - Listar produtos");
        printf("\n4 - Conferir produtos");
        printf("\n5 - Sair");

    int option;
    printf("\n");
    scanf("%i",&option);

        int verified;
        if(option == 1){
            printf("Opção selecionada: ");
            printf("\n1 - Cadastrar produtos");
                verified = 1;
        }else if (option == 2){
            printf("Opção selecionada: ");
            printf("\n2 - Remover produtos");
                verified = 2;
        }else if (option == 3){
            printf("Opção selecionada: ");
            printf("\n3 - Listar produtos");
                verified = 3;
        }else if(option == 4){
            printf("Opção selecionada: ");
            printf("\n4 - Conferir produtos");
                verified = 4;
        }else{
            printf("Nenhuma opção selecionada: ");
        }

    cadastro(&verified);
    return 0;

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

                printf("Quantidade: \n");
                scanf("%i", arm.qtdestoque[l]);
        }
    }


}