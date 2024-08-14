/* Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program format din mai multe functii: o functie ce
 citeste un astfel de fisier si stocheaza numerele intr-un tablou. O functie care sorteaza acest tablou in ordine descrescatoare, o functie ce scrie un astfel de tablou intr-un alt 
fisier in format text, fiecare numar in zecimal pe un alt rand. Program testa functionalitatea prin citirea aceluiasi fisier ca si cel de la exercitiul anterior, va sorta datele 
obtinute si le va scrie in fisier conform cerintei. */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 4096
#define CHUNK 10000

int32_t *citire(FILE *in, unsigned *size_tab)
{
  int32_t tablou[SIZE];
  unsigned size_total = 0;
  uint16_t i = 0, j = 0;
  int32_t *final = NULL, *temp = NULL;
  while ((i = fread(tablou,sizeof(int32_t),SIZE,in)) > 0)
    {
      *size_tab += i;
      if (*size_tab > size_total)
	{
	  size_total += CHUNK;
	  if ((temp = (int32_t*)realloc(final,size_total*sizeof(int32_t))) == NULL)
	    {
	      perror(NULL);
	      fclose(in);
	      free(final);
	      exit(EXIT_FAILURE);
	    }
	  final = temp;
	}
      for (j = (*size_tab-i); j<*size_tab; j++)
	{
	  final[j] = tablou[j-(*size_tab-i)];
	}
    }
  if (*size_tab < size_total)
    {
      if ((temp = (int32_t*)realloc(final,*size_tab*sizeof(int32_t))) == NULL)
	{
	  perror(NULL);
	  fclose(in);
	  free(final);
	  exit(EXIT_FAILURE);
	}
      final = temp;
    }
  return final;
}

void sortare(int32_t *tablou, unsigned size_tab)
{
  unsigned i = 0;
  int32_t aux = 0;
  uint8_t check = 0;
  do
    {
      check = 0;
      for (i = 0; i<size_tab-1; i++)
	{
	  if (tablou[i] < tablou[i+1])
	    {
	      check = 1;
	      aux = tablou[i];
	      tablou[i] = tablou[i+1];
	      tablou[i+1] = aux;
	    }
	}
    } while (check == 1);
}

int main()
{
  FILE *in = NULL, *out = NULL;
  int32_t *tab = NULL;
  unsigned size_tab = 0;
  if ((in = fopen("integers.bin","rb")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  tab = citire(in, &size_tab);
  if (fclose(in) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  sortare(tab, size_tab);
  if ((out = fopen("rezultat.txt","w")) == NULL)
    {
      free(tab);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  unsigned i = 0;
  for (i = 0; i<size_tab; i++)
    {
      fprintf(out,"%d\n",tab[i]);
    }
  if (fclose(out) != 0)
    {
      free(tab);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  free(tab);
  return 0;
}
