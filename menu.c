/*
 |===========================================================================|
 |                             SIG-MASSAGE                                   |
 |        Um Sistema de Gestão para Serviços de Massagens Terapêuticas       |
 |===========================================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

void Pausar() {
    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}


int main() {
    int opcao;
    
    do {
        exibirMenuPrincipal();
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            
            case 1: cliente(); break;
                
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
                Pausar();
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
                Pausar();
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
                Pausar();
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
                Pausar();
                break;
            
            case 6:
                system("clear || cls");
                printf("\n╔══════════════════════════════════════════════════╗\n");
                printf("║               SOBRE O SIG-MASSAGE                ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║                                                  ║\n");
                printf("║ O SIG-MASSAGE é um sistema desenvolvido para     ║\n");
                printf("║ auxiliar no gerenciamento de atendimentos de     ║\n");
                printf("║ massagem terapêutica. Ele foi pensado para       ║\n");
                printf("║ oferecer praticidade e organização, permitindo   ║\n");
                printf("║ o cadastro de clientes, controle de sessões,     ║\n");
                printf("║ agenda de horários e relatórios de atividades.   ║\n");
                printf("║                                                  ║\n");
                printf("║ Com o SIG-MASSAGE, o profissional pode manter    ║\n");
                printf("║ seus atendimentos de forma estruturada,          ║\n");
                printf("║ proporcionando um serviço mais eficiente e       ║\n");
                printf("║ focado no bem-estar dos clientes.                ║\n");
                printf("║                                                  ║\n");
                printf("╚══════════════════════════════════════════════════╝\n");
                Pausar();
                break;

            case 7:
                system("clear || cls");
                printf("\n╔══════════════════════════════════════════════════╗\n");
                printf("║                  EQUIPE SIG-MASSAGE              ║\n");
                printf("╠══════════════════════════════════════════════════╣\n");
                printf("║                                                  ║\n");
                printf("║   Desenvolvedores:                               ║\n");
                printf("║      • Felipe Eduardo Silva Fernandes            ║\n");
                printf("║      • Elisson Tavares                           ║\n");
                printf("║                                                  ║\n");
                printf("║   Contato:                                       ║\n");
                printf("║      • felipe.fernandes.710@ufrn.edu.br          ║\n");
                printf("║      • elisson.tavares.dev@gmail.com             ║\n");
                printf("║                                                  ║\n");
                printf("╚══════════════════════════════════════════════════╝\n");
                Pausar();
                break;
                
            case 0:
                exibirMensagemSaida();
                break;
                
            default:
                printf("\n Opção inválida! Por favor, tente novamente.\n");
                Pausar();
        }
    } while(opcao != 0);
    
    return 0;
    
}
