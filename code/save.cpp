#include<bits/stdc++.h>
#include <conio.h>
#include<Windows.h>
using namespace std;

#define stars "\t**************************"

extern char map1[10][26], map2[10][26], map3[10][26], map4[10][26], map5[10][26], map6[10][26], map7[10][26], map8[10][26], map9[10][26];
extern char map10[10][26], map11[10][26], map12[10][26], map13[10][26], map14[10][26], map15[10][26], map16[10][26], map17[10][26], map18[10][26], map19[10][26];
extern char map20[10][26], map21[10][26], map22[10][26], map23[10][26], map24[10][26], map25[10][26];

extern struct attribute { int blood; int attarct; int defence; int gold; } playeratt;
extern struct mybag { int yellowkey; int bluekey; int redkey; int book; int pickaxe; int upstick; int lucky_gold; }bags;
int save1 = 0, save2 = 0;

static char s1[10][26], s2[10][26], s3[10][26], s4[10][26], s5[10][26], s6[10][26], s7[10][26], s8[10][26], s9[10][26], s10[10][26];
static char s11[10][26], s12[10][26], s13[10][26], s14[10][26], s15[10][26], s16[10][26], s17[10][26], s18[10][26], s19[10][26], s20[10][26];
static char s21[10][26], s22[10][26], s23[10][26], s24[10][26], s25[10][26];
static int slevel, sblood, sattarct, sdefence, sgold, si, sj;
static int syellowkey, sbluekey, sbook, spickaxe, slucky, sredkey, supstick;

static char S1[10][26], S2[10][26], S3[10][26], S4[10][26], S5[10][26], S6[10][26], S7[10][26], S8[10][26], S9[10][26], S10[10][26];
static char S11[10][26], S12[10][26], S13[10][26], S14[10][26], S15[10][26], S16[10][26], S17[10][26], S18[10][26], S19[10][26], S20[10][26];
static char S21[10][26], S22[10][26], S23[10][26], S24[10][26], S25[10][26];
static int Slevel;
static int Sblood, Sattarct, Sdefence, Sgold;
static int Si, Sj;
static int Syellowkey, Sbluekey, Sbook, Spickaxe, Slucky, Sredkey, Supstick;

void copy(char s[10][26], char map[10][26])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			s[i][j] = map[i][j];
		}
	}
	return;
}

void load(char s[10][26], char map[10][26])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			map[i][j] = s[i][j];
		}
	}
	return;
}

void saves1(int level,int i,int j)
{
	slevel = level;
	sblood = playeratt.blood;
	sattarct = playeratt.attarct;
	sdefence = playeratt.defence;
	sgold = playeratt.gold;
	si = i;
	sj = j;
	copy(s1, map1);
	copy(s2, map2);
	copy(s3, map3);
	copy(s4, map4);
	copy(s5, map5);
	copy(s6, map6);
	copy(s7, map7);
	copy(s8, map8);
	copy(s9, map9);
	copy(s10, map10);
	copy(s11, map11);
	copy(s12, map12);
	copy(s13, map13);
	copy(s14, map14);
	copy(s15, map15);
	copy(s16, map16);
	copy(s17, map17);
	copy(s18, map18);
	copy(s19, map19);
	copy(s20, map20);
	copy(s21, map21);
	copy(s22, map22);
	copy(s23, map23);
	copy(s24, map24);
	copy(s25, map25);
	syellowkey = bags.yellowkey;
	sbluekey = bags.bluekey;
	sbook = bags.book;
	slucky = bags.lucky_gold;
	spickaxe = bags.pickaxe;
	sredkey = bags.redkey;
	supstick = bags.upstick;
	return;   
}

