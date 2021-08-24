#include <stdio.h>
#include <stdlib.h>
#include "professores.h"
#include "disciplinas.h"
#include "professores_disciplinas.h"

char arquivoProfessoresDisciplinas[50] = "professores_disciplinas.txt";

void carregarProfessoresDisciplinas(ProfessorDisciplina **professoresDisciplinas) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessoresDisciplinas > 0) {
    *professoresDisciplinas = realloc(*professoresDisciplinas, sizeof(ProfessorDisciplina) * quantidadeProfessoresDisciplinas);

    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      fscanf(fr, "%d", &(*professoresDisciplinas)[i].id);
      fscanf(fr, "%d", &(*professoresDisciplinas)[i].idProfessor);
      fscanf(fr, "%d", &(*professoresDisciplinas)[i].idDisciplina);
    }
  }

  fclose(fr);
}

int verificarSeAssociacaoExistePorId(int idAssociacao) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  int existe = 0;

  if (quantidadeProfessoresDisciplinas > 0) {
    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      int idProfessorAtual;
      int idDisciplinaAtual;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%d", &idProfessorAtual);
      fscanf(fr, "%d", &idDisciplinaAtual);

      if (idAtual == idAssociacao) {
        existe = 1;
        break;
      }
    }
  }

  fclose(fr);
  return existe;
}

int verificarSeAssociacaoExistePorProfessorEDisciplina(int idProfessor, int idDisciplina) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  int existe = 0;

  if (quantidadeProfessoresDisciplinas > 0) {
    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      int idProfessorAtual;
      int idDisciplinaAtual;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%d", &idProfessorAtual);
      fscanf(fr, "%d", &idDisciplinaAtual);

      if (idProfessor == idProfessorAtual && idDisciplina == idDisciplinaAtual) {
        existe = 1;
        break;
      }
    }
  }

  fclose(fr);
  return existe;
}

int verificarSeAssociacaoExistePorProfessor(int idProfessor) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  int existe = 0;

  if (quantidadeProfessoresDisciplinas > 0) {
    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      int idProfessorAtual;
      int idDisciplinaAtual;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%d", &idProfessorAtual);
      fscanf(fr, "%d", &idDisciplinaAtual);

      if (idProfessor == idProfessorAtual) {
        existe = 1;
        break;
      }
    }
  }

  fclose(fr);
  return existe;
}

int verificarSeAssociacaoExistePorDisciplina(int idDisciplina) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  int existe = 0;

  if (quantidadeProfessoresDisciplinas > 0) {
    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      int idProfessorAtual;
      int idDisciplinaAtual;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%d", &idProfessorAtual);
      fscanf(fr, "%d", &idDisciplinaAtual);

      if (idDisciplina == idDisciplinaAtual) {
        existe = 1;
        break;
      }
    }
  }

  fclose(fr);
  return existe;
}

void listarProfessoresDisciplinas(ProfessorDisciplina **professoresDisciplinas) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessoresDisciplinas > 0) {
    printf("\n------------------------------------------------\n");

    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      Professor professorAtual = retornaProfessorPorId((*professoresDisciplinas)[i].idProfessor);
      Disciplina disciplinaAtual = retornaDisciplinaPorId((*professoresDisciplinas)[i].idDisciplina);

      printf("ID: %d\n", (*professoresDisciplinas)[i].id);
      printf("Nome do professor: %s\n", professorAtual.nome);
      printf("Nome da disciplina: %s\n", disciplinaAtual.nome);
      printf("------------------------------------------------\n");
    }
  }

  else {
    printf("\nNAO EXISTE NENHUM PROFESSOR ASSOCIADO A UMA DISCIPLINA!\n");
  }

  printf("\n\n");

  fclose(fr);
}

void listarProfessorDisciplinaPorId(ProfessorDisciplina **professoresDisciplinas) {
  int idProfessorDisciplina;

  printf("\nInforme o id: ");
  scanf("%d", &idProfessorDisciplina);

  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessoresDisciplinas > 0) {
    int existe = verificarSeAssociacaoExistePorId(idProfessorDisciplina);

    if (existe == 1) {
      printf("\n------------------------------------------------\n");
      for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
        if ((*professoresDisciplinas)[i].id == idProfessorDisciplina) {
          Professor professorAtual = retornaProfessorPorId((*professoresDisciplinas)[i].idProfessor);
          Disciplina disciplinaAtual = retornaDisciplinaPorId((*professoresDisciplinas)[i].idDisciplina);

          printf("ID: %d\n", (*professoresDisciplinas)[i].id);
          printf("Nome do professor: %s\n", professorAtual.nome);
          printf("Nome da disciplina: %s\n", disciplinaAtual.nome);
          printf("------------------------------------------------\n");
        }
      }
    }

    else {
      printf("\n\nASSOCIACAO NAO ENCONTRADA!\n");
    }
  }

  else {
    printf("\n\nNAO EXISTE NENHUM PROFESSOR ASSOCIADO A UMA DISCIPLINA!\n");
  }

  printf("\n\n");

  fclose(fr);
}

