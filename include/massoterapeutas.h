#ifndef MASSOTERAPEUTA_H
#define MASSOTERAPEUTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

typedef struct {
    char nome[70];
    char cpf[20];
    char telefone[20];
    char email[70];
    char crefito[20];
    char especialidade[50];
    int status;
} Massoterapeutas;

typedef enum {
    Relaxante = 1,
    Terapeutica,
    Esportiva,
    Quiropratica,
    Ayurvedica
} Especialidade;

void massoterapeutas();
void menuMassoterapeutas();
void cadastrarMassoterapeuta();
void listarMassoterapeutas();
void buscarMassoterapeuta();
void atualizarMassoterapeuta();
void deletarMassoterapeuta();
int salvarMassoterapeuta(Massoterapeutas *m);
int carregarMassoterapeutas(Massoterapeutas **massoterapeutas, int *quantidade);
int atualizarArquivoMassoterapeutas(Massoterapeutas *massoterapeutas, int quantidade);

#endif