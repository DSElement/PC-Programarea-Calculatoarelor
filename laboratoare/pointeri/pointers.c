#include <stdio.h>
/*

int main()
{
    int a=7,b=1;
    int *p=&a;        // pointerul p este initializat cu adresa variabilei a
    int *r=p;           // pointerul r este initializat cu adresa care este stocata in pointerul p
    p=&b;              // pointerului p i se atribuie adresa variabilei b 
    // in acest punct pointerul p va contine adresa variabilei b 
    // iar pointerul r va contine adresa variabilei a
    
    printf("&a=%p\n&b=%p\n",r,p);// in C se poate afisa adresa continuta de un pointer folosind %p (afișarea are loc în hexazecimal)
    return 0;
    } */

/*int main()
{
    int v[10];
    int i,j,n,tmp;
    n=0;                                      // n indica numarul de elemente din vector
    for(;;){                                   // bucla infinita pentru citire
        printf("v[%d]=",n);
        scanf("%d",&v[n]);            // citeste direct in vector, dar nu va considera valoarea decat deca este !=0
        if(v[n]==0)break;               // daca s-a introdus 0, iesire din bucla
        n++;                                  // considera valoarea citita ca fiind introdusa
        }
    for(i=0, j=n-1 ; i<j ; i++, j--){  // inversare valori
        tmp=v[i];
        v[i]=v[j];
        v[j]=tmp;
        }
    for(i=0;i<n;i++){                    // afisare valori
        printf("%d\n",v[i]);
        }
    return 0;
    }*/

/*int main()
{
  int a,b;
  int *p;
  scanf("%d%d",&a,&b);
  if (a>b)
    p = &a;
  else
    p = &b;
  printf("%d\n",*p);
  return 0;
  } */

//Să se scrie un program care citește un număr n<10 iar apoi citește 2 vectori v1 și v2 de câte n elemente de tip int. Pentru citirea elementelor unui vector se folosește o funcție citire(v,n).
//Se va implementa o funcție egal(v1,v2,n), care testează dacă toate elementele din v1 sunt egale cu cele din v2 la poziții corespondente.

/*void citire(int v[],int n)
{
  int i;
  for (i = 0; i < n; i++)
    scanf("%d",&v[i]);
}

int egal(int v1[],int v2[],int n)
{
  int *p1,*p2;
  for (p1 = v1, p2 = v2; p1 < v1 + n; p1++, p2++)
    {
      if (*p1!=*p2)
	return 0;
    }
  return 1;
}


int main()
{
  int n,v1[10],v2[10];
  scanf("%d",&n);
  citire(v1,n);
  citire(v2,n);
  if (egal(v1,v2,n))
    printf("Sunt egale");
  else
    printf("Nu sunt egale");
  return 0;
  } */

//Să se citească de la tastatură două variabile de tip double (se citește cu %lf, nu cu %g!!!) și să se afișeze numele variabilei care se află la adresa cea mai mică de memorie utilizând pointeri.

/*int main()
{
  double  a,b;
  scanf ("%lf%lf",&a,&b);
  double *p1,*p2;
  p1 = &a;
  p2 = &b;
  if (p1<p2)
    printf("%lf",*p1);
  else
    printf("%lf",*p2);
  printf("%p %p\n",&a,&b);
  return 0;
  } */

//Scrieți un program care interschimbă valorile a două variabile de tip întreg utilizând pointeri

/*int main()
{
  int a,b,aux=0;
  int *p1,*p2,*p3;
  scanf("%d%d",&a,&b);
  p1 = &a;
  p2 = &b;
  p3 = &aux;
  *p3 = *p1;
  *p1 = *p2;
  *p2 = *p3;
  printf("%d %d\n",*p1,*p2);
  return 0;
  } */

//Să se afișeze câte elemente negative sunt în vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși. (Fără indecși înseamnă că în cod nu va exista niciun v[i])

/*int main()
{
  int v[] = {7, -5, 4, 3, -9, 2, -8};
  int *p1 = v, s = 0;
  for (p1 = v; p1 < v + 7; p1++)
    if (*p1 < 0)
      s++;
  printf("%d\n",s);
  return 0;
  } */

//Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși.

/* int main()
{
  int v[] = {7, -5, 4, 3, -9, 2, -8};
  int *p1 = v, min = *p1;
  for (p1 = v + 1; p1 < v + 7; p1++)
    if (*p1<min)
      min = *p1;
  printf("%d\n",min);
  return 0;
  }*/

//: Se citește un număr n (n<=10) și apoi n numere întregi. Se cere să se sorteze aceste numere în ordine descrescătoare utilizând pointeri, fără indecși.
//(Inclusiv citirea se va face cu pointeri.)

/*int main()
{
  int n, v[10],*p,s,aux;
  scanf("%d",&n);
  for (p = v; p < v + n; p++)
    scanf("%d",p);
  do
    {
      s = 0;
      for (p = v; p < v + n - 1; p++)
	{
	  if (*p < *(p + 1))
	    {
	      aux = *p;
	      *p = *(p + 1);
	      *(p + 1) = aux;
	      s = 1;
	    }
	    
	}
    }
  while (s == 1);

  for (p = v; p < v + n; p++)
    printf("%d ",*p);
  printf ("\n");
  return 0;
  }*/

//Să se șteargă din vectorul {5, 8, 1, 4, 2, 6, 9} toate elementele pare, păstrând neschimbată ordinea elementelor, după care să se afișeze noul vector. Utilizați pointeri, fără indecși.

/*int main()
{
  int v[] = {5, 8, 1, 4, 2, 6, 9};
  int *p,*pt,n = 7;
  for (p = v; p < v + n; p++)
    {
      if (*p % 2 == 0)
	{
	  for (pt = p; pt < v + n - 1; pt++)
	    *pt = *(pt + 1);
	  n--;
	  p--;
	}
    }
  for (p = v; p < v + n; p++)
    printf("%d ",*p);
  printf("\n");
  return 0;
  } */

//Se dă vectorul {7, -5, 4, 3, -9, 2, -8}. Să se insereze înainte de fiecare valoare din vectorul original negativul ei. Utilizați pointeri, fără indecși.

/*int main()
{
  int v[14] = {7, -5, 4, 3, -9, 2, -8};
  int *p,*pt,n = 7;
  for (p = v; p < v + n; p++)
    {
      for (pt = v + n - 1; pt >= p; pt--)
	{
	  *(pt + 1) = *pt;
	}
      *p = -(*p);
      n++;
      p++;
    }
  for (p = v; p < v + n; p++)
    printf ("%d ",*p);
  printf("\n");
  return 0;
  } */

//Se citesc n<=10 valori întregi. Folosind doar pointeri, fără niciun fel de indexare, să se afișeze toate valorile care au cel puțin un duplicat. (Inclusiv citirea se va face cu pointeri.)

int main()
{
  int n,*p,*pt,v[10];
  scanf("%d",&n);
  for (p = v; p < v + n; p++)
    scanf("%d",p);
  for (p = v; p < v + n - 1; p++)
    for (pt = p+1; pt < v + n; pt++)
      {
	if (*p == *pt)
	  {
	    printf("%d ",*p);
	    break;
	  }
      }
  printf("\n");
  return 0;
}
