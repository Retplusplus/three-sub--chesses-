#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
#define r 3
#define l 3
int a = 0;
//int ret = 0;

void init(char arr[r][l])
{
	int i;
	for (i = 0; i < r; i++)
	{
		for (int j = 0; j < l; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

 static void Menu()
{
	
	printf("###################\n");
	printf("##1,play   2,exit##\n");
	printf("###################\n");
	printf("1 or 2:");
	scanf("%d", &a);
}
void ShowBoard(char arr[][l])
{
	//assert(arr);
	for (int i = 0; i < 3; i++)
	{
		printf("  %c| %c| %c\n",arr[i][0],arr[i][1],arr[i][2]);
		if (i < 2)
		{
			printf(" -- -- --\n");
		}
	}
}

//void is_win(int arr[][l])
//{
//	for (int i = 0; i < r; i++)
//	{
//		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == '0' || \
//			arr[1][i] == arr[2][i] && arr[1][i] == arr[3][i] && arr[1][i] == '0' || \
//			arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == '0'||\
//			arr[0][3]==arr[1][1]&&arr[1][1]==arr[2][0]&&arr[1][1]=='0')
//		{
//			printf("you win!\n");
//		}
//	}
//	for (int i = 0; i < r; i++)
//	{
//		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == 'x' || \
//			arr[1][i] == arr[2][i] && arr[1][i] == arr[3][i] && arr[1][i] == 'x' || \
//			arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == 'x' || \
//			arr[0][3] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] == 'x')
//		{
//			printf("you fail!\n");
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < l; j++)
//		{
//			if (arr[i][j] != ' ')
//			{
//				count++;
//			}
//		}
//	}
//	if (count == 9)
//	{
//		printf("平局");
//	}
//}

void player(char arr[][l])
{
	int x=0, y=0;
	//ShowBoard(arr);
	while (1)
	{
		printf("please input>:");
		scanf("%d%d", &x, &y);
		if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
		{
			if (arr[x][y] == ' ')
			{
				arr[x][y] = 'x';
				break;
			}
			else
			{
				printf("该位置被占,请重输\n");
			}
		}
		else
		{
			printf("该位置无效,请重输\n");
		}
	}
}

int check_full(char arr[r][l])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

void computer(char arr[r][l])
{
	srand((unsigned int)time(NULL));
	while(1)
	{
		int x = rand() % 3;
		int y = rand() % 3;		
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '0';
			break;
		}
		else
		{
			if (check_full(arr) == 0)
			{
				continue;
			}
			else
			{
				
				break;
			}
		}
	}
}

char check_win(char arr[r][l])
{
	int i;
	int ret = check_full(arr);
	//if(ret==1)
	//{
	//	return 'q';
	//}
	for (i = 0; i < r; i++)
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < l; i++)
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
		{
			return arr[0][i];
		}
	}
	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
	{
		return arr[0][0];
	}
	if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
	{
		return arr[1][1];
	}

	if (ret == 1)
	{
		return 'q';
	}
	return ' ';
}

void Game()
{
	
	char arr[r][l] = { 0 };
	char ret = 0;
	init(arr);
	while (ret=' ')
	{
		ShowBoard(arr);
		computer(arr);
		ShowBoard(arr);
		if ((ret=check_win(arr)) != ' ')
		{
			break;
		}	
		player(arr);
		if ((ret = check_win(arr)) != ' ')
		{
			break;
		}
		ret = check_win(arr);
		//is_win(arr);
	}
	ShowBoard(arr);

	if (ret == 'x')
	{
		printf("you win!\n");
	}
	else if(ret=='0')
	{
		printf("you fail\n");
	}
	else if (ret == 'q')
	{
		printf("平局\n");
	}



}

int main()
{
	//int a=0;
	Menu();
	switch (a)
	{
	case 1:
		Game();
		break;
	case 2:
		exit(0);
		break;
	default:
		break;
	}
	return 0;
}