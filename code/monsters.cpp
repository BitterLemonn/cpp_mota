#include<bits/stdc++.h>
# include <conio.h>
#include<Windows.h>

extern struct attribute { int blood; int attarct; int defence; int gold; }playeratt;

struct monster
{
	int attact = 0;
	int defence = 0;
	int gold = 0;
	int blood = 0;
}slime, mice, bat, orc, muggle, warrior, skelenton, dragon, dragon_rider, blood_bat, ske_cap, wizard, vampire, werewolf, bing, maou_JR, JR,guard;

void vivid()
{
	guard.blood = 1;
	guard.attact = playeratt.defence + 1;
	guard.defence = playeratt.attarct + 1;
	guard.gold = 20;

	slime.blood = 50;
	slime.attact = 20;
	slime.defence = 1;
	slime.gold = 1;

	mice.blood = 70;
	mice.attact = 15;
	mice.defence = 2;
	mice.gold = 2;

	bat.blood = 100;
	bat.attact = 20;
	bat.defence = 5;
	bat.gold = 3;

	orc.blood = 150;
	orc.attact = 40;
	orc.defence = 20;
	orc.gold = 6;

	muggle.blood = 150;
	muggle.attact = 65;
	muggle.defence = 30;
	muggle.gold = 8;

	warrior.blood = 300;
	warrior.attact = 75;
	warrior.defence = 45;
	warrior.gold = 10;

	skelenton.blood = 250;
	skelenton.attact = 120;
	skelenton.defence = 70;
	skelenton.gold = 20;

	dragon.blood = 400;
	dragon.attact = 90;
	dragon.defence = 50;
	dragon.gold = 15;

	dragon_rider.blood = 450;
	dragon_rider.attact = 150;
	dragon_rider.defence = 90;
	dragon_rider.gold = 25;

	blood_bat.blood = 500;
	blood_bat.attact = 120;
	blood_bat.defence = 100;
	blood_bat.gold = 35;

	ske_cap.blood = 700;
	ske_cap.attact = 250;
	ske_cap.defence = 125;
	ske_cap.gold = 32;

	wizard.blood = 500;
	wizard.attact = 400;
	wizard.defence = 260;
	wizard.gold = 45;

	vampire.blood = 1300;
	vampire.attact = 300;
	vampire.defence = 150;
	vampire.gold = 50;

	werewolf.blood = 2000;
	werewolf.attact = 680;
	werewolf.defence = 590;
	werewolf.gold = 70;

	bing.blood = 1200;
	bing.attact = 980;
	bing.defence = 900;
	bing.gold = 88;

	maou_JR.blood = 15000;
	maou_JR.attact = 1000;
	maou_JR.defence = 1000;
	maou_JR.gold = 0;

	JR.blood = 99999;
	JR.attact = 9999;
	JR.defence = 5000;
	JR.gold = 0;
}
