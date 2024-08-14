/* 1. Un program primeste in linia de comanda o serie de optiuni si de fisiere. Optiunile incep cu '-' si pot fi:
    -o - original - nu se modifica literele in niciun fel
    -l - lowercase - afiseaza toate literele in lowercase
    -u - uppercase - afiseaza toate literele in uppercase
Optiunile se pot da de mai multe ori, inclusiv intercalate intre nume de fisiere. Este activa ultima optiune introdusa. Celelalte caractere decat literele raman neschimbate.
Initial se considera ca fiind activa optiunea '-o'.
Exemplu:
afis -o 1.txt -l 2.txt
Afiseaza fisierul 1.txt cu literele originale, iar 2.txt in lowercase. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define SIZE 801


void printare(char *file_path, char *string)
{
  FILE *file = NULL;
  uint16_t i = 0;
  char temp[SIZE];
  if ((file = fopen(file_path,"r")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  if (strcmp(string,"-o") == 0)
    {
      for(;;)
	{
	  if ((fgets(temp,SIZE,file)) == NULL)
	    {
	      if (feof(file))
		return;
	      else
		{
		  fclose(file);
		  perror(NULL);
		  exit(EXIT_FAILURE);
		}
	    }
	  temp[strcspn(temp,"\n")] = '\0';
	  if (strlen(temp) == 0)
	    continue;
	  printf("%s\n",temp);
	}
    }
  if (strcmp(string,"-l") == 0)
    {
      for(;;)
	{
	  if ((fgets(temp,SIZE,file)) == NULL)
	    {
	      if (feof(file))
		return;
	      else
		{
		  fclose(file);
		  perror(NULL);
		  exit(EXIT_FAILURE);
		}
	    }
	  temp[strcspn(temp,"\n")] = '\0';
	  if (strlen(temp) == 0)
	    continue;
	  for (i = 0; i<strlen(temp); i++)
	    {
	      temp[i] = tolower(temp[i]);
	    }
	  printf("%s\n",temp);
	}
    }
  if (strcmp(string,"-u") == 0)
    {
      for(;;)
	{
	  if ((fgets(temp,SIZE,file)) == NULL)
	    {
	      if (feof(file))
		return;
	      else
		{
		  fclose(file);
		  perror(NULL);
		  exit(EXIT_FAILURE);
		}	      
	    }
	  temp[strcspn(temp,"\n")] = '\0';
	  if (strlen(temp) == 0)
	    continue;
	  for (i = 0; i<strlen(temp); i++)
	    {
	      temp[i] = toupper(temp[i]);
	    }
	  printf("%s\n",temp);
	}
    }
  if (fclose(file) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
  if (argc < 2)
    exit(EXIT_SUCCESS);
  uint8_t i = 0;
  for(i = 1; i<argc; i++)
    {
      if ((strcmp(argv[i],"-o") != 0)&&(strcmp(argv[i],"-l") != 0)&&(strcmp(argv[i],"-u") != 0))
	if ((strcmp(argv[i-1],"-o") == 0)||(strcmp(argv[i-1],"-l") == 0)||(strcmp(argv[i-1],"-u") == 0))
	  {
	    printare(argv[i],argv[i-1]);
	  }
    }
  return 0;
}
