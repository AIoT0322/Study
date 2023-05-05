//90도 돌리기
#include <stdio.h>
int main(void)
{
    int arr[5][5]={
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20},
                {21, 22, 23, 24, 25}
    };
    int arr90[5][5];
    // 4,0 -> 0,0  3,0 -> 0,1  2,0-> 0,2  1,0 -> 0,3  0,0-> 0,4
    // (4,1)->(1,0) (3,1)->(1,1) (2,1)->(1,2) (1,1)->(1,3) (0,1)->(1,4)
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            arr90[i][j]=arr[4-j][i];
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        { 
            printf("%d ", arr90[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//180도 돌리기
#include <stdio.h>
int main(void)
{
    int arr[5][5]={
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20},
                {21, 22, 23, 24, 25}
    };
    int arr180[5][5];

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            arr180[i][j]=arr[4-i][4-j];
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        { 
            printf("%d ", arr180[i][j]);
        }
        printf("\n");
    }
    return 0;
}    