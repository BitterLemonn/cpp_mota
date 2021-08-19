﻿#include<bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#pragma comment(lib,"winmm.lib")

#define stars "\t**************************"

using namespace std;

extern void start();
extern void printmap(char map[10][26], int level);
extern int move(char map[][26], int& i, int& j, int level);
extern struct attribute { int blood = 10000; int attarct = 5000; int defence = 3500; int gold = 0; }playeratt;
extern void rebag();
int level = 0;

extern void lcontrol(char input, int& level, int& i, int& j, int& p, int& save1, int& save2, int& xl, int& flag);
extern void loadscreen(int& level, int& i, int& j, int& flag);


int music = 1;         //定义音乐开关
string mp = "\0";      //定义当前音乐
extern int save1, save2;

//下图为地图(可改动)

char map0[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','d','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','H','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','>',' ',' ',' ','<','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','Z',' ','@',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'}
};

char map1[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ','*','k','o','o',' ','*','*',' ',' ',' ',' ',' ','*','K','g','*',' ',' ','=',' ','e','G','*'},
 {'*',' ','G','*','*','*',' ',' ','*','*',' ',' ',' ',' ',' ','*','%','k','*',' ',' ','*',' ','o','k','*'},
 {'*','G',' ','e',' ',' ',' ',' ','*','*',' ','X','X','X',' ','*','n','G','*',' ',' ','*','*','*','*','*'},
 {'*','*','=','*','*','*',' ','*','*','*',' ','X','d','X',' ','*','G','*','*',' ',' ','*','k','%','K','*'},
 {'*','n','n','g',' ','*',' ',' ',' ','o',' ','X',' ','X',' ','*','|','*',' ',' ',' ','*','G','n','G','*'},
 {'*','6','n','G','i','*',' ',' ','*','*',' ','*','i','*',' ','i','n','*',' ','*','*','*','*','-','*','*'},
 {'*','*','*','*','=','*',' ',' ','o','o',' ',' ',' ',' ',' ','*','*','*',' ','*','K','i',' ','i','G','*'},
 {'*','k','i',' ',' ',' ',' ',' ','*','*','e',' ',' ',' ',' ','e',' ',' ',' ','-','e','*',' ',' ','o','*'},
 {'*','G','i',' ',' ',' ','*','*','*','*','k','e',' ',' ',' ','e',' ',' ',' ','*','g','e','G','o','#','*'}
};

char map2[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*','%','g',' ',' ',' ',' ','n',' ',' ','G','G','i',' ',' ',' ','*','k','m',' ',' ','*','#','k',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ','n',' ',' ','g','i',' ',' ',' ',' ','*','G','*','g','n','*','m','*',' ','*'},
 {'*','n','*','*','*','-','*','-','*','*','*','X','X','X','G','i','*','g','*','-','-','*','n','*','#','*'},
 {'*',' ','*',' ','n','i','n','n','K','n',' ','X','u','X','n',' ','*','*','*',' ',' ','=','i','n','m','*'},
 {'*',' ','*','*',' ','*','i','*','n','#',' ','X',' ','X',' ',' ','*','n','i',' ','g','*','*','=','*','*'},
 {'*',' ',' ','*','=','*','%','*',' ','G','*','e',' ','e','*',' ','*',' ','n','#','G','-','g','n','m','*'},
 {'*',' ',' ','*','G','*','g','*',' ','g','*','*','-','*','*',' ','*','=','*','*','*','*','n','*','K','*'},
 {'*','X',' ','X','#','*','n','=',' ',' ',' ','*',' ','n','g',' ',' ',' ',' ',' ',' ','*','m','*','G','*'},
 {'*','X','d','X','K','*','g','*',' ',' ',' ','*',' ',' ','i',' ',' ',' ',' ',' ',' ','*','g',' ','g','*'}
};

