/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char tab[10];
  int tab_int[10], n = 0;
  memset(tab,0,10);
  memset(tab_int,0,10*sizeof(int));
  scanf("%9s",tab);
  n = atoi(tab);
  n += 1;
  printf("%d\n",n);
  return 0;
  } */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  char tab_bin[] = "10010101";
  char tab_hex[] = "A455";
  char tab_dec[] = "1411";
  int n = 0;
  n = strtol(tab_bin,NULL,2);
  printf("%d\n",n);
  n = strtol(tab_hex,NULL,16);
  printf("%d\n",n);
  n = strtol(tab_dec,NULL,10);
  printf("%d\n",n);
  return 0;
}
