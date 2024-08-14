/* Sa se implementeze o baza de date care contine urmatoarele tipuri de produse:
     - stick USB: interfata (A sau C), capacitate
     - baterie: voltaj
Fiecare produs va avea asociate un pret, stoc si un cod unic. Operatiile vor fi:
     - introducere - introduce un nou produs, inclusiv codul sau. Daca codul exista deja, se incrementeaza stocul, altfel se considera stoc=1
     - listare - se listeaza doar produsele existente pe stoc
     - stergere - se da un cod si se decrementeaza stocul. Produsele cu stoc 0 raman in baza de date. Daca deja este 0, se emite mesaj de atentionare. */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

enum interfata{A,C,};

struct USB
{
  enum interfata interfata_0;
  float capacitate;
};

union produss
{
  struct USB usb_stick;
  float voltaj_baterie;
};

struct produs
{
  uint8_t auxiliar; // 0 --- baterie;   1 --- USB
  union produss produs_0;
  float pret;
  uint32_t stoc;
  char cod[20];
};

uint8_t search(char *cod_cautat,struct produs *tablou, uint8_t *dimension)
{
  uint8_t i = 0;
  for (i = 0; i<(*dimension); i++)
    if (strcmp(cod_cautat,(tablou+i)->cod) == 0)
      {
	(tablou+i)->stoc++;
	return 1;
      }
  return 0;
}

void introducere(struct produs *produs_f,uint8_t *size)
{
  struct produs produs_temporar;
  getchar(); uint8_t x = 0;
  printf("Introducem baterie sau USB?\n");
  char string[10], codd[20];
  if (fgets(string,10,stdin) == NULL)
    {
      printf("eroare la fgets\n");
      return;
    }
  string[strcspn(string,"\n")] = '\0';
  if (strcmp(string,"USB") == 0)
    {
      produs_temporar.auxiliar = 1;
      printf("Ce interfata are stickul? (0 - A; 1 - C)\n");
      scanf("%hhd",&x);
      switch(x)
	{
	case 0:
	  {
	    produs_temporar.produs_0.usb_stick.interfata_0 = A;
	    break;
	  }
	case 1:
	  {
	    produs_temporar.produs_0.usb_stick.interfata_0 = C;
	    break;
	  }
	default:
	  {
	    printf("Ati introdus o varianta invalida\n");
	    return;
	  }
	}
      printf("Ce capacitate are stickul? (in MB)\n");
      scanf("%f",&produs_temporar.produs_0.usb_stick.capacitate);
      printf("Care e pretul stick-ului?\n");
      scanf("%f",&produs_temporar.pret);
    }
  else if (strcmp(string,"baterie") == 0)
    {
      produs_temporar.auxiliar = 0;
      printf("Care e voltajul bateriei?\n");
      scanf("%f",&produs_temporar.produs_0.voltaj_baterie);
      printf("Ce pret va avea produsul?\n");
      scanf("%f",&produs_temporar.pret);
    }
  else
    {
      printf("Nu ati introdus un produs cunoscut\n");
      return;
    }
  getchar();
  printf("Care e codul produsului?\n");
  if (fgets(codd,20,stdin) == NULL)
    {
      printf("Eroare la fgets\n");
      return;
    }
  codd[strcspn(codd,"\n")] = '\0';
  x = search(codd,produs_f,size);
  if (x == 1)
    printf("Produsul a fost gasit in baza de date si stocul a fost updatat!\n");
  else
    {
      strcpy(produs_temporar.cod,codd);
      produs_temporar.stoc = 1;
      *(produs_f+(*size)) = produs_temporar;
      (*size)++;
      printf("Produsul a fost adaugat in baza de date!\n");
    }
  printf("\n");
}

void listare(struct produs *produs_f,uint8_t *size)
{
  printf("\n");
  uint8_t i = 0;
  for (i = 0; i<*size; i++)
    if ((produs_f+i)->stoc > 0)
      {
	if ((produs_f+i)->auxiliar == 0) //baterie
	  {
	    printf ("Baterie cu %.2f volatj\n",(produs_f+i)->produs_0.voltaj_baterie);
	    printf("Pretul de %.2f\n",(produs_f+i)->pret);
	    printf("%u in stoc\n",(produs_f+i)->stoc);
	    printf("Are codul %s\n",(produs_f+i)->cod);
	  }
	else //USB
	  {
	    printf ("USB cu interfata ");
	    switch((produs_f+i)->produs_0.usb_stick.interfata_0)
	      {
	      case 0:
		{
		  printf("A\n");
		  break;
		}
	      case 1:
		{
		  printf("C\n");
		  break;
		}
	      default:
		{
		  printf("Eroare\n");
		  break;
		}
	      }
	    printf ("Are capacitatea de %.2f MB\n",(produs_f+i)->produs_0.usb_stick.capacitate);
	    printf("Pretul de %.2f\n",(produs_f+i)->pret);
	    printf("%u in stoc\n",(produs_f+i)->stoc);
	    printf("Are codul %s\n",(produs_f+i)->cod);
	  }
	printf("\n");
      }
}

void stergere(struct produs *produs_f,uint8_t *size)
{
  getchar();
  printf("Introduceti codul produsului care a fost cumparat:\n");
  char string[20]; uint8_t i = 0, out = 0;
  if (fgets(string,20,stdin) == NULL)
    {
      printf("Eroare la fgets\n");
      return;
    }
  string[strcspn(string,"\n")] = '\0';
  do
    {
      if (strcmp(string,(produs_f+i)->cod) == 0)
	{
	  out = 1;
	  if ((produs_f+i)->stoc > 0)
	    {
	      (produs_f+i)->stoc--;
	      printf("Noul stoc al produsului este %u\n",(produs_f+i)->stoc);
	    }
	  else
	    printf("Stocul produsului este deja 0!!\n");
	}
      i++;
    } while ((i < *size) && (out == 0)); 
}

int main()
{
  struct produs produse[100];
  uint8_t i_size = 0;
  uint8_t n = 0;
  for(;;)
    {
      printf("1 - introducere\n2 - listare\n3 - stergere\n0 - exit\n");
      scanf("%hhd",&n);
      switch (n)
	{
	case 1:
	  {
	    introducere(produse,&i_size);
	    break;
	  }
	case 2:
	  {
	    listare(produse,&i_size);
	    break;
	  }
	case 3:
	  {
	    stergere(produse,&i_size);
	    break;
	  }
	case 0:
	  {
	    return 0;
	  }
	default:
	  {
	    printf("Uknown command\n");
	    break;
	  }
	}
    }
  return 0;
}
