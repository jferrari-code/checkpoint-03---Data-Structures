#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

void exibirMenu();
void consultarSaldo(float saldo);
float realizarDeposito(float saldo);
float realizarSaque(float saldo);
void pausarTela();
void limparBuffer();

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

void limparBuffer() {
    while (getchar() != '\n');
}

void pausarTela() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

int main() {
    int opcao;
    float saldo = 0.0;

    do {
        system(LIMPAR_TELA);
        exibirMenu();

        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("\nOpcao invalida! Digite apenas numeros.\n");
            pausarTela();
            continue;
        }

        limparBuffer();

        switch (opcao) {
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
                printf("\nOpcao invalida! Tente novamente.\n");
                pausarTela();
                break;
        }

    } while (opcao != 4);

    return 0;
}

void consultarSaldo(float saldo) {
    system(LIMPAR_TELA);
    printf("\n========= [ SALDO ATUAL ] =========\n");
    printf(" R$ %.2f\n", saldo);
    printf("===================================\n");
    pausarTela();
}

float realizarDeposito(float saldo) {
    system(LIMPAR_TELA);

    float valor;

    printf("========= [ DEPOSITO ] =========\n");
    printf("Digite o valor do deposito: R$ ");

    if (scanf("%f", &valor) != 1) {
        limparBuffer();
        printf("\nValor invalido!\n");
        pausarTela();
        return saldo;
    }

    limparBuffer();

    if (valor > 0) {
        saldo += valor;
        printf("\nDeposito realizado com sucesso!\n");
        printf("Saldo atual: R$ %.2f\n", saldo);
    } else {
        printf("\nValor invalido!\n");
    }

    pausarTela();
    return saldo;
}

float realizarSaque(float saldo) {
    system(LIMPAR_TELA);

    float valor;

    printf("========= [ SAQUE ] =========\n");
    printf("Digite o valor do saque: R$ ");

    if (scanf("%f", &valor) != 1) {
        limparBuffer();
        printf("\nValor invalido!\n");
        pausarTela();
        return saldo;
    }

    limparBuffer();

    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        printf("\nSaque realizado com sucesso!\n");
        printf("Saldo atual: R$ %.2f\n", saldo);
    } else if (valor > saldo) {
        printf("\nSaldo insuficiente para realizar o saque!\n");
    } else {
        printf("\nValor invalido!\n");
    }

    pausarTela();
    return saldo;
}