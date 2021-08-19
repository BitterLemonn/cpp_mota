#include<bits/stdc++.h>
# include <conio.h>
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define star "    **************************" 
using namespace std;

extern int music;
extern string mp;

void start()
{
	while (1)
	{
		if(music == 0|| music == 1)PlaySound(TEXT("Toby Fox - Start Menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		cout << '\t' << star << endl;
		cout << endl << endl << endl << endl;
		cout << '\t' << '\t' << "魔塔2019(极简版)";
		cout << endl << endl << endl << endl;
		cout << '\t' << '\t' << "(按任意键开始游戏)";
		cout << endl << endl << endl << endl;
		cout << '\t' << star << endl;
		if (_getch() != '\0')
		{
			system("cls");
			break;
		}
	}
	return;
}