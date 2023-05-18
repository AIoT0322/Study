//2번
// #include<stdio.h>
// int main(void)
// {
// 	int n,q=0,w=0,e=1;
// 	printf("숫자를 입력하시오 : ");
// 	scanf("%d",&n);
// 	int a[n][n]={};
// 	a[0][0]=1;
// 	while(1)
// 	{
// 		while(a[q][w+1]==0&&w<n-1)
// 			a[q][++w]=++e;
// 		while(a[q+1][w]==0&&q<n-1)
// 			a[++q][w]=++e;
// 		while(a[q][w-1]==0&&w>-1)	
// 			a[q][--w]=++e;
// 		while(a[q-1][w]==0&&q>-1)
// 			a[--q][w]=++e;
// 		if(e==n*n)
// 			break;
// 	}
// 	for(int i=0; i<n; i++)
// 	{
// 		for(int z=0; z<n; z++)
// 			printf("%3d ",a[i][z]);
// 		printf("\n");
// 	}
// }

//3번
//0이상 99이하의 난수를 총 5개 생성 %연산자 적절히 활용
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int i;
//     int rand(void);
//     printf("난수의 범위: 0부터 99까지 \n");
//     for(i=0; i<5; i++)
//         printf("난수 출력: %d \n", rand()%99);
//     return 0;
// }


//6번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int a[3];
  int b[3];
  int num=1;
  
  srand(time(NULL));

  for (int i = 0; i < 3; i++)
  {
    a[i]= rand()%10;
    for (int j = 0; j < i; j++)
    {
      if (a[i] == a[j])
      {
        i--;
        break;
      }
    }
  }
  
  while(1)
  {
    int strike=0;
    int ball=0;
  
    printf("세 수를 입력: ");
    scanf("%d %d %d", &b[0], &b[1], &b[2]);
    
    if(a[0]==b[0])  
      strike++;
    else if(a[0]==b[1] || a[0]==b[2])
      ball++;
    
    if(a[1]==b[1])
      strike++;
    else if(a[1]==b[0] || a[1]==b[2])
      ball++;

    if (a[2]==b[2])
      strike++;
    else if(a[2]==b[0] || a[2]==b[1])
      ball++;      

    printf("%d회차 결과: %dstrike! %dball!\n", num++, strike, ball);
  
    if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2])
      break;
  }
  return 0;
}