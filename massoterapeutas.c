/*
 |===========================================================================|
 |                         MÓDULO MASSOTERAPEUTAS                           |
 |        CRUD para Gestão de Massoterapeutas do SIG-MASSAGE                |
 |===========================================================================|
*/

#include <stdio.h>
#include <stdlib.h>

void pausar() {
    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mostrarMenuMassoterapeutas() {
    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║             MODULO MASSOTERAPEUTA           ║\n");
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

void cadastroMassoterapeuta() {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
    char especialidade[50];

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║           CADASTRAR MASSOTERAPEUTA          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do massoterapeuta: ");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Digite o CPF do massoterapeuta: ");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Digite o telefone do massoterapeuta: ");
    if (scanf(" %19s", telefone) != 1) {
        printf("\n Erro: Telefone inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Digite o email do massoterapeuta: ");
    if (scanf(" %69s", email) != 1) {
        printf("\n Erro: Email inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    limparBuffer();
    printf("Digite a especialidade do massoterapeuta: ");
    if (scanf(" %49[^\n]", especialidade) != 1) {
        printf("\n Erro: Especialidade inválida!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("\n Massoterapeuta %s cadastrado com sucesso!\n", nome);
    pausar();
}

void listarMassoterapeutas() {
    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            LISTAR MASSOTERAPEUTAS           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    // Simulando que não há dados ainda
    printf("Nenhum massoterapeuta cadastrado ainda.\n");
    printf("Para cadastrar um massoterapeuta, escolha a opção 1 no menu.\n");
    
    pausar();
}

void buscarMassoterapeuta() {
    char nome[70];

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║           PROCURAR MASSOTERAPEUTA           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o nome do massoterapeuta que deseja buscar: ");
    if (scanf(" %69[^\n]", nome) != 1) {
        printf("\n Erro: Nome inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Função de busca de massoterapeuta ainda não implementada.\n");
    printf("Busca seria feita por: %s\n", nome);
    
    pausar();
}

void atualizarMassoterapeuta() {
    char cpf[20];

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║      ATUALIZAR DADOS DO MASSOTERAPEUTA       ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o CPF do massoterapeuta que deseja atualizar: ");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Função de atualização de massoterapeuta ainda não implementada.\n");
    printf("CPF informado: %s\n", cpf);
    
    pausar();
}

void deletarMassoterapeuta() {
    char cpf[20];
    char confirmacao;

    system("clear || cls");
    printf("\n╔══════════════════════════════════════════════╗\n");
    printf("║            EXCLUIR MASSOTERAPEUTA           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    
    printf("Digite o CPF do massoterapeuta que deseja excluir: ");
    if (scanf(" %19s", cpf) != 1) {
        printf("\n Erro: CPF inválido!\n");
        limparBuffer();
        pausar();
        return;
    }
    
    printf("Tem certeza que deseja excluir? (s/N): ");
    limparBuffer();
    scanf("%c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        printf("\n Função de exclusão de massoterapeuta ainda não implementada.\n");
        printf("CPF que seria excluído: %s\n", cpf);
    } else {
        printf("\n Operação cancelada pelo usuário.\n");
    }
    
    pausar();
}

