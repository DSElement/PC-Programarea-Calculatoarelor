/* Jocul fazan: se citesc de la tastatură cuvinte separate prin spaţii albe (spaţiu, TAB sau ENTER), până la întâlnirea cuvântului vid. Pornind de la cuvintele citite, se construieşte 
un şir de caractere după următoarele reguli:
    - Primul cuvânt citit se adaugă la şirul de caractere
    - Fiecare din următoarele cuvinte citite se adaugă la şirul de caractere dacă ultimele două litere ale şirului coincid cu primele două litere ale cuvântului (nu se face distincţie 
între literele mici şi cele mari);
Cuvintele adăugate la şirul de caractere sunt despărţite de caracterul ’-’. Să se afişeze şirul astfel construit. Programul va folosi alocare dinamică astfel încât spaţiul de memorie 
utilizat să fie minim.
Spre exemplu, pentru intrarea:

Fazan Antic Noe icoana Egipt naftalina nimic Narcisa trei altceva santier iarba Caine Pisica erudit

se afişează:
Fazan-Antic-icoana-naftalina-Narcisa-santier-erudit */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 100

char **tablou = NULL;
uint16_t nr_cuvinte = 0;

void eliberare()
{
  uint32_t i = 0;
  for(i = 0; i<nr_cuvinte; i++)
    if (tablou[i])
      free(tablou[i]);
  free(tablou);
}

char *citire_sir_mare(uint32_t *len)
{
  uint32_t index = 0;
  uint8_t i = 0;
  char *sir = NULL;
  char temp[CHUNK]; uint8_t size_temp = 0;
  char *sir_temporar = NULL;
  while ((fgets(temp,CHUNK,stdin)) != NULL)
    {
      size_temp = strlen(temp);
      if ((sir_temporar = (char*)realloc(sir,(*len+size_temp)*sizeof(char))) == NULL)
	{
	  printf("Eroare la alocarea memoriei\n");
	  if (sir)
	    free(sir);
	  exit(EXIT_FAILURE);
	}
      sir = sir_temporar;
      for (i = 0; i<size_temp; i++)
	{
	  sir[index] = temp[i];
	  index++;
	}
      *len += size_temp;
    }
  (*len)++;
  if ((sir_temporar = (char*)realloc(sir,(*len)*sizeof(char))) == NULL)
	{
	  printf("Eroare la alocarea memoriei\n");
	  if (sir)
	    free(sir);
	  exit(EXIT_FAILURE);
	}
  sir = sir_temporar;
  sir[*len-1] = '\0';
  return sir;
}

void spargere_stringuri(char* sir,uint32_t *len)
{
  uint32_t index = 0;
  uint8_t i = 0;
  char caracter = 0;
  char *string = NULL;
  char **tab_temp = NULL;
  char *string_temp = NULL;
  while (index < *len)
    {
      caracter = sir[index];
      if (caracter == EOF)
	return;
      i = 0;
      while (isspace(caracter))
	{
	  index++;
	  caracter = sir[index];
	}
      if (caracter == EOF)
	return;
      string = &sir[index];
      do
	{
	  index++;
	  i++;
	} while ((isgraph(sir[index])) && (!isspace(sir[index])));
      nr_cuvinte++;
      if ((tab_temp = (char**)realloc(tablou,nr_cuvinte*sizeof(char*))) == NULL)
	{
	  printf("Eroare la realocare\n");
	  free(sir);
	  eliberare();
	  exit(EXIT_FAILURE);
	}
      tablou = tab_temp;
      if ((string_temp = (char*)malloc((i+1)*sizeof(char))) == NULL)
	{
	  eliberare();
	  free(sir);
	  printf("Eroare la alocare\n");
	  exit(EXIT_FAILURE);
	}
      tablou[nr_cuvinte-1] = string_temp;
      strncpy(string_temp,string,i);
      string_temp[i] = '\0';
    }
}

int main()
{
  char *sir = NULL;
  uint32_t length = 0;
  sir = citire_sir_mare(&length);
  spargere_stringuri(sir,&length);
  for (uint16_t i = 0; i<nr_cuvinte; i++)
    printf("%s\n",tablou[i]);
  printf("%s-",tablou[0]);
  for (uint16_t i = 0; i<nr_cuvinte-1; i++)
    {
      for (uint16_t j = i+1; j<nr_cuvinte; j++)
	{
	  if ((tolower(tablou[i][strlen(tablou[i])-2]) == tolower(tablou[j][0])) && (tolower(tablou[i][strlen(tablou[i])-1]) == tolower(tablou[j][1])))
	    {
	      printf("%s-",tablou[j]);
	      i = j-1;
	      break;
	    }
	}
    }
  printf("\n");
  eliberare();
  free(sir);
  return 0;
}
