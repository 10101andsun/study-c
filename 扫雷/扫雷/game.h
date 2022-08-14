#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define row 9
#define col 9

void pp(char are[row + 2][col + 2], int r, int c);//打印雷区
void mis(char are[row+2][col+2],int r,int c);//生成遮挡雷区
void menu();//生成菜单
void start();//游戏程序
void generate(int arr[row+2][col+2], int r, int c, int d);//生成雷区
int diffcult();//选择难度
void check(int arr[row+2][col+2], int r, int c);//检查全部雷区
void act(int arr[row + 2][col + 2],char are [row+2][col+2], int r, int c);//玩家行动
int iswin(int r,int c,int d);
int open (int arr[row + 2][col + 2], char are[row + 2][col + 2], int r, int c,int x, int y);//玩家行动
