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

#define MASSOTERAPEUTAS_FILE "massoterapeutas.dat"


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

int salvarMassoterapeuta(Massoterapeutas *m) {
    FILE *arquivo = fopen(MASSOTERAPEUTAS_FILE, "ab");
    size_t escrito = fwrite(m, sizeof(Massoterapeutas), 1, arquivo);
    fclose(arquivo);
    return (escrito == 1);
}

int carregarMassoterapeutas(Massoterapeutas **massoterapeutas, int *quantidade) {
    FILE *arquivo = fopen(MASSOTERAPEUTAS_FILE, "rb");
    if (arquivo == NULL) {
        *massoterapeutas = NULL;
        *quantidade = 0;
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *quantidade = tamanho / sizeof(Massoterapeutas);

    if (*quantidade == 0) {
        *massoterapeutas = NULL;
        fclose(arquivo);
        return 1;
    }

    *massoterapeutas = (Massoterapeutas*)malloc((*quantidade) * sizeof(Massoterapeutas));
    size_t lidos = fread(*massoterapeutas, sizeof(Massoterapeutas), *quantidade, arquivo);
    fclose(arquivo);

    return (lidos == *quantidade);
}

int atualizarArquivoMassoterapeutas(Massoterapeutas *massoterapeutas, int quantidade) {
    FILE *arquivo = fopen(MASSOTERAPEUTAS_FILE, "wb");
    size_t escritos = fwrite(massoterapeutas, sizeof(Massoterapeutas), quantidade, arquivo);
    fclose(arquivo);
    return (escritos == quantidade);
}

void cadastrarMassoterapeuta() {
    Massoterapeutas *massoterapeuta = (Massoterapeutas*)malloc(sizeof(Massoterapeutas));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            CADASTRAR MASSOTERAPEUTA          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do massoterapeuta: ");
    scanf(" %69[^\n]", massoterapeuta->nome);
    limparBuffer();

    printf("Digite o CPF do massoterapeuta: ");
    scanf(" %19s", massoterapeuta->cpf);
    limparBuffer();

    printf("Digite o telefone do massoterapeuta: ");
    scanf(" %19s", massoterapeuta->telefone);
    limparBuffer();

    printf("Digite o email do massoterapeuta: ");
    scanf(" %69s", massoterapeuta->email);
    limparBuffer();

    printf("Digite o número do CREFITO: ");
    scanf(" %19s", massoterapeuta->crefito);
    limparBuffer();

    printf("Digite a especialidade: ");
    scanf(" %49[^\n]", massoterapeuta->especialidade);
    limparBuffer();

    massoterapeuta->status = 1;

    if (salvarMassoterapeuta(massoterapeuta)) {
        printf("\n Massoterapeuta cadastrado com sucesso!\n");
    } else {
        printf("\n Erro ao salvar massoterapeuta!\n");
    }

    free(massoterapeuta);
    pausar();
}

void listarMassoterapeutas() {
    FILE *fp;
    Massoterapeutas *massoterapeuta;
    int massoterapeutasAtivos = 0;

    massoterapeuta = (Massoterapeutas*)malloc(sizeof(Massoterapeutas));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             LISTAR MASSOTERAPEUTAS           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    fp = fopen(MASSOTERAPEUTAS_FILE, "rb");
    if (fp == NULL) {
        printf("Nenhum massoterapeuta cadastrado ainda.\n");
        free(massoterapeuta);
        pausar();
        return;
    }

    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
        if (massoterapeuta->status == 1) {
            printf("──────────────────────────────────────────────\n");
            printf("Nome: %s\n", massoterapeuta->nome);
            printf("CPF: %s\n", massoterapeuta->cpf);
            printf("Telefone: %s\n", massoterapeuta->telefone);
            printf("Email: %s\n", massoterapeuta->email);
            printf("CREFITO: %s\n", massoterapeuta->crefito);
            printf("Especialidade: %s\n", massoterapeuta->especialidade);
            massoterapeutasAtivos++;
        }
    }

    if (massoterapeutasAtivos == 0) {
        printf("Nenhum massoterapeuta ativo encontrado.\n");
    } else {
        printf("──────────────────────────────────────────────\n");
        printf("\nTotal de massoterapeutas ativos: %d\n", massoterapeutasAtivos);
    }

    fclose(fp);
    free(massoterapeuta);
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