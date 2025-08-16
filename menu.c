#include <stdio.h>
#include <stdlib.h>

void pausar() {
    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}

int main() {
    int opcao;
    
    do {
        system("clear || cls");
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
                system("clear || cls");
                printf("\n╔══════════════════════════════════════════════════╗\n");
                printf("║ MÓDULO EM DESENVOLVIMENTO                        ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║                                                  ║\n");
                printf("║ O módulo CLIENTES está em desenvolvimento        ║\n");
                printf("║ e estará disponível em breve!                    ║\n");
                printf("║                                                  ║\n");
                printf("║ Aguarde as próximas atualizações do sistema.     ║\n");
                printf("║                                                  ║\n");
                printf("╚══════════════════════════════════════════════════╝\n");
                pausar();
                break;
                
            case 2:
                system("clear || cls");
                printf("\n╔══════════════════════════════════════════════════╗\n");
                printf("║ MÓDULO EM DESENVOLVIMENTO                        ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║                                                  ║\n");
                printf("║ O módulo MASSOTERAPEUTAS está em                 ║\n");
                printf("║ desenvolvimento e estará disponível em breve!    ║\n");
                printf("║                                                  ║\n");
                printf("║ Aguarde as próximas atualizações do sistema.     ║\n");
                printf("║                                                  ║\n");
                printf("╚══════════════════════════════════════════════════╝\n");
                pausar();
                break;
                
            case 3:
                system("clear || cls");
                printf("\n╔══════════════════════════════════════════════════╗\n");
                printf("║ MÓDULO EM DESENVOLVIMENTO                        ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║                                                  ║\n");
                printf("║ O módulo SERVIÇOS está em desenvolvimento        ║\n");
                printf("║ e estará disponível em breve!                    ║\n");
                printf("║                                                  ║\n");
                printf("║ Aguarde as próximas atualizações do sistema.     ║\n");
                printf("║                                                  ║\n");
                printf("╚══════════════════════════════════════════════════╝\n");
                pausar();
                break;
                
            case 4:
                system("clear || cls");
                printf("\n╔══════════════════════════════════════════════════╗\n");
                printf("║ MÓDULO EM DESENVOLVIMENTO                        ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║                                                  ║\n");
                printf("║ O módulo AGENDAMENTOS está em                    ║\n");
                printf("║ desenvolvimento e estará disponível em breve!    ║\n");
                printf("║                                                  ║\n");
                printf("║ Aguarde as próximas atualizações do sistema.     ║\n");
                printf("║                                                  ║\n");
                printf("╚══════════════════════════════════════════════════╝\n");
                pausar();
                break;
                
            case 5:
                system("clear || cls");
                printf("\n╔══════════════════════════════════════════════════╗\n");
                printf("║ MÓDULO EM DESENVOLVIMENTO                        ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║                                                  ║\n");
                printf("║ O módulo RELATÓRIOS está em desenvolvimento      ║\n");
                printf("║ e estará disponível em breve!                    ║\n");
                printf("║                                                  ║\n");
                printf("║ Aguarde as próximas atualizações do sistema.     ║\n");
                printf("║                                                  ║\n");
                printf("╚══════════════════════════════════════════════════╝\n");
                pausar();
                break;
                
            case 0:
                system("clear || cls");
                printf("\n╔════════════════════════════════════════════════════╗\n");
                printf("║ OBRIGADO POR USAR O SIG-MASSAGE                    ║\n");
                printf("╠════════════════════════════════════════════════════╣\n");
                printf("║                                                    ║\n");
                printf("║ Sistema encerrado com sucesso!                     ║\n");
                printf("║                                                    ║\n");
                printf("║ Esperamos que o SIG-Massage tenha                  ║\n");
                printf("║ facilitado a gestão da sua clínica.                ║\n");
                printf("║                                                    ║\n");
                printf("║ Continue cuidando do bem-estar dos seus            ║\n");
                printf("║ clientes com excelência!                           ║\n");
                printf("║                                                    ║\n");
                printf("║ Até logo!                                          ║\n");
                printf("║                                                    ║\n");
                printf("╚════════════════════════════════════════════════════╝\n");
                break;
                
            default:
                printf("\n Opção inválida! Por favor, tente novamente.\n");
                pausar();
        }
    } while(opcao != 0);
    
    return 0;
}
