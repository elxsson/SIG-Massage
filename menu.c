#include <stdio.h>

int main() {
    int opcao;

    printf("\n╔══════════════════════════════════════════════════╗\n");
    printf("║ SIG-MASSAGE - SISTEMA DE GESTÃO DE MASSAGENS     ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║                                                  ║\n");
    printf("║ ► 1. Módulo Clientes                             ║\n");
    printf("║ ► 2. Módulo Massoterapeutas                      ║\n");
    printf("║ ► 3. Módulo Serviços                             ║\n");
    printf("║ ► 4. Módulo Agendamentos                         ║\n");
    printf("║ ► 5. Módulo Relatórios                           ║\n");
    printf("║ ► 0. Sair do Sistema                             ║\n");
    printf("║                                                  ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");

    printf("\n Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("\nVocê escolheu o módulo CLIENTES.\n");
            break;
        case 2:
            printf("\nVocê escolheu o módulo MASSOTERAPEUTAS.\n");
            break;
        case 3:
            printf("\nVocê escolheu o módulo SERVIÇOS.\n");
            break;
        case 4:
            printf("\nVocê escolheu o módulo AGENDAMENTOS.\n");
            break;
        case 5:
            printf("\nVocê escolheu o módulo RELATÓRIOS.\n");
            break;
        case 0:
            printf("\nSaindo do sistema...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
    }

    return 0;
}
