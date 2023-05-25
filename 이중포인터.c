// #include <stdio.h>
// int main(void)
// {
//     double num=3.14;
//     double * ptr = &num;
//     double **dptr=&ptr;
//     double * ptr2;

//     printf("%9p %9p \n", ptr, *dptr);
//     printf("%9g %9g \n", num, **dptr);
//     ptr2= *dptr;
//     *ptr2= 10.99;
//     printf("%9g %9g \n", num, **dptr);
//     return 0;
// }

// #include <stdio.h>

// void SwapIntPtr(int **dp1, int **dp2)
// {
//     int *temp=*dp1;
//     *dp1=*dp2;
//     *dp2=temp;
// }

// int main (void)
// {
//     int num1=10, num2=20;
//     int *ptr1, *ptr2;
//     ptr1=&num1, ptr2=&num2;
//     printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

//     SwapIntPtr(&ptr1, &ptr2);
//     printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);
//     return 0;
// }

// int main (void)
// {
// int num1;
// int num2;
// int *p;
// int *q;
// int *r;
// int **pp;

// num1=10;
// num2=20;

// p=&num1;
// q=&num2;
// r=&num1;

// pp=&p;
// *pp=q;
// **pp=1024;
// printf("%d %d ", num1, num2);

// pp=&r;
// **pp=*p*2;

// printf("%d %d ", num1, num2);
// return 0;
// }

// int main(void)
// {
//     int num1=10, num2=20, num3=30;
//     int *ptr1=&num1;
//     int *ptr2= &num2;
//     int *ptr3= &num3;

//     int * ptrArr[]={ptr1, ptr2, ptr3};
//     int ** dptr = ptrArr;

//     printf("%d %d %d \n", *(ptrArr[0]), *(ptrArr[1]), *(ptrArr[2]));

//     printf("%d %d %d \n", *(dptr[0]), *(dptr[1]), *(dptr[2]));
//     return 0;
// }
// void MaxAndMin(int *arr, int **mxPtr, int **mnPtr)
// {
//     int *max, *min;
//     int i;
    
//     max=min=&arr[0];

//     for(i=0; i<5; i++)
//     {
//         if(*max<arr[i]);
//             max=&arr[i];
//         if(*min>arr[i]);
//             min=&arr[i];
//     }
//     *mxPtr=max;
//     *mnPtr=min;
// }

// int main(void)
// {
//     int * maxPtr;
//     int * minPtr;
//     int arr[5];

//     for(int i=0; i<5; i++)
//     {
//         printf("정수 입력: ");
//         scanf("%d", &arr[i]);
//     }

//     MaxAndMin(arr, &maxPtr, &minPtr);
//     printf("최대 : %d, 최소: %d \n", *maxPtr, *minPtr);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// char * ReadUserName(void)
// {
//     char * name = (char *)malloc(sizeof(char)*30);
//     printf("What's your name? ");
//     gets(name);
//     return name;  
// }

// int main(void)
// {
//     char * name1;
//     char * name2;
//     name1=ReadUserName();
//     printf("name1: %s \n", name1);
//     name2=ReadUserName();
//     printf("name2: %s \n", name2);

//     printf("name1: %s \n", name1);
//     printf("name2: %s \n", name2);
//     free(name1);
//     free(name2);
//     return 0;
// }

// #include <stdio.h>

// void main()
// {
	//char c = 'a';
	//printf("%I64d\n", sizeof(c));
	//printf("%c\n", c);

	//int n = 100;
	//printf("%I64d\n", sizeof(n));
	//printf("%d\n", n);

	// char c1 = 'A';
	// char c2 = 'B';
	// printf("%c\n", c1);

	// char* ptr = &c1;
	// printf("         c1 : %c\n",           c1);
	// printf("        ptr : %p\n",          ptr);
	// printf("       *ptr : %c\n",         *ptr);
	// printf("     *(&c1) : %c\n",       *(&c1));
	// printf("       *&c1 : %c\n",         *&c1);
	// printf("        &c1 : %p\n",          &c1);
	// printf(" (char*)&c1 : %p\n",   (char*)&c1);
	// // printf("  (char*)c1 : %p\n",    (char*)c1); //16진수 포인터 형변환
	// printf("  (char*)c1 : %d\n",      (int)c1);
	// printf("*(char*)&c1 : %c\n",  *(char*)&c1);
	// printf("       *&c1 : %c\n",         *&c1);

	//printf("%x\n", (int)&c1);
	//printf("%p\n", &c1);
	//printf("%d\n", (int)&c1);
	//printf("%d\n", (int)sizeof(&c1));
	//printf("%p\n", &c2);
// }

// #include <stdio.h>
// #define NAME  "홍길동"
// #define AGE  24
// #define pRINT_ADDR  puts("주소: 경기도 용인시 \n");

// int main(void)
// {
// 	printf("이름: %s \n", NAME);
// 	printf("나이: %d \n", AGE);
// 	PTINT_ADDR;
// 	return 0;
// }

