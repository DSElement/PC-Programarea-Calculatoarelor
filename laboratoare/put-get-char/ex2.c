/* Scrieți un program, folosind getchar() și putchar(), care, primind la stdin redirectat un fișier ce conține un cod C, va printa la stdout 
același fișier dar fără comentarii. Practic, programul va elimina comentariile din fișierul C primit prin redirectare de stdin și va printa
 rezultatul la stdout */

#include <stdio.h>


int main()
{
  char c = 0, aux = 0;
  while ((c = getchar()) != EOF)
    {
      if ((c == '/') && (aux == 0))
	  aux = '/';
      else if ((c == '/') && (aux == '/'))
	{
	  while ((c = getchar()) != '\n')
	    ;
	  aux = 0;
	}
      else if ((c == '*') && (aux == '/'))
	{
	  while (1)
	    {
	      aux = c;
	      c = getchar();
	      if ((aux == '*') && (c == '/'))
		break;
	    }
	  aux = 0;
	}
      else if ((aux == '/') && (c != '/'))
	{
	  putchar(aux);
	  aux = 0;
	  putchar(c);
	}
      else if ((c != '/') && (aux == 0))
	putchar(c);
    }
  return 0;
}
