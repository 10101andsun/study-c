#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

extern int flag;
extern int count;

int diffcult()
{
	int dif = 0;
	printf("请选择难度\n");
	printf("1.简单/10个地雷\n2.中等/20个地雷\n3.困难/30个地雷\n");
	scanf("%d", &dif);
	return dif;
}

void mis(char are[row + 2][col + 2], int r, int c)
{
	int i = 0;
	for (i = 0; i < row + 2; i++)
	{
		int j = 0;
		for (j = 0; j < col + 2; j++)
		{
			if (i == 0 || i == row + 1)
			{
				char x = j + 48;
				are[i][j] = x;
			}
			else if (j == 0 || j == col + 1)
			{
				char y = i + 48;
				are[i][j] = y;
			}
			else
			    are[i][j] = 'X';
		}
	}
}

void pp(char are[row+2][col+2], int r, int c)
{
	int i = 0;
	for (i = 0; i < row+2; i++)
	{
		int j = 0;
		for (j = 0; j < col+2; j++)
		{
			printf("%c ", are[i][j]);
		}
		printf("\n");
	}
}

int open(int arr[row + 2][col + 2], char are[row + 2][col + 2], int r, int c, int x, int y)
{
	if (are[y][x] == 'X')
	{
		if (arr[y][x] == 9)//开雷游戏结束
		{
			printf("踩到地雷，游戏结束\n");
			flag = 1;//游戏结束标志
			return 0;
		}
		else if (arr[y][x] < 9 && arr[y][x]>0)//数字格继续游戏
		{
			are[y][x] = arr[y][x] + 48;//
			count++;//翻开格子数+1
			return 0;
		}
		else if (arr[y][x] == 0)//0格自动翻开附近格子
		{
			are[y][x] = arr[y][x] + 48;//翻开该格
			count++;//翻开格子数+1
			int i = 0;//检查周围格子
			for (i = -1; i <= 1; i++)
			{
				int j = 0;
				for (j = -1; j <= 1; j++)
				{
					if (y + i < 1 || y + i > row && x + j < 1 || x + j > col)//如果是坐标格，那就跳过//如果是坐标格就检查下一格
					{
					  
					}
					else
					{
						if (are[y + i][x + j] == 'X')//如果没被翻开，那就翻开
							open(arr, are, row, col, x + j, y + i);//打开该格
					}
				}
			}
			return 0;
		}
		else//坐标格跳过
			return 0;
	}
	else
		printf("该格子已翻开，请重新输入\n");
	return 0;
}

void act(int arr[row + 2][col + 2],char are[row+2][col+2], int r, int c)
{
	int a = 0;
	int x = 0;
	int y = 0;
	int o = 0;
	printf("1.翻开  2.标记\n");
	while (1)
	{
		printf("请输入要执行的命令:行动+坐标\n");
		scanf("%d%d%d", &a, &x, &y);
		if (x > 0 && x < col+1 || y>0 && y < row+1 && a == 1 || a == 2)
		{
			if (a == 1)//翻开
			{
				o = open(arr, are, row, col, x, y);
				break;
			}
			else if (are[y][x] == 'X')//标记
			{
				are[y][x] = 'T';
				break;
			}
			else
			{
				are[y][x] = 'X';
				break;
			}
		}
		else
			printf("输入错误\n");
	}
}

int iswin(int r, int c, int d)
{
	if (flag == 1)
	{
		return 1;
	}
	else if (count == col * row - d * 10)
	{
		printf("恭喜你，游戏获胜");
		return 0;
	}
	else
		return 2;
}

void check(int arr[row+2][col+2], int r, int c)
{
	int i = 0;
	for (i = 1; i < row+1; i++)
	{
		int j = 0;
		for (j = 1; j < col+1; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void generate(int arr[row+2][col+2],int r,int c,int d)
{
	int i = 0;
	int x = 0;
	int y = 0;
	for (i = 1; i <= d * 10; i++)//生成地雷 9为雷
	{
		x = rand() % c;
		y = rand() % r;
		if (arr[y+1][x+1] == 0)
			arr[y+1][x+1] = 9;
		else
			i--;
	}
	for (i = 0; i < row+1; i++)//使地雷周围的格子显示数字
	{
		int j = 0;
		for (j = 0; j < col+1; j++)
		{
			if (arr[i][j] >= 9)
			{
				int ii = 0;
				for (ii = -1; ii <= 1; ii++)
				{
					int jj = 0;
					for (jj = -1; jj <= 1; jj++)
					{
						arr[i + ii][j + jj] += 1;
					}
				}
			}
		}
	}
	for (i = 1; i < row + 1; i++)
	{
		int j = 0;
		for (j = 1; j < col + 1; j++)
		{
			if (arr[i][j] > 9)
				arr[i][j] = 9;
		}
	}
}



void menu()
{

	printf("---------------------\n");
	printf("|                   |\n");
	printf("|      1.play       |\n");
	printf("|                   |\n");
	printf("|      2.exit       |\n");
	printf("|                   |\n");
	printf("---------------------\n");
}