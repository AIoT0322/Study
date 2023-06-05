#include <stdio.h>
#include <string.h>

//문제1
// int main(void)
// {
//     FILE * fp=fopen("mystory.txt", "wt");
//     if(fp==NULL)
//     {
//         puts("파일오픈 실패!");
//         return -1;
//     }

//     fputs("#이름: 윤성우 \n", fp);
//     fputs("#주민번호: 900208-1012589 \n", fp);
//     fputs("#전화번호: 010-1111-2222 \n", fp);

//     fclose(fp);
//     return 0;
// }

//문제2
// int main(void)
// {
//     FILE * fp=fopen("mystory.txt", "at");
//     if(fp==NULL)
//     {
//         puts("파일오픈 실패!");
//         return -1;
//     }

//     fputs("#즐겨먹는 음식: 짬뽕, 탕수육 \n", fp);
//     fputs("취미: 축구 \n", fp);

//     fclose(fp);
//     return 0;
// }

//문제3
// int main(void)
// {
//     char str[50];
//     FILE * fp=fopen("mystory.txt", "rt");
//     if(fp==NULL)
//     {
//         puts("파일오픈 실패!");
//         return -1;
//     }

//     fgets(str, sizeof(str), fp);
//     printf("%s", str);
//     fgets(str, sizeof(str), fp);
//     printf("%s", str);
//     fgets(str, sizeof(str), fp);
//     printf("%s", str);
//     fgets(str, sizeof(str), fp);
//     printf("%s", str);
//     fgets(str, sizeof(str), fp);
//     printf("%s", str);

//     fclose(fp);
//     return 0;
// }

//24-2 문제
//FILE 구조체의 포인터가 인자로 전달되면 파일의 크기를 바이트단위로 계산하여 반환하는 함수 정의
//ftell함수 이용
//함수가 호출된 이후에도 파일 위치 지시자의 정보가 변경되어서는 안됨
// void SizePrint(FILE * fp)
// {
//     while (1)
//     {
//         int byte=0;
//         fseek(fp, 1, SEEK_SET);
//         byte++;
//         if(fseek(fp, 1, SEEK_SET)==EOF)
//         { 
//             printf("%d \n", byte);
//             break;
//         }
//     }
    
// }

// int main(void)
// {
//     long fpos;
//     FILE * fp=fopen("test.txt", "wt");
//     fputs("1234-", fp);
//     fclose(fp);

//     fp=fopen("test.txt", "rt");
//     fpos=ftell(fp);
//     SizePrint(fp);
//     fseek(fp, fpos, SEEK_SET);
//     fclose(fp);
//     return 0;
// }
long SizePrint(FILE * fp)
{
    long fpos;
    long fsize;
    fpos=ftell(fp); //파일 위치 지시자 정보 백업

    fseek(fp, 0, SEEK_END);
    fsize=ftell(fp);
    fseek(fp, fpos, SEEK_SET); //파일 위치 지시자 정보 복구
    return fsize;
}

int main(void)
{
    char str[100];
    FILE * fp=fopen("test.txt", "rt");
    fgets(str, 100, fp);
    fputs(str, stdout);
    printf("파일의 크기: %ld \n", SizePrint(fp));
    fgets(str, 100, fp);
    fputs(str, stdout);
    printf("파일의 크기: %ld \n", SizePrint(fp));
    fgets(str, 100, fp);
    fputs(str, stdout);
    fclose(fp);
    return 0;
}