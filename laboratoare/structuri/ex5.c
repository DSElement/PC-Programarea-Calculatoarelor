/* Să se implementeze o bază de date ce modelează animale. Animelele pot fi insecte, păsări, mamifere și pești. O insectă se caracterizează prin număr picioare și durata medie de 
viată în zile, o pasăre prin viteza de zbor și lungimea aripilor, un mamifer prin greutate, înălțime și tip de mancare (carnivor, ierbivor, omnivor) iar un pește prin greutate, 
adâncimea maximă de înnot și salinitatea apei (în procentaj). Să se definnească structurile de date necesare cât mai abstract posibil și cu amprenta de memorie minima. Se va 
defini un tablou de astfel de structuri și se vor implementa funcții de adaugare animal, stergere animal și printare animale. */

#include <stdio.h>
#include <string.h>

typedef struct
{
  float numar_picioare;
  float durata_de_viata;  //in zile
}insecte;

typedef struct
{
  int viteza_de_zbor;
  double lungimea_aripilor;
}pasari;

typedef struct
{
  double greutate;
  double inaltime;
  enum {carnivor,ierbivor,omnivor}tip_mancare;
}mamifere;

typedef struct
{
  double greutate;
  double adancimea_inot;
  double salinitatea_apei;   //in procente
}pesti;

typedef struct
{
  char Nume[50];
  char tipul[20];
  union
  {
    insecte insecta;
    pasari pasare;
    mamifere mamifer;
    pesti peste;
  }tipp;
}animal;

animal Animale[100];
int nr_animale = 0;

void adaugare(char *nume,char *tip, float spec1, float spec2)
{
  if (nr_animale<100)
    {
      strcpy(Animale[nr_animale].Nume,nume);
      strcpy(Animale[nr_animale].tipul,tip);
      if (strcmp(tip,"insecta") == 0)
	{
	  Animale[nr_animale].tipp.insecta.numar_picioare = spec1;
	  Animale[nr_animale].tipp.insecta.durata_de_viata = spec2;
	}
    }
  else
    printf("Nu mai e loc in baza de date\n");
}

int main()
{
  adaugare("Tintar","insecta",4,112);  
  return 0;
}
