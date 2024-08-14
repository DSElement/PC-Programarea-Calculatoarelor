/* Scrieti un program care numără caracterele, cuvintele şi liniile citite de la intrarea standard, pana la sfarsitul acesteia. Cuvintele sunt 
secvenţe de caractere despărţite prin unul sau mai multe "spatii albe". Precizări O linie se numără doar când e încheiată cu '\n'. Programul va 
tipări la ieşire numărul de linii, cuvinte, şi caractere, aliniate la dreapta pe un câmp de lăţime 7 (se poate face cu formatul %7d), şi separate 
prin câte un spaţiu. Pentru comparaţie, folosiţi programul UNIX wc (word count). */

#include <stdio.h>
#include <ctype.h>

int main()
{
  char c = 0;
  int caractere = 0, cuvinte = 0, linii = 0, aux = 0;
  while ((c = getchar()) != EOF)
    {
      caractere++;
      if ((aux == 1) && (isspace(c)))
	aux = 0;
      else if (isalpha(c) && (aux == 0))
	{
	  aux = 1;
	  cuvinte++;
	}
      if (c == '\n')
	linii++;
    }
  printf("%7d %7d %7d\n",linii,cuvinte,caractere);
  return 0;
}
