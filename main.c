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
	printf("\n");
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
int compare(struct Card* com, struct Card* MY, struct Card* OP)
{
	struct Card s_my[COMSIZE + HANDSIZE], s_op[COMSIZE + HANDSIZE];
	int i, j, k, result, str;
	char t, n, made_my, made_op;
	char suitmem_my[SUIT][COMSIZE + HANDSIZE], suitcount_my[SUIT] = {0, }, nummem_my[NUM][COMSIZE + HANDSIZE], numcount_my[NUM] = {0, }, strmem_my[COMSIZE + HANDSIZE], st_my[COMSIZE + HANDSIZE];
	char suitmem_op[SUIT][COMSIZE + HANDSIZE], suitcount_op[SUIT] = { 0, }, nummem_op[NUM][COMSIZE + HANDSIZE], numcount_op[NUM] = { 0, }, strmem_op[COMSIZE + HANDSIZE], st_op[COMSIZE + HANDSIZE];
	//Append Hand and Community(s_my, s_op)
	for (i = 0; i < COMSIZE; i++)
	{
		s_my[i] = *(com + i);
		s_op[i] = *(com + i);
	}
	for (j = 0; j < HANDSIZE; j++)
	{
		s_my[i + j] = *(MY + j);
		s_op[i + j] = *(OP + j);
	}
	//print s_my
	for (k = 0; k < COMSIZE + HANDSIZE; k++)
	{
		i = s_my[k].type;
		j = s_my[k].number;
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
		t = s_my[i].type;
		n = s_my[i].number;
		switch (t)//Get the number of same types
		{
		case spade:
			suitmem_my[spade][suitcount_my[spade]] = i;
			suitcount_my[spade]++;
			break;
		case diamond:
			suitmem_my[diamond][suitcount_my[diamond]] = i;
			suitcount_my[diamond]++;
			break;
		case heart:
			suitmem_my[heart][suitcount_my[heart]] = i;
			suitcount_my[heart]++;
			break;
		case clover:
			suitmem_my[clover][suitcount_my[clover]] = i;
			suitcount_my[clover]++;
			break;
		}
		switch (n)//Get the number of same numbers
		{
		case Ace:
			nummem_my[Ace][numcount_my[Ace]] = i;
			numcount_my[Ace]++;
			break;
		case Two:
			nummem_my[Two][numcount_my[Two]] = i;
			numcount_my[Two]++;
			break;
		case Three:
			nummem_my[Three][numcount_my[Three]] = i;
			numcount_my[Three]++;
			break;
		case Four:
			nummem_my[Four][numcount_my[Four]] = i;
			numcount_my[Four]++;
			break;
		case Five:
			nummem_my[Five][numcount_my[Five]] = i;
			numcount_my[Five]++;
			break;
		case Six:
			nummem_my[Six][numcount_my[Six]] = i;
			numcount_my[Six]++;
			break;
		case Seven:
			nummem_my[Seven][numcount_my[Seven]] = i;
			numcount_my[Seven]++;
			break;
		case Eight:
			nummem_my[Eight][numcount_my[Eight]] = i;
			numcount_my[Eight]++;
			break;
		case Nine:
			nummem_my[Nine][numcount_my[Nine]] = i;
			numcount_my[Nine]++;
			break;
		case Ten:
			nummem_my[Ten][numcount_my[Ten]] = i;
			numcount_my[Ten]++;
			break;
		case Jack:
			nummem_my[Jack][numcount_my[Jack]] = i;
			numcount_my[Jack]++;
			break;
		case Queen:
			nummem_my[Queen][numcount_my[Queen]] = i;
			numcount_my[Queen]++;
			break;
		case King:
			nummem_my[King][numcount_my[King]] = i;
			numcount_my[King]++;
			break;
		}
		t = s_op[i].type;
		n = s_op[i].number;
		switch (t)//Get the number of same types
		{
		case spade:
			suitmem_op[spade][suitcount_op[spade]] = i;
			suitcount_op[spade]++;
			break;
		case diamond:
			suitmem_op[diamond][suitcount_op[diamond]] = i;
			suitcount_op[diamond]++;
			break;
		case heart:
			suitmem_op[heart][suitcount_op[heart]] = i;
			suitcount_op[heart]++;
			break;
		case clover:
			suitmem_op[clover][suitcount_op[clover]] = i;
			suitcount_op[clover]++;
			break;
		}
		switch (n)//Get the number of same numbers
		{
		case Ace:
			nummem_op[Ace][numcount_op[Ace]] = i;
			numcount_op[Ace]++;
			break;
		case Two:
			nummem_op[Two][numcount_op[Two]] = i;
			numcount_op[Two]++;
			break;
		case Three:
			nummem_op[Three][numcount_op[Three]] = i;
			numcount_op[Three]++;
			break;
		case Four:
			nummem_op[Four][numcount_op[Four]] = i;
			numcount_op[Four]++;
			break;
		case Five:
			nummem_op[Five][numcount_op[Five]] = i;
			numcount_op[Five]++;
			break;
		case Six:
			nummem_op[Six][numcount_op[Six]] = i;
			numcount_op[Six]++;
			break;
		case Seven:
			nummem_op[Seven][numcount_op[Seven]] = i;
			numcount_op[Seven]++;
			break;
		case Eight:
			nummem_op[Eight][numcount_op[Eight]] = i;
			numcount_op[Eight]++;
			break;
		case Nine:
			nummem_op[Nine][numcount_op[Nine]] = i;
			numcount_op[Nine]++;
			break;
		case Ten:
			nummem_op[Ten][numcount_op[Ten]] = i;
			numcount_op[Ten]++;
			break;
		case Jack:
			nummem_op[Jack][numcount_op[Jack]] = i;
			numcount_op[Jack]++;
			break;
		case Queen:
			nummem_op[Queen][numcount_op[Queen]] = i;
			numcount_op[Queen]++;
			break;
		case King:
			nummem_op[King][numcount_op[King]] = i;
			numcount_op[King]++;
			break;
		}
	}
my:
	//if(flush)
	for (i = 0; i < SUIT; i++)//S, D, H, C
	{
		if (suitcount_my[i] >= 5)
		{
			for (j = 0; j < suitcount_my[i]; j++)
			{
				strmem_my[j] = s_my[suitmem_my[i][j]].number;
			}
			str = straigt_com(strmem_my, suitcount_my[i]);
			if (str == -1)//flush
			{
				printf("FLUSH!!!\n");
				made_my = flush;
				goto op;
			}
			else if (str == 9)//royal straigt flush
			{
				printf("ROYAL STRAIGT FLUSH\n");
				made_my = rst_flush;
				goto op;
			}
			else//straigt flush
			{
				printf("STRAIGT FLUSH\n");
				made_my = st_flush;
				goto op;
			}
		}
	}
	//if(straigh)
	k = 0;
	for (i = 0; i < NUM; i++)
	{
		if (numcount_my[i] > 0)
		{
			st_my[k] = i;
			k++;
		}
	}
	if (k >= 5)
	{
		str = straigt_com(st_my, k);
		if (str != -1)
		{
			printf("STRAIGT!");
			made_my = st;
			goto op;
		}
	}
	//if(Four of a kind)
	for (i = 0; i < NUM; i++)
	{
		if (numcount_my[i] == 4)
		{
			made_my = fourcard;
			goto op;
		}
	}
	//if(Fullhouse, triple, twopair, onepair)
	j = k = 0;
	for (i = 0; i < NUM; i++)
	{
		if (numcount_my[i] == 3 && j == 0)
		{
			j++;
		}
		if (numcount_my[i] == 2 && k <= 1)
		{
			k++;
		}
	}
	if (j == 1 && k >= 1)//fh
	{
		made_my = fullhouse;
		goto op;
	}
	else if (j == 1 && k == 0)
	{
		made_my = triple;
		goto op;
	}
	else if (j == 0 && k == 2)
	{
		made_my = twopair;
		goto op;
	}
	else if (j == 0 && k == 1)
	{
		made_my = pair;
		goto op;
	}
	else
		made_my = high;
op:
	//if(flush)
	for (i = 0; i < SUIT; i++)//S, D, H, C
	{
		if (suitcount_op[i] >= 5)
		{
			for (j = 0; j < suitcount_op[i]; j++)
			{
				strmem_op[j] = s_op[suitmem_op[i][j]].number;
			}
			str = straigt_com(strmem_op, suitcount_op[i]);
			if (str == -1)//flush
			{
				printf("FLUSH!!!\n");
				made_op = flush;
				goto result;
			}
			else if (str == 9)//royal straigt flush
			{
				printf("ROYAL STRAIGT FLUSH\n");
				made_op = rst_flush;
				goto result;
			}
			else//straigt flush
			{
				printf("STRAIGT FLUSH\n");
				made_op = st_flush;
				goto result;
			}
		}
	}
	//if(straigh)
	k = 0;
	for (i = 0; i < NUM; i++)
	{
		if (numcount_op[i] > 0)
		{
			st_op[k] = i;
			k++;
		}
	}
	if (k >= 5)
	{
		str = straigt_com(st_op, k);
		if (str != -1)
		{
			printf("STRAIGT!");
			made_op = st;
			goto result;
		}
	}
	//if(Four of a kind)
	for (i = 0; i < NUM; i++)
	{
		if (numcount_op[i] == 4)
		{
			made_op = fourcard;
			goto result;
		}
	}
	//if(Fullhouse, triple, twopair, onepair)
	j = k = 0;
	for (i = 0; i < NUM; i++)
	{
		if (numcount_op[i] == 3 && j == 0)
		{
			j++;
		}
		if (numcount_op[i] == 2 && k <= 1)
		{
			k++;
		}
	}
	if (j == 1 && k >= 1)//fh
	{
		made_op = fullhouse;
		goto result;
	}
	else if (j == 1 && k == 0)
	{
		made_op = triple;
		goto result;
	}
	else if (j == 0 && k == 2)
	{
		made_op = twopair;
		goto result;
	}
	else if (j == 0 && k == 1)
	{
		made_op = pair;
		goto result;
	}
	else
		made_op = high;
result:
	if (made_op > made_my)
		result = -1;
	else if (made_op < made_my)
		result = 1;
	else
	{
		result = 0;
		switch (made_my)
		{
		case 9:
			break;
		}
	}

	return result;
}

