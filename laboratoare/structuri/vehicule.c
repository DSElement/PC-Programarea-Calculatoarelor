/*
Se va scrie un program ce contine o baza de date de vehicule, implementata 
printr-un tablou.
Un element de tip vehicul va avea urmatoarele proprietati
vechicul
{
    nr_roti
    tip vehicul { trotineta, bicicleta, automobil, autobuz }
    caracteristici 
          trotineta { electrica ; clasica }
	  bicicleta { nr viteze }
	  automobil { an fabricatie }
	  autobuz { nr locuri }
} 

se vor defini in detaliu structurile de date necesare implementarii unui element de tip vehicul de mai sus
- carateristicile sunt date in functie de tipul de vehicul si nu pot exista in acelasi timp, fiind disjuncte
*/

#include <stdio.h>
#include <stdint.h>

#define SIZE 10

enum tip_vehicul {trotineta,bicicleta,automobil,autobuz,};

enum tip_trotineta {electrica,clasica,};

union caracteristici
{
  enum tip_trotineta tip_trotineta_0;
  uint8_t nr_viteze_bicicleta;
  uint16_t an_fabricatie_automobil;
  uint8_t nr_locuri_autobuz;
};

struct vehicul
{
  uint8_t nr_roti;
  enum tip_vehicul tip_vehicul_0;
  union caracteristici caracteristici_0;
};

void printare(struct vehicul *vehicul_curent)
{
  printf("Numarul de roti: %hhd\n", vehicul_curent->nr_roti);
  printf("Tipul vehiculului: ");
  switch (vehicul_curent->tip_vehicul_0)
    {
    case trotineta:
      {
	printf("Trotineta\n");
	printf("tipul trotinetei: ");
	switch(vehicul_curent->caracteristici_0.tip_trotineta_0)
	  {
	  case electrica:
	    {
	      printf("electrica\n");
	      break;
	    }
	  case clasica:
	    {
	      printf("clasica\n");
	      break;
	    }
	  default:
	    {
	      printf("Uknown\n");
	      break;
	    }
	  }
	break;
      }
    case bicicleta:
      {
	printf("Bicicleta\n");
	printf("numarul de viteze: %hhd\n",vehicul_curent->caracteristici_0.nr_viteze_bicicleta);
	break;
      }
    case automobil:
      {
	printf("Automobil\n");
	printf("Anul de fabricatie: %hd\n",vehicul_curent->caracteristici_0.an_fabricatie_automobil);
	break;
      }
    case autobuz:
      {
	printf("Autobuz\n");
	printf("Numar de locuri: %hhd\n",vehicul_curent->caracteristici_0.nr_locuri_autobuz);
	break;
      }
    default:
      {
	printf("Uknown\n");
	break;
      }
    }
  printf("\n");
}

void printare_tablou(struct vehicul *vehicul,uint8_t size)
{
  uint8_t i = 0;
  for (i = 0; i<size; i++)
    printare(&vehicul[i]);
}

int main()
{
  uint32_t i = 0;
  struct vehicul vehicule[SIZE];

  struct vehicul trotineta_1;
  trotineta_1.nr_roti = 2;
  trotineta_1.tip_vehicul_0 = trotineta;
  trotineta_1.caracteristici_0.tip_trotineta_0 = electrica;
  vehicule[i] = trotineta_1;
  i++;

  struct vehicul bicicleta_1;
  bicicleta_1.nr_roti = 2;
  bicicleta_1.tip_vehicul_0 = bicicleta;
  bicicleta_1.caracteristici_0.nr_viteze_bicicleta = 10;
  vehicule[i] = bicicleta_1;
  i++;

  struct vehicul automobil_1;
  automobil_1.nr_roti = 4;
  automobil_1.tip_vehicul_0 = automobil;
  automobil_1.caracteristici_0.an_fabricatie_automobil = 2014;
  vehicule[i] = automobil_1;
  i++;

  struct vehicul autobuz_1;
  autobuz_1.nr_roti = 12;
  autobuz_1.tip_vehicul_0 = autobuz;
  autobuz_1.caracteristici_0.nr_locuri_autobuz = 50;
  vehicule[i] = autobuz_1;
  i++;

  printare_tablou(vehicule,i);
  
  return 0;
}
