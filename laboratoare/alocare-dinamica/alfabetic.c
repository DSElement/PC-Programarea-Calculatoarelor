/* Aplicația 11.2: Se citesc linii de caractere, până la întâlnirea liniei vide. Să se sorteze aceste linii în ordine alfabetică și să se afișeze. Programul va utiliza doar 
strictul necesar de memorie. */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void eliberare(char **tablou,uint32_t size)
{
  uint32_t i = 0;
  for(i = 0; i<size; i++)
    {
      free(tablou[i]);
    }
  free(tablou);
}

char *get_line(char **tablou,uint32_t size_tab)
{
  char caracter;
  char *linia = NULL;
  char *temp = NULL;
  uint16_t size_line = 0;
  for(;;)
    {
      size_line++;
      if ((temp = (char*)realloc(linia,size_line*sizeof(char))) == NULL)
	{
	  free(linia);
	  eliberare(tablou,size_tab);
	  exit(EXIT_FAILURE);
	}
      linia = temp;
      if ((caracter = getchar()) == EOF)
	{
	  free(linia);
	  eliberare(tablou,size_tab);
	  exit(EXIT_FAILURE);
	}
      if (caracter == '\n')
	break;
      linia[size_line-1] = caracter;
    }  
  linia[size_line-1] = '\0';
  return linia;
}

void sortare(char **tablou, uint32_t len)
{
  char *p = NULL;
  uint8_t check = 0;
  uint32_t i = 0;
  do
    {
      for (i = 1; i<len; i++)
	{
	  check = 0;
	  if (strcmp(tablou[i-1],tablou[i]) > 0)
	    {
	      check = 1;
	      p = tablou[i-1];
	      tablou[i-1] = tablou[i];
	      tablou[i] = p;
	    }
	}
    } while (check);
  for (i = 0; i<len; i++)
    {
      printf("%s\n",tablou[i]);
    }
}

int main()
{
  char **tab = NULL;
  uint32_t size = 0;
  char *linie = NULL;
  char **auxiliar = NULL;

  for(;;)
    {
      linie = get_line(tab,size);
      if (strlen(linie) == 0)
	break;
      size++;
      if ((auxiliar = (char**)realloc(tab,size*sizeof(char*))) == NULL)
	{
	  eliberare(tab,size);
	  exit(EXIT_FAILURE);
	}
      tab = auxiliar;
      tab[size-1] = linie;
    }
  
  printf("Aranjarea in ordine alfabetica:\n\n");
  sortare(tab,size);
  eliberare(tab,size);
  return 0;
}
