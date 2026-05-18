#include <stdio.h>
#include <stdlib.h>

void exibirMenu();
void consultarSaldo(float Saldo);
float realizarDeposito(float saldo);
float realizarSaque(float saldo);

void exibirMenu() {
    printf("\n=================================\n");
    printf("   CAIXA ELETRONICO DO BIASON    \n");
    printf("=================================\n");
    printf(" Digite a opcao desejada:\n");
    printf(" 1 - Consultar seu Saldo\n");
    printf(" 2 - Realizar um Saque\n");
    printf(" 3 - Realizar um Deposito\n");
    printf(" 4 - Sair\n");
    printf("=================================\n");
}

int main() {
    int opcao;
    float saldo = 0.0; 

    do {
        system("cls"); 
        exibirMenu();
        printf("Opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); 

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
            case 4:
                printf("\nObrigado por usar nosso ATM! Atenciosamente, Banco Biason!!\n");
                break;
            default:
                break;
        }

    } while (opcao != 4);

    return 0;
}


void consultarSaldo(float Saldo) {
    system("cls");
    printf("\n========= [ SALDO ATUAL ] =========\n");
    printf(" R$ %.2f\n", Saldo);
    printf("===================================\n");
    printf("\nPressione Enter para continuar...");
    getchar(); 
}

float realizarDeposito(float saldo) {
    system("cls");
    float valor;
    printf("========= [ DEPOSITO ] =========\n");
    printf("Digite o valor do deposito: R$ ");
    scanf("%f", &valor);
    while (getchar() != '\n');

    if (valor > 0) {
        saldo += valor;
        printf("\nDeposito realizado com sucesso!\n");
    } else {
        printf("\nValor invalido!\n");
    }
    
    printf("\nPressione Enter para continuar...");
    getchar();
    return saldo;
}

float realizarSaque(float saldo) {
    system("cls");
    float valor;
    printf("========= [ SAQUE ] =========\n");
    printf("Digite o valor do saque: R$ ");
    scanf("%f", &valor);
    while (getchar() != '\n'); 

    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        printf("\nSaque realizado com sucesso!\n");
    } else if (valor > saldo) {
        printf("\nSaldo insuficiente para realizar o saque!\n");
    } else {
        printf("\nValor invalido!\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
    return saldo;
}