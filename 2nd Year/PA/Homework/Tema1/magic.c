#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

struct magic {
  int value;
  int stg;
  int drp;
};

int get_magic(int suma_stg, int suma_drp, int stg, int drp) {
  int suma, suma_patrat, diferenta, diferenta_patrat;
  suma = suma_stg - suma_drp;
  suma_patrat = suma * suma;
  diferenta = stg - drp;
  diferenta_patrat = diferenta * diferenta;
  return suma_patrat + diferenta_patrat;
}

struct magic *lowest_magic(struct magic *stg, struct magic *drp) {
  if (stg->value <= drp->value)
    return stg;
  else
    return drp;
}

struct magic *dei(int *sume, int N,  int i, int j) {
  if (j - i <= 15) {
    struct magic *min_magic = (struct magic *) malloc(sizeof(struct magic));
    min_magic->value = INF;
    int suma_stg = 0;
    int suma_drp = 0;
    int magic;
    if (i > 0) {
      suma_stg = sume[i - 1];
      suma_drp = sume[i];
      magic = get_magic(suma_stg, suma_drp, i - 1, i);
      if (magic <= min_magic->value) {
        min_magic->value = magic;
        min_magic->stg = i - 1;
        min_magic->drp = i;
      }
    }

    for (int stg = i; stg < j; stg++) {
      suma_stg = sume[stg];
      for (int drp = stg + 1; drp <= j; drp++) {
        suma_drp = sume[drp];
        magic = get_magic(suma_stg, suma_drp, stg, drp);

        if (magic < min_magic->value) {
          min_magic->value = magic;
          min_magic->stg = stg;
          min_magic->drp = drp;
        }
      }
    }

    if (j < N - 1) {
      suma_stg = sume[j];
      suma_drp = sume[j + 1];
      magic = get_magic(suma_stg, suma_drp, j, j + 1);
      if (magic < min_magic->value) {
        min_magic->value = magic;
        min_magic->stg = j;
        min_magic->drp = j + 1;
      }
    }
    return min_magic;
  } else {
    int m = (i + j) / 2;
    return lowest_magic(dei(sume, N, i, m) , dei(sume, N, m + 1, j));
  }
}

int main() {
  int N;

  FILE *fin = fopen("magic.in", "r");
  fscanf(fin, "%d", &N);
  int bilete[N];
  for (int i = 0; i < N; i++) {
    fscanf(fin, "%d", &bilete[i]);
  }
  fclose(fin);

  int stg_magic = 0;
  int drp_magic = 0;
  int sume[N];
  sume[0] = 0;
  for (int i = 1; i < N; i++) {
    sume[i] = sume[i - 1] + bilete[i - 1];
  }

  struct magic *min_magic = (struct magic *) malloc(sizeof(struct magic));
  min_magic = dei(sume, N, 0, N - 1);

  FILE *fout = fopen("magic.out", "w");
  fprintf(fout, "%d\n%d %d\n", min_magic->value,
          min_magic->stg + 1, min_magic->drp + 1);

  fclose(fout);
  return 0;
}
