//TermProject - Vending Machine
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//���������� ���� ����
int item[10] = { 10, 20, 15, 25, 5, 8, 10, 15, 20, 3 }; //��ǰ�� ���
int price[10] = { 500, 500, 700, 700, 700, 700, 800, 800, 800, 1000 }; //��ǰ�� ����
char* itemN[11] = { "��", "��","��ī�ݶ�", "ĥ�����̴�", "�����ݶ�", "�̶���", "��ī��", "Ȱ���", "��������-C", "����" }; //��ǰ�� �̸�


void title() {
    printf("================================\n");
    printf("============DCU���Ǳ�===========\n");
    printf("================================\n");
}
void menu() {
    for (int i = 0; i < 10; i++) {
        printf("%2d�� | ���� : %2d | %s | ���� : %4d��\n", i + 1, item[i], itemN[i], price[i]); //�̸����� ������ �����ϰ����
    }
}
int getMoney(money) { //�Լ��ȿ��� ���� �Ҵ�������ϴ� ��ȯ���� ���õȴٰ� ���. �̸� ���� �׳� main�Լ����� �ޱ�� �Ͽ���.
    printf("================================\n");
    printf("   ���� �־� �ּ��� : ");
    scanf("%d", &money);
    return money;

}
void manual(int money) {
    printf("================================\n");
    printf("=======[���� �ݾ� : %4d]========\n", money);
    printf("================================\n");
    printf("=====[ �Ǹ� ���� ���� : W ]=====\n");
    printf("=====[�Ǹ� ���� �ʱ�ȭ : E]=====\n");
    printf("=====[   ���Ǳ� ���� : X  ]=====\n");
    printf("================================\n");
    printf("====[��ǰ�� ���� �� �ּ���.]====\n");
}
int selectItem(int selection, int money, int change, int sales) {
    if (item[selection] < 0) {
        printf("��� ����");
        printf("�ٽ� ������ �ּ���.");
        selectItem(selection, money, change, sales);
        return -1;
    }
    else if (money < price[selection]) {
        printf("���� �����մϴ�.");
        printf("�ٽ� ������ �ּ���.");
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
/* ������� ���� �����...
* ����ϸ� selectItem���� slection�� money�� ����ϸ� �ǹǷ� main���� opctin()�� ���� selection�� �����ָ��. or selection�� sales�Ѵ� ���������
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
        printf("�Ǹ� ���� : %d��", sales);
        break;
    case 'E': case 'e':
        sales = 0;
        printf("�Ǹ� ������ �ʱ�ȭ �Ǿ����ϴ�.");
        break;
    case 'X': case 'x':
        printf("���Ǳ⸦ ���� �մϴ�.");
        break;
    }
}
//�Լ��� ���� ����
void result(int selection) {
    printf("================================\n");
    printf("=[�ֹ��Ͻ� ��ǰ %s ���Խ��ϴ�.]=\n", itemN[selection]);
    printf("================================\n");
    printf("=======[ ��� �̱� : Y ]========\n");
    printf("=======[ �ܵ� �ޱ� : N ]========\n");
    printf("================================\n");
}
int main()
{
    int money = 0; //������ �ݾ�
    int change = 0; //�ܵ�
    int selection = 0; //���� 
    int sales = 0; //��ü ����
    int YN = 1; //������ result�� ���� ��
    while (1) {
        title();
        menu();
        getMoney(money);
        manual(money);
        scanf("%d", &selection);
        selection = selection - 1; //��ǰ ��ȣ�� �ε����� �����ϰ� ����.
        if (0 <= selection <= 10) {
            selectItem(selection, money, change, sales);
            result(selection);
            scanf("%d", &YN);
            if (YN == 'N' || YN == 'n') printf("�ܵ� %d�� �Դϴ�.", change);
            else if (YN == 'Y' || YN == 'y') {
                printf("�����մϴ�. ������ �� �̿����ּ���");
                break;
            }
        }
        else if (selection == 'W' || selection == 'w' || selection == 'E' || selection == 'e' || selection == 'Q' || selection == 'q') {
            option(sales, selection);
        }
        else if (selection == 'X' || selection == 'x') {
            printf("���Ǳ� ������ �����ϴ�.");
            return 0;
        }
        else {
            printf("�߸��� �Է��Դϴ�.\n�ٽ� ������ �ֽʽÿ�");
            selectItem(selection, money, change, sales);
        }
    }
    printf("�����մϴ�.\n ������ �� �̿��� �ּ���");
    
    return 0;
}
