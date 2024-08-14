#include <stdio.h>
#include <string.h>

int main()
{
  char tab[30], text[] = "ana are mere", text2[] = " si pere si gaste";
  int n = 0;
  char *p = NULL;
  int compare = 0;
  if ((fgets(tab, 30, stdin)) != NULL)
    printf("%s\n",tab);
  else
    printf("error\n");
  n = strlen(tab);
  printf("%d - este numarul de caractere din string\n",n);
  strcpy(tab,text);
  printf("%s - este noul tab\n",tab);
  strcat(tab,text2);
  printf("%s - este tabloul concatenat\n",tab);
  //ana are mere si pere si gaste
  p = strchr(tab,'g');
  if (p == NULL)
    printf("Nu s-a gasit\n");
  else
    printf("S-a gasit - %s\n",p);
  p = NULL;
  p = strstr(tab,"pere");
  if (p == NULL)
    printf("There's nothing we can do\n");
  else
    printf("There is something right - %s\n",p);
  strcpy(tab,"ana are mere si pere si gasTe");
  compare = strcmp(tab,"ana are mere si pere si gASte");
  printf("Compare: %d\n",compare);
  return 0;
}
