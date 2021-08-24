#include <stdio.h>
#include <stdlib.h>

struct professor {
  int id;
  char nome[100];
  char formacao[50];
  float salario;
};

typedef struct professor Professor;

char arquivoProfessores[50];

void carregarProfessores(Professor **professores);

int verificarSeProfessorExistePorId(int idProfessor);

Professor retornaProfessorPorId(int idProfessor);

void listarProfessores(Professor **professores);

void listarProfessorPorId(Professor **professores);

void inserirProfessor(Professor **professores);

void removerProfessorPorId(Professor **professores);
