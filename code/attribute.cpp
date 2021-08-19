#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct attribute { int blood = 10000; int attarct = 5000; int defence = 3500; int gold = 0; }playeratt;

void att(attribute &playeratt,char map[10][26],int &i,int &j,int key)
{
	if (key == 1)
	{
		playeratt.blood = 1000;
		playeratt.attarct = 10;
		playeratt.defence = 10;
	}
	return;
}