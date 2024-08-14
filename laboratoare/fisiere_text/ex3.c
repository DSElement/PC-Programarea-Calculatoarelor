/*     Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin semnul punct-virgulă. Fișierul conține informații statistice
 oferite de Institutul National de Statistica prin platforma OpenData a Guvernului Romaniei (https://data.gov.ro/) despre plata indemnizațiilor de creșterea copilului pe o anumită lună
 din anul 2021. Fișierul are următorul cap de tabel ce descrie câmpurile din liniile conținue

Judet;Populatie;Beneficiari plãtiti;Beneficiari suspendati la sfârsit de lunã;Suma totalã plãtitã drepturi curente;Alte plãþi

Programul va citi acest fișier folosind funcțiile dedicate pentru citirea fișierelor text, va extrage câmpurile judet, beneficiari platiti si suma total platita drepturi curente, si va
 stoca datele într-un tablou alocat dinamic, de structuri de date corespunzătoare, de dimensiune minimă necesară. Se cere să se implementeze tipuri de date utilizator. Se va implementa
 de asemenea o funcție de sortate dupa judet și o funcție de sortare după suma totala platita drepturi curente. Programul va scrie în fișierul rezultat.txt pe câte un rând diferit
 judetul cu cea mai mare populatie, judetul cu cea mai mare suma din câmpul alte plati.

Fișierul se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/indemnizatie.csv */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 200
#define CHUNK 100


typedef struct
{
  char *judet;
  unsigned beneficiari;
  unsigned suma;
  unsigned populatie;
}indemn;

indemn **tablou = NULL;
unsigned nr = 0;

void eliberare(size_t nr)
{
  size_t i = 0;
  for (i = 0; i<nr; i++)
    {
      if (tablou[i]->judet != NULL)
	free(tablou[i]->judet);
      if (tablou[i] != NULL)
	free(tablou[i]);
    }
  free(tablou);
}

indemn *adaugare(char*string, size_t nr, FILE *intrare)
{
  char *token = NULL;
  char *aux = NULL;
  indemn *final = NULL;
  uint8_t i = 0;
  token = strtok(string,";");
  if ((aux = (char*)malloc((strlen(token)+1)*sizeof(char))) == NULL)
    {
      eliberare(nr);
      fclose(intrare);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  strcpy(aux,token);
  if ((final = (indemn*)malloc(sizeof(indemn))) == NULL)
    {
      eliberare(nr);
      fclose(intrare);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  final->judet = aux;
  for (i = 1; i<5; i++)
    {
      token = strtok(NULL,";");
      if (i == 2)
	{
	  final->beneficiari = strtol(token,NULL,10);
	}
      if (i == 4)
	{
	  final->suma = strtol(token,NULL,10);
	}
      if (i == 1)
	{
	  final->populatie = strtol(token,NULL,10);
	}
    }
  return final;
}

void citire(FILE *intrare)
{
  char string[SIZE];
  size_t counter = 0;
  uint8_t checker = 0;
  indemn* structura = NULL;
  indemn **aux = NULL;
  for(;;)
    {
      if ((fgets(string,SIZE,intrare)) == NULL)
	{
	  if (feof(intrare))
	    break;
	  else
	    {
	      perror(NULL);
	      eliberare(counter);
	      fclose(intrare);
	      exit(EXIT_FAILURE);
	    }
	}
      if (checker == 0)
	{
	  checker = 1;
	  continue;
	}
      string[strcspn(string,"\n")] = '\0';
      if (strlen(string) == 0)
	continue;
      structura = adaugare(string, counter, intrare);
      if (counter == nr)
	{
	  if ((aux = (indemn**)realloc(tablou,(nr+CHUNK)*sizeof(indemn*))) == NULL)
	    {
	      perror(NULL);
	      eliberare(counter);
	      fclose(intrare);
	      exit(EXIT_FAILURE);
	    }
	  tablou = aux;
	  tablou[counter] = structura;
	  nr += CHUNK;
	  counter++;
	}
      else
	{
	  tablou[counter] = structura;
	  counter++;
	}
    }
  if (counter < nr)
    {
      if ((aux = (indemn**)realloc(tablou,counter*sizeof(indemn*))) == NULL)
	{
	  perror(NULL);
	  eliberare(counter);
	  fclose(intrare);
	  exit(EXIT_FAILURE);
	}
      tablou = aux;
      nr = counter;
    }
}

void sortare_judet()
{
  size_t i = 0;
  uint8_t check = 0;
  indemn *aux = NULL;
  do
    {
      check = 0;
      for (i = 1; i<nr; i++)
	{
	  if (strcmp(tablou[i-1]->judet,tablou[i]->judet) > 0)
	    {
	      aux = tablou[i-1];
	      tablou[i-1] = tablou[i];
	      tablou[i] = aux;
	      check = 1;
	    }
	}
    } while (check == 1);
}

void sortare_suma()
{
  size_t i = 0;
  uint8_t check = 0;
  indemn *aux = NULL;
  do
    {
      check = 0;
      for (i = 1; i<nr; i++)
	{
	  if (tablou[i-1]->suma > tablou[i]->suma)
	    {
	      aux = tablou[i-1];
	      tablou[i-1] = tablou[i];
	      tablou[i] = aux;
	      check = 1;
	    }
	}
    } while (check == 1);
}

void cea_mai_mare_populatie(FILE *file)
{
  indemn *aux = tablou[0];
  size_t i = 0;
  for (i = 1; i<nr; i++)
    {
      if (tablou[i]->populatie>aux->populatie)
	aux = tablou[i];
    }
  fprintf(file,"%s\n",aux->judet);
}

int main()
{
  FILE *in = NULL, *out = NULL;
  if ((in = fopen("indemnizatie.csv","r")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  citire(in);
  if (fclose(in) != 0)
    {
      perror(NULL);
      eliberare(nr);
      exit(EXIT_FAILURE);
    }
  if ((out = fopen("out.txt","w")) == NULL)
    {
      eliberare(nr);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  cea_mai_mare_populatie(out);
  sortare_suma();
  fprintf(out,"%s\n",tablou[nr-1]->judet);
  if (fclose(out) != 0)
    {
      eliberare(nr);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  eliberare(nr);
  return 0;
}
