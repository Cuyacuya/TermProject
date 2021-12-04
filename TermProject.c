//TermProject - Vending Machine
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//���������� ���� ����
int item[10] = { 10, 20, 15, 0, 5, 8, 10, 15, 20, 3 }; //��ǰ�� ���
int price[10] = { 500, 500, 700, 700, 700, 700, 800, 800, 800, 1000 }; //��ǰ�� ����
char* itemN[11] = { "��", "��","��ī�ݶ�", "ĥ�����̴�", "�����ݶ�", "�̶���", "��ī��", "Ȱ���", "��������-C", "����" }; //��ǰ�� �̸�
int money = 0; //������ �ݾ�
int change = 0; //�ܵ�
int selection = 0; //���� 
int sales = 0; //��ü ����
char option = -1; //�����ڸ�忡�� �ɼǰ�
char YN = 'A'; //������ result�� ���� ��


void title() {
    printf("================================\n");
    printf("============DCU���Ǳ�===========\n");
    printf("================================\n");
}
void menu() {
    for (int i = 0; i < 10; i++) {
        if(item[i]>0)
        printf("%2d�� | ���� : %4d | %s | ���� : %4d��\n", i + 1, item[i], itemN[i], price[i]); //�̸����� ������ �����ϰ����
        else
            printf("%2d�� | ������ | %s | ���� : %4d��\n", i + 1, itemN[i], price[i]); //�̸����� ������ �����ϰ����
    }
    printf("================================\n");
}
void manual(int money) {
    printf("================================\n");
    printf("=======[���� �ݾ� : %4d]========\n", money);
    printf("================================\n");
    printf("=======[ ������ ��� : 0 ]======\n");
    printf("================================\n");
    printf("====[��ǰ�� ���� �� �ּ���.]====\n");
}
int selectItem(int selection,int money) {
    if (item[selection] <= 0) {
        printf("��� ����");
        printf("�ٽ� ������ �ּ���.");
        return 0;
    }
    else if (money < price[selection]) {
        printf("���� �����մϴ�.");
        printf("�ٽ� ������ �ּ���.");
        return 0;
    }
    else {
        change = money - price[selection]; //�ܵ����
        sales += price[selection]; //�Ѹ���
        item[selection] -= 1; //������ ��ǰ�� ��� -1
        return change, sales;
    }
}
int admin() {
    printf("=========[ ������ ��� ]=======\n");
    printf("================================\n");
    printf("========[ �Ǹ� ���� : W ]=======\n");
    printf("=======[ ���� �ʱ�ȭ : E ]======\n");
    printf("=======[ ���Ǳ� ���� : X ]======\n");
    printf("================================\n");
    printf("======[�ɼ��� �������ּ���]=====\n");
    while (1) {
        scanf(" %c", &option);
        if (option == 'W' || option == 'w') {
            printf("�Ǹ� ���� : %d��", sales);
            return 0;
        }
        else if (option == 'E' || option == 'e') {
            sales = 0;
            printf("�Ǹ� ������ �ʱ�ȭ �Ǿ����ϴ�.");
            return 0;
        }
        else printf("�߸��� �ɼ��Դϴ�. �ٽ� �������ּ���.");
    }
}
//�Լ��� ���� ����
void result(int selection) {
    int i = selection; //itemN[slection]���� �ϴѱ� %s�ε� �������̶�� �ȵǼ� i�� �������.
    printf("================================\n");
    printf("=[�ֹ��Ͻ� ��ǰ %s ���Խ��ϴ�.]=\n", itemN[i]);
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
        printf("   ���� �־� �ּ��� : ");
        scanf("%d", &money);
        manual(money);
        scanf("%d", &selection);
        if (selection == 0) {
            printf("������ ��带 �����մϴ�.\n");
            admin();
            if (option == 'X' || option == 'x') {
                printf("���Ǳ⸦ �����մϴ�.");
                return 0; //���Ǳ⸦ ����
            }
        }
        else if (1 <= selection <= 10) {
            selection = selection - 1; //��ǰ ��ȣ�� �ε����� �����ϰ� ����.
            selectItem(selection, money);
            result(selection);
            scanf(" %c", &YN);
            if (YN == 'N' || YN == 'n') {
                printf("�ܵ� : %d���Դϴ�.\n", change);
                printf("�̿����ּż� �����մϴ�.");
                return 0;//���Ǳ⸦ ����
            }
            if (YN == 'Y' || YN == 'y') {
                continue; //���Ǳ⸦ ��� �̿�
            }
        }
        else {
            printf("�߸��� �����Դϴ�.");
            return 0;
        }
    }
    return 0;
}
