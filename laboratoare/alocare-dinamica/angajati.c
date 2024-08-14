/* Exemplul 12.5: Un angajat este definit prin nume, funcție și salariu. Să se implementeze o bază de date cu angajați, care să permită adăugarea, ștergerea și listarea înregistrărilor,
 astfel încât memoria folosită să fie minimă. */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
  char *nume;
  char *functie;
  float salariu;
}Angajat;

Angajat **angajati = NULL;
uint16_t nr_angajati = 0;

void eliberare()
{
  uint8_t i = 0;
  for(i = 0; i<nr_angajati; i++)
    {
      free(angajati[i]->nume);
      free(angajati[i]->functie);
      free(angajati[i]);
    }
  free(angajati);
}

char *citire_sir(const char *string)
{
  char *temp_sir = NULL;
  uint8_t length = 0;
  char *sir = NULL;
  char caracter = 0;
  printf("%s:\n",string);
  for(;;)
    {
      if ((temp_sir = (char*)realloc(sir,(length+1)*sizeof(char))) == NULL)
	{
	  eliberare();
	  if (sir)
	    free(sir);
	  exit(EXIT_FAILURE);
	}
      sir = temp_sir;
      if ((caracter = getchar()) == EOF)
	{
	  eliberare();
	  printf("Eroare in citire_sir\n");
	  exit(EXIT_FAILURE);
	}
      if (caracter == '\n')
	break;
      sir[length] = caracter;
      length++;
    }
  sir[length] = '\0';
  return sir;
}

int main()
{
  uint8_t n = 0;
  Angajat **temp = NULL;
  Angajat *p = NULL;
  uint16_t i = 0, j = 0;
  char *string_de_eliminat = NULL;
  for(;;)
    {
      printf("Tastati 1 pentru adaugare\n");
      printf("Tastati 2 pentru stergere\n");
      printf("Tastati 3 pentru listare\n");
      printf("Tastati 0 pentru iesire\n");
      scanf("%hhd",&n);
      switch(n)
	{
	case 1:
	  {
	    temp = (Angajat**)realloc(angajati,(nr_angajati+1)*sizeof(Angajat*));
	    if (temp == NULL)
	      {
		eliberare();
		printf("Eroare la realocarea tabloului\n");
		exit(EXIT_FAILURE);
	      }
	    angajati = temp;
	    if ((p = (Angajat*)malloc(sizeof(Angajat))) == NULL)
	      {
		printf("Eroare la alocarea memoriei unei structuri\n");
		eliberare();
		exit(EXIT_FAILURE);
	      }
	    p->nume = NULL;
	    p->functie = NULL;
	    angajati[nr_angajati] = p;
	    getchar();
	    p->nume = citire_sir("Nume");
	    p->functie = citire_sir("Functie");
	    nr_angajati++;
	    printf("Salariu:\n");
	    scanf("%f",&p->salariu);
	    break;
	  }
	case 2:
	  {
	    getchar();
	    string_de_eliminat = citire_sir("Numele angajatului pe care il eliminam din baza de date");
	    for (i = 0; i<nr_angajati; i++)
	      {
		if ((strcmp(string_de_eliminat,angajati[i]->nume)) == 0)
		  {
		    free(angajati[i]->nume);
		    free(angajati[i]->functie);
		    free(angajati[i]);
		    for (j = i+1; j<nr_angajati; j++)
		      {
			angajati[j-1] = angajati[j];
		      }		    
		    nr_angajati--;
		    i--;
		  }
	      }
	    free(string_de_eliminat);
	    break;
	  }
	case 3:
	  {
	    for (i = 0; i<nr_angajati; i++)
	      {
		printf("\t%s\n",angajati[i]->nume);
		printf("\t%s\n",angajati[i]->functie);
		printf("\t%.2f\n",angajati[i]->salariu);
		printf("\n");
	      }
	    break;
	  }
	case 0:
	  {
	    eliberare();
	    return 0;
	  }
	default:
	  printf("Uknown command\n");
	  break;
	}
    }
  return 0;
}
