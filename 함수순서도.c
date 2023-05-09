//예제53
#include <stdio.h>
int max(int a, int b)
{
    int m;
    if(a>b)
        m=a;
    else
        m=b;
    return m;
}

int main(void)
{
    int a, b;
    int r;
    printf("a, b 입력: ");
    scanf("%d %d", &a, &b);
    r = max(a, b);
    printf("%d", r);
    return 0;
}

//예제54
#include <stdio.h>
int max(int a, int b, int c)
{
    int m;
    if(a>b)
    {
        if(a>c)
        {
            m=a;
        }
        else
            m=c;
    }
    else
    {
        if(b>c)
        {
            m=b;
        }
        else
            m=c;
    }
    return m;
}

int main(void)
{
    int a, b, c;
    int r;
    printf("a, b, c를 입력: ");
    scanf("%d %d %d", &a, &b, &c);
    r = max(a, b, c);
    printf("%d", r);
    return 0;
}

//예제55
#include <stdio.h>
int aliquot(int a)
{
    for(int i=1; i<=a; i++)
    {
        if(a%i==0)
            printf("%d", i);
    }   
}

int main(void)
{
    for(int i=1; i<=10; i++)
    {
        printf("\n%d : ", i);
        aliquot(i);
    }
    return 0;
}

//예제 56
#include <stdio.h>
int sum(int a)
{
    int r;
    if(a<=1)
    {
        r=1;
    }
    else
    {
        r=a+sum(a-1);
    }
    return r;
}

int main(void)
{
    int n, result;
    printf("n 입력: ");
    scanf("%d", &n);

    result=sum(n);

    printf("%d", result);
    
    return 0;
}

//예제57
#include <stdio.h>
int fibo(int a)
{
    int r;
    if(a<=2)
        r=1;
    else
        r=fibo(a-1)+fibo(a-2);
    
    return r;
}

int main(void)
{
    int n, result;
    printf("n 입력: ");
    scanf("%d", &n);

    result=fibo(n);

    printf("%d", result);

    return 0;
}