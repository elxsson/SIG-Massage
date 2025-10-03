/*
|=============================================================|
|                  MODULO MASSOTERAPEUTA                      |
| CRUD para a gestao de massoterapeutas do sistema SIG-MASSAGE|
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "massoterapeutas.h"
#include "utils.h"

#define MASSOTERAPEUTAS_FILE "massoterapeutas.csv";

void salvarMassoterapeuta(Massoterapeutas massoterapeuta) {
    FILE *fp = fopen(MASSOTERAPEUTAS_FILE, "a");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo de massoterapeutas");
        return;
    }

    // Converte para lowercase
    for (int i = 0; massoterapeuta.nome[i]; i++) massoterapeuta.nome[i] = tolower(massoterapeuta.nome[i]);
    for (int i = 0; massoterapeuta.email[i]; i++) massoterapeuta.email[i] = tolower(massoterapeuta.email[i]);

    fprintf(fp, "%s;%s;%s;%s;%s;%s\n",
            massoterapeuta.nome, massoterapeuta.cpf, massoterapeuta.telefone, massoterapeuta.email, massoterapeuta.crefito, massoterapeuta.especialidade);
    fclose(fp);
}

void menuMassoterapeutas() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             MODULO MASSOTERAPEUTA            ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Cadastrar Massoterapeuta                  ║\n");
    printf("║ 2. Listar Massoterapeutas                    ║\n");
    printf("║ 3. Procurar Massoterapeuta                   ║\n");
    printf("║ 4. Atualizar Dados do Massoterapeuta         ║\n");
    printf("║ 5. Excluir Massoterapeuta                    ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

void cadastrarMassoterapeuta() {
    Massoterapeutas massoterapeuta;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            CADASTRAR MASSOTERAPEUTA          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do massoterapeuta: ");
    if (scanf(" %69[^\n]", massoterapeuta.nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o CPF do massoterapeuta: ");
    if (scanf(" %19s", massoterapeuta.cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o telefone do massoterapeuta: ");
    if (scanf(" %19s", massoterapeuta.telefone) != 1) {
        printf("\n Erro: Telefone inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o email do massoterapeuta: ");
    if (scanf(" %69s", massoterapeuta.email) != 1) {
        printf("\n Erro: Email inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o número do CREFITO: ");
    if (scanf(" %19s", massoterapeuta.crefito) != 1) {
        printf("\n Erro: CREFITO inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite a especialidade: ");
    if (scanf(" %49[^\n]", massoterapeuta.especialidade) != 1) {
        printf("\n Erro: Especialidade inválida!\n");
        limparBuffer();
        pausar();
        return;
    }
    salvarMassoterapeuta(massoterapeuta);

    printf("\n Massoterapeuta %s cadastrado com sucesso!\n", massoterapeuta.nome);
    pausar();
}

void listarMassoterapeutas() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             LISTAR MASSOTERAPEUTAS           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    FILE *fp = fopen(MASSOTERAPEUTAS_FILE, "r");
    if (fp == NULL) {
        printf("Nenhum massoterapeuta cadastrado ainda.\n");
        pausar();
        return;
    }

    Massoterapeutas massoterapeuta;
    while (fscanf(fp, " %69[^;];%19[^;];%19[^;];%69[^;];%19[^;];%49[^\n]\n",
                  massoterapeuta.nome, massoterapeuta.cpf, massoterapeuta.telefone, 
                  massoterapeuta.email, massoterapeuta.crefito, massoterapeuta.especialidade) == 6) {
        printf("Nome: %s | CPF: %s | Telefone: %s | Email: %s | CREFITO: %s | Especialidade: %s\n",
               massoterapeuta.nome, massoterapeuta.cpf, massoterapeuta.telefone, 
               massoterapeuta.email, massoterapeuta.crefito, massoterapeuta.especialidade);
    }

    fclose(fp);
    pausar();
}

void buscarMassoterapeuta() {
    char nome[70];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            PROCURAR MASSOTERAPEUTA           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o nome do massoterapeuta que deseja buscar: \n");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Função de busca de massoterapeuta ainda não implementada.\n");
    pausar();
}

void atualizarMassoterapeuta() {
    char cpf[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║       ATUALIZAR DADOS DO MASSOTERAPEUTA      ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o CPF do massoterapeuta que deseja atualizar: \n");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    printf("Função de atualização de massoterapeuta ainda não implementada.\n");
    pausar();
}

void deletarMassoterapeuta() {
    char cpf[20];
    char confirmacao;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            EXCLUIR MASSOTERAPEUTA            ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o CPF do massoterapeuta que deseja deletar: ");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Tem certeza que deseja excluir? (s/N): ");
    limparBuffer();
    scanf("%c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        printf("\n Função de exclusão de massoterapeuta ainda não implementada.\n");
        printf("CPF que seria excluído: %s\n", cpf);
    } else {
        printf("\n Operação cancelada pelo usuário.\n");
    }
    
    pausar();
}

void massoterapeutas() {
    int opcao;

    do {
        menuMassoterapeutas();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                cadastrarMassoterapeuta(); 
                break;
            case 2: 
                listarMassoterapeutas(); 
                break;
            case 3: 
                buscarMassoterapeuta(); 
                break;
            case 4: 
                atualizarMassoterapeuta(); 
                break;
            case 5: 
                deletarMassoterapeuta(); 
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n"); 
                break;
        
            default:
                limparTela();
                printf("\n Opção inválida! Digite um número entre 0 e 5.\n");
                pausar();
                break;
        }

    } while(opcao != 0);
}