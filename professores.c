#include <stdio.h>
#include <stdlib.h>
#include "professores.h"
#include "disciplinas.h"
#include "professores_disciplinas.h"

char arquivoProfessores[50] = "professores.txt";

void carregarProfessores(Professor **professores) {
  FILE *fr = fopen(arquivoProfessores, "r");

  int quantidadeProfessores;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessores > 0) {
    *professores = realloc(*professores, sizeof(Professor) * quantidadeProfessores);

    for (int i = 0; i < quantidadeProfessores; i++) {
      if (feof(fr)) {
        break;
      }

      fscanf(fr, "%d", &(*professores)[i].id);
      fscanf(fr, " %[^\n]", (*professores)[i].nome);
      fscanf(fr, " %[^\n]", (*professores)[i].formacao);
      fscanf(fr, "%f", &(*professores)[i].salario);
    }
  }

  fclose(fr);
}

int verificarSeProfessorExistePorId(int idProfessor) {
  FILE *fr = fopen(arquivoProfessores, "r");

  int quantidadeProfessores;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  int existe = 0;

  if (quantidadeProfessores > 0) {
    for (int i = 0; i < quantidadeProfessores; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      char nome[100];
      char formacao[50];
      float salario;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%s", nome);
      fscanf(fr, "%s", formacao);
      fscanf(fr, "%f", &salario);

      if (idAtual == idProfessor) {
        existe = 1;
        break;
      }
    }
  }

  fclose(fr);
  return existe;
}

Professor retornaProfessorPorId(int idProfessor) {
  FILE *fr = fopen(arquivoProfessores, "r");

  int quantidadeProfessores;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  Professor professorEncontrado;

  if (quantidadeProfessores > 0) {
    for (int i = 0; i < quantidadeProfessores; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      char nome[100];
      char formacao[50];
      float salario;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%s", nome);
      fscanf(fr, "%s", formacao);
      fscanf(fr, "%f", &salario);

      if (idAtual == idProfessor) {
        professorEncontrado.id = idAtual;

        for (int i = 0 ; i < 100; i++) {
          professorEncontrado.nome[i] = nome[i];
        }

        for (int i = 0 ; i < 50; i++) {
          professorEncontrado.formacao[i] = formacao[i];
        }

        professorEncontrado.salario = salario;
        break;
      }
    }
  }

  fclose(fr);
  return professorEncontrado;
}

void listarProfessores(Professor **professores){
  FILE *fr = fopen(arquivoProfessores, "r");

  int quantidadeProfessores, numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessores > 0){
    printf("\n------------------------------------------------\n");
    for(int i = 0; i < quantidadeProfessores; i++){
      printf("ID: %d\n", (*professores)[i].id);
      printf("Nome: %s\n", (*professores)[i].nome);
      printf("Formacao: %s\n", (*professores)[i].formacao);
      printf("Salario: R$ %.2f\n", (*professores)[i].salario);
      printf("------------------------------------------------\n");
    }
  }
  else {
    printf("\nNAO EXISTE NENHUM PROFESSOR CADASTRADO!\n");
  }

  printf("\n\n");

  fclose(fr);
}


void listarProfessorPorId(Professor **professores){
  FILE *fr = fopen(arquivoProfessores, "r");

  int idProfessor;

  printf("\nInforme o id do professor: ");
  scanf("%d",&idProfessor);

  int quantidadeProfessores;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessores > 0){
    int existe = verificarSeProfessorExistePorId(idProfessor);

    if (existe == 1) {
      printf("\n------------------------------------------------\n");
      for(int i = 0; i < quantidadeProfessores; i++){
        if ((*professores)[i].id == idProfessor){
          printf("ID: %d\n", (*professores)[i].id);
          printf("Nome: %s\n", (*professores)[i].nome);
          printf("Formacao: %s\n", (*professores)[i].formacao);
          printf("Salario: R$ %.2f\n", (*professores)[i].salario);
          printf("------------------------------------------------\n");
        }
      }
    }

    else {
      printf("\n\nPROFESSOR NAO ENCONTRADO!\n");
    }
  }

  else {
    printf("\n\nNAO EXISTE NENHUM PROFESSOR CADASTRADO!\n");
  }

  printf("\n\n");

  fclose(fr);
}

void inserirProfessor(Professor **professores){
  FILE *fr = fopen(arquivoProfessores, "r");

  int quantidadeProfessores, numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  fclose(fr);

  quantidadeProfessores++;
  numeroUltimoId++;

  *professores = realloc(*professores, sizeof(Professor) * quantidadeProfessores);

  printf("\nInforme o nome do professor: ");
  scanf(" %[^\n]", (*professores)[quantidadeProfessores - 1].nome);
  printf("Informe a formacao do professor: ");
  scanf(" %[^\n]", (*professores)[quantidadeProfessores - 1].formacao);
  printf("Informe o salario do professor, em reais: ");
  scanf("%f", &(*professores)[quantidadeProfessores - 1].salario);

  (*professores)[quantidadeProfessores - 1].id = numeroUltimoId;

  FILE *fw = fopen(arquivoProfessores, "w");

  fprintf(fw, "%d\n", quantidadeProfessores);
  fprintf(fw, "%d\n", numeroUltimoId);

  for(int i = 0; i < quantidadeProfessores; i++){
    fprintf(fw, "%d\n",(*professores)[i].id);
    fprintf(fw, "%s\n", (*professores)[i].nome);
    fprintf(fw, "%s\n", (*professores)[i].formacao);
    fprintf(fw, "%.2f\n", (*professores)[i].salario);
  }

  printf("\n\nPROFESSOR INSERIDO COM SUCESSO!\n\n\n");

  fclose(fw);
}

void removerProfessorPorId(Professor **professores){
  FILE *fr = fopen(arquivoProfessores, "r");

  int quantidadeProfessores, numeroUltimoId;
  int idProfessor;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  fclose(fr);

  printf("\nInforme o id: ");
  scanf("%d", &idProfessor);

  if (quantidadeProfessores > 0) {
    int existe = verificarSeProfessorExistePorId(idProfessor);

    if(existe == 1) {
      int existeAssociacao = verificarSeAssociacaoExistePorProfessor(idProfessor);

      if(existeAssociacao == 0){
        FILE *fw = fopen(arquivoProfessores, "w");

        fprintf(fw, "%d\n", quantidadeProfessores-1);
        fprintf(fw, "%d\n", numeroUltimoId);

        for(int i = 0; i < quantidadeProfessores; i++){
          if((*professores)[i].id != idProfessor){
            fprintf(fw, "%d\n", (*professores)[i].id);
            fprintf(fw, "%s\n", (*professores)[i].nome);
            fprintf(fw, "%s\n", (*professores)[i].formacao);
            fprintf(fw, "%.2f\n", (*professores)[i].salario);
          }
        }

        printf("\n\nPROFESSOR EXCLUIDO COM SUCESSO!");
        fclose(fw);
      }

      else {
        printf("\n\nPROFESSOR ESTA ASSOCIADO A UMA DISCIPLINA");
      }
    }

    else {
      printf("\n\nPROFESSOR NAO ENCONTRADO!");
    }
  }

  else {
    printf("\n\nNAO EXISTE NENHUM PROFESSOR!");
  }

  printf("\n\n\n");

  carregarProfessores(professores);
  fclose(fr);
}
