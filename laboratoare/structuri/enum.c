#include <stdio.h>

enum My_enum
  {
    Luni,
    Marti,
    Miercuri,
    Joi,
    Vineri,
    Sambata,
    Duminica,
  };

int main()
{
  enum My_enum zi_saptamana;
  int n = 0;
  zi_saptamana = Joi;
  scanf("%d",&n);
  if ((n >= 0) && (n <= 6))
    zi_saptamana = (enum My_enum)n;
  switch (zi_saptamana)
    {
    case Luni:
    case Marti:
    case Miercuri:
    case Joi:
    case Vineri:
      {
	printf("Weekday, %d\n", zi_saptamana);
	break;
      }
    case Sambata:
    case Duminica:
      {
	printf("Weekend, %d\n", zi_saptamana);
	break;
      }
    default:
      {
	printf("Uknown\n");
	break;
      }
    }
  return 0;
}
