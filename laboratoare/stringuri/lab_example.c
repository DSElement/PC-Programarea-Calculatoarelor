#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
  const char *some_text="some text";
  char t[128];
  char *text = NULL;
  int n = 3;
  float f = 3.14;
  unsigned int x = 780;
  sprintf(t, "%d", x);
  sprintf(t, "%X", x);
  sprintf(t, "%08X", x);
  sprintf(t, "%f", f);
  if ((text = malloc(1024 * sizeof(char))) == NULL)
    {
      printf ("no more memory\n");
      return -1;
    }
  sprintf(text, "String-ul meu custom: un sir %s, un numar in hex %04X si un float %f\n", some_text, n, f);
  printf("%s\n",text);
  return 0;
}
