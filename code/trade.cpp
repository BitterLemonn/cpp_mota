#include<bits/stdc++.h>
# include <conio.h>
#include<Windows.h>

#define stars "\t**************************"

using namespace std;
extern struct mybag { int yellowkey; int bluekey; int redkey; int book; int pickaxe; int upstick; }bags;
extern struct attribute { int blood; int attarct; int defence; int gold; }playeratt;
extern int music;
extern string  mp;
extern void musicc(string mp, int& music);
extern void musics(int& music,char input);

int buyY(int& exit)
{
	if (playeratt.gold >= 10)               //若金币大于等于10
	{
		playeratt.gold -= 10;               //金币数-10
		bags.yellowkey++;                   //黄钥匙+1
		exit = 1;                           //反馈成功购买
		return 1;
	}
	else return -1;
}

int buyB(int& exit)
{
	if (playeratt.gold >= 50)
	{
		playeratt.gold -= 50;
		bags.bluekey++;
		exit = 1;
		return 1;
	}
	else return -1;
}

int sellY(int& exit)
{
	if (bags.yellowkey > 0)
	{
		bags.yellowkey--;
		playeratt.gold += 5;
		exit = 1;
		return 1;
	}
	else return -1;
}

int sellB(int& exit)
{
	if (bags.bluekey > 0)
	{
		bags.bluekey--;
		playeratt.gold += 35;
		exit = 1;
		return 1;
	}
	else return -1;
}

int sellR(int& exit)
{
	if (bags.redkey > 0)
	{
		bags.redkey--;
		playeratt.gold += 100;
		exit = 1;
		return 1;
	}
	else return -1;
}

