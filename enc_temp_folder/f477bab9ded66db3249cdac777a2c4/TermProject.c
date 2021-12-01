//TermProject - Vending Machine
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//전역변수에 대해 공부
int item[10] = { 10, 20, 15, 25, 5, 8, 10, 15, 20, 3 }; //상품별 재고
int price[10] = { 500, 500, 700, 700, 700, 700, 800, 800, 800, 1000 }; //상품별 가격
char* itemN[11] = { "물", "불","코카콜라", "칠성사이다", "제로콜라", "미란다", "박카스", "활명수", "오르나민-C", "몬스터" }; //상품별 이름


void title() {
    printf("================================\n");
    printf("============DCU자판기===========\n");
    printf("================================\n");
}
void menu() {
    for (int i = 0; i < 10; i++) {
        printf("%2d번 | 수량 : %2d | %s | 가격 : %4d원\n", i + 1, item[i], itemN[i], price[i]); //이름들을 오른쪽 정렬하고싶음
    }
}
int getMoney(money) { //함수안에서 값을 할당받으려하니 반환값이 무시된다고 뜬다. 이를 나는 그냥 main함수에서 받기로 하였다.
    printf("================================\n");
    printf("   돈을 넣어 주세요 : ");
    scanf("%d", &money);
    return money;

}
void manual(int money) {
    printf("================================\n");
    printf("=======[현재 금액 : %4d]========\n", money);
    printf("================================\n");
    printf("=====[ 판매 매출 보기 : W ]=====\n");
    printf("=====[판매 매출 초기화 : E]=====\n");
    printf("=====[   자판기 종료 : X  ]=====\n");
    printf("================================\n");
    printf("====[상품을 선택 해 주세요.]====\n");
}
int selectItem(int selection, int money, int change, int sales) {
    if (item[selection] < 0) {
        printf("재고 없음");
        printf("다시 선택해 주세요.");
        selectItem(selection, money, change, sales);
        return -1;
    }
    else if (money < price[selection]) {
        printf("돈이 부족합니다.");
        printf("다시 선택해 주세요.");
        selectItem(selection, money, change, sales);
        return -1;
    }
    else if (money >= price[selection]) {
        change = money - price[selection];
        sales += price[selection];
        item[selection] -= 1;
        return change, sales, selection;
    }
}
/* 사용할지 말지 고민중...
* 사용하면 selectItem에서 slection과 money만 사용하면 되므로 main에서 opctin()을 사용시 selection만 적어주면됨. or selection과 sales둘다 적어줘야함
int payment(int money, int selection, int change, int selection) {
    if (money >= price[selection]) {
        change = money - price[selection];
        sales += price[selection];
        item[selection] -= 1;
        return change, sales;
    }
}
*/
void option(int sales, int selection) {
    switch (selection) {
    case 'W': case 'w':
        printf("판매 매출 : %d원", sales);
        break;
    case 'E': case 'e':
        sales = 0;
        printf("판매 매출이 초기화 되었습니다.");
        break;
    case 'X': case 'x':
        printf("자판기를 종료 합니다.");
        break;
    }
}
//함수에 대해 공부
void result(int selection) {
    printf("================================\n");
    printf("=[주문하신 상품 %s 나왔습니다.]=\n", itemN[selection]);
    printf("================================\n");
    printf("=======[ 계속 뽑기 : Y ]========\n");
    printf("=======[ 잔돈 받기 : N ]========\n");
    printf("================================\n");
}
int main()
{
    int money = 0; //투입한 금액
    int change = 0; //잔돈
    int selection = 0; //선택 
    int sales = 0; //전체 매출
    int YN = 1; //마지막 result에 대한 값
    while (1) {
        title();
        menu();
        getMoney(money);
        manual(money);
        scanf("%d", &selection);
        selection = selection - 1; //상품 번호와 인덱스가 동일하게 변경.
        if (0 <= selection <= 10) {
            selectItem(selection, money, change, sales);
            result(selection);
            scanf("%d", &YN);
            if (YN == 'N' || YN == 'n') printf("잔돈 %d원 입니다.", change);
            else if (YN == 'Y' || YN == 'y') {
                printf("감사합니다. 다음에 또 이용해주세요");
                break;
            }
        }
        else if (selection == 'W' || selection == 'w' || selection == 'E' || selection == 'e' || selection == 'Q' || selection == 'q') {
            option(sales, selection);
        }
        else if (selection == 'X' || selection == 'x') {
            printf("자판기 전원이 꺼집니다.");
            return 0;
        }
        else {
            printf("잘못된 입력입니다.\n다시 선택해 주십시오");
            selectItem(selection, money, change, sales);
        }
    }
    printf("감사합니다.\n 다음에 또 이용해 주세요");
    
    return 0;
}
