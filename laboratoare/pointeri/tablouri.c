//Exemplu: Se dă vectorul {7, -5, 4, 3, -9, 2, -8}. Să se insereze înainte de fiecare valoare din vectorul original negativul ei.

/*#include <stdio.h>

int main()
{
  int v[14]={7,-5,4,3,-9,2,-8};
  int i=0,n=7,j=0;
  for (i=0; i<n; i++)
    {
      for (j = n; j > i; j--)
	{
	  v[j] = v[j-1];
	}
      v[i] = -v[i+1];
      n++;
      i++;
    }
  for (i=0;i<n;i++)
    printf("%d ",v[i]);
  return 0;
  } */

//Să se scrie o funcție care ia un număr fără semn n și returnează numărul de segmente de biți consecutivi egali. Exemplu: 000100 are 3 segmente: 000, 1, 00, deci programul va returna 3

/*#include <stdio.h>

int main()
{
  unsigned n = 0;
  int v[32];
  scanf("%u",&n);
  int i=0,j=0,b=0;
  for (i = sizeof(n)*8-1; i>=0; i--)
    {
      v[j] = 1 & (n >> i);
      j++;
    }
  j = 1;
  b = v[0];
  for (i=1;i<32;i++)
    {
      printf("%d",v[i]);
      if ((v[i]) != b)
	{
	  j++;
	  b = v[i];
	}
    }
  printf("\n");
  printf("%d\n",j);
  return 0;
  } */


//Să se citească de la tastatură un număr n<=5 iar apoi n valori de tip intreg. Să se afișeze toate valorile ale căror modul (valoare absolută) este strict mai mare decat 10.

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n = 0,i = 0;
  scanf("%d",&n);
  int v[5];
  for (i = 0; i<n; i++)
    scanf("%d",&v[i]);
  for (i = 0; i<n; i++)
    if (abs(v[i]) > 10)
      printf("%d ",v[i]);
  printf("\n");
  return 0;
  } */

//Se citește un număr n (n<=10) și apoi n numere întregi. Se cere să se sorteze aceste numere astfel încât numerele impare să fie înaintea celor pare

/*#include <stdio.h>

int main()
{
  int n = 0, i = 0, j = 0, s = 0, aux = 0;
  int v[10];
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    scanf("%d",&v[i]);

  for (i = 0; i<n; i++)
    {
      if (v[i] % 2 == 1)
	{
	  aux = v[i];
	  for (j = i; j>0; j--)
	    {
	      v[j] = v[j-1];
	    }
	  v[0] = aux;
	  aux = 0;
	}
    }
  
  for (i = 0; i<n; i++)
    printf("%d ",v[i]);
  printf("\n");
  return 0;
  } */

//Se citește un număr n<=10 și apoi n numere întregi. Se cere să se insereze după fiecare valoare din vectorul original pătratul ei.

#include <stdio.h>

int main()
{
  int n = 0, i = 0, j = 0;
  int v[20];
  scanf ("%d",&n);
  for (i = 0; i<n; i++)
    scanf ("%d",&v[i]);
  for (i = 0; i<n; i++)
    {
      for(j = n; j>i; j--)
	{
	  v[j] = v[j-1];
	}
      v[i+1] = (v[i]*v[i]);
      i++;
      n++;
      printf("%d ",v[i-1]);
    }
  printf("\n");
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
  return 0;
}
