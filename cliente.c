#include <stdio.h>
#include <stdlib.h>


void pausar() {

    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}
void cadastroCliente() {
    system("clear || cls");
    printf("\n Função de cadastro de cliente ainda não implementada.\n");
    pausar();
}
void listarClientes() {
    system("clear || cls");
    printf("\n Função de listagem de clientes ainda não implementada.\n");
    pausar();
}
void buscarCliente() {
    system("clear || cls");
    printf("\n Função de busca de cliente por CPF ainda não implementada.\n");
    pausar();
}
void atualizarCliente() {
    system("clear || cls");
    printf("\n Função de atualização de dados do cliente ainda não implementada.\n");
    pausar();
}
void deletarCliente() {
    system("clear || cls");
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
        printf("║ 3. Buscar Cliente                            ║\n");
        printf("║ 4. Atualizar Dados do Cliente                ║\n");
        printf("║ 5. Deletar Cliente                           ║\n");
        printf("║ 0. Voltar ao Menu Principal                  ║\n");
        printf("║                                              ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf("\n Digite a opção desejada: ");
        scanf("%d", &opcao);


        switch (opcao)
        {
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

