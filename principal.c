#include <stdio.h>
#include <stdlib.h>

struct professor {
  int id;
  char nome[100];
  char formacao[50];
  float salario;
};

typedef struct professor Professor;

struct disciplina {
  int id;
  char nome[50];
  int cargaHoraria;
};

typedef struct disciplina Disciplina;

struct professorDisciplina {
  int id;
  int idProfessor;
  int idDisciplina;
};

typedef struct professorDisciplina ProfessorDisciplina;

char arquivoProfessores[50] = "professores.txt";
char arquivoDisciplinas[50] = "disciplinas.txt";
char arquivoProfessoresDisciplinas[50] = "professores_disciplinas.txt";

void iniciarArquivo(char *nomeArquivo) {
  FILE *fa = fopen(nomeArquivo, "a+");

  fgetc(fa);

  if (feof(fa)) {
    fprintf(fa, "%d\n", 0);
    fprintf(fa, "%d\n", 0);
  }

  fclose(fa);
}

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

        for (int i = 0 ; i < 100; i++) {
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

        for (int i = 0; i < 100; i++) {
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

void listarProfessores(Professor **professores){
  FILE *fr = fopen(arquivoProfessores, "r");

  int quantidadeProfessores, numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessores > 0){
    for(int i=0;i<quantidadeProfessores;i++){
      printf("\n------------------------------------------------------");
      printf("\nId: %d\n", (*professores)[i].id);
      printf("Nome: %s\n", (*professores)[i].nome);
      printf("Formacao: %s\n", (*professores)[i].formacao);
      printf("Salario: R$ %.2f\n", (*professores)[i].salario);
      printf("------------------------------------------------------\n\n");
    }
  }
  else {
    printf("\nNAO EXISTE NENHUM PROFESSOR CADASTRADO!\n\n");
  }

  printf("\n");

  fclose(fr);
}

void listarProfessoresDisciplinas(ProfessorDisciplina **professoresDisciplinas) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessoresDisciplinas > 0) {
    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      Professor professorAtual = retornaProfessorPorId((*professoresDisciplinas)[i].idProfessor);
      Disciplina disciplinaAtual = retornaDisciplinaPorId((*professoresDisciplinas)[i].idDisciplina);

      printf("\n------------------------------------------------------");
      printf("\nId: %d\n", (*professoresDisciplinas)[i].id);
      printf("Nome do professor: %d\n", professorAtual.nome);
      printf("Nome da disciplina: %d\n", disciplinaAtual.nome);
      printf("------------------------------------------------------\n\n");
    }
  }

  else {
    printf("\nNAO EXISTE NENHUM PROFESSOR ASSOCIADO A UMA DISCIPLINA!\n\n");
  }

  printf("\n");

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
      for(int i=0;i<quantidadeProfessores;i++){
        if ((*professores)[i].id == idProfessor){
          printf("\n\n------------------------------------------------------");
          printf("\nId: %d\n", (*professores)[i].id);
          printf("Nome: %s\n", (*professores)[i].nome);
          printf("Formacao: %s\n", (*professores)[i].formacao);
          printf("Salario: R$ %.2f\n", (*professores)[i].salario);
          printf("------------------------------------------------------\n\n");
        }
      }
    }
    else {
      printf("\n\nPROFESSOR NAO ENCONTRADO!\n\n");
    }
  }
  else {
    printf("\n\nNAO EXISTE NENHUM PROFESSOR CADASTRADO!\n\n");
  }

  printf("\n");

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
    printf("\n");

    int existe = 0;
    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if ((*professoresDisciplinas)[i].id == idProfessorDisciplina) {
        Professor professorAtual = retornaProfessorPorId((*professoresDisciplinas)[i].idProfessor);
        Disciplina disciplinaAtual = retornaDisciplinaPorId((*professoresDisciplinas)[i].idDisciplina);

        printf("\n------------------------------------------------------");
        printf("\nId: %d\n", (*professoresDisciplinas)[i].id);
        printf("Nome do professor: %d\n", professorAtual.nome);
        printf("Nome da disciplina: %d\n", disciplinaAtual.nome);
        printf("------------------------------------------------------\n\n");
      }
    }

    if (existe == 0) {
      printf("\nASSOCIACAO NAO ENCONTRADA!\n\n");
    }
  }

  else {
    printf("\n\nNAO EXISTE NENHUM PROFESSOR ASSOCIADO A UMA DISCIPLINA!\n\n");
  }

  printf("\n");

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
    int existe = 0;

    for (int i = 0; i < quantidadeProfessores; i++) {
      if ((*professores)[i].id == idProfessor) {
        existe = 1;
      }
    }

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
    int existe = 0;

    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if ((*professoresDisciplinas)[i].id == idProfessorDisciplina) {
        existe = 1;
      }
    }

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

