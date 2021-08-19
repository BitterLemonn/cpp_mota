#include<bits/stdc++.h>
#include <conio.h>
#include<Windows.h>

using namespace std;

extern struct attribute { int blood; int attarct; int defence; int gold; } playeratt;
extern struct mybag { int yellowkey = 0; int bluekey = 0; int redkey = 0; int book = 0; int pickaxe = 0; int upstick = 0; int lucky_gold = 0; }bags;

extern void printmap(char map[10][26], int level);
extern void shop(int level);
extern void bag(char map[10][26], char pick, char& useditem, char ch);
extern void jump(char map[10][26], int& i, int& j, int level);
extern void story(char map[10][26], string text, char pick, char useditem, char input, int& key, int& flag, int level, int& i, int& j);
extern int openY(int door);
extern int openB(int door);
extern int openR(int door);
extern void printmerchant();
extern void battle(char bp, int& win);
extern void printmonster(char map[10][26]);
extern void printicon(char map[10][26]);
extern void musicc(string mp, int& music);
extern void musics(int& music,char input);
void menu(int& level, int& i, int& j);


extern int music;
extern string mp;

int bug = 0;                          //定义管理者外挂
int boss = 0;                         //定义是否削弱魔王

int move(char map[][26], int& i, int& j, int level)
{
	char player = '@';                //定义玩家图标为   @
	char pick = '\0';                 //定义拾取道具 
	char useditem = '\0';             //定义使用的道具
	char input = '\0';                //接收玩家按键
	char primeinput = '\0';           //接收玩家上一次的按键
	int yi = 0, yj = 0;               //定义玩家原坐标（yi，yj）
	int flag = 0;                     //定义是否触发开场动画
	int door = 0;                     //定义是否开门
	char bp = '\0';                   //定义触发战斗点
	int win = 0;                      //定义胜利
	int premoney = 0;                 //定义玩家之前金钱
	int prelevel = 0;                 //定义玩家之前层数

	printmap(map, level);             //打印地图函数（请见print.cpp）
	printicon(map);                   //打印图示函数（请见print.cpp）
	bag(map, pick, useditem, input);  //打印背包函数（请见bag.cpp）
	printmonster(map);                //打印怪物图鉴 (请见print.cpp）


	for (;;)
	{
		if (level == 0 && flag == 0) mp = "menu2";    //如果在第0层玩家未触发剧情将当前音乐储存为menu2
		if (level == 0 && flag == 1) mp = "normal";   //如果在第0层玩家已触发剧情将当前音乐储存为normal
		if (level != 0 && level != 24) mp = "normal"; //当玩家不在boss关和第0层时玩家关闭音乐时将当前音乐储存为normal
		if (level == 24 && boss == 0)mp = "bossm";
		if (level == 24 && boss == 1)mp = "bossa";
		if (level == 25)              //临时
		{
			level++;
			Sleep(10000);
			break;
		}
		yi = i;                       //获取玩家原坐标
		yj = j;
		int toward = 0;               //定义玩家移动方向
		primeinput = input;           //获取玩家上一次的按键
		premoney = playeratt.gold;    //获取玩家之前的金钱
		prelevel = level;             //获取玩家之前层数

		musicc(mp, music);
		input = _getch();             //获取玩家按键
		musics(music, input);

		if (primeinput != 'c'&& input != 'p') 
			useditem = '\0';          //若上次按键不为使用道具键，重置使用道具状态
		
		switch (input)
		{
		case'a': {j -= 1; toward = 1; break; } //当按下a键时将玩家坐标左移且记录移动方向
		case's': {i += 1; toward = 2; break; } //当按下s键时将玩家坐标下移且记录移动方向
		case'd': {j += 1; toward = 3; break; } //当按下d键时将玩家坐标右移且记录移动方向
		case'w': {i -= 1; toward = 4; break; } //当按下w键时将玩家坐标上移且记录移动方向
		}

		if (i < 0)i += 1;                      //以下均为防止坐标超出数组范围
		if (i > 9)i -= 1;
		if (j < 0)j += 1;
		if (j > 25)j -= 1;

		if (map[i][j] == '*')                  //如果玩家坐标与墙壁坐标重叠
		{                                      //判断是否使用了十字镐
			if (useditem != 'T')               //若未使用
			{
				switch (toward)                //根据玩家的移动方向将玩家退回原来位置
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break; 
				case 4:i += 1; break;
				}
			}
			else                               //若使用了十字镐
			{
				pick = '[';                    //相当捡起了一个消耗十字镐的道具（即消耗一个十字镐）
				useditem = '\0';               //将使用道具状态重置
			}                                  //因没有将玩家坐标退回相当于玩家将墙壁凿掉了
		}

		if (map[i][j] == 'X')                  //判断玩家坐标是否与铁栅栏重叠
		{
			switch (toward)                    //根据玩家的移动方向将玩家退回原来位置
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
		}

		if (map[i][j] == 'd')                  //判断玩家坐标是否与向上的楼梯重叠
		{
			level++;                           //若重叠层数+1
			switch (toward)                    //根据玩家的移动方向将玩家退回原来位置（防止玩家将向上的楼梯吞掉）
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			map[yi][yj] = ' ';
			system("cls");                     //清屏
			break;
		}

		if (map[i][j] == 'u')				   //判断玩家坐标是否与向下的楼梯重叠
		{
			level--;                           //若重叠层数-1
			switch (toward)                    //根据玩家的移动方向将玩家退回原来位置（防止玩家将向下的楼梯吞掉）
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			map[yi][yj] = ' ';
			system("cls");                     //清屏
			break;
		}

		if (map[i][j] == '$')                  //判断玩家坐标是否与商店重叠
		{
			mp = "shop";
			if (music == 0)music = 2;          //若音乐开着，强制切换音乐
			switch (toward)                    //根据玩家的移动方向将玩家退回原来位置（防止玩家将商店吞掉）
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			system("cls");                    //清屏
			shop(level);                      //打印商店函数（请见trade.cpp）
			if (level != 24) mp = "normal";
			else if (level == 24 && boss == 0)mp = "bossm";
			else if (level == 24 && boss == 1)mp = "bossa";
			if (music == 0)music = 2;          //若音乐开着，强制切换音乐
		}

		if (map[i][j] == '-')
		{
			door = openY(door);               //开黄门函数（详见open.cpp）
			if (door == 2)
			{
				switch (toward)               //根据玩家的移动方向将玩家退回原来位置（防止玩家将黄门吞掉）
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break;
				case 4:i += 1; break;
				}
			}
		}

		if (map[i][j] == '=')
		{
			door = openB(door);                //开蓝门函数（详见open.cpp）
			if (door == 3)
			{
				switch (toward)                //根据玩家的移动方向将玩家退回原来位置（防止玩家将蓝门吞掉）
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break;
				case 4:i += 1; break;
				}
			}
		}

		if (map[i][j] == '|')
		{
			door = openR(door);                //开红门函数（详见open.cpp）
			if (door == 4)
			{
				switch (toward)                //根据玩家的移动方向将玩家退回原来位置（防止玩家将红门吞掉）
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break;
				case 4:i += 1; break;
				}
			}
		}

		if (map[i][j] == 'M')                  //判断玩家是否与商人重叠
		{
			mp = "merchant";
			if (music == 0)music = 2;          //若音乐开着，强制切换音乐
			switch (toward)                    //根据玩家的移动方向将玩家退回原来位置（防止玩家将商人吞掉）
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			system("cls");                     //清屏
			printmerchant();                   //打印商人函数（详见print.cpp）
			mp = "normal";
			if (music == 0)music = 2;          //若音乐开着，强制切换音乐
		}

		if (map[i][j] == 'H')                  //判断玩家是否与机关门重叠
		{
			switch (toward)                    //根据玩家的移动方向将玩家退回原来位置
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
		}

		switch (map[i][j])                    //判断是否拾取道具
		{
		case 'T':pick = 'T'; break;           //十字镐
		case 'I':pick = 'I'; break;           //遁地法杖
		case '#':pick = '#'; break;           //小生命药水
		case '%':pick = '%'; break;           //大生命药水
		case '+':pick = '+'; break;           //圣水
		case 'G':pick = 'G'; break;           //攻击宝石
		case 'g':pick = 'g'; break;           //防御宝石
		case 'k':pick = 'k'; break;           //黄钥匙
		case 'K':pick = 'K'; break;           //蓝钥匙
		case '6':pick = '6'; break;           //红钥匙
		case '9':pick = '9'; break;           //神圣钥匙
		case 'Z':pick = 'Z'; break;           //怪物图鉴
		case 'A':pick = 'A'; break;           //神圣盾
		case 'a':pick = 'a'; break;           //铁盾
		case 'S':pick = 'S'; break;           //神圣剑
		case 's':pick = 's'; break;           //铁剑
		case '&':pick = '&'; break;           //幸运金币
		case '>':pick = '>'; break;           //驱魔盾
		case '<':pick = '<'; break;           //驱魔剑
		}

		switch (map[i][j])                    //判断战斗状态
		{
		case'8':bp = '8'; break;              //守卫
		case'o':bp = 'o'; break;              //史莱姆
		case'e':bp = 'e'; break;              //小老鼠
		case'i':bp = 'i'; break;              //蝙蝠
		case'n':bp = 'n'; break;              //兽人
		case'm':bp = 'm'; break;              //麻瓜
		case'p':bp = 'p'; break;              //武士
		case'q':bp = 'q'; break;              //骷髅
		case'r':bp = 'r'; break;              //魔龙
		case'h':bp = 'h'; break;              //驯龙者
		case'b':bp = 'b'; break;              //吸血蝙蝠
		case'P':bp = 'P'; break;              //骷髅队长
		case'B':bp = 'B'; break;              //巫师
		case'E':bp = 'E'; break;              //吸血鬼
		case'Y':bp = 'Y'; break;              //狼人
		case'W':bp = 'W'; break;              //冰冰小魔王
		case'V':bp = 'V'; break;              //加绒大魔王      bad.jpg
		case'N':bp = 'N'; break;              //加绒大魔王(全)  bad.jpg
		}

		if (useditem == 'I' && level > 1)     //判断是否使用遁地法杖
		{
			map[i][j] = ' ';                  //将玩家位置图标由 @  变为空地（防止出现两个 玩家图标）
			level--;                          //向下一层
			jump(map, i, j, level);           //跳跃函数（详见jump.cpp）
			system("cls");                    //清屏
			break;
		}

		if (level == 0&&flag == 0)            //判断触发开头动画
		{
			string text;
			int key = 0;
			if (i == 4 && j == 12)
			{
				story(map, text, pick, useditem, input, key, flag, level, i, j);
			}
		}

		if (bp != '\0')
		{
			battle(bp, win);
			if (win == -1|| win == 4)
			{
				switch (toward)                //根据玩家的移动方向将玩家退回原来位置(必输保护)
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break;
				case 4:i += 1; break;
				}
			}
		}

		map[i][j] = player;                   //将玩家当前坐标放上玩家图标  @
		if (yi != i || yj != j) map[yi][yj] = ' ';//将玩家原来的坐标上的图标 @ 变为空地

		if (input == '\x1b')menu(level, i, j);
		if (prelevel != level)break;

		bag(map, pick, useditem, input);      //打印背包函数（请见bag.cpp）
		printmonster(map);                    //打印怪物图鉴 (请见print.cpp）

		switch(door)                          //反馈无钥匙的情况
		{
		case 2:cout << endl << '\t' << "你需要一把黄钥匙来打开黄门"; break;
		case 3:cout << endl << '\t' << "你需要一把蓝钥匙来打开蓝门"; break;
		case 4:cout << endl << '\t' << "你需要一把红钥匙来打开红门"; break;
		}   

		switch (win)
		{
		case -1:cout << endl << '\t' << "对方护甲太高，你甚至无法击穿"; break;
		case -2:level = -1; break;                                                     //死亡
		case 1:cout << endl << "    恭喜你战斗胜利,获得 " << (playeratt.gold - premoney) << " G,你距离变秃又近了一步"; break;
		case 2:cout << endl << "对方没能击穿你的护甲，轻松取胜,获得 " << (playeratt.gold - premoney) << " G,你距离变秃又近了一步"; break;
		case 3:cout << endl << '\t' << "你竟然打败了冰冰小天使，你是魔鬼吧！！！！"; break;
		case 4:
		{
			cout << endl << '\t' << "全盛的魔王是不败的！！！";
			break;
		}
		case 5:level++; break;
		}

		//管理员作弊码
		if (input == '+')
		{
			if (bug == 0)
			{
				system("color f1");
				bug = 1;
			}
			playeratt.attarct += 100;
			playeratt.defence += 100;
			playeratt.gold += 100;
			bags.pickaxe++;
			pick = '9';

			bag(map, pick, useditem, input);      //打印背包函数（请见bag.cpp）
			printmonster(map);                    //打印怪物图鉴 (请见print.cpp）

		}
		if (bug == 1)
		{
			cout << "\n\t\t你已启用开发者模式";
		}
		if (bug == 1)
		{
			if (level < 24)
			{
				if (input == '-')
				{
					map[i][j] = ' ';
					level++;
					jump(map, i, j, level);
					system("cls");
					break;
				}
			}
		}

		door = 0;                             //重置开门值
		win = 0;                              //重置胜利值
		pick = '\0';                          //重置拾取的道具
		bp = '\0';                            //重置战斗点


		if (level == -1)break;                //若死亡返回
		if (level == 25)break;                //获胜返回
	}
	return level;                             //返回当前所在的层数
}
