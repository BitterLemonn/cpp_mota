#include<bits/stdc++.h>
# include <conio.h>
#include<Windows.h>

#define stars "\t**************************"
#define t "\t"

using namespace std;
extern struct mybag { int yellowkey; int bluekey; int redkey; int book; int pickaxe; int upstick; int lucky_gold; }bags;
extern struct attribute { int blood; int attarct; int defence; int gold; }playeratt;

extern int buyY(int& exit);
extern int buyB(int& exit);
extern int sellY(int& exit);
extern int sellB(int& exit);
extern int sellR(int& exit);
extern void vivid();
extern void musicc(string mp, int& music);
extern void musics(int& music, char input);
extern int music;
extern string  mp;
extern int boss;

extern struct monster
{
	int attact;
	int defence;
	int gold;
	int blood;
}slime, mice, bat, orc, muggle, warrior, skelenton, dragon, dragon_rider, blood_bat, ske_cap, wizard, vampire, werewolf, bing, maou_JR, JR, guard;

void printlevel(int level)
{
	switch (level)
	{
	case 0:cout << "��         ��"; break;
	case 1:cout << "��    1    ��"; break;
	case 2:cout << "��    2    ��"; break;
	case 3:cout << "��    3    ��"; break;
	case 4:cout << "��    4    ��"; break;
	case 5:cout << "��    5    ��"; break;
	case 6:cout << "��    6    ��"; break;
	case 7:cout << "��    7    ��"; break;
	case 8:cout << "��    8    ��"; break;
	case 9:cout << "��    9    ��"; break;
	case 10:cout << "��    10    ��"; break;
	case 11:cout << "��    11    ��"; break;
	case 12:cout << "��    12    ��"; break;
	case 13:cout << "��    13    ��"; break;
	case 14:cout << "��    14    ��"; break;
	case 15:cout << "��    15    ��"; break;
	case 16:cout << "��    16    ��"; break;
	case 17:cout << "��    17    ��"; break;
	case 18:cout << "��    18    ��"; break;
	case 19:cout << "��    19    ��"; break;
	case 20:cout << "��    20    ��"; break;
	case 21:cout << "��    21    ��"; break;
	case 22:cout << "��    22    ��"; break;
	case 23:cout << "��    23    ��"; break;
	case 24:cout << "��    24    ��"; break;
	case 25:cout << "��    25    ��"; break;
	}
	return;
}

//��ӡ��ͼ����������
void printmap(char map[10][26], int level)
{
	cout << endl;
	cout << "\t�˵�(esc)" << endl;
	cout << endl << "\t\t\t" << "    ħ      ��" << endl;
	cout << endl << "\t\t\t\t\t\t����(\\)��";
	if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
	else if (music == -1)cout << "off" << endl;
	cout << endl << endl << '\t';
	for (int i = 0; i < 10; i++)                  //��ӡ��ͼ
	{
		for (int j = 0; j < 26; j++)
		{
			cout << map[i][j];
			cout << " ";
			if (i == 0 && j == 25)               //�ڵ�һ��ĩβ��ӡ����
			{
				cout << '\t';
				printlevel(level);
			}
			if (i == 2 && j == 25)              //�ڵ�����ĩβ��ӡ���Ѫ��
			{
				cout << '\t';
				cout << "Ѫ��:   " << playeratt.blood;
			}
			if (i == 4 && j == 25)              //�ڵ�����ĩβ��ӡ��ҹ�����
			{
				cout << '\t';
				cout << "������: " << playeratt.attarct;
			}			
			if (i == 6 && j == 25)              //�ڵ�����ĩβ��ӡ��ҷ�����
			{
				cout << '\t';
				cout << "������: " << playeratt.defence;
			}
			if (i == 8 && j == 25)              //�ڵھ���ĩβ��ӡ��ҽ�Ǯ
			{
				cout << '\t';
				cout << "��Ǯ:   " << playeratt.gold << " G ";
			}
		}
		cout << endl << '\t';
	}
	cout << endl << endl;
	return;
}


//��ӡ����

