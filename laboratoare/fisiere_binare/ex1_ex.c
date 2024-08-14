// nr 2 bytes unsigned --> uint16_t
/*
program care citeste un fisier binar interpretat cum ca ar contine 
un numar necunoscut (foarte mare) de intregi fara semn pe 2 bytes
programul citeste fisierul si adauga datele intr-un tablou alocat dinamic
de structuri. fiecare structura contine numarul si de cate ori apare acesta
in fisier

se poate testa cu integers.bin (sau cu orice alt fisier)

 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define AUX 4096
#define CHUNK 10000

typedef struct
{
  uint16_t valoare;
  uint32_t aparitii;
}numar;

void eliberare(numar **tab, unsigned size)
{
  unsigned i = 0;
  for(i = 0; i<size; i++)
    {
      if (tab[i] != NULL)
	free(tab[i]);
    }
  free(tab);
}

int nr(uint16_t val, numar **tablou, unsigned size)
{
  unsigned h = 0;
  if (size == 0)
    return -1;
  for (h = 0; h<size; h++)
    {
      if (val == tablou[h]->valoare)
	{
	  //printf("SUAAAAAAAAAAAAA\n"); 
	  return h;
	}
    }
  return -1;
}

numar **adaugare(numar **tab, uint16_t val, FILE *file, unsigned *size, unsigned *size_total)
{
  numar *structura = NULL;
  numar **aux = NULL;
  if ((structura = (numar*)malloc(sizeof(numar))) == NULL)
    {
      perror(NULL);
      fclose(file);
      eliberare(tab, *size_total);
      exit(EXIT_FAILURE);
    }
  structura->valoare = val;
  structura->aparitii = 1;
  if ((*size+1)>*size_total)
    {
      *size_total += CHUNK;
      if ((aux = (numar**)realloc(tab,*size_total*sizeof(numar*))) == NULL)
	{
	  perror(NULL);
	  fclose(file);
	  eliberare(tab, *size_total);
	  exit(EXIT_FAILURE);
	}
      tab = aux;
    }
  tab[*size] = structura;
  (*(size))++;
  return tab;
}

numar **citire(char *path, unsigned *size)
{
  numar **temporar = NULL;
  numar **aux = NULL;
  FILE *in = NULL;
  unsigned size_total = 0;
  int num = 0;
  if ((in = fopen(path,"rb")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  uint16_t i = 0, j = 0;
  uint16_t tab[AUX];
  while ((i = fread(tab,sizeof(uint16_t),AUX,in)) > 0)
    {
      for (j = 0; j<i; j++)
	{
	  num = nr(tab[j], temporar, *size);
	  if (num == -1)
	    {
	      temporar = adaugare(temporar,tab[j],in, size, &size_total);
	    }
	  else
	    {
	      temporar[num]->aparitii++;
	    }
	}
    }
  if (fclose(in) != 0)
    {
      eliberare(temporar,size_total);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  if (*size<size_total)
    {
      if ((aux = (numar**)realloc(temporar,*size*sizeof(numar*))) == NULL)
	{
	  eliberare(temporar,size_total);
	  perror(NULL);
	  exit(EXIT_FAILURE);
	}
      temporar = aux;
      size_total = *size;
    }
  return temporar;
}

int main(int argc, char **argv)
{
  numar **tablou = NULL;
  unsigned size = 0;
  if (argc != 2)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  tablou = citire(argv[1], &size);
  unsigned i = 0;
  for (i = 0; i<size; i++)
    {
      printf("valoare: %hu   aparitii: %u\n",tablou[i]->valoare,tablou[i]->aparitii);
    }
  eliberare(tablou,size);
  return 0;
}
