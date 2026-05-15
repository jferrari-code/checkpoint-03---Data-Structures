#include <stdio.h>
#include <stdlib.h>

void exibirMenu() {
    printf("\n---------------------------------\n");
    printf("   Caixa Eletronico do Biason \n");
    printf("---------------------------------\n");
    printf("Digite a opcao desejada:\n");
    printf("1 - Consultar seu Saldo\n");
    printf("2 - Realizar um Saque\n");
    printf("3 - Realizar um Deposito\n");
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

    system("cls");
    printf("Saldo: R$ %.2f\n", saldo);
     printf("\nPressione Enter para continuar...");
    setbuf(stdin, NULL);
    getchar();
}

void consultarSaldo(float Saldo) {
printf("\n--- Saldo atual ---\n");
printf("R$ %.2f\n", Saldo);
printf("-------------------\n");
system("pause");
}

float realizarDeposito(float saldo) {
float valor;
printf("Digite o valor do deposito: ");
scanf("%f", &valor);
if (valor > 0) {
saldo += valor;
printf("Deposito realizado!\n");
} else {
printf("Valor invalido!\n");
}
return saldo;

int main() {
    int opcao;

switch(opcao) {
case 1:
consultarSaldo(saldo);
break;
case 2:
saldo = realizarSaque(saldo);
break;
case 3:
saldo = realizarDeposito(saldo);
break;
case 0:
printf("Saindo...\n");
break;
}
}
}


