/* Scrieți un program, folosind getchar() si putchar() care, primind la stdin un fișier text va tipari la iesirea standard acelasi fisier text dar
   va schimba literele mari intalnite in fisier in litere mici iar cele mici in litere mari. */

#include <stdio.h>
#include <ctype.h>

int main()
{
  char c = 0;
  while ((c = getchar()) != EOF)
    {
      if isalpha(c)
	if isupper(c)
	  c = tolower(c);
	else
	  c = toupper(c);
      putchar(c);
    }
  return 0;
}
