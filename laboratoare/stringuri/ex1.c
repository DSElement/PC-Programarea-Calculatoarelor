/* Se va citi un n<=10. Se vor citi apoi pe rând n nume. Se cere ca în final să fie afișat numele cel mai lung și lungimea sa */

#include <stdio.h>
#include <string.h>

int main()
{
  int n = 0, i = 0;
  char s[30], s1[30];
  scanf("%d",&n);
  if (n>10)
    {
      printf("Numarul trebuie sa fie mai mic ca 10\n");
      return 0;
    }
  else
    {
      getchar();  //getcharul asta practic ia acel "new line" din buffer, pentru ca altfel el interfereaza cu fgets-ul ce urmeaza
      for (i = 0; i<n; i++)
	{
	  if (fgets(s1,30,stdin) != NULL)
	    {
	      if (strlen(s1) > strlen(s))
		strcpy(s,s1);
	    }
	  else
	    {
	      printf("eroare\n");
	      return 0;
	    }
	}
    }
  s[strcspn(s,"\n")] = '\0';
  printf("%s e cel mai lung sir cu lungimea de %ld caractere\n",s,strlen(s));
  return 0;
}
