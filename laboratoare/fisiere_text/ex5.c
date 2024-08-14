/* 
    Se consideră un fișier text ce conține in general text, de o dimensiune necunoscută, programul considerând-o infinită. Să se scrie un program care citește acest fișier și scrie în
 fișierul histo.txt histragama literelor din fișier. Prin histrograma literelor (mari și mici) se înțelege distribuția în procente a acestora, procentul de apariție din total. În 
fișierul histo.txt se vor scrie linii sub forma : litera - numar apariții. Exemplu:

a - 16 %
b - 2 %
c - 17.8 %

Fișierul de test se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/scrisoare.txt */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#define SIZE 201

size_t citire(unsigned *tablou, FILE *in)
{
  char string[SIZE];
  uint16_t i = 0;
  size_t marime = 0;
  for(;;)
    {
      if ((fgets(string,SIZE,in)) == NULL)
	{
	  if (feof(in))
	    break;
	  else
	    {
	      perror(NULL);
	      fclose(in);
	      exit(EXIT_FAILURE);
	    }
	}
      string[strcspn(string,"\n")] = '\0';
      if (strlen(string) == 0)
	continue;
      for (i = 0; i<strlen(string); i++)
	{
	  if (isalpha(string[i]))
	    {
	      tablou[tolower(string[i])-'a']++;
	      marime++;
	    }
	}
    }
  return marime;
}

int main()
{
  FILE *in = NULL, *out = NULL;
  double temp = 0;
  unsigned tablou[26] = {0};
  size_t marime = 0, i = 0;
  if ((in = fopen("scrisoare.txt","r")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);      
    }
  marime = citire(tablou,in);
  printf("%ld\n",marime);
  if (fclose(in) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  if ((out = fopen("out1.txt","w")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  for (i = 0; i<26; i++)
    {
      temp = (double)tablou[i]*100/marime;
      fprintf(out,"%c - %f%%\n",(int)i+'a',temp);
    }
  if (fclose(out) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  return 0;
}
