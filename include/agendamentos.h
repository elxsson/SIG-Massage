#ifndef AGENDAMENTOS_H
#define AGENDAMENTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

typedef struct {
    char id[50];
    char cpfCliente[20];
    char crefitoMassoterapeuta[30];
    char hora[6];
    char dataAgendada[11];
    char dataDoAgendamento[11];
    int status;
} Agendamento;

typedef struct noAgendamento NoAgendamento;

struct noAgendamento {
    Agendamento dados;     
    NoAgendamento* prox;     
};

void agendamentos();
void menuAgendamentos();
void cadastrarAgendamento();
void listarAgendamentos();
void buscarAgendamento();
void atualizarAgendamento();
void deletarAgendamento();
int salvarAgendamento(Agendamento *a);
int carregarAgendamentos(Agendamento **agendamento, int *quantidade);
int atualizarArquivoAgendamentos(Agendamento *agendamento, int quantidade);

#endif