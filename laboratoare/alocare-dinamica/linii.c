/* Exemplu: Se citesc linii de caractere, de maxim 200 de caractere fiecare, până la întâlnirea liniei vide. Ulterior se cere un șir, terminat și el cu \n. Să se afișeze 
toate liniile care conțin șirul dat. Programul va utiliza doar strictul necesar de memorie. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

char *citire_linie()
{
  char *p = NULL;
  char linie_temporara[201];
  if (fgets(linie_temporara,201,stdin) == NULL)
    {
      printf("Eroare la citire\n");
      exit(EXIT_FAILURE);
    }
  linie_temporara[strcspn(linie_temporara,"\n")] = '\0';
  p = (char*)malloc(1+strlen(linie_temporara)*sizeof(char));
  if (p == NULL)
    {
      printf("eroare in alocare dinamica");
      exit(EXIT_FAILURE);
    }
  strcpy(p,linie_temporara);
  return p;
}

void eliberare(char **tab, uint32_t size)
{
  uint32_t i = 0;
  for (i = 0; i<size; i++)
    free(tab[i]);
}

int main()
{
  char **tablou = NULL;;
  char **temp = NULL;
  uint32_t size = 0;
  char *linie = NULL;
  for(;;)
    {
      linie = citire_linie();
      if (strlen(linie) == 0)
	{
	  free (linie);
	  break;
	}
      size++;
      temp = (realloc(tablou,size*sizeof(char*)));
      if (temp == NULL)
	{
	  printf("realloc failed\n");
	  eliberare(tablou,size);
	  exit(EXIT_FAILURE);
	}
      tablou = temp;
      tablou[size-1] = linie;
    }
  printf("Ce string cautam?\n");
  linie = citire_linie();
  uint32_t i = 0;
  for (i = 0; i<size; i++)
    {
      if (strstr(tablou[i],linie))
	{
	  printf("%s\n",tablou[i]);
	}
    }
  free(linie);
  eliberare(tablou,size);
  free(tablou);
  return 0;
}