void saves2(int level, int i, int j)
{
	Slevel = level;
	Sblood = playeratt.blood;
	Sattarct = playeratt.attarct;
	Sdefence = playeratt.defence;
	Sgold = playeratt.gold;
	Si = i;
	Sj = j;
	copy(S1, map1);
	copy(S2, map2);
	copy(S3, map3);
	copy(S4, map4);
	copy(S5, map5);
	copy(S6, map6);
	copy(S7, map7);
	copy(S8, map8);
	copy(S9, map9);
	copy(S10, map10);
	copy(S11, map11);
	copy(S12, map12);
	copy(S13, map13);
	copy(S14, map14);
	copy(S15, map15);
	copy(S16, map16);
	copy(S17, map17);
	copy(S18, map18);
	copy(S19, map19);
	copy(S20, map20);
	copy(S21, map21);
	copy(S22, map22);
	copy(S23, map23);
	copy(S24, map24);
	copy(S25, map25);
	Syellowkey = bags.yellowkey;
	Sbluekey = bags.bluekey;
	Sbook = bags.book;
	Slucky = bags.lucky_gold;
	Spickaxe = bags.pickaxe;
	Sredkey = bags.redkey;
	Supstick = bags.upstick;
	return;
}

void load1(int &level, int &i, int &j)
{
	level = slevel;
	playeratt.blood = sblood;
	playeratt.attarct = sattarct;
	playeratt.defence = sdefence;
	playeratt.gold = sgold;
	i = si;
	j = sj;
	load(s1, map1);
	load(s2, map2);
	load(s3, map3);
	load(s4, map4);
	load(s5, map5);
	load(s6, map6);
	load(s7, map7);
	load(s8, map8);
	load(s9, map9);
	load(s10, map10);
	load(s11, map11);
	load(s12, map12);
	load(s13, map13);
	load(s14, map14);
	load(s15, map15);
	load(s16, map16);
	load(s17, map17);
	load(s18, map18);
	load(s19, map19);
	load(s20, map20);
	load(s21, map21);
	load(s22, map22);
	load(s23, map23);
	load(s24, map24);
	load(s25, map25);
	bags.yellowkey = syellowkey;
	bags.bluekey = sbluekey;
	bags.book = sbook;
	bags.lucky_gold = slucky;
	bags.pickaxe = spickaxe;
	bags.redkey = sredkey;
	bags.upstick = supstick;
	return;
}

void load2(int &level, int &i, int &j)
{
	level = Slevel;
	playeratt.blood = Sblood;
	playeratt.attarct = Sattarct;
	playeratt.defence = Sdefence;
	playeratt.gold = Sgold;
	i = Si;
	j = Sj;
	load(S1, map1);
	load(S2, map2);
	load(S3, map3);
	load(S4, map4);
	load(S5, map5);
	load(S6, map6);
	load(S7, map7);
	load(S8, map8);
	load(S9, map9);
	load(S10, map10);
	load(S11, map11);
	load(S12, map12);
	load(S13, map13);
	load(S14, map14);
	load(S15, map15);
	load(S16, map16);
	load(S17, map17);
	load(S18, map18);
	load(S19, map19);
	load(S20, map20);
	load(S21, map21);
	load(S22, map22);
	load(S23, map23);
	load(S24, map24);
	load(S25, map25);
	bags.yellowkey = Syellowkey;
	bags.bluekey = Sbluekey;
	bags.book = Sbook;
	bags.lucky_gold = Slucky;
	bags.pickaxe = Spickaxe;
	bags.redkey = Sredkey;
	bags.upstick = Supstick;
	return;
}

void scontrol(char input, int &level, int &i, int &j, int &p, int &save1, int &save2)
{
	if (input == '\n' || input == '\r')
	{
		if (p == 1 && save1 == 0)
		{
			cout << endl << endl << "      该位置还没有存档，确认存档吗(Y)" << endl;
			input = _getch();
			if (input == 'y')
			{
				saves1(level, i, j);
				save1 = 1;
				if (save2 == 1)save2 = 2;
			}
		}
		else if (p == 1 && (save1 == 1 || save1 == 2))
		{
			cout << endl << endl << "      该位置已经有存档了，确认覆盖吗(Y)" << endl;
			input = _getch();
			if (input == 'y')
			{
				saves1(level, i, j);
				save1 = 1;
				if (save2 == 1)save2 = 2;
			}
		}
		else if (p == 2 && save2 == 0)
		{
			cout << endl << endl << "      该位置还没有存档，确认存档吗(Y)" << endl;
			input = _getch();
			if (input == 'y')
			{
				saves2(level, i, j);
				save2 = 1;
				if (save1 == 1)save1 = 2;
			}
		}
		else if (p == 2 && (save2 == 1 || save2 == 2))
		{
			cout << endl << endl << "      该位置已经有存档了，确认覆盖吗(Y)" << endl;
			input = _getch();
			if (input == 'y')
			{
				saves2(level, i, j);
				save2 = 1;
				if (save1 == 1)save1 = 2;
			}
		}
	}
	return;
}

