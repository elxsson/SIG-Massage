/*
|=============================================================|
|                    MODULO CLIENTE                           |
| CRUD para a gestao de clientes do sistema SIG-MASSAGE       |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>

void pausar() {
    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}



void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70]; 

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               CADASTRAR CLIENTE              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do cliente: ");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o CPF do cliente: ");
       if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o telefone do cliente: ");
    if (scanf(" %19s", telefone) != 1) {
        printf("\n Erro: Telefone inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o email do cliente: ");
    if (scanf(" %69s", email) != 1) {
        printf("\n Erro: Email inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Cliente %s cadastrado com sucesso!\n", nome);
    pausar();
}



void listarClientes() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                LISTAR CLIENTES               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Nenhum cliente cadastrado ainda.\n");
    printf("Para cadastrar um cliente, escolha a opção 1 no menu.\n");
    pausar();
}



void buscarCliente() {
    char nome[70];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               PROCURAR CLIENTE               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o nome do cliente que deseja buscar: \n");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("função de busca de cliente ainda não implementada.\n");
    pausar();
}



void atualizarCliente() {
    char cpf[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║          ATUALIZAR DADOS DO CLIENTE          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o CPF do cliente que deseja atualizar:  \n");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    printf("Função de atualização de cliente ainda não implementada.\n");
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
        printf("\n Função de exclusão de massoterapeuta ainda não implementada.\n");
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
