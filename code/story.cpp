#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>

using namespace std;

extern struct attribute { int blood; int attarct; int defence; int gold; } playeratt;
extern void printstory(string text);
extern void att(attribute& playeratt, char map[10][26], int& i, int& j, int key);
extern void printmap(char map[10][26], int level);
extern void bag(char map[10][26], char pick, char& useditem, char ch);
extern void musicc(string mp, int& music);
extern void musics(int& music, char input);

extern string mp;
extern int music;

char error[10][26] =
{
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
	{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};
char empty[10][26] =
{
	{ '*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' },
	{ '*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*' }
};

void story(char map[10][26],string text,char pick,char useditem,char input, int &key, int &flag,int level,int &i,int &j)
{
	text = "ħ���� ���������������ߣ�";
	printstory(text);
	Sleep(800);
	system("cls");
	printmap(map, level);
	bag(map, pick, useditem, input);
	text = "ħ����װ����ȫ�ɲ�����Ŷ�������ѶȰ�!";
	printstory(text);
	Sleep(800);
	mp = "normal";
	if (music == 0)music = 1;
	system("cls");
	printmap(error, level);
	Sleep(20);
	system("cls");
	printmap(map, level);
	Sleep(20);
	system("cls");
	printmap(error, level);
	Sleep(20);
	system("cls");
	printmap(map, level);
	Sleep(20);
	system("cls");
	printmap(error, level);
	Sleep(20);
	system("cls");
	printmap(map, level);
	Sleep(20);
	system("cls");
	printmap(error, level);
	Sleep(20);
	system("cls");
	printmap(map, level);
	key = 1;
	att(playeratt, map, i, j, key);
	flag = 1;
	return;
}