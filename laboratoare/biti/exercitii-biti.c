#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void showBits(unsigned long int a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%lu",(a>>i)&1);
    printf("\n");
}


//Se citește de la tastatură un număr fără semn. Să se seteze biții săi cu indecșii 0,2,3, să se reseteze
//biții cu indecșii 1,5,6 și să se complementeze biții cu indecșii 4,7. Se vor afișa în binar atât numărul inițial cât și cel final.

/* #include <stdio.h>
#include <stdint.h>

void showBits(unsigned a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}


unsigned int procedure(unsigned int b)
{
  uint16_t i = 0; unsigned int x = 0;
  uint8_t mask = 1;
  for (i = 0; i < sizeof(b)*8; i++)
    {
      switch (i)
	{
	case 0:
	case 2:
	case 3:
	  x = x | (mask << i);
	  break;
	case 1:
	case 5:
	case 6:
	  x = x & ~(mask << i);
	  break;
	case 4:
	case 7:
	  x = x ^ (mask << i);
	  break;
	}
    }
  for (i = 0; i < 7; i++)
    {
      b = b & ~(1 << i);
    }
  x = x | b;
  return x;
  }


int main()
{
  unsigned int a = 0;
  scanf ("%ud",&a);
  //a = 0;
  showBits(a);
  showBits(procedure(a));
  return 0;
  } */

/*
#include <stdio.h>
#include <stdint.h>


void print_bit_16(uint8_t nr)
{
  uint8_t mask = 0x80; // 0b1000000000000000
  uint8_t i = 0;
  for (i = 0; i < 8; i++)
    {
      if ((nr & mask) == 0)
	{
	  printf ("0");
	}
      else
	{
	  printf ("1");
	}
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}


int main()
{
  char c = 0;
  uint8_t a = 0,b = 0;
  scanf ("%hhu%hhu",&a,&b);
  a = a << 4;
  c = c | a;
  c = c | b;
  print_bit_16(c);
  return 0;
} */


//Se citește o valoare de tip int. Se cere să se afișeze valoarea bitului de semn. Nu se cunoaște a priori dimensiunea tipului de date int.


/* #include <stdio.h>

int main()
{
  signed int n;
  scanf ("%d",&n);
  if ((n & (1 << (sizeof(n)*8-1))) == 0)
    printf ("0");
  else
    printf ("1"); 
  return 0;
  } */


//Se citește o valoare. Să se afișeze suma primilor săi 4 biți LSB (cei mai din dreapta)

/* int main()
{
  unsigned int a = 0;
  uint8_t suma = 0, i = 0;
  scanf ("%d",&a);
  for (i = 0; i<4; i++)
    {
      if ((a & (1 << i)) == 0)
	;
      else
	suma += 1;
    }
  showBits(a);
  printf ("%hhu\n",suma);
  return 0;
  } */


//Scrieţi o funcție care ia ca parametru un întreg fără semn şi returnează numărul de biţi de 1 din reprezentarea sa.

/* int nrbiti(unsigned int x)
{
  uint16_t i = 0, s = 0;
  for (i = 0; i < sizeof(x)*8-1; i++)
    {
      if ((x & (1 << i)) != 0)
	s++;
    }
  return s;
}

int main()
{
  unsigned int a =325465;
  showBits(a);
  printf ("%hhu\n",nrbiti(a));
  return 0;
  } */

//Un nibble este un grup de 4 biti. Să se scrie un program care primește un număr fără semn n și această funcție
//a) returnează valoarea acestui număr cu ordinea inversă a nibble-urilor
//b) returnează valoarea acestui număr cu biții din fiecare nibble în ordine inversă


/*unsigned inversa(unsigned x)
{
  unsigned mask = 0;
  uint8_t i = 0; 

  while (x != 0)
    {
      for (i = 0; i<4; i++)
	{
	  if ((x & (1 << i)) != 0)
	    mask = mask | (1 << i);
	}
      x = x >> 4;
      if (x!=0)
	mask = mask << 4;
    }
  return mask;
}

unsigned efectivinversa(unsigned x)
{
  unsigned mask = 0;
  uint8_t i = 0,j = 3; 

  while (x != 0)
    {
      for (i = 0; i<4; i++)
	{
	  if ((x & (1 << i)) != 0)
	    mask = mask | (1 << j);
	  j--;
	}
      x = x >> 4;
      if (x!=0)
	mask = mask << 4;
      j = 3;
    }
  return mask;
}


int main()
{
  unsigned a = 0;
  scanf ("%u",&a);
  showBits(a);
  showBits(inversa(a));
  showBits(efectivinversa(a));
  return 0;
  } */

//Să se scrie o funcție care ia un număr fără semn n și returnează numărul de segmente de biți consecutivi egali. Exemplu: 000100 are 3 segmente: 000, 1, 00, deci programul va returna 3


