#include<bits/stdc++.h>
# include <conio.h>
#include<Windows.h>

using namespace std;

extern struct monster
{
	int attact;
	int defence;
	int gold;
	int blood;
}slime, mice, bat, orc, muggle, warrior, skelenton, dragon, dragon_rider, blood_bat, ske_cap, wizard, vampire, werewolf, bing, maou_JR, guard;
extern struct attribute { int blood; int attarct; int defence; int gold; } playeratt;
extern struct mybag { int yellowkey; int bluekey; int redkey; int book; int pickaxe; int upstick; int lucky_gold; }bags;
extern void vivid();

int battle_slime()
{
	if (playeratt.attarct <= slime.defence)return -1;
	if (playeratt.defence >= slime.attact)
	{
		playeratt.gold += slime.gold;
		return 2;
	}
	while (1)
	{
		slime.blood -= (playeratt.attarct - slime.defence);
		if (slime.blood <= 0)
		{
			playeratt.gold += slime.gold;
			return 1;
		}
		playeratt.blood -= (slime.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_mice()
{
	if (playeratt.attarct <= mice.defence)return -1;
	if (playeratt.defence >= mice.attact)
	{
		playeratt.gold += mice.gold;
		return 2;
	}
	while (1)
	{
		mice.blood -= (playeratt.attarct - mice.defence);
		if (mice.blood <= 0)
		{
			playeratt.gold += mice.gold;
			return 1;
		}
		playeratt.blood -= (mice.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_bat()
{
	if (playeratt.attarct <= bat.defence)return -1;
	if (playeratt.defence >= bat.attact)
	{
		playeratt.gold += bat.gold;
		return 2;
	}
	while (1)
	{
		bat.blood -= (playeratt.attarct - bat.defence);
		if (bat.blood <= 0)
		{
			playeratt.gold += bat.gold;
			return 1;
		}
		playeratt.blood -= (bat.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_orc()
{
	if (playeratt.attarct <= orc.defence)return -1;
	if (playeratt.defence >= orc.attact) 
	{
		playeratt.gold += orc.gold;
		return 2;
	}
	while (1)
	{
		orc.blood -= (playeratt.attarct - orc.defence);
		if (orc.blood <= 0)
		{
			playeratt.gold += orc.gold;
			return 1;
		}
		playeratt.blood -= (orc.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_muggle()
{
	if (playeratt.attarct <= muggle.defence)return -1;
	if (playeratt.defence >= muggle .attact)
	{
		playeratt.gold += muggle.gold;
		return 2;
	}
	while (1)
	{
		muggle.blood -= (playeratt.attarct - muggle.defence);
		if (muggle.blood <= 0)
		{
			playeratt.gold += muggle.gold;
			return 1;
		}
		playeratt.blood -= (muggle.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_warrior()
{
	if (playeratt.attarct <= warrior.defence)return -1;
	if (playeratt.defence >= warrior.attact)
	{
		playeratt.gold += warrior.gold;
		return 2;
	}
	while (1)
	{
		warrior.blood -= (playeratt.attarct - warrior.defence);
		if (warrior.blood <= 0)
		{
			playeratt.gold += warrior.gold;
			return 1;
		}
		playeratt.blood -= (warrior.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_skelenton()
{
	if (playeratt.attarct <= skelenton.defence)return -1;
	if (playeratt.defence >= skelenton.attact)
	{
		playeratt.gold += skelenton.gold;
		return 2;
	}
	int n = 1;
	while (1)
	{
		skelenton.blood -= (playeratt.attarct - skelenton.defence);
		if (skelenton.blood <= 0 && n == 0)
		{
			playeratt.gold += skelenton.gold;
			return 1;
		}
		if (skelenton.blood <= 0 && n != 0)
		{
			vivid();
			skelenton.blood *= 0.2;
			n = 0;
		}
		playeratt.blood -= (skelenton.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}


int battle_dragon()
{
	if (playeratt.attarct <= dragon.defence)return -1;
	if (playeratt.defence >= dragon.attact)
	{
		playeratt.gold += dragon.gold;
		return 2;
	}
	while (1)
	{
		dragon.blood -= (playeratt.attarct - dragon.defence);
		if (dragon.blood <= 0)
		{
			playeratt.gold += dragon.gold;
			return 1;
		}
		playeratt.blood -= (dragon.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}


int battle_dragon_rider()
{
	if (playeratt.attarct <= dragon_rider.defence)return -1;
	if (playeratt.defence >= dragon_rider.attact)
	{
		playeratt.gold += dragon_rider.gold;
		return 2;
	}
	while (1)
	{
		dragon_rider.blood -= (playeratt.attarct - dragon_rider.defence);
		if (dragon_rider.blood <= 0)
		{
			playeratt.gold += dragon_rider.gold;
			return 1;
		}
		playeratt.blood -= (dragon_rider.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_blood_bat()
{
	if (playeratt.attarct <= blood_bat.defence)return -1;
	if (playeratt.defence >= blood_bat.attact)
	{
		playeratt.gold += blood_bat.gold;
		return 2;
	}
	while (1)
	{
		blood_bat.blood -= (playeratt.attarct - blood_bat.defence);
		if (blood_bat.blood <= 0)
		{
			playeratt.gold += blood_bat.gold;
			return 1;
		}
		playeratt.blood -= (blood_bat.attact - playeratt.defence);
		blood_bat.blood += (blood_bat.attact - playeratt.defence) * 0.1;
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_ske_cap()
{
	if (playeratt.attarct <= ske_cap.defence)return -1;
	if (playeratt.defence >= ske_cap.attact)
	{
		playeratt.gold += ske_cap.gold;
		return 2;
	}
	int n = 1;
	while (1)
	{
		ske_cap.blood -= (playeratt.attarct - ske_cap.defence);
		if (ske_cap.blood <= 0 && n == 0)
		{
			playeratt.gold += ske_cap.gold;
			return 1;
		}
		if (ske_cap.blood <= 0 && n != 0)
		{
			vivid();
			ske_cap.blood *= 0.5;
			n = 0;
		}
		playeratt.blood -= (ske_cap.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_wizard()
{
	if (playeratt.attarct <= wizard.defence)return -1;
	if (playeratt.defence * 0.2 >= wizard.attact)
	{
		playeratt.gold += wizard.gold;
		return 2;
	}
	while (1)
	{
		wizard.blood -= (playeratt.attarct - wizard.defence);
		if (wizard.blood <= 0)
		{
			playeratt.gold += wizard.gold;
			return 1;
		}
		playeratt.blood -= (wizard.attact - playeratt.defence * 0.2);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_vampire()
{
	if (playeratt.attarct <= vampire.defence)return -1;
	if (playeratt.defence >= vampire.attact)
	{
		playeratt.gold += vampire.gold;
		return 2;
	}
	while (1)
	{
		vampire.blood -= (playeratt.attarct - vampire.defence);
		if (vampire.blood <= 0)
		{
			playeratt.gold += vampire.gold;
			return 1;
		}
		playeratt.blood -= (vampire.attact - playeratt.defence);
		vampire.blood += (vampire.attact - playeratt.defence) * 0.3;
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_werewolf()
{
	if (playeratt.attarct <= werewolf.defence)return -1;
	if (playeratt.defence >= werewolf.attact)
	{
		playeratt.gold += werewolf.gold;
		return 1;
	}
	while (1)
	{
		werewolf.blood -= (playeratt.attarct - werewolf.defence);
		if (werewolf.blood <= 0)
		{
			playeratt.gold += werewolf.gold;
			return 1;
		}
		playeratt.blood -= (werewolf.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
	}
}

int battle_bing()
{
	if (playeratt.attarct <= bing.defence)return -1;
	if (playeratt.defence >= bing.attact) 
	{
		playeratt.gold += bing.gold;
		return 3;
	}
	int n = 0;
	while (1)
	{
		bing.blood -= (playeratt.attarct - bing.defence);
		if (bing.blood <= 0)
		{
			playeratt.gold += bing.gold;
			return 3;
		}
		playeratt.blood -= (bing.attact - playeratt.defence);
		if (playeratt.blood <= 0)return -2;
		n++;
		if (n == 3)
		{
			playeratt.blood -= (bing.attact - playeratt.defence);
			n = 0;
		}
	}
}

int battle_maou_JR()
{
	if (playeratt.attarct <= maou_JR.defence)return -1;
	if (playeratt.defence >= maou_JR.attact)return 5;
	int n = 0;
	while (1)
	{
		maou_JR.blood -= (playeratt.attarct - maou_JR.defence);
		if (maou_JR.blood <= 0)
		{
			return 5;
		}
	}
}

int battle_JR()
{
	return 4;
}

int battle_guard()
{
	playeratt.blood *= 0.75;
	playeratt.gold += guard.gold;
	return 1;
}



void battle(char bp,int &win)
{
	vivid();
	if(bags.lucky_gold == 1)
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
		ske_cap.gold *= 2;
		wizard.gold *= 2;
		vampire.gold *= 2;
		werewolf.gold *= 2;
		bing.gold *= 2;
		slime.attact *= 1.1;
		mice.attact *= 1.1;
		bat.attact *= 1.1;
		orc.attact *= 1.1;
		muggle.attact *= 1.1;
		warrior.attact *= 1.1;
		skelenton.attact *= 1.1;
		dragon.attact *= 1.1;
		dragon_rider.attact *= 1.1;
		blood_bat.attact *= 1.1;
		ske_cap.attact *= 1.1;
		wizard.attact *= 1.1;
		vampire.attact *= 1.1;
		werewolf.attact *= 1.1;
		bing.attact *= 1.1;
	}
	switch(bp)
	{
	case'8':win = battle_guard(); break;            //ÊØÎÀ
	case'o':win = battle_slime(); break;            //Ê·À³Ä·
	case'e':win = battle_mice(); break;             //Ð¡ÀÏÊó
	case'i':win = battle_bat(); break;              //òùòð
	case'n':win = battle_orc(); break;              //ÊÞÈË
	case'm':win = battle_muggle(); break;           //Âé¹Ï
	case'p':win = battle_warrior(); break;          //ÎäÊ¿
	case'q':win = battle_skelenton(); break;        //÷¼÷Ã
	case'r':win = battle_dragon(); break;           //Ä§Áú
	case'h':win = battle_dragon_rider(); break;     //Ñ±ÁúÕß
	case'b':win = battle_blood_bat(); break;        //ÎüÑªòùòð
	case'P':win = battle_ske_cap(); break;          //÷¼÷Ã¶Ó³¤
	case'B':win = battle_wizard(); break;           //Î×Ê¦
	case'E':win = battle_vampire(); break;          //ÎüÑª¹í
	case'Y':win = battle_werewolf(); break;         //ÀÇÈË
	case'W':win = battle_bing(); break;             //±ù±ùÐ¡Ä§Íõ
	case'V':win = battle_maou_JR(); break;          //¼ÓÈÞ´óÄ§Íõ
	case'N':win = battle_JR(); break;               //¼ÓÈÞ´óÄ§Íõ(È«)
	}
}