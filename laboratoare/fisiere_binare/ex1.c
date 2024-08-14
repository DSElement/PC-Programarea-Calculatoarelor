/* 
    Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program ce citeste un astfel de fisier si scrie
numerele citite intr-un alt fisier in format text hexazecimal cu 8 cifre hexa cate unul pe rand. Pentru testare se poate folosi fisierul descarcat prin urmatoarea comanda:

wget http://staff.cs.upt.ro/~valy/pt/integers.bin */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define AUX 4096


void functie(FILE *in, FILE *out)
{
  uint16_t i = 0, j = 0;
  int tablou[AUX];
  while ((i = fread(tablou,sizeof(int),AUX,in)) > 0)
    {
      for (j = 0; j<i; j++)
	{
	  fprintf(out,"%08X\n",*(tablou+j));
	}
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
  if ((out = fopen("out.txt","wb")) == NULL)
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
