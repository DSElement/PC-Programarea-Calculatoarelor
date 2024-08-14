/* O structură conține ora (ca si o alta structura potrivita) la care s-a măsurat o anumită temperatură și valoarea acestei temperaturi (real). Se cere n<=10 și apoi n temperaturi.
 Se cere apoi o oră de început și una de sfârșit. Să se afișeze media temperaturilor care au fost măsurate în acel interval orar, inclusiv în capetele acestuia. */

#include <stdio.h>

typedef struct
{
  int ora:5;
  double temp;
}temperatura;

int main()
{
  int n = 0, i = 0, count = 0,ora_intermediar = 0;
  int inceput_interval = 0, sfarsit_interval = 0;
  double media = 0;
  scanf("%d",&n);
  temperatura tablou[9];
  for (i = 0; i<n; i++)
    {
      scanf("%d",&ora_intermediar);
      tablou[i].ora = ora_intermediar;
      scanf("%lf",&tablou[i].temp);
    }
  printf ("In ce interval doriti sa aflati valoarea medie a temperaturii?\n");
  scanf("%d%d",&inceput_interval,&sfarsit_interval);
  for (i = 0; i<n; i++)
    {
      if ((tablou[i].ora > inceput_interval) && (tablou[i].ora < sfarsit_interval))
	{
	  count++;
	  media += tablou[i].temp;
	}
    }
  media /= count;
  printf("Media temperaturilor din acel interval este %f\n",media);
  return 0;
}
