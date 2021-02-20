#include <stdio.h>
#include <stdlib.h>

#define INF 100000
void problema_spectacolelor(int n, int *start, int *final)
{
  int sort[100];
  for (int i = 0; i < n; i++)
  {
    sort[i] = i;
  }
  
  int aux;
  for (int i = 0; i < n - 1; i++)
    for (int j = i; j < n; j++)
      if (final[i] > final[j])
      {
        aux = sort[i];
        sort[i] = sort[j];
        sort[j] = aux;
      }
  
  int nr = 0;
  int final_current = -INF;
  for (int i = 0; i < n; i++)
  {
      if (start[sort[i]] >= final_current)
      {
          nr++;
          final_current = final[sort[i]];
          printf("Se afiseaza filmul de la %d la %d\n",
            start[sort[i]], final[sort[i]]); 
      }
  }
  printf("Numarul de filme este: %d\n", nr);
}

int main()
{
  int start[] = {10, 11, 12, 14, 16, 17};
  int final[] = {11, 13, 13, 18, 17, 19};
  int n = 6;
  
  problema_spectacolelor(n, start, final);
  return 0;
}
