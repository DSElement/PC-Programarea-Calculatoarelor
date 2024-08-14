/* Să se scrie un program care citește linii de caractere până la întâlnirea liniei vide. Fiecare linie conține un cuvânt. Să se afișeze în ordine alfabetică cuvintele 
distincte introduse și de câte ori apare fiecare. */

#include <stdio.h>
#include <string.h>


typedef struct
{
  char txt[20];
  int count;
} tip_cuvinte;


tip_cuvinte tablou_cuvinte[100];
int cuvinte_count = 0;


tip_cuvinte *cautare(char *string)
{
  int i = 0;
  for (i = 0; i<cuvinte_count; i++)
    {
      if (strcmp(string,tablou_cuvinte[i].txt) == 0)
	return &tablou_cuvinte[i];
    }
  return NULL;
}


void sortare()
{
  int i = 0, s = 0;
  char temporar[20];
  do
    {
      s = 0;
      for (i = 0; i<cuvinte_count-1; i++)
	{
	  if (strcmp(tablou_cuvinte[i].txt,tablou_cuvinte[i+1].txt) > 0)
	    {
	      strcpy(temporar,tablou_cuvinte[i].txt);
	      strcpy(tablou_cuvinte[i].txt,tablou_cuvinte[i+1].txt);
	      strcpy(tablou_cuvinte[i+1].txt,temporar);
	      s = 1;
	    }
	}
    } while (s);
}


int main()
{
  char linia[20];
  for (;;)
    {
      if (fgets(linia,20,stdin) == NULL)
	{
	  printf ("eroare la citire\n");
	  break;
	}
      else
	{
	  if (strcmp(linia,"\n") == 0)
	    break;
	}
      linia[strcspn(linia,"\n")] = '\0';
      tip_cuvinte *c = cautare(linia);
      if (c)
	{
	  c->count++;
	}
      if (c == NULL)
	{
	  strcpy(tablou_cuvinte[cuvinte_count].txt,linia);
	  tablou_cuvinte[cuvinte_count].count = 1;
	  cuvinte_count++;
	}
    }
  sortare();
  int i = 0;
  for (i = 0; i<cuvinte_count; i++)
    {
      printf("%s  %d\n",tablou_cuvinte[i].txt,tablou_cuvinte[i].count);
    }
  return 0;
}
