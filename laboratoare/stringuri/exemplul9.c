/* Exemplul 9.3: Să se scrie un program care citește linii de caractere până la întâlnirea liniei vide. Fiecare linie conține un cuvânt. Să se afișeze în ordine alfabetică
 cuvintele distincte introduse și de câte ori apare fiecare. */

#include <stdio.h>
#include <string.h>

typedef struct
{
  char word[20];
  int aparitii;
}cuvant;

cuvant tablou[100];
int numwords = 0;

cuvant *cautare(char *txt)
{
  int i = 0;
  for (i = 0; i<numwords; i++)
    {
      if (strcmp(txt,tablou[i].word) == 0)
	return &tablou[i];
    }
  return NULL;
}

void sortare()
{
  int check = 1, i = 0;
  do
    {
      check = 0;
      for (i = 1; i<numwords; i++)
	if (strcmp(tablou[i-1].word,tablou[i].word) < 0)
	  {
	    cuvant c = tablou[i-1];
	    tablou[i-1] = tablou[i];
	    tablou[i] = c;
	  }
    } while (check != 0);
}

int main()
{
  int i = 0;
  char n[20];
  for (;;)
    {
      if (fgets(n,20,stdin) == NULL)
	{
	  printf("Nu ti-o citit fgetsu\n");
	  return -1;
	}
      else
	{
	  if (strcmp(n,"\n\0") == 0)
	    break;
	  n[strcspn(n,"\n")] = '\0';
	  cuvant *c = cautare(n);
	  if (c)
	    {
	      c->aparitii++;
	    }
	  else
	    {
	      strcpy(tablou[numwords].word,n);
	      tablou[numwords].aparitii = 1;
	      numwords++;
	    }
	}
    }
  sortare();
  for (i = 0; i<numwords; i++)
    printf("Cuvantul %s are %d aparitii\n",tablou[i].word,tablou[i].aparitii);
  return 0;
}