// #include <stdio.h>
// #define SQUARE(X) X*X

// int main(void)
// {
// 	int num=20;
// 	//정상적 결과 출력
// 	printf("Square of num: %d \n", SQUARE(num));
// 	printf("Square of -5: %d \n", SQUARE(-5));
// 	printf("Squrat of 2.5: %g \n", SQUARE(3+2));

// 	//비정상적 출력
// 	printf("Square of 3+2: %d \n", SQUARE(3+2));
// 	return 0;
// }

// #include <stdio.h>
// #define PI 3.14
// #define PRODUCT(X, Y)  ((X)*(Y))
// #define CIRCLE_AREA(R)  (PRODUCT((R), (R))*PI)

// int main(void)
// {
// 	double rad=2.1;
// 	printf("반지름 %g인 원의 넓이: %g \n", rad, CIRCLE_AREA(rad));
// 	return 0;
// }

// #include <stdio.h>
// #define DIFF_ABS(X, Y)  (  (x)>(y) ? (x)-(y) : (y)-(x) )

// int main(void)
// {
// 	printf("두 값의 차: %d \n", DIFF_ABS(5,7));
// 	printf("두 값의 차: %g \n", DIFF_ABS(1.8, -1.4));
// 	return 0;
// }

// #include <stdio.h>
// //#define ADD 1
// #define MIN 0

// int main(void)
// {
// 	int num1, num2;
// 	printf("두 개의 정수 입력: ");
// 	scanf("%d %d", &num1, &num2);

// 	#ifdef ADD  //ADD가 참이라면
// 		printf("%d + %d = %d \n", num1, num2, num1+num2);
// 	#endif

// 	#ifdef MIN  //MIN이 참이라면
// 		printf("%d - %d = %d", num1, num2, num1-num2);
// 	#endif

// 	return 0;
// }

// #include <stdio.h>
// #define HIT_NUM  7

// int main(void)
// {
// 	#if HIT_NUM==5
// 		puts("매크로 상수 HIT_NUM은 현재 5입니다.");
// 	#elif HIT_NUM==6
// 		putr("매크로 상수 HIT_NUM은 현재 6입니다.");
// 	#elif HIT_NUM==7
// 		puts("매크로 상수 HIT_NUM은 현재 7입니다.");
// 	#else	
// 		putr("매크로 상수 HIT_NUM은 5, 6, 7이 확실히 아닙니다.");
// 	#endif

// 	return 0;
// }

// #include <stdio.h>
// #define STRING_JOB(A, B) #A "의 직업은" #B "입니다."

// int main(void)
// {
// 	printf("%s \n", STRING_JOB(이동춘, 나무꾼));
// 	printf("%s \n", STRING_JOB(한상순, 사냥꾼));
// 	return 0;
// }

// #include <stdio.h>
// //#define STNUM(Y, S, P)  YSP
// //#define STNUM(Y, S, P)  Y  S  P
// #define STNUM(Y, S, P)﻿((Y)*100000+(S)*1000+(P))

// int main(void)
// {
// 	printf("학번: %d \n", STNUM(10,65,175));
// 	printf("학번: %d \n", STNUM(10,65,075));

// 	return 0;
// }

// double Add(double num1, double num2)
// {
// 	return num1+num2;
// }

// double Min(double num1, double num2)
// {
// 	return num1-num2
// }

// double Mul(double num1, double num2)
// {
// 	return num1*num2;
// }

// double Div(double num1, double num2)
// {
// 	return num1/num2;
// }

// double TriangleArea(double base, double height);
// double CircleArea(double rad);

// #include "basicArith.h"

// double TriangleArea(double base, double height)
// {
// 	return Div(Mul(base, height), 2);
// }

// double CircleArea(double rad)
// {
// 	return Mul(Mul(rad, rad), PI);
// }

// #include <stdio.h>
// #include "areaArith.h"
// #include "roundArith.h"

// int main(void)
// {
// 	printf("삼각형 넓이(밑변 4, 높이 2): %g \n", TriangleArea(4, 2));
// 	printf("원 넓이(반지름3): %g \n", CircleArea(3));

// 	printf("직사각형 둘레(밑변 2.5, 높이 5.2): %g \n", RectangleRound(2.5, 5.2));
// 	printf("정사각형 둘에(변의 길이 3): %g \n", SquareRound(3));
// 	return 0;
// }

// typedef struct div
// {
// 	int quotient;
// 	int remainder;
// } Div;

// Div IntDiv(int num1, int num2)
// {
// 	Div dval;
// 	dval.quotient=num1/num2;
// 	dval.remainder=num1%num2;
// 	return dval;
// }

// #include <stdio.h>
// typedef struct div
// {
// 	int quotient;
// 	int remainder;
// } Div;

// extern Div IntDiv(int num1, int num2);

// int main(void)
// {
// 	Div cal=IntDiv(5,2);
// 	printf("몫: %d \n", val.quotient);
// 	printf("나머지:%d \n", val.remainder);
// 	return 0;
// }


