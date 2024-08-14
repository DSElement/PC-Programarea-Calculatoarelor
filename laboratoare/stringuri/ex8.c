/*     Sa se scrie o functie cu urmatorul antet:

uint32_t upper_sub_string(char *str, const char *substr);

Pentru fiecare aparitie a string-ului substr in string-ul str se va modifica ca acest string din str sa fie transpus in litere mari (upper-case) Functia va returna numarul de aparitii. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
  char string_initial[100];
  char string_final[100];
  char sub_string[30];
  char sub_string_real[30];
  int diferenta = 0;
  if (fgets(string_initial,100,stdin) == NULL)
    return (-1);
  if (fgets(sub_string,30,stdin) == NULL)
    return (-1);
  string_initial[strcspn(string_initial,"\n")] = '\0';
  sub_string[strcspn(sub_string,"\n")] = '\0';
  strcpy(sub_string_real,sub_string);
  int length = strlen(sub_string);
  int i = 0;
  char *c = string_initial;
  char *p = NULL;
  for (i = 0; i<length; i++)
    sub_string[i] = toupper(sub_string[i]);
  for(;;)
    {
      p = c;
      c = strstr(c,sub_string_real);
      if ((c == NULL) || (*c == '\0'))
	{
	  strcat(string_final,p);
	  break;	  
	}
      diferenta = (c - p);
      strncat(string_final,p,diferenta);
      strcat(string_final,sub_string);
      c += length;
    }
  printf("%s\n",string_final);
  return 0;
}