char map3[10][26] =
{
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','K',' ','*',' ','#','*','*','%','*',' ',' ','*','%','#','K','m',' ','m',' ',' ','*',' ',' ','X','X'},
	{'*','g','G','*','m','m','*','*',' ','*','m','K','*','p','m','G','*',' ',' ',' ',' ','*',' ',' ',' ','d'},
	{'*',' ','G','n',' ',' ','*','*',' ','*','-','*','*','=','*','*','*','*','*',' ','G','m',' ',' ','X','X'},
	{'*','*','*','*',' ','m',' ',' ','m',' ',' ',' ',' ',' ','*','*','*','*','*',' ','G','*','*','*','*','*'},
	{'*',' ',' ','*',' ','m',' ',' ','m',' ',' ',' ',' ',' ',' ',' ',' ',' ','m',' ',' ','*','G','m',' ','*'},
	{'*',' ',' ',' ',' ',' ','*','*','*','|','*','*','*',' ',' ',' ',' ',' ','*','*','*','*',' ','*','G','*'},
	{'*',' ',' ',' ',' ',' ','*','G','T','n','*',' ','*','*','-','*','*','*','*',' ','m','=','m','*','*','*'},
	{'*','X',' ','X',' ',' ','*','m','*','G','*',' ','#','*','m','*',' ',' ',' ',' ',' ','*',' ','*','g','*'},
	{'*','X','u','X',' ',' ','*','6','m','#','*','G','p','G',' ',' ',' ',' ',' ',' ',' ','p','g','p',' ','*'}
};

