/* Exemplul 12.1: Se definește o structură Dreptunghi care conține lățimea și lungimea unui dreptunghi. Se cere n<=10 și apoi n dreptunghiuri. 
Să se afișeze dimensiunile dreptunghiului de arie maximă. */

/*#include <stdio.h>

struct Dreptunghi
{
  int latime,lungime;
};

int main()
{
  int n = 0, i = 0, max = 0, index = 0;
  struct Dreptunghi dreptunghiuri[10];
  scanf("%d",&n);
  for (i = 0; i<n; i++)
    {
      scanf("%d%d",&dreptunghiuri[i].latime,&dreptunghiuri[i].lungime);
      if (dreptunghiuri[i].latime*dreptunghiuri[i].lungime > max)
	{
	  max = dreptunghiuri[i].latime*dreptunghiuri[i].lungime;
	  index = i;
	}
      
    }
  printf("Dreptunghiul cel mai mare are dimensiunile: latime - %d, lungime - %d\n",dreptunghiuri[index].latime,dreptunghiuri[index].lungime);
  return 0;
  } */

/* Exemplul 12.2: Să se implementeze o bază de date cu produse definite prin câmpurile nume și preț. Operațiile necesare sunt introducere, afișare și ieșire, iar ele se vor cere de la tastatură, 
utilizatorului fiindu-i prezentat un meniu de unde poate alege operația dorită. 
Aplicația 12.2: Să se extindă exemplul 2 cu operația de căutare de produs după nume: se cere un nume de la tastatură și apoi se caută în baza de date. Dacă s-a găsit, se va afișa prețul său. 
Dacă nu s-a găsit, se va afișa textul „produs inexistent”.*/

/*#include <stdio.h>
#include <string.h>

typedef struct
{
  char nume[50];
  float pret;
} Produs;


int main()
{
  int i = 0, i1 = 0, n = 0;
  Produs produse[100];
  char s[50];
  for (;;)
    {
      printf("Pentru introducere de noi elemente tastati 1\n");
      printf("Pentru afisarea tuturor produselor tastati 2\n");
      printf("Pentru cautare tastati 3\n");
      printf("Pentru iesire tastati 0\n");
      printf("Ce operatie doriti sa efectuati: ");
      scanf("%d",&i);
      switch (i)
	{
	case 1:
	  {
	    getchar();
	    if (fgets(produse[n].nume,50,stdin) == NULL)
	      {
		printf("EROARE\n");
		return 0;
	      }
	    else
	      scanf("%g",&produse[n].pret);
	    produse[n].nume[strcspn(produse[n].nume,"\n")] = '\0';
	    n++;
	    break;
	  }
	case 2:
	  {
	    for (i1 = 0; i1<n; i1++)
	      {
		printf("produsul - %s, pretul - %4g\n",produse[i1].nume,produse[i1].pret);
	      }
	    break;
	  }
	case 3:
	  {
	    getchar();
	    if (fgets(s,50,stdin) != NULL)
	      {
		s[strcspn(s,"\n")] = '\0';
		for (i1 = 0; i1<n; i1++)
		  {
		    if (strcmp(produse[i1].nume,s) == 0)
		      {
			printf ("pretul produsului este %2f\n", produse[i1].pret);
			break;
		      }
		  }
		if (i1 == n)
		  printf("Produs inexistent\n");
	      }
	    else
	      {
		printf("Eroareeeeeeeee\n");
		return 0;
	      }
	    break;
	  }
	case 0:
	  {
	    return 0;
	    break;
	  }
	default:
	  {
	    printf("Unknown operation\n");
	  }
	}
      
    }
  return 0;
  } */


/* Exemplul 12.4: Se consideră o structură Produs care conține un câmp nume și altul pret. Să se scrie o funcție care primește ca parametru un produs și un procent 
reprezentând o reducere de preț. Funcția va modifica prețul produsului conform cu reducerea dată. În programul principal se vor introduce un număr n de produse, cu 
n citit de la tastatură. Folosind funcția definită anterior, să se modifice prețurile produselor și să se afișeze. */

#include <stdio.h>
#include <string.h>

struct Produs
{
  char nume[50];
  float pret;
};

void reducere(struct Produs *p ,float procentaj1)
{
  p->pret *= (1 - procentaj1/100);
}

int main()
{
  struct Produs produse[100];
  int n = 0, i = 0, procentaj = 0;
  char s[50];
  scanf("%d",&n);
  for (i = 0; i<n; i++)
    {
      getchar();
      if (fgets(produse[i].nume,50,stdin) == NULL)
	{
	  printf("Eroare\n");
	  return 0;
	}
      else
	{
	  produse[i].nume[strcspn(produse[i].nume,"\n")] = '\0';
	  scanf("%f",&produse[i].pret);
	}
    }
  printf("Cu cat scadem in procente: ");
  scanf("%d",&procentaj);
  getchar();
  printf("Si la care produs facem reducerea?");
  if (fgets(s,50,stdin) != NULL)
    {
      s[strcspn(s,"\n")] = '\0';
      for (i = 0; i < n; i++)
	if (!strcmp(s,produse[i].nume))
	  break;
      
    }
  reducere(&produse[i],procentaj);
  for (i = 0; i<n; i++)
    printf("produsul - %s,  pretul - %g\n",produse[i].nume,produse[i].pret);
  return 0;
}
