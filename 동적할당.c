#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int maxlen, len, i;
    char * str;
    printf("문자열의 최대 길이 입력: ");
    scanf("%d", &maxlen);

    getchar(); // \n 문자 삭제
    str=(char *)malloc(sizeof(char)*(maxlen+1));

    printf("문자열 입력: ");
    fgets(str, maxlen+1, stdin);
    str[strlen(str)-1]=0; // \n 문자 삭제
    len = strlen(str);

    for(i=len; i>0; i--)
    {
        if(str[i]==' ')
        {
            printf("%s ", &str[i+1]);
            str[i]=0;
        }
    }
    printf("%s", &str[0]);
    free(str);
    return 0;
}


// int main(void)
// {
//     int num=0;
//     int size=5;
//     int * arr = (int *)malloc(sizeof(int)*size);
    
//     while(1)
//     {
//         printf("정수 입력: ");
//         scanf("%d", &arr[num]);
//         if(arr[num]==-1)
//             break;

//         if(size==num+1)
//         {
//             size+=3;
//             arr = (int *)realloc(arr, sizeof(int)*size);
//         }
//         num++;
//     }
//     for(int i=0; i<num; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     free(arr);
//     return 0;
// }