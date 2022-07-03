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
enum type {
	spade,     //0
	diamond,   //1
	heart,     //2
	clover     //3
} TYPE;
enum number {
	Ace,   //0
	Two,   //1
	Three, //2
	Four,  //3
	Five,  //4
	Six,   //5
	Seven, //6
	Eight, //7
	Nine,  //8
	Ten,   //9
	Jack,  //10
	Queen, //11
	King   //12
} NUMBER;
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
void get_card(int* t, int* n)
{
	char type, number;
	printf("Type : ");
	type = _getche();
	printf("\n");
	printf("Number : ");
	number = _getche();
	printf("\n");
	switch (type)
	{
	case 'S':
		*t = spade;
		break;
	case 'D':
		*t = diamond;
		break;
	case 'H':
		*t = heart;
		break;
	case 'C':
		*t = clover;
		break;
	}
	switch (number)
	{
	case 'A':
	case '1':
		*n = Ace;
		break;
	case '2':
		*n = Two;
		break;
	case '3':
		*n = Three;
		break;
	case '4':
		*n = Four;
		break;
	case '5':
		*n = Five;
		break;
	case '6':
		*n = Six;
		break;
	case '7':
		*n = Seven;
		break;
	case '8':
		*n = Eight;
		break;
	case '9':
		*n = Nine;
		break;
	case 'T':
		*n = Ten;
		break;
	case 'J':
		*n = Jack;
		break;
	case 'Q':
		*n = Queen;
		break;
	case 'K':
		*n = King;
		break;
	}
	printf("%d %d\n", *t, *n);
	printf("\n");
	
}
void calculate(struct Card* s)
{
	int i;
	//Royal Straigt Flush
	for (i = 0; i < 7; i++)
	{

	}
	//Straigt Flush
}
int main()
{
	int in_t, in_n, t, n;
	int path, player_num;
	struct Card community[5], My_Hand[2];//
	char deck[4][13] = { {0}, };//[type][number]

player_number://get player num
	printf("Enter the number of Other Players (1~%d) : ", PLAYERMAX);
	scanf("%d", &player_num);

	printf("Entering : ");
	scanf("%d", &path);
	//Enter
	if (path == King)//for debuging
		goto debug;
	else if (path > PLAYERMAX || path < 1)//confirm if (1 ~ PLAYERMAX)
	{
		printf("Wrong input!\n");
		goto player_number;
	}

debug:
M1:
	printf("Enter your hand (1st)\n");
	get_card(&in_t, &in_n);
	My_Hand[0].type = in_t;
	My_Hand[0].number = in_n;
	deck[in_t][in_n] = 1;
M2:
	printf("Enter your hand (2nd)\n");
	get_card(&in_t, &in_n);
	My_Hand[1].type = in_t;
	My_Hand[1].number = in_n;
	deck[in_t][in_n] = 1;

	print_deck(deck);
	return 0;
}
