/* Se citește un n<=10 și apoi n nume de persoane, fiecare nume putând apărea de mai multe ori. Să se afișeze de câte ori apare fiecare nume */

#include <stdio.h>
#include <string.h>

struct Persoane
{
  char nume[50];
  int aparitii;
};

int main()
{
  struct Persoane tablou[10];
  int n = 0, i = 0, j = 0;
  scanf("%d",&n);
  getchar();
  for (i = 0; i<n; i++)
    {
      if (fgets(tablou[i].nume,50,stdin) == NULL)
	{
	  printf("Ai eroare fra");
	  return -1;
	}
      else
	{
	  tablou[i].nume[strcspn(tablou[i].nume,"\n")] = '\0';
	  tablou[i].aparitii = 1;
	  for (j = 0; j<i; j++)
	    {
	      if (strcmp(tablou[i].nume,tablou[j].nume) == 0)
		{
		  tablou[j].aparitii += 1;
		  i--;
		  n--;
		  break;
		}
	    }	  
	}
    }
  for (i = 0; i<n; i++)
    {
      printf("Numele %s are %d aparitii\n",tablou[i].nume,tablou[i].aparitii);
    }
  printf("%d\n",n);
  return 0;
}
