#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
  if (a > b) return a;
  else return b;
}

int D(int i, int j, int *m, int *v, int *sol) {
  if (i < 1) return 0;
  if (j < 0) return 0;
  //printf ("%d\n", max(D(i - 1, j, m, v), D(i - 1, j - m[i], m, v) + v[i]));
  if (D(i - 1, j, m, v, sol) < D(i - 1, j - m[i], m, v, sol) + v[i]) sol[i] = m[i];
  
  return max(D(i - 1, j, m, v, sol), D(i - 1, j - m[i], m, v, sol) + v[i]); 
  
}

void rucsac_discret(int *m, int *v, int n, int R) {
  int sol[n];
  printf("Valoarea maxima este %d\n", D(n - 1, R, m, v, sol));  
  for (int i = 0; i < n; i++)
    printf ("%d ", sol[i]);
    
  printf("\n");
}

void subsir(int *v, int n) {
  int sol[n];
  int lung[n];
  for (int i = 0; i < n ; i++)
  {
    lung[i] = 0;
  }
  int aux = 0;
  for (int i = 0; i < n - 1; i++) 
    for (int j = i + 1; j < n; j++) { 
      aux = 0;
      if (i == 0) lung[i] = 1;
      if (v[i] < v[j]) {
        lung[j]++;
      } 
    }
  
  int max = 0;
  for (int i = 0; i < n; i++)
    if (max < lung[i])
      max = lung[i];
      
  printf("%d\n", max);
 
}

int main() {
  int n = 3;
  int m[] = {10, 30, 20};
  int v[] = {60, 120, 100};
  int R = 50;  
  rucsac_discret(m, v, n, R);
  
  int x = 8;
  int sir[] = {6, 1, 2, 9, 3, 8, 4, 7};
  subsir(sir, x);
  return 0;
}
