#include <stdio.h>
#include <string.h>

// struct persom
// {
//     char name[20];
//     char phonenum[20];
//     int age;
// };

// int main(void)
// {
//     struct person man1, man2;
//     strcpy(man1.name, "안성준");
//     strcpy(man1.phonenum, "010-1122-3344");
//     man1.age=23;

//     printf("이름 입력: "); scanf("%s", man2.name);
//     printf("번호 입력: "); scanf("%s", man2.phonenum);
//     printf("나이 입력: "); scanf("%d", &(man2.age));

//     printf("이름 : %s \n", man1.name);
//     printf("번호 : %s \n", man1.phonenum);
//     printf("나이 : %d \n", man1.age);

//     printf("이름: %s \n", man2.name);
//     printf("번호: %s \n", man2.phonenum);
//     printf("나이: %d \n", man2.age);
//     return 0;
// }

// struct employee
// {
//     char name[20];
//     char num[30];
//     int pay;
// };

// int main (void)
// {
//     struct employee person;
//     strcpy(person.name, "이시영");
//     strcpy(person.num, "940211");
//     person.pay=3500;

//     printf("이름: "); scanf("%s", person.name);
//     printf("주민등록번호: "); scanf("%s", person.num);
//     printf("급여: "); scanf("")
    
// }

// struct person
// {
//     char name[20];
//     char phoneNum[20];
//     int age;
// };

// int main (void)
// {
//     struct person arr[3]={
//         {"이승기", "010-1212-0001", 21},
//         {"정지영", "010-1313-0002", 22},
//         {"한지수", "010-1717-0003", 19}
//     };

//     int i;
//     for(i=0; i<3; i++)  
//         printf("%s %s %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);
//     return 0;
// }

// struct point
// {
//     int xpos;
//     int ypos;
// };
 
// int main(void)
// {
//     struct point pos1={1,2};
//     struct point pos2={100, 200};
//     struct point * pptr=&pos1;

//     (*pptr).xpos += 4;
//     (*pptr).ypos +=5;
//     printf("[%d, %d] \n", pptr->xpos, pptr->ypos);

//     pptr=&pos2;
//     pptr->xpos +=1;
//     pptr->ypos +=2;
//     printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);
//     return 0;
// }

struct point
{
    int xpos;
    int ypos;
    struct point * ptr;
};

int main(void)
{
    struct point pos1={1,1};
    struct point pos2={2,2};
    struct point pos3={3,3};
    pos1.ptr= &pos2;
    pos2.ptr= &pos3;
    pos3.ptr= &pos1;

    printf("점의 연결관계... \n");
    printf("[%d, %d]와 [%d, %d] 연결\n", 
        pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
    printf("[%d, %d]와 [%d, %d]연결 \n",
        pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
    printf("[%d, %d]와 [%d, %d]연결 \n",
        pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
    return 0;
}