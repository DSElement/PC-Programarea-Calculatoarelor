/* Un fisier binar incepe cu un numar fara semn pe 32 de biti care reprezinta numarul de inregistrari din fisier. Dupa acesta urmeaza inregistrarile, implementate prin structura 
urmatoare:
- an - nr fara semn pe 16 biti
- luna - nr fara semn pe 8 biti
- zi - nr fara semn pe 8 biti
- idx senzor - nr fara semn pe 8 biti
- valoare - nr cu semn pe 16 biti
O inregistrare codifica valoarea citita de un senzor la o anumita data. Valorile corecte pot fi in intervalul [-1000,1000]. Daca un senzor da din cand in cand valori in afara 
intervalului, atunci se considera ca are probleme. Daca toate valorile sunt in afara intervalului, atunci senzorul este defect.
Cerinte:
- sa se scrie o functie care creaza un fisier de test, ce cuprinde valori pentru un senzor care merge, altul care are probleme
si altul defect.
- sa se citeasca fisierul de test si sa se afiseze care senzor merge, care are probleme si care e defect.
- se cere de la tastatura un an si o luna. Se cere sa se afiseze toate valorile senzorilor din acel an/luna. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


typedef struct
{
  uint16_t an;
  uint8_t luna;
  uint8_t zi;
  uint8_t indx;
  int16_t valoare;
}structura;

structura *creare(char *path)
{
  structura *temp = NULL;
  srand(time(NULL));
  FILE *test = NULL;
  if ((test = fopen(path,"wb")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  unsigned size = (rand() % 10000)+1, i = 0;
  fwrite(&size,sizeof(unsigned),1,test);
  if ((temp = (structura*)malloc(size*sizeof(structura))) == NULL)
    {
      perror(NULL);
      fclose(test);
      exit(EXIT_FAILURE);
    }
  for (i = 0; i<size; i++)
    {
      temp[i].an = 2024;
      temp[i].luna = rand() % 12 + 1;
      temp[i].zi = rand() % 30 + 1;
      temp[i].indx = rand() % 3 + 1;
      switch(temp[i].indx)
	{
	case 1:
	  {
	    temp[i].valoare = rand() % 5000 + 3000;
	    break;
	  }
	case 2:
	  {
	    temp[i].valoare = rand() % 2001 - 1000;
	    break;
	  }
	case 3:
	  {
	    temp[i].valoare = rand() % 3000 - 1500;
	    break;
	  }
	default:
	  {
	    fprintf(stderr,"problema la default");
	    exit(EXIT_FAILURE);
	  }
	}
    }
  fwrite(temp,sizeof(structura),size,test);
  if (fclose(test) != 0)
    {
      perror(NULL);
      free(temp);
      exit(EXIT_FAILURE);
    }
  return temp;
}

typedef struct
{
  uint8_t check1;
  uint8_t check2;
}verificare;

void determinare(char *path)
{
  FILE *in = NULL;
  structura temporar;
  verificare tab[] = {{0, 1}, {0, 1}, {0, 1}};
  if ((in = fopen(path,"rb")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  unsigned size = 0, i = 0;
  if (fread(&size,sizeof(unsigned),1,in) != 1)
    {
      perror(NULL);
      fclose(in);
      exit(EXIT_FAILURE);
    }
  for (i = 0; i<size; i++)
    {
      if (fread(&temporar,sizeof(structura),1,in) != 1)
	{
	  perror(NULL);
	  fclose(in);
	  exit(EXIT_FAILURE);
	}
      if ((temporar.valoare <= 1000) && (temporar.valoare >= -1000))
	tab[temporar.indx-1].check1 = 1;
      else
	tab[temporar.indx-1].check2 = 0;
    }
  for (i = 0; i<3; i++)
    {
      if ((tab[i].check1 == 1) && (tab[i].check2 == 1))
	  printf("Senzorul %u functioneaza\n",i+1);
      if ((tab[i].check1 == 1) && (tab[i].check2 == 0))
	  printf("Senzorul %u are probleme\n",i+1);
      if ((tab[i].check1 == 0) && (tab[i].check2 == 0))
	  printf("Senzorul %u nu functioneaza\n",i+1);
    }
  if (fclose(in) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
  structura *tablou;
  tablou = creare(argv[1]);
  determinare(argv[1]);
  free(tablou);
  return 0;
}
