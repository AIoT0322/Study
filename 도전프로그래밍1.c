#include <stdio.h>
// 2번
// void Printgugudan(int num1, int num2)
// {
//     if(num1>num2)
//     {
//         for(int i=num2; i<=num1; i++)
//         {
//             for(int j=1; j<10; j++)
//             {
//                 printf("%d x %d = %d\n", i, j, i*j);
//             }
//         }
//     }    
//     if(num1<num2)
//     {
//         for(int i=num1; i<=num2; i++)
//         {
//             for(int j=1; j<10; j++)
//             {
//                 printf("%d x %d = %d\n", i, j, i*j);
//             }
//         }
//     }
// }

// int main (void)
// {
//     int num1, num2;

//     printf("두 개의 숫자 입력: ");
//     scanf("%d %d", &num1, &num2);

//     Printgugudan(num1, num2);

//     return 0;
// }

//3번
// int GCD(int num1, int num2)
// {
//     int gcd;
//     if(num1>num2)
//     {
//         for(int i=1; i<=num2; i++)
//         {
//             if(num1%i==0 && num2%i==0)
//             {
//                 gcd=i;
//             }
//         }
//     }

//     if(num2>num1)
//     {
//         for(int i=1; i<=num1; i++)
//         {
//             if(num1%i==0 && num2%i==0)
//             {
//                 gcd=i;
//             }
//         }
//     }
//     return gcd;
// }

// int main(void)
// {
//     int num1, num2;
//     int num3;
//     printf("두 개의 정수 입력: ");
//     scanf("%d %d", &num1, &num2);
//     num3=GCD(num1, num2);
//     printf("%d", num3);
// }

// 4번
// int main(void)
// {
//     int cream=500;
//     int shrimp=700;
//     int cola=400;

//     printf("현재 당신이 소유하고 있는 금액: 3500\n");
//     for(int i=7; i>0; i--)
//     {
//         for(int j=0; j<6; j++)
//         {
//             for(int k=0; k<9; k++)
//             {
//                 if(cream*i+shrimp*j+cola*k==3500)
//                 {
//                     printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", i, j, k);
//                 }
//             }
//         }
//     }
//     printf("어떻게 구입하시겠습니까?\n");
//     return 0;
// }

//6번
// void Printtime(int sec)
// {
//     int h;
//     int m;
//     int s;
//     h=sec/3600;
//     m=(sec%3600)/60;
//     s=(sec%3600)%60;
//     printf("h: %d, m: %d, s: %d\n", h, m, s);
// }

// int main(void)
// {
//     int sec;
//     printf("초 입력: ");
//     scanf("%d", &sec);

//     Printtime(sec);

//     return 0;
// }

//7번
void NumPrint(int n)
{
    int num;
    for(int i=1; i<; i++)
    {
        if(n>=num)
        {

        }
    }
}

int main(void)
{
    int n;
    printf("상수 n 입력: ");
    scanf("%d", &n);

    NumPrint(n);

    return 0;
}