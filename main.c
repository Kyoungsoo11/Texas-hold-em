#include "header.h"

struct Card
{
	char type; //0 ~ 3, 0♠, 1◆, 2♥, 3♣ (SDHC)
	char number;//0 ~ 12, 0 = A, 12 = K
};

int main()
{
	char input_t, input_n;
	int player_num;
	struct Card community[5], My_Hand[2], OPP[2 * PLAYERMAX];//18 = 2(hand) * PLAYERMAX(max player number)
	char deak[4][13];//[type][number]

player_number:
	player_num = 0;
	printf("Enter the number of Other Players (1~%d) : ", PLAYERMAX);
	scanf("%d", &player_num);

	if (player_num > PLAYERMAX || player_num < 1)//confirm if (1 ~ PLAYERMAX)
	{
		printf("Wrong number!\n");
		goto player_number;
	}
Pre_flop:
	printf("Enter your hand (1st) : ");
	scanf("%hhd %hhd", &input_t, &input_n);
	My_Hand[0].type = input_t;
	My_Hand[0].number = input_n;
	printf("Enter your hand (2nd) : ");
	scanf("%hhd %hhd", &input_t, &input_n);
	My_Hand[1].type = input_t;
	My_Hand[1].number = input_n;
Flop:
	printf("Enter 1st Flop : ");
	scanf("%hhd %hhd", &input_t, &input_n);
	community[0].type = input_t;
	community[0].number = input_n;
	printf("Enter 2nd Flop : ");
	scanf("%hhd %hhd", &input_t, &input_n);
	community[1].type = input_t;
	community[1].number = input_n;
	printf("Enter 3rd Flop : ");
	scanf("%hhd %hhd", &input_t, &input_n);
	community[2].type = input_t;
	community[2].number = input_n;


	return 0;
}
