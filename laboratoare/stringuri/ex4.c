/* Se citește un text care este alcătuit doar din litere. Să se afișeze pentru fiecare literă de câte ori apare în text */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 100

void procentaj(char *s, char *tab)
{
  int i = 0;
  for (i = 0; s[i] != '\0' && i<CHUNK; i++)
    tab[tolower(s[i])-'a']++;
}

int main()
{
  char s[CHUNK];
  char tablou[26];
  int i = 0;
  for (i = 0; i < 26; i++)
    tablou[i] = 0;
  for (;;)
    {
      if (fgets(s,CHUNK,stdin) != NULL)
	{
	  procentaj(s,tablou);
	}
      else
	{
	    break;
	}
    }
  for (i = 0; i<26; i++)
	printf("%c - %d\n", 'a'+i, tablou[i]);
  return 0;
}
