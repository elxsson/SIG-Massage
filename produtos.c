/*
|=============================================================|
|                      MODULO PRODUTOS                        |
| CRUD para a gestão de produtos do sistema SIG-MASSAGE        |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"
#include "utils.h"

#define ARQUIVO_PRODUTOS "produtos.dat"


void menuProdutos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                MODULO PRODUTOS               ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Cadastrar Produto                         ║\n");
    printf("║ 2. Listar Produtos                           ║\n");
    printf("║ 3. Buscar Produto                            ║\n");
    printf("║ 4. Atualizar Dados do Produto                ║\n");
    printf("║ 5. Excluir Produto                           ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

int salvarProduto(Produto *p) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "ab");
    if (arquivo == NULL) return 0;
    
    size_t escrito = fwrite(p, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
    return (escrito == 1);
}

int carregarProdutos(Produto **produtos, int *quantidade) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (arquivo == NULL) {
        *produtos = NULL;
        *quantidade = 0;
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *quantidade = tamanho / sizeof(Produto);

    if (*quantidade == 0) {
        *produtos = NULL;
        fclose(arquivo);
        return 1;
    }

    *produtos = (Produto*)malloc((*quantidade) * sizeof(Produto));
    size_t lidos = fread(*produtos, sizeof(Produto), *quantidade, arquivo);
    fclose(arquivo);

    return (lidos == *quantidade);
}

int atualizarArquivoProdutos(Produto *produtos, int quantidade) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "wb");
    if (arquivo == NULL) return 0;
    
    size_t escritos = fwrite(produtos, sizeof(Produto), quantidade, arquivo);
    fclose(arquivo);
    return (escritos == quantidade);
}


void produtos() {
    int opcao;

    do {
        menuProdutos();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                cadastrarProduto(); 
                break;
            case 2: 
                listarProdutos(); 
                break;
            case 3: 
                buscarProduto(); 
                break;
            case 4: 
                atualizarProduto(); 
                break;
            case 5: 
                deletarProduto(); 
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
