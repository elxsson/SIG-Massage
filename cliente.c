#include <stdio.h>
#include <stdlib.h>


void pausar() {

    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}



void cadastroCliente() {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70]; 

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             CADASTRO DE CLIENTE              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("Digite o nome do cliente: ");
    scanf(" %s", nome);
    printf("Digite o CPF do cliente: ");
    scanf(" %s", cpf);
    printf("Digite o telefone do cliente: ");
    scanf(" %s", telefone);
    printf("Digite o email do cliente: ");
    scanf(" %s", email);
    printf("\n Cliente %s cadastrado com sucesso!\n", nome);
    pausar();
}



void listarClientes() {
    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               LISTA DE CLIENTES              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("Nenhum cliente cadastrado ainda.\n");
    printf("Para cadastrar um cliente, escolha a opção 1 no menu.\n");
    pausar();
}



void buscarCliente() {
    char nome[70];

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               PROCURAR CLIENTE               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("Digite o nome do cliente que deseja buscar: \n");
    scanf(" %s", nome);
    printf("função de busca de cliente ainda não implementada.\n");
    pausar();
}



void atualizarCliente() {
    char cpf[20];

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            ATUALIZAÇÃO DE CLIENTE            ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja atualizar:  \n");
    scanf(" %s", cpf);
    printf("Função de atualização de cliente ainda não implementada.\n");
    pausar();
}



void deletarCliente() {
    char cpf[20];

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               EXCLUIR CLIENTE                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("Digite o CPF do cliente que deseja deletar: ");
    scanf(" %s", cpf);
    printf("\n Função de deleção de cliente ainda não implementada.\n");
    pausar();
}



int main() {
    int opcao;

    do {
        system("clear || cls");
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
        scanf("%d", &opcao);

        switch (opcao){
        case 1: cadastroCliente(); break;
        case 2: listarClientes(); break;
        case 3: buscarCliente(); break;
        case 4: atualizarCliente(); break;
        case 5: deletarCliente(); break;
        case 0: break;
        
        default:
            printf("\n Opção inválida! Por favor, tente novamente.\n");
            pausar();
            break;
        }
 
    } while(opcao != 0);
    
    return 0;
}

