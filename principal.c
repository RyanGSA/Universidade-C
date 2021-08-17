#include <stdio.h>
#include <stdlib.h>

struct professorDisciplina {
  int id;
  int idProfessor;
  int idDisciplina;
};

typedef struct professorDisciplina ProfessorDisciplina;

char arquivoProfessoresDisciplinas[50] = "professores_disciplinas.txt";
char arquivoProfessores[50] = "professores.txt";
char arquivoDisciplinas[50] = "disciplinas.txt";

void iniciarArquivo(char *nomeArquivo) {
  FILE *fw = fopen(nomeArquivo, "a");

  fgetc(fw);

  if (feof(fw)) {
    fprintf(fw, "%d\n", 0);
    fprintf(fw, "%d\n", 0);
  }

  fclose(fw);
}

void carregarProfessoresDisciplinas(ProfessorDisciplina *professoresDisciplinas) {


}

void listarProfessoresDisciplinas(ProfessorDisciplina *professoresDisciplinas) {


}

void listarProfessorDisciplinaPorId(ProfessorDisciplina *professoresDisciplinas) {


}

int verificarProfessorDisciplinaExistePorProfessorEDisciplina(int idProfessor, int idDisciplina) {


}

int verificarProfessorDisciplinaExistePorProfessor(int idProfessor) {


}

int verificarProfessorDisciplinaExistePorDisciplina(int idDisciplina) {


}

void inserirProfessorDisciplina(ProfessorDisciplina *professoresDisciplinas) {


}

void removerProfessorDisciplinaPorId(ProfessorDisciplina *professoresDisciplinas) {


}

void menu() {
  ProfessorDisciplina *professoresDisciplinas = (ProfessorDisciplina*) malloc(sizeof(ProfessorDisciplina));
  carregarProfessoresDisciplinas(professoresDisciplinas);

  // TODO - Carregar os professores e as disciplinas

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
        printf("1 - Listar associacao de professor com disciplina por id\n");
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
