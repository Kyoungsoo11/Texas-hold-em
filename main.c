#include "header.h"

struct Card
{
	char type; //0 ~ 3, 0♠, 1◆, 2♥, 3♣ (SDHC)
	char number;//0 ~ 12, 0 = A, 12 = K
};
enum ColorType {
	BLACK,  	//0
	DARKBLUE,	//1
	DARKGREEN,	//2
	DARKSKYBLUE,//3
	DARKRED,  	//4
	DARKPURPLE,	//5
	DARKYELLOW,	//6
	GRAY,		//7
	DARKGRAY,	//8
	BLUE,		//9
	GREEN,		//10
	SKYBLUE,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE		//15
} COLOR;
void print_deck(char d[4][13])
{
	int x = 70, y = 1;//Locate
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 13; j++)
		{
			gotoxy(x + 5 * i, y + j);
			switch (i)
			{
			case 0:
				if(!(d[i][j]))
					Color(WHITE, BLACK);
				else
					Color(GRAY, BLACK);
				printf("♠");
				break;
			case 1:
				if (!(d[i][j]))
					Color(WHITE, RED);
				else
					Color(GRAY, RED);
				printf("◆");
				break;
			case 2:
				if (!(d[i][j]))
					Color(WHITE, RED);
				else
					Color(GRAY, RED);
				printf("♥");
				break;
			case 3:
				if (!(d[i][j]))
					Color(WHITE, BLACK);
				else
					Color(GRAY, BLACK);
				printf("♣");
				break;
			}
			switch (j)
			{
			case 0://A
				printf("A");
				break;
			case 1://2
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				printf("%d", j + 1);
				break;
			case 9://10
				printf("T");
				break;
			case 10://J
				printf("J");
				break;
			case 11://Q
				printf("Q");
				break;
			case 12://K
				printf("K");
				break;
			}
			Color(BLACK, WHITE);
		}
	}
}
int main()
{
	char input_t, input_n, t, n;
	int player_num;
	struct Card community[5], My_Hand[2], OPP[2 * PLAYERMAX];//18 = 2(hand) * PLAYERMAX(max player number)
	char deck[4][13] = { {0}, };//[type][number]

player_number://get player num
	player_num = 0;
	printf("Enter the number of Other Players (1~%d) : ", PLAYERMAX);
	scanf("%d", &player_num);
	if (player_num == 16)
		goto debug;
	else if (player_num > PLAYERMAX || player_num < 1)//confirm if (1 ~ PLAYERMAX)
	{
		printf("Wrong input!\n");
		goto player_number;
	}

debug:
	printf("Enter your hand (1st) : ");
	scanf("%hhd %hhd", &input_t, &input_n);
	My_Hand[0].type = input_t;
	My_Hand[0].number = input_n;
	deck[input_t][input_n] = 1;


	printf("Enter your hand (2nd) : ");
	scanf("%hhd %hhd", &input_t, &input_n);
	My_Hand[1].type = input_t;
	My_Hand[1].number = input_n;
	deck[input_t][input_n] = 1;

	print_deck(deck);

	return 0;
}
