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
enum Made {
	high,     //0
	pair,     //1
	twopair,  //2
	triple,   //3
	st,       //4
	flush,    //5
	fullhouse,//6 
	fourcard, //7
	st_flush, //8
	rst_flush //9
} MADE;
void print_deck(char d[SUIT][NUM])
{
	int x = 100, y = 5;//Locate
	int i, j;
	for (i = 0; i < SUIT; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			gotoxy(x + 5 * i, y + j);
			switch (i)
			{
			case spade:
				if(!(d[i][j]))
					Color(WHITE, BLACK);
				else
					Color(GRAY, BLACK);
				printf("♠");
				break;
			case diamond:
				if (!(d[i][j]))
					Color(WHITE, RED);
				else
					Color(GRAY, RED);
				printf("◆");
				break;
			case heart:
				if (!(d[i][j]))
					Color(WHITE, RED);
				else
					Color(GRAY, RED);
				printf("♥");
				break;
			case clover:
				if (!(d[i][j]))
					Color(WHITE, BLACK);
				else
					Color(GRAY, BLACK);
				printf("♣");
				break;
			}
			switch (j)
			{
			case Ace://A
				printf("A");
				break;
			case Two://2
			case Three:
			case Four:
			case Five:
			case Six:
			case Seven:
			case Eight:
			case Nine:
				printf("%d", j + 1);
				break;
			case Ten://10
				printf("T");
				break;
			case Jack://J
				printf("J");
				break;
			case Queen://Q
				printf("Q");
				break;
			case King://K
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
void bubble_sort(char* a, int size)
{
	char i, j, tmp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (a[j] < a[j + 1] || a[j] != Ace || a[j + 1] == Ace)
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
int straigt_com(char a[], int size)//9 mountain, 8~0<-straight, -1 <- no straigt
{
	int i, j, k, tmp, count, score;
	char straigt[10][5];
	//initializing straigt
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 5; j++)
		{
			straigt[i][j] = i + j;
		}
	}//i=9
	straigt[i][0] = Ten; straigt[i][1] = Jack; straigt[i][2] = Queen; straigt[i][3] = King; straigt[i][4] = Ace;
	//compare a and straigt
	for (k = 9; k >= 0; k--)
	{
		count = 0;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (straigt[k][i] == a[j])
				{
					count++;
					break;
				}
			}
		}
		if (count >= 5)
		{
			break;
		}
	}//if there is no straigt then k = -1
	return k;
}
int score_cal(int n, char* a)//n: kind of made, a: additional deter
{
	int s_1, s_2;

}
int compare(struct Card* com, struct Card* MY, struct Card* OP)
{
	struct Card s[COMSIZE + HANDSIZE], s_1;
	int i, j, k, score, str;
	char t, n;
	char suitmem[SUIT][COMSIZE + HANDSIZE], suitcount[SUIT] = {0, }, nummem[NUM][COMSIZE + HANDSIZE], numcount[NUM] = {0, }, strmem[COMSIZE + HANDSIZE];
	//Append Hand and Community
	for (i = 0; i < COMSIZE; i++)
	{
		s[i] = *(com + i);
	}
	for (j = 0; j < HANDSIZE; j++)
	{
		s[i + j] = *(MY + j);
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
	//count type and num
	for (i = 0; i < COMSIZE + HANDSIZE; i++)
	{
		t = s[i].type;
		n = s[i].number;
		switch (t)//Get the number of same types
		{
		case spade:
			suitmem[spade][suitcount[spade]] = i;
			suitcount[spade]++;
			break;
		case diamond:
			suitmem[diamond][suitcount[diamond]] = i;
			suitcount[diamond]++;
			break;
		case heart:
			suitmem[heart][suitcount[heart]] = i;
			suitcount[heart]++;
			break;
		case clover:
			suitmem[clover][suitcount[clover]] = i;
			suitcount[clover]++;
			break;
		}
		switch (n)//Get the number of same numbers
		{
		case Ace:
			nummem[Ace][numcount[Ace]] = i;
			numcount[Ace]++;
			break;
		case Two:
			nummem[Two][numcount[Two]] = i;
			numcount[Two]++;
			break;
		case Three:
			nummem[Three][numcount[Three]] = i;
			numcount[Three]++;
			break;
		case Four:
			nummem[Four][numcount[Four]] = i;
			numcount[Four]++;
			break;
		case Five:
			nummem[Five][numcount[Five]] = i;
			numcount[Five]++;
			break;
		case Six:
			nummem[Six][numcount[Six]] = i;
			numcount[Six]++;
			break;
		case Seven:
			nummem[Seven][numcount[Seven]] = i;
			numcount[Seven]++;
			break;
		case Eight:
			nummem[Eight][numcount[Eight]] = i;
			numcount[Eight]++;
			break;
		case Nine:
			nummem[Nine][numcount[Nine]] = i;
			numcount[Nine]++;
			break;
		case Ten:
			nummem[Ten][numcount[Ten]] = i;
			numcount[Ten]++;
			break;
		case Jack:
			nummem[Jack][numcount[Jack]] = i;
			numcount[Jack]++;
			break;
		case Queen:
			nummem[Queen][numcount[Queen]] = i;
			numcount[Queen]++;
			break;
		case King:
			nummem[King][numcount[King]] = i;
			numcount[King]++;
			break;
		}
	}
	//if(flush)
	for (i = 0; i < SUIT; i++)//S, D, H, C
	{
		if (suitcount[i] >= 5)
		{
			printf("FLUSH!!!\n");
			for (j = 0; j < suitcount[i]; j++)
			{
				strmem[j] = s[suitmem[i][j]].number;
			}
			str = straigt_com(strmem, suitcount[i]);
			if (str == -1)
			{
				bubble_sort(strmem, suitcount[i]);
				score = score_cal(flush, strmem);//flush(type:i)
			}
			else if (str == 9)
			{
				printf("ROYAL STRAIGT FLUSH");
				score = score_cal(rst_flush, strmem);
			}
			else
			{
				printf("STRAIGT FLUSH");
				score = score_cal(st_flush, strmem);
			}
		}
	}
	return score;
}

int main()
{
	system("mode con cols=200 lines=50");
	int in_t, in_n, t, n;
	int path, player_num;
	time_t t1, t2;//To get processing time
	struct Card community[COMSIZE], My_Hand[HANDSIZE], op_Hand[HANDSIZE];//
	char deck[SUIT][NUM] = { {0,}, };//[type][number]

player_number://get player num
	printf("Enter the number of Other Players (1~%d) : ", PLAYERMAX);
	scanf("%d", &player_num);

	printf("Entering : ");
	scanf("%d", &path);
	//Enter
	if (path == King)//for debuging
		goto debug;
	else if (player_num > PLAYERMAX || player_num < 1)//confirm if (1 ~ PLAYERMAX)
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
	compare(community, My_Hand, op_Hand);
	t2 = time(NULL);
	printf("%lld", t2 - t1);//Get processing time;
	print_deck(deck);

	gotoxy(0, 48);
	return 0;
}
