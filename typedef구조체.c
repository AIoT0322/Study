#include <stdio.h>

// typedef struct point
// {
//     int xpos;
//     int ypos;
// } Point;

// void ShowPosition(Point pos)
// {
//     printf("[%d, %d] \n", pos.xpos, pos.ypos);
// }

// Point GetCurrentPosition(void)
// {
//     Point cen;
//     printf("Input current pos: ");
//     scanf("%d %d", &cen.xpos, &cen.ypos);
//     return cen;
// }

// int main(void)
// {
//     Point curPos=GetCurrentPosition();
//     ShowPosition(curPos);
//     return 0;
// }

// typedef struct person
// {
//     char name[20];
//     char phoneNum[20];
//     int age;
// } Person;

// void ShowPersonInfo(Person man)
// {
//     printf("name: %s \n", man.name);
//     printf("phone: %s \n", man.phoneNum);
//     printf("age: %d \n", man.age);
// }

// Person ReadPersonInfo(void)
// {
//     Person man;
//     printf("name? "); scanf("%s", man.name);
//     printf("phone? "); scanf("%s", man.phoneNum);
//     printf("age? "); scanf("%d", &man.age);
//     return man;
// }

// int main(void)
// {
//     Person man=ReadPersonInfo();
//     ShowPersonInfo(man);
//     return 0;
// }

// typedef struct student
// {
//     char name[20];
//     char stdnum[20];
//     char school[20];
//     char major[20];
//     int year;
// } Student;

// void ShowStudentInfo(Student * sptr)
// {
//     printf("학생 이름: %s \n", sptr->name);
//     printf("학생 고유번호: %s \n", sptr->stdnum);
//     printf("학교 이름: %s \n", sptr->school);
//     printf("선택 전공: %s \n", sptr->major);
//     printf("학년: %d \n", sptr->year);
// }

// void SearchStudent(Student stname, Student * ptr)
// {
//     scanf("학생이름 입력: ", stname);
//     for (int i = 0; i < 7; i++)
//     {
//         if(ptr[i].name==stname)
//         {
//             printf("이름: "); scanf("%s", ptr[i].name);
//             printf("번호: "); scanf("%s", ptr[i].stdnum);
//             printf("학교: "); scanf("%s", ptr[i].school);
//             printf("전공: "); scanf("%s", ptr[i].major);
//             printf("학년: "); scanf("%ls", &ptr[i].year);
//         }
//     }
    
// }

// int main(void)
// {
//     Student arr[7];
//     int i;

//     for(i=0; i<7; i++)
//     {
//         printf("이름: "); scanf("%s", arr[i].name);
//         printf("번호: "); scanf("%s", arr[i].stdnum);
//         printf("학교: "); scanf("%s", arr[i].school);
//         printf("전공: "); scanf("%s", arr[i].major);
//         printf("학년: "); scanf("%ls", &arr[i].year);
//     }

//     for(i=0; i<7; i++)
//         ShowStudentInfo(&arr[i]);

//     SearchStudent(Student name, Student arr);

//     return 0;
// }

typedef enum syllable
{
    Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7 
} Syllable;

void Sound(Syllable sy)
{
    switch(sy)
    {
        case Do:
            puts("도는 하얀 도라지"); return;
        case Re:
            puts("레는 둥근 레코드"); return;
        case Mi:
            puts("미는 파란 미나리"); return;
        case Fa:
            puts("파는 예쁜 파랑새"); return;
        case So:
            puts("솔은 작은 솔방울"); return;
        case La:
            puts("라는 라디오고요~"); return;
        case Ti:
            puts("시는 졸졸 시냇물"); return;    
    }
    puts("다 함께 부르세~ 도레미파 솔라시도 솔 도~ 짠~");
}

int main(void)
{
    Syllable tone;
    for(tone=Do; tone<=Ti; tone+=1)
        Sound(tone);
    return 0;
}
