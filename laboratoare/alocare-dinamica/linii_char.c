/* Exemplu: Se citesc linii de caractere, de maxim 200 de caractere fiecare, până la întâlnirea liniei vide. Ulterior se cere un șir, terminat și el cu \n. Să se afișeze 
toate liniile care conțin șirul dat. Programul va utiliza doar strictul necesar de memorie. 

luarea liniei se va face si ea cu alocare dinamica*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void eliberare(char **tab, uint32_t size)
{
  uint32_t i = 0;
  for (i = 0; i<size; i++)
    free(tab[i]);
}

char *citire_linie(char **tab, uint32_t *size)
{
  char *ch = NULL;
  char ch_temp1;
  char *ch_temp = NULL;
  int n = 0;
  for (;;)
    {
      n++;
      if ((ch_temp = (char *)realloc(ch,n)) == NULL)
	{
	  eliberare(tab,*size);
	  free(ch);
	  exit(EXIT_FAILURE);
	}
      ch = ch_temp;
      if ((ch_temp1 = getchar()) == EOF)
	{
	  eliberare(tab,*size);
	  free(ch);
	  exit(EXIT_FAILURE);
	}
      if (ch_temp1 == '\n')
	break;
      ch[n-1] = ch_temp1;
    }
  ch[n-1] = '\0';
  return ch;
}

int main()
{
  char **tablou = NULL;;
  char **temp = NULL;
  uint32_t size = 0;
  char *linie = NULL;
  for(;;)
    {
      linie = citire_linie(tablou,&size);
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
  linie = citire_linie(tablou,&size);
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
