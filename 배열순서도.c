//예제36
#include <stdio.h>
int main(void)
{
    int a[10], i;
    for(i=1; i<=10; i++)
    {
        a[i-1]=i;
    }
    for(i=0; i<10; i++)
    {
        printf("%d ", a[i]);

    }
    return 0;
}

// 예제37
#include <stdio.h>
int main(void)
{
    int a[10];
    for(int i=1; i<=10; i++)
    {
        a[i-1]=i*10;
    }
    for(int i=9; i>=0; i--)
    {
        printf("%d ", a[i]);
    }
}

// 예제 38
#include <stdio.h>
int main(void)
{
    int a[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    int temp;
    for(i=0; i<=4; i++)
    {
        temp=a[i];
        a[i]=a[9-i];
        a[9-i]=temp;
        printf("%d ", a[i]);
    }
    return 0;
}

// 예제 39
#include <stdio.h>
int main(void)
{
    int a[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10];
    int i;
    for(i=0; i<=9; i++)
    {
        b[i]=a[9-i];
    }
    for(i=0; i<=9; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}

// 예제 40
#include <stdio.h>
int main(void)
{
    int a[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int temp;
    int i;
    temp=a[0];
    for(i=0; i<=8; i++)
    {
        a[i]=a[i+1];
    }
    a[9]=temp;
    for(i=0; i<=9; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

// 예제41
#include <stdio.h>
int main(void)
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int max=a[0];
    
    for(int i=1; i<=9; i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    printf("%d", max);
    return 0;
}

//예제42
#include <stdio.h>
int main(void)
{
    int a[100]={0, };
    
    for(int i=2; i<=10; i++)
    {
        if(a[i]==0)
        {
            for(int j=i*2; j<=100; j+=i)
            {
                a[j]=1;
            }
        }
    }

    for(int i=2; i<=100; i++)
    {
        if(a[i]==0)
        { 
            printf("%d ", i);
        }
    }
    return 0;
}
