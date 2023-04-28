#include <stdio.h>
int main(void)
{
   int money;
   int total=0;
   int choice1; 
   char choice2;
   int coke=1200;
   int space=1900;
   int zero=1200;
   int sprite=1100;
   int fanta=900; 
   int pepper=1100;
   int monster=1800;
   int power=1900;
   int nasty=1600;
   int vitamin=2100;
   int minute=1700;
   int coffee=900;
   int ambasa=900;
   int tea=1700;
   int i;   
 
   printf("돈을 넣어주세요 -> ");
   scanf("%d원\n", &money);
         
   printf("1)  콜라             1200원   2)  우주맛콜라  1900원   3)  제로콜라    1200원\n");
   printf("4)  스프라이트       1100원   5)  환타         900원   6)  닥터페퍼    1100원\n");
   printf("7)  몬스터           1800원   8)  파워에이드  1900원   9)  네스티      1600원\n");
   printf("10) 글라소비타민워터 2100원   11) 미닛메이드  1700원   12) 조지아커피   900원\n");
   printf("13) 암바사            900원   14) 마테차      1700원\n");
   
   while(choice2!='S')
   {
      printf("\n메뉴를 선택하세요: ");
      scanf("%d", &choice1);
      printf("S) 계산하기 X) 종료하기\n");
      scanf("%c", &choice2);

      if(choice2=='S')
         continue;
      

      switch(choice1)
      {
         case 1:
           printf("콜라 %d원\n", coke);           
           total+=1200;
           break;
         case 2:
           printf("우주맛 콜라 %d원\n", space);
           total+=1900;
           break;
         case 3:
           printf("제로콜라 %d원\n", zero);
           total+=1200;
           break;
         case 4:
           printf("스프라이트 %d원\n", sprite);
           total+=1100;
           break;
         case 5:
           printf("환타 %d원\n", fanta);
           total+=900;
           break;
         case 6:
           printf("닥터페퍼 %d원\n", pepper);
           total+=1100;
           break;
         case 7:
           printf("몬스터 %d원\n", monster);
           total+=1800;
           break;
         case 8:
           printf("파워에이드 %d원\n", power);
           total+=1900;
           break;
         case 9:
           printf("네스티 %d원\n", nasty); 
           total+=1600;
           break;
         case 10:
           printf("글라소비타민워터 %d원\n", vitamin);
           total+=2100;
           break;
         case 11:
           printf("미닛메이드 %d원\n", minute);
           total+=1700;
           break;
         case 12:
           printf("조지아커피 %d원\n", coffee);
           total+=900;
           break;
         case 13:
           printf("암바사 %d원\n", ambasa);
           total+=900;
           break;
         case 14:
           printf("마테차 %d원\n", tea); 
           total+=1700;
         default:
           printf("잘못 입력하였습니다. 다시 선택하세요!\n");
      }            
       
      if(choice2=='X')
      {
         printf("종료합니다.\n");  
         break;
      }
   }

   if(choice2=='S')
   {
       printf("\n총 %d원입니다.\n", total);   
   }
   if(money<total)
   {
      printf("돈이 부족합니다.\n종료합니다\n");
   }
   return 0;
}  


