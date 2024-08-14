/* Sa se scrie o functie cu urmatorul antent

uint32_t string_replace(char *where, const char *what, const char *replace)

Functia inlocuieste fiecare aparitie a string-ului what in string-ul where cu string-ul replace. Se considera ca zona de memorie a lui where este suficient de mare ca sa poata 
contine noul string. Functia returneaza numarul de inlocuiri

char s1[1000];
char s2[] = "string";
char s3[] = "sir de caractere";
strcpy(s1, "Acesta este un string si un string este terminat cu 0x00");

int r = string_replace(s1, s2, s3);

s1 devine "Acesta este un sir de caractere si un sir de caractere este terminat cu 0x00";
s2, s3 - raman neschimbate
r = 2 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint32_t string_replace(char *where, const char *what, const char *replace)
{
  size_t count = 0, lungimea1 = strlen(what), lungimea2 = strlen(replace), lungimea0 = strlen(where);
  char *i = NULL, *holder = where;
  if (lungimea2>lungimea1)
    {
      while ((where = strstr(where,what)) != NULL)
	{
	  count++;
	  for (i = holder+lungimea0+lungimea2; i>=where+lungimea2; i--)
	    {
	      *i = *(i-lungimea2);
	    }
	  printf("%s\n",where);
	  strncpy(where,replace,lungimea2);
	  printf("%s\n",where);
	  where += lungimea2;
	  printf("%s\n",where);
	  lungimea0 += lungimea2;
	}
    }
  return count;
}

int main()
{
  char s1[1000];
  char s2[] = "string";
  char s3[] = "sir de caractere";
  strcpy(s1, "Acesta este un string si un string este terminat cu 0x00");
  int r = string_replace(s1, s2, s3);
  printf("%s\n",s1);
  printf("%d\n",r);
  return 0;
}
