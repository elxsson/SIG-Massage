#include "clientes.h"

#define ARQUIVO_CLIENTES "clientes.dat"

void menuClientes() {
    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                 MODULO CLIENTE               ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║                                              ║\n");
    printf("║ 1. Cadastrar Cliente                         ║\n");
    printf("║ 2. Listar Clientes                           ║\n");
    printf("║ 3. Procurar Cliente                          ║\n");
    printf("║ 4. Atualizar Dados do Cliente                ║\n");
    printf("║ 5. Exluir Cliente                            ║\n");
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

int atualizarArquivoClientes(Cliente *clientes, int quantidade) {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "wb");
    size_t escritos = fwrite(clientes, sizeof(Cliente), quantidade, arquivo);
    fclose(arquivo);
    return (escritos == quantidade);
}

void cadastrarCliente() {
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            CADASTRAR CLIENTE                 ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    if (!lerNome(cliente->nome, sizeof(cliente->nome))) {
        free(cliente);
        pausar();
        return;
    }

    if (!lerCPF(cliente->cpf, sizeof(cliente->cpf))) {
        free(cliente);
        pausar();
        return;
    }

    if (!lerTelefone(cliente->telefone, sizeof(cliente->telefone))) {
        free(cliente);
        pausar();
        return;
    }

    if (!lerEmail(cliente->email, sizeof(cliente->email))) {
        free(cliente);
        pausar();
        return;
    }

    cliente->status = 1;

    if (salvarCliente(cliente)) {
        printf("\n Cliente cadastrado com sucesso!\n");
    } else {
        printf("\n Erro ao salvar cliente!\n");
    }

    free(cliente);
    pausar();
}

void listarClientes() {
    FILE *fp;
    Cliente *cliente;
    int clientesAtivos = 0;

    cliente = (Cliente*)malloc(sizeof(Cliente));

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            LISTAR CLIENTES                   ║\n");
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
            clientesAtivos++;
        }
    }
    
    printf("════════════════════════════════════════════════════════════════════════════════════\n");

    if (clientesAtivos == 0) {
        printf("Nenhum cliente ativo encontrado.\n");
    } else {
        printf("\nTotal de clientes ativos: %d\n", clientesAtivos);
    }

    fclose(fp);
    free(cliente);
    pausar();
}

void buscarCliente() {
    Cliente *clientes = NULL;
    int quantidade = 0;
    char cpfBusca[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║                BUSCAR CLIENTE                ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    printf("Digite o CPF do cliente: ");
    scanf(" %19s", cpfBusca);
    limparBuffer();

    carregarClientes(&clientes, &quantidade);

    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(clientes[i].cpf, cpfBusca) == 0 && clientes[i].status == 1) {
            printf("\n           Cliente encontrado\n");
            printf("══════════════════════════════════════════════\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Email: %s\n", clientes[i].email);
            printf("══════════════════════════════════════════════\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n Cliente não encontrado ou inativo!\n");
    }

    free(clientes);
    pausar();
}

void atualizarCliente() {
    Cliente *clientes = NULL;
    int quantidade = 0;
    char cpfBusca[20];

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            ATUALIZAR CLIENTE                 ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    listarClientes();

    printf("Digite o CPF do cliente a atualizar: ");
    scanf(" %19s", cpfBusca);
    limparBuffer();

    carregarClientes(&clientes, &quantidade);

    int indice = -1;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(clientes[i].cpf, cpfBusca) == 0 && clientes[i].status == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Cliente não encontrado ou inativo!\n");
        free(clientes);
        pausar();
        return;
    }

    printf("\n Cliente encontrado. Digite os novos dados:\n\n");

    lerNome(clientes[indice].nome, sizeof(clientes[indice].nome));
    lerTelefone(clientes[indice].telefone, sizeof(clientes[indice].telefone));
    lerEmail(clientes[indice].email, sizeof(clientes[indice].email));

    if (atualizarArquivoClientes(clientes, quantidade)) {
        printf("\n Cliente atualizado com sucesso!\n");
    } else {
        printf("\n Erro ao atualizar cliente!\n");
    }

    free(clientes);
    pausar();
}

void deletarCliente() {
    Cliente *clientes = NULL;
    int quantidade = 0;
    char cpfBusca[20];
    char confirmacao;

    limparTela();
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            DELETAR CLIENTE                   ║\n");
    printf("╚══════════════════════════════════════════════╝\n\n");

    listarClientes();

    printf("Digite o CPF do cliente a deletar: ");
    scanf(" %19s", cpfBusca);
    limparBuffer();

    carregarClientes(&clientes, &quantidade);

    int indice = -1;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(clientes[i].cpf, cpfBusca) == 0 && clientes[i].status == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n Cliente não encontrado ou já está inativo!\n");
        free(clientes);
        pausar();
        return;
    }

    printf("\n Cliente encontrado:\n");
    printf("Nome: %s\n", clientes[indice].nome);
    printf("CPF: %s\n", clientes[indice].cpf);
    printf("\nTem certeza que deseja deletar? (S/N): ");
    scanf(" %c", &confirmacao);
    limparBuffer();

    if (confirmacao == 'S' || confirmacao == 's') {
        clientes[indice].status = 0;

        if (atualizarArquivoClientes(clientes, quantidade)) {
            printf("\n Cliente deletado com sucesso!\n");
        } else {
            printf("\n Erro ao deletar cliente!\n");
        }
    } else {
        printf("\n Operação cancelada!\n");
    }

    free(clientes);
    pausar();
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
