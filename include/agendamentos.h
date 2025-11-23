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

void agendamentos();
void menuAgendamentos();
void cadastrarAgendamento();
void listarAgendamentos();
void atualizarAgendamento();
void deletarAgendamento();
int salvarAgendamento(Agendamento *a);

#endif