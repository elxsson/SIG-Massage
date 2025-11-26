#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "relatorios.h"
#include "clientes.h"
#include "massoterapeutas.h"
#include "produtos.h"
#include "financeiro.h"
#include "agendamentos.h"
#include "utils.h"

#define ARQUIVO_CLIENTES "clientes.dat"
#define MASSOTERAPEUTAS_FILE "massoterapeutas.dat"
#define ARQUIVO_PRODUTOS "produtos.dat"
#define ARQUIVO_FINANCEIRO "financeiro.dat"
#define ARQUIVO_AGENDAMENTOS "agendamentos.dat"

void menuRelatorios() {
    limparTela();
    printf("\n╔════════════════════════════════════════════════╗\n");
    printf("║                MODULO RELATORIOS               ║\n");
    printf("╠════════════════════════════════════════════════╣\n");
    printf("║                                                ║\n");
    printf("║ 1. Listar Relatorios                           ║\n");
    printf("║ 2. Filtrar Clientes por Letra                  ║\n");
    printf("║ 3. Filtrar Produtos por Faixa de Preço         ║\n");
    printf("║ 4. Filtrar Por Especialidade de Massoterapeuta ║\n");
    printf("║ 5. Filtrar Agendamentos com Nomes              ║\n");
    printf("║ 6. Filtrar Financeiro com Nomes                ║\n");
    printf("║ 0. Voltar ao Menu Principal                    ║\n");
    printf("║                                                ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

void menuRelatoriosListar() {
    limparTela();
    printf("\n╔════════════════════════════════════════════════╗\n");
    printf("║                LISTAR RELATORIOS               ║\n");
    printf("╠════════════════════════════════════════════════╣\n");
    printf("║                                                ║\n");
    printf("║ 1. Listar Clientes                             ║\n");
    printf("║ 2. Listar Massoterapeutas                      ║\n");
    printf("║ 3. Listar Produto                              ║\n");
    printf("║ 4. Listar Agendamentos                         ║\n");
    printf("║ 5. Listar Financeiro                           ║\n");
    printf("║ 0. Voltar ao Menu Relatorios                   ║\n");
    printf("║                                                ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

// Funções de listagem
void listarClientesGeral() {
    FILE *fp;
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            LISTAGEM DE CLIENTES              ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_CLIENTES, "rb");
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado ainda.\n");
        free(cliente);
        pausar();
        return;
    }

    printf("════════════════════════════════════════════════════════════════════════════════════\n");
    printf("Nome                     CPF              Telefone       Email\n");
    printf("════════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == 1) {
            printf("%-24s %-16s %-14s %s\n",
                   cliente->nome,
                   cliente->cpf,
                   cliente->telefone,
                   cliente->email);
        }
    }

    printf("════════════════════════════════════════════════════════════════════════════════════\n");

    fclose(fp);
    free(cliente);
    pausar();
}

void listarMassoterapeutasGeral() {
    FILE *fp;
    Massoterapeutas *massoterapeuta = (Massoterapeutas*)malloc(sizeof(Massoterapeutas));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             LISTAGEM DE MASSOTERAPEUTAS      ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    fp = fopen(MASSOTERAPEUTAS_FILE, "rb");
    if (fp == NULL) {
        printf("Nenhum massoterapeuta cadastrado ainda.\n");
        free(massoterapeuta);
        pausar();
        return;
    }

    printf("════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
    printf("Nome                     CPF              Telefone       Email                  CREFITO\n");
    printf("════════════════════════════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
        if (massoterapeuta->status == 1) {
            printf("%-24s %-16s %-14s %-22s %s\n",
                   massoterapeuta->nome,
                   massoterapeuta->cpf,
                   massoterapeuta->telefone,
                   massoterapeuta->email,
                   massoterapeuta->crefito);
        }
    }
    printf("════════════════════════════════════════════════════════════════════════════════════════════════════════\n");

    fclose(fp);
    free(massoterapeuta);
    pausar();
}

void listarProdutosGeral() {
    FILE *fp;
    Produto *produto = (Produto*)malloc(sizeof(Produto));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║               LISTAGEM DE PRODUTOS           ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fp == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        free(produto);
        pausar();
        return;
    }

    printf("══════════════════════════════════════════════════════════════════════════\n");
    printf("Nome                     Código       Preço       Estoque\n");
    printf("══════════════════════════════════════════════════════════════════════════\n");
    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (produto->status == 1) {
            printf("%-24s %-12s R$ %-9.2f %d\n",
                   produto->nome,
                   produto->codigo,
                   produto->preco,
                   produto->estoque);
        }
    }
    printf("══════════════════════════════════════════════════════════════════════════\n");

    fclose(fp);
    free(produto);
    pausar();
}

