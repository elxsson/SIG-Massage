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
