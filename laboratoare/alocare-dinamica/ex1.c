/* Să se scrie o funcție care primește două șiruri de caractere și le concatenează cu un spațiu între ele, folosind un bloc de memorie alocat dinamic pentru rezultat. Funcția va 
returna acest bloc de memorie. Să se verifice funcția cu două șiruri de caractere introduse de la tastatură, fiecare de maxim 100 de caractere. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 101

char *citire_sir(uint8_t *len)
{
  uint8_t length = CHUNK;
  char *sir = NULL;
  char *temp = NULL;
  if ((sir = (char*)malloc(length*sizeof(char))) == NULL)
    {
      printf("Eroare la alocare\n");
      exit(EXIT_FAILURE);
    }
  if ((fgets(sir,CHUNK,stdin)) == NULL)
    {
      printf("Eroare la fgets\n");
      free(sir);
      exit(EXIT_FAILURE);
    }
  sir[strcspn(sir,"\n")] = '\0';
  length = strlen(sir);
  if (length != CHUNK)
    if ((temp = realloc(sir,(length+1)*sizeof(char))) == NULL)
      {
	printf("Eroare la realloc\n");
	free(sir);
	exit(EXIT_FAILURE);
      }
  sir = temp;
  *len = length;
  return sir;
}

int main()
{
  char *sir = NULL;
  char *sir1 = NULL;
  uint8_t len1 = 0;
  char *sir2 = NULL;
  uint8_t len2 = 0;
  sir1 = citire_sir(&len1);
  sir2 = citire_sir(&len2);
  if ((sir = (char*)malloc((len1+len2+2)*sizeof(char))) == NULL)
    {
      printf("Eroare la alocare pentru sir\n");
      free(sir1);
      free(sir2);
      exit(EXIT_FAILURE);
    }
  strcpy(sir,sir1);
  strcat(sir," ");
  strcat(sir,sir2);
  printf("Sirul final este:\n%s\n",sir);
  free(sir);
  free(sir1);
  free(sir2);
  return 0;
}