void menu() {
  Professor *professores = (Professor*) malloc(sizeof(Professor));
  Disciplina *disciplinas = (Disciplina*) malloc(sizeof(Disciplina));
  ProfessorDisciplina *professoresDisciplinas = (ProfessorDisciplina*) malloc(sizeof(ProfessorDisciplina));

  carregarProfessores(&professores);
  carregarDisciplinas(&disciplinas);
  carregarProfessoresDisciplinas(&professoresDisciplinas);

  int categoria;

  do {
    printf("Menu do sistema:\n\n");

    printf("1 - Professores\n");
    printf("2 - Disciplinas\n");
    printf("3 - Professores com disciplinas\n");
    printf("4 - Sair\n\n");

    printf("Informe uma categoria: ");
    scanf("%d", &categoria);
    printf("\n");

    if (categoria == 1) {
      int opcao;

      do {
        printf("\nMenu dos professores:\n\n");

        printf("1 - Listar todos os professores\n");
        printf("2 - Listar professor por id\n");
        printf("3 - Inserir professor\n");
        printf("4 - Excluir professor\n");
        printf("5 - Voltar\n\n");

        printf("Informe uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

          if (opcao == 1) {
              listarProfessores(&professores);
          }

          else if (opcao == 2) {
              listarProfessorPorId(&professores);
          }

          else if (opcao == 3) {
              inserirProfessor(&professores);
          }

          else if (opcao == 4) {
              removerProfessorPorId(&professores);
          }
        } while(opcao != 5);

      printf("\n\n");
    }

    else if (categoria == 2) {
      int opcao;

      do {
        printf("\nMenu das disciplinas:\n\n");

        printf("1 - Listar todas as disciplinas\n");
        printf("2 - Listar disciplina por id\n");
        printf("3 - Inserir disciplina\n");
        printf("4 - Excluir disciplina\n");
        printf("5 - Voltar\n\n");

        printf("Informe uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
          // TODO - chamar fun��o para imprimir todas as disciplinas
        }

        else if (opcao == 2) {
          // TODO - chamar fun��o para imprimir uma disciplina por id
        }

        else if (opcao == 3) {
          // TODO - chamar fun��o para inserir uma disciplina
        }

        else if (opcao == 4) {
          // TODO - chamar fun��o para excluir disciplina por id
        }
      } while(opcao != 5);

      printf("\n\n");
    }

    else if (categoria == 3) {
      int opcao;

      do {
        printf("\nMenu das associacoes de professor com disciplina:\n\n");

        printf("1 - Listar todas associacoes de professores com disciplinas\n");
        printf("2 - Listar associacao de professor com disciplina por id\n");
        printf("3 - Associar um professor a uma disciplina\n");
        printf("4 - Excluir associacao de professor com disciplina\n");
        printf("5 - Voltar\n\n");

        printf("Informe uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
          listarProfessoresDisciplinas(&professoresDisciplinas);
        }

        else if (opcao == 2) {
          listarProfessorDisciplinaPorId(&professoresDisciplinas);
        }

        else if (opcao == 3) {
          inserirProfessorDisciplina(&professoresDisciplinas);
        }

        else if (opcao == 4) {
          removerProfessorDisciplinaPorId(&professoresDisciplinas);
        }
      } while(opcao != 5);

      printf("\n\n");
    }

  } while(categoria != 4);

  free(professores);
  free(disciplinas);
  free(professoresDisciplinas);

  printf("\nPROGRAMA ENCERRADO!\n");
}

int main() {
  iniciarArquivo(arquivoProfessores);
  iniciarArquivo(arquivoDisciplinas);
  iniciarArquivo(arquivoProfessoresDisciplinas);

  menu();

  return(0);
}
