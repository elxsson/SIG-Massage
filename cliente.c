/*
|=============================================================|
|                    MODULO CLIENTE                           |
| CRUD para a gestao de clientes do sistema SIG-MASSAGE       |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "utils.h"

#define CLIENTE_FILE "clientes.csv"
#define TEMP_FILE "clientes_temp.csv"

void salvarCliente(Cliente cliente) {
    FILE *fp = fopen(CLIENTE_FILE, "a");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo de clientes");
        return;
    }
    
    // converte todos os dados para lowercase antes de salvar
    for (int i = 0; cliente.nome[i]; i++) cliente.nome[i] = tolower(cliente.nome[i]);
    for (int i = 0; cliente.cpf[i]; i++) cliente.cpf[i] = tolower(cliente.cpf[i]);
    for (int i = 0; cliente.telefone[i]; i++) cliente.telefone[i] = tolower(cliente.telefone[i]);
    for (int i = 0; cliente.email[i]; i++) cliente.email[i] = tolower(cliente.email[i]);
    
    fprintf(fp, "%s;%s;%s;%s\n", cliente.nome, cliente.cpf, cliente.telefone, cliente.email);
    fclose(fp);
}


void menucliente() {
        limparTela();
        printf("\n╔══════════════════════════════════════════════╗\n");
        printf("║                 MODULO CLIENTE               ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║                                              ║\n");
        printf("║ 1. Cadastrar Cliente                         ║\n");
        printf("║ 2. Listar Clientes                           ║\n");
        printf("║ 3. procurar Cliente                          ║\n");
        printf("║ 4. Atualizar Dados do Cliente                ║\n");
        printf("║ 5. exluir Cliente                            ║\n");
        printf("║ 0. Voltar ao Menu Principal                  ║\n");
        printf("║                                              ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf("\n Digite a opção desejada: ");
}



void cadastroCliente() {
    Cliente cliente;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               CADASTRAR CLIENTE              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o nome do cliente: ");
    if (scanf(" %69[^\n]", cliente.nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o CPF do cliente: ");
    if (scanf(" %19s", cliente.cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o telefone do cliente: ");
    if (scanf(" %19s", cliente.telefone) != 1) {
        printf("\n Erro: Telefone inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o email do cliente: ");
    if (scanf(" %69s", cliente.email) != 1) {
        printf("\n Erro: Email inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    salvarCliente(cliente);

    printf("\n Cliente %s cadastrado com sucesso!\n", cliente.nome);
    pausar();
}



void listarClientes() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                LISTAR CLIENTES               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    FILE *fp = fopen(CLIENTE_FILE, "r");
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado ainda.\n");
        pausar();
        return;
    }

    Cliente cliente;
    while (fscanf(fp, " %69[^;];%19[^;];%19[^;];%69[^\n]\n",
                  cliente.nome, cliente.cpf, cliente.telefone, cliente.email) == 4) {
        printf("Nome: %s | CPF: %s | Telefone: %s | Email: %s\n",
               cliente.nome, cliente.cpf, cliente.telefone, cliente.email);
    }

    fclose(fp);
    pausar();
}



void buscarCliente() {
    char nome[70];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               PROCURAR CLIENTE               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o nome do cliente que deseja buscar: ");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    // converte busca para lowercase
    for (int i = 0; nome[i]; i++) nome[i] = tolower(nome[i]);

    FILE *fp = fopen(CLIENTE_FILE, "r");
    if (fp == NULL) {
        printf("\nNenhum cliente cadastrado ainda.\n");
        pausar();
        return;
    }

    Cliente cliente;
    int encontrado = 0;
    
    printf("\n--- Resultados da busca ---\n\n");
    
    while (fscanf(fp, " %69[^;];%19[^;];%19[^;];%69[^\n]\n",
                  cliente.nome, cliente.cpf, cliente.telefone, cliente.email) == 4) {
        
        if (strstr(cliente.nome, nome) != NULL) {
            printf("Nome: %s\n", cliente.nome);
            printf("CPF: %s\n", cliente.cpf);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Email: %s\n", cliente.email);
            printf("---------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com o nome '%s'.\n", nome);
    }

    fclose(fp);
    pausar();
}



void atualizarCliente() {
    char cpf[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║          ATUALIZAR DADOS DO CLIENTE          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o CPF do cliente que deseja atualizar os dados: ");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    FILE *fp = fopen(CLIENTE_FILE, "r");
    if (fp == NULL) {
        printf("\nNenhum cliente cadastrado ainda.\n");
        pausar();
        return;
    }

    FILE *temp = fopen(TEMP_FILE, "w");
    if (temp == NULL) {
        printf("\nErro ao criar arquivo temporário.\n");
        fclose(fp);
        pausar();
        return;
    }

    Cliente cliente;
    int encontrado = 0;

    while (fscanf(fp, " %69[^;];%19[^;];%19[^;];%69[^\n]\n",
                  cliente.nome, cliente.cpf, cliente.telefone, cliente.email) == 4) {
        
        if (strcmp(cliente.cpf, cpf) == 0) {
            encontrado = 1;
            
            printf("\nCliente encontrado:\n");
            printf("Nome: %s\n", cliente.nome);
            printf("CPF: %s\n", cliente.cpf);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Email: %s\n\n", cliente.email);
            
            Cliente novoCliente;
            strcpy(novoCliente.cpf, cliente.cpf); // CPF não muda
            
            printf("Digite o novo nome (atual: %s): ", cliente.nome);
            if (scanf(" %69[^\n]", novoCliente.nome) != 1) {
                strcpy(novoCliente.nome, cliente.nome);
            }

            for (int i = 0; novoCliente.nome[i]; i++) novoCliente.nome[i] = tolower(novoCliente.nome[i]);
            
            printf("Digite o novo telefone (atual: %s): ", cliente.telefone);
            if (scanf(" %19s", novoCliente.telefone) != 1) {
                strcpy(novoCliente.telefone, cliente.telefone);
            }
            
            printf("Digite o novo email (atual: %s): ", cliente.email);
            if (scanf(" %69s", novoCliente.email) != 1) {
                strcpy(novoCliente.email, cliente.email);
            }

            for (int i = 0; novoCliente.email[i]; i++) novoCliente.email[i] = tolower(novoCliente.email[i]);
            
            fprintf(temp, "%s;%s;%s;%s\n", 
                    novoCliente.nome, novoCliente.cpf, 
                    novoCliente.telefone, novoCliente.email);
            
            printf("\nDados atualizados com sucesso!\n");
        } else {
            fprintf(temp, "%s;%s;%s;%s\n", 
                    cliente.nome, cliente.cpf, cliente.telefone, cliente.email);
        }
    }

    fclose(fp);
    fclose(temp);

    if (encontrado) {
        remove(CLIENTE_FILE);
        rename(TEMP_FILE, CLIENTE_FILE);
    } else {
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
        remove(TEMP_FILE);
    }

    pausar();
}



void deletarCliente() {
    char cpf[20];
    char confirmacao;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               EXCLUIR CLIENTE                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o CPF do cliente que deseja deletar: ");
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
        printf("\n Função de exclusão de cliente ainda não implementada.\n");
        printf("CPF que seria excluído: %s\n", cpf);
    } else {
        printf("\n Operação cancelada pelo usuário.\n");
    }
    
    pausar();
}



void cliente() {
    int opcao;

    do {
        menucliente();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                cadastroCliente(); 
                break;
            case 2: 
                listarClientes(); 
                break;
            case 3: 
                buscarCliente(); 
                break;
            case 4: 
                atualizarCliente(); 
                break;
            case 5: 
                deletarCliente(); 
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n"); 
                break;
        
            default:
                printf("\n Opção inválida! Digite um número entre 0 e 5.\n");
                pausar();
            break;
        }
 
    } while(opcao != 0);
    
}
