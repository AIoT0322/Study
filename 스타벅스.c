#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(void)
{
   int menu1;
   int menu2;
   int menu3;
   int menu4;
   int menu5;
   int menu6;
   int size1;
   int size2;
   int size3;
   int size4;
   int size5;
   int size6;
   int num1;
   int num2;
   int num3;
   int num4;
   int num5;
   int num6;
   int sum1=0;   
   int sum2=0;
   int sum3=0;
   int sum4=0;
   int sum5=0;
   int sum6=0;
   int total=0;
   int choice1, choice2, choice3;
   int membership;
   int discount;
   int day=0;
   int coffeesum=0;
   int coldbrewsum=0;
   int frappuccinosum=0;
   int blendedsum=0;
   int fizziosum=0;
   int teasum=0;
   int cart1[100];
   char cart2[100];
   char *coffeemenu[7]={"아메리카노", "카페라떼", "카푸치노", "카라멜마끼아또", "화이트초콜릿모카", "카페모카", "돌체라떼"};
   char *coldbrewmenu[4]={"콜드브루오트라떼", "돌체콜드브루", "바닐라크림콜드브루", "콜드브루"};
   char *frappuccinomenu[9]={"더블에스프레소칩프라푸치노", "제주유기농말차로만든크림프라푸치노", "자바칩프라푸치노", "초콜릿크림칩프라푸치노", "화이트초콜릿모카프라푸치노", "모카프라푸치노", "카라멜프라푸치노", "에스프레소프라푸치노", "바닐라크림프라푸치노"};
   char *blendedmenu[5]={"민트초콜릿칩블렌디드", "딸기딜라이트요거트블렌디드", "피치&레몬블렌디드", "망고바나나블렌디드", "망고패션프루트블렌디드"};
   char *fizziomenu[3]={"쿨라임피지오", "블랙티레모네이드피지오", "패션탱고티레모네이드피지오"};
   char *teamenu[8]={"뉴이어시트러스티", "돌체블랙밀크티", "유자민트티", "패션프루트티", "제주유기농말차로만든라떼", "차이티라떼", "라임패션티", "자몽허니블랙티"};
   srand(time(NULL));

   while(1)   
   {
        printf("환영합니다! 스타벅스입니다.  1. 메뉴보기  2. 일매출정산\n");
        scanf("%d", &choice1);

        if(choice1==2)
        {
            printf("----------------카테고리 별 매출----------------\n");
            printf("  커피메뉴                              %d원\n", coffeesum);
            printf("  콜드브루메뉴                          %d원\n", coldbrewsum);
            printf("  프라푸치노메뉴                        %d원\n", frappuccinosum);
            printf("  블렌디드메뉴                          %d원\n", blendedsum);
            printf("  피지오메뉴                            %d원\n", fizziosum);
            printf("  티메뉴                                %d원\n", teasum);
            printf("------------------------------------------------\n");
            printf(" 일 매출 총합                        %d원\n", day);
            continue;
        }

        while(1)
        {
            if(choice1==1)
            {
                printf("카테고리를 선택하세요: 1.커피  2.콜드브루  3.프라푸치노  4.블렌디드  5.피지오  6.티\n");
                scanf("%d", &choice2);
            }
            
            if(choice2==1)
            {
                printf("            스타벅스 커피 메뉴\n");
                printf("-------------------------------------------------\n");
                printf("메뉴             1.Short 2.Tall 3.Grande 4.Venti\n");
                printf("-------------------------------------------------\n");
                printf("1.아메리카노        4000   4500   5000    5500\n");
                printf("2.카페라떼          4500   5000   5500    6000\n");
                printf("3.카푸치노          4500   5000   5500    6000\n");
                printf("4.카라멜마끼아또    5400   5900   6400    6900\n");
                printf("5.화이트초콜릿모카  5400   5900   6400    6900\n");
                printf("6.카페모카          5000   5500   6000    6500\n");
                printf("7.돌체라떼          5400   5900   6400    6900\n");

                int coffee[7][4]= {
                    {4000, 4500, 5000, 5500},
                    {4500, 5000, 5500, 6000},
                    {4500, 5000, 5500, 6000},
                    {5400, 5900, 6400, 6900},
                    {5400, 5900, 6400, 6900},
                    {5000, 5500, 6000, 6500},
                    {5400, 5900, 6400, 6900}
                };

                printf("원하는 메뉴를 선택하세요.\n");
                scanf(" %d", &menu1);
                printf("음료의 사이즈를 선택하세요.\n");
                scanf(" %d", &size1);
                printf("몇 잔 주문하시겠습니까?\n");
                scanf(" %d", &num1);

                cart1[0]=coffee[menu1-1][size1-1];
                cart2[0]=*coffeemenu[menu1-1];
                sum1 += (coffee[menu1-1][size1-1]*num1);
                coffeesum+=sum1;

                printf("1.추가주문  2.계산\n");
                scanf("%d", &choice3);
                if(choice3==1)
                    choice1=1;

                else if(choice3==2)  
                    break;
            }
                        
                
            else if(choice2==2)
            {
                printf("        스타벅스 콜드브루 메뉴\n");
                printf("-----------------------------------------------\n");
                printf("메뉴               1.Tall 2.Grande  3.Venti\n");
                printf("-----------------------------------------------\n");
                printf("1.콜드브루오트라떼    5800   6300    6800\n");
                printf("2.돌체콜드브루        6000   6500    7000\n");
                printf("3.바닐라크림콜드브루  5800   6300    6800\n");
                printf("4.콜드브루            4900   5400    5900\n");

                int coldbrew[4][3] = {
                    {5800, 6300, 6800},
                    {6000, 6500, 7000},
                    {5800, 6300, 6800},
                    {4900, 5400, 5900}
                };

                printf("원하는 메뉴를 선택하세요.\n");
                scanf(" %d", &menu2);
                printf("음료의 사이즈를 선택하세요.\n");
                scanf(" %d", &size2);
                printf("몇 잔 주문하시겠습니까?\n");
                scanf(" %d", &num2);

                sum2 += (coldbrew[menu2-1][size2-1]*num2);
                coldbrewsum+=sum2;

                printf("1.추가주문  2.계산\n");
                scanf("%d", &choice3);
                if(choice3==1)
                    choice1=1;

                else if(choice3==2)  
                    break;
            }
                
            else if(choice2==3)
            {
                printf("               스타벅스 프라푸치노 메뉴\n");
                printf("-----------------------------------------------------------\n");
                printf("메뉴                               1.Tall 2.Grande 3.Venti\n");
                printf("-----------------------------------------------------------\n");
                printf("1.더블에스프레소칩프라푸치노          6300   6800   7300\n");
                printf("2.제주유기농말차로만든크림프라푸치노  6300   6800   7300\n");
                printf("3.자바칩프라푸치노                    6300   6800   7300\n");
                printf("4.초콜릿크림칩프라푸치노              6000   6500   7000\n");
                printf("5.화이트초콜릿모카프라푸치노          6000   6500   7000\n");
                printf("6.모카프라푸치노                      6000   6500   7000\n");
                printf("7.카라멜프라푸치노                    5900   6400   6900\n");
                printf("8.에스프레소프라푸치노                5500   6000   6500\n");
                printf("9.바닐라크림프라푸치노                5500   6000   6500\n");

                int frappuccino[9][3] = {
                    {6300, 6800, 7300},
                    {6300, 6800, 7300},
                    {6300, 6800, 7300},
                    {6000, 6500, 7000},
                    {6000, 6500, 7000},
                    {6000, 6500, 7000},
                    {5900, 6400, 6900},
                    {5500, 6000, 6500},
                    {5500, 6000, 6500}
                };

                printf("원하는 메뉴를 선택하세요.\n");
                scanf(" %d", &menu3);
                printf("음료의 사이즈를 선택하세요.\n");
                scanf(" %d", &size3);
                printf("몇 잔 주문하시겠습니까?\n");
                scanf(" %d", &num3);

                sum3 += (frappuccino[menu3-1][size3-1]*num3);
                frappuccinosum+=sum3;

                printf("1.추가주문  2.계산\n");
                scanf("%d", &choice3);
                if(choice3==1)
                    choice1=1;

                else if(choice3==2)  
                    break;
            }
                
            else if(choice2==4)
            {
                printf("              스타벅스 블렌디드 메뉴\n");
                printf("----------------------------------------------------\n");
                printf("메뉴                       1.Tall  2.Grande 3.Venti\n");
                printf("----------------------------------------------------\n");
                printf("1.민트초콜릿칩블렌디드        6300    6800    7300\n");
                printf("2.딸기딜라이트요거트블렌디드  6300    6800    7300\n");
                printf("3.피치&레몬블렌디드           6300    6800    7300\n");
                printf("4.망고바나나블렌디드          6300    6800    7300\n");
                printf("5.망고패션프루트블렌디드      5400    5900    6400\n");

                int blended[5][3] = {
                    {6300, 6800, 7300},
                    {6300, 6800, 7300},
                    {6300, 6800, 7300},
                    {6300, 6800, 7300},
                    {5400, 5900, 6400}
                };

                printf("원하는 메뉴를 선택하세요.\n");
                scanf(" %d", &menu4);
                printf("음료의 사이즈를 선택하세요.\n");
                scanf(" %d", &size4);
                printf("몇 잔 주문하시겠습니까?\n");
                scanf(" %d", &num4);

                sum4 += (blended[menu4-1][size4-1]*num4);
                blendedsum+=sum4;
                
                printf("1.추가주문  2.계산\n");
                scanf("%d", &choice3);
                
                if(choice3==1)
                    choice1=1;

                else if(choice3==2)  
                    break;
            }
                
            else if(choice2==5)
            {
                printf("             스타벅스 피지오 메뉴\n");
                printf("---------------------------------------------------\n");
                printf("메뉴                        1.Tall 2.Grande 3.Venti\n");
                printf("---------------------------------------------------\n");
                printf("1.쿨라임피지오                 5900   6400   6900\n");
                printf("2.블랙티레모네이드피지오       5400   5900   6400\n");
                printf("3.패션탱고티레모네이드피지오   5400   5900   6400\n");

                char *fizziomenu[3]={"쿨라임피지오", "블랙티레모네이드피지오", "패션탱고티레모네이드피지오"};
                int fizzio[3][3] = {
                    {5900, 6400, 6900},
                    {5400, 5900, 6400},
                    {5400, 5900, 6400}
                };

                printf("원하는 메뉴를 선택하세요.\n");
                scanf(" %d", &menu5);
                printf("음료의 사이즈를 선택하세요.\n");
                scanf(" %d", &size5);
                printf("몇 잔 주문하시겠습니까?\n");
                scanf(" %d", &num5);

                sum5 += (fizzio[menu5-1][size5-1]*num5);
                fizziosum+=sum5;

                printf("1.추가주문  2.계산\n");
                scanf("%d", &choice3);
                if(choice3==1)
                    choice1=1;

                else if(choice3==2)  
                    break;
            }
                
            else if(choice2==6)
            {
                printf("              스타벅스 티 메뉴\n");
                printf("-------------------------------------------------\n");
                printf("메뉴                      1.Tall 2.Grande 3.Venti\n");
                printf("-------------------------------------------------\n");
                printf("1.뉴이어시트러스티           6200   6600   7200\n");
                printf("2.돌체블랙밀크티             5900   6400   6900\n");
                printf("3.유자민트티                 5900   6400   6900\n");
                printf("4.패션프루트티               5900   6400   6900\n");
                printf("5.제주유기농말차로만든라떼   6200   6600   7200\n");
                printf("6.차이티라떼                 5500   6000   6500\n");
                printf("7.라임패션티                 5900   6400   6900\n");
                printf("8.자몽허니블랙티             5700   6200   6700\n");

                char *teamenu[8]={"뉴이어시트러스티", "돌체블랙밀크티", "유자민트티", "패션프루트티", "제주유기농말차로만든라떼", "차이티라떼", "라임패션티", "자몽허니블랙티"};
                int tea[8][3] = {
                    {6100, 6600, 7100},
                    {5900, 6400, 6900},
                    {5900, 6400, 6900},
                    {5900, 6400, 6900},
                    {6100, 6600, 7100},
                    {5500, 6000, 6500},
                    {5900, 6400, 6900},
                    {5700, 6200, 6700}
                };

                printf("원하는 메뉴를 선택하세요.\n");
                scanf(" %d", &menu6);
                printf("음료의 사이즈를 선택하세요.\n");
                scanf(" %d", &size6);
                printf("몇 잔 주문하시겠습니까?\n");
                scanf(" %d", &num6);

                sum6 += (tea[menu6-1][size6-1]*num6);
                teasum+=sum6;

                printf("1.추가주문  2.계산\n");
                scanf("%d", &choice3);
                if(choice3==1)
                    choice1=1;

                else if(choice3==2)  
                    break;
            }
        }
        if(sum1!=0)
        {
            printf("커피 주문메뉴: %s %d잔 %d원\n", coffeemenu[menu1-1], num1, sum1);
        }  
        if (sum2!=0)
        {
            printf("콜드브루 주문메뉴: %s %d잔 %d원\n", coldbrewmenu[menu2-1], num2, sum2);
        }
        if (sum3!=0)
        {
            printf("프라푸치노 주문메뉴: %s %d잔 %d원\n", frappuccinomenu[menu3-1], num3, sum3);
        }
        if(sum4!=0)
        {
            printf("블렌디드 주문메뉴: %s %d잔 %d원\n", blendedmenu[menu4-1], num4, sum4);
        }
        if (sum5!=0)
        {
            printf("피지오 주문메뉴: %s %d잔 %d원\n", fizziomenu[menu5-1], num5, sum5);
        }
        if (sum6!=0)
        {
            printf("티 주문메뉴: %s %d잔 %d원\n", teamenu[menu6-1], num6, sum6);
        }
        printf("멤버쉽 할인을 받으시겠습니까?  1.할인선택  2.계산\n");
        scanf("%d", &discount);
        total=sum1+sum2+sum3+sum4+sum5+sum6;
        
        if(discount==1)
        {
            membership=rand()%300;
            if(membership<100)
            {
                printf("멤버쉽 등급은 Silver입니다!\n");
                if(total>=10000)
                {
                    printf("총 합계: %.0f원\n", 0.95*(total));
                    day+=total;
                }
                else
                {
                    printf("최소 금액 10000원 미달로 할인 적용을 할 수 없습니다.\n");
                    printf("총 합계: %.d원\n", total);
                    day+=total;
                }
            }
            else if(membership>=100 && membership<200)
            {
                printf("멤버쉽 등급은 Gold입니다!\n");
                if(total>=20000)
                {
                    printf("총 합계: %.0f원\n", 0.85*(total));
                    day+=total;
                }
                else
                {
                    printf("최소 금액 20000원 미달로 할인 적용을 할 수 없습니다.\n");
                    printf("총 합계: %d원\n", total);
                    day+=total;
                }
            }
            else
            {
                printf("멤버쉽 등급은 Vip입니다!\n");
                printf("총 합계: %.0f원\n", 0.85*(total));
                day+=total;
            }
        }
        if(discount==2)
        {
            printf("총 합계: %d원\n", total);
            day+=total;
        }
        continue;
   }
    return 0;
}  