void shop1()
{
	static int gh1 = 20, gd1 = 20, ga1 = 20;
	char input = '\0';
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t音乐(\\)：";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "欢迎来到商店" << endl;
		cout << '\t' << "1.购买500点生命值   " << gh1 << "   G" << endl;
		cout << '\t' << "2.购买2点防御力     " << gd1 << "   G" << endl;
		cout << '\t' << "3.购买4点攻击力     " << ga1 << "   G" << endl;
		cout << '\t' << "4.退出商店           " << "     " << endl;
		cout << endl << endl << "\t你现在拥有   " << playeratt.gold << " G" << endl;
		cout << "\t你现在血量   " << playeratt.blood << endl;
		cout << "\t你现在攻击力 " << playeratt.attarct << endl;
		cout << "\t你现在防御力 " << playeratt.defence << endl;
		cout << stars << endl << endl;

		musicc(mp, music);
		input = _getch();
		musics(music, input);
		switch (input)
		{
		case '1':
		{
			if (playeratt.gold >= gh1)
			{
				playeratt.gold -= gh1;
				playeratt.blood += 500;
				gh1 += 10;
				cout << "\t" << "生命之神给了你祝福,血量得到了回复";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd1)
			{
				playeratt.gold -= gd1;
				playeratt.defence += 2;
				gd1 += 10;
				cout << "\t" << "大地之神给了你祝福,防御力得到了极小的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga1)
			{
				playeratt.gold -= ga1;
				playeratt.attarct += 4;
				ga1 += 10;
				cout << "\t" << "战斗之神给了你祝福,攻击力得到了极小的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "谢谢惠顾" << endl; Sleep(800); return;
		default: if (input != '\\') cout << '\t' << '\t' << "请输入正确数字" << endl; Sleep(800); continue;
		}
	}
}

void shop2()
{
	static int gh2 = 20, gd2 = 20, ga2 = 20;
	char input = '\0';
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t音乐(\\)：";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "欢迎来到商店" << endl;
		cout << '\t' << "1.购买500点生命值   " << gh2 << "   G" << endl;
		cout << '\t' << "2.购买4点防御力     " << gd2 << "   G" << endl;
		cout << '\t' << "3.购买8点攻击力     " << ga2 << "   G" << endl;
		cout << '\t' << "4.退出商店           " << "     " << endl;
		cout << endl << endl << "\t你现在拥有   " << playeratt.gold << " G" << endl;
		cout << "\t你现在血量   " << playeratt.blood << endl;
		cout << "\t你现在攻击力 " << playeratt.attarct << endl;
		cout << "\t你现在防御力 " << playeratt.defence << endl;
		cout << stars << endl << endl;

		musicc(mp, music);
		input = _getch();
		musics(music, input);
		switch (input)
		{
		case '1':
		{
			if (playeratt.gold >= gh2)
			{
				playeratt.gold -= gh2;
				playeratt.blood += 500;
				gh2 += 10;
				cout << "\t" << "生命之神给了你祝福,血量得到了回复";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd2)
			{
				playeratt.gold -= gd2;
				playeratt.defence += 4;
				gd2 += 10;
				cout << "\t" << "大地之神给了你祝福,防御力得到了小上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga2)
			{
				playeratt.gold -= ga2;
				playeratt.attarct += 8;
				ga2 += 10;
				cout << "\t" << "战斗之神给了你祝福,攻击力得到了小上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "谢谢惠顾" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "请输入正确数字" << endl; Sleep(800); continue;
		}
	}
}

void shop3()
{
	static int gh3 = 20, gd3 = 20, ga3 = 20;
	char input = '\0';
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t音乐(\\)：";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "欢迎来到商店" << endl;
		cout << '\t' << "1.购买500点生命值   " << gh3 << "   G" << endl;
		cout << '\t' << "2.购买6点防御力     " << gd3 << "   G" << endl;
		cout << '\t' << "3.购买12点攻击力     " << ga3 << "   G" << endl;
		cout << '\t' << "4.退出商店           " << "     " << endl;
		cout << endl << endl << "\t你现在拥有   " << playeratt.gold << " G" << endl;
		cout << "\t你现在血量   " << playeratt.blood << endl;
		cout << "\t你现在攻击力 " << playeratt.attarct << endl;
		cout << "\t你现在防御力 " << playeratt.defence << endl;
		cout << stars << endl << endl;

		musicc(mp, music);
		input = _getch();
		musics(music, input);
		switch (input)
		{
		case '1':
		{
			if (playeratt.gold >= gh3)
			{
				playeratt.gold -= gh3;
				playeratt.blood += 500;
				gh3 += 5;
				cout << "\t" << "生命之神给了你祝福,血量得到了回复";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd3)
			{
				playeratt.gold -= gd3;
				playeratt.defence += 6;
				gd3 += 5;
				cout << "\t" << "大地之神给了你祝福,防御力得到了中等程度的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga3)
			{
				playeratt.gold -= ga3;
				playeratt.attarct += 12;
				ga3 += 5;
				cout << "\t" << "战斗之神给了你祝福,攻击力得到了中等程度的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "谢谢惠顾" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "请输入正确数字" << endl; Sleep(800); continue;
		}
	}
}

void shop4()
{
	static int gh4 = 20, gd4 = 20, ga4 = 20;
	char input = '\0';
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t音乐(\\)：";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "欢迎来到商店" << endl;
		cout << '\t' << "1.购买500点生命值   " << gh4 << "   G" << endl;
		cout << '\t' << "2.购买8点防御力     " << gd4 << "   G" << endl;
		cout << '\t' << "3.购买16点攻击力    " << ga4 << "   G" << endl;
		cout << '\t' << "4.退出商店           " << "     " << endl;
		cout << endl << endl << "\t你现在拥有   " << playeratt.gold << " G" << endl;
		cout << "\t你现在血量   " << playeratt.blood << endl;
		cout << "\t你现在攻击力 " << playeratt.attarct << endl;
		cout << "\t你现在防御力 " << playeratt.defence << endl;
		cout << stars << endl << endl;

		musicc(mp, music);
		input = _getch();
		musics(music, input);
		switch (input)
		{
		case '1':
		{
			if (playeratt.gold >= gh4)
			{
				playeratt.gold -= gh4;
				playeratt.blood += 500;
				gh4 += 10;
				cout << "\t" << "生命之神给了你祝福,血量得到了回复";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd4)
			{
				playeratt.gold -= gd4;
				playeratt.defence += 8;
				gd4 += 10;
				cout << "\t" << "大地之神给了你祝福,防御力得到了大幅度的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga4)
			{
				playeratt.gold -= ga4;
				playeratt.attarct += 16;
				ga4 += 10;
				cout << "\t" << "战斗之神给了你祝福,攻击力得到了大幅度的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "谢谢惠顾" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "请输入正确数字" << endl; Sleep(800); continue;
		}
	}
	
}

void shop5()
{
	static int gh5 = 20, gd5 = 20, ga5 = 20;
	char input = '\0';
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t音乐(\\)：";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "欢迎来到商店" << endl;
		cout << '\t' << "1.购买500点生命值    " << gh5 << "   G" << endl;
		cout << '\t' << "2.购买10点防御力     " << gd5 << "   G" << endl;
		cout << '\t' << "3.购买20点攻击力     " << ga5 << "   G" << endl;
		cout << '\t' << "4.退出商店           " << "     " << endl;
		cout << endl << endl << "\t你现在拥有   " << playeratt.gold << " G" << endl;
		cout << "\t你现在血量   " << playeratt.blood << endl;
		cout << "\t你现在攻击力 " << playeratt.attarct << endl;
		cout << "\t你现在防御力 " << playeratt.defence << endl;
		cout << stars << endl << endl;

		musicc(mp, music);
		input = _getch();
		musics(music, input);
		switch (input)
		{
		case '1':
		{
			if (playeratt.gold >= gh5)
			{
				playeratt.gold -= gh5;
				playeratt.blood += 500;
				gh5 += 10;
				cout << "\t" << "生命之神给了你祝福,血量得到了回复";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd5)
			{
				playeratt.gold -= gd5;
				playeratt.defence += 10;
				gd5 += 10;
				cout << "\t" << "大地之神给了你祝福,防御力得到了极大幅度的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga5)
			{
				playeratt.gold -= ga5;
				playeratt.attarct += 15;
				ga5 += 10;
				cout << "\t" << "战斗之神给了你祝福,攻击力得到了极大幅度的上升";
				Sleep(800);
				break;
			}
			else cout << "\t\t你没有那么多钱哦" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "谢谢惠顾" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "请输入正确数字" << endl; Sleep(800); continue;
		}
	}
}

void shop(int level)
{
	int l = level / 5;
	switch (l)
	{
	case 1:shop1(); break;
	case 2:shop2(); break;
	case 3:shop3(); break;
	case 4:shop4(); break;
	case 5:shop5(); break;
	}
	return;
}
