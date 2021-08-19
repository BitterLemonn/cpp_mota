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
	case 0:cout << "入         口"; break;
	case 1:cout << "第    1    层"; break;
	case 2:cout << "第    2    层"; break;
	case 3:cout << "第    3    层"; break;
	case 4:cout << "第    4    层"; break;
	case 5:cout << "第    5    层"; break;
	case 6:cout << "第    6    层"; break;
	case 7:cout << "第    7    层"; break;
	case 8:cout << "第    8    层"; break;
	case 9:cout << "第    9    层"; break;
	case 10:cout << "第    10    层"; break;
	case 11:cout << "第    11    层"; break;
	case 12:cout << "第    12    层"; break;
	case 13:cout << "第    13    层"; break;
	case 14:cout << "第    14    层"; break;
	case 15:cout << "第    15    层"; break;
	case 16:cout << "第    16    层"; break;
	case 17:cout << "第    17    层"; break;
	case 18:cout << "第    18    层"; break;
	case 19:cout << "第    19    层"; break;
	case 20:cout << "第    20    层"; break;
	case 21:cout << "第    21    层"; break;
	case 22:cout << "第    22    层"; break;
	case 23:cout << "第    23    层"; break;
	case 24:cout << "第    24    层"; break;
	case 25:cout << "第    25    层"; break;
	}
	return;
}

//打印地图及基本数据
void printmap(char map[10][26], int level)
{
	cout << endl;
	cout << "\t菜单(esc)" << endl;
	cout << endl << "\t\t\t" << "    魔      塔" << endl;
	cout << endl << "\t\t\t\t\t\t音乐(\\)：";
	if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
	else if (music == -1)cout << "off" << endl;
	cout << endl << endl << '\t';
	for (int i = 0; i < 10; i++)                  //打印地图
	{
		for (int j = 0; j < 26; j++)
		{
			cout << map[i][j];
			cout << " ";
			if (i == 0 && j == 25)               //在第一行末尾打印层数
			{
				cout << '\t';
				printlevel(level);
			}
			if (i == 2 && j == 25)              //在第三行末尾打印玩家血量
			{
				cout << '\t';
				cout << "血量:   " << playeratt.blood;
			}
			if (i == 4 && j == 25)              //在第五行末尾打印玩家攻击力
			{
				cout << '\t';
				cout << "攻击力: " << playeratt.attarct;
			}			
			if (i == 6 && j == 25)              //在第七行末尾打印玩家防御力
			{
				cout << '\t';
				cout << "防御力: " << playeratt.defence;
			}
			if (i == 8 && j == 25)              //在第九行末尾打印玩家金钱
			{
				cout << '\t';
				cout << "金钱:   " << playeratt.gold << " G ";
			}
		}
		cout << endl << '\t';
	}
	cout << endl << endl;
	return;
}


//打印背包

void printbag(mybag bags)
{
	cout << endl << '\t' << "背包：" << endl << endl;
	cout << "   " << "黄钥匙：" << bags.yellowkey << "    蓝钥匙：" << bags.bluekey << "    红钥匙：" << bags.redkey << endl;
	if (bags.pickaxe != 0)cout << "   十字镐：" << bags.pickaxe << " 使用方法：按c键然后靠近你要破坏的墙壁(消耗品)" << endl;
	if (bags.upstick != 0)cout << "   遁地法杖：" << bags.upstick << " 使用方法：按两次p键即可到达上一层" << endl;
	if (bags.book != 0)cout << "   你已拥有怪物图鉴。" << endl;
	if (bags.lucky_gold != 0)cout << "   你已拥有幸运金币,将会给你带来财运\n   但它金光闪闪怪物们似乎都盯上了你,按空格键可以将它遮起来" << endl;
	if (bags.lucky_gold == 1)cout << "   当前幸运金币状态：开 (周围怪物对你虎视眈眈)" << endl;
	if (bags.lucky_gold == 2)cout << "   当前幸运金币状态：关 (周围怪物恢复了平静)" << endl;
}

//开头故事
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