void listarAgendamentosGeral() {
    FILE *fp;
    Agendamento *agendamento = (Agendamento*)malloc(sizeof(Agendamento));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            LISTAMGEM DE AGENDAMENTOS         ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_AGENDAMENTOS, "rb");
    if (fp == NULL) {
        printf("Nenhum agendamento cadastrado ainda.\n");
        free(agendamento);
        pausar();
        return;
    }

    printf("═══════════════════════════════════════════════════════════════════════════════\n");
    printf("ID   CPF Cliente      Cod Massoterapeuta     Data Agendada   Hora\n");
    printf("═══════════════════════════════════════════════════════════════════════════════\n");

    while (fread(agendamento, sizeof(Agendamento), 1, fp)) {
        if (agendamento->status == 1) {
            printf("%-4s %-17s %-21s %-15s %-5s\n",
                agendamento->id,
                agendamento->cpfCliente,
                agendamento->crefitoMassoterapeuta,
                agendamento->dataAgendada,
                agendamento->hora);
        }
    }

    printf("═══════════════════════════════════════════════════════════════════════════════\n");
    
    fclose(fp);
    free(agendamento);    
    pausar();
}

void listarFinanceiroGeral() {
    FILE *fp;
    Movimentacao *mov = (Movimentacao*)malloc(sizeof(Movimentacao));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║      LISTAR MOVIMENTAÇÕES FINANCEIRAS        ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_FINANCEIRO, "rb");
    if (fp == NULL) {
        printf("Nenhuma movimentação registrada ainda.\n");
        printf("Use as opções de entrada ou saída para registrar.\n");
        free(mov);
        pausar();
        return;
    }

    printf("════════════════════════════════════════════════════════════════════════════════\n");
    printf("Tipo         Valor        Descrição\n");
    printf("════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(mov, sizeof(Movimentacao), 1, fp)) {
        if (mov->status == 1) {
            char *tipo = mov->tipo == 'E' ? "ENTRADA" : "SAÍDA";
            char sinal = mov->tipo == 'E' ? '+' : '-';
            
            printf("%-12s %cR$ %-9.2f %s\n",
                   tipo,
                   sinal,
                   mov->valor,
                   mov->descricao);
        }
    }
    
    printf("════════════════════════════════════════════════════════════════════════════════\n");

    fclose(fp);
    free(mov);
    pausar();
}

// Funções de Filtragem

void filtrarClientesPorLetra() {
    FILE *fp;
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    int count = 0;
    char letra;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║        FILTRAR CLIENTES POR LETRA INICIAL    ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite a letra inicial para filtrar: ");
    scanf(" %c", &letra);
    limparBuffer();

    fp = fopen(ARQUIVO_CLIENTES, "rb");
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado ainda.\n");
        free(cliente);
        pausar();
        return;
    }

    printf("════════════════════════════════════════════════════════════════════════════════════\n");
    printf("Clientes que começam com '%c'\n", letra);
    printf("════════════════════════════════════════════════════════════════════════════════════\n");
    printf("Nome                     CPF              Telefone       Email\n");
    printf("════════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == 1 && cliente->nome[0] == letra) {
            printf("%-24s %-16s %-14s %s\n",
                   cliente->nome,
                   cliente->cpf,
                   cliente->telefone,
                   cliente->email);
            count++;
        }
    }

    printf("════════════════════════════════════════════════════════════════════════════════════\n");
    
    if (count == 0) {
        printf("Nenhum cliente encontrado com a letra '%c'.\n", letra);
    }

    fclose(fp);
    free(cliente);
    pausar();
}

