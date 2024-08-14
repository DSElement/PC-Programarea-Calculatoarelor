/* Scrieți un program, folosind getchar() și putchar() prin care se numără cuvintele de la stdint. Se consideră un cuvânt ca fiind o secvență de litere mici
 și/sau mari care despărțite prin unul sau mai multe spații, tab-uri, linii noi și EOF. Testarea se va face atât clasic prin scriere la stdin cât și prin 
redirectare cu un fișier text realizat inainte ca și caz de test catre intrarea standard a programului */

#include <stdio.h>
#include <ctype.h>


int main()
{
  char c = 0;
  int wc = 0, check = 0;
  while ((c = getchar()) != EOF)
    {
      if (isalpha(c))
	{
	  if (check == 0)
	    {
	      check = 1;
	      wc += 1;
	    }
	}
      else
	{
	  if (check == 1)
	    check = 0;
	}
    }
  printf("%d\n", wc);
  return 0;
}
