//04.25 p.280 예제
// #include <stdio.h>
// int main(void)
// {
//     int num1=100, num2=100;
//     int*pnum;
//     pnum=&num1;
//     (*pnum)+=30;
//     pnum=&num2;
//     (*pnum)-=30;

//     printf("num2:%d, num2: %d \n", num1, num2);
//     return 0;
// }

// 12-1 문제1
// #include <stdio.h>
// int main(void)
// {
//     int num=10;
//     int * ptr1=&num;
//     int * ptr2=ptr1;

//     (*ptr1)++;
//     (*ptr2)++;
//     printf("%d \n", num);
//     return 0;
// }

//12-2 문제2
// #include <stdio.h>
// int main(void)
// {
//     int num1=10;
//     int num2=20;

//     int * ptr1=&num1;
//     int * ptr2=&num2;
//     (*ptr1)+=10;
//     (*ptr2)-=10;
//     ptr1=&num2;
//     ptr2=&num1;
    
//     printf("%d %d\n", *ptr1, *ptr2);
//     return 0;
// }

// p.290 예제
// #include <stdio.h>
// int main(void)
// {
//     int arr[3]={0,1,2};
//     printf("배열의 이름: %p \n", arr);
//     printf("첫 번째 요소: %p \n", &arr[0]);
//     printf("두 번째 요소: %p \n", &arr[1]);
//     printf("세 번째 요소: %p \n", &arr[2]);
    
//     return 0;
// }

// p.292 예제
// #include <stdio.h>
// int main(void)
// {
//     int arr1[3]={1,2,3};
//     double arr2[3]={1.1, 2.2, 3.3};

//     printf("%d %g \n", *arr1, *arr2);
//     *arr1 += 100;
//     *arr2+= 120.5;
//     printf("%d %g \n", arr1[0], arr2[0]);
//     return 0;
// }

// p.295 예제
// #include <stdio.h>
// int main(void)
// {
//     int * ptr1= 0x0010;
//     double * ptr2= 0x0010;
//     printf("%p %p \n", ptr1+1, ptr2+2);
//     printf("%p %p \n", ptr2+1, ptr2+2);

//     printf("%p %p \n", ptr1, ptr2);
//     ptr1++;
//     ptr2++;
//     printf("%p %p \n", ptr1, ptr1);
//     return 0;
// }

// p.297 예제
// #include <stdio.h>
// int main(void)
// {
//     int arr[3]={11, 22, 33};
//     int * ptr =arr;
//     printf("%d %d %d \n", *ptr, *(ptr+1), *(ptr+2));

//     printf("%d ", *ptr); ptr++;
//     printf("%d ", *ptr); ptr++;
//     printf("%d ", *ptr); ptr--;
//     printf("%d ", *ptr); ptr--;
//     printf("%d ", *ptr); printf("\n");
//     return 0;
// }

// 문제 13-1 1번
// #include <stdio.h>
// int main(void)
// {
//     int arr[5]={1, 2, 3, 4, 5};

//     int *ptr=arr;
    
//     *ptr += 2; ptr++;
//     *ptr += 2; ptr++;
//     *ptr += 2; ptr++;
//     *ptr += 2; ptr++;
//     *ptr += 2; 

//     printf("%d %d %d %d %d \n", arr[0], arr[1], arr[2], arr[3], arr[4]);
//     return 0;
// }

// 문제 13-1 2번
// #include <stdio.h>
// int main(void)
// {
//     int arr[5]={1, 2, 3, 4, 5};

//     int *ptr=arr;
    
//     *ptr+=2;
//     *(ptr+1)+=2;
//     *(ptr+2)+=2;
//     *(ptr+3)+=2;
//     *(ptr+4)+=2;

//     printf("%d %d %d %d %d \n", arr[0], arr[1], arr[2], arr[3], arr[4]);
//     return 0;
// }

// 문제 13-1 3번
// #include <stdio.h>
// int main(void)
// {
//     int arr[5]={1, 2, 3, 4, 5};
//     int *ptr = &arr[4];
    
//     *ptr-=1; ptr--;
//     *ptr-=1; ptr--;
//     *ptr-=1; ptr--;
//     *ptr-=1; ptr--;
//     *ptr-=1;

//     printf("%d\n", arr[0]+arr[1]+arr[2]+arr[3]+arr[4]);
//     return 0;
// }

// 문제 13-1 4번
// #include <stdio.h>
// int main(void)
// {
//     int arr[6]={1, 2, 3, 4, 5, 6};
//     int i;
//     int * ptr1 = &arr[0];
//     int * ptr2 = &arr[5];
    
//     for(i=0; i<3; i++)
//         printf("%d\n", *ptr1(i));

//     for(i=0; i<3; i++)
//         printf("%d\n", *ptr2(i));

//     return 0;
// }

// #include <stdio.h>
// int main(void)
// {
//     char * strArr[3]={"Simple", "string", "Array"};
//     printf("%s \n", strArr[0]);
//     printf("%s \n", strArr[1]);
//     printf("%s \n", strArr[2]);
//     return 0; 
// }