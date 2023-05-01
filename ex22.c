//과제2번 춘식이키우기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, j, k, l, m, n, o;   
   double weight;
   int love;
   srand(time(NULL));

   for(i=1; i<11; i++)
   {   
       love = i*5;
       weight = (double)(i*0.3)+20;
       printf("[%d회차]\n", i);     
       printf("애정도: %d\n", love);
       printf("몸무게: %.1fkg\n", weight);
      
       j=rand()%2;
          
       if(j==0)
       {
         
           printf("춘식이가 화장실을 갔어요!\n");
           printf("현재 몸무게: %.1fkg\n", weight-0.2);
       }
       
       else 
           printf("현재 몸무게: %.1fkg\n", weight);             
  
       k=rand()%100;
   
       if(k<10)
       {
           printf("춘식이가 병에 걸렸어요!\n밥을 먹지 않아요!\n");
           printf("현재 몸무게: %.1fkg\n", weight-0.8);
                  
           l=rand()%love;

           if(l<love*0.1)
           {
               printf("춘식이의 병이 나았어요!\n");
               continue;
           }   
        
           n=rand()%100;

           if(n<10)
           {
               printf("Game Over");
               break;

           }       
        }      
  
   
   }
   return 0;
}
