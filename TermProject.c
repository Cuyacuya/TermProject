//TermProject - Vending Machine
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int money = 0; //������ �ݾ�
int change = 0; //�ܵ�
int selection = 0; //��ǰ ��ȣ
int sales = 0; //��ü ����
char select;
int item[10] = { 10, 20, 15, 25, 5, 8, 10, 15, 20, 3 };
int price[10] = { 500, 500, 700, 700, 700, 700, 800, 800, 800, 1000 };
char* itemN[11] = { "��", "��","��ī�ݶ�", "ĥ�����̴�", "�����ݶ�", "�̶���", "��ī��", "Ȱ���", "��������-C", "����" };

void title() {
    printf("================================\n");
    printf("============DCU���Ǳ�===========\n");
    printf("================================\n");
}
int menu() {
    for (int i = 0; i < 10; i++) {
        printf("%2d�� | ���� : %2d | %s | ���� : %4d��\n", i + 1, item[i], itemN[i], price[i]); //�̸����� ������ �����ϰ����
        printf("================================\n");
        printf("=====[ ���� ������ �ּ��� ]=====\n");
        scanf("%d", &money);
        printf("================================\n");
        return money;
    }
}
char manual() {
    printf("=======[���� �ݾ� : %4d]========\n", money);
    printf("================================\n");
    printf("=====[ �Ǹ� ���� ���� : W ]=====\n");
    printf("=====[�Ǹ� ���� �ʱ�ȭ : E]=====\n");
    printf("=====[   ���Ǳ� ���� : X  ]=====\n");
    printf("================================\n");
    printf("=====[��ǰ�� ������ �ּ���]======\n");
    scanf("%s", select);
    return select;
}
int selectItem() {
    while (1) {
        if (item[select - 1] <= 0) printf("��� ����");
        else break;
    }
    item[selection - 1] -= 1;
    selection = selection -1; //�迭�� �ε����� ��ǰ ��ȣ �����ֱ�
    return selection;
}
int payment(int selection) {
    if (money < price[selection]) printf("���� �����մϴ�.");
    else {
        change = money - price[selection-1]; //�ܵ�
        sales += price[selection - 1]; //�Ѹ���
    }
    return change, sales;
}
void result() {
    printf("================================\n");
    printf("==�ֹ��Ͻ� ��ǰ %s ���Խ��ϴ�.==\n", itemN[selection-1]);
    printf("================================\n");
    printf("=======[ ��� �̱� : Y ]========\n");
    printf("=======[ �ܵ� �ޱ� : N ]========\n");
    printf("================================\n");
}
int main()
{
    while (1) {
        title();
        menu();
        manual();
        if (0 < select < 11) {
            selectItem();

        }
        else option();
    }
    return 0;
}
