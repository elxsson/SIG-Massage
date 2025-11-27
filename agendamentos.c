/*
|=============================================================|
|                    MODULO AGENDAMENTOS                      |
| CRUD para a gestao de clientes do sistema SIG-MASSAGE       |
|=============================================================|
*/
#include "agendamentos.h"

#define ARQUIVO_AGENDAMENTOS "agendamentos.dat"

void menuAgendamentos() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              MODULO AGENDAMENTOS             ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Cadastrar Agendamento                     ║\n");
    printf("║ 2. Listar Agendamentos                       ║\n");
    printf("║ 3. Buscar Agendamento                        ║\n");
    printf("║ 4. Atualizar Agendamento                     ║\n");
    printf("║ 5. Excluir Agendamento                       ║\n");
    printf("║ 0. Voltar ao Menu Principal                  ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("\n Digite a opção desejada: ");
}

int salvarAgendamento(Agendamento *a) {
    FILE *arquivo = fopen(ARQUIVO_AGENDAMENTOS, "ab");
    size_t escrito = fwrite(a, sizeof(Agendamento), 1, arquivo);
    fclose(arquivo);
    return (escrito == 1);
}

int carregarAgendamentos(Agendamento **agendamento, int *quantidade) {
    FILE *arquivo = fopen(ARQUIVO_AGENDAMENTOS, "rb");
    if (arquivo == NULL) {
        *agendamento = NULL;
        *quantidade = 0;
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    *quantidade = tamanho / sizeof(Agendamento);

    if (*quantidade == 0) {
        *agendamento = NULL;
        fclose(arquivo);
        return 1;
    }

    *agendamento = (Agendamento*)malloc((*quantidade) * sizeof(Agendamento));
    size_t lidos = fread(*agendamento, sizeof(Agendamento), *quantidade, arquivo);
    fclose(arquivo);

    return (lidos == *quantidade);
}

int atualizarArquivoAgendamentos(Agendamento *agendamento, int quantidade) {
    FILE *arquivo = fopen(ARQUIVO_AGENDAMENTOS, "wb");
    size_t escritos = fwrite(agendamento, sizeof(Agendamento), quantidade, arquivo);
    fclose(arquivo);
    return (escritos == quantidade);
}

void cadastrarAgendamento() {
    Agendamento *agendamento = (Agendamento*)malloc(sizeof(Agendamento));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            CADASTRAR AGENDAMENTO             ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    int idInteiro = atribuirId("agendamentos.dat", sizeof(Agendamento));
    sprintf(agendamento->id, "%d", idInteiro); // Converte int para string

    if (!lerCPF(agendamento->cpfCliente, sizeof(agendamento->cpfCliente))) {
        free(agendamento);
        pausar();
        return;
    }

    if (!lerCrefito(agendamento->crefitoMassoterapeuta, sizeof(agendamento->crefitoMassoterapeuta))) {
        free(agendamento);
        pausar();
        return;
    }

    if (!lerData(agendamento->dataAgendada, sizeof(agendamento->dataAgendada))) {
        free(agendamento);
        pausar();
        return;
    }

    if (!lerHora(agendamento->hora, sizeof(agendamento->hora))) {
        free(agendamento);
        pausar();
        return;
    }

    strcpy(agendamento->dataDoAgendamento, atribuirData());
    agendamento->status = 1;

    if (salvarAgendamento(agendamento)) {
        printf("\n Agendamento cadastrado com sucesso!\n");
    } else {
        printf("\n Erro ao salvar Agendamento!\n");
    }

    free(agendamento);
    pausar();
}

void listarAgendamentos() {

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

    printf("===============================================================================\n");
    printf("ID   CPF Cliente      Cod Massoterapeuta     Data Agendada   Hora\n");
    printf("===============================================================================\n");

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

    printf("===============================================================================\n");
        fclose(fp);
        free(agendamento);
        pausar();
}

void buscarAgendamento() {
    int id;
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║              BUSCAR AGENDAMENTO              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o ID do agendamento a ser buscado: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\n Erro: ID inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Nenhum agendamento encontrado com o ID %d.\n", id);
    pausar();
}

void atualizarAgendamento() {
    Agendamento *agendamento = (Agendamento*)malloc(sizeof(Agendamento));
    int quantidade = 0;
    char IdBusca[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            ATUALIZAR AGENDAMENTOS            ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    listarAgendamentos();

    printf("Digite o ID do agendamento a atualizar: ");
    scanf(" %19s", IdBusca);
    limparBuffer();

    carregarAgendamentos(&agendamento, &quantidade);

    int indice = -1;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(agendamento[i].id, IdBusca) == 0 && agendamento[i].status == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Agendamento não encontrado ou inativo!\n");
        free(agendamento);
        pausar();
        return;
    }

    printf("\n Agendamento encontrado. Digite os novos dados:\n\n");


    lerCPF(agendamento[indice].cpfCliente, sizeof(agendamento[indice].cpfCliente));
    lerCrefito(agendamento[indice].crefitoMassoterapeuta, sizeof(agendamento[indice].crefitoMassoterapeuta));
    lerData(agendamento[indice].dataAgendada, sizeof(agendamento[indice].dataAgendada));
    lerHora(agendamento[indice].hora, sizeof(agendamento[indice].hora));


    if (atualizarArquivoAgendamentos(agendamento, quantidade)) {
        printf("\n Agendamento atualizado com sucesso!\n");
    } else {
        printf("\n Erro ao atualizar agendamento!\n");
    }

    free(agendamento);
    pausar();

}

void deletarAgendamento() {
    int id;
    char confirmacao;
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             EXCLUIR AGENDAMENTO              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o ID do agendamento a ser excluído: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\n Erro: ID inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("Tem certeza que deseja excluir? (s/N): ");
    limparBuffer();
    scanf("%c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        printf("\n Função de exclusão de agendamento ainda não implementada.\n");
        printf("ID que seria excluído: %i\n",id);
    } else {    
        printf("\n Operação cancelada pelo usuário.\n");   
    }
    
    pausar();

}

void agendamentos() {
    int opcao;
    do {
        menuAgendamentos();
        if (scanf("%d", &opcao) != 1) {
            printf("\n Erro: Entrada inválida!\n");
            limparBuffer();
            pausar();
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarAgendamento();
                break;
            case 2:
                listarAgendamentos();
                break;
            case 3:
                buscarAgendamento();
                break;
            case 4:
                atualizarAgendamento();
                break;
            case 5:
                deletarAgendamento();
                break;
            case 0:
                printf("\n Retornando ao menu principal...\n");
                break;
            default:
                printf("\n Erro: Opção inválida!\n");
                pausar();
                break;
        }

    } while (opcao != 0);
}
