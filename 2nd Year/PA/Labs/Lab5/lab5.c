#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void k_garduri(int n, int k) {
	int *D = (int *) calloc(n + 1, sizeof(int));
  int nr_oriz;
	for (int i = 0; i <= k; i++) 
	{	
		D[i] = i;	
	}
	
	for (int i = k + 1; i <= n; i++) 
	{
		D[i] = D[i - 1] + D[i - k];	 
	}
	
	for (int i = 1; i <= n; i++)
	{	
		printf("D[%d] = %d\n", i, D[i]);
		for (int j = i; j >= 0; j -= k) 
		{
			nr_oriz = (i - j) / k;	// nr_oriz = Numarul de grupuri de k scanduri asezate pe orizontala
			if (nr_oriz >= 1) 
			{
			  if (j == 0)
			  {
			    printf("%d grupuri de %d scanduri grupate orizontale\n", nr_oriz, k);
			  }
			  else
			  {
				  printf("permutari de %d scanduri verticale si %d grupuri de "
				        "%d scanduri grupate orizontale\n", j, nr_oriz, k);
				}
			}
			else 
			{
				printf("%d scanduri verticale\n", j);
			}
		}
	}
}


void print_sume_3(int *v, int n, int index, int sum, int rest, int *sol, 
                  int index_sol)
{
  if (index == -1)
  {
    return;
  }
  
  print_sume_3(v, n, index - 1, sum, rest, sol, index_sol);
  
  if (((sum + v[index]) % 3) == rest)
  {
    sol[index_sol++] = v[index];
 
    printf("%d + %d = %d { ", sum, v[index], sum + v[index]);
    
    for (int j = 0; j < index_sol; j++)
    {
      printf("%d ", sol[j]);
    }
    printf("}\n");
  }

  if (((sum + v[index]) % 3) != rest)
  {
    sol[index_sol++] = v[index];
    print_sume_3(v, n, index - 1, sum + v[index], rest, sol, index_sol);
  }
  else 
  {
    print_sume_3(v, n, index - 1, sum + v[index], rest, sol, index_sol);
  }
}

void sume_3(int *v, int n)
{
  int D[n + 1][3];
  
  // cazurile de baza
  D[0][0] = 0;
  D[0][1] = 0;
  D[0][2] = 0;

  for (int i = 1; i <= n; i++)
  {
    if (v[i - 1] % 3 == 0) 
    {
      D[i][0] = 1 + 2 * D[i - 1][0]; 
      D[i][1] = 2 * D[i - 1][1];     
      D[i][2] = 2 * D[i - 1][2];     
    }
    else if (v[i - 1] % 3 == 1) 
    {
      D[i][0] = D[i - 1][0] + D[i - 1][1]; 
      D[i][1] = 1 + D[i - 1][0] + D[i - 1][1];   
      D[i][2] = D[i - 1][2] + D[i - 1][1];
    }
    else
    {
      D[i][0] = D[i - 1][0] + D[i - 1][1]; 
      D[i][1] = D[i - 1][2] + D[i - 1][1]; 
      D[i][2] = 1 + D[i - 1][2] + D[i - 1][0]; 
    }
    
    printf("i = %d;  v[i] = %d\nCele 3 recurente sunt:\n", i - 1, v[i - 1]);
    int sol[n];       // vectorul de solutii
    int len = 0;      // lungimea vectorului de solutii

    printf("\nD[%d][0] = %d\n", i, D[i][0]);
    print_sume_3(v, n, i - 1, 0, 0, sol, len);
    
    len = 0;
    printf("\nD[%d][1] = %d\n", i, D[i][1]);
    print_sume_3(v, n, i - 1, 0, 1, sol, len);
    
    len = 0;
    printf("\nD[%d][2] = %d\n", i, D[i][2]);
    print_sume_3(v, n, i - 1, 0, 2, sol, len);
    printf("\n");
  }
  
  printf("\nNumarul de sume care dau restul 0 la impartirea cu 3 este %d.\n",
         D[n][0]);
}

int main()
{
  printf("k-garduri\n");
  int n = 5, k = 2;
  k_garduri(n, k); 

  printf("\n\n3-sume\n");
  int v[] = {3, 4, 2, 1}; 
  int len = 4;            
  sume_3(v, len);           
  return 0;
}
