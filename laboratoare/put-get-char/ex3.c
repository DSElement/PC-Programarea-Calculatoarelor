/* Scrieți un program, folosind getchar() pentru citire, care, primind la stdin redirectat un fișier text va tipari la iesirea standard histograma literelor,
 adica distributia in procente a literelor din fisier. Se considera in calcul doar litere mari si litere mici. Programul va printa pe cate un rand litera si 
procentajul de aparitie. */

#include <stdio.h>
#include <ctype.h>

int main()
{
  char c = 0, tab[26];
  int i = 0, count = 0;
  for (i = 0; i<26; i++)
    tab[i] = 0;
  
  while ((c = getchar()) != EOF)
    {
      if (isalpha(c))
	{
	  if(isupper(c))
	    c = tolower(c);
	  i = c - 'a';
	  tab[i]++;
	  count++;
	}
    }

  for (i = 0; i<26; i++)
    printf("%c: %f\n", 'a' + i,((float)tab[i]/(float)count)*100);
  return 0;
}
