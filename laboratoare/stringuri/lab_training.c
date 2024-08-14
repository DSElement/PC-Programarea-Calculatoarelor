/* Aplicația 9.1: Să se citească o linie de la tastatură. Linia conține cuvinte care sunt formate doar din litere, cuvintele fiind 
despărțite prin orice alte caractere ce nu sunt litere. Să se capitalizeze prima literă din fiecare cuvânt și să se afișeze șirul rezultat. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char s[100];
  int i = 0, check = 0;
  if (fgets(s,100,stdin) == NULL)
    {
      printf("eroare\n");
      return (-1);
    }
  else
    for (i = 0; s[i]; i++)
      {
	if ((check == 1) && (!isalpha(s[i])))
	  {
	    check = 0;
	  }
	else if ((check == 0) && (isalpha(s[i])))
	  {
	    check = 1;
	    s[i] = toupper(s[i]);
	  }
      }
  printf("%s\n",s);
  return 0;
  } */

/* Exemplul 9.2: Să se scrie un program care citește pe rând 2 nume. Cele două nume vor fi concatenate într-un alt șir de caractere 
cu „ și ” între ele și rezultatul va fi afișat. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char s1[30],s2[30],s[60];
  if (fgets(s1,30,stdin) == NULL)
    return (-1);
  if (fgets(s2,30,stdin) == NULL)
    return (-2);
  strcpy(s,s1);
  s[strcspn(s,"\n")] = '\0';
  strcat(s," si ");
  strcat(s,s2);
  s[strcspn(s,"\n")] = '\0';
  printf("%s\n",s);
  return 0;
}
