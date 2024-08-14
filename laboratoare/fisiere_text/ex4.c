/* 
    Se consideră un fișier text ce conține un număr necunoscut de
linii de text de o dimensiune necunoscută. Să se scrie un program ce
citește un astfel de fișier și stochează datele într-un tablou alocat
dinamic de string-uri C alocate dinamic. Se va folosi o amprentă
minimă de memorie. Se vor scrie de asemenea și următoarele funcții

    o funcție void write_sort(char **lines, char *filepath); - funcția va prelua tabloul de linii, le va sorta alfabetic și le va scrie în fișierul cu calea filepath. Se va realiza 
conex și o funcție de sortare a tabloului de linii lines. Se poate folosi bubble-sort. Pentru compararea aflabetică a două linii se poate folosi funcția strcmp(...)
    o funcție void write_random(char **lines, char *filepath); - funcția va prelua tabloul de linii și le va scrie în fișierul referit prin calea filepath în ordine aleatoare a 
liniilor. Hint ! Se poate folosi funcția rand(....);
    o funcție uint32_t find_word(char **lines, char *word); - funcția va căuta cuvântul referit prin word în tabloul de linii lines și va returna numărul de apariții.

Fișierul de test se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/scrisoare.txt */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 100
#define SIZE 200


void eliberare(char **tablou, size_t nr)
{
  size_t i = 0;
  for (i = 0; i<nr; i++)
    {
      if (tablou[i] != NULL)
	free(tablou[i]);
    }
  free(tablou);
}

char **citire(char **tablou, size_t *nr, FILE *in)
{
  size_t counter = 0;
  char **aux = NULL;
  char *string = NULL;
  char temp[SIZE];
  for(;;)
    {
      if ((fgets(temp,SIZE,in)) == NULL)
	{
	  if (feof(in))
	    break;
	  else
	    {
	      eliberare(tablou,*nr);
	      fclose(in);
	      perror(NULL);
	      exit(EXIT_FAILURE);
	    }
	}
      temp[strcspn(temp,"\n")] = '\0';
      if (strlen(temp) == 0)
	continue;
      if ((string = (char*)malloc((strlen(temp)+1)*sizeof(char))) == NULL)
	{
	  perror(NULL);
	  eliberare(tablou,*nr);
	  fclose(in);
	  exit(EXIT_FAILURE);
	}
      strcpy(string,temp);
      if (counter == *nr)
	{
	  if ((aux = (char**)realloc(tablou,(*nr+CHUNK)*sizeof(char*))) == NULL)
	    {
	      perror(NULL);
	      eliberare(tablou,*nr);
	      fclose(in);
	      exit(EXIT_FAILURE);
	    }
	  tablou = aux;
	  tablou[counter] = string;
	  counter++;
	  *nr += CHUNK;
	}
      else
	{
	  tablou[counter] = string;
	  counter++;
	}
    }
  if (counter < *nr)
    {
      if ((aux = (char**)realloc(tablou,counter*sizeof(char*))) == NULL)
	    {
	      perror(NULL);
	      eliberare(tablou,*nr);
	      fclose(in);
	      exit(EXIT_FAILURE);
	    }
	  tablou = aux;
	  *nr = counter;
    }
  return tablou;
}

void liness(char **lines, size_t nr)
{
  size_t i = 0;
  uint8_t check = 0;
  char *aux = NULL;
  do
    {
      check = 0;
      for (i = 1; i<nr; i++)
	{
	  if (strcmp(lines[i-1],lines[i]) > 0)
	    {
	      aux = lines[i-1];
	      lines[i-1] = lines[i];
	      lines[i] = aux;
	      check = 1;
	    }
	}
    } while (check == 1);
}

void write_sort(char **lines, char *filepath, size_t nr)
{
  FILE *out1 = NULL;
  if ((out1 = fopen(filepath,"w")) == NULL)
    {
      perror(NULL);
      eliberare(lines,nr);
      exit(EXIT_FAILURE);
    }
  liness(lines,nr);
  size_t i = 0;
  for (i = 0; i<nr; i++)
    fprintf(out1,"%s\n",lines[i]);
  if (fclose(out1) != 0)
    {
      perror(NULL);
      eliberare(lines,nr);
    }
}

uint32_t find_word(char **lines, char *word, size_t nr)
{
  uint32_t apar = 0;
  size_t i = 0;
  char *p = NULL;
  for (i = 0; i<nr; i++)
    {
      if ((p = strstr(lines[i], word)) != NULL)
	do
	  {
	    apar++;
	    p = strstr(p+1,word);
	  } while (p != NULL);
    }
  return apar;
}

int main()
{
  char **tablou = NULL;
  size_t nr = 0;
  uint32_t apar = 0;
  FILE *in = NULL;
  if ((in = fopen("scrisoare.txt","r")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  tablou = citire(tablou,&nr,in);
  if (fclose(in) != 0)
    {
      eliberare(tablou,nr);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  apar = find_word(tablou,"a", nr);
  printf("%u\n",apar);
  write_sort(tablou,"out1.txt",nr);
  eliberare(tablou,nr);
  return 0;
}
