//과제 1번 청소당번뽑기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
   int a, b, c, d;

   srand(time(NULL));
   
   for(;;)  
   {
      a=rand()%16+1;
      b=rand()%16+1;
      c=rand()%16+1;
      d=rand()%16+1;

      if(a!=b && a!=c && a!=d && b!=c && b!=d &&c!=d)
        break;
   }     
   printf("청소당번: %d, %d, %d, %d\n", a, b, c, d);

   return 0;
}


