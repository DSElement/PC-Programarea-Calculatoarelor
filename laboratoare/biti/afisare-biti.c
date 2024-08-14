#include <stdio.h>
#include <stdint.h>

void showBits(unsigned a)
{
  int i;
  for (i = sizeof(a)*8-1; i>=0; i--)
    printf ("%d",((a >> i) & 1));
  printf ("\n");
}

void scrie(uint16_t n)
{
  uint16_t mask = 1 << 15, i;
  for (i=0; i<16; i++)
    {
      if ((n & mask) == 0)
	printf ("0");
      else
	printf ("1");
      mask = mask >> 1;
      if (((i+1) % 4) == 0)
	printf (" ");
    }
  printf ("\n");
}



int main()
{
  scrie(-1224);
  showBits(-1224);
  return 0;
}