void lcontrol(char input, int &level, int &i, int &j, int& p, int& save1, int& save2, int& xl,int& flag)
{
	if (input == '\n' || input == '\r')
	{
		if (p == 1 && save1 == 0)
		{
			cout << endl << endl << "      该位置还没有存档" << endl;
			Sleep(800);
		}
		else if (p == 1 && (save1 == 1 || save1 == 2))
		{
			cout << endl << endl << "  该位置已经有存档了，状态如下，确认读档吗(Y)" << endl<<endl;
			cout << "\t\t   第 " << slevel << " 层" << endl;
			cout << "\t\t  血量：" << sblood << endl;
			cout << "\t\t  攻击：" << sattarct << endl;
			cout << "\t\t  防御：" << sdefence << endl;
			cout << "\t\t  金币：" << sgold << " G" << endl;
			cout << "    背包：" << endl;
			cout << "\t  黄钥匙：" << syellowkey << "\t蓝钥匙：" << sbluekey << "\t红钥匙：" << sredkey << endl;
			cout << "\t  十字镐：" << spickaxe << endl;
			if (sbook == 1)cout << "\t  你已拥有怪物图鉴" << endl;
			if (slucky == 1)cout << "\t  你已拥有幸运金币" << endl;

			input = _getch();
			if (input == 'y')
			{
				load1(level, i, j);
				xl = 1;
				flag = 1;
			}
		}
		else if (p == 2 && save2 == 0)
		{
			cout << endl << endl << "      该位置还没有存档" << endl;
			Sleep(800);
		}
		else if (p == 2 && (save2 == 1 || save2 == 2))
		{
			cout << endl << endl << "  该位置已经有存档了，状态如下，确认读档吗(Y)" << endl << endl;
			cout << "\t\t   第 " << slevel << " 层" << endl;
			cout << "\t\t  血量：" << sblood << endl;
			cout << "\t\t  攻击：" << sattarct << endl;
			cout << "\t\t  防御：" << sdefence << endl;
			cout << "\t\t  金币：" << sgold << " G" << endl;
			cout << "    背包：" << endl;
			cout << "\t  黄钥匙：" << syellowkey << "\t蓝钥匙：" << sbluekey << "\t红钥匙：" << sredkey << endl;
			cout << "\t  十字镐：" << spickaxe << endl;
			if (sbook == 1)cout << "\t  你已拥有怪物图鉴" << endl;
			if (slucky == 1)cout << "\t  你已拥有幸运金币" << endl;

			input = _getch();
			if (input == 'y')
			{
				load2(level, i, j);
				xl = 1;
				flag = 1;
			}
		}
	}
	return;
}

