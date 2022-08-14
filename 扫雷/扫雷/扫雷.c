#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int count = 0;
int flag = 0;

void start()
{
	int arr[row+2][col+2] = { 0 };
	char are[row+2][col+2] = { 0 };
	int d = diffcult();
	int win = 0;
	generate(arr, row, col,d);//生成雷区
	printf("游戏开始\n");
	check(arr, row, col);
	mis(are,row,col);//埋雷
	pp(are,row,col);//打印雷区
	while (1)
	{
		act(arr, are, row, col);//玩家行动
		win = iswin(row, col, d);//判断胜负
		if (win == 1 || win == 0)
			break;
		pp(are, row, col);//打印雷区
	}
}


int main()
{
	int n = 0;
	srand((unsigned int)time(NULL));
	menu();//菜单/选择
	while (1)
	{
		printf("请选择");
		scanf("%d", &n);
		if (1 == n)
		{
			start();
			break;
		}
		else if (n != 2)
			printf("输入错误，请重新输入");
		else
			printf("退出游戏");
	}
	return 0;
}