#include "massoterapeutas.h"

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
    
    if (!lerNome(massoterapeuta->nome, sizeof(massoterapeuta->nome))) {
        free(massoterapeuta);
        pausar();
        return;
    }

    if (!lerCPF(massoterapeuta->cpf, sizeof(massoterapeuta->cpf))) {
        free(massoterapeuta);
        pausar();
        return;
    }

    if (!lerTelefone(massoterapeuta->telefone, sizeof(massoterapeuta->telefone))) {
        free(massoterapeuta);
        pausar();
        return;
    }

    if (!lerEmail(massoterapeuta->email, sizeof(massoterapeuta->email))) {
        free(massoterapeuta);
        pausar();
        return;
    }

    if (!lerCrefito(massoterapeuta->crefito, sizeof(massoterapeuta->crefito))) {
        free(massoterapeuta);
        pausar();
        return;
    }

    if (!lerEspecialidade(massoterapeuta->especialidade, sizeof(massoterapeuta->especialidade))) {
        free(massoterapeuta);
        pausar();
        return;
    }

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

    printf("══════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
    printf("Nome                     CPF              Telefone       Email                  CREFITO       Especialidade   \n");
    printf("══════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(massoterapeuta, sizeof(Massoterapeutas), 1, fp)) {
        if (massoterapeuta->status == 1) {
            printf("%-24s %-16s %-14s %-22s %-12s %s\n",
                   massoterapeuta->nome,
                   massoterapeuta->cpf,
                   massoterapeuta->telefone,
                   massoterapeuta->email,
                   massoterapeuta->crefito,
                   massoterapeuta->especialidade);
            massoterapeutasAtivos++;
        }
    }
    
    printf("══════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");

    if (massoterapeutasAtivos == 0) {
        printf("Nenhum massoterapeuta ativo encontrado.\n");
    } else {
        printf("\nTotal de massoterapeutas ativos: %d\n", massoterapeutasAtivos);
    }

    fclose(fp);
    free(massoterapeuta);
    pausar();
}

void buscarMassoterapeuta() {
    Massoterapeutas *massoterapeutas = NULL;
    int quantidade = 0;
    char cpfBusca[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            PROCURAR MASSOTERAPEUTA           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o CPF do massoterapeuta: ");
    scanf(" %19s", cpfBusca);
    limparBuffer();

    carregarMassoterapeutas(&massoterapeutas, &quantidade);

    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(massoterapeutas[i].cpf, cpfBusca) == 0 && massoterapeutas[i].status == 1) {
            printf("\n       Massoterapeuta encontrado \n");
            printf("═══════════════════════════════════════════════\n");
            printf("Nome: %s\n", massoterapeutas[i].nome);
            printf("CPF: %s\n", massoterapeutas[i].cpf);
            printf("Telefone: %s\n", massoterapeutas[i].telefone);
            printf("Email: %s\n", massoterapeutas[i].email);
            printf("CREFITO: %s\n", massoterapeutas[i].crefito);
            printf("Especialidade: %s\n", massoterapeutas[i].especialidade);
            printf("═══════════════════════════════════════════════\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n Massoterapeuta não encontrado ou inativo!\n");
    }

    free(massoterapeutas);
    pausar();
}

void atualizarMassoterapeuta() {
    Massoterapeutas *massoterapeutas = NULL;
    int quantidade = 0;
    char cpfBusca[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║       ATUALIZAR DADOS DO MASSOTERAPEUTA      ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o CPF do massoterapeuta a atualizar: ");
    scanf(" %19s", cpfBusca);
    limparBuffer();

    carregarMassoterapeutas(&massoterapeutas, &quantidade);

    int indice = -1;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(massoterapeutas[i].cpf, cpfBusca) == 0 && massoterapeutas[i].status == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Massoterapeuta não encontrado ou inativo!\n");
        free(massoterapeutas);
        pausar();
        return;
    }

    printf("\n Massoterapeuta encontrado. Digite os novos dados:\n\n");

    printf("Digite o nome: ");
    scanf(" %69[^\n]", massoterapeutas[indice].nome);
    limparBuffer();

    printf("Digite o telefone: ");
    scanf(" %19s", massoterapeutas[indice].telefone);
    limparBuffer();

    printf("Digite o email: ");
    scanf(" %69s", massoterapeutas[indice].email);
    limparBuffer();

    printf("Digite o CREFITO: ");
    scanf(" %19s", massoterapeutas[indice].crefito);
    limparBuffer();

    printf("Digite a especialidade: ");
    scanf(" %49[^\n]", massoterapeutas[indice].especialidade);
    limparBuffer();

    if (atualizarArquivoMassoterapeutas(massoterapeutas, quantidade)) {
        printf("\n Massoterapeuta atualizado com sucesso!\n");
    } else {
        printf("\n Erro ao atualizar massoterapeuta!\n");
    }

    free(massoterapeutas);
    pausar();
}

void deletarMassoterapeuta() {
    Massoterapeutas *massoterapeutas = NULL;
    int quantidade = 0;
    char cpfBusca[20];
    char confirmacao;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            EXCLUIR MASSOTERAPEUTA            ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    printf("Digite o CPF do massoterapeuta a deletar: ");
    scanf(" %19s", cpfBusca);
    limparBuffer();

    carregarMassoterapeutas(&massoterapeutas, &quantidade);

    int indice = -1;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(massoterapeutas[i].cpf, cpfBusca) == 0 && massoterapeutas[i].status == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Massoterapeuta não encontrado ou já está inativo!\n");
        free(massoterapeutas);
        pausar();
        return;
    }

    printf("\n Massoterapeuta encontrado:\n");
    printf("Nome: %s\n", massoterapeutas[indice].nome);
    printf("CPF: %s\n", massoterapeutas[indice].cpf);
    printf("\nTem certeza que deseja deletar? (S/N): ");
    scanf(" %c", &confirmacao);
    limparBuffer();

    if (confirmacao == 'S' || confirmacao == 's') {
        massoterapeutas[indice].status = 0;

        if (atualizarArquivoMassoterapeutas(massoterapeutas, quantidade)) {
            printf("\n Massoterapeuta deletado com sucesso!\n");
        } else {
            printf("\n Erro ao deletar massoterapeuta!\n");
        }
    } else {
        printf("\n Operação cancelada!\n");
    }

    free(massoterapeutas);
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