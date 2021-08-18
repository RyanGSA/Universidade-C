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

void carregarProfessores(Professor *professores) {
  FILE *fr = fopen(arquivoProfessores, "r+");

  int quantidadeProfessores;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessores);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessores > 0) {
    professores = (Professor*) realloc(professores, sizeof(Professor) * quantidadeProfessores);

    for (int i = 0; i < quantidadeProfessores; i++) {
      if (feof(fr)) {
        break;
      }

      fscanf(fr, "%d", &(professores[i].id));
      fscanf(fr, "%s", &(professores[i].nome));
      fscanf(fr, "%s", &(professores[i].formacao));
      fscanf(fr, "%f", &(professores[i].salario));
    }
  }

  fclose(fr);
}

void carregarDisciplinas(Disciplina *disciplinas) {
  FILE *fr = fopen(arquivoDisciplinas, "r+");

  int quantidadeDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeDisciplinas > 0) {
    disciplinas = (Disciplina*) realloc(disciplinas, sizeof(Disciplina) * quantidadeDisciplinas);

    for (int i = 0; i < quantidadeDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      fscanf(fr, "%d", &(disciplinas[i].id));
      fscanf(fr, "%s", &(disciplinas[i].nome));
      fscanf(fr, "%d", &(disciplinas[i].cargaHoraria));
    }
  }

  fclose(fr);
}

void carregarProfessoresDisciplinas(ProfessorDisciplina *professoresDisciplinas) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r+");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessoresDisciplinas > 0) {
    professoresDisciplinas = (ProfessorDisciplina*) realloc(professoresDisciplinas, sizeof(ProfessorDisciplina) * quantidadeProfessoresDisciplinas);

    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      if (feof(fr)) {
        break;
      }

      fscanf(fr, "%d", &(professoresDisciplinas[i].id));
      fscanf(fr, "%d", &(professoresDisciplinas[i].idProfessor));
      fscanf(fr, "%d", &(professoresDisciplinas[i].idDisciplina));
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

    return existe;
  }

  fclose(fr);
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

    return existe;
  }

  fclose(fr);
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

    return existe;
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
      fscanf(fr, " %[^\n]", nome);
      fscanf(fr, " %[^\n]", formacao);
      fscanf(fr, "%f", &salario);

      if (idAtual == idProfessor) {
        existe = 1;
        break;
      }
    }

    return existe;
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
      fscanf(fr, " %[^\n]", &nome);
      fscanf(fr, "%d", &cargaHoraria);

      if (idDisciplina == idAtual) {
        existe = 1;
        break;
      }
    }

    return existe;
  }

  fclose(fr);
}

void listarProfessoresDisciplinas(ProfessorDisciplina *professoresDisciplinas) {
  FILE *fr = fopen(arquivoProfessoresDisciplinas, "r+");

  int quantidadeProfessoresDisciplinas;
  int numeroUltimoId;

  fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
  fscanf(fr, "%d", &numeroUltimoId);

  if (quantidadeProfessoresDisciplinas > 0) {
    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      printf("\nid: %d\n", professoresDisciplinas[i].id);
      printf("id do professor: %d\n", professoresDisciplinas[i].idProfessor);
      printf("id da disciplina: %d\n", professoresDisciplinas[i].idDisciplina);
    }
  }

  else {
    printf("\nNAO EXISTE NENHUM PROFESSOR ASSOCIADO A UMA DISCIPLINA!\n");
  }

  printf("\n\n");

  fclose(fr);
}

void listarProfessorDisciplinaPorId(ProfessorDisciplina *professoresDisciplinas) {
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
      if (professoresDisciplinas[i].id == idProfessorDisciplina) {
        existe = 1;
        printf("\nid: %d\n", professoresDisciplinas[i].id);
        printf("id do professor: %d\n", professoresDisciplinas[i].idProfessor);
        printf("id da disciplina: %d\n", professoresDisciplinas[i].idDisciplina);
      }
    }

    if (existe == 0) {
      printf("\nASSOCIACAO NAO ENCONTRADA!\n");
    }
  }

  else {
    printf("\n\nNAO EXISTE NENHUM PROFESSOR ASSOCIADO A UMA DISCIPLINA!\n");
  }

  printf("\n\n");

  fclose(fr);
}