/* int segmente(unsigned x)
{
  uint8_t i = 0,inc = 0,dec = 1;
  bool b = false;
  for (i = 0; i< sizeof(x)*8; i++)
    {
      if (((x & (1 << i)) != 0) && ((!b) || (dec != 0)))
	{
	b = true;
	inc++;
	}
      else if (((x & (1 << i)) == 0) && ((b) || (dec != 0)))
	{
	  b = false;
	  inc++;
	}
      if (dec !=0)
	dec = 0;	
    }
  return inc;
}


int main()
{
  unsigned n = 0;
  scanf ("%u",&n);
  showBits (n);
  printf("%d\n",segmente(n));
  return 0;
  } */


/* uint64_t suma(int x, int y)
{
  uint64_t i = 0;
  uint64_t mask1 = 0, mask2 = 0, mask = 0,inc = 0;
  for (i=0;i<sizeof(x)*8;i++)
    {
      mask1 = (x & (1 << i));
      mask2 = (y & (1 << i));
      if (((mask1 ^ mask2) != 0) && (inc == 0))
	mask = mask | (1 << i);
      else if (((mask1 ^ mask2) != 0) && (inc == 1))
	{
	  mask = mask & ~(1 << i);
	  inc = 1;
	}
      else if (((mask1) != 0) && ((mask1 ^ mask2) == 0))
	{
	  if (inc == 1)
	    mask = mask | (1 << i);
	  else
	    mask = mask & ~(1 << i);
	  inc = 1;
	}
      else if (((mask1 ^ mask2) == 0) && (mask1 == 0))
	if (inc == 1)
	  {
	    mask = mask | (1 << i);
	    inc = 0;
	  }
    }
  return mask;
}

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  showBits(a);
  showBits(b);
  showBits(suma(a,b));
  printf("%lu\n",suma(a,b));
  return 0;
  } */

//Să se scrie o funcție care primește ca argument un număr pe 32 de biți fără semn (nr), un număr pe 8 biți fără semn (n) și o poziție (p).
//Funcția va returna numărul (nr) în care octetul de pe poziția p va fi inlocuit cu numărul n. Octeții se numără se la dreapta (cel mai puțin semnificativ, poziția 0) spre stanga
//exemplu: nr = 0011 0110 0101 1011 0011 0110 0101 1011 = 911.947.35510 , n = 1110 1111 = 23910, p = 2 -> rezultat: 0010 0110 1110 1111 0011 0110 0101 1011


/* uint32_t inlocuire(uint32_t numar,uint8_t x,uint8_t p)
{
  uint32_t mask = 0; uint8_t i=0; 
  mask = mask | x;
  mask = mask << (p*8);
  for (i = p*8-1; i<p*8+7; i++)
      numar = numar & ~(1 << i);
  numar = numar | mask;
  return numar;
}

int main()
{
  uint32_t nr; uint8_t nr0 = 0,p = 0;
  scanf("%u%hhu%hhu",&nr,&nr0,&p);
  showBits(inlocuire(nr,nr0,p));
  printf ("%u\n",inlocuire(nr,nr0,p));
  return 0;
  } */

/*int main()
{
  uint8_t i = 0,inc = 0;
  uint64_t a = 0;
  scanf ("%lu",&a);
  showBits(a);
  for (i=0; i<64; i++)
    {
      if ((a & (1 << i)) != 0)
	inc++;
    }
  if ((inc % 2) == 0)
    printf("par");
  if ((inc % 2) != 0)
    printf("impar");
  return 0;
  } */


/*void print_bit_16(uint16_t nr)
{
  uint16_t mask = 0x8000; // 0b1000000000000000
  uint8_t i = 0;
  for (i = 0; i < 16; i++)
    {
      if ((nr & mask) == 0)
	{
	  printf ("0");
	}
      else
	{
	  printf ("1");
	}
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}


uint16_t creeaza(uint8_t x, uint8_t y)
{
  uint16_t mask=0;
  mask = mask | x;
  mask = mask << 8;
  mask = mask | y;
  return mask;
}


int main()
{
  uint8_t a=0,b=0;
  scanf("%hhu%hhu",&a,&b);
  print_bit_16(a);
  print_bit_16(b);
  print_bit_16(creeaza(a,b));
  return 0;
  } */

int main()
{
  int32_t media = 0, min = 0, nr, inc = 0;;
  bool b = true;
  uint64_t x = 0, mask = 0;
  while (1)
    {
      scanf("%d",&nr);
      if (nr == 0)
	break;
      media += nr;
      if (b)
	min = nr;
      else
	if (nr < min)
	  min = nr;
      b = false;
      inc++;
    }
  media = media / inc;
  mask = mask | media;
  mask = mask << (sizeof(mask)*8-sizeof(media)*8);
  x = x | mask;
  x = x | min;
  showBits(x);
  return 0;
}


