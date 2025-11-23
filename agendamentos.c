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

    if (!lerTipoMassagem(agendamento->tipoMassagem, sizeof(agendamento->tipoMassagem))) {
        free(agendamento);
        pausar();
        return;
    }

    char data[11];
    printf("Digite a data para agendar EX(DD/MM/AAAA): ");
    scanf(" %11[^\n]", data);
    strcpy(agendamento->dataAgendada, data);

    char hora[10];
    printf("Digite a hora para agendar EX(HH:MM): ");
    scanf(" %10[^\n]", hora);
    strcpy(agendamento->hora, hora);

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

printf("===================================================================\n");
printf("ID   CPF Cliente     Tipo Massagem        Data Agendada   Hora\n");
printf("===================================================================\n");

while (fread(agendamento, sizeof(Agendamento), 1, fp)) {
    if (agendamento->status == 1) {
        printf("%-3s  %-12s   %-18s   %-11s   %-4s\n",
               agendamento->id,
               agendamento->cpfCliente,
               agendamento->tipoMassagem,
               agendamento->dataAgendada,
               agendamento->hora);
    }
}

printf("===================================================================\n");
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
    int id;
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            ATUALIZAR AGENDAMENTO             ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o ID do agendamento a ser atualizado: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\n Erro: ID inválido!\n");
        limparBuffer();
        pausar();
        return;
    }

    printf("\n Agendamento com ID %d atualizado com sucesso!\n", id);
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
