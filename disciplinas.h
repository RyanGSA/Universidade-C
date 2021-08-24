#include <stdio.h>
#include <stdlib.h>

struct disciplina {
  int id;
  char nome[50];
  int cargaHoraria;
};

typedef struct disciplina Disciplina;

char arquivoDisciplinas[50];

void carregarDisciplinas(Disciplina **disciplinas);

int verificarSeDisciplinaExistePorId(int idDisciplina);

Disciplina retornaDisciplinaPorId(int idDisciplina);

void listarDisciplinas(Disciplina **disciplinas);

void listarDisciplinaPorId(Disciplina **disciplinas);

void inserirDisciplina(Disciplina **disciplinas);

void removerDisciplinaPorId(Disciplina **disciplinas);