void printbag(mybag bags)
{
	cout << endl << '\t' << "������" << endl << endl;
	cout << "   " << "��Կ�ף�" << bags.yellowkey << "    ��Կ�ף�" << bags.bluekey << "    ��Կ�ף�" << bags.redkey << endl;
	if (bags.pickaxe != 0)cout << "   ʮ�ָ䣺" << bags.pickaxe << " ʹ�÷�������c��Ȼ�󿿽���Ҫ�ƻ���ǽ��(����Ʒ)" << endl;
	if (bags.upstick != 0)cout << "   �ݵط��ȣ�" << bags.upstick << " ʹ�÷�����������p�����ɵ�����һ��" << endl;
	if (bags.book != 0)cout << "   ����ӵ�й���ͼ����" << endl;
	if (bags.lucky_gold != 0)cout << "   ����ӵ�����˽��,��������������\n   ������������������ƺ�����������,���ո�����Խ���������" << endl;
	if (bags.lucky_gold == 1)cout << "   ��ǰ���˽��״̬���� (��Χ������㻢������)" << endl;
	if (bags.lucky_gold == 2)cout << "   ��ǰ���˽��״̬���� (��Χ����ָ���ƽ��)" << endl;
}

//��ͷ����
void printstory(string text)
{
	cout << endl;
	cout << '\t';
	for (int i = 0; text[i] != '\0'; i++)
	{
		cout << text[i];
		Sleep(10);
	}
	return;
}

//��ӡ����
void printmerchant()
{
	int buy = 0, exit = 0, sell = 0, quit = 0;
	char input = '\0';
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t����(\\)��";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << "1.����һ�ѻ�Կ��      10G" << endl;
		cout << '\t' << "2.����һ����Կ��      50G" << endl;
		cout << '\t' << "3.����һ�ѻ�Կ��       5G" << endl;
		cout << '\t' << "4.����һ����Կ��      35G" << endl;
		cout << '\t' << "5.����һ�Ѻ�Կ��     100G" << endl;
		cout << '\t' << "6.        �ټ�" << endl;
		cout << stars << endl;
		cout << endl <<'\t'<<"��ӵ�� " << playeratt.gold << " G" << endl;
		cout <<'\t'<< "��ӵ�� " << bags.yellowkey << " �ѻ�Կ��    " << endl;
		cout <<'\t'<< "��ӵ�� " << bags.bluekey << " ����Կ��    " << endl;
		cout <<'\t'<< "��ӵ�� " << bags.redkey << " �Ѻ�Կ��    " << endl;

		input = _getch();
		if (music == 2)music = 1;
		musics(music,input);
		musicc(mp, music);

		switch (input)
		{
		case '1':buy = buyY(exit); break;             //�����Կ��
		case '2':buy = buyB(exit); break;             //������Կ��
		case '3':sell = sellY(exit); break;           //���ۻ�Կ��
		case '4':sell = sellB(exit); break;           //������Կ��
		case '5':sell = sellR(exit); break;           //���ۺ�Կ��
		case '6':quit = 1; break;
		default:
		{
			if (input != '\\')
			{
				cout << endl << '\t' << "�Ҳ��ṩ�������Ŷ!";
				Sleep(800);
				system("cls");
			}
		}
		}
		if (sell == 1)                                //���ɹ�����Կ��ʱ����
		{
			cout << endl <<'\t'<< "�����Ǹ��û�!"; 
			Sleep(800);
			sell = 0;
		}
		if (buy == 1)                                 //���ɹ�����Կ��ʱ����
		{
			cout << endl <<'\t'<< "лл�ݹ�!����";
			Sleep(800);
			buy = 0;
		}
		if (buy == -1 && sell == 0)                    //������Կ��ʧ��ʱ����
		{
			cout << endl <<'\t'<< "���!���Ǯ���ų�����!";
			Sleep(800);
			buy = 0;
		}
		if (buy == 0 && sell == -1)                    //������Կ��ʧ��ʱ����
		{
			cout << endl <<'\t'<<"����,��������۾��л�����!";
			Sleep(800);
			sell = 0;
		}
		if (quit == 1 && exit == 1)                    //���ɹ����ۻ�������һ�κ��˳�ʱ����
		{
			cout << endl <<'\t'<< "�´�����ѽ!����";
			Sleep(800);
			break;
		}
		if (quit == 1 && exit == 0)                    //��δ�ɹ����ۻ�������һ�κ��˳�ʱ����
		{
			cout << endl <<'\t'<<"ûǮû����Ҫ��!";
			Sleep(800);
			break;
		}
	}
	return;
}

