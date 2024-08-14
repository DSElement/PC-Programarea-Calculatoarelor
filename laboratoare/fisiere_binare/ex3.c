/* Sa se scrie si testeze o functie ce primeste ca argument o cale de fisier sursa si o cale de fisier destinatie. Programul va copia continutul fisierului sursa in fisierul
 destinatie. Se vor folosi functii specializate de lucru cu fisiere binare. */

#include <stdio.h>
#include <stdlib.h>

#define AUX 4096


void functie(FILE *in, FILE *out)
{
  int tab[AUX];
  unsigned i = 0;
  while ((i = fread(tab,sizeof(int),AUX,in)) > 0)
    {
      fwrite(tab,sizeof(int),AUX,out);
    }
}

int main()
{
  FILE *in = NULL, *out = NULL;
  if ((in = fopen("integers.bin","rb")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
      }
  if ((out = fopen("copie_integers.bin","wb")) == NULL)
    {
      perror(NULL);
      fclose(in);
      exit(EXIT_FAILURE);
    }
  functie(in,out);
  if (fclose(in) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  if (fclose(out) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  return 0;
}
