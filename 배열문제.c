/*문제 11-1 1번
#include <stdio.h>

int max_arr(int arr1[]) 
{	                               
	int max = arr1[0];				   
	for (int i = 0; i < 5; i++) 
    {	                           
		if (max < arr1[i])			   // 새로운 최대값 구하기
			max = arr1[i];		       // max에 새로운 최대값 저장
	}
	return max;	

}
int min_arr(int arr1[])
{
    int min = arr1[0];
    for(int i = 0; i < 5; i++)
    {
        if(min > arr1[i])
            min = arr1[i];
    }
    return min;
}

int main(void)
{
    int arr1[5]={ };
    printf("5개의 정수를 입력하세요: \n");
    scanf("%d %d %d %d %d", &arr1[0], &arr1[1], &arr1[2], &arr1[3], &arr1[4]);

    printf("정수 중 최댓값: %d \n", max_arr(arr1));
    printf("정수 중 최솟값: %d \n", min_arr(arr1));
    printf("정수의 총 합: %d \n", arr1[0]+arr1[1]+arr1[2]+arr1[3]+arr1[4]);
    
    return 0;
}*/

//문제 11-1 2번 
//#include <stdio.h>
// int main(void)
// {
//     char str[10]={"Good time"};

//     printf("%s", str);
    
//     return 0;
// }

//문제 11-2 1번 
//#include <stdio.h>
// int main(void)
// {
//     char str[50];
//     int len=0;
//     printf("하나의 영단어를 입력: \n");
//     scanf("%s", str);
    
//     while(str[len] !='\0')
//         len++;
    
//     printf("길이: %d\n", len);

//     return 0;
// }

//문제11-2 2번
// #include <stdio.h>
// int main(void)
// {
//     char str[50];
//     int len =0, i;
//     char temp;

//     printf("하나의 영단어 입력: \n");
//     scanf("%s", str);

//     while(str[len] != '\0')
//         len++;

//     for(i=0; i<len/2; i++)
//     {
//         temp=str[i];
//         str[i]=str[(len-i)-1];  //뒤의 문자를 앞으로
//         str[(len-i)-1]=temp; //앞의 문자를 뒤로
//     }
//     printf("뒤집힌 영단어: %s \n", str);
       
//     return 0;
// }

//문제 11-2 3번
#include <stdio.h>
int main(void)
{
    char arr[50];
    int len = 0, i;
    char max = 0;
    
    printf("영단어 하나를 입력하세요: \n");
    scanf("%s", arr);
   
    while (arr[len] != '\0')
        len++;
    	   
	for (i = 0; i < len; i++) 
    {	                           
		if (max < arr[i])			   
			max = arr[i];		       
    }

    printf("아스키코드 값이 가장 큰 문자: %c\n", max);
    
    return 0;
}
#include 