//打印商人
void printmerchant()
{
	int buy = 0, exit = 0, sell = 0, quit = 0;
	char input = '\0';
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t音乐(\\)：";
		if (music == 2 || music == 1 || music == 0)cout << "on" << endl;
		else if (music == -1)cout << "off" << endl;
		cout << stars << endl;
		cout << '\t' << "1.购买一把黄钥匙      10G" << endl;
		cout << '\t' << "2.购买一把蓝钥匙      50G" << endl;
		cout << '\t' << "3.出售一把黄钥匙       5G" << endl;
		cout << '\t' << "4.出售一把蓝钥匙      35G" << endl;
		cout << '\t' << "5.出售一把红钥匙     100G" << endl;
		cout << '\t' << "6.        再见" << endl;
		cout << stars << endl;
		cout << endl <<'\t'<<"你拥有 " << playeratt.gold << " G" << endl;
		cout <<'\t'<< "你拥有 " << bags.yellowkey << " 把黄钥匙    " << endl;
		cout <<'\t'<< "你拥有 " << bags.bluekey << " 把蓝钥匙    " << endl;
		cout <<'\t'<< "你拥有 " << bags.redkey << " 把红钥匙    " << endl;

		input = _getch();
		if (music == 2)music = 1;
		musics(music,input);
		musicc(mp, music);

		switch (input)
		{
		case '1':buy = buyY(exit); break;             //购买黄钥匙
		case '2':buy = buyB(exit); break;             //购买蓝钥匙
		case '3':sell = sellY(exit); break;           //出售黄钥匙
		case '4':sell = sellB(exit); break;           //出售蓝钥匙
		case '5':sell = sellR(exit); break;           //出售红钥匙
		case '6':quit = 1; break;
		default:
		{
			if (input != '\\')
			{
				cout << endl << '\t' << "我不提供此项服务哦!";
				Sleep(800);
				system("cls");
			}
		}
		}
		if (sell == 1)                                //当成功出售钥匙时反馈
		{
			cout << endl <<'\t'<< "这真是个好货!"; 
			Sleep(800);
			sell = 0;
		}
		if (buy == 1)                                 //当成功购买钥匙时反馈
		{
			cout << endl <<'\t'<< "谢谢惠顾!嘻嘻";
			Sleep(800);
			buy = 0;
		}
		if (buy == -1 && sell == 0)                    //当购买钥匙失败时反馈
		{
			cout << endl <<'\t'<< "穷鬼!这点钱留着吃土吧!";
			Sleep(800);
			buy = 0;
		}
		if (buy == 0 && sell == -1)                    //当出售钥匙失败时反馈
		{
			cout << endl <<'\t'<<"拜托,睁大你的眼睛有货再来!";
			Sleep(800);
			sell = 0;
		}
		if (quit == 1 && exit == 1)                    //当成功出售或购买至少一次后退出时反馈
		{
			cout << endl <<'\t'<< "下次再来呀!嘻嘻";
			Sleep(800);
			break;
		}
		if (quit == 1 && exit == 0)                    //当未成功出售或购买至少一次后退出时反馈
		{
			cout << endl <<'\t'<<"没钱没货不要来!";
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
				case'8':Guard = 1; break;//守卫
				case'o':o = 1; break;    //史莱姆
				case'e':e = 1; break;    //小老鼠
				case'i':f = 1; break;    //蝙蝠
				case'n':x = 1; break;    //兽人
				case'm':m = 1; break;    //麻瓜
				case'p':p = 1; break;    //武士
				case'q':q = 1; break;    //骷髅
				case'r':r = 1; break;    //魔龙
				case'h':h = 1; break;    //驯龙者
				case'b':b = 1; break;    //吸血蝙蝠
				case'P':P = 1; break;    //骷髅队长
				case'B':B = 1; break;    //巫师
				case'E':E = 1; break;    //吸血鬼
				case'Y':Y = 1; break;    //狼人
				case'W':W = 1; break;    //冰冰小魔王
				case'V':V = 1; break;    //加绒大魔王
				case'N':N = 1; break;    //加绒大魔王(全)
				}
			}
		}
		cout << endl << endl;
		cout << "\t怪物(强度由低到高):" << endl;
		if (Guard == 1)
		{
			cout << '\t' << "8 —— 守卫";
			n++;
			pendl(n);
		}
		if (o == 1)
		{
			cout << '\t' << "o —— 史莱姆";
			n++;
			pendl(n);
		}
		if (e == 1)
		{
			cout << '\t' << "e —— 小老鼠";
			n++;
			pendl(n);
		}
		if (f == 1)
		{
			cout << '\t' << "i —— 蝙蝠";
			n++;
			pendl(n);
		}
		if (x == 1)
		{
			cout << '\t' << "n —— 兽人";
			n++;
			pendl(n);
		}
		if (m == 1)
		{
			cout << '\t' << "m —— 麻瓜";
			n++;
			pendl(n);
		}
		if (p == 1)
		{
			cout << '\t' << "p —— 武士";
			n++;
			pendl(n);
		}
		if (q == 1)
		{
			cout << '\t' << "q —— 骷髅";
			n++;
			pendl(n);
		}
		if (r == 1)
		{
			cout << '\t' << "r —— 魔龙";
			n++;
			pendl(n);
		}
		if (h == 1)
		{
			cout << '\t' << "h —— 驯龙者";
			n++;
			pendl(n);
		}
		if (b == 1)
		{
			cout << '\t' << "b —— 吸血蝙蝠";
			n++;
			pendl(n);
		}
		if (P == 1)
		{
			cout << '\t' << "P —— 骷髅队长";
			n++;
			pendl(n);
		}
		if (B == 1)
		{
			cout << '\t' << "B —— 巫师";
			n++;
			pendl(n);
		}
		if (E == 1)
		{
			cout << '\t' << "E —— 吸血鬼";
			n++;
			pendl(n);
		}
		if (Y == 1)
		{
			cout << '\t' << "Y —— 狼人";
			n++;
			pendl(n);
		}
		if (W == 1)
		{
			cout << '\t' << "W —— 冰冰小魔王";
			n++;
			pendl(n);
		}
		if (V == 1)
		{
			cout << '\t' << "V —— 加绒大魔王";
			n++;
			pendl(n);
		}
		if (N == 1)
		{
			cout << '\t' << "N —— 加绒大魔王";
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
				case'8':Guard = 1; n++; break;//守卫
				case'o':o = 1; n++; break;    //史莱姆
				case'e':e = 1; n++; break;    //小老鼠
				case'i':f = 1; n++; break;    //蝙蝠
				case'n':x = 1; n++; break;    //兽人
				case'm':m = 1; n++; break;    //麻瓜
				case'p':p = 1; n++; break;    //武士
				case'q':q = 1; n++; break;    //骷髅
				case'r':r = 1; n++; break;    //魔龙
				case'h':h = 1; n++; break;    //驯龙者
				case'b':b = 1; n++; break;    //吸血蝙蝠
				case'P':P = 1; n++; break;    //骷髅队长
				case'B':B = 1; n++; break;    //巫师
				case'E':E = 1; n++; break;    //吸血鬼
				case'Y':Y = 1; n++; break;    //狼人
				case'W':W = 1; n++; break;    //冰冰小魔王
				case'V':V = 1; n++; break;    //加绒大魔王
				case'N':N = 1; n++; break;    //加绒大魔王(全)
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
			cout << '\t' << "8 —— 守卫       " << "攻击力:" << guard.attact << "   防御力:" << guard.defence << "   血量:" << guard.blood << "    掉落金币: " << guard.gold << " G";
			cout << endl;
			cout << "\t守卫机关门的守卫，与守卫战斗会固定损失1/4的血量";
			cout << endl;
			cout << endl;
		}
		if (o == 1)
		{
			cout << '\t' << "o —— 史莱姆     " << "攻击力:" << slime.attact << "   防御力:" << slime.defence << "   血量:" << slime.blood << "    掉落金币: " << slime.gold << " G";
			cout << endl;
		}
		if (e == 1)
		{
			cout << '\t' << "e —— 小老鼠     " << "攻击力:" << mice.attact << "   防御力:" << mice.defence << "   血量:" << mice.blood << "    掉落金币: " << mice.gold << " G";
			cout << endl;
		}
		if (f == 1)
		{
			cout << '\t' << "i —— 蝙蝠       " << "攻击力:" << bat.attact << "   防御力:" << bat.defence << "   血量:" << bat.blood << "   掉落金币: " << bat.gold << " G";
			cout << endl;
		}
		if (x == 1)
		{
			cout << '\t' << "n —— 兽人       " << "攻击力:" << orc.attact << "   防御力:" << orc.defence << "  血量:" << orc.blood << "   掉落金币: " << orc.gold << " G";
			cout << endl;
		}
		if (m == 1)
		{
			cout << '\t' << "m —— 麻瓜       " << "攻击力:" << muggle.attact << "   防御力:" << muggle.defence << "  血量:" << muggle.blood << "   掉落金币: " << muggle.gold << " G";
			cout << endl;
		}
		if (p == 1)
		{
			cout << '\t' << "p —— 武士       " << "攻击力:" << warrior.attact << "   防御力:" << warrior.defence << "  血量:" << warrior.blood << "   掉落金币: " << warrior.gold << " G";
			cout << endl;
		}
		if (q == 1)
		{
			cout << '\t' << "q —— 骷髅       " << "攻击力:" << skelenton.attact << "  防御力:" << skelenton.defence << "  血量:" << skelenton.blood << "   掉落金币: " << skelenton.gold << " G";
			cout << endl;
			cout << "\t骷髅在第一次死亡后会回复20%的生命值继续跟你战斗";
			cout << endl;
			cout << endl;
		}
		if (r == 1)
		{
			cout << '\t' << "r —— 魔龙       " << "攻击力:" << dragon.attact << "   防御力:" << dragon.defence << "  血量:" << dragon.blood << "   掉落金币: " << dragon.gold << " G";
			cout << endl;
		}
		if (h == 1)
		{
			cout << '\t' << "h —— 驯龙者     " << "攻击力:" << dragon_rider.attact << "  防御力:" << dragon_rider.defence << "  血量:" << dragon_rider.blood << "   掉落金币: " << dragon_rider.gold << " G";
			cout << endl;
		}
		if (b == 1)
		{
			cout << '\t' << "b —— 吸血蝙蝠   " << "攻击力:" << blood_bat.attact << "  防御力:" << blood_bat.defence << " 血量:" << blood_bat.blood << "   掉落金币: " << blood_bat.gold << " G";
			cout << endl;
			cout << "\t吸血蝙蝠在每次攻击后会回复造成伤害的10%的血量";
			cout << endl;
			cout << endl;
		}
		if (P == 1)
		{
			cout << '\t' << "P —— 骷髅队长   " << "攻击力:" << ske_cap.attact << "  防御力:" << ske_cap.defence << " 血量:" << ske_cap.blood << "   掉落金币: " << ske_cap.gold << " G";
			cout << endl;
			cout << "\t骷髅队长在第一次死亡后会回复40%的生命值继续跟你战斗";
			cout << endl;
			cout << endl;
		}
		if (B == 1)
		{
			cout << '\t' << "B —— 巫师       " << "攻击力:" << wizard.attact << "  防御力:" << wizard.defence << " 血量:" << wizard.blood << "   掉落金币: " << wizard.gold << " G";
			cout << endl;
			cout << '\t' << "\t巫师可以无视你20%的防御";
			cout << endl;
			cout << endl;
		}
		if (E == 1)
		{
			cout << '\t' << "E —— 吸血鬼     " << "攻击力:" << vampire.attact << "  防御力:" << vampire.defence << " 血量:" << vampire.blood << "  掉落金币: " << vampire.gold << " G";
			cout << endl;
			cout <<"\t吸血鬼在每次攻击后会回复造成伤害的30%的血量";
			cout << endl;
			cout << endl;
		}
		if (Y == 1)
		{
			cout << '\t' << "Y —— 狼人       " << "攻击力:" << werewolf.attact << "  防御力:" << werewolf.defence << " 血量:" << werewolf.blood << "  掉落金币: " << werewolf.gold << " G";
			cout << endl;
		}
		if (W == 1)
		{
			cout << '\t' << "W —— 冰冰小魔王   " << "攻击力:" << bing.attact << "   防御力:" << bing.defence << "   血量:" << bing.blood << "   掉落金币: " << bing.gold << " G";
			cout << endl;
			cout << "\t冰冰小魔王会每三回合冻住你一回合，请小心";
			cout << endl;
			cout << endl;
		}
		if (V == 1)
		{
			cout << '\t' << "V —— 加绒大魔王   " << "攻击力:" << maou_JR.attact << "   防御力:" << maou_JR.defence << "   血量:" << maou_JR.blood << "   掉落金币: " << maou_JR.gold << " G";
			cout << endl;
			cout << "\t他  很秃(划掉)很强，请小心！";
			cout << endl;
			cout << endl;
		}
		if (N == 1)
		{
			cout << '\t' << "N —— 加绒大魔王   " << "攻击力:" << JR.attact << "   防御力:" << JR.defence << "   血量:" << JR.blood << "   掉落金币: " << JR.gold << " G";
			cout << endl;
			cout << "\t全盛的魔王是不可战胜的，请削弱他";
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
	if (wall == 1)cout << "\t“ * ”墙壁，一般情况下无法穿过，但可以使用十字镐破坏" << endl;
	if (france == 1)
	{
		cout << "\t“ X ”铁栅栏，无法穿过";
		cout << endl;
	}
	if (up == 1)
	{
		cout << "\t“ u ”向上楼梯，可到上一层";
		cout << endl;
	}
	if (down == 1)
	{
		cout << "\t“ d ”向下楼梯，可到下一层";
		cout << endl;
	}
	if (shop == 1)
	{
		cout << "\t“ $ ”商店";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (merchan == 1)
	{
		cout << "\t“ M ”商人";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (pixaxe == 1)
	{
		cout << "\t“ T ”十字镐";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (stick == 1)
	{
		cout << "\t“ I ”遁地法杖";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (yk == 1)
	{
		cout << "\t“ k ”黄钥匙";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (bk == 1)
	{
		cout << "\t“ K ”蓝钥匙";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (rk == 1)
	{
		cout << "\t“ 6 ”红钥匙";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (hk == 1)
	{
		cout << "\t“ 9 ”神圣钥匙";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (yd == 1)
	{
		cout << "\t“ - ”黄门";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (bd == 1)
	{
		cout << "\t“ = ”蓝门";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (rd == 1)
	{
		cout << "\t“ | ”红门";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (coin == 1)
	{
		cout << "\t“ & ”幸运金币";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (isw == 1)
	{
		cout << "\t“ s ”铁剑";
		n++; 
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (hsw == 1)
	{
		cout << "\t“ S ”神圣剑";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (ish == 1)
	{
		cout << "\t“ a ”铁盾";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (hsh == 1)
	{
		cout << "\t“ A ”神圣盾";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (mj == 1)
	{
		cout << "\t“ < ”驱魔剑";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (md == 1)
	{
		cout << "\t“ > ”驱魔盾";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (bg == 1)
	{
		cout << "\t“ g ”蓝宝石(+2防御)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (rg == 1)
	{
		cout << "\t“ G ”红宝石(+2攻击)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (s == 1)
	{
		cout << "\t“ # ”小血瓶(+150血量)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (l == 1)
	{
		cout << "\t“ % ”大血瓶(+400血量)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (holy == 1)
	{
		cout << "\t“ + ”圣水(血量翻倍)";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}
	if (book == 1)
	{
		cout << "\t“ Z ”怪物图鉴";
		n++;
		if (n == 3)
		{
			cout << endl;
			n = 0;
		}
	}

	if (H == 1)
	{
		cout << "\t“ H ”机关门（找寻开门的方法吧）";
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