int main()
{
	system("mode con cols=200 lines=50");
	CONSOLE_SCREEN_BUFFER_INFO presentCur;
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
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
M2:
	printf("Enter your hand (2nd)\n");
	get_card(&in_t, &in_n);
	My_Hand[1].type = in_t;
	My_Hand[1].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
C1:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[0].type = in_t;
	community[0].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
C2:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[1].type = in_t;
	community[1].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
C3:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[2].type = in_t;
	community[2].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
C4:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[3].type = in_t;
	community[3].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
C5:
	printf("Enter your community\n");
	get_card(&in_t, &in_n);
	community[4].type = in_t;
	community[4].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
O1:
	printf("Enter oppent's hand (1st)\n");
	get_card(&in_t, &in_n);
	op_Hand[0].type = in_t;
	op_Hand[0].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
O2:
	printf("Enter oppent's hand (2nd)\n");
	get_card(&in_t, &in_n);
	op_Hand[1].type = in_t;
	op_Hand[1].number = in_n;
	deck[in_t][in_n] = 1;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	print_deck(deck);
	gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);

	t1 = time(NULL);
	compare(community, My_Hand, op_Hand);
	t2 = time(NULL);
	printf("%lld", t2 - t1);//Get processing time;

	gotoxy(0, 48);
	return 0;
}
