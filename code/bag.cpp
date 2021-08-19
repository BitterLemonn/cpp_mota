#include<bits/stdc++.h>
# include <conio.h>

using namespace std;

extern struct attribute { int blood; int attarct; int defence; int gold; } playeratt;
extern void att(attribute& playeratt, char map[10][26], int& i, int& j, int key);
extern void printmap(char map[10][26], int level);

struct mybag { int yellowkey = 0; int bluekey = 0; int redkey = 0; int book = 0; int pickaxe = 0; int upstick = 0; int lucky_gold = 0;}bags;
extern void printbag(mybag bags);
extern int level;
extern void printicon(char map[10][26]);

void bag(char map[10][26], char pick, char& useditem,char input)
{


	switch (pick)
	{
	case'T':bags.pickaxe++; break;                   //十字镐
	case'I':bags.upstick++; break;                   //遁地法杖
	case'[':bags.pickaxe--; break;                   //使用十字镐
	case'#':playeratt.blood += 150; break;           //小生命药水
	case'%':playeratt.blood += 400; break;           //大生命药水
	case'+':playeratt.blood *= 2; break;             //圣水
	case'G':playeratt.attarct += 2; break;           //攻击宝石
	case'g':playeratt.defence += 2; break;           //防御宝石
	case 'k':bags.yellowkey++; break;                //黄钥匙
	case 'K':bags.bluekey++; break;                  //蓝钥匙
	case '6':bags.redkey++; break;                   //红钥匙
	case '9':bags.redkey++; bags.bluekey++; bags.yellowkey++; break;
	case 'Z':bags.book = 1; break;                   //怪物图鉴
	case '&':bags.lucky_gold = 1; break;             //幸运金币
	case 's':playeratt.attarct += 20; break;         //铁剑
	case 'S':playeratt.attarct += 200; break;        //神圣剑
	case 'a':playeratt.defence += 20; break;         //铁盾
	case 'A':playeratt.defence += 200; break;        //神圣盾
	case '<':playeratt.attarct = 5000; break;        //驱魔剑
	case '>':playeratt.defence = 3500; break;        //驱魔盾
	}

	system("cls");
	printmap(map, level);
	printicon(map);                                  //打印图示函数（请见print.cpp） 
	printbag(bags);

	if (bags.pickaxe > 0 && input == 'c') useditem = 'T';    //判断能否使用十字镐
	if (bags.upstick > 0 && input == 'p') useditem = 'I';    //判断能否使用遁地法杖
	if (bags.lucky_gold != 0 && input == ' ')                //开关幸运金币
	{
		if (bags.lucky_gold == 1)bags.lucky_gold = 2;
		else if (bags.lucky_gold == 2)bags.lucky_gold = 1;
		system("cls");
		printmap(map, level);
		printicon(map);                                  //打印图示函数（请见print.cpp）
		printbag(bags);
	}
	return;
}

void rebag()
{
	bags.bluekey = 0;
	bags.book = 0;
	bags.lucky_gold = 0;
	bags.pickaxe = 0;
	bags.redkey = 0;
	bags.upstick = 0;
	bags.yellowkey = 0;
	return;
}