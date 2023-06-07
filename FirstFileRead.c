#include <stdio.h>
// int main(void)
// {
//     int ch, i;
//     FILE * fp=fopen("data.txt", "rt");
//     if(fp==NULL)
//     {
//         puts("파일 오픈 실패!");
//         return -1;
//     }
    
//     for(i=0; i<25; i++)
//     {
//         ch=fgetc(fp);
//         printf("%c \n", ch);
//     }
//     fclose(fp);
//     return 0;
// }

// int main(void)
// {
//     FILE * src=fopen("src.txt", "rt");
//     FILE * des=fopen("dst.txt", "wt");
//     int ch;

//     if(src==NULL || des==NULL)
//     {
//         puts("파일오픈 실패");
//         return -1;
//     }
//     while((ch=fgetc(src))!=EOF)
//         fputc(ch, des);
    
//     if(feof(src)!=0)
//         puts("파일 복사 완료");
//     else
//         puts("파일복사 실패");

//     fclose(src);
//     fclose(des);
    
//     return 0;
// }

// int main(void)
// {
//     char name[10];
//     char sex;
//     int age;
     
//     FILE * fp = fopen("friend.txt", "wt");
//     int i;

//     for(i=0; i<3; i++)
//     {
//         printf("이름 성별 나이 순 입력: ");
//         scanf("%s %c %d", name, &sex, &age);
//         getchar();
//         fprintf(fp, "%s %c %d", name, sex, age);
//     }
//     fclose(fp);
//     return 0;
// }

typedef struct fren
{
    char name[10];
    char sex;
    int age;
} Friend;

int main(void)
{
    FILE * fp;
    Friend myfren1;
    Friend myfren2;

    /*** fine writr ***/
    fp=fopen("friend.bin", "wb");
    printf("이름, 성별, 나이 순 입력: ");
    scanf("%s %c %d", myfren1.name, &(myfren1.sex), &(myfren1.age));
    fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
    fclose(fp);

    /***file read***/
    fp=fopen("friend.bin", "rb");
    fread((void*)&myfren2, sizeof(myfren2), 1, fp);
    printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
    fclose(fp);
    return 0;
}