void inserirProfessorDisciplina(ProfessorDisciplina **professoresDisciplinas) {
  int idProfessor;
  int idDisciplina;

  printf("\nInforme o id do professor: ");
  scanf("%d", &idProfessor);
  printf("Informe o id do disciplina: ");
  scanf("%d", &idDisciplina);

  int professorJaExiste = verificarSeProfessorExistePorId(idProfessor);
  int disciplinaJaExiste = verificarSeDisciplinaExistePorId(idDisciplina);

  int professorDisciplinaJaExiste = verificarSeAssociacaoExistePorProfessorEDisciplina(idProfessor, idDisciplina);

  if (professorDisciplinaJaExiste == 0 && professorJaExiste == 1 && disciplinaJaExiste == 1) {
    FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

    int quantidadeProfessoresDisciplinas;
    int numeroUltimoId;

    fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
    fscanf(fr, "%d", &numeroUltimoId);

    fclose(fr);

    quantidadeProfessoresDisciplinas++;

    *professoresDisciplinas = realloc(*professoresDisciplinas, sizeof(ProfessorDisciplina) * quantidadeProfessoresDisciplinas);
    (*professoresDisciplinas)[quantidadeProfessoresDisciplinas - 1].id = numeroUltimoId + 1;
    (*professoresDisciplinas)[quantidadeProfessoresDisciplinas - 1].idProfessor = idProfessor;
    (*professoresDisciplinas)[quantidadeProfessoresDisciplinas - 1].idDisciplina = idDisciplina;

    FILE *fw = fopen(arquivoProfessoresDisciplinas, "w");

    fprintf(fw, "%d\n", quantidadeProfessoresDisciplinas);
    fprintf(fw, "%d\n", (*professoresDisciplinas)[quantidadeProfessoresDisciplinas - 1].id);

    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      fprintf(fw, "%d\n", (*professoresDisciplinas)[i].id);
      fprintf(fw, "%d\n", (*professoresDisciplinas)[i].idProfessor);
      fprintf(fw, "%d\n", (*professoresDisciplinas)[i].idDisciplina);
    }

    fclose(fw);
    printf("\n\nASSOCIACAO INSERIDA COM SUCESSO!\n\n\n");
  }

  else if (professorJaExiste == 0) {
    printf("\n\nPROFESSOR NAO EXISTE!\n\n\n");
  }

  else if (disciplinaJaExiste == 0) {
    printf("\n\nDISCIPLINA NAO EXISTE!\n\n\n");
  }

  else if (professorDisciplinaJaExiste == 1) {
    printf("\n\nASSOCIACAO JA EXISTE!\n\n\n");
  }
}

void removerProfessorDisciplinaPorId(ProfessorDisciplina **professoresDisciplinas) {
  int idProfessorDisciplina;

  printf("\nInforme o id: ");
  scanf("%d", &idProfessorDisciplina);

  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  fclose(fr);

  if (quantidadeProfessoresDisciplinas > 0) {
    int existe = verificarSeAssociacaoExistePorId(idProfessorDisciplina);

    if (existe == 1) {
      FILE *fw = fopen(arquivoProfessoresDisciplinas, "w");

      fprintf(fw, "%d\n", (quantidadeProfessoresDisciplinas - 1));
      fprintf(fw, "%d\n", (*professoresDisciplinas)[quantidadeProfessoresDisciplinas - 1].id);

      for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
        if ((*professoresDisciplinas)[i].id != idProfessorDisciplina) {
          fprintf(fw, "%d\n", (*professoresDisciplinas)[i].id);
          fprintf(fw, "%d\n", (*professoresDisciplinas)[i].idProfessor);
          fprintf(fw, "%d\n", (*professoresDisciplinas)[i].idDisciplina);
        }
      }

      fclose(fw);

      carregarProfessoresDisciplinas(professoresDisciplinas);

      printf("\n\nASSOCIACAO REMOVIDA COM SUCESSO!");
    }

    else {
      printf("\n\nASSOCIACAO NAO ENCONTRADA!");
    }
  }

  else {
    printf("\n\nNAO EXISTE NENHUM PROFESSOR ASSOCIADO A UMA DISCIPLINA!");
  }

  printf("\n\n\n");

  fclose(fr);
}
