#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1번
// typedef struct
// {
//     char title[30];
//     char writer[20];
//     int page;
// } Library;

// int main(void)
// {
//     Library list[3];
//     for(int i=0; i<3; i++)
//     {
//         printf("제목: ");
//         scanf("%s", list[i].title);
//         printf("저자명: ");
//         scanf("%s", list[i].writer);
//         printf("페이지수: ");
//         scanf("%d", &list[i].page);
//     }

//     for(int i=0; i<3; i++)
//     {
//         printf("%s %s %d\n", list[i].title, list[i].writer, list[i].page);
//     }    

//     return 0;
// }

//2번
// int main(void)
// {
//     Library * list = (Library *)malloc(sizeof(Library)*3);
    
//     for(int i=0; i<3; i++)
//     {
//         printf("제목: ");
//         scanf("%s", list[i].title);
//         printf("저자명: ");
//         scanf("%s", list[i].writer);
//         printf("페이지수: ");
//         scanf("%d", &list[i].page);
//     }

//     for(int i=0; i<3; i++)
//     {
//         printf("%s %s %d\n", list[i].title, list[i].writer, list[i].page);
//     }    
//     free(list);
//     return 0;
// }

//3번
// typedef struct 
// {
//     double num1;
//     double num2;
// }Complexnumber;

// void Add(Complexnumber * com)
// {
//     printf("합의 결과] 실수: %f, 허수: %f\n", com[0].num1+com[1].num1, com[0].num2+com[1].num2);
// }

// void Multi(Complexnumber * com)
// {
//     printf("곱의 결과] 실수: %f, 허수: %f\n", (com[0].num1*com[1].num1)-(com[0].num2*com[1].num2), (com[0].num2*com[1].num1)+(com[0].num1*com[1].num2));
// }

// int main(void)
// {
//     Complexnumber com[2];
//     for(int i=0; i<2; i++)
//     {
//         printf("복소수 입력1[실수 허수]: ");
//         scanf("%lf %lf", &com[i].num1, &com[i].num2);
//     }
//     Add(com);
//     Multi(com);

//     return 0;
// }

//strcmp
//4번
int main(void)
{
    int anum;
    int pnum;
    char a;

    FILE * fp = fopen("txt.txt", "rt");

    if(fp==NULL)
    {
        puts("파일을 생설할 수 없습니다.");
    }
    else
    {
        fscanf(fp, "%s", &a);
        printf("a=%s\n", a);
        int fclose(FILE * stream);
    }
}