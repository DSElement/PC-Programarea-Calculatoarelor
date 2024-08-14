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
#include <stdint.h>
#include <time.h>

typedef struct
{
  uint16_t an;
  uint8_t luna;
  uint8_t zi;
  uint8_t idx;
  int16_t valoare;
}structura;

FILE *creare(char *path)
{
  FILE *out = NULL;
  if ((out = fopen(path,"w+b")) == NULL)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  srand(time(NULL));
  unsigned i = 0, size = 0;
  structura temporar;
  size = (rand() % 10000) + 1;
  fwrite(&size,sizeof(unsigned),1,out);
  for (i = 0; i<size; i++)
    {
      temporar.an = 2024;
      temporar.luna = (rand() % 12)+1;
      temporar.zi = (rand() % 29)+1;
      temporar.idx = (rand() % 3)+1;
      switch (temporar.idx)
	{
	case 2:
	  {
	    temporar.valoare = (rand() % 2001)-1000;
	    break;
	  }
	case 1:
	  {
	    temporar.valoare = (rand() % 2001)-1500;
	    break;
	  }
	case 3:
	  {
	    temporar.valoare = (rand() % 5000) + 5000;
	    break;
	  }
	default:
	  {
	    temporar.valoare = 1001;
	    break;
	  }
	}
      if ((fwrite(&temporar,sizeof(structura),1,out)) != 1)
	{
	  fclose(out);
	  perror(NULL);
	  exit(EXIT_FAILURE);
	}
    }
  return out;
}

typedef struct
{
  uint8_t check1;
  uint8_t check2;
}verificare;

void afisare(FILE *file)
{
  unsigned size = 0, i = 0;
  rewind(file);
  verificare tablou[] = {{0, 1}, {0, 1}, {0, 1}};
  structura temporar;
  if (fread(&size,sizeof(unsigned),1,file) != 1)
    {
      fclose(file);
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  for (i = 0; i<size; i++)
    {
      if (fread(&temporar,sizeof(structura),1,file) != 1)
	{
	  perror(NULL);
	  fclose(file);
	  exit(EXIT_FAILURE);
	}
      if ((temporar.valoare >= -1000) && (temporar.valoare <= 1000))
	  tablou[temporar.idx-1].check1 = 1;
      else
	tablou[temporar.idx-1].check2 = 0;
    }
  for (i = 0; i<3; i++)
    {
      if ((tablou[i].check1 == 1) && (tablou[i].check2 == 1))
	printf("senzorul %hhu merge\n",i+1);
      else
	if ((tablou[i].check1 == 1) && (tablou[i].check2 ==0))
	  printf("senzorul %hhu are probleme\n",i+1);
	else
	  printf("senzorul %hhu e defect\n",i+1);
    }
  if (fclose(file) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
  if (argc!=2)
    {
      fprintf(stderr,"Nu au fost introduse suficiente argumente\n");
      exit(EXIT_FAILURE);
    }
  FILE *test = NULL;
  test = creare(argv[1]);
  afisare(test);
  if (fclose(test) != 0)
    {
      perror(NULL);
      exit(EXIT_FAILURE);
    }
  return 0;
}
