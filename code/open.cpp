#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>

extern struct mybag { int yellowkey; int bluekey; int redkey; int book; int pickaxe; int upstick; }bags;

int openY(int door)
{
	if (bags.yellowkey > 0)     //若黄钥匙数量大于0
	{
		door = 1;               //door变量变为1，即开门成功
		bags.yellowkey--;       //黄钥匙数量-1
	}
	else door = 2;              //否则door变量变为2，即开黄门失败
	return door;
}

int openB(int door)
{
	if (bags.bluekey > 0)     //若蓝钥匙数量大于0
	{
		door = 1;             //door变量变为1，即开门成功
		bags.bluekey--;       //蓝钥匙数量-1
	}
	else door = 3;            //否则door变量变为3，即开蓝门失败
	return door;
}

int openR(int door)
{
	if (bags.redkey > 0)      //若红钥匙数量大于0
	{
		door = 1;             //door变量变为1，即开门成功
		bags.redkey--;        //红钥匙数量-1
	}
	else door = 4;            //否则door变量变为4，即开红门失败
	return door;
}