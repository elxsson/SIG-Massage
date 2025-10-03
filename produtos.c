/*
|=============================================================|
|                      MODULO PRODUTOS                        |
| CRUD para a gestão de produtos do sistema SIG-MASSAGE        |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "produtos.h"
#include "utils.h"

#define PRODUTOS_FILE "produtos.csv"
#define TEMP_FILE "produtos_temp.csv"

void salvarProduto(Produtos produto) {
    FILE *fp = fopen(PRODUTOS_FILE, "a");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo de produtos");
        return;
    }

    // Converte para lowercase
    for (int i = 0; produto.nome[i]; i++) produto.nome[i] = tolower(produto.nome[i]);
    for (int i = 0; produto.codigo[i]; i++) produto.codigo[i] = tolower(produto.codigo[i]);

    fprintf(fp, "%s;%s;%.2f;%d\n", produto.nome, produto.codigo, produto.preco, produto.estoque);
    fclose(fp);
}

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

void cadastrarProduto() {
    Produtos produto;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              CADASTRAR PRODUTO               ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do produto: ");
    if (scanf(" %69[^\n]", produto.nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o código do produto: ");
    if (scanf(" %19s", produto.codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite o preço do produto: ");
    if (scanf("%f", &produto.preco) != 1) {
        printf("\n Erro: Preço inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Digite a estoque em estoque: ");
    if (scanf("%d", &produto.estoque) != 1) {
        printf("\n Erro: Estoque inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    salvarProduto(produto);

    printf("\n Produto %s cadastrado com sucesso!\n", produto.nome);
    pausar();
}

void listarProdutos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               LISTAR PRODUTOS                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    FILE *fp = fopen(PRODUTOS_FILE, "r");
    if (fp == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        pausar();
        return;
    }

    Produtos produto;
    while (fscanf(fp,  " %69[^;];%19[^;];%f;%d",
                  produto.nome, produto.codigo, &produto.preco, &produto.estoque) == 4) {
        printf("Nome: %s | Código: %s | Preço: R$ %.2f | Estoque: %d\n",
               produto.nome, produto.codigo, produto.preco, produto.estoque);
    }

    fclose(fp);
    pausar();
}

void buscarProduto() {
    char nome[70];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                PROCURAR PRODUTO              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o nome do produto que deseja buscar: \n");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    // converte busca para lowercase
    for (int i = 0; nome[i]; i++) nome[i] = tolower(nome[i]);

    FILE *fp = fopen(PRODUTOS_FILE, "r");
    if (fp == NULL) {
        printf("\nNenhum produto cadastrado ainda.\n");
        pausar();
        return;
    }

    Produtos produto;
    int encontrado = 0;
    
    printf("\n--- Resultados da busca ---\n\n");

    while (fscanf(fp,  " %69[^;];%19[^;];%f;%d",
                  produto.nome, produto.codigo, &produto.preco, &produto.estoque) == 4) {
                    
        if (strstr(produto.nome, nome) != NULL) {
            printf("Nome: %s\n", produto.nome);
            printf("Código: %s\n", produto.codigo);
            printf("Preço: %.2f\n", produto.preco);
            printf("Estoque: %d\n", produto.estoque);
            printf("---------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o nome '%s'.\n", nome);
    }

    fclose(fp);
    pausar();
}

void atualizarProduto() {
    char codigo[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║          ATUALIZAR DADOS DO PRODUTO          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o código do produto que deseja atualizar: \n");
    if (scanf(" %19s", codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    // converte busca para lowercase
    for (int i = 0; codigo[i]; i++) codigo[i] = tolower(codigo[i]);

    FILE *fp = fopen(PRODUTOS_FILE, "r");
    if (fp == NULL) {
        printf("\nNenhum produto cadastrado ainda.\n");
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
    
    Produtos produto;
    int encontrado = 0;

    while (fscanf(fp,  " %69[^;];%19[^;];%f;%d",
                  produto.nome, produto.codigo, &produto.preco, &produto.estoque) == 4) {
                    
        if (strcmp(produto.codigo, codigo) == 0) {
            encontrado = 1;

            printf("\nProduto encontrado:\n");
            printf("Nome: %s\n", produto.nome);
            printf("Código: %s\n", produto.codigo);
            printf("Preço: %.2f\n", produto.preco);
            printf("Estoque: %d\n", produto.estoque);

            Produtos novoProduto;
            strcpy(novoProduto.codigo,produto.codigo); // Código não muda

            printf("Digite o novo nome (atual: %s): ", produto.nome);
            if (scanf(" %69[^\n]", novoProduto.nome) != 1) {
                strcpy(novoProduto.nome, produto.nome);
            }

            for (int i = 0; novoProduto.nome[i]; i++) novoProduto.nome[i] = tolower(novoProduto.nome[i]);

            printf("Digite o novo preço (atual: %.2f): ", produto.preco);
            if (scanf("%f", &novoProduto.preco) != 1) {
                novoProduto.preco = produto.preco;
            }

            printf("Digite a nova quantidade em estoque (atual: %d): ", produto.estoque);
            if (scanf("%d", &novoProduto.estoque) != 1) {
                novoProduto.estoque = produto.estoque;
            }

            fprintf(temp, "%s;%s;%.2f;%d\n",
                    novoProduto.nome, novoProduto.codigo,
                    novoProduto.preco, novoProduto.estoque);

            printf("\nDados atualizados com sucesso!\n");
        }else {
            fprintf(temp, "%s;%s;%.2f;%d\n",
                    produto.nome, produto.codigo, produto.preco, produto.estoque);
        }
    }
    
    fclose(fp);
    fclose(temp);

    if (encontrado) {
        remove(PRODUTOS_FILE);
        rename(TEMP_FILE, PRODUTOS_FILE);
    } else {
        printf("\nProduto com Código %s não encontrado.\n", codigo);
        remove(TEMP_FILE);
    }

    pausar();
}

void deletarProduto() {
    char codigo[20];
    char confirmacao;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               EXCLUIR PRODUTO                ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o código do produto que deseja deletar: ");
    if (scanf(" %19s", codigo) != 1) {
        printf("\n Erro: Código inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    // converte busca para lowercase
    for (int i = 0; codigo[i]; i++) codigo[i] = tolower(codigo[i]);

    FILE *fp = fopen(PRODUTOS_FILE, "r");
    if (fp == NULL) {
        printf("\nNenhum produto cadastrado ainda.\n");
        pausar();
        return;
    }

    Produtos produto;
    int encontrado = 0;

    while (fscanf(fp,  " %69[^;];%19[^;];%f;%d",
                  produto.nome, produto.codigo, &produto.preco, &produto.estoque) == 4) {
                    
        if (strcmp(produto.codigo, codigo) == 0) {
            encontrado = 1;

            printf("\nProduto encontrado:\n");
            printf("Nome: %s\n", produto.nome);
            printf("Código: %s\n", produto.codigo);
            printf("Preço: %.2f\n", produto.preco);
            printf("Estoque: %d\n", produto.estoque);
            break;
        }
    }
    
    fclose(fp);

    if (!encontrado) {
        printf("\nProduto com Código %s não encontrado.\n", codigo);
        pausar();
        return;
    }

    printf("Tem certeza que deseja excluir? (s/N): ");
    limparBuffer();
    scanf("%c", &confirmacao);
    
    if (confirmacao != 's' && confirmacao != 'S') {
        printf("\n Operação cancelada pelo usuário.\n");
        pausar();
        return;
    }

    fp = fopen(PRODUTOS_FILE, "r");
    FILE *temp = fopen(TEMP_FILE, "w");
    
    if (temp == NULL) {
        printf("\nErro ao criar arquivo temporário.\n");
        fclose(fp);
        pausar();
        return;
    }

    while (fscanf(fp,  " %69[^;];%19[^;];%f;%d",
                  produto.nome, produto.codigo, &produto.preco, &produto.estoque) == 4) {
        if (strcmp(produto.codigo, codigo) != 0) {
            fprintf(temp, "%s;%s;%.2f;%d\n",
                    produto.nome, produto.codigo, produto.preco, produto.estoque);
        }
    }

    fclose(fp);
    fclose(temp);

    // remove o arquivo original e renomeia o temporario
    remove(PRODUTOS_FILE);
    rename(TEMP_FILE, PRODUTOS_FILE);

    printf("\n Produto excluído com sucesso!\n");

    pausar();
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