void savescreen(int &level, int &i, int &j)
{
	system("cls");
	char input = '\0';
	int p = 1;

	while (1)
	{
		if (p == 1)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t存档列表" << endl;
			cout << stars << endl << endl;
			cout << "\t\t>1.";
			if (save1 == 0)cout << "空<" << endl;
			else if (save1 == 1)cout << "已有存档<" << endl;
			else if (save1 == 2)cout << "已有存档(旧)<" << endl;
			cout << "\t\t2.";
			if (save2 == 0)cout << "空" << endl;
			else if (save2 == 1)cout << "已有存档" << endl;
			else if (save2 == 2)cout << "已有存档(旧)" << endl;
			cout << endl;
			cout << stars << endl;
		}
		else if (p == 2)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t存档列表" << endl;
			cout << stars << endl << endl;
			cout << "\t\t1.";
			if (save1 == 0)cout << "空" << endl;
			else if (save1 == 1)cout << "已有存档" << endl;
			else if (save1 == 2)cout << "已有存档(旧)" << endl;
			cout << "\t\t>2.";
			if (save2 == 0)cout << "空<" << endl;
			else if (save2 == 1)cout << "已有存档<" << endl;
			else if (save2 == 2)cout << "已有存档(旧)<" << endl;
			cout << endl;
			cout << stars << endl;
		}

		if (level == 0)
		{
			cout << "\t\t你当前在入口" << endl;
			cout << "    请不要在入口存档，可能会造成不可逆的错误";
		}

		input = _getch();
		if (input == 'w') p = 1;
		else if (input == 's')p = 2;
		scontrol(input, level, i, j, p, save1, save2);

		if (input == '\x1b')
		{
			system("cls");
			break;
		}
	}
	return;
}

void loadscreen(int &level, int &i, int &j,int &flag)
{
	system("cls");
	char input = '\0';
	int p = 1;
	int xl = 0;

	while (1)
	{
		if (p == 1)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t存档列表" << endl;
			cout << stars << endl << endl;
			cout << "\t\t>1.";
			if (save1 == 0)cout << "空<" << endl;
			else if (save1 == 1)cout << "已有存档<" << endl;
			else if (save1 == 2)cout << "已有存档(旧)<" << endl;
			cout << "\t\t2.";
			if (save2 == 0)cout << "空" << endl;
			else if (save2 == 1)cout << "已有存档" << endl;
			else if (save2 == 2)cout << "已有存档(旧)" << endl;
			cout << endl;
			cout << stars << endl;
		}
		else if (p == 2)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t存档列表" << endl;
			cout << stars << endl << endl;
			cout << "\t\t1.";
			if (save1 == 0)cout << "空" << endl;
			else if (save1 == 1)cout << "已有存档" << endl;
			else if (save1 == 2)cout << "已有存档(旧)" << endl;
			cout << "\t\t>2.";
			if (save2 == 0)cout << "空<" << endl;
			else if (save2 == 1)cout << "已有存档<" << endl;
			else if (save2 == 2)cout << "已有存档(旧)<" << endl;
			cout << endl;
			cout << stars << endl;
		}

		input = _getch();
		if (input == 'w') p = 1;
		else if (input == 's')p = 2;
		lcontrol(input, level, i, j, p, save1, save2, xl,flag);

		if (xl == 1)
		{
			system("cls");
			break;
		}
		if (input == '\x1b')
		{
			system("cls");
			break;
		}
	}
	return;
}

void menu(int &level,int &i,int &j)
{
	system("cls");
	int p = 1;
	char input = '\0';
	int flag = 0;
	while (1)
	{
		system("cls");
		if (p == 1 && (input == '\r' || input == '\n')) savescreen(level, i, j);
		if (p == 2 && (input == '\r' || input == '\n')) loadscreen(level, i, j, flag);
		if (p == 1)
		{
			cout << endl << endl << endl << endl;
			cout << "\t      菜单(esc退出)" << endl;
			cout << stars << endl << endl;
			cout << "\t\t>1.存档<" << endl;
			cout << "\t\t2.读档" << endl;
			cout << endl;
			cout << stars << endl;
		}
		else if (p == 2)
		{
			cout << endl << endl << endl << endl;
			cout << "\t      菜单(esc退出)" << endl;
			cout << stars << endl << endl;
			cout << "\t\t1.存档" << endl;
			cout << "\t\t>2.读档<" << endl;
			cout << endl;
			cout << stars << endl;
		}

		if (flag == 1)break;
		input = _getch();
		switch (input)
		{
		case'w':p = 1; break;
		case's':p = 2; break;
		}
		if (input == '\x1b')break;
	}
}