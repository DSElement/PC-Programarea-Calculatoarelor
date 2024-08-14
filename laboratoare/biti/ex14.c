/* Un nibble este un grup de 4 biti. Să se scrie un program care primește un număr fără semn n și această funcție
a) returnează valoarea acestui număr cu ordinea inversă a nibble-urilor
b) returnează valoarea acestui număr cu biții din fiecare nibble în ordine inversă */

#include <stdio.h>
#include <stdint.h>

void printare(unsigned nr)
{
  int8_t i = 0;
  for (i = (sizeof(unsigned)*8)-1; i>=0; i--)
    {
      if (((nr >> i) & 1) == 0)
	printf("0");
      else
	printf("1");
    }
  printf("\n");
}

//1111000011110000
//0000111100001111

unsigned inversa1(unsigned nr)
{
  unsigned mask = 0;
  uint8_t i = 0;
  for (i = 0; i<(sizeof(unsigned)*2); i++)
    {
      mask = mask << 4;
      mask |= (nr & 0xF);
      nr = nr >> 4;
    }
  return mask;
}

//1100 0011 1010 0101
//0011 1100 0101 1010

unsigned inversa2(unsigned nr)
{
  unsigned mask = 0;
  int8_t i = 0, j = 0, aux = 0;

  for (i = (sizeof(unsigned)*2)-1; i>=0; i--)
    {
      aux = 0;
      aux |= (nr >> i*4);
      aux &= 0xF;
      for (j = 0; j<4; j++)
	{
	  mask = mask << 1;
	  mask |= (aux >> j) & 1;
	}
    }
  return mask;
}

int main()
{
  unsigned numar = 0;
  //scanf("%u",&numar);
  numar = 0b10100000111000000010010000011011;
  printf("%lu\n",sizeof(unsigned));
  printare(numar);
  numar = inversa1(numar);
  printare(numar);
  numar = 0b10100000111000000010010000011011;
  numar = inversa2(numar);
  printare(numar);
  return 0;
}