void filtrarProdutosPorPreco() {
    FILE *fp;
    Produto *produto = (Produto*)malloc(sizeof(Produto));
    int count = 0;
    float precoMin, precoMax;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║         FILTRAR PRODUTOS POR PREÇO           ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite o preço mínimo: R$ ");
    scanf("%f", &precoMin);
    printf("Digite o preço máximo: R$ ");
    scanf("%f", &precoMax);
    limparBuffer();

    if (precoMin < 0 || precoMax < 0) {
        printf("Erro: Preços não podem ser negativos!\n");
        free(produto);
        pausar();
        return;
    }

    if (precoMin > precoMax) {
        printf("Erro: Preço mínimo não pode ser maior que preço máximo!\n");
        free(produto);
        pausar();
        return;
    }

    fp = fopen(ARQUIVO_PRODUTOS, "rb");
    if (fp == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        free(produto);
        pausar();
        return;
    }

    printf("\n═════════════════════════════════════════════════════════════════════════\n");
    printf("Produtos entre R$ %.2f e R$ %.2f\n", precoMin, precoMax);
    printf("══════════════════════════════════════════════════════════════════════════\n");
    printf("Nome                     Código       Preço       Estoque\n");
    printf("══════════════════════════════════════════════════════════════════════════\n");

    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (produto->status == 1 && 
            produto->preco >= precoMin && 
            produto->preco <= precoMax) {
            printf("%-24s %-12s R$ %-9.2f %d\n",
                   produto->nome,
                   produto->codigo,
                   produto->preco,
                   produto->estoque);
            count++;
        }
    }

    printf("══════════════════════════════════════════════════════════════════════════\n");
    
    if (count == 0) {
        printf("Nenhum produto encontrado na faixa de R$ %.2f a R$ %.2f.\n", precoMin, precoMax);
    }

    fclose(fp);
    free(produto);
    pausar();
}

void filtrarMassoterapeutasPorEspecialidade() {
    FILE *fp;
    Massoterapeutas *massoterapeuta = (Massoterapeutas*)malloc(sizeof(Massoterapeutas));
    char especialidade;
    int encontrou = 0;

    printf("\n╔══════════════════════════════════╗\n");
    printf("║   TIPOS DE MASSOTERAPEUTAS       ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  R  -  Massagem Relaxante        ║\n");
    printf("║  T  -  Massagem Terapêutica      ║\n");
    printf("║  E  -  Massagem Esportiva        ║\n");
    printf("║  Q  -  Massagem Quiroprática     ║\n");
    printf("║  A  -  Massagem Ayurvédica       ║\n");
    printf("╚══════════════════════════════════╝\n");

    printf("Digite a letra inicial para filtrar: ");
    scanf(" %c", &especialidade);
    limparBuffer();

    especialidade = toupper(especialidade);

    char nomeEspecialidade[30];
    switch(especialidade) {
        case 'R': 
            strcpy(nomeEspecialidade, "Relaxante"); 
            break;
        case 'T': 
            strcpy(nomeEspecialidade, "Terapêutica"); 
            break;
        case 'E': 
            strcpy(nomeEspecialidade, "Esportiva"); 
            break;
        case 'Q': 
            strcpy(nomeEspecialidade, "Quiroprática"); 
            break;
        case 'A': 
            strcpy(nomeEspecialidade, "Ayurvédica"); 
            break;
        default: 
            printf("Especialidade Inválida"); 
            break;
    }

    limparTela();
    printf("\n╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║          LISTAGEM DE MASSOTERAPEUTAS - ESPECIALIDADE: %-12s   ║\n", nomeEspecialidade);
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");

    fp = fopen(MASSOTERAPEUTAS_FILE, "rb");
    if (fp == NULL) {
        printf("Nenhum massoterapeuta cadastrado ainda.\n");
        free(massoterapeuta);
        pausar();
        return;
    }

    printf("═══════════════════════════════════════════════════════════════════════════════════════════\n");
    printf("Nome                     Telefone       Email                  CREFITO      Especialidade\n");
    printf("═══════════════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
        if (massoterapeuta->status == 1) {
            if (toupper(massoterapeuta->especialidade[0]) == especialidade) {
                printf("%-24s %-14s %-22s %-12s %s\n",
                       massoterapeuta->nome,
                       massoterapeuta->telefone,
                       massoterapeuta->email,
                       massoterapeuta->crefito,
                       massoterapeuta->especialidade);
                encontrou = 1;
            }
        }
    }
    
    printf("═══════════════════════════════════════════════════════════════════════════════════════════\n");

    if (!encontrou) {
        printf("\nNenhum massoterapeuta encontrado para a especialidade '%s'.\n", nomeEspecialidade);
    }

    fclose(fp);
    free(massoterapeuta);
    pausar();
}

// Relatórios com dados de várias fontes

