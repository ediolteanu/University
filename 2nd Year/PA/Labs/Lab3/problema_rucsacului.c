#include <stdio.h>
#include <stdlib.h>

void problema_rucsacului(float *m, float *v, int nr_elem, int R)
{
  float p[nr_elem];
  int sort[100];
  for (int i = 0; i < nr_elem; i++)
  {
    p[i] = v[i] / m[i];
    sort[i] = i;
  }
  float aux;
  for (int i = 0; i < nr_elem - 1; i++)
    for (int j = i + 1; j < nr_elem; j++)
      if (p[i] < p[j]) 
      {
        aux = sort[i];
        sort[i] = sort[j];
        sort[j] = aux;
        
      }
  
  int current = 0;
  float val_total = 0;
  int i = 0;
  while (current < R) {
    if (current + m[sort[i]] < R) {
      printf("Alegem m%d\n", sort[i] + 1);
      current = current + m[sort[i]];
      val_total = val_total + v[sort[i]];
    }
    else {
      float percent = (R - current) / m[sort[i]];
      current = current + percent * m[sort[i]];
      printf("Alegem %f * m%d\n", percent, sort[i] + 1);
      val_total = val_total + percent * v[sort[i]];
    }
    i++;
  }
  printf("Valoare totala = %f\n", val_total);
}

int main()
{
  int nr_elem = 3;
  float m[] = {10, 30, 20};
  float v[] = {60, 120, 100};
  int R = 50;
  
  problema_rucsacului(m, v, nr_elem, R);
  return 0;
}
