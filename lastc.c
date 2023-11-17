#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
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
    char who[50];        // 대여기간
} Book;

char getch();

void error_handling(char *message);
void Rent_Book(int sock);
int Login(int sock);
void Return_Book(int sock);
void Search_Book(int sock);
void searchAndPrintResults(int sock);

int main(int argc, char *argv[])
{
    int sock;
    int menu, flag;
    char id[30];
    char pw[30];
    int find = 0;
    int loginss = 0;

    char buf[BUF_SIZE] = {};
    int read_cnt;
    int oic = 0; // 나가기 변수

    FILE *fp_user;
    User user;
    Book book;
    struct sockaddr_in serv_adr;
    if (argc != 3)
    {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connect() error!");
    else
        puts("waiting plz...");

    char mess[100];
    int str_len = read(sock, mess, sizeof(mess));
    mess[str_len] = 0;

    printf("%s\n", mess);
    while (1)
    {

        printf("1.로그인  2.회원가입\n");
        scanf("%d", &menu);
        getchar();
        write(sock, (int *)&menu, sizeof(menu));

        if (menu == 1) // 로그인
        {
            loginss = Login(sock);
            if (loginss == 3)
                break;
        }
        else
        {
            printf("이름: ");
            scanf("%s", user.name);
            printf("주소: ");
            scanf("%s", user.residence);
            printf("연락처: ");
            scanf("%s", user.pnum);
            printf("ID: ");
            scanf("%s", user.id);
            printf("PW: ");
            scanf("%s", user.pw);

            write(sock, (char *)&user.id, sizeof(user.id));
            read(sock, (int *)&loginss, sizeof(loginss));

            if (loginss == 1)
            {
                write(sock, (User *)&user, sizeof(user));
                puts("회원가입 되었습니다.");
            }
            else if (loginss == 2)
            {
                puts("이미 존재하는 ID입니다.");
            }
        }
    }

    if (loginss == 3)
    {
        while (1)
        {
            // system("clear");
            fputs("\n 1. 도서조회  2. 도서대여  3. 도서반납  4. 프로그램 종료 \n", stdout);
            scanf("%d", &menu);
            while (getchar() != '\n')
                continue;

            write(sock, &menu, sizeof(menu)); // 4바이트 인트로 보내.
            switch (menu)
            {
            case 1: // 도서 조회
                //Search_Book(sock);
                // 읽기
                searchAndPrintResults(sock);
                break;

            case 2: // 대여

                Rent_Book(sock);
                // sleep(2);

                break;
            case 3: // 반납

                Return_Book(sock);
                // sleep(2);
                break;
            case 4:

                oic = 3;
                break;
            }
            if (oic == 3)
                break;
        }
    }

    close(sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

char getch()
{
    struct termios oldattr, newattr;
    char ch;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
}
void Search_Book(int sock)
{
    char word[50];
    char message[MAX_BUF];
    int str_len;
    char *token;
    Book B;
    char *delimiter = "\n"; // 구분자 비교를위해
    // 단어 입력
    printf("검색하실 단어를 입력해주세요 : ");
    memset(word, 0, sizeof(word));
    memset(message, 0, sizeof(message));
    fgets(word, sizeof(word), stdin);
    word[strlen(word) - 1] = 0; // 개행을 삭제하고 보내주기.

    // 서버에 보내기
    write(sock, word, sizeof(word));
    // //서버에서 도서정보받기
    str_len = read(sock, message, MAX_BUF);
    message[str_len] = 0;

    if (message[0] == '5')
    {
        printf("검색하신 도서가 존재하지 않습니다 \n");
        return;
    }
    token = strtok(message, delimiter); // 첫 번째 호출
    while (token != NULL)
    {
        sscanf(token, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", B.code, B.title, B.writer, B.publisher, B.year, B.rent);
        printf("등록번호: %s\n", B.code);
        printf("제목: %s\n", B.title);
        printf("저자: %s\n", B.writer);
        printf("출판사: %s\n", B.publisher);
        printf("대여: %s\n\n", B.rent);

        token = strtok(NULL, delimiter); // 다음 호출
    }

    // 출력
}
int Login(int sock)
{
    char id[30];
    char pw[30];
    int loginss = 0;
    int index = 0;

    printf("ID: ");
    scanf("%s", id);
    getchar();
    printf("PW: ");
    while (1)
    {
        char c = getch(); // getch 함수로 키 입력 받음

        if (c == '\n') // Enter 키를 누르면 입력 종료
        {
            break;
        }

        if (c == 127) // 백스페이스 키를 누른 경우
        {
            if (index > 0) // 입력된 문자가 있는 경우에만 처리
            {
                printf("\b \b"); // 커서를 앞으로 이동하여 백스페이스 효과 구현
                index--;
            }
        }
        else // 다른 문자를 입력한 경우
        {
            pw[index] = c;
            printf("*");
            index++;
        }
    }

    pw[index] = '\0'; // 문자열 종료를 위해 널 문자 추가

    printf("\n");
    write(sock, (char *)&id, sizeof(id));
    write(sock, (char *)&pw, sizeof(pw));
    read(sock, (int *)&loginss, sizeof(loginss));
    if (loginss == 1)
    {
        puts("로그인 성공하였습니다.");
        loginss = 3;
        write(sock, (int *)&loginss, sizeof(loginss));
    }
    else if (loginss == 2)
    {
        puts("ID 또는 PW가 일치하지 않습니다.");
    }

    return loginss;
}
void searchAndPrintResults(int sock)
{
    char ans[MAX_BUF] = "";
    char str[MAX_LINE_LENGTH] = "";

    printf("검색할 단어: ");
    fgets(ans, sizeof(ans), stdin);
    ans[strcspn(ans, "\n")] = '\0'; // 개행 문자 제거

    send(sock, ans, strlen(ans), 0);

    recv(sock, str, sizeof(str), 0);
    printf("Search results:\n%s\n", str);


}
void Rent_Book(int sock)
{
    char message[MAX_BUF];
    int str_len;

    fputs("대여하실 도서 등록번호를 입력하시오 :  ", stdout);
    fgets(message, MAX_BUF, stdin);
    write(sock, message, MAX_BUF - 1);      // 책 등록번호 보내주기.
    str_len = read(sock, message, MAX_BUF); // 서버의 대답 잘되었다 안되었다 받기.
    message[str_len] = 0;
    printf("Message from server: %s \n", message);
}
void Return_Book(int sock)
{
    system("clear");
    char message[MAX_BUF];
    int str_len;
    char *token;
    char *delimiter = "\n"; // 구분자 비교를위해
    Book B;
    memset(message, 0, sizeof(message)); // 메세지 배열 초기화.

    printf("\n 대여하신 도서 목록입니다 \n\n");
    str_len = read(sock, message, MAX_BUF);

    message[str_len] = 0;

    if (message[0] == '5')
    {
        printf("대여하신 도서가 존재하지 않습니다 \n");
        return;
    }

    token = strtok(message, delimiter); // 첫 번째 호출
    while (token != NULL)
    {
        sscanf(token, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", B.code, B.title, B.writer, B.publisher, B.year, B.rent, B.who);
        printf("등록번호 : %s\n", B.code); // 각 문장을 출력
        printf("책제목 : %s\n", B.title);  // 각 문장을 출력
        printf("대여자 : %s\n\n", B.who);  // 각 문장을 출력

        token = strtok(NULL, delimiter); // 다음 호출
    }

    printf("반납하실 도서의 등록번호를 입력해주세요(대소문자 구별) : ");
    fgets(message, MAX_BUF, stdin);

    write(sock, message, MAX_BUF - 1);

    memset(message, 0, sizeof(message)); // 메세지 배열 초기화.
    str_len = read(sock, message, MAX_BUF - 1);

    message[str_len] = 0;
    printf("%s \n", message);
}