#include <stdio.h>
#include <stdlib.h>

#define neg_inf -100000
void hanoi(int n, char a, char b, char c) {
  if (n > 0) {
    hanoi(n - 1, a, c, b);
    printf("%c->%c\n", a, b);
    hanoi(n - 1, c, b, a);
  }
}
int max(int a, int b) {
  if (a >= b) return a;
  return b;  
}

int max_vect(int *v, int i, int j) {
  if (i == j) return v[i];
  else {
    int m = (i + j) / 2;
    return max(max_vect(v, i, m), max_vect(v, m + 1, j));
  }
}

void interclasare(int *v, int i, int m, int j) {
  int a = i, b = m + 1;
  int *u = (int *) calloc((j - i + 1), sizeof(int));
  int c = 0;
  while (a <= m && b <= j) {
    if (v[a] <= v[b]) {
      u[c++] = v[a++];
    }
    else u[c++] = v[b++];
  }
  
  while (a <= m)
    u[c++] = v[a++];
  
  while (b <= j)
    u[c++] = v[b++];
    
  for (int l = i, k = 0; l <= j; l++)
    v[l] = u[k++];
  
  free(u);
}

void sort_interclasare(int *v, int i, int j) {
  if (i < j) {
    int m = (i + j) / 2;
    sort_interclasare(v, i, m);
    sort_interclasare(v, m + 1, j);
    interclasare(v, i, m, j);
  }
}

int binary_search(int *v, int i , int j, int x) {
  if (i > j) return -1;
  else {
    int m = (i + j) / 2;
    if (v[m] == x)
      return m;
    else
      if (v[m] > x)
        return binary_search(v, i, m - 1, x);
      else
        return binary_search(v, m + 1, j, x);
  }
}

int aparitii_nesortat(int *v2, int i , int j, int x) {
  if (i == j) {
    if (v2[i] == x)
      return 1;
    else return 0;
  }
  else {
    int m = (i + j) / 2;
    return aparitii_nesortat(v2, i, m, x) + aparitii_nesortat(v2, m + 1, j, x);
  }
}
int main() {
  hanoi(2, 'a', 'b', 'c');
  printf("\n");
  hanoi(3, 'a', 'b', 'c');
  
  int v[] = {-1, 6, -123, 9500, 1245, 43};
  printf("\n%d\n", max_vect(v, 0, 5));
  sort_interclasare(v, 0, 5);
  for (int i = 0; i <= 5; i++)
    printf("%d ", v[i]);
  
  printf("\n%d\n", binary_search(v, 0, 5, 43));
  
  int v2[] = {-1, 4, 4, 4, 3, 4 , 21, 4};
  printf("%d\n", aparitii_nesortat(v2, 0, 7, 4));
  return 0;
}



