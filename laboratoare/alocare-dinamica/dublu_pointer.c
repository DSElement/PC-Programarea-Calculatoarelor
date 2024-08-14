/* Exemplu: Se citesc linii de caractere, de maxim 200 de caractere fiecare, până la întâlnirea liniei vide. Ulterior se cere un șir, terminat și el cu \n. 
   Să se afișeze toate liniile care conțin șirul dat. Programul va utiliza doar strictul necesar de memorie. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **linii = NULL;
int nrLinii = 0;

void eliberare()
{
  int i = 0;
  for (i = 0; i<nrLinii; i++)
    free(linii[i]);
  free(linii);
}

char *linie()
{
  char stringg[201];
  size_t n = 0;
  char *p1 = NULL;
  if (fgets(stringg,201,stdin) == NULL)
    {
      printf("eroare");
      exit(-1);
    }
  stringg[strcspn(stringg,"\n")] = '\0';
  n = strlen(stringg)+1;
  if ((p1 = (char*)malloc(n*sizeof(char))) == NULL)
    {
      printf("Eroaree");
      exit(-1);
    }
  strcpy(p1,stringg);
  return p1;
}

int main()
{
  char **linii1 = NULL;
  char *p = NULL;
  int i = 0;
  for (;;)
    {
      p = linie();
      if (strlen(p) == 0)
	{
	  free(p);
	  break;
	}
      nrLinii++;
      if ((linii1 = (char**)realloc(p,nrLinii*sizeof(char))) == NULL)
	{
	  eliberare();
	  printf("Eroaree");
	  exit(-2);
	}
      linii = linii1;
      linii[nrLinii-1] = p;
    }
  return 0;
}
