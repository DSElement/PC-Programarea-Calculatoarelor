/* Scrieti un program care tipareste la iesire textul citit de la intrarea standard, modificat astfel incat orice litera de la inceputul unui 
cuvant e transcrisa ca litera mare. La sfarsit, programul va tipari numarul total de cuvinte si numarul maxim de cuvinte pe aceeasi linie.
 Cuvintele sunt secvenţe de caractere despărţite prin unul sau mai multe "spatii albe". */

#include <stdio.h>
#include <ctype.h>

int main()
{
  char c = 0;
  int aux = 0, cuvinte = 0, max = 0, max_temp = 0;
  while ((c = getchar()) != EOF)
    {
      if (c == '\n')
	{
	  putchar(c);
	  if (max_temp > max)
	    max = max_temp;
	  max_temp = 0;
	  aux = 0;
	}
      else if ((aux == 1) && (isblank(c)))
	{
	  aux = 0;
	  putchar(c);
	}
      else if ((aux == 0) && (isalpha(c)))
	{
	  putchar(toupper(c));
	  aux = 1;
	  cuvinte++;
	  max_temp++;
	}
      else
	putchar(c);
    }
  printf("\n");
  printf("%7d %4d\n",cuvinte, max);
  return 0;
}
