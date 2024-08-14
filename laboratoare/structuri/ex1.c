/* 
    Să se scrie un program ce definește un tip de date utilizator ce modelează un număr complex și o serie de funcții ce realizeaza operațiile de bază cu numere complexe. 
Programul se va testa prin numere introduse de la tastatură

    o funcție de adunare ce primește ca argument două numere complexe și returnează un număr complex ce reprezinta suma celor 2 numere complexe primite ca și argumente
    o funcție de scadere ce primește ca argument două numere complexe și returnează un număr complex ce reprezinta diferența celor 2 numere complexe primite ca și argumente
    o funcție de înmulțire ce primește ca argument două numere complexe și returnează un număr complex ce reprezinta produsul celor 2 numere complexe primite ca și argumente
    o funcție de afișare a unui număr complex în formă algebrică: a+bj - primește ca argument numărul complex
    o funcție de calcul a modulului unui număr compex - primește ca argument numărul complex și returnează un double ce reprezintă modulul numărului complex. Se va folosi functia
 sqrt din <math.h>. Pentru compilare se adauga parametrul -lm la gcc.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
  int partea_reala;
  int partea_imaginara;
}numar_complex;

void adunare()
{
  char string[10];
  char *second_part;
  int a=0,b=0,c=0,d=0;
  getchar();
  printf("Introduceti doua numere complexe, fiecare din rand nou, sub forma 'a+bi'\n");
  
  if (fgets(string,10,stdin) == NULL)
    return;
  a = strtol(string,&second_part,10);
  b = strtol(second_part,NULL,10);
  c = a; d = b;
  if (fgets(string,10,stdin) == NULL)
    return;
  a = strtol(string,&second_part,10);
  b = strtol(second_part,NULL,10);
  c += a; d += b;
  printf("%d+%di\n",c,d);
}

void scadere()
{
  char string[10];
  char *second_part;
  int a=0,b=0,c=0,d=0;
  getchar();
  printf("Introduceti doua numere complexe, fiecare din rand nou, sub forma 'a+bi'\n");
  
  if (fgets(string,10,stdin) == NULL)
    return;
  a = strtol(string,&second_part,10);
  b = strtol(second_part,NULL,10);
  c = a; d = b;
  if (fgets(string,10,stdin) == NULL)
    return;
  a = strtol(string,&second_part,10);
  b = strtol(second_part,NULL,10);
  c -= a; d -= b;
  printf("%d+%di\n",c,d);
}

void inmultire()
{
  char string[10];
  char *second_part;
  int a=0,b=0,c=0,d=0;
  getchar();
  printf("Introduceti doua numere complexe, fiecare din rand nou, sub forma 'a+bi'\n");
  
  if (fgets(string,10,stdin) == NULL)
    return;
  a = strtol(string,&second_part,10);
  b = strtol(second_part,NULL,10);
  c = a; d = b;
  if (fgets(string,10,stdin) == NULL)
    return;
  a = strtol(string,&second_part,10);
  b = strtol(second_part,NULL,10);
  c *= a; d *= b;
  printf("%d+%di\n",c,d);
}

void afisare()
{
  char string[10];
  if (fgets(string,10,stdin) == NULL)
    return;
  printf("%s\n",string);
}

void modulul()
{
  char string[10];
  char *second_part;
  int a=0,b=0;
  double s = 0;
  getchar();
  printf("Introduceti doua numere complexe, fiecare din rand nou, sub forma 'a+bi'\n");
  
  if (fgets(string,10,stdin) == NULL)
    return;
  a = strtol(string,&second_part,10);
  b = strtol(second_part,NULL,10);
  s = sqrt(a*a+b*b);
  printf("%f\n",s);
}

int main()
{
  int n = 0;
  for (;;)
    {
      printf("Introduceti:\n");
      printf("1 --- pentru adunarea a doua numere complexe\n");
      printf("2 --- pentru scaderea a doua numere complexe\n");
      printf("3 --- pentru inmultirea a doua numere complexe\n");
      printf("4 --- pentru afisarea unui numar complex in forma sa algebrica\n");
      printf("5 --- pentru a calcula modulul unui numar complex\n");
      printf("0 --- pentru iesire\n");
      scanf ("%d",&n);
      switch(n)
	{
	case 1:
	  {
	    adunare();
	    break;
	  }
	case 2:
	  {
	    scadere();
	    break;
	  }
	case 3:
	  {
	    inmultire();
	    break;
	  }
	case 4:
	  {
	    afisare();
	    break;
	  }
	case 5:
	  {
	    modulul();
	    break;	      
	  }
	case 0:
	  {
	    return 0;
	  }
	default:
	  {
	    printf("uknown command\n");
	    break;
	  }
	}
    }
  return 0;
}
