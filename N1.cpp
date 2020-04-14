#include<stdio.h>
#include<Windows.h>
void my_opening();
int my_card1(int(*)[4]);
int my_card2(int(*)[4]);
int my_card3(int(*)[4]);
int my_card4(int(*)[4]);
int my_card5(int(*)[4]);
void my_res(int, int, int, int, int);
int main()
{
    int card1[4][4] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31 };
    int card2[4][4] = { 2,3,6,7,10,11,14,15,18,19,22,23,26,27,30,31 };
    int card3[4][4] = { 4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31 };
    int card4[4][4] = { 8,9,10,11,12,13,14,15,24,25,26,27,28,29,30,31 };
    int card5[4][4] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    int(*ca1)[4];
    int(*ca2)[4];
    int(*ca3)[4];
    int(*ca4)[4];
    int(*ca5)[4];
    int a, b, c, d, e;
    char k;
    my_opening();
    printf("생각하셨어요? 시작하려면 엔터를 누르시오.");
    scanf("%c", &k);
    printf("\n\n");
    ca1 = card1;
    a = my_card1(card1);
    ca2 = card2;
    b = my_card2(card2);
    ca3 = card3;
    c = my_card3(card3);
    ca4 = card4;
    d = my_card4(card4);
    ca5 = card5;
    e = my_card5(card5);
    my_res(a, b, c, d, e);
    system("PAUSE");
    return 0;
}
void my_opening()
{
    printf("# 지금부터 여러분을 신비한 마술의 세계로 초대합니다.\n\n\n");
    printf("1 - 31의 숫자중 마음에 드는 숫자를 생각해 보세요. \n\n\n");
}

int my_card1(int(*ca1)[4])
{
    int i, j, a;
    while (1)
    {
        printf(" ㅁ-------- A 카드 --------ㅁ\n");
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%7d", ca1[i][j]);
            }
            printf("\n");                    //////////제시된 소스코드
        }
        printf(" ㅁ------------------------ㅁ\n");
        printf("\n\n");
        printf("A 카드에 생각한 숫자가 있으면 1(Yes) 없으면 0(No) 입력: ");
        scanf("%d", &a);
        printf("\n");
        if (a == 0 || a == 1) return a;
    }
}
int my_card2(int(*ca2)[4]) {
    int i, j, b;
    while (1)
    {
        printf(" ㅁ-------- B 카드 --------ㅁ\n");
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%7d", ca2[i][j]);
            }
            printf("\n");
        }
        printf(" ㅁ------------------------ㅁ\n");
        printf("\n\n");
        printf("B 카드에 생각한 숫자가 있으면 1(Yes) 없으면 0(No) 입력: ");
        scanf("%d", &b);
        printf("\n");
        if (b == 0 || b == 1) return b;
    }
}

int my_card3(int(*ca3)[4])
{
    int i, j, c;
    while (1)
    {
        printf(" ㅁ-------- C 카드 --------ㅁ\n");
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%7d", ca3[i][j]);
            }
            printf("\n");
        }
        printf(" ㅁ------------------------ㅁ\n");
        printf("\n");
        printf("C 카드에 생각한 숫자가 있으면 1(Yes) 없으면 0(No) 입력: ");
        scanf("%d", &c);
        printf("\n");
        if (c == 0 || c == 1) return c;
    }
}
int my_card4(int(*ca4)[4])
{
    int i, j, d;
    while (1)
    {
        printf(" ㅁ-------- D 카드 --------ㅁ\n");
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%7d", ca4[i][j]);
            }
            printf("\n");
        }
        printf(" ㅁ------------------------ㅁ\n");
        printf("\n\n");
        printf("D 카드에 생각한 숫자가 있으면 1(Yes) 없으면 0(No) 입력: ");
        scanf("%d", &d);
        printf("\n");
        if (d == 0 || d == 1) return d;
    }
}
int my_card5(int(*ca5)[4])
{
    int i, j, e;
    while (1)
    {
        printf(" ㅁ-------- E 카드 --------ㅁ\n");
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                printf("%7d", ca5[i][j]);
            }
            printf("\n");
        }
        printf(" ㅁ------------------------ㅁ\n");
        printf("\n");
        printf("E 카드에 생각한 숫자가 있으면 1(Yes) 없으면 0(No) 입력: ");
        scanf("%d", &e);
        printf("\n");
        if (e == 0 || e == 1) return e;
    }
}
void my_res(int a, int b, int c, int d, int e) {
    int res;
    res = a + b * 2 + c * 2 * 2 + d * 2 * 2 * 2 + e * 2 * 2 * 2 * 2;
    printf("빠밤 당신이 생각한 숫자는 %d입니다.", res);
}