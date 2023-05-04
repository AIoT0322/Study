//과제 문제3-1
//공백 4 3 2 1 0
//별   1 3 5 7 9
/*#include <stdio.h>
int main(void)
{
   int i,j,k;
   
   for(i=0; i<4; i++)
     {
        for(j=i; j<4; j++)
           printf(" ");
        for(k=0; k<2*i+1; k++)
           printf("*");
           printf("\n");
     }
    return 0;
}*/

//문제 3-2
//공백 0 1 2 3 4
//별   9 7 5 3 1
/*#include <stdio.h>
int main(void)
{
   int i, j, k;
   
   for(i=0; i<5; i++)
   {
	for(j=0; j<i; j++) 
           printf(" ");
        for(k=8; k>i*2-1; k--)
           printf("*");
      printf("\n");
   }
   return 0;
}*/
  
//문제 3-3
/*#include <stdio.h>
int main(void)
{
   int i,j,k;
   
   for(i=0; i<4; i++)
    {
        for(j=i; j<4; j++)
           printf(" ");
        for(k=0; k<2*i+1; k++)
           printf("*");
           printf("\n");
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<i; j++) 
           printf(" ");
        for(k=8; k>i*2-1; k--)
           printf("*");
           printf("\n");
    }
    return 0;
}*/

//문제 3-4
/*#include <stdio.h>
int main(void)
{
   int i, j, k;
   
   for(i=0; i<7; i++)
   {
        for(j=0; j<i; j++) 
           printf(" ");
        for(k=12; k>i*2-1; k--)
           printf("*");
      printf("\n");
   }
   for(i=0; i<7; i++)
   {
        for(j=i; j<6; j++)
           printf(" ");
        for(k=0; k<2*i+1; k++)
           printf("*");
           printf("\n");
   }
   return 0;
}*/

//문제 3-5
//공백 9 8 7 6 5 4 3 2 1 0
// 별  1 2 3 4 5 6 7 8 9 10
#include <stdio.h>
int main(void)
{
   int i, j, k, l, m;

   for(i=0; i<10; i++)
   {
      for(j=0; j<=i; j++)
         printf("*");  
      for(k=10; k>i; k--)
         printf(" ");
      for(l=10; l>i; l--)
         printf("*");
         printf("\n");
   }
   for(i=0; i<10; i++)
   {
      for(j=10; j>i; j--)
         printf(" ");
      for(k=0; k<=i; k++)
         printf("*");
      for(l=0; l<=i; l++)
         printf(" ");
      for(m=10; m>i; m--)
         printf("*");
         printf("\n");
   }
   return 0;
}
   





