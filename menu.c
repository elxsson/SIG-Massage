/*
 |===========================================================================|
 |                             SIG-MASSAGE                                   |
 |        Um Sistema de Gestão para Serviços de Massagens Terapêuticas       |
 |===========================================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "massoterapeutas.h"
#include "agendamentos.c"
#include "utils.h"

int main() {
    int opcao;
    
    do {
        limparTela();
        printf("\n╔══════════════════════════════════════════════════╗\n");
        printf("║ SIG-MASSAGE - SISTEMA DE GESTÃO DE MASSAGENS     ║\n");
        printf("╠══════════════════════════════════════════════════╣\n");
        printf("║                                                  ║\n");
        printf("║ ► 1. Módulo Clientes                             ║\n");
        printf("║ ► 2. Módulo Massoterapeutas                      ║\n");
        printf("║ ► 3. Módulo Serviços                             ║\n");
        printf("║ ► 4. Módulo Agendamentos                         ║\n");
        printf("║ ► 5. Módulo Relatórios                           ║\n");
        printf("║ ► 6. Sobre o SIG-MASSAGE                         ║\n");
        printf("║ ► 7. Equipe SIG-MASSAGE                          ║\n");
        printf("║ ► 0. Sair do Sistema                             ║\n");
        printf("║                                                  ║\n");
        printf("╚══════════════════════════════════════════════════╝\n");
        printf("\n Digite a opção desejada: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            
            case 1: 
                cliente(); 
                break;
                
            case 2:
                massoterapeuta();
                break;
                
            case 3:
                limparTela();
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
                agendamentos();
                break;
                
            case 5:
                limparTela();
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
            
            case 6:
                limparTela();
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
                pausar();
                break;

            case 7:
                limparTela();
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
                pausar();
                break;
                
            case 0:
                limparTela();
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
