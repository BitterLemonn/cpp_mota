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
	if (playeratt.gold >= 10)               //����Ҵ��ڵ���10
	{
		playeratt.gold -= 10;               //�����-10
		bags.yellowkey++;                   //��Կ��+1
		exit = 1;                           //�����ɹ�����
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
		cout << "\t\t\t\t\t\t����(\\)��";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "��ӭ�����̵�" << endl;
		cout << '\t' << "1.����500������ֵ   " << gh1 << "   G" << endl;
		cout << '\t' << "2.����2�������     " << gd1 << "   G" << endl;
		cout << '\t' << "3.����4�㹥����     " << ga1 << "   G" << endl;
		cout << '\t' << "4.�˳��̵�           " << "     " << endl;
		cout << endl << endl << "\t������ӵ��   " << playeratt.gold << " G" << endl;
		cout << "\t������Ѫ��   " << playeratt.blood << endl;
		cout << "\t�����ڹ����� " << playeratt.attarct << endl;
		cout << "\t�����ڷ����� " << playeratt.defence << endl;
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
				cout << "\t" << "����֮�������ף��,Ѫ���õ��˻ظ�";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd1)
			{
				playeratt.gold -= gd1;
				playeratt.defence += 2;
				gd1 += 10;
				cout << "\t" << "���֮�������ף��,�������õ��˼�С������";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga1)
			{
				playeratt.gold -= ga1;
				playeratt.attarct += 4;
				ga1 += 10;
				cout << "\t" << "ս��֮�������ף��,�������õ��˼�С������";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "лл�ݹ�" << endl; Sleep(800); return;
		default: if (input != '\\') cout << '\t' << '\t' << "��������ȷ����" << endl; Sleep(800); continue;
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
		cout << "\t\t\t\t\t\t����(\\)��";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "��ӭ�����̵�" << endl;
		cout << '\t' << "1.����500������ֵ   " << gh2 << "   G" << endl;
		cout << '\t' << "2.����4�������     " << gd2 << "   G" << endl;
		cout << '\t' << "3.����8�㹥����     " << ga2 << "   G" << endl;
		cout << '\t' << "4.�˳��̵�           " << "     " << endl;
		cout << endl << endl << "\t������ӵ��   " << playeratt.gold << " G" << endl;
		cout << "\t������Ѫ��   " << playeratt.blood << endl;
		cout << "\t�����ڹ����� " << playeratt.attarct << endl;
		cout << "\t�����ڷ����� " << playeratt.defence << endl;
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
				cout << "\t" << "����֮�������ף��,Ѫ���õ��˻ظ�";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd2)
			{
				playeratt.gold -= gd2;
				playeratt.defence += 4;
				gd2 += 10;
				cout << "\t" << "���֮�������ף��,�������õ���С����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga2)
			{
				playeratt.gold -= ga2;
				playeratt.attarct += 8;
				ga2 += 10;
				cout << "\t" << "ս��֮�������ף��,�������õ���С����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "лл�ݹ�" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "��������ȷ����" << endl; Sleep(800); continue;
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
		cout << "\t\t\t\t\t\t����(\\)��";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "��ӭ�����̵�" << endl;
		cout << '\t' << "1.����500������ֵ   " << gh3 << "   G" << endl;
		cout << '\t' << "2.����6�������     " << gd3 << "   G" << endl;
		cout << '\t' << "3.����12�㹥����     " << ga3 << "   G" << endl;
		cout << '\t' << "4.�˳��̵�           " << "     " << endl;
		cout << endl << endl << "\t������ӵ��   " << playeratt.gold << " G" << endl;
		cout << "\t������Ѫ��   " << playeratt.blood << endl;
		cout << "\t�����ڹ����� " << playeratt.attarct << endl;
		cout << "\t�����ڷ����� " << playeratt.defence << endl;
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
				cout << "\t" << "����֮�������ף��,Ѫ���õ��˻ظ�";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd3)
			{
				playeratt.gold -= gd3;
				playeratt.defence += 6;
				gd3 += 5;
				cout << "\t" << "���֮�������ף��,�������õ����еȳ̶ȵ�����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga3)
			{
				playeratt.gold -= ga3;
				playeratt.attarct += 12;
				ga3 += 5;
				cout << "\t" << "ս��֮�������ף��,�������õ����еȳ̶ȵ�����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "лл�ݹ�" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "��������ȷ����" << endl; Sleep(800); continue;
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
		cout << "\t\t\t\t\t\t����(\\)��";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "��ӭ�����̵�" << endl;
		cout << '\t' << "1.����500������ֵ   " << gh4 << "   G" << endl;
		cout << '\t' << "2.����8�������     " << gd4 << "   G" << endl;
		cout << '\t' << "3.����16�㹥����    " << ga4 << "   G" << endl;
		cout << '\t' << "4.�˳��̵�           " << "     " << endl;
		cout << endl << endl << "\t������ӵ��   " << playeratt.gold << " G" << endl;
		cout << "\t������Ѫ��   " << playeratt.blood << endl;
		cout << "\t�����ڹ����� " << playeratt.attarct << endl;
		cout << "\t�����ڷ����� " << playeratt.defence << endl;
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
				cout << "\t" << "����֮�������ף��,Ѫ���õ��˻ظ�";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd4)
			{
				playeratt.gold -= gd4;
				playeratt.defence += 8;
				gd4 += 10;
				cout << "\t" << "���֮�������ף��,�������õ��˴���ȵ�����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga4)
			{
				playeratt.gold -= ga4;
				playeratt.attarct += 16;
				ga4 += 10;
				cout << "\t" << "ս��֮�������ף��,�������õ��˴���ȵ�����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "лл�ݹ�" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "��������ȷ����" << endl; Sleep(800); continue;
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
		cout << "\t\t\t\t\t\t����(\\)��";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << '\t' << "��ӭ�����̵�" << endl;
		cout << '\t' << "1.����500������ֵ    " << gh5 << "   G" << endl;
		cout << '\t' << "2.����10�������     " << gd5 << "   G" << endl;
		cout << '\t' << "3.����20�㹥����     " << ga5 << "   G" << endl;
		cout << '\t' << "4.�˳��̵�           " << "     " << endl;
		cout << endl << endl << "\t������ӵ��   " << playeratt.gold << " G" << endl;
		cout << "\t������Ѫ��   " << playeratt.blood << endl;
		cout << "\t�����ڹ����� " << playeratt.attarct << endl;
		cout << "\t�����ڷ����� " << playeratt.defence << endl;
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
				cout << "\t" << "����֮�������ף��,Ѫ���õ��˻ظ�";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '2':
		{
			if (playeratt.gold >= gd5)
			{
				playeratt.gold -= gd5;
				playeratt.defence += 10;
				gd5 += 10;
				cout << "\t" << "���֮�������ף��,�������õ��˼�����ȵ�����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl;  Sleep(800); continue;
		}
		case '3':
		{
			if (playeratt.gold >= ga5)
			{
				playeratt.gold -= ga5;
				playeratt.attarct += 15;
				ga5 += 10;
				cout << "\t" << "ս��֮�������ף��,�������õ��˼�����ȵ�����";
				Sleep(800);
				break;
			}
			else cout << "\t\t��û����ô��ǮŶ" << endl; Sleep(800); continue;
		}
		case '4':cout << '\t' << '\t' << "лл�ݹ�" << endl; Sleep(800); return;
		default:if (input != '\\') cout << '\t' << '\t' << "��������ȷ����" << endl; Sleep(800); continue;
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
