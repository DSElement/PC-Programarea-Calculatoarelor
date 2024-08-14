/* Exemplu: Se citesc de la tastatură numere până la introducerea valorii 0. Să se afișeze dacă toate numerele sunt pare, sau nu. Programul va utiliza doar strictul necesar de memorie. */

#include <stdio.h>
#include <stdlib.h>



int main()
{
  int k = 0, i = 0, n = 0, pare = 1;
  int *v = NULL, *v1 = NULL;
  for (;;)
    {
      scanf("%d",&k);
      if (k == 0)
	break;
      n++;
      if ((v1 = (int*)realloc(v,sizeof(int)*n)) == NULL)
	{
	  printf("Eroare in realocarea dinamica");
	  free (v);
	  exit(-1);
	}
      v = v1;
      v[n-1] = k;
    }
  for (i = 0; i<n; i++)
    if ((v[i] % 2) != 0)
      {
	pare = 0;
	break;
      }
  if (pare)
    printf("Toate numerele sunt pare\n");
  else
    printf("Nu toate numerele sunt pare\n");
  free(v);
  return 0;
}
