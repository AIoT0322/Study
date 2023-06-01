#include <stdio.h>
// int main(void)
// {
//     int arr2d[3][3];
//     printf("%p \n", arr2d);
//     printf("%p \n", arr2d[0]);
//     printf("%p \n\n", &arr2d[0][0]);

//     printf("%p \n", arr2d[1]);
//     printf("%p \n\n", &arr2d[1][0]);

//     printf("%p \n", arr2d[2]);
//     printf("%p \n\n", &arr2d[2][0]);

//     printf("sizeof(arr2d): %ld \n", sizeof(arr2d));
//     printf("sizeof(arr2d[0]) : %ld \n", sizeof(arr2d[0]));
//     printf("sizeof(arr2d[1]) : %ld \n", sizeof(arr2d[1]));
//     printf("sizeof(arr2d[2]) : %ld \n", sizeof(arr2d[2]));
//     return 0;
// }

// int main(void)
// {
//     int arr1[3][2];
//     int arr2[2][3];

//     printf("arr1: %p \n", arr1);
//     printf("arr1+1: %p \n", arr1+1);
//     printf("arr1+2: %p \n\n", arr1+2);

//     printf("arr2: %p \n", arr2);
//     printf("arr2+1: %p \n", arr2+1);
//     return 0;
// }

// int main(void)
// {
//     int arr1[2][2]={
//         {1,2}, {3,4}
//     };
//     int arr2[3][2]={
//         {1,2}, {3,4}, {5,6}
//     };
//     int arr3[4][2]={
//         {1,2}, {3,4}, {5,6}, {7,8}
//     };

//     int (*ptr)[2];
//     int i;

//     ptr=arr1;
//     printf("** Show 2,2 arr1 **\n");
//     for(i=0; i<2; i++)
    
//         printf("%d %d \n", ptr[i][0], ptr[i][1]);
    
   
//     ptr=arr2;
//     printf("** Show 3,2 arr2**\n");
//     for(i=0; i<3; i++)
        
//         printf("%d %d \n", ptr[i][0], ptr[i][2]);
    

//     ptr=arr3;
//     printf("** Show 4,2 arr3 **\n");
//     for(i=0; i<4; i++)
    
//         printf("%d %d \n", ptr[i][0], ptr[i][1]);
    
//     return 0;
// }

// int main(void)
// {
//     int a[3][2]={{1,2}, {3,4}, {5,6}};

//     printf("a[0]: %p \n", a[0]);
//     printf("*(a+0): %p \n", *(a+1));
    
//     printf("a[1]: %p \n", a[1]);
//     printf("*(a+1): %p \n", *(a+1));

//     printf("a[2]: %p \n", a[2]);
//     printf("*(a+2): %p \n", *(a+2));

//     printf("%d, %d \n", a[2][1], (*(a+2))[1]);
//     printf("%d, %d \n", a[2][1], *(a[2]+1));
//     printf("%d, %d \n", a[2][1], *(*(a+2)+1));
//     return 0;
// }

#include <stdio.h>
int main(void)
{
  long fpos;
  int i;
  
  /*파일생성*/
  FILE *fp=fopen("text.txt", "wt");
  fputs("1234-", fp);
  fclose(fp);

  /*파일개방*/
  fp=fopen("text.txt", "rt");

  for(i=0; i<4; i++);
  {
    putchar(fgetc(fp));
    fpos=ftell(fp);
    fseek(fp, -1, SEEK_END);
    putchar(fgetc(fp));
    fseek(fp, fpos, SEEK_SET);
  }
  fclose(fp);
    return 0;
}