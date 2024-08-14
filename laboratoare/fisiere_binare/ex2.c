/* Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program format din mai multe functii: o functie ce
 citeste un astfel de fisier si stocheaza numerele intr-un tablou. O functie care sorteaza acest tablou in ordine descrescatoare, o functie ce scrie un astfel de tablou intr-un alt 
fisier in format text, fiecare numar in zecimal pe un alt rand. Program testa functionalitatea prin citirea aceluiasi fisier ca si cel de la exercitiul anterior, va sorta datele 
obtinute si le va scrie in fisier conform cerintei. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 5000
#define AUX 4096


int *citire(FILE *in, uint32_t *size)
{
  int *tablou = NULL;
  int *aux = NULL;
  int temp[AUX];
  uint32_t size_total = 0;
  uint16_t i = 0, j = 0;

  while ((i = fread(temp,sizeof(int),AUX,in)) > 0)
    {
      *size += i;
      if (*size > size_total)
	{
	  size_total += CHUNK;
	  if ((aux = (int*)realloc(tablou,size_total*sizeof(int))) == NULL)
	    {
	      perror(NULL);
	      fclose(in);	     
	      free(tablou);
	      exit(EXIT_FAILURE);
	    }
	  tablou = aux;
	}
      for (j = i; j>0; j--)
	{
	  tablou[*size-j] = temp[i-j];
	}
    }
  
  if (*size<size_total)
    {
      if ((aux = (int*)realloc(tablou,*size*sizeof(int))) == NULL)
	    {
	      perror(NULL);
	      fclose(in);
	      free(tablou);
	      exit(EXIT_FAILURE);
	    }
      tablou = aux;
    }
  return tablou;
}

int *sortare(int *tablou, uint32_t size)
{
  uint32_t i = 0;
  uint8_t check = 0;
  int aux = 0;
  do
    {
      check = 0;
      for (i = 1; i<size; i++)
	{
	  if (tablou[i-1]<tablou[i])
	    {
	      aux = tablou[i-1];
	      tablou[i-1] = tablou[i];
	      tablou[i] = aux;
	      check = 1;
	    }
	}
    } while (check == 1);
  return tablou;
}

void printare(int *tablou, FILE *out, uint32_t size)
{
  uint32_t i = 0;
  for (i = 0; i<size; i++)
    fprintf(out,"%d\n",tablou[i]);
}
  
int main()
{
  int *tablou = 0;
  uint32_t size = 0;
  FILE *in = NULL, *out = NULL;
  if ((in = fopen("integers.bin","rb")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  if ((out = fopen("out_zecimal.txt","w")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  tablou = citire(in,&size);
  tablou = sortare(tablou, size);
  printare(tablou,out,size);
  free(tablou);
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
