/* Scrieti un program care numara cuvintele si liniile citite de la intrarea standard, pana la sfarsitul acesteia. Un cuvant e o secventa de
   litere, cifre, caractere '.' sau '_' . */

#include <stdio.h>
#include <ctype.h>

int main()
{
  char c = 0;
  int aux = 0, linii = 0, cuvinte = 0;
  while ((c = getchar()) != EOF)
    {
      if (c == '\n')
	linii++;
      if ((aux == 1) && isblank(c))
	aux = 0;
      if (((isalnum(c)) || (c == '.') || (c == '_')) && (aux == 0))
	{
	  aux = 1;
	  cuvinte++;
	}
    }
  printf("%7d %7d\n",linii,cuvinte);
  return 0;
}