char map4[10][26] =
{
	{'*','*','*','*','X','d','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','#','*',' ','X',' ','X',' ',' ',' ',' ',' ','q',' ','*',' ',' ',' ','*',' ','Z',' ','*',' ','X','X'},
	{'*','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','p',' ','*',' ',' ','p','-','T','p','q','*',' ',' ','u'},
	{'*','p','p',' ',' ',' ',' ',' ','*','|','*','*',' ',' ','*','=','*','*','*','*','-','*','*',' ','X','X'},
	{'*','*','*',' ',' ','q','*','*','*','m',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
	{'*','6','*',' ','q','p','*','#','*','p',' ','*','*','*','*','*','*','*','*','=','*','*','*',' ','K','*'},
	{'*','r','*','*','*','-','*','p','*','6','p','*','*','*','*',' ','p',' ','q','p',' ','#','*',' ','k','*'},
	{'*',' ','r',' ',' ',' ',' ',' ','-','p',' ','*','K','G','*',' ',' ','*','*','*','*','*','*',' ','6','*'},
	{'*','G','p','*','*','*',' ',' ','*','*','*','*','G','%','*',' ','q','*',' ','I','K',' ','*',' ',' ','*'},
	{'*','p','%','*','#','r',' ',' ','p','p','%','*','r','r','q',' ',' ','*',' ','%',' ',' ','*',' ',' ','*'}
};

char map5[10][26] =
{
	{'*','*','*','*','X','u','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*',' ','*','g','X',' ','X',' ',' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','q','%','-',' ','*'},
	{'*','9','*','G','q',' ',' ',' ',' ','*','*','*','*',' ','*','*','*','*','*','*',' ','*','-',' ','q','*'},
	{'*','q','*','*','*','*',' ','*','*','*','#','g','*',' ','*',' ','+','*','*',' ',' ','*',' ','q','T','*'},
	{'*','q','g','g','q','G','q',' ',' ',' ','r','G','*',' ','*','m','h','r','g','m',' ','*',' ',' ','q','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*',' ','*',' ','*','%','$','*',' ','*',' ','G',' ','*'},
	{'*',' ',' ',' ',' ',' ','r','#','q',' ','*',' ',' ',' ',' ',' ','*','*','*','*','*','*','g','G','g','*'},
	{'*',' ',' ',' ',' ','*','*','*','*',' ','*',' ',' ','*','*','*','*','*','*','*',' ',' ','r',' ','r','*'},
	{'*','X',' ','X',' ','*','*','*','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','h','M','#','*'},
	{'*','X','d','X',' ',' ','G',' ','p',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*'}
};

char map6[10][26] =
{
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
	{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
	{'*','*','*','*','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ','*'},
	{'*',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*'},
	{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*'},
	{'*','*','*','*',' ',' ','*',' ','*','*','*','*',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ','*'},
	{'*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
	{'*','X',' ','X',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','X',' ','X','*'},
	{'*','X','u','X',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','X','d','X','*'}
};

char map7[10][26] =
{
	{'*','*','*','*','*','*','X','d','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*',' ',' ',' ','*',' ','X',' ','X',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*'},
	{'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ','*'},
	{'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*','*','*','*','*',' ','*','*','*','*',' ','*',' ',' ',' ','*'},
	{'*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ','*'},
	{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*'},
	{'*',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ','*','*','*','*','*','*','*',' ',' ','*'},
	{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','X',' ','X','*'},
	{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','X','u','X','*'}
};

char map8[10][26] =
{
 {'*','*','*','*','*','*','X','u','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ','*',' ','*','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X'},
 {'*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d'},
 {'*',' ',' ','*','*','*','*','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*','*','*','X','X'},
 {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*','*','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ','*','*',' ',' ','*','*','*','*','*','*','*',' ',' ','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ','*','*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*'}
};

char map9[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','X','X'},
 {'*',' ',' ','*',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ','*',' ','*',' ',' ','u'},
 {'*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ','*',' ','X','X'},
 {'*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ','*'},
 {'*','X',' ','X',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ','*',' ','*',' ',' ','*'},
 {'*','X','d','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*'}
};

char map10[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','X','d','X','*','*','*','*'},
 {'*',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','X',' ','X',' ',' ',' ','*'},
 {'*',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*','*','*'},
 {'*',' ','*','*','*','*','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*',' ','*'},
 {'*','*','*','*','*',' ','*',' ',' ','*','*','*','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*'},
 {'*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*'},
 {'*','X',' ','X',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ','*'},
 {'*','X','u','X',' ','*','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'}
};

char map11[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','X','u','X','*','*','*','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ','X',' ','X',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*','X','X','X','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*','X','d','X','*',' ','*',' ',' ','*','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'}
};

char map12[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*','*','*',' ',' ','X','X','X',' ',' ','*','*','*',' ',' ','*',' ',' ',' ','*'},
 {'*',' ','*','*',' ',' ','*',' ','*',' ',' ','X','u','X',' ',' ','*',' ','*',' ',' ','*','*',' ',' ','*'},
 {'*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*'},
 {'*',' ','*','*','*','*',' ',' ','*','*','*','*','*','*','*','*','*',' ',' ','*','*','*','*',' ',' ','*'},
 {'*',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ','*'},
 {'*',' ',' ','*',' ','*','*','*','*',' ',' ','X','d','X',' ',' ','*','*','*','*',' ','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','X','X','X',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*'}
};

char map13[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','X','d','X','*'},
 {'*',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ','X',' ','X','*'},
 {'*',' ',' ',' ','*','*','*','*',' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ','*'},
 {'*',' ','*',' ','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ','*'},
 {'*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*','*','*','*'},
 {'*',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*'},
 {'*',' ','*','*','*','*','*','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ','*'},
 {'*',' ',' ','*',' ',' ',' ','*',' ','*',' ','X','u','X',' ','*',' ',' ',' ','*',' ',' ','*','*','*','*'},
 {'*',' ',' ','*',' ',' ',' ',' ',' ','*',' ','X','X','X',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*','*','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ','*'}
};

char map14[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','X','u','X','*'},
 {'*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ','X',' ','X','*'},
 {'*',' ',' ','*',' ','*','*',' ',' ','*',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ','*',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*','*','*','*',' ','*',' ',' ','*'},
 {'*','*','*','*',' ',' ','*','*','*','*',' ',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*',' ',' ','*'},
 {'*',' ',' ',' ',' ','X',' ','X',' ',' ',' ','*','*','*',' ',' ',' ',' ','*','*','*','*','*',' ',' ','*'},
 {'*',' ',' ','*',' ','X',' ','X',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*',' ','X','d','X',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};

char map15[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','X','d','X','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ','*','*',' ',' ',' ','*','*',' ','X',' ','X',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*','*'},
 {'*',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ','*',' ',' ',' ','*','*'},
 {'*',' ',' ',' ','*',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',' ','*',' ','*','*','*',' ',' ','*'},
 {'*',' ','*','*',' ',' ',' ',' ',' ','*',' ','*','*','*','*',' ','*',' ','*',' ',' ',' ','*',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ','*',' ','*',' ','*','*',' ',' ','*','*',' ','*'},
 {'*',' ','*','*','*','*',' ',' ',' ','*','*',' ',' ','*','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*'},
 {'*',' ','*',' ',' ','X',' ','X',' ',' ',' ',' ',' ','*',' ',' ','*','*','*','*',' ','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*','*','X','u','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};

char map16[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','X','u','X','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ','*',' ','*',' ',' ',' ',' ','X',' ','X',' ','*',' ',' ','*',' ',' ','X','X','X',' ','*'},
 {'*',' ',' ',' ','*',' ',' ',' ','*','*','*','*',' ',' ',' ','*',' ',' ','*',' ',' ','X','d','X',' ','*'},
 {'*',' ',' ',' ','*',' ','*','*','*',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*','*',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ','*','*',' ',' ',' ','*',' ','*','*','*','*','*',' ',' ',' ','*','*','*','*','*','*','*','*'},
 {'*',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*','*','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ','*'},
 {'*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ','*'}
};

char map17[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','X','X','X',' ','*'},
 {'*',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*',' ',' ','X','u','X',' ','*'},
 {'*',' ','*','*','*','*','*','*','*','*','*','*',' ','*',' ',' ',' ',' ','*',' ','*','*',' ','*',' ','*'},
 {'*',' ','*','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*',' ','*',' ','*',' ',' ','*','*','*'},
 {'*',' ','*','*',' ','*','*','*','*','*',' ','*',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*','*'},
 {'*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*','*',' ','*','*'},
 {'*',' ',' ','*',' ','*',' ','X',' ','X','*',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ','*','*'},
 {'*',' ',' ',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*'},
 {'*','*','*','*','*','*',' ','X','d','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};

char map18[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ','*',' ','*',' ',' ',' ','*','*','*','*',' ','*','*','*','*',' ','*','*',' ',' ',' ','*'},
 {'*',' ',' ','*','*',' ',' ','*','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ','*'},
 {'*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ','*',' ','*',' ',' ',' ','*','*','*','*',' ','*',' ',' ',' ','*','*','*',' ',' ',' ',' ','*'},
 {'*',' ',' ','*',' ','*','*','*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*'},
 {'*',' ','*','*',' ',' ',' ','X',' ','X',' ','X',' ',' ',' ',' ','*','*','*',' ','*',' ',' ',' ',' ','*'},
 {'*',' ','*',' ',' ',' ',' ','X',' ','X',' ','X',' ',' ',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ','*'},
 {'*','*','*',' ',' ',' ',' ','X','u','X','d','X',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*'}
};

char map19[10][26] =
{
 {'X','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'d',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ','*'},
 {'X','X',' ','*',' ','*',' ',' ','*','*','*','*','*','*',' ','*',' ','*','*',' ',' ',' ','*','*','*','*'},
 {'*',' ',' ','*',' ','*',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*','*',' ',' ',' ',' ','*'},
 {'*',' ','*','*',' ','*',' ','*','*','*','*','*','*','*','*','*',' ','*',' ',' ','*',' ','*','*',' ','*'},
 {'*',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ','*','*',' ','*'},
 {'*',' ','*','*',' ','*',' ',' ','*','*',' ','*','*','*','*',' ','*',' ',' ',' ','*','*','*','*',' ','*'},
 {'*',' ',' ','*','*','*',' ','*',' ','X',' ','X',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ','*',' ','X',' ','X',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*','*','*','*',' ',' ','X','u','X',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ','*'}
};

char map20[10][26] =
{
 {'X','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','X','X'},
 {'u',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*',' ','*',' ',' ',' ',' ',' ','d'},
 {'X','X','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ','*',' ','*',' ',' ','X','X'},
 {' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ','*','*',' ','*','*','*',' ','*',' ','*'},
 {'*',' ',' ','*',' ',' ','*',' ','*',' ','*',' ','*',' ','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ','*'},
 {'*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ','*'},
 {'*',' ',' ','*','*','*',' ',' ',' ','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ','*'},
 {'*','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*','*',' ',' ','*','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ','*'}
};

char map21[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','X','u','X','*'},
 {'*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ','X',' ','X','*'},
 {'*',' ',' ','*',' ','*','*',' ',' ','*',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ','*',' ',' ','*'},
 {'*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*','*','*','*',' ','*',' ',' ','*'},
 {'*','*','*','*',' ',' ','*','*','*','*',' ',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',' ',' ','*'},
 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*',' ',' ','*'},
 {'*',' ',' ',' ',' ','X',' ','X',' ',' ',' ','*','*','*',' ',' ',' ',' ','*','*','*','*','*',' ',' ','*'},
 {'*',' ',' ','*',' ','X',' ','X',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*',' ','X','d','X',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};

char map22[10][26] =
{
 {'*','*','*','*','*','*','X','u','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ','*',' ','*','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X'},
 {'*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d'},
 {'*',' ',' ','*','*','*','*','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*','*','*','X','X'},
 {'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*','*','*','*','*','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ','*','*',' ',' ','*','*','*','*','*','*','*',' ',' ','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ','*','*',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*'},
 {'*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ','*'}
};

char map23[10][26] =
{
 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
 {'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','X','X','X',' ','*'},
 {'*',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*',' ',' ','X','u','X',' ','*'},
 {'*',' ','*','*','*','*','*','*','*','*','*','*',' ','*',' ',' ',' ',' ','*',' ','*','*',' ','*',' ','*'},
 {'*',' ','*','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*',' ','*',' ','*',' ',' ','*','*','*'},
 {'*',' ','*','*',' ','*','*','*','*','*',' ','*',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*','*'},
 {'*',' ',' ','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ','*','*','*','*','*',' ','*','*'},
 {'*',' ',' ','*',' ','*',' ','X',' ','X','*',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ','*','*'},
 {'*',' ',' ',' ',' ',' ',' ','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*'},
 {'*','*','*','*','*','*',' ','X','d','X','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};

char map25[10][26] =
{
 {' ',' ',' ','*',' ',' ',' ','*','*','*','*','*',' ','*','*','*','*','*',' ','*','*','*','*','*','X','X'},
 {' ',' ','*','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','d'},
 {' ','*',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*','X','X'},
 {' ',' ',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' '},
 {' ',' ',' ','*',' ',' ',' ','*','*','*','*','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ',' '},
 {' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','*','*','*','*','*',' ',' '},
 {'X','X',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ',' '},
 {'u',' ',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ',' '},
 {'X','X',' ','*',' ',' ',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ','*',' ',' ',' ','*',' ',' '},
 {' ','*','*','*','*','*',' ','*','*','*','*','*',' ','*','*','*','*','*',' ','*','*','*','*','*',' ',' '}
};

char map24[10][26] =
{
	{ 'W',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','$',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','u' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','8','H','8',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H','N','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','8','H','8',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'W',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','W' }
};

int main()
{
	int life = 1;
	int i = 9, j = 12;
	int game = 1;
	level = 0;
	char input = '\0';
	while (game)
	{

		system("cls");

		while (1)
		{
			switch (level)
			{
			case -1:life = 0; break;
			case 0: start(); level = move(map0, i, j, level); break;
			case 1: map1[i][j] = '@'; level = move(map1, i, j, level); break;
			case 2: map2[i][j] = '@'; level = move(map2, i, j, level); break;
			case 3: map3[i][j] = '@'; level = move(map3, i, j, level); break;
			case 4: map4[i][j] = '@'; level = move(map4, i, j, level); break;
			case 5: map5[i][j] = '@'; level = move(map5, i, j, level); break;
			case 6: map6[i][j] = '@'; level = move(map6, i, j, level); break;
			case 7: map7[i][j] = '@'; level = move(map7, i, j, level); break;
			case 8: map8[i][j] = '@'; level = move(map8, i, j, level); break;
			case 9: map9[i][j] = '@'; level = move(map9, i, j, level); break;
			case 10: map10[i][j] = '@'; level = move(map10, i, j, level); break;
			case 11: map11[i][j] = '@'; level = move(map11, i, j, level); break;
			case 12: map12[i][j] = '@'; level = move(map12, i, j, level); break;
			case 13: map13[i][j] = '@'; level = move(map13, i, j, level); break;
			case 14: map14[i][j] = '@'; level = move(map14, i, j, level); break;
			case 15: map15[i][j] = '@'; level = move(map15, i, j, level); break;
			case 16: map16[i][j] = '@'; level = move(map16, i, j, level); break;
			case 17: map17[i][j] = '@'; level = move(map17, i, j, level); break;
			case 18: map18[i][j] = '@'; level = move(map18, i, j, level); break;
			case 19: map19[i][j] = '@'; level = move(map19, i, j, level); break;
			case 20: map20[i][j] = '@'; level = move(map20, i, j, level); break;
			case 21: map21[i][j] = '@'; level = move(map21, i, j, level); break;
			case 22: map22[i][j] = '@'; level = move(map22, i, j, level); break;
			case 23: map23[i][j] = '@'; level = move(map23, i, j, level); break;
			case 24: map24[i][j] = '@'; PlaySound(TEXT("Toby Fox - But the Earth Refused to Die.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); level = move(map24, i, j, level); break;
			case 25: map25[i][j] = '@'; PlaySound(TEXT("Toby Fox - Undertale.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); level = move(map25, i, j, level); break;
			case 26: life = 2;
			}
			if (life == 0 || life == 2)break;
		}
		if (life == 0)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << '\t' << stars << endl;
			cout << '\t' << "你倒在了征途的路上，直到下个勇者发现了秃顶的你" << endl << endl << endl << endl;
			cout << '\t' << '\t' << '\t' << "游戏结束" << endl;
			cout << '\t' << stars << endl << endl << endl;
			if (music == 0)PlaySound(TEXT("Toby Fox - Fallen Down.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			Sleep(5000);
			if (save1 == 1 || save2 == 1)
			{
				int flag = 0;
				cout << "\t    检测到你有存档，是否读档(Y)" << endl << "\t\t    ";
				cout << "不读档将关闭程序" << endl << "\t\t    "; 
				system("pause");
				input = _getch();
				if (input == 'y')
				{
					loadscreen(level, i, j, flag);
					if (flag == 1)
					{
						life = 1;
						continue;
					}
				}
			}
			else
			{
				cout << "\t\t  检测到你无存档,即将退出" << endl;
				cout << "\t\t    ";
				system("pause");
			}
			game--;
		}
		else if (life == 2)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << '\t' << stars << endl;
			cout << '\t' << "    你战胜了魔王，取代魔王成为了最秃的人\n\t\t公主嫌你秃抛弃你离开了魔塔" << endl << endl << endl << endl;
			cout << '\t' << '\t' << '\t' << "游戏结束" << endl;
			cout << '\t' << stars << endl << endl << endl;
			if(music == 0)PlaySound(TEXT("Toby Fox - An Ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			Sleep(5000);
			game--;
		}
	}
	return 0;
}