void pendl(int& n)
{
	if (n == 3)
	{
		cout << endl;
		n = 0;
	}
	return;
}

void printmonster(char map[10][26])
{
	char icon = '\0';
	int n = 0;
	int o = 0, e = 0, f = 0, x = 0, m = 0, p = 0, q = 0, r = 0, h = 0, b = 0, P = 0, B = 0, E = 0, Y = 0, W = 0, V = 0, N = 0,Guard = 0;
	if(bags.book == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				icon = map[i][j];
				switch (icon)
				{
				case'8':Guard = 1; break;//����
				case'o':o = 1; break;    //ʷ��ķ
				case'e':e = 1; break;    //С����
				case'i':f = 1; break;    //����
				case'n':x = 1; break;    //����
				case'm':m = 1; break;    //���
				case'p':p = 1; break;    //��ʿ
				case'q':q = 1; break;    //����
				case'r':r = 1; break;    //ħ��
				case'h':h = 1; break;    //ѱ����
				case'b':b = 1; break;    //��Ѫ����
				case'P':P = 1; break;    //���öӳ�
				case'B':B = 1; break;    //��ʦ
				case'E':E = 1; break;    //��Ѫ��
				case'Y':Y = 1; break;    //����
				case'W':W = 1; break;    //����Сħ��
				case'V':V = 1; break;    //���޴�ħ��
				case'N':N = 1; break;    //���޴�ħ��(ȫ)
				}
			}
		}
		cout << endl << endl;
		cout << "\t����(ǿ���ɵ͵���):" << endl;
		if (Guard == 1)
		{
			cout << '\t' << "8 ���� ����";
			n++;
			pendl(n);
		}
		if (o == 1)
		{
			cout << '\t' << "o ���� ʷ��ķ";
			n++;
			pendl(n);
		}
		if (e == 1)
		{
			cout << '\t' << "e ���� С����";
			n++;
			pendl(n);
		}
		if (f == 1)
		{
			cout << '\t' << "i ���� ����";
			n++;
			pendl(n);
		}
		if (x == 1)
		{
			cout << '\t' << "n ���� ����";
			n++;
			pendl(n);
		}
		if (m == 1)
		{
			cout << '\t' << "m ���� ���";
			n++;
			pendl(n);
		}
		if (p == 1)
		{
			cout << '\t' << "p ���� ��ʿ";
			n++;
			pendl(n);
		}
		if (q == 1)
		{
			cout << '\t' << "q ���� ����";
			n++;
			pendl(n);
		}
		if (r == 1)
		{
			cout << '\t' << "r ���� ħ��";
			n++;
			pendl(n);
		}
		if (h == 1)
		{
			cout << '\t' << "h ���� ѱ����";
			n++;
			pendl(n);
		}
		if (b == 1)
		{
			cout << '\t' << "b ���� ��Ѫ����";
			n++;
			pendl(n);
		}
		if (P == 1)
		{
			cout << '\t' << "P ���� ���öӳ�";
			n++;
			pendl(n);
		}
		if (B == 1)
		{
			cout << '\t' << "B ���� ��ʦ";
			n++;
			pendl(n);
		}
		if (E == 1)
		{
			cout << '\t' << "E ���� ��Ѫ��";
			n++;
			pendl(n);
		}
		if (Y == 1)
		{
			cout << '\t' << "Y ���� ����";
			n++;
			pendl(n);
		}
		if (W == 1)
		{
			cout << '\t' << "W ���� ����Сħ��";
			n++;
			pendl(n);
		}
		if (V == 1)
		{
			cout << '\t' << "V ���� ���޴�ħ��";
			n++;
			pendl(n);
		}
		if (N == 1)
		{
			cout << '\t' << "N ���� ���޴�ħ��";
			n++;
			pendl(n);
		}
		o = 0, e = 0, f = 0, x = 0, m = 0, p = 0, q = 0, r = 0, h = 0, b = 0, P = 0, B = 0, E = 0, Y = 0, W = 0, V = 0;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				icon = map[i][j];
				switch (icon)
				{ 
				case'8':Guard = 1; n++; break;//����
				case'o':o = 1; n++; break;    //ʷ��ķ
				case'e':e = 1; n++; break;    //С����
				case'i':f = 1; n++; break;    //����
				case'n':x = 1; n++; break;    //����
				case'm':m = 1; n++; break;    //���
				case'p':p = 1; n++; break;    //��ʿ
				case'q':q = 1; n++; break;    //����
				case'r':r = 1; n++; break;    //ħ��
				case'h':h = 1; n++; break;    //ѱ����
				case'b':b = 1; n++; break;    //��Ѫ����
				case'P':P = 1; n++; break;    //���öӳ�
				case'B':B = 1; n++; break;    //��ʦ
				case'E':E = 1; n++; break;    //��Ѫ��
				case'Y':Y = 1; n++; break;    //����
				case'W':W = 1; n++; break;    //����Сħ��
				case'V':V = 1; n++; break;    //���޴�ħ��
				case'N':N = 1; n++; break;    //���޴�ħ��(ȫ)
				}
			}
		}

		vivid();
		if (bags.lucky_gold == 1)
		{
			slime.gold *= 2;
			mice.gold *= 2;
			bat.gold *= 2;
			orc.gold *= 2;
			muggle.gold *= 2;
			warrior.gold *= 2;
			skelenton.gold *= 2;
			dragon.gold *= 2;
			dragon_rider.gold *= 2;
			blood_bat.gold *= 2;
			ske_cap.blood *= 2;
			wizard.gold *= 2;
			vampire.gold *= 2;
			werewolf.gold *= 2;
			slime.attact *= 1.2;
			mice.attact *= 1.2;
			bat.attact *= 1.2;
			orc.attact *= 1.2;
			muggle.attact *= 1.2;
			warrior.attact *= 1.2;
			skelenton.attact *= 1.2;
			dragon.attact *= 1.2;
			dragon_rider.attact *= 1.2;
			blood_bat.attact *= 1.2;
			ske_cap.attact *= 1.2;
			wizard.attact *= 1.2;
			vampire.attact *= 1.2;
			werewolf.attact *= 1.2;
		}
		cout << endl << endl;
		if (Guard == 1)
		{
			cout << '\t' << "8 ���� ����       " << "������:" << guard.attact << "   ������:" << guard.defence << "   Ѫ��:" << guard.blood << "    ������: " << guard.gold << " G";
			cout << endl;
			cout << "\t���������ŵ�������������ս����̶���ʧ1/4��Ѫ��";
			cout << endl;
			cout << endl;
		}
		if (o == 1)
		{
			cout << '\t' << "o ���� ʷ��ķ     " << "������:" << slime.attact << "   ������:" << slime.defence << "   Ѫ��:" << slime.blood << "    ������: " << slime.gold << " G";
			cout << endl;
		}
		if (e == 1)
		{
			cout << '\t' << "e ���� С����     " << "������:" << mice.attact << "   ������:" << mice.defence << "   Ѫ��:" << mice.blood << "    ������: " << mice.gold << " G";
			cout << endl;
		}
		if (f == 1)
		{
			cout << '\t' << "i ���� ����       " << "������:" << bat.attact << "   ������:" << bat.defence << "   Ѫ��:" << bat.blood << "   ������: " << bat.gold << " G";
			cout << endl;
		}
		if (x == 1)
		{
			cout << '\t' << "n ���� ����       " << "������:" << orc.attact << "   ������:" << orc.defence << "  Ѫ��:" << orc.blood << "   ������: " << orc.gold << " G";
			cout << endl;
		}
		if (m == 1)
		{
			cout << '\t' << "m ���� ���       " << "������:" << muggle.attact << "   ������:" << muggle.defence << "  Ѫ��:" << muggle.blood << "   ������: " << muggle.gold << " G";
			cout << endl;
		}
		if (p == 1)
		{
			cout << '\t' << "p ���� ��ʿ       " << "������:" << warrior.attact << "   ������:" << warrior.defence << "  Ѫ��:" << warrior.blood << "   ������: " << warrior.gold << " G";
			cout << endl;
		}
		if (q == 1)
		{
			cout << '\t' << "q ���� ����       " << "������:" << skelenton.attact << "  ������:" << skelenton.defence << "  Ѫ��:" << skelenton.blood << "   ������: " << skelenton.gold << " G";
			cout << endl;
			cout << "\t�����ڵ�һ���������ظ�20%������ֵ��������ս��";
			cout << endl;
			cout << endl;
		}
		if (r == 1)
		{
			cout << '\t' << "r ���� ħ��       " << "������:" << dragon.attact << "   ������:" << dragon.defence << "  Ѫ��:" << dragon.blood << "   ������: " << dragon.gold << " G";
			cout << endl;
		}
		if (h == 1)
		{
			cout << '\t' << "h ���� ѱ����     " << "������:" << dragon_rider.attact << "  ������:" << dragon_rider.defence << "  Ѫ��:" << dragon_rider.blood << "   ������: " << dragon_rider.gold << " G";
			cout << endl;
		}
		if (b == 1)
		{
			cout << '\t' << "b ���� ��Ѫ����   " << "������:" << blood_bat.attact << "  ������:" << blood_bat.defence << " Ѫ��:" << blood_bat.blood << "   ������: " << blood_bat.gold << " G";
			cout << endl;
			cout << "\t��Ѫ������ÿ�ι������ظ�����˺���10%��Ѫ��";
			cout << endl;
			cout << endl;
		}
		if (P == 1)
		{
			cout << '\t' << "P ���� ���öӳ�   " << "������:" << ske_cap.attact << "  ������:" << ske_cap.defence << " Ѫ��:" << ske_cap.blood << "   ������: " << ske_cap.gold << " G";
			cout << endl;
			cout << "\t���öӳ��ڵ�һ���������ظ�40%������ֵ��������ս��";
			cout << endl;
			cout << endl;
		}
		if (B == 1)
		{
			cout << '\t' << "B ���� ��ʦ       " << "������:" << wizard.attact << "  ������:" << wizard.defence << " Ѫ��:" << wizard.blood << "   ������: " << wizard.gold << " G";
			cout << endl;
			cout << '\t' << "\t��ʦ����������20%�ķ���";
			cout << endl;
			cout << endl;
		}
		if (E == 1)
		{
			cout << '\t' << "E ���� ��Ѫ��     " << "������:" << vampire.attact << "  ������:" << vampire.defence << " Ѫ��:" << vampire.blood << "  ������: " << vampire.gold << " G";
			cout << endl;
			cout <<"\t��Ѫ����ÿ�ι������ظ�����˺���30%��Ѫ��";
			cout << endl;
			cout << endl;
		}
		if (Y == 1)
		{
			cout << '\t' << "Y ���� ����       " << "������:" << werewolf.attact << "  ������:" << werewolf.defence << " Ѫ��:" << werewolf.blood << "  ������: " << werewolf.gold << " G";
			cout << endl;
		}
		if (W == 1)
		{
			cout << '\t' << "W ���� ����Сħ��   " << "������:" << bing.attact << "   ������:" << bing.defence << "   Ѫ��:" << bing.blood << "   ������: " << bing.gold << " G";
			cout << endl;
			cout << "\t����Сħ����ÿ���غ϶�ס��һ�غϣ���С��";
			cout << endl;
			cout << endl;
		}
		if (V == 1)
		{
			cout << '\t' << "V ���� ���޴�ħ��   " << "������:" << maou_JR.attact << "   ������:" << maou_JR.defence << "   Ѫ��:" << maou_JR.blood << "   ������: " << maou_JR.gold << " G";
			cout << endl;
			cout << "\t��  ��ͺ(����)��ǿ����С�ģ�";
			cout << endl;
			cout << endl;
		}
		if (N == 1)
		{
			cout << '\t' << "N ���� ���޴�ħ��   " << "������:" << JR.attact << "   ������:" << JR.defence << "   Ѫ��:" << JR.blood << "   ������: " << JR.gold << " G";
			cout << endl;
			cout << "\tȫʢ��ħ���ǲ���սʤ�ģ���������";
			cout << endl;
			cout << endl;
		}
		o = 0, e = 0, f = 0, x = 0, m = 0, p = 0, q = 0, r = 0, h = 0, b = 0, P = 0, B = 0, E = 0, Y = 0, W = 0, V = 0, N = 0;
	}
	return;
}

