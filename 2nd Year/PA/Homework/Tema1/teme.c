#include <stdio.h>
#include <stdlib.h>

struct tema {
  int index;
  int timp;
  int punctaj;
  int deadline;
};

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int main() {
  FILE *fin = fopen("teme.in", "r");
  int nr_teme;
  int timp, punctaj, deadline;
  fscanf(fin, "%d", &nr_teme);
  int index = 1;
  struct tema *Teme = (struct tema *) malloc(nr_teme * sizeof(struct tema));
  for (int i = 0; i < nr_teme; i++) {
    fscanf(fin, "%d %d %d", &timp, &punctaj, &deadline);
    Teme[i].timp = timp;
    Teme[i].punctaj = punctaj;
    Teme[i].deadline = deadline;
    Teme[i].index = index++;
  }

  fclose(fin);
  struct tema aux;
  for (int i = 0; i < nr_teme - 1; i++)
    for (int j = i + 1; j < nr_teme; j++) {
      if (Teme[i].deadline > Teme[j].deadline) {
        aux = Teme[j];
        Teme[j] = Teme[i];
        Teme[i] = aux;
      }
    }

  struct tema *rez = (struct tema *) calloc(nr_teme, sizeof(struct tema));
  int k = 0;
  int sapt = 0;
  int puncte = 0;
  struct tema current;
  int sapt_current = 0;
  int puncte_current = 0;
  int timp_current = 0;
  int capac = Teme[nr_teme - 1].deadline;
  int **D = (int **) calloc(nr_teme, (sizeof(int *)));
  for (int i = 0 ; i <= nr_teme; i++) {
    D[i] = (int *) calloc(capac, sizeof(int));
  }
  for (int i = 0; i < nr_teme; i++) {
    D[i][0] = 0;
  }

  for (int i = 1; i <= capac; i++) {
    D[0][i] = 0;
  }

  for (int i = 1; i <= nr_teme; i++) {
    for (int j = 1; j <= capac; j++) {
      if (j < Teme[i - 1].timp) {
          D[i][j] = D[i - 1][j];
      } else {
        if (j <= Teme[i - 1].deadline) {
          D[i][j] = max(D[i - 1][j],
                    D[i - 1][j - Teme[i - 1].timp] + Teme[i - 1].punctaj);
        } else {
          D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
      }
    }
  }

  int *sol = (int *) malloc(nr_teme * sizeof(int));;
  for (int i = 0; i <= nr_teme ; i++) {
    sol[i] = 0;
  }
  int i = nr_teme, j = capac;
  while (D[i][j] > 0) {
    if (D[i][j] == D[i-1][j]) {
      i = i - 1;
    } else {
      sol[i] = 1;
      k++;
      j = j - Teme[i-1].timp;
      i = i - 1;
    }
  }

  FILE *fout = fopen("teme.out", "w");
  fprintf(fout, "%d %d\n", D[nr_teme][capac], k);
  for (int j = 1; j <= nr_teme; j++) {
    if (sol[j] == 1) {
      fprintf(fout, "%d ", Teme[j-1].index);
    }
  }

  fclose(fout);
  return 0;
}
