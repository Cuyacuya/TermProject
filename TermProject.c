//TermProject - Vending Machine
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//전역변수에 대해 공부
int item[10] = { 10, 20, 15, 0, 5, 8, 10, 15, 20, 3 }; //상품별 재고
int price[10] = { 500, 500, 700, 700, 700, 700, 800, 800, 800, 1000 }; //상품별 가격
char* itemN[11] = { "물", "불","코카콜라", "칠성사이다", "제로콜라", "미란다", "박카스", "활명수", "오르나민-C", "몬스터" }; //상품별 이름
int money = 0; //투입한 금액
int change = 0; //잔돈
int selection = 0; //선택 
int sales = 0; //전체 매출
char option = -1; //관리자모드에서 옵션값
char YN = 'A'; //마지막 result에 대한 값


void title() {
    printf("================================\n");
    printf("============DCU자판기===========\n");
    printf("================================\n");
}
void menu() {
    for (int i = 0; i < 10; i++) {
        if(item[i]>0)
        printf("%2d번 | 수량 : %4d | %s | 가격 : %4d원\n", i + 1, item[i], itemN[i], price[i]); //이름들을 오른쪽 정렬하고싶음
        else
            printf("%2d번 | 재고없음 | %s | 가격 : %4d원\n", i + 1, itemN[i], price[i]); //이름들을 오른쪽 정렬하고싶음
    }
    printf("================================\n");
}
void manual(int money) {
    printf("================================\n");
    printf("=======[현재 금액 : %4d]========\n", money);
    printf("================================\n");
    printf("=======[ 관리자 모드 : 0 ]======\n");
    printf("================================\n");
    printf("====[상품을 선택 해 주세요.]====\n");
}
int selectItem(int selection,int money) {
    if (item[selection] <= 0) {
        printf("재고 없음");
        printf("다시 선택해 주세요.");
        return 0;
    }
    else if (money < price[selection]) {
        printf("돈이 부족합니다.");
        printf("다시 선택해 주세요.");
        return 0;
    }
    else {
        change = money - price[selection]; //잔돈계산
        sales += price[selection]; //총매출
        item[selection] -= 1; //선택한 상품의 재고 -1
        return change, sales;
    }
}
int admin() {
    printf("=========[ 관리자 모드 ]=======\n");
    printf("================================\n");
    printf("========[ 판매 매출 : W ]=======\n");
    printf("=======[ 매출 초기화 : E ]======\n");
    printf("=======[ 자판기 종료 : X ]======\n");
    printf("================================\n");
    printf("======[옵션을 선택해주세요]=====\n");
    while (1) {
        scanf(" %c", &option);
        if (option == 'W' || option == 'w') {
            printf("판매 매출 : %d원", sales);
            return 0;
        }
        else if (option == 'E' || option == 'e') {
            sales = 0;
            printf("판매 매출이 초기화 되었습니다.");
            return 0;
        }
        else printf("잘못된 옵션입니다. 다시 선택해주세요.");
    }
}
//함수에 대해 공부
void result(int selection) {
    int i = selection; //itemN[slection]으로 하닌깐 %s인데 정수형이라고 안되서 i를 만들어줌.
    printf("================================\n");
    printf("=[주문하신 상품 %s 나왔습니다.]=\n", itemN[i]);
    printf("================================\n");
    printf("=======[ 계속 뽑기 : Y ]========\n");
    printf("=======[ 잔돈 받기 : N ]========\n");
    printf("================================\n");
}
int main()
{
    while (1) {
        title();
        menu();
        printf("   돈을 넣어 주세요 : ");
        scanf("%d", &money);
        manual(money);
        scanf("%d", &selection);
        if (selection == 0) {
            printf("관리자 모드를 실행합니다.\n");
            admin();
            if (option == 'X' || option == 'x') {
                printf("자판기를 종료합니다.");
                return 0; //자판기를 종료
            }
        }
        else if (1 <= selection <= 10) {
            selection = selection - 1; //상품 번호와 인덱스가 동일하게 변경.
            selectItem(selection, money);
            result(selection);
            scanf(" %c", &YN);
            if (YN == 'N' || YN == 'n') {
                printf("잔돈 : %d원입니다.\n", change);
                printf("이용해주셔서 감사합니다.");
                return 0;//자판기를 종료
            }
            if (YN == 'Y' || YN == 'y') {
                continue; //자판기를 계속 이용
            }
        }
        else {
            printf("잘못된 선택입니다.");
            return 0;
        }
    }
    return 0;
}
