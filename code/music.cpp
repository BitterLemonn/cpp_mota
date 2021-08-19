#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

using namespace std;

void musicc(string mp,int &music)
{
	if (music == 2)music = 1;
	if (music == 1)                                 //当玩家打开音乐，读取正确音乐播放
	{
		if (mp == "shop")PlaySound(TEXT("Toby Fox - Shop.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		else if (mp == "normal")PlaySound(TEXT("Toby Fox - Once Upon a Time.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		else if (mp == "bossm")PlaySound(TEXT("Toby Fox - But the Earth Refused to Die.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		else if (mp == "merchant")PlaySound(TEXT("Toby Fox - Tem Shop.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		else if (mp == "menu2")PlaySound(TEXT("Toby Fox - Menu (Full).wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		else if(mp == "bossa")PlaySound(TEXT("Toby Fox - MEGALOVANIA.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		music = 0;
	}
	if(music == -1) PlaySound(NULL, NULL, SND_FILENAME);   //当玩家关闭音乐，关闭音乐
	return;
}

void musics(int &music,char input)
{
	if (input == '\\')                                    //当玩家按下 \ 时切换音乐状态
	{
		if (music == -1)music = 1;
		if (music == 0)music = -1;
	}
	return;
}