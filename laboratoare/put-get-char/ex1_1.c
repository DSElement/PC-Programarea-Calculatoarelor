/* Exemplul 10.1: Să se citească un caracter de la tastatură și să se afișeze dacă este cifră, literă mică, literă mare sau altceva.
 În caz că e litera mică să se afișeze litera mare corespunzătoare și invers. */

#include <stdio.h>
#include <ctype.h>


int main()
{
  char c;
  if ((c = getchar()) != EOF)
    {
      if (isdigit(c))
	printf("%c este o cifra\n",c);
      else if (islower(c))
	printf("%c e acum o litera mare\n", toupper(c));
      else if (isupper(c))
	printf("%c este acum o litera mica", tolower(c));
      else
	printf("Nu e nici cifra, nici litera\n");
    }
  return 0;
}
