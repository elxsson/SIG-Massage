/*
|=============================================================|
|                          UTILS                              |
| Funções utilitárias compartilhadas pelo sistema SIG-MASSAGE |
|=============================================================|
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void pausar() {
    printf("\n Pressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    system("clear || cls");
}