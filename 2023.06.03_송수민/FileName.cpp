#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
int battle();
int percentage();
int item();
int work();
void serach();
int bag();

int dmg = 15;   // 사용자 데미지
int hp = 100;   // 사용자 HP
int heal = 0;
int addDmg = 0;

int sword = 0;
int longSword = 0;
int gun = 0;
int working = -10;

int main()
{
	srand(time(NULL));
	while (working < 7)
	{
		
		if (hp < 1) { // 플레이어 사망 
			int die = 0;
			while (die < 5) {
				Sleep(300);
				printf(".\n");
				++die;
			}

			printf("죽었다!! 더는 싸울수없다.\n");
			break;
		}
		

		int i = 0;
		printf("===============================================\n");
		printf("나의 현상태 \nHP: %d 공격력 :%d\n", hp, dmg + addDmg);
		printf("행동선택  1.걷기  2.주변을 살펴보기 3.인벤토리\n");
		printf("===============================================\n");
		scanf_s("%d", &i);
		
			switch (i)
			{
				case 1: // 걷기 선택시
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

			if (i == 1 || i ==2 ||i==3) {
				
			}
			else {
				break;
			}
		
	}

}//main()
int bag() {
	int chack = 0;
	printf("인벤토리 목록 =======================================\n");
	printf("%s ", (sword > 0 )? "1.낡은 검 ,":"");
	printf("%s ", (longSword > 0) ? "2.날카로운 검 ," : "");
	printf("%s ", (gun > 0) ? "3.총" : "");
	printf("\n                   장비하고 싶은 장비번호를 눌러주세요.\n");
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
		printf("근처를 살펴본다\n");
		printf("===============================================\n");
		if (search < 5) {//길로 간다
			printf(" \n");
			printf("약초를 찾아서 먹었다.\n");
			printf("===============================================\n");
			Sleep(300);
			printf("HP를 회복했다!!\n");
			hp = hp + 20;
			
		}
		heal = 1;
	}
	else {
		printf("근처에 아무것도 없다...\n");
		heal = 1;
	}
	
}
int work() {
	heal = 0;
	++working;
	int runing1 = rand() % 10 + 1;
	int runing2 = rand() % 10 + 1;
	if (runing1 > 5) {//산으로 간다
		printf("===============================================\n");
		printf("나는 산으로 갔다. \nHP: %d 공격력 :%d\n", hp, dmg+ addDmg);
		printf("===============================================\n");

		if (runing2 > 6) {// 몬스터 조우 확률
			printf("\n\n");
			printf("                적을 만났다!\n");
			printf("\n\n");

			battle();//전투


		}//몬스터 만남
		else if (runing2 <= 5) {// 아이템 획득 확률
			if (sword > 0 && longSword > 0&& gun > 0) {

			}
			else {
				printf("무언가 반짝인다 !!!!\n");
				item();
			}
			


		}
	}
	else if (runing1 > 7) {//길로 간다
		printf("===============================================\n");
		printf("나는 길로 갔다. \nHP: %d 공격력 :%d\n", hp, dmg + addDmg);
		printf("===============================================\n");
	}
	else if (runing1 >= 10) {//강으로 간다 
		int river = rand() % 10 + 1;
		printf("===============================================\n");
		printf("나는 강으로 갔다. \nHP: %d 공격력 :%d\n", hp, dmg + addDmg);
		printf("===============================================\n");

		if (river > 3) {
			printf("물살에 휩쓸렸다 \n");
			Sleep(300);
			printf("HP를 잃었다......\n");
			hp = hp - 3;
			--working;
		}

	}
	return 0;
}
int battle() 
{
	
	int boos = 150; // 보스 HP
	int ans = 0;
	printf("===============================================\n");
	printf("나의 현상태 \nHP: %d 공격력 :%d\n", hp, dmg + addDmg);
	printf("적의 hp : %d\n", boos);
	printf("행동선택  1.공격  2.도망\n");
	printf("===============================================\n");
	scanf_s("%d", &ans);
	for (int i = 0; i < 500 ; i++)
	{
		printf("===============================================\n");
		printf("나의 현상태 \nHP: %d 공격력 :%d\n", hp, dmg + addDmg);
		printf("적의 hp : %d\n", boos);
		printf("===============================================\n");
		int die = 0;
		int sum = 0;
		srand(time(NULL));// rand함수의 키값을 바꿔즈는 함수 
		// rand() 함수를 사용해서 랜덤 값을 받는다
		if (hp < 1) {
			while(die <5) {
				Sleep(300);
				printf(".\n");
				++die;
			}
			
			printf("죽었다!! 더는 싸울수없다.\n");
			break;
		}

		if (boos < 1) {
			printf("승리하었다!!.\n");
			break;
		}
			

		if (ans == 1) {
			printf("공격!!!!!!!!\n");

			Sleep(500);
			int randomNumber1 = rand() % 15 + 1;
			int randomNumber2 = rand() % 20 + 1;
			int randomNumber3 = rand() % 10 + 1;
			if (randomNumber1 > 4) {
				sum += dmg * 1.5;
				printf("크리티컬! %d데미지!(%d0%%발생|60~100%% 공격발생시 치명타 발생!)\n", sum+ addDmg, randomNumber1);
				Sleep(500);
				boos -= sum + addDmg;
				if (randomNumber3 > 8) {
					printf("적의 공격을 피했다 !\n");
					continue;
				}
				printf("적에게 공격당했다!\n");
				Sleep(500);
				printf("%d 데미지를 먹었다 !\n", randomNumber2);
				Sleep(500);
				hp -= randomNumber2;

			}
			else {
				printf("%d데미지!\n", dmg + addDmg);
				Sleep(500);
				sum += dmg + addDmg;
				boos -= sum + addDmg;
				printf("적에게 공격당했다!\n");
				Sleep(500);
				printf("%d 데미지를 먹었다 !\n", randomNumber2);
				Sleep(500);
				hp -= randomNumber2;

			}
			continue;
		}
		else if (ans == 2) {
			int randomNumber3 = rand() % 30 + 1;
			if (randomNumber3 > 7) {
				printf("도망에 성공했다!\n");
				break;
			}
			else {
				printf("도망에 실패했다!\n");
				printf("적에게 공격당했다!\n");
				printf("%d 데미지를 먹었다 !\n", randomNumber3);
				hp -= randomNumber3;
				ans = 1;
				
			}
			continue;
		}
		printf("자격이 없다 종료");
		break;		
	}
	return 0;
}// 전투 함수 
int item() {
	
	while (true)
	{
		int itemP =percentage();
		printf("%d\n", itemP);
		int num1 = (sword > 0) ? 0 : 7;
		int num2 = (longSword > 0) ? 0 : (sword > 0) ? 0 : 5;
		int num3 = (gun > 0) ? 0 : (longSword > 0) ? 0 : 8;
		if (itemP < num1) {

			printf("===============================================\n");
			printf("낡은 검을 얻었다.!!!\n");
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
			printf("  γ     공격력 : 5 \n");
			printf("===============================================\n");
			sword = 1;

			break;
		}
		else if (itemP < num2) {

			printf("===============================================\n");
			printf("날카로운 검을 얻었다.!!!\n");
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
			printf("  γ     공격력 : 10 \n");
			printf("===============================================\n");
			longSword = 1;
			break;
		}else if (itemP < num3) {

			printf("===============================================\n");
			printf("총을 얻었다.!!!\n");
			printf("   ::         ============                 =   \n");
			printf(" ▶■■■■■■==================================== \n");
			printf("▶     ◀=========[= ]====== ------------      \n");	
			printf("        === /    [= ]                        \n");
			printf("       ===       [= ]                        \n");
			printf("      ===        [= ]       공격력 : 20       \n");
			printf("===============================================\n");
			gun = 1;
			break;
		}
		else {
			printf("유리구슬이다.... 버리자.\n");
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