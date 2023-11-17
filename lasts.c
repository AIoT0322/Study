#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
#define MAX_BUF 2000
#define MAX_LINE_LENGTH 10000

typedef struct
{
    char name[30];
    char residence[30];
    char id[30];
    char pw[30];
    char pnum[30];
} User;

typedef struct Book
{
    char code[50];       // 등록번호
    char title[200];     // 도서명
    char writer[100];    // 저자
    char publisher[100]; // 출판사
    char year[50];       // 출판연도
    char rent[50];       // 대여정보
    char who[50];        // 대여자
} Book;

void error_handling(char *message);
void Return_Book(int clnt_sock, char *id);
void Rent_Book(int clnt_sock, char *id);
void Search_Book(int clnt_sock);
int Login(int clnt_sd,char*id,char*pw);
int Join(int clnt_sd);
int searchAndSendResults(int clnt_sd);

int main(int argc, char *argv[])
{
    int serv_sd, clnt_sd;
    char buf[BUF_SIZE] = {};
    int menu, flag = 0;
    int loginss;
    Book book;
    char id[30]; // 유저아이디
    char pw[30];
    User user;
    int oic = 0; //종료버튼을 위한 변수
    int loginoic=0;//함수의 종류후 반복문 벗어나기위한 변수

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sd = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sd == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sd, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    if (listen(serv_sd, 5) == -1)
        error_handling("listen() error");

    clnt_adr_sz = sizeof(clnt_adr);

    clnt_sd = accept(serv_sd, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
    if (clnt_sd == -1)
        error_handling("accept() error");
    else
        printf("Connected\n");

    char *mess = "connect sucess !";
    write(clnt_sd, mess, sizeof(mess));

    while (1)
    {
        read(clnt_sd, (int *)&menu, sizeof(menu));
        if (menu == 1) // 로그인
        {

            read(clnt_sd, (char *)&id, sizeof(id));
            read(clnt_sd, (char *)&pw, sizeof(pw));
            //메인에있어야해.

            loginoic=Login(clnt_sd,id,pw); //while문 벗어나기위한 return값 받기.
            if(loginoic==5) 
            break;
        }
        else if (menu == 2) // 회원가입
        {
            Join(clnt_sd);
        }
    }
    read(clnt_sd, (int *)&loginss, sizeof(loginss));
    if (loginss == 3)
    {
        while (1) // 로그인이 성공해야만 들어옴
        {
            read(clnt_sd, &menu, sizeof(menu)); // 클라이언트가 입력한 메뉴번호 받아오기.//인트 4바이트.
            switch (menu)
            {
            case 1: // 도서 조회
                //Search_Book(clnt_sd);
                 searchAndSendResults(clnt_sd);
                break;

            case 2: // 대여 정보 조회
                Rent_Book(clnt_sd, id);
                break;
            case 3:
                Return_Book(clnt_sd, id);
                break;
            case 4:
                oic = 3;
                break;
            }
            if (oic == 3)
                break;
        }
    }

    shutdown(clnt_sd, SHUT_WR);

    close(clnt_sd);

    close(serv_sd);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int Join(int clnt_sd)
{
    User compuser;
    User user;
    int find = 0;
    int loginss = 1;
    FILE *fp_user1;
    FILE *fp_user2;

    read(clnt_sd, (char *)&user.id, sizeof(user.id));

    fp_user1 = fopen("Userinfo.csv", "a");
    if (fp_user1 == NULL)
    {
        puts("파일 오픈 실패");
        return -1;
    }

    fp_user2 = fopen("Userinfo.csv", "r");
    if (fp_user2 == NULL)
    {
        puts("파일 오픈 실패");
        return -1;
    }

    while (fread((void *)&compuser, sizeof(compuser), 1, fp_user2) > 0)
    {
        if (strcmp(compuser.id, user.id) == 0)
        {
            loginss = 2;
            break;
        }
    }
    fclose(fp_user2);

    write(clnt_sd, (int *)&loginss, sizeof(loginss));

    if (loginss == 1)
    {
        read(clnt_sd, (User *)&user, sizeof(user));
        fwrite(&user, sizeof(user), 1, fp_user1);
        printf("%s님 회원가입\n", user.name);
    }
    else if (loginss == 2)
    {
        puts("이미 존재하는 ID입니다.");
    }
    fclose(fp_user1);
    return 0;
}
int Login(int clnt_sd,char *id, char *pw)
{
            int loginss;
            int find = 0;
            User user;

            FILE *fp_user1 = fopen("Userinfo.csv", "r");
            if (fp_user1 == NULL)
            {
                puts("파일 오픈 실패");
                return -1;
            }

            while (fread(&user, sizeof(user), 1, fp_user1) > 0)
            {
                if (strcmp(user.id, id) == 0 && strcmp(user.pw, pw) == 0)
                {
                    find = 1;
                    break;
                }
            }
            fclose(fp_user1);

            if (find == 1)
            {
                printf("%s님 접속\n", user.name);
                loginss = 1;
                write(clnt_sd, (int *)&loginss, sizeof(loginss));
      
            }
            else
            {
                puts("ID와 PW가 일치하지 않습니다.");
                loginss = 2;
                write(clnt_sd, (int *)&loginss, sizeof(loginss));
            }
            return 5;
}
void Search_Book(int clnt_sock)
{
    char word[50];
    char message[MAX_BUF];
    char *line = malloc(500 * sizeof(char));

    int pass = 0;
    int str_len;
    memset(message, 0, sizeof(message));
    memset(word, 0, sizeof(word));
    // 클라이언트에 단어 받기
    str_len = read(clnt_sock, word, sizeof(word));
    // 파일입출력 strstr 도서 검색
    word[str_len] = '\0';

    FILE *file = fopen("Bookinfo.csv", "r");
    while (fgets(line, 500 * sizeof(char), file))
    {
        if (strstr(line, word) != NULL)
        {

            strcat(message, line);
            pass++;
            if (pass == 5)
            {
                break;
            }
        }
    }
    free(line);
    fclose(file);
    if (pass == 0) // 존재하지않을때
    {
        message[0] = '5';
        message[1] = 0;
        write(clnt_sock, message, BUF_SIZE);

        return;
    }

    write(clnt_sock, message, MAX_BUF); // 대여리스트 보내줌

    // 도서정보 클라이언트에게 보내기
}
void Rent_Book(int clnt_sock, char *id)
{
    int str_len;
    char message[MAX_BUF];
    char line[MAX_BUF];
    char linecopy[MAX_BUF];
    char *ptr;
    Book B;

    FILE *file = fopen("Bookinfo.csv", "r"); // 책정보 파일스트림 오픈

    str_len = read(clnt_sock, message, MAX_BUF - 1);

    int found = 0; // 책번호 일치 여부를 확인하는 변수

    while (fgets(line, MAX_BUF, file))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", B.code, B.title, B.writer, B.publisher, B.year, B.rent);

        if (strncmp(B.code, message, strlen(B.code)) == 0)
        {
            found = 1; // 일치하는 책번호가 있음을 표시
            break;     // 반복문 종료
        }
    }
    printf("%s", B.rent);
    if (found==1)
    {
        if (strcmp(B.rent, "대여가능") == 0) // 책번호가 일치할때 bookrent 가 대여가능으로 써져있는지 확인.
        {
            printf("ID:%s 님이 %s 책을 대여하셨습니다 \n", id, B.title);

            FILE *filewrite = fopen("abc.csv", "w"); // 대여가능을 >대여중으로 바꿔서 저장하는 파일.
            fseek(file, 0, SEEK_SET);                // 파일지시자 처음위치로. 처음부터 루프 돌기위해서.

            while (fgets(linecopy, MAX_BUF, file)) // 대여가능 >대여중으로 바꾸는 루프.
            {

                sscanf(linecopy, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", B.code, B.title, B.writer, B.publisher, B.year, B.rent);
                if (strncmp(B.code, message, strlen(B.code)) == 0) // 번호가 같을때.
                {
                    ptr = strstr(linecopy, "대여가능"); // linecopy에서 '대여가능' 글자 바로앞의 포인터를 반환.

                    strncpy(ptr, "대여중\n", 13); // 대여가능 > 대여중으로 바꿈.

                    FILE *rentfile = fopen("Rentinfo.csv", "a"); // 대여한책리스트 파일 덧붙여쓰기로생성

                    ptr = strstr(line, "대여가능");

                    char *UserRent = (char *)malloc(50 * sizeof(char));

                    if (UserRent == NULL)
                    {
                        printf("메모리 할당에 실패했습니다.");
                        return;
                    }

                    strcpy(UserRent, "대여중,");
                    strcat(UserRent, id);
                    strcat(UserRent, "\n");
                    strncpy(ptr, UserRent, 50);

                    free(UserRent);        // 할당된 메모리 해제
                    fputs(line, rentfile); // 대여리스트 파일에 넣기.
                    fclose(rentfile);      // 파일스트림 닫기
                }

                fputs(linecopy, filewrite); // abc.csv에 넣기.
            }

            fclose(file);      // 책정보 닫아.
            fclose(filewrite); // 복사된 파일 종료

            if (-1 == remove("Bookinfo.csv"))
                printf("삭제 실패 \n");

            if (-1 == rename("abc.csv", "Bookinfo.csv"))
                printf("변경 실패 \n");

            // 원본파일삭제하고 복사된파일 이름 변경해야함.

            strcpy(message, "대여가 완료되었습니다");
        }
        else
        {
            strcpy(message, "대여가 불가능합니다");
        }
    }
    else
    {
        strcpy(message, "등록되지 않은 책 번호입니다.");
    }

    write(clnt_sock, message, strlen(message));
}
int searchAndSendResults(int clnt_sd)
{
    char ans[MAX_BUF] = "";
    // 검색어 수신
    recv(clnt_sd, ans, sizeof(ans), 0);
    printf("검색할 단어: %s\n", ans);

    // CSV 파일에서 검색 결과 추출
    FILE *fp = fopen("Bookinfo.csv", "r");
    if (fp == NULL)
    {
        perror("Opening CSV file failed");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH] = "";
    char result[MAX_LINE_LENGTH] = "";
    int resultCount = 0;


    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, ans) != NULL)
        {
            strcat(result, line); //행을 복사
            resultCount++;

            if (resultCount >= 10)
            {
                break; // 상위 10개 결과만 추출
            }
        }
    }
    if(resultCount==0)
    {
        strcpy(result,"검색하신 책이 존재하지않습니다.");
    }

    fclose(fp);

    // 결과 전송
    send(clnt_sd, result, strlen(result), 0);

    // 변수 초기화


    return 0;
}
void Return_Book(int clnt_sock, char *id)
{

    FILE *file = fopen("Bookinfo.csv", "r");         // 책정보 파일스트림 오픈
    FILE *rentfileread = fopen("Rentinfo.csv", "r"); // 렌트정보 읽기 오픈.
    char message[MAX_BUF];
    char line[MAX_BUF];
    char linecopy[MAX_BUF];
    char *ptr;
    Book B;
    int Found = 0;
    int str_len;
    char Booknum[MAX_BUF];

    int pass = 0;

    memset(message, 0, sizeof(message)); // 메세지 배열 초기화.

    while (fgets(line, MAX_BUF, rentfileread) != NULL) // 메세지에 line이 덧붙이기
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", B.code, B.title, B.writer, B.publisher, B.year, B.rent, B.who);
        if (strcmp(B.who, id) == 0)
        {
            strcat(message, line);
            pass++;
        }
    }

    if (pass == 0) // 존재하지않을때
    {
        message[0] = '5';
        message[1] = 0;
        write(clnt_sock, message, BUF_SIZE);
        return;
    }
    write(clnt_sock, message, strlen(message)); // 대여리스트 보내줌

    memset(message, 0, sizeof(message)); // 메세지 배열 초기화.

    str_len = read(clnt_sock, message, MAX_BUF - 1); // 등록번호를 받음

    message[str_len] = '\0';

    strcpy(Booknum, message);

    printf("받은 등록번호는 %s", message);

    fseek(rentfileread, 0, SEEK_SET); // 파일지시자 처음위치로. 처음부터 루프 돌기위해서.
    fseek(file, 0, SEEK_SET);

    while (fgets(line, MAX_BUF, rentfileread)) // 렌트파일 읽어오고
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", B.code, B.title, B.writer, B.publisher, B.year, B.rent, B.who);
        if (strcmp(B.who, id) == 0) // 대여자 아이디가같고
        {

            if (strncmp(B.code, message, strlen(B.code)) == 0) // 받은등록번호와같을때
            {

                Found = 1;
            }
        }
    }

    if (Found)
    {
        FILE *filewrite = fopen("abc.csv", "w"); // 대여중을 >대여가능으로 바꿔서 저장하는 파일.

        while (fgets(linecopy, MAX_BUF, file)) // 대여중 >대여가능으로 바꾸는 루프.
        {

            sscanf(linecopy, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", B.code, B.title, B.writer, B.publisher, B.year, B.rent);
            if (strncmp(B.code, message, strlen(B.code)) == 0) // 번호가 같을때.
            {

                ptr = strstr(linecopy, "대여중"); // linecopy에서 '대여중' 글자 바로앞의 포인터를 반환.

                strncpy(ptr, "대여가능\n", 15); // 대여중 > 대여가능으로 바꿈.
            }

            fputs(linecopy, filewrite); // abc.csv에 넣기.
        }
        fclose(filewrite);
    }
    else
    {
        strcpy(message, "등록번호를 잘못 입력하셧습니다. \n");
        write(clnt_sock, message, strlen(message));

        return;
    }

    // 대여리스트에있는 한줄을 삭제시켜야한다.
    FILE *rentfilewrite = fopen("fakerent.csv", "w");
    // 대여리스트 (fakerent.scv 파일스트림 w로 생성.)

    fseek(rentfileread, 0, SEEK_SET); // rentfileread 파일지시자 초기화

    while (fgets(linecopy, MAX_BUF, rentfileread)) //
    {

        sscanf(linecopy, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", B.code, B.title, B.writer, B.publisher, B.year, B.rent, B.who);

        if (strncmp(B.code, Booknum, strlen(B.code)) != 0)
        {

            fputs(linecopy, rentfilewrite);
        }
    }
    // 번호가같으면 복사하지말고 다르면 복사하게끔로직짬.
    fclose(rentfilewrite);
    // fakerent 파일스트림 닫음.
    memset(message, 0, sizeof(message)); // 메세지 배열 초기화.

    strcpy(message, "입력하신 등록번호의 책이 반납되었습니다. \n");

    fclose(file);
    fclose(rentfileread);
    // 원본 삭제시키고
    if (-1 == remove("Bookinfo.csv"))
        printf("삭제 실패 \n");

    if (-1 == rename("abc.csv", "Bookinfo.csv"))
        printf("변경 실패 \n");
    if (-1 == remove("Rentinfo.csv"))
        printf("삭제 실패 \n");

    if (-1 == rename("fakerent.csv", "Rentinfo.csv"))
        printf("변경 실패 \n");
    // Bookinfo.csv / Rentinfo.csv 이름변경

    write(clnt_sock, message, strlen(message));
}