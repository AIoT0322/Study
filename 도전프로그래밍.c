1번 10개 정수 main함수 내에서 입력 받고 배열 내에 존재하는 홀수만 출력, 짝수만 출력하는 함수를 정의해서 호출
#include <stdio.h>
void Odd(int*num1)
{   
    printf("홀수 출력: ");
    for(int i=0; i<10; i++)
    {
        if(num1[i]%2 != 0)
            printf("%d ", num1[i]);
    }
}

void Even(int*num2)
{
    printf("짝수 출력: ");
    for(int i=0; i<10; i++)
    {
        if(num2[i]%2 == 0)
            printf("%d ", num2[i]);
    }
}

int main(void)
{
    int a[10];
    int input;
    for(int i=0; i<10; i++)
    {
        printf("정수를 입력: \n");
        scanf("%d", &input);
        a[i]=input;
    }
    
    Odd(a);
    printf("\n");
    Even(a);
    printf("\n");

    return 0;
}

//2번 10진수 형태로 정수 하나 입력, 2진수로 변환해서 출력
#include <stdio.h>
int main(void)
{
    int num;
    int a[20]={0, };
    int position=0;

    printf("10진수 정수 하나 입력: ");
    scanf("%d", &num);

    //2로 나머지가 0이 될 때 까지 나누고 나머지 역순으로
    //나머지 값을 배열에 저장 후 역순으로 출력
    

    while(1)
    {
        a[position]=num%2;
        num = num/2;
        position++;
        if(num==0)
            break;    
    }

    for(int i = position-1; i>=0; i--)
        printf("%d", a[i]);

    printf("\n");
    
        return 0;
}

//3번 길이10인배열 선언, 10개 정수 입력받아서 홀수면 배열 앞부터, 짝수면 뒤부터
#include <stdio.h>
int main(void)
{
    int a[10];
    int num;
    int front = 0;
    int rear =  9;

    for(int i=0; i<10; i++)
    {
        printf("정수 입력: ");
        scanf("%d", &num);

        if(num%2!=0)
            a[front++]=num;
    
        else if(num%2==0)
            a[rear--]=num;
    }

    for(int i=0; i<10; i++)
        printf("%d ", a[i]);

    return 0;
}

//4번 sttlen함수 사용 size_t strlen(const char * s);
//영단어가 회문인지 아닌지 판단해서 결과 출력하는 기능의 함수 정의, 이제 적절한 main함수 정의, 대소문자까지 일치해야 인정
#include <stdio.h>
#include <string.h>
void palindrome(char str[])
{//맨앞문자랑 맨끝이랑 비교하고 길이 반 잘라서 돌려
    int i;
    int j;
    int len;

    len = strlen(str);

    for(i=0; i<len/2; i++)
    {
        if(str[i] != str[len-1-i])
            j=1;
    }
    if(j==0)
        printf("회문입니다");
    else
        printf("회문이 아닙니다");
}

int main(void)
{
    char str[100];
    int len = 0;
    printf("영단어를 입력: ");
    scanf("%s", str);

    palindrome(str);

    return 0;
}

//5번
#include <stdio.h>
//배열에 저장되어 있는 요소들은 내림차순으로 정렬하는 함수 정의 이름은 DesSort 
//이 함수를 호출 길이7인 int형 배열 선언 7개 정수 입력받기
//배열을 인자로 전달하면서 DesSort함수 호출, 배열 요소 출력
void DesSort(int arr[])
{
    int temp=0;
    int i;
    int j;
    for(i=0; i<7; i++)
    {
        for(j=i; j<7; j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(void)
{
    int arr[7];
    int temp=0;
    int i; 
    int j;
    for(i=0; i<7; i++)
    {
        printf("정수를 입력: ");
        scanf("%d", &arr[i]);
    }

    DesSort(arr);

    for(j=0; j<7; j++)
    {
        printf("%d", arr[j]);
    }
    return 0;
}


