#include <stdio.h>
#include <stdlib.h>

struct professorDisciplina {
  int id;
  int idProfessor;
  int idDisciplina;
};

typedef struct professorDisciplina ProfessorDisciplina;

char arquivoProfessoresDisciplinas[50];

void carregarProfessoresDisciplinas(ProfessorDisciplina **professoresDisciplinas);

int verificarSeAssociacaoExistePorId(int idAssociacao);

int verificarSeAssociacaoExistePorProfessorEDisciplina(int idProfessor, int idDisciplina);

int verificarSeAssociacaoExistePorProfessor(int idProfessor);

int verificarSeAssociacaoExistePorDisciplina(int idDisciplina);

void listarProfessoresDisciplinas(ProfessorDisciplina **professoresDisciplinas);

void listarProfessorDisciplinaPorId(ProfessorDisciplina **professoresDisciplinas);

void inserirProfessorDisciplina(ProfessorDisciplina **professoresDisciplinas);

void removerProfessorDisciplinaPorId(ProfessorDisciplina **professoresDisciplinas);
