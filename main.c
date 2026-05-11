#include <stdio.h>
#include <stdlib.h>

void exibirMenu() {
    printf("\n---------------------------------\n");
    printf("   Caixa Eletronico do Biason \n");
    printf("---------------------------------\n");
    printf("Digite a opcao desejada:\n");
    printf("1 - Consultar seu saldo\n");
    printf("2 - Realizar um saque\n");
    printf("3 - Realizar um deposito\n");
    printf("4 - Sair\n");
    printf("---------------------------------\n");

}


int main() {

    int opcao;
    do {
        system("cls");
        exibirMenu();
        scanf("%d", &opcao);
        while (getchar() != '\n');

        if (opcao < 1 || opcao > 4) {
            printf("Opcao Invalida! Pressione Enter para tentar novamente...");
            getchar();
        }

    } while (opcao != 4);
    printf("Obrigado por usar nosso ATM! Atenciosamente, Banco Biason!!\n");
    return 0;

}