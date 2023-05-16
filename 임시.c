#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void RandNum(int * ptr1, int * ptr2)  
{
    srand(time(NULL));
  
    for (int i = 0; i < 10; i++)
    {
        ptr1[i] = ((rand() % 10 + 1) * 2);
        for (int j = 0; j < i; j++)
        {
            if (ptr1[i] == ptr1[j])
            {
                i--;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        ptr2[i] = ((rand() % 10 + 1) * 2);
        for (int j = 0; j < i; j++)
        {
            if (ptr2[i] == ptr2[j])
            {
                i--;
            }
        }
    }
}

void Card1Print(int*ptr1)
{
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", i + 1);
        if (ptr1[i] == 2)
            printf(" 🐵");
        else if (ptr1[i] == 4)
            printf(" 🐶");
        else if (ptr1[i] == 6)
            printf(" 🦊");
        else if (ptr1[i] == 8)
            printf(" 🐯");
        else if (ptr1[i] == 10)
            printf(" 🐱");
        else if (ptr1[i] == 12)
            printf(" 🐷");
        else if (ptr1[i] == 14)
            printf(" 🦝");
        else if (ptr1[i] == 16)
            printf(" 🐼");
        else if (ptr1[i] == 18)
            printf(" 🐻");
        else if (ptr1[i] == 20)
            printf(" 🐸");
    }
}

void BackPrint(int*ptr1)
{
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", i + 1);
        if (ptr1[i] == 3)
            printf(" 🐵");
        else if (ptr1[i] == 5)
            printf(" 🐶");
        else if (ptr1[i] == 7)
            printf(" 🦊");
        else if (ptr1[i] == 9)
            printf(" 🐯");
        else if (ptr1[i] == 11)
            printf(" 🐱");
        else if (ptr1[i] == 13)
            printf(" 🐷");
        else if (ptr1[i] == 15)
            printf(" 🦝");
        else if (ptr1[i] == 17)
            printf(" 🐼");
        else if (ptr1[i] == 19)
            printf(" 🐻");
        else if (ptr1[i] == 21)
            printf(" 🐸");
        else
            printf(" ■ ");
    }
}

void LifePrint(int num)
{
    if (num == 5)
    {
        printf("  목숨 :  ❤️   ❤️   ❤️   ❤️   ❤️  │\n");
    }
    else if (num == 4)
    {
        printf("  목숨 :  ❤️   ❤️   ❤️   ❤️      │\n");
    }
    else if (num == 3)
    {
        printf("  목숨 :  ❤️   ❤️   ❤️          │\n");
    }
    else if (num == 2)
    {
        printf("  목숨 :  ❤️   ❤️              │\n");
    }
    else if (num == 1)
    {
        printf("  목숨 :  ❤️                  │\n");
    }
    else if (num == 0)
    {
        printf("  목숨 :                     │\n");
    }
}

void ItemPrint(int num)
{
    if (num == 2)
    {
        printf("  아이템 :         ⭐   ⭐   │");
    }
    else if (num == 1)
    {
        printf("  아이템 :              ⭐   │");
    }
    else if (num == 0)
    {
        printf("  아이템 :                   │");
    }
}

void ItemCard(int*ptr1)
{
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", i + 1);
        if (ptr1[i] == 3 || ptr1[i] == 2)
            printf(" 🐵");
        else if (ptr1[i] == 5 || ptr1[i] == 4)
            printf(" 🐶");
        else if (ptr1[i] == 7 || ptr1[i] == 6)
            printf(" 🦊");
        else if (ptr1[i] == 9 || ptr1[i] == 8)
            printf(" 🐯");
        else if (ptr1[i] == 11 || ptr1[i] == 10)
            printf(" 🐱");
        else if (ptr1[i] == 13 || ptr1[i] == 12)
            printf(" 🐷");
        else if (ptr1[i] == 15 || ptr1[i] == 14)
            printf(" 🦝");
        else if (ptr1[i] == 17 || ptr1[i] == 16)
            printf(" 🐼");
        else if (ptr1[i] == 19 || ptr1[i] == 18)
            printf(" 🐻");
        else if (ptr1[i] == 21 || ptr1[i] == 20)
            printf(" 🐸");
    }
}

void Line1(void)
{
     printf("╭");
    for (int i = 0; i < 80; i++)
    {
        printf("─");
    }
    printf("╮\n");
    printf("│");
}

void Line2(void)
{
    printf("\n");
    printf("╰");
    for (int i = 0; i < 80; i++)
    {
        printf("─");
    }
    printf("╯\n");
}

int main(void)
{
    int x;
    int y;
    int a;
    int b = 0;
    int heart = 5;
    int item = 2;
    int choice;
    int card1[10] = {
        0};
    int card2[10] = {
        0};
   
    RandNum(card1, card2);

    Line1();

    Card1Print(card1);

    printf("   목숨 : ❤️   ❤️   ❤️   ❤️   ❤️  │\n");
    printf("│");

    Card1Print(card2);

    printf("  아이템 :           ⭐   ⭐ │");
    
    Line2();
    
    sleep(5);

    while (1)
    {
        system("clear");

        Line1();

        BackPrint(card1);

        LifePrint(heart);
        
        printf("│");

        BackPrint(card2);

        ItemPrint(item);
        
        Line2();
       
        printf("                   ⭐ 아이템을 사용하려면 11, 11을 입력하세요!\n");
        if (heart == 0)
        {
            printf("5번의 목숨을 다 사용하여 춘식이 사망\n");
            sleep(1);
            break;
        }
        if (b == 10)
        {
            printf("\n카드를 다 뒤집었어요! 성공!\n");
            break;
        }
        printf("\n");
        printf("윗자리의 카드번호를 선택하세요");
        scanf("%d", &x);
        printf("아랫자리의 카드번호를 선택하세요");
        scanf("%d", &y);

        if (x == 11 && y == 11 && item >= 1)
        {
            system("clear");
            printf("  아이템을 사용합니다\n");

            ItemCard(card1);            
            printf("\n");
            ItemCard(card2);
            printf("\n");
            
            sleep(3);
            item--;
            continue;
        }
        else if (x == 11 && y == 11 && item == 0)
        {
            printf("아이템을 다 사용했습니다!\n");
            sleep(1);
            continue;
        }

        if (card1[x - 1] == card2[y - 1])
        {
            a = card1[x - 1];
            a++;
            card1[x - 1] = a;
            card2[y - 1] = a;
            b++;
        }
        else
        {
            printf("땡 틀렸습니다!\n");
            heart -= 1;
            sleep(1);
        }
    }
    return 0;
}

