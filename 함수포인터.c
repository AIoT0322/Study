#include <stdio.h>
// void SimpleAdder(int n1, int n2)
// {
//     printf("%d + %d = %d \n", n1, n2, n1+n2);
// }

// void ShowString(char * str)
// {
//     printf("%s \n", str);
// }

// int main(void)
// {
//     char * str="Function Pointer";
//     int num1=10, num2=20;

//     void (*fptr1)(int, int)= SimpleAdder;
//     void (*fptr2)(char *)= ShowString;

//     /*함수포인터 변수에 의한 호출*/
//     fptr1(num1, num2);
//     fptr2(str);
//     return 0;
// }

// int WhoIsFirst(int age1, int age2, int(*cmp)(int n1, int n2))
// {
//     return cmp(age1, age2);
// }

// int OlderFirst(int age1, int age2)
// {
//     if(age1>age2)
//         return age1;
//     else if(age1<age2)
//         return age2;
//     else
//         return 0;
// }

// int YoungerFirst(int age1, int age2)
// {
//     if(age1<age2)
//         return age1;
//     else if(age1>age2)
//         return age2;
//     else 
//         return 0;
// }

// int main(void)
// {
//     int age1=20;
//     int age2= 30;
//     int first;

//     printf("입장순서 1 \n");
//     first=WhoIsFirst(age1, age2, OlderFirst);
//     printf("%d세와 %d세 중 %d세가 먼저 입장 \n\n", age1, age2, first);

//     printf("입장순서 2 \n");
//     first=WhoIsFirst(age1, age2, YoungerFirst);
//     printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
//     return 0;
// }

int main(int argc, char*argv[])
{
    int i=0;
    printf("전달된 문자열의 수: %d \n", argc);

    for(i=0; i<argc; i++)
        printf("%d번째 문자열: %s \n", i+1, argv[i]);
    return 0;    
}