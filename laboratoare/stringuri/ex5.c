/* Se citește n din intervalul [3,10] și apoi n nume de persoane. Să se concateneze primele n-1 nume folosind „, ”, ultimul nume cu „ si ”, iar apoi să se adauge „invata.”. Să se afișeze propoziția rezultată.
Exemplu: n=3, numele: Ion Ana Maria
Propoziție rezultata: Ion, Ana și Maria invata. */

#include <stdio.h>
#include <string.h>

int main()
{
  int n = 0, i = 0;
  char nume[20];
  char temporar[30];
  char string[150] = "";
  scanf("%d",&n);
  for (i = 0; i<=n; i++)
    {
      if (fgets(nume,20,stdin) == NULL)
	{
	  printf("eroare la citire");
	  return (-1);
	}
      nume[strcspn(nume,"\n")] = '\0';
      if (i > 1)
	strcat(string,", ");
      strcat(string,nume);
    }
  for (i = strlen(string); i>0; i--)
    if (string[i] == ',')
      break;
  char *c = &string[i+2];
  string[i] = '\0';
  strcpy(temporar,c);
  strcat(string," si ");
  strcat(string, temporar);
  strcat(string," invata.");
  printf("%s\n",string);
  return 0;
}
