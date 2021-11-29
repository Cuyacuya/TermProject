//TermProject - Vending Machine
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int money = 0; //투입한 금액
int change = 0; //잔돈
int selection = 0; //상품 번호
int sales = 0; //전체 매출
int item[10] = { 10, 20, 15, 25, 5, 8, 10, 15, 20, 3 };
int price[10] = { 500, 500, 700, 700, 700, 700, 800, 800, 800, 1000 };
char* itemN[11] = { "물", "불","코카콜라", "칠성사이다", "제로콜라", "미란다", "박카스", "활명수", "오르나민-C", "몬스터" };

void title() {
    printf("================================\n");
    printf("============DCU자판기===========\n");
    printf("================================\n");
    printf("=====[ 돈을 투입해 주세요 ]=====\n");
    scanf("%d", &money);
    printf("================================\n");
}
void menu() {
    for (int i = 0; i < 10; i++) {
        printf("%2d번 | 수량 : %2d | %s | 가격 : %4d원\n", i + 1, item[i], itemN[i], price[i]);
    }
}
void manual() {
    printf("=======[현재 금액 : %4d]========\n", money);
    printf("================================\n");
    printf("=====[ 판매 매출 보기 : W ]=====\n");
    printf("=====[판매 매출 초기화 : E]=====\n");
    printf("=====[   자판기 종료 : X  ]=====\n");
    printf("================================\n");
}
void selectItem(int selection) {
    while (1) {
        printf("=====[상품을 선택해 주세요]======\n");
        scanf("%d", &selection);
        if (item[selection - 1] == 0) printf("재고 없음");
        else break;
    }
    item[selection - 1] -= 1;
    return selection;
}
void payment() {
    if (money < price[selection]) printf("돈이 부족합니다.");
    else {
        change = money - price[selection-1]; //잔돈
        sales += price[selection - 1]; //총매출
    }
}
int main()
{
    title();
    menu(money);
    selectItem(selection);


    return 0;
}
