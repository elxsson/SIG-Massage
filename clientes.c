/*
|=============================================================|
|                    MODULO CLIENTE                           |
| CRUD para a gestao de clientes do sistema SIG-MASSAGE       |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utils.h"

#define ARQUIVO_CLIENTES "clientes.dat"


void menuClientes() {
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

int salvarCliente(Cliente *c) {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "ab");
    size_t escrito = fwrite(c, sizeof(Cliente), 1, arquivo);
    fclose(arquivo);
    return (escrito == 1);
}

int carregarClientes(Cliente **clientes, int *quantidade) {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "rb");
    if (arquivo == NULL) {
        *clientes = NULL;
        *quantidade = 0;
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *quantidade = tamanho / sizeof(Cliente);

    if (*quantidade == 0) {
        *clientes = NULL;
        fclose(arquivo);
        return 1;
    }

    *clientes = (Cliente*)malloc((*quantidade) * sizeof(Cliente));
    size_t lidos = fread(*clientes, sizeof(Cliente), *quantidade, arquivo);
    fclose(arquivo);

    return (lidos == *quantidade);
}

void clientes() {
    int opcao;

    do {
        menuClientes();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                cadastrarCliente(); 
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
