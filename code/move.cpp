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

int bug = 0;                          //������������
int boss = 0;                         //�����Ƿ�����ħ��

int move(char map[][26], int& i, int& j, int level)
{
	char player = '@';                //�������ͼ��Ϊ   @
	char pick = '\0';                 //����ʰȡ���� 
	char useditem = '\0';             //����ʹ�õĵ���
	char input = '\0';                //������Ұ���
	char primeinput = '\0';           //���������һ�εİ���
	int yi = 0, yj = 0;               //�������ԭ���꣨yi��yj��
	int flag = 0;                     //�����Ƿ񴥷���������
	int door = 0;                     //�����Ƿ���
	char bp = '\0';                   //���崥��ս����
	int win = 0;                      //����ʤ��
	int premoney = 0;                 //�������֮ǰ��Ǯ
	int prelevel = 0;                 //�������֮ǰ����

	printmap(map, level);             //��ӡ��ͼ���������print.cpp��
	printicon(map);                   //��ӡͼʾ���������print.cpp��
	bag(map, pick, useditem, input);  //��ӡ�������������bag.cpp��
	printmonster(map);                //��ӡ����ͼ�� (���print.cpp��


	for (;;)
	{
		if (level == 0 && flag == 0) mp = "menu2";    //����ڵ�0�����δ�������齫��ǰ���ִ���Ϊmenu2
		if (level == 0 && flag == 1) mp = "normal";   //����ڵ�0������Ѵ������齫��ǰ���ִ���Ϊnormal
		if (level != 0 && level != 24) mp = "normal"; //����Ҳ���boss�غ͵�0��ʱ��ҹر�����ʱ����ǰ���ִ���Ϊnormal
		if (level == 24 && boss == 0)mp = "bossm";
		if (level == 24 && boss == 1)mp = "bossa";
		if (level == 25)              //��ʱ
		{
			level++;
			Sleep(10000);
			break;
		}
		yi = i;                       //��ȡ���ԭ����
		yj = j;
		int toward = 0;               //��������ƶ�����
		primeinput = input;           //��ȡ�����һ�εİ���
		premoney = playeratt.gold;    //��ȡ���֮ǰ�Ľ�Ǯ
		prelevel = level;             //��ȡ���֮ǰ����

		musicc(mp, music);
		input = _getch();             //��ȡ��Ұ���
		musics(music, input);

		if (primeinput != 'c'&& input != 'p') 
			useditem = '\0';          //���ϴΰ�����Ϊʹ�õ��߼�������ʹ�õ���״̬
		
		switch (input)
		{
		case'a': {j -= 1; toward = 1; break; } //������a��ʱ��������������Ҽ�¼�ƶ�����
		case's': {i += 1; toward = 2; break; } //������s��ʱ��������������Ҽ�¼�ƶ�����
		case'd': {j += 1; toward = 3; break; } //������d��ʱ��������������Ҽ�¼�ƶ�����
		case'w': {i -= 1; toward = 4; break; } //������w��ʱ��������������Ҽ�¼�ƶ�����
		}

		if (i < 0)i += 1;                      //���¾�Ϊ��ֹ���곬�����鷶Χ
		if (i > 9)i -= 1;
		if (j < 0)j += 1;
		if (j > 25)j -= 1;

		if (map[i][j] == '*')                  //������������ǽ�������ص�
		{                                      //�ж��Ƿ�ʹ����ʮ�ָ�
			if (useditem != 'T')               //��δʹ��
			{
				switch (toward)                //������ҵ��ƶ���������˻�ԭ��λ��
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break; 
				case 4:i += 1; break;
				}
			}
			else                               //��ʹ����ʮ�ָ�
			{
				pick = '[';                    //�൱������һ������ʮ�ָ�ĵ��ߣ�������һ��ʮ�ָ䣩
				useditem = '\0';               //��ʹ�õ���״̬����
			}                                  //��û�н���������˻��൱����ҽ�ǽ�������
		}

		if (map[i][j] == 'X')                  //�ж���������Ƿ�����դ���ص�
		{
			switch (toward)                    //������ҵ��ƶ���������˻�ԭ��λ��
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
		}

		if (map[i][j] == 'd')                  //�ж���������Ƿ������ϵ�¥���ص�
		{
			level++;                           //���ص�����+1
			switch (toward)                    //������ҵ��ƶ���������˻�ԭ��λ�ã���ֹ��ҽ����ϵ�¥���̵���
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			map[yi][yj] = ' ';
			system("cls");                     //����
			break;
		}

		if (map[i][j] == 'u')				   //�ж���������Ƿ������µ�¥���ص�
		{
			level--;                           //���ص�����-1
			switch (toward)                    //������ҵ��ƶ���������˻�ԭ��λ�ã���ֹ��ҽ����µ�¥���̵���
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			map[yi][yj] = ' ';
			system("cls");                     //����
			break;
		}

		if (map[i][j] == '$')                  //�ж���������Ƿ����̵��ص�
		{
			mp = "shop";
			if (music == 0)music = 2;          //�����ֿ��ţ�ǿ���л�����
			switch (toward)                    //������ҵ��ƶ���������˻�ԭ��λ�ã���ֹ��ҽ��̵��̵���
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			system("cls");                    //����
			shop(level);                      //��ӡ�̵꺯�������trade.cpp��
			if (level != 24) mp = "normal";
			else if (level == 24 && boss == 0)mp = "bossm";
			else if (level == 24 && boss == 1)mp = "bossa";
			if (music == 0)music = 2;          //�����ֿ��ţ�ǿ���л�����
		}

		if (map[i][j] == '-')
		{
			door = openY(door);               //�����ź��������open.cpp��
			if (door == 2)
			{
				switch (toward)               //������ҵ��ƶ���������˻�ԭ��λ�ã���ֹ��ҽ������̵���
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
			door = openB(door);                //�����ź��������open.cpp��
			if (door == 3)
			{
				switch (toward)                //������ҵ��ƶ���������˻�ԭ��λ�ã���ֹ��ҽ������̵���
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
			door = openR(door);                //�����ź��������open.cpp��
			if (door == 4)
			{
				switch (toward)                //������ҵ��ƶ���������˻�ԭ��λ�ã���ֹ��ҽ������̵���
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break;
				case 4:i += 1; break;
				}
			}
		}

		if (map[i][j] == 'M')                  //�ж�����Ƿ��������ص�
		{
			mp = "merchant";
			if (music == 0)music = 2;          //�����ֿ��ţ�ǿ���л�����
			switch (toward)                    //������ҵ��ƶ���������˻�ԭ��λ�ã���ֹ��ҽ������̵���
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
			system("cls");                     //����
			printmerchant();                   //��ӡ���˺��������print.cpp��
			mp = "normal";
			if (music == 0)music = 2;          //�����ֿ��ţ�ǿ���л�����
		}

		if (map[i][j] == 'H')                  //�ж�����Ƿ���������ص�
		{
			switch (toward)                    //������ҵ��ƶ���������˻�ԭ��λ��
			{
			case 1:j += 1; break;
			case 2:i -= 1; break;
			case 3:j -= 1; break;
			case 4:i += 1; break;
			}
		}

		switch (map[i][j])                    //�ж��Ƿ�ʰȡ����
		{
		case 'T':pick = 'T'; break;           //ʮ�ָ�
		case 'I':pick = 'I'; break;           //�ݵط���
		case '#':pick = '#'; break;           //С����ҩˮ
		case '%':pick = '%'; break;           //������ҩˮ
		case '+':pick = '+'; break;           //ʥˮ
		case 'G':pick = 'G'; break;           //������ʯ
		case 'g':pick = 'g'; break;           //������ʯ
		case 'k':pick = 'k'; break;           //��Կ��
		case 'K':pick = 'K'; break;           //��Կ��
		case '6':pick = '6'; break;           //��Կ��
		case '9':pick = '9'; break;           //��ʥԿ��
		case 'Z':pick = 'Z'; break;           //����ͼ��
		case 'A':pick = 'A'; break;           //��ʥ��
		case 'a':pick = 'a'; break;           //����
		case 'S':pick = 'S'; break;           //��ʥ��
		case 's':pick = 's'; break;           //����
		case '&':pick = '&'; break;           //���˽��
		case '>':pick = '>'; break;           //��ħ��
		case '<':pick = '<'; break;           //��ħ��
		}

		switch (map[i][j])                    //�ж�ս��״̬
		{
		case'8':bp = '8'; break;              //����
		case'o':bp = 'o'; break;              //ʷ��ķ
		case'e':bp = 'e'; break;              //С����
		case'i':bp = 'i'; break;              //����
		case'n':bp = 'n'; break;              //����
		case'm':bp = 'm'; break;              //���
		case'p':bp = 'p'; break;              //��ʿ
		case'q':bp = 'q'; break;              //����
		case'r':bp = 'r'; break;              //ħ��
		case'h':bp = 'h'; break;              //ѱ����
		case'b':bp = 'b'; break;              //��Ѫ����
		case'P':bp = 'P'; break;              //���öӳ�
		case'B':bp = 'B'; break;              //��ʦ
		case'E':bp = 'E'; break;              //��Ѫ��
		case'Y':bp = 'Y'; break;              //����
		case'W':bp = 'W'; break;              //����Сħ��
		case'V':bp = 'V'; break;              //���޴�ħ��      bad.jpg
		case'N':bp = 'N'; break;              //���޴�ħ��(ȫ)  bad.jpg
		}

		if (useditem == 'I' && level > 1)     //�ж��Ƿ�ʹ�öݵط���
		{
			map[i][j] = ' ';                  //�����λ��ͼ���� @  ��Ϊ�յأ���ֹ�������� ���ͼ�꣩
			level--;                          //����һ��
			jump(map, i, j, level);           //��Ծ���������jump.cpp��
			system("cls");                    //����
			break;
		}

		if (level == 0&&flag == 0)            //�жϴ�����ͷ����
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
				switch (toward)                //������ҵ��ƶ���������˻�ԭ��λ��(���䱣��)
				{
				case 1:j += 1; break;
				case 2:i -= 1; break;
				case 3:j -= 1; break;
				case 4:i += 1; break;
				}
			}
		}

		map[i][j] = player;                   //����ҵ�ǰ����������ͼ��  @
		if (yi != i || yj != j) map[yi][yj] = ' ';//�����ԭ���������ϵ�ͼ�� @ ��Ϊ�յ�

		if (input == '\x1b')menu(level, i, j);
		if (prelevel != level)break;

		bag(map, pick, useditem, input);      //��ӡ�������������bag.cpp��
		printmonster(map);                    //��ӡ����ͼ�� (���print.cpp��

		switch(door)                          //������Կ�׵����
		{
		case 2:cout << endl << '\t' << "����Ҫһ�ѻ�Կ�����򿪻���"; break;
		case 3:cout << endl << '\t' << "����Ҫһ����Կ����������"; break;
		case 4:cout << endl << '\t' << "����Ҫһ�Ѻ�Կ�����򿪺���"; break;
		}   

		switch (win)
		{
		case -1:cout << endl << '\t' << "�Է�����̫�ߣ��������޷�����"; break;
		case -2:level = -1; break;                                                     //����
		case 1:cout << endl << "    ��ϲ��ս��ʤ��,��� " << (playeratt.gold - premoney) << " G,������ͺ�ֽ���һ��"; break;
		case 2:cout << endl << "�Է�û�ܻ�����Ļ��ף�����ȡʤ,��� " << (playeratt.gold - premoney) << " G,������ͺ�ֽ���һ��"; break;
		case 3:cout << endl << '\t' << "�㾹Ȼ����˱���С��ʹ������ħ��ɣ�������"; break;
		case 4:
		{
			cout << endl << '\t' << "ȫʢ��ħ���ǲ��ܵģ�����";
			break;
		}
		case 5:level++; break;
		}

		//����Ա������
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

			bag(map, pick, useditem, input);      //��ӡ�������������bag.cpp��
			printmonster(map);                    //��ӡ����ͼ�� (���print.cpp��

		}
		if (bug == 1)
		{
			cout << "\n\t\t�������ÿ�����ģʽ";
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

		door = 0;                             //���ÿ���ֵ
		win = 0;                              //����ʤ��ֵ
		pick = '\0';                          //����ʰȡ�ĵ���
		bp = '\0';                            //����ս����


		if (level == -1)break;                //����������
		if (level == 25)break;                //��ʤ����
	}
	return level;                             //���ص�ǰ���ڵĲ���
}
