#include <stdio.h>
#include <stdlib.h>
#include "professores.h"
#include "disciplinas.h"
#include "professores_disciplinas.h"

char arquivoDisciplinas[50] = "disciplinas.txt";

void carregarDisciplinas(Disciplina **disciplinas) {
  FILE *fr = fopen(arquivoDisciplinas, "r");

  int quantidadeDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeDisciplinas > 0) {
    *disciplinas = realloc(*disciplinas, sizeof(Disciplina) * quantidadeDisciplinas);

    for (int i = 0; i < quantidadeDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      fscanf(fr, "%d", &(*disciplinas)[i].id);
      fscanf(fr, " %[^\n]", (*disciplinas)[i].nome);
      fscanf(fr, "%d", &(*disciplinas)[i].cargaHoraria);
    }
  }

  fclose(fr);
}

int verificarSeDisciplinaExistePorId(int idDisciplina) {
  FILE *fr = fopen(arquivoDisciplinas, "r");

  int quantidadeDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  int existe = 0;

  if (quantidadeDisciplinas > 0) {
    for (int i = 0; i < quantidadeDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      char nome[50];
      int cargaHoraria;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%s", nome);
      fscanf(fr, "%d", &cargaHoraria);

      if (idDisciplina == idAtual) {
        existe = 1;
        break;
      }
    }
  }

  fclose(fr);
  return existe;
}

Disciplina retornaDisciplinaPorId(int idDisciplina) {
  FILE *fr = fopen(arquivoDisciplinas, "r");

  int quantidadeDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  Disciplina disciplinaEncontrada;

  if (quantidadeDisciplinas > 0) {
    for (int i = 0; i < quantidadeDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      int idAtual;
      char nome[50];
      int cargaHoraria;

      fscanf(fr, "%d", &idAtual);
      fscanf(fr, "%s", nome);
      fscanf(fr, "%d", &cargaHoraria);

      if (idDisciplina == idAtual) {
        disciplinaEncontrada.id = idAtual;

        for (int i = 0; i < 50; i++) {
          disciplinaEncontrada.nome[i] = nome[i];
        }

        disciplinaEncontrada.cargaHoraria = cargaHoraria;
        break;
      }
    }
  }

  fclose(fr);
  return disciplinaEncontrada;
}

void listarDisciplinas(Disciplina **disciplinas){
  FILE *fr = fopen(arquivoDisciplinas, "r");

  int quantidadeDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  fclose(fr);

  if (quantidadeDisciplinas > 0){
    printf("\n------------------------------------------------\n");
    for (int i = 0; i < quantidadeDisciplinas; i++) {
      printf("ID: %d\n", (*disciplinas)[i].id);
      printf("Nome: %s\n", (*disciplinas)[i].nome);
      printf("Carga horaria: %d Horas\n", (*disciplinas)[i].cargaHoraria);
      printf("------------------------------------------------\n");
    }
  }
  else{
    printf("\n\nNENHUMA DISCIPLINA CADASTRADA!!\n");
  }

  printf("\n\n");
}

void listarDisciplinaPorId(Disciplina **disciplinas){
  FILE *fr = fopen(arquivoDisciplinas, "r");

  int idDisciplina;
  printf("Informe o id: ");
  scanf("%d", &idDisciplina);

  int quantidadeDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  fclose(fr);

  int existe = verificarSeProfessorExistePorId(idDisciplina);

  if (quantidadeDisciplinas > 0){
    if (existe == 1){
      printf("\n------------------------------------------------\n");
      for(int i = 0; i < quantidadeDisciplinas; i++){
        if ((*disciplinas)[i].id == idDisciplina){
          printf("ID: %d\n", (*disciplinas)[i].id);
          printf("Nome: %s\n", (*disciplinas)[i].nome);
          printf("Carga horaria: %d Horas\n", (*disciplinas)[i].cargaHoraria);
          printf("------------------------------------------------\n");
        }
      }
    }

    else{
      printf("\n\nDISCIPLINA NAO ENCONTRADO!\n");
    }
  }

  else{
    printf("\n\nNAO EXISTE NENHUMA DISCIPLINA CADASTRADA!\n");
  }

  printf("\n\n");
}

void inserirDisciplina(Disciplina **disciplinas){
  FILE *fr = fopen(arquivoDisciplinas, "r");

  int quantidadeDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  fclose(fr);

  quantidadeDisciplinas++;
  numeroUltimoId++;

  *disciplinas = realloc(*disciplinas, sizeof(Disciplina)*quantidadeDisciplinas);

  printf("\nInforme o nome da disciplina: ");
  scanf(" %[^\n]", (*disciplinas)[quantidadeDisciplinas-1].nome);
  printf("Informe a carga horaria: ");
  scanf("%d", &(*disciplinas)[quantidadeDisciplinas-1].cargaHoraria);

  (*disciplinas)[quantidadeDisciplinas-1].id = numeroUltimoId;

  FILE *fw = fopen(arquivoDisciplinas, "w");

  fprintf(fw, "%d\n", quantidadeDisciplinas);
  fprintf(fw, "%d\n", numeroUltimoId);

  for (int i = 0; i < quantidadeDisciplinas; i++){
    fprintf(fw, "%d\n", (*disciplinas)[i].id);
    fprintf(fw, "%s\n", (*disciplinas)[i].nome);
    fprintf(fw, "%d\n", (*disciplinas)[i].cargaHoraria);
  }

  fclose(fw);

  printf("\n\nDISCIPLINA INSERIDA COM SUCESSO\n\n\n");
}

void removerDisciplinaPorId(Disciplina **disciplinas){
  int quantidadeDisciplinas;
  int numeroUltimoId;

  int idDisciplina;
  printf("Informe o id: ");
  scanf("%d", &idDisciplina);

  FILE *fr = fopen(arquivoDisciplinas, "r");

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  fclose(fr);

  int existe = verificarSeDisciplinaExistePorId(idDisciplina);

  if (existe == 1){
    int associacao = verificarSeAssociacaoExistePorDisciplina(idDisciplina);

    if (associacao == 0){
      FILE *fw = fopen(arquivoDisciplinas, "w");

      fprintf(fw, "%d\n", quantidadeDisciplinas-1);
      fprintf(fw, "%d\n", numeroUltimoId);

      for (int i = 0; i < quantidadeDisciplinas; i++){
        if ((*disciplinas)[i].id != idDisciplina){
          fprintf(fw, "%d\n", (*disciplinas)[i].id);
          fprintf(fw, "%s\n", (*disciplinas)[i].nome);
          fprintf(fw, "%d\n", (*disciplinas)[i].cargaHoraria);
        }
      }

      printf("\n\nDISCIPLINA APAGADA COM SUCESSO!!\n\n\n");
      fclose(fw);
      carregarDisciplinas(disciplinas);
    }

    else{
      printf("\n\nNAO FOI POSSIVEL EXCLUIR PORQUE A DISCIPLINA ESTA ASSOCIADA A UM PROFESSOR\n\n\n");
    }
  }
  else{
      printf("\n\nDISCIPLINA INEXISTENTE!!\n\n\n");
  }
}
