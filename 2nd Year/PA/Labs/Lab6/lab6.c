#include <stdlib.h>
#include <stdio.h>

//verifica daca elementul x se afla in vectorul sol
int verif_sol(int x, int *sol, int index) {
  int i = 0;
  while (i < index) {
    if (sol[i] == x) return 1;
    i++;
  }
  return 0;
}

//printeaza solutia
void print_sol(int *sol, int n) {
  int i = 0;
  while (i < n) {
    printf("%d ", sol[i]);
    i++;
  }
  printf("\n");
}

void generare_permutari(int *M, int n, int *sol, int index) {
  if (n == index) 
  {
    print_sol(sol, n);
    return;
  }
  
  for (int i = 0; i < n; i++)
  {
    if (verif_sol(M[i], sol, index)) continue;
    
    // un nou vector de solutii in care se copiaza vectorul vechi de solutii
    // si se adauga elementul curent
    int new_sol[n]; 
    int k = 0;
    for (int j = 0; j < index; j++)
      new_sol[j] = sol[j];
      
    new_sol[index] = M[i];

    generare_permutari(M, n, new_sol, index + 1);
  }
}

// afiseaza toate elementele confirmate de seq, daca nu este afisat niciunul
// se afiseaza {} - multimea vida
void print_submultime(int *M, int n, int *seq) {
  int j = 0;
  int ok = 1;
  for (int i = 0; i < n; i++) {
    if (seq[j] == 1) {
      printf("%d ", M[j]);
      ok = 0;
    }
    j++;
  }
  if (ok) printf("{}");
  printf("\n");
}

void generare_submultimi(int *M, int n, int index, int *seq) {
  if (index >= n)
    print_submultime(M, n, seq);
  else {
    seq[index] = 0;
    generare_submultimi(M, n, index + 1, seq);
    seq[index] = 1;
    generare_submultimi(M, n, index + 1, seq);
  }
}

void print_regine(int *sol, int N) {
  for(int k = 0; k < N; k++) { // afisare
    printf("%d ", sol[k]);
  }
  printf("\n");
}

int check_regina(int *sol, int k) {
  for(int i = 0; i < k; i++) {
    if(sol[i] == sol[k] || k - i == abs(sol[i]-sol[k])) {
      return 0;
      }
  }
  return 1;
}

void problema_reginelor(int N) {
	int max = N - 1; // numarul maxim de linii
	int *sol = (int *) malloc(N * sizeof(int)); // vectorul solutii
	int ok; // 0 -> invalid; 1 -> ok
	
  for(int j = 0; j < N; j++) {
	  sol[j] = -1; // initializare vector solutii
  }
  
  int i = 0; // incepe de la prima coloana
  while(i >= 0) {
    ok = 0; 
    while((!ok) && (sol[i] <= max)) {
      sol[i] = sol[i] + 1; // urmatoarea linie
      ok = check_regina(sol, i); // verifica daca pozitia reginei este buna
    }
    if(sol[i] <= max) {
      if(i == N - 1) { // afisare solutie
        print_regine(sol, N);
      }
      else { // nu este solutie finala, pas inainte
        i++;
      }
    }
    else { // mai mare decat max
      sol[i] = -1; // reinitializare
      i--; // pas inapoi
    }
  }
}

// afiseaza submultimea doar daca numarul ei de elemente este k
void print_combinare(int *M, int n, int *seq, int k) {
  int j = 0;
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (seq[i] == 1) l++;
  }
  if (k == l) {
    for (int i = 0; i < n; i++) {
      if (seq[j] == 1) {
        printf("%d ", M[j]);
      }
      j++;
    }
    printf("\n");
  }
}

// acelasi principiu ca si la generare submultimi doar ca se afieaza
// doar atunci cand sunt k elemente in submultime
void generare_combinari(int *M, int n, int index, int *seq, int k) {
  if (index >= n)
    print_combinare(M, n, seq, k);
  else {
    seq[index] = 0;
    generare_combinari(M, n, index + 1, seq, k);
    seq[index] = 1;
    generare_combinari(M, n, index + 1, seq, k);
  }
}

int main() {
  int M[3] = {1, 2, 3};
  int n = 3;
  int sol[3];
  printf("1. Generare permutari\n");
  generare_permutari(M, n, sol, 0);
  printf("\n");
  printf("2. Generare submultimi\n");
  generare_submultimi(M, n, 0, sol);
  printf("\n");
  printf("3. Problema reginelor\n");
  problema_reginelor(4);
  printf("\n");
  printf("Bonus 1\n");
  int k = 2;
  generare_combinari(M, n, 0, sol, k);
  
  
  
  return 0;
}

