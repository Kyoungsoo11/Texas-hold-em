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
	int x = 100, y = 5;//Locate
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
}
int calculate(struct Card* com, struct Card* hand)
{
	struct Card s[COMSIZE + HANDSIZE];
	int i, j, k;
	char t, n;
	char Scount, Smem[COMSIZE + HANDSIZE], Dcount, Dmem[COMSIZE + HANDSIZE], Hcount, Hmem[COMSIZE + HANDSIZE], Ccount, Cmem[COMSIZE + HANDSIZE];
	//Compound hand and community
	for (i = 0; i < COMSIZE; i++)
	{
		s[i] = *(com + i);
	}
	for (j = 0; j < HANDSIZE; j++)
	{
		s[i + j] = *(hand + j);
	}
	//print s
	for (k = 0; k < COMSIZE + HANDSIZE; k++)
	{
		i = s[k].type;
		j = s[k].number;
		switch (i)
		{
		case 0:
			Color(WHITE, BLACK);
			printf("♠");
			break;
		case 1:
			Color(WHITE, RED);
			printf("◆");
			break;
		case 2:
			Color(WHITE, RED);
			printf("♥");
			break;
		case 3:
			Color(WHITE, BLACK);
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
		Color(BLACK, WHITE); printf(" ");
	}
	//Flush
	Scount = Dcount = Hcount = Ccount = 0;
	for (i = 0; i < COMSIZE + HANDSIZE; i++)
	{
		t = s[i].type;
		switch (t)
		{
		case spade:
			Smem[Scount] = i;
			Scount++;
			break;
		case diamond:
			Dmem[Dcount] = i;
			Dcount++;
			break;
		case heart:
			Hmem[Hcount] = i;
			Hcount++;
			break;
		case clover:
			Cmem[Ccount] = i;
			Ccount++;
			break;
		}
	}
	if (Scount >= 5 || Dcount >= 5 || Hcount >= 5 || Ccount >= 5)
	{
		printf("flush!!");
	}
	return 0;
}
int main()
{
	system("mode con cols=200 lines=50");
	int in_t, in_n, t, n;
	int path, player_num;
	time_t t1, t2;//To get processing time
	struct Card community[COMSIZE], My_Hand[HANDSIZE];//
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
C1:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[0].type = in_t;
	community[0].number = in_n;
	deck[in_t][in_n] = 1;
C2:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[1].type = in_t;
	community[1].number = in_n;
	deck[in_t][in_n] = 1;
C3:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[2].type = in_t;
	community[2].number = in_n;
	deck[in_t][in_n] = 1;
C4:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[3].type = in_t;
	community[3].number = in_n;
	deck[in_t][in_n] = 1;
C5:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[4].type = in_t;
	community[4].number = in_n;
	deck[in_t][in_n] = 1;

	t1 = time(NULL);
	calculate(community, My_Hand);
	t2 = time(NULL);
	printf("%lld", t2 - t1);//Get processing time;
	print_deck(deck);

	gotoxy(0, 48);
	return 0;
}