void printicon(char map[10][26])
{
	int wall = 0, france = 0, up = 0, down = 0, shop = 0, merchan = 0, pixaxe = 0, stick = 0;
	int yk = 0, bk = 0, rk = 0, hk = 0, yd = 0, bd = 0, rd = 0, bg = 0, rg = 0;
	int s = 0, l = 0, holy = 0, book = 0, coin = 0, isw = 0, hsw = 0, ish = 0, hsh = 0;
	int W = 0; int H = 0; int mj = 0; int md = 0; int gu = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			switch (map[i][j])
			{
			case'*': wall = 1; break;
			case'X':france = 1; break;
			case'u':up = 1; break;
			case'd':down = 1; break;
			case'$':shop = 1; break;
			case'M':merchan = 1; break;
			case'T':pixaxe = 1; break;
			case'I':stick = 1; break;
			case'k':yk = 1; break;
			case'K':bk = 1; break;
			case'6':rk = 1; break;
			case'9':hk = 1; break;
			case'-':yd = 1; break;
			case'=':bd = 1; break;
			case'|':rd = 1; break;
			case'g':bg = 1; break;
			case'G':rg = 1; break;
			case'#':s = 1; break;
			case'%':l = 1; break;
			case'+':holy = 1; break;
			case'Z':book = 1; break;
			case'&':coin = 1; break;
			case's':isw = 1; break;
			case'S':hsw = 1; break;
			case'a':ish = 1; break;
			case'A':hsh = 1; break;
			case'W':W = 1; break;
			case'H':H = 1; break;
			case'<':mj = 1; break;
			case'>':md = 1; break;
			case'8':gu = 1; break;
			}
		}
	}
	int n = 0;
	if (wall == 1)cout << "\t�� * ��ǽ�ڣ�һ��������޷�������������ʹ��ʮ�ָ��ƻ�" << endl;
	if (france == 1)
	{
		cout << "\t�� X ����դ�����޷�����";
		cout << endl;
	}
	if (up == 1)
	{
		cout << "\t�� u ������¥�ݣ��ɵ���һ��";
		cout << endl;
	}
	if (down == 1)
	{
		cout << "\t�� d ������¥�ݣ��ɵ���һ��";
		cout << endl;
	}
	if (shop == 1)
	{
		cout << "\t�� $ ���̵�";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (merchan == 1)
	{
		cout << "\t�� M ������";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (pixaxe == 1)
	{
		cout << "\t�� T ��ʮ�ָ�";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (stick == 1)
	{
		cout << "\t�� I ���ݵط���";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (yk == 1)
	{
		cout << "\t�� k ����Կ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (bk == 1)
	{
		cout << "\t�� K ����Կ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (rk == 1)
	{
		cout << "\t�� 6 ����Կ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (hk == 1)
	{
		cout << "\t�� 9 ����ʥԿ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (yd == 1)
	{
		cout << "\t�� - ������";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (bd == 1)
	{
		cout << "\t�� = ������";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (rd == 1)
	{
		cout << "\t�� | ������";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (coin == 1)
	{
		cout << "\t�� & �����˽��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (isw == 1)
	{
		cout << "\t�� s ������";
		n++; 
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (hsw == 1)
	{
		cout << "\t�� S ����ʥ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (ish == 1)
	{
		cout << "\t�� a ������";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (hsh == 1)
	{
		cout << "\t�� A ����ʥ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (mj == 1)
	{
		cout << "\t�� < ����ħ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (md == 1)
	{
		cout << "\t�� > ����ħ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (bg == 1)
	{
		cout << "\t�� g ������ʯ(+2����)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (rg == 1)
	{
		cout << "\t�� G ���챦ʯ(+2����)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (s == 1)
	{
		cout << "\t�� # ��СѪƿ(+150Ѫ��)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (l == 1)
	{
		cout << "\t�� % ����Ѫƿ(+400Ѫ��)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (holy == 1)
	{
		cout << "\t�� + ��ʥˮ(Ѫ������)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (book == 1)
	{
		cout << "\t�� Z ������ͼ��";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (H == 1)
	{
		cout << "\t�� H �������ţ���Ѱ���ŵķ����ɣ�";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (md != 1 && mj != 1 && gu != 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (map[i][j] == 'H')
				{
					map[i][j] = ' ';
				}
			}
		}
	}

	if (W == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (map[i][j] == 'N')
				{
					map[i][j] = 'V';
					boss = 1;
					if(music == 0)music = 2;
				}
			}
		}
	}
	cout << endl;
	return;
}