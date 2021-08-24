#include <stdio.h>
#include <stdlib.h>
#include "professores.h"
#include "disciplinas.h"
#include "professores_disciplinas.h"

void iniciarArquivo(char *nomeArquivo) {
  FILE *fa = fopen(nomeArquivo, "a+");

  fgetc(fa);

  if (feof(fa)) {
    fprintf(fa, "%d\n", 0);
    fprintf(fa, "%d\n", 0);
  }

  fclose(fa);
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
          listarDisciplinas(&disciplinas);
        }

        else if (opcao == 2) {
          listarDisciplinaPorId(&disciplinas);
        }

        else if (opcao == 3) {
          inserirDisciplina(&disciplinas);
        }

        else if (opcao == 4) {
          removerDisciplinaPorId(&disciplinas);
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
