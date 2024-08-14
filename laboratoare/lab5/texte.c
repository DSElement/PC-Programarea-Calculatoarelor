#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/* int main()
{
  int c=0, wc=0;
  bool b = false;
  while ((c = getchar()) != EOF)
    {
      if ((isalpha (c)) && (!b))
			    b = true;			    
      else if ((isspace(c)) && (b))
				{
				  b = false;
				  wc++;
				}
    }
  printf ("%d\n",wc);
  return 0;
  } */

int main()
{
  int c=0,i=0;
  char temp = '0',temp1 = '0';
  bool b = false;
  while ((c = getchar()) != EOF)
    {
      if ((c != '/') && (c != '*') && ((i == 1 || b == true)))   /* 2 */
			 {
			   i = 0;
			   b = false;
			   if (temp != '0')
			     {			       
			       printf ("%c",temp);
			       temp = '0';
			     }
			 }
      else if ((c == '/') && (!b) && (i == 0))     /* 1 */ 
	{
	  i = 1;
	  b = true;
	  temp = '/';
	}
      else if ((c == '/') && (b) && (i == 1) && (temp == '/'))     /* 3 */
  	{
	  while ((c = getchar()) != '\n')
	    ;
	  b = false; i = 0; temp = '0';
	}
      
      else if ((c == '*') && (b) && (i == 1) && (temp == '/'))     /* 4 */
	{
	  while (1)
	    {
	      temp1 = c;
	      c = getchar();
	      if ((c == '/') && (temp1 == '*'))		
		  break;		
	    }
	  b = false;
	  i = 0;
	  temp = '0';
	  temp1 = '0';
	  continue;
  	}
      /*  else if ((c == '/') && (temp1 == '*') && (b) && (i == 1))
	{
	  b = false;
	  i = 0;
	  temp1 = '0';
	  continue;
	  } */

      
      if (temp != '/')
	putchar(c);
	       
    }	       
   return 0;
}
