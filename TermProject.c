//TermProject - Vending Machine
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int money = 0; //������ �ݾ�
int change = 0; //�ܵ�
int selection = 0; //��ǰ ��ȣ
int sales = 0; //��ü ����
int item[10] = { 10, 20, 15, 25, 5, 8, 10, 15, 20, 3 };
int price[10] = { 500, 500, 700, 700, 700, 700, 800, 800, 800, 1000 };
char* itemN[11] = { "��", "��","��ī�ݶ�", "ĥ�����̴�", "�����ݶ�", "�̶���", "��ī��", "Ȱ���", "��������-C", "����" };

void title() {
    printf("================================\n");
    printf("============DCU���Ǳ�===========\n");
    printf("================================\n");
    printf("=====[ ���� ������ �ּ��� ]=====\n");
    scanf("%d", &money);
    printf("================================\n");
}
void menu() {
    for (int i = 0; i < 10; i++) {
        printf("%2d�� | ���� : %2d | %s | ���� : %4d��\n", i + 1, item[i], itemN[i], price[i]);
    }
}
void manual() {
    printf("=======[���� �ݾ� : %4d]========\n", money);
    printf("================================\n");
    printf("=====[ �Ǹ� ���� ���� : W ]=====\n");
    printf("=====[�Ǹ� ���� �ʱ�ȭ : E]=====\n");
    printf("=====[   ���Ǳ� ���� : X  ]=====\n");
    printf("================================\n");
}
void selectItem(int selection) {
    while (1) {
        printf("=====[��ǰ�� ������ �ּ���]======\n");
        scanf("%d", &selection);
        if (item[selection - 1] == 0) printf("��� ����");
        else break;
    }
    item[selection - 1] -= 1;
    return selection;
}
void payment() {
    if (money < price[selection]) printf("���� �����մϴ�.");
    else {
        change = money - price[selection-1]; //�ܵ�
        sales += price[selection - 1]; //�Ѹ���
    }
}
int main()
{
    title();
    menu(money);
    selectItem(selection);


    return 0;
}
