#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int battle(int boostype);
int percentage();
int item();
int work();
void serach();
int bag();

int dmg = 15;   // ����� ������
int hp = 100;   // ����� HP
int heal = 0;	
int addDmg = 0;

int sword = 0;
int longSword = 0;
int gun = 0;
int working = 1;

int main()
{
	int last = 0;
	srand(time(NULL));
	while (working < 7)
	{
		
		if (hp < 1) { // �÷��̾� ��� 
			int die = 0;
			while (die < 5) {
				Sleep(300);
				printf(".\n");
				++die;
			}

			printf("�׾���!! ���� �ο������.\n");
			break;
		}
	
		

		int i = 0;
		printf("===============================================\n");
		printf("���� ������ \nHP: %d ���ݷ� :%d\n", hp, dmg + addDmg);
		printf("�ൿ����  1.�ȱ�  2.�ֺ��� ���캸�� 3.�κ��丮\n");
		printf("===============================================\n");
		scanf_s("%d", &i);
		
			switch (i)
			{
				case 1: // �ȱ� ���ý�
					work();
				break;

				
				case 2 :
					serach();
				break;

				case 3 : 
					bag();
				break;
				
			}
			
			if (hp < 0) {
				break;
			}
			if (working == 6) {
				printf("==============���ڱ� ������ ���� ������========\n");

				last == battle(3);
				printf("==============������ ������===================\n");
				break;
			}
			if (i == 1 || i ==2 ||i==3) {
				
			}
			else {
				printf("����ؼ� �׾���ȴ�..........");
				break;
			}
		
	}

}//main()
int bag() {
	int chack = 0;
	printf("�κ��丮 ��� =======================================\n");
	printf("%s ", (sword > 0 )? "1.���� �� ,":"");
	printf("%s ", (longSword > 0) ? "2.��ī�ο� �� ," : "");
	printf("%s ", (gun > 0) ? "3.��" : "");
	printf("\n                   ����ϰ� ���� ����ȣ�� �����ּ���.\n");
	printf("=====================================================\n");
	scanf_s("%d", &chack);
	
	switch (chack)
	{
	case 1: 
		sword = 3;
		addDmg = 5;
	break;
	case 2:
		longSword = 3;
		addDmg = 10;
	break;
	case 3:
		gun = 3;
		addDmg = 20;
		break;
	default:
		break;
	}
	return 0;

}
void serach() {
	int search = rand() % 10 + 1;
	if (heal == 0) {
		printf("��ó�� ���캻��\n");
		printf("===============================================\n");
		if (search < 5) {//��� ����
			printf(" \n");
			printf("���ʸ� ã�Ƽ� �Ծ���.\n");
			printf("===============================================\n");
			Sleep(300);
			printf("HP�� ȸ���ߴ�!!\n");
			hp = hp + 20;
			
		}
		heal = 1;
	}
	else {
		printf("��ó�� �ƹ��͵� ����...\n");
		heal = 1;
	}
	
}
int work() {
	heal = 0;
	++working;
	int runing1 = rand() % 10 + 1;
	int runing2 = rand() % 10 + 1;
	if (runing1 <= 5) {//������ ����
		printf("===============================================\n");
		printf("���� ������ ����. \nHP: %d ���ݷ� :%d\n", hp, dmg+ addDmg);
		printf("===============================================\n");

		if (runing2 > 6) {// ���� ���� Ȯ��
			printf("\n\n");
			printf("                ���� ������!\n");
			printf("\n\n");

			battle(0);//����


		}//���� ����
		else if (runing2 <= 5) {// ������ ȹ�� Ȯ��
			if (sword > 0 && longSword > 0&& gun > 0) {

			}
			else {
				printf("���� ��¦�δ� !!!!\n");
				item();
			}
			


		}
	}
	else if (runing1 >= 6) {//��� ����
		printf("===============================================\n");
		printf("���� ��� ����. \nHP: %d ���ݷ� :%d\n", hp, dmg + addDmg);
		printf("===============================================\n");
	}
	else if (runing1 >= 8) {//������ ���� 
		int river = rand() % 10 + 1;
		printf("===============================================\n");
		printf("���� ������ ����. \nHP: %d ���ݷ� :%d\n", hp, dmg + addDmg);
		printf("===============================================\n");

		if (river > 3) {
			printf("���쿡 �۾��ȴ� \n");
			Sleep(300);
			printf("HP�� �Ҿ���......\n");
			hp = hp - 3;
			--working;
		}

	}
	return 0;
}
int battle(int boostype) 
{
	int good = 0;
	int boos = 150+(boostype*5); // ���� HP
	int ans = 0;
	printf("===============================================\n");
	printf("���� ������ \nHP: %d ���ݷ� :%d\n", hp, dmg + addDmg);
	printf("%s�� hp : %d\n",(boostype == 0)? "���": "�߽���",boos);
	printf("�ൿ����  1.����  2.����\n");
	printf("===============================================\n");
	scanf_s("%d", &ans);
	for (int i = 0; i < 500 ; i++)
	{
		printf("===============================================\n");
		printf("���� ������ \nHP: %d ���ݷ� :%d\n", hp, dmg + addDmg);
		printf("���� hp : %d\n", boos);
		printf("===============================================\n");
		int die = 0;
		int sum = 0;
		
		srand(time(NULL));// rand�Լ��� Ű���� �ٲ���� �Լ� 
		// rand() �Լ��� ����ؼ� ���� ���� �޴´�
		if (hp < 1) {
			while(die <5) {
				Sleep(300);
				printf(".\n");
				++die;
			}
			
			printf("�׾���!! ���� �ο������.\n");
			break;
		}

		if (boos < 1) {
			printf("�¸��Ͼ���!!.\n");
			break;
			if (boostype  != 0 ) {
				printf("������ ���������� ������ �Ͽ���!!.\n");
				good = 1;
				break;
			}
		}
		



		if (ans == 1) {
			printf("����!!!!!!!!\n");

			Sleep(500);
			int randomNumber1 = rand() % 15 + 1;
			int randomNumber2 = rand() % 20 + 1;
			int randomNumber3 = rand() % 10 + 1;
			if (randomNumber1 > 4) {
				sum += dmg * 1.5;
				printf("ũ��Ƽ��! %d������!(%d0%%�߻�|60~100%% ���ݹ߻��� ġ��Ÿ �߻�!)\n", sum+ addDmg, randomNumber1);
				Sleep(500);
				boos -= sum + addDmg;
				if (randomNumber3 > 8) {
					printf("���� ������ ���ߴ� !\n");
					continue;
				}
				printf("������ ���ݴ��ߴ�!\n");
				Sleep(500);
				printf("%d �������� �Ծ��� !\n", randomNumber2);
				Sleep(500);
				hp -= randomNumber2;

			}
			else {
				printf("%d������!\n", dmg + addDmg);
				Sleep(500);
				sum += dmg + addDmg;
				boos -= sum + addDmg;
				printf("������ ���ݴ��ߴ�!\n");
				Sleep(500);
				printf("%d �������� �Ծ��� !\n", randomNumber2);
				Sleep(500);
				hp -= randomNumber2;

			}
			continue;
		}
		else if (ans == 2) {
			int randomNumber3 = rand() % 10 + 1;
			if (randomNumber3 > 7) {
				printf("������ �����ߴ�!\n");
				break;
			}
			else {
				printf("������ �����ߴ�!\n");
				printf("������ ���ݴ��ߴ�!\n");
				printf("%d �������� �Ծ��� !\n", randomNumber3);
				hp -= randomNumber3;
				ans = 1;
				
			}
			continue;
		}
		printf("�ڰ��� ���� ����");
		break;		
	}
	return good;
}// ���� �Լ� 
int item() {
	
	while (true)
	{
		int itemP =percentage();
		printf("%d\n", itemP);
		int num1 = (sword > 0) ? 11 : 2;
		int num2 = (longSword > 0) ? 11: (sword > 0) ? 2:4;
		int num3 = (gun > 0) ? 11 : (longSword > 0) ? 4: 8;
		printf("%d\n", num1);
		if (itemP > num1) {

			printf("===============================================\n");
			printf("���� ���� �����.!!!\n");
			printf("  ::    \n");
			printf("  ::     \n");
			printf("  ::     \n");
			printf("======    \n");
			printf(" | |      \n");
			printf(" | |     \n");
			printf(" | |     \n");
			printf(" | |     \n");
			printf(" | |     \n");
			printf(" |<     \n");
			printf(" | |    \n");
			printf("  ��     ���ݷ� : 5 \n");
			printf("===============================================\n");
			sword = 1;

			break;
		}
		else if (itemP > num2) {

			printf("===============================================\n");
			printf("��ī�ο� ���� �����.!!!\n");
			printf("   ::      \n");
			printf("   ::      \n");
			printf("   ::      \n");
			printf("=======    \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |   |     \n");
			printf(" |  /      \n");
			printf("  ��     ���ݷ� : 10 \n");
			printf("===============================================\n");
			longSword = 1;
			break;
		}else if (itemP > num3) {

			printf("===============================================\n");
			printf("���� �����.!!!\n");
			printf("   ::         ============                 =   \n");
			printf(" ���������==================================== \n");
			printf("��     ��=========[= ]====== ------------      \n");	
			printf("        === /    [= ]                        \n");
			printf("       ===       [= ]                        \n");
			printf("      ===        [= ]       ���ݷ� : 20       \n");
			printf("===============================================\n");
			gun = 1;
			break;
		}
		else {
			printf("���������̴�.... ������.\n");
			break;
		}


		
	}
	return 0;
}
int percentage() {
	srand(time(NULL));
	int itemP = rand() % 10 + 1;
	return itemP;
}