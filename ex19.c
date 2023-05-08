//순서도 반복구조
//예제17
/*#include <stdio.h>
int main(void)
{
   int i=1;
   
   while(i<=10)
   {
       printf("%d ", i);
       i=i+1;
   }

   return 0;
}*/

//예제18
/*#include <stdio.h>
int main(void)
{
   int i;

   for(i=1; i<=10; i++)
       printf("%d ", i);

  return 0;
}*/      

//예제19
/*#include <stdio.h>
int main(void)
{
   int i;

   for(i=10; i>=1; i--)
     printf("%d ", i);

   return 0;
}*/

//예제20
/*#include <stdio.h>
int main(void)
{
   int i;
   int sum=0;

   for(i=1; i<=100; i++)
      sum=sum+i;
   printf("%d \n", sum);

   return 0;
}*/

//예제21 
/*#include <stdio.h>
int main(void)
{
   int i;
   int sum=0;

   for(i=2; i<=100; i+=2)
     sum=sum+i;
   printf("%d", sum);

   return 0;
}*/

//예제22 
/*#include <stdio.h>
int main(void)
{
   int i;
   int sum=0;

   for(i=1; i<=100; i++)
   { 
       if(i%2==0) 
          sum=sum+i;  
   }
   printf("%d", sum);
 
   return 0;
}*/

//예제23 
/*#include <stdio.h>
int main(void)
{
   int a;
   int sum =0;

   for(a=1; a<=100; a++)
   {
        if(a%2==0)
           sum=sum-a;
        else  
           sum=sum+a;   
   }
   printf("%d", sum);
   return 0;
}*/

//예제24
/*#include <stdio.h>
int main(void)
{
   int fact=1;
   int i;
 
   for(i=5; i>=1; i--)
      fact=fact*i;

   printf("%d\n", fact);
   return 0;
}*/

//예제25 
/*#include <stdio.h>
int main(void)
{
   int n,i;
   printf("n을 입력: ");
   scanf("%d", &n);

   for(i=1; i<=n; i++)
   {
      if(n%i==0)
        printf("%d ", i);
   }
   return 0;
}*/

//예제26  
/*#include <stdio.h>
int main(void)
{
   int n1, n2, i;
 
   printf("n1, n2 입력: ");
   scanf("%d %d", &n1, &n2);

   for(i=1; i<=n1; i++)
   {
       if(n1%i==0 && n2%i==0)
          printf("%d ", i);
   }
   return 0;
}*/

//예제27   
/*#include <stdio.h>
int main(void)
{
   int n1, n2, i;
   
   printf("n1, n2를 입력: ");
   scanf("%d %d", &n1, &n2);

   for(i=n1; i>=1; i--)
   {  
      if(n1%i==0 && n2%i==0)
      { 
         printf("%d", i);
         break;
      }  
   }
   return 0;
}*/

//예제28 
/*#include <stdio.h>
int main(void)
{
   int chk=1;
   int n, i;

   printf("n을 입력: ");
   scanf("%d", &n);

   for(i=2; i<=n-1; i++)
   {
       if(n%i==0)
       { 
          chk=0;    
          break;
       }
   }
   if(chk==1)
        printf("소수임");

   else 
        printf("소수아님");
    
   return 0;
}*/
 
//예제29
/*#include <stdio.h>
int main(void)
{
   int a=1;
   int b=1;
   int i;
   printf("%d %d", a, b);

   for(i=3; i<=20; i++)
   {
      int c = a+b;
      printf(" %d ", c);
      a=b;
      b=c;
   }
   return 0;
}*/

//예제30 
/*#include <stdio.h>
int main(void)
{
   int a, max;
   printf("a를 입력: ");
   scanf("%d", &a);

   max=a;

   while(a!=0)
   {
       if(a>max)
          max=a;
     
       printf("a를 입력: ");
       scanf("%d", &a);       
   }
   printf("%d", max);
   return 0;
}*/

//예제31
/*#include<stdio.h>
int main(void)
{
   int i, j;
   for(i=1; i<=5; i++)
   {
       for(j=1; j<=i; j++)
         printf("%d", j);
     printf("\n");
   }
   return 0;
}*/

//예제32
/*#include <stdio.h>
int main(void)
{
   int i, j;
   for(i=1; i<=10; i++)
   {   printf("\n%d:", i);
         for(j=1; j<=i; j++)
         {
             if(i%j==0)
             printf("%d", j);
         }
   }
   return 0;
}*/

//예제33 
/*#include <stdio.h>
int main(void)
{
   int i, j, chk;
   for(i=2; i<=100; i++)
   {
      chk=1;
      for(j=2; j<=i-1; j++)
      {
         if(i%j==0)
         {   chk=0;
             break;
         }  
      }
      if(chk==1)
         printf("%d ", j);
   }
   return 0;
}*/

//예제34
#include <stdio.h>
int main(void)
{
   int n=0;
   int sum=0;
   int i;

   for(i=1; i<=10; i++)
   {
      n=n+i;
      sum=sum+n;
   }
   printf("%d\n", sum);
   return 0;
}

//예제35
/*#include <stdio.h>
int main(void)
{
   int i, j;
   
   for(i=2; i<=9; i++)
   {
       for(j=1; j<=9; j++)
           printf("%d x %d = %d\n", i, j, i*j);
   }
   return 0;
}*/
