//순서도-선택구조 예제08
/*#include <stdio.h>
int main(void)
{
   int a, b;
   printf("a,b를 입력: ");
   scanf("%d %d", &a, &b);

   if(a>b)
     printf("%d", a);
   else
     printf("%d", b);
   return 0;
}*/

//예제09
/*#include <stdio.h>
int main(void)
{
   int a;
   printf("a를 입력: ");
   scanf("%d", &a);

   if(a<0)
     printf("음수 \n");
   else if(a>0)
     printf("양수 \n");
   else
     printf("0");
   return 0;
}*/

//예제10
/*#include <stdio.h>
int main(void)
{
   int a, b, c;
printf("a, b, c를 입력: ");
   scanf("%d %d %d", &a, &b, &c);

   if(a>b)
   {   if(a>c)
         printf("%d", a);
      else
         printf("%d", c);
   }
   else
   {   if(b>c)
         printf("%d", b);
       else
         printf("%d", c);
   }
   return 0;
}*/

//예제11
/*#include <stdio.h>
int main(void)
{
   int max, a;
   printf("max를 입력: ");
   scanf("%d", &max);
   printf("a를 입력: ");
   scanf("%d", &a);

   if(a>max)  
       max=a;

   printf("a를 입력: ");
   scanf("%d", &a);

   if(a>max)
      max=a;
   
   printf("%d", max);
   return 0;
}*/
   


//예제12
/*#include <stdio.h>
int main(void)
{
   int a;
   printf("a를 입력: ");
   scanf("%d", &a);

   if(a%2==0)
      printf("짝수\n");
   else
printf("홀수\n");
   return 0;
}*/

//예제13
/*#include <stdio.h>
int main(void)
{
   int a;
   printf("a를 입력: ");
   scanf("%d", &a);
  
   if(a%3==0)
     printf("3의 배수\n");
   else
     printf("3의 배수 아님\n");
   return 0;
}*/

//예제14
/*#include <stdio.h>
int main(void)
{
   int charge=5000;
   int age;
   printf("나이 입력: ");
   scanf("%d", &age);

   if(age<8)
      printf("0");
   else if(age<60)
      printf("%d", charge);
   else
      printf("%0.f", charge*0.5);
   return 0;
}*/

//예제15
/*#include <stdio.h>
int main(void)
{
   int a;
   printf("a를 입력: ");
   scanf("%d", &a);
 
   if(a%3==0 && a%5==0)
      printf("3과 5의 배수\n");
   else
      printf("3과 5의 배수 아님\n");
   return 0;
}*/

//예제16
/*#include <stdio.h>
int main(void)
{
   int age;
   printf("나이 입력: ");
   scanf("%d", &age);

   if(age<8 || age>=60)
     printf("무료\n");
  else
     printf("5,000원\n");
   return 0;
}*/