void inserirProfessorDisciplina(ProfessorDisciplina *professoresDisciplinas) {
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
    FILE *fr = fopen(arquivoProfessoresDisciplinas, "a+");

    int quantidadeProfessoresDisciplinas;
    int numeroUltimoId;

    fscanf(fr, "%d", &quantidadeProfessoresDisciplinas);
    fscanf(fr, "%d", &numeroUltimoId);

    fclose(fr);

    quantidadeProfessoresDisciplinas++;

    professoresDisciplinas = (ProfessorDisciplina*) realloc(professoresDisciplinas, sizeof(ProfessorDisciplina) * quantidadeProfessoresDisciplinas);
    professoresDisciplinas[quantidadeProfessoresDisciplinas - 1].id = numeroUltimoId + 1;
    professoresDisciplinas[quantidadeProfessoresDisciplinas - 1].idProfessor = idProfessor;
    professoresDisciplinas[quantidadeProfessoresDisciplinas - 1].idDisciplina = idDisciplina;

    FILE *fw = fopen(arquivoProfessoresDisciplinas, "w");

    fprintf(fw, "%d\n", quantidadeProfessoresDisciplinas);
    fprintf(fw, "%d\n", professoresDisciplinas[quantidadeProfessoresDisciplinas - 1].id);

    for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
      fprintf(fw, "%d\n", professoresDisciplinas[i].id);
      fprintf(fw, "%d\n", professoresDisciplinas[i].idProfessor);
      fprintf(fw, "%d\n", professoresDisciplinas[i].idDisciplina);
    }

    fclose(fw);

    carregarProfessoresDisciplinas(professoresDisciplinas);

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

void removerProfessorDisciplinaPorId(ProfessorDisciplina *professoresDisciplinas) {
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
      if (professoresDisciplinas[i].id == idProfessorDisciplina) {
        existe = 1;
      }
    }

    if (existe == 1) {
      FILE *fw = fopen(arquivoProfessoresDisciplinas, "w");

      fprintf(fw, "%d\n", (quantidadeProfessoresDisciplinas - 1));
      fprintf(fw, "%d\n", professoresDisciplinas[quantidadeProfessoresDisciplinas - 1].id);

      for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
        if (professoresDisciplinas[i].id != idProfessorDisciplina) {
          fprintf(fw, "%d\n", professoresDisciplinas[i].id);
          fprintf(fw, "%d\n", professoresDisciplinas[i].idProfessor);
          fprintf(fw, "%d\n", professoresDisciplinas[i].idDisciplina);
        }
      }

      printf("\n");

      fclose(fw);

      carregarProfessoresDisciplinas(professoresDisciplinas);

      printf("\nASSOCIACAO REMOVIDA COM SUCESSO!");
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

void removerProfessorDisciplinaPorId(ProfessorDisciplina *professoresDisciplinas) {
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
      if (professoresDisciplinas[i].id == idProfessorDisciplina) {
        existe = 1;
      }
    }

    if (existe == 1) {
      FILE *fw = fopen(arquivoProfessoresDisciplinas, "w");

      fprintf(fw, "%d\n", (quantidadeProfessoresDisciplinas - 1));
      fprintf(fw, "%d\n", professoresDisciplinas[quantidadeProfessoresDisciplinas - 1].id);

      for (int i = 0; i < quantidadeProfessoresDisciplinas; i++) {
        if (professoresDisciplinas[i].id != idProfessorDisciplina) {
          fprintf(fw, "%d\n", professoresDisciplinas[i].id);
          fprintf(fw, "%d\n", professoresDisciplinas[i].idProfessor);
          fprintf(fw, "%d\n", professoresDisciplinas[i].idDisciplina);
        }
      }

      printf("\n");

      fclose(fw);

      carregarProfessoresDisciplinas(professoresDisciplinas);

      printf("\nASSOCIACAO REMOVIDA COM SUCESSO!");
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

  carregarProfessores(professores);
  carregarDisciplinas(disciplinas);
  carregarProfessoresDisciplinas(professoresDisciplinas);

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
          // TODO - chamar função para imprimir todos os professores
        }

        else if (opcao == 2) {
          // TODO - chamar função para imprimir o professor por id
        }

        else if (opcao == 3) {
          // TODO - chamar função para inserir professor
        }

        else if (opcao == 4) {
          // TODO - chamar função para excluir professor por id
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
          // TODO - chamar função para imprimir todas as disciplinas
        }

        else if (opcao == 2) {
          // TODO - chamar função para imprimir uma disciplina por id
        }

        else if (opcao == 3) {
          // TODO - chamar função para inserir uma disciplina
        }

        else if (opcao == 4) {
          // TODO - chamar função para excluir disciplina por id
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
          listarProfessoresDisciplinas(professoresDisciplinas);
        }

        else if (opcao == 2) {
          listarProfessorDisciplinaPorId(professoresDisciplinas);
        }

        else if (opcao == 3) {
          inserirProfessorDisciplina(professoresDisciplinas);
        }

        else if (opcao == 4) {
          removerProfessorDisciplinaPorId(professoresDisciplinas);
        }
      } while(opcao != 5);

      printf("\n\n");
    }

  } while(categoria != 4);

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
