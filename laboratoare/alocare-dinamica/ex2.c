/* Se citesc numere până la întâlnirea numărului 0. Să se afișeze aceste numere în ordine inversă. Programul va folosi doar minimul necesar de memorie*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 100

int *citire(uint32_t *len)
{
  int *p = NULL;
  int *temp = NULL;
  int c = 0;
  if ((p = (int*)malloc(CHUNK*sizeof(int))) == NULL)
    {
      printf("Eroare la alocare\n");
      exit(EXIT_FAILURE);
    }
  while(1)
    {
      if ((scanf("%d",&c)) == EOF)
	{
	  printf("Eroare la scanf\n");
	  free(p);
	  exit(EXIT_FAILURE);
	}
      if (c == 0)
	{
	  p[*len] = c;
	  (*len)++;
	  break;
	}
      p[*len] = c;
      (*len)++;
      if ((*len) == CHUNK)
	{
	  *len += CHUNK;
	  if ((temp = (int*)realloc(p,*len*sizeof(int))) == NULL)
	    {
	      printf("Eroare la realloc\n");
	      free(p);
	      exit(EXIT_FAILURE);
	    }
	  p = temp;
	}
    }
  if ((*len % CHUNK) != 0)
    {
      if ((temp = (int*)realloc(p,*len*sizeof(int))) == NULL)
	{
	  printf("Eroare la realloc\n");
	  free(p);
	  exit(EXIT_FAILURE);
	}
      p = temp;
      }
  return p;
}

int main()
{
  int *array = NULL;
  uint32_t length = 0;
  int32_t i = 0;
  array = citire(&length);
  printf("%d\n",length);
  for (i = length-1; i>=0; i--)
    printf("%d ",array[i]);
  free(array);
  return 0;
}