void agendamentoListandoNomes(){
    FILE *fp;
    Agendamento *agendamento = (Agendamento*)malloc(sizeof(Agendamento));

    fp = fopen(ARQUIVO_AGENDAMENTOS, "rb");
    if (fp == NULL) {
        printf("Nenhum agendamento cadastrado ainda.\n");
        free(agendamento);
        pausar();
        return;
    }

    printf("══════════════════════════════════════════════════════════════════════════════════\n");
    printf("                              AGENDAMENTOS COM NOMES                              \n");
    printf("══════════════════════════════════════════════════════════════════════════════════\n");
    printf("ID   Nome Cliente      Nome Massoterapeuta   Tipo Massagem     Data      Hora\n");
    printf("══════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(agendamento, sizeof(Agendamento), 1, fp)) {
        if (agendamento->status == 1) {
            char* nomeCliente = getNomeClientePorCPF(agendamento->cpfCliente);
            char* nomeMassoterapeuta = getNomeMassoterapeutaPorCrefito(agendamento->crefitoMassoterapeuta);
            char* tipoMassagem = getTipoMassagemPorCrefito(agendamento->crefitoMassoterapeuta);
            
            printf("%-4s %-18s %-21s %-15s %-11s %-5s\n",
                agendamento->id,
                nomeCliente,
                nomeMassoterapeuta,
                tipoMassagem,
                agendamento->dataAgendada,
                agendamento->hora);
            
            free(nomeCliente);
            free(nomeMassoterapeuta);
            free(tipoMassagem);
        }
    }

    printf("══════════════════════════════════════════════════════════════════════════════════\n");
    fclose(fp);
    free(agendamento);
    pausar();
}

void financeiroListandoNomes() {
    FILE *fp;
    Movimentacao *mov = (Movimentacao*)malloc(sizeof(Movimentacao));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║      LISTAR MOVIMENTAÇÕES FINANCEIRAS        ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    fp = fopen(ARQUIVO_FINANCEIRO, "rb");
    if (fp == NULL) {
        printf("Nenhuma movimentação registrada ainda.\n");
        printf("Use as opções de entrada ou saída para registrar.\n");
        free(mov);
        pausar();
        return;
    }

    printf("════════════════════════════════════════════════════════════════════════════════════════\n");
    printf("Tipo         Valor        Descrição                                Massoterapeuta\n");
    printf("════════════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(mov, sizeof(Movimentacao), 1, fp)) {
        if (mov->status == 1) {
            char *tipo = mov->tipo == 'E' ? "ENTRADA" : "SAÍDA";
            char sinal = mov->tipo == 'E' ? '+' : '-';
            char *nomeMassoterapeuta = getNomeMassoterapeutaPorCpf(mov->cpf);
            
            printf("%-12s %cR$ %-9.2f %-40s %s\n",
                   tipo,
                   sinal,
                   mov->valor,
                   mov->descricao,
                   nomeMassoterapeuta);
        }
    }
    
    printf("════════════════════════════════════════════════════════════════════════════════════════\n");

    fclose(fp);
    free(mov);
    pausar();
}

void relatorios() {
    int opcao;

    do {
        menuRelatorios();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Digite apenas números!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch(opcao) {
            case 1: 
                int opcaoListar;
                do {
                    menuRelatoriosListar(); 
                    if (scanf("%d", &opcaoListar) != 1) {
                        printf("\n Erro: Digite apenas números!\n");
                        limparBuffer();
                        pausar();
                        continue;
                    }

                    switch (opcaoListar){
                    case 1:
                        listarClientesGeral();
                        break;
                    case 2:
                        listarMassoterapeutasGeral();
                        break;
                    case 3:
                        listarProdutosGeral();
                        break;
                    case 4:
                        listarAgendamentosGeral();
                        break;
                    case 5:
                        listarFinanceiroGeral();
                        break;
                    case 0:
                        printf("\n Retornando...\n"); 
                        break;
                    default:
                        printf("\n Opção inválida! Digite um número entre 0 e 5.\n");
                        pausar();
                        break;
                    }
                } while(opcaoListar != 0);
                break;

            case 2: 
                filtrarClientesPorLetra();
                break;
            case 3: 
                filtrarProdutosPorPreco();
                break;
            case 4: 
                filtrarMassoterapeutasPorEspecialidade(); 
                break;
            case 5: 
                agendamentoListandoNomes(); 
                break;
            case 6:
                financeiroListandoNomes();
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n"); 
                break;
            default:
                printf("\n Opção inválida! Digite um número entre 0 e 6.\n");
                pausar();
                break;
        }
    } while(opcao != 0);
}