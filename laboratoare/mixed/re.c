/*
Să se scrie o funcție care primește ca argument un număr pe 32 de biți fără semn (nr), un număr pe 8 biți fără semn (n) și o poziție (p). Funcția va returna numărul (nr) în 
care octetul de pe poziția p va fi inlocuit cu numărul n. Octeții se numără se la dreapta (cel mai puțin semnificativ, poziția 0) spre stanga
exemplu: nr = 0011 0110 0101 1011 0011 0110 0101 1011 = 911.947.35510 , n = 1110 1111 = 23910, p = 2 -> rezultat: 0011 0110 1110 1111 0011 0110 0101 1011
 */

/*#include <stdio.h>
#include <stdint.h>

void showbits(uint32_t nr)
{
  int i = 0;
  for (i = sizeof(nr)*8-1; i >= 0; i--)
    {
      printf("%d",(nr >> i) & 1);
    }
  printf("\n");
}


uint32_t functie(uint32_t nr,uint8_t n,uint8_t p)
{
  uint32_t mask = 0;
  mask = n;
  uint8_t i = 0;
  mask = mask << (p*8);
  for (i = (p+1)*8-1; i >= p*8; i--)
    {
      nr = nr & ~(1 << i);
    }
  showbits(mask);
  printf("\n");
  nr = nr | mask;
  return nr;
}


int main()
{
  uint32_t nr = 0b00110110010110110011011001011011;
  uint8_t n = 0b11101111, p = 2;
  
  showbits(functie(nr,n,p));
  printf("\n");
  printf("00110110111011110011011001011011\n");
  return 0;
}
*/

/*
Se citește un număr n<=10 și apoi n numere întregi. Se cere să se insereze după fiecare valoare din vectorul original pătratul ei.
 */

/*
#include <stdio.h>

int main()
{
  int tab[20];
  int n = 0,i = 0,j = 0;
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    scanf("%d",&tab[i]);
  for (i = 0; i < n; i++)
    {
      for (j = n; j > i; j--)
	{
	  tab[j] = tab[j-1];
	}
      tab[i+1] = tab[i]*tab[i];
      n++;
      i++;
    }
  printf("\n");
  for (i = 0; i < n; i++)
    printf("%d ",tab[i]);
  printf("\n");
  return 0;
}
*/

/*
  Se dă vectorul {7, -5, 4, 3, -9, 2, -8}. Să se insereze înainte de fiecare valoare din vectorul original negativul ei. Utilizați pointeri, fără indecși.
 */

/*#include <stdio.h>

int main()
{
  int tab[14] = {7, -5, 4, 3, -9, 2, -8};
  int *p1 = 0, *p2 = 0, n = 7;
  for (p1 = tab; p1 < tab + n; p1++)
    {
      for (p2 = tab+n; p2 > p1; p2--)
	{
	  *p2 = *(p2-1);
	}
      *p1 = -(*p1);
      n++;
      p1++;
    }
  for (p1 = tab; p1 < tab + n; p1++)
    printf("%d ", *p1);
  printf("\n");
  
  return 0;
  } */

/*
  Scrieți un program, folosind getchar() și putchar() prin care se numără cuvintele de la stdint. Se consideră un cuvânt ca fiind o secvență de
 litere mici și/sau mari care despărțite prin unul sau mai multe spații, tab-uri, linii noi și EOF. Testarea se va face atât clasic prin scriere
 la stdin cât și prin redirectare cu un fișier text realizat inainte ca și caz de test catre intrarea standard a programului
 */

#include <stdio.h>
#include <ctype.h>

int main()
{
  int i = 0,wc = 0;
  char c;
  while ((c = getchar()) != EOF)
    {
      if ((((c > 'a') && (c < 'z')) || ((c > 'A') && (c < 'Z'))) && (i == 0))
	{
	  i = 1;
	}
      else if ((((c > 'a') && (c < 'z')) || ((c > 'A') && (c < 'Z'))) && (i == 1))
	continue;
      else if (!(isalpha(c)) && (i == 1))
	{
	  i = 0;
	  wc++;
	}
    }
  if (i == 1)
    wc++;
  printf("%d\n",wc);
  return 0;
}
