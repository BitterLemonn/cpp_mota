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
	case'T':bags.pickaxe++; break;                   //ʮ�ָ�
	case'I':bags.upstick++; break;                   //�ݵط���
	case'[':bags.pickaxe--; break;                   //ʹ��ʮ�ָ�
	case'#':playeratt.blood += 150; break;           //С����ҩˮ
	case'%':playeratt.blood += 400; break;           //������ҩˮ
	case'+':playeratt.blood *= 2; break;             //ʥˮ
	case'G':playeratt.attarct += 2; break;           //������ʯ
	case'g':playeratt.defence += 2; break;           //������ʯ
	case 'k':bags.yellowkey++; break;                //��Կ��
	case 'K':bags.bluekey++; break;                  //��Կ��
	case '6':bags.redkey++; break;                   //��Կ��
	case '9':bags.redkey++; bags.bluekey++; bags.yellowkey++; break;
	case 'Z':bags.book = 1; break;                   //����ͼ��
	case '&':bags.lucky_gold = 1; break;             //���˽��
	case 's':playeratt.attarct += 20; break;         //����
	case 'S':playeratt.attarct += 200; break;        //��ʥ��
	case 'a':playeratt.defence += 20; break;         //����
	case 'A':playeratt.defence += 200; break;        //��ʥ��
	case '<':playeratt.attarct = 5000; break;        //��ħ��
	case '>':playeratt.defence = 3500; break;        //��ħ��
	}

	system("cls");
	printmap(map, level);
	printicon(map);                                  //��ӡͼʾ���������print.cpp�� 
	printbag(bags);

	if (bags.pickaxe > 0 && input == 'c') useditem = 'T';    //�ж��ܷ�ʹ��ʮ�ָ�
	if (bags.upstick > 0 && input == 'p') useditem = 'I';    //�ж��ܷ�ʹ�öݵط���
	if (bags.lucky_gold != 0 && input == ' ')                //�������˽��
	{
		if (bags.lucky_gold == 1)bags.lucky_gold = 2;
		else if (bags.lucky_gold == 2)bags.lucky_gold = 1;
		system("cls");
		printmap(map, level);
		printicon(map);                                  //��ӡͼʾ���������print.cpp��
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