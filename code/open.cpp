#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>

extern struct mybag { int yellowkey; int bluekey; int redkey; int book; int pickaxe; int upstick; }bags;

int openY(int door)
{
	if (bags.yellowkey > 0)     //����Կ����������0
	{
		door = 1;               //door������Ϊ1�������ųɹ�
		bags.yellowkey--;       //��Կ������-1
	}
	else door = 2;              //����door������Ϊ2����������ʧ��
	return door;
}

int openB(int door)
{
	if (bags.bluekey > 0)     //����Կ����������0
	{
		door = 1;             //door������Ϊ1�������ųɹ�
		bags.bluekey--;       //��Կ������-1
	}
	else door = 3;            //����door������Ϊ3����������ʧ��
	return door;
}

int openR(int door)
{
	if (bags.redkey > 0)      //����Կ����������0
	{
		door = 1;             //door������Ϊ1�������ųɹ�
		bags.redkey--;        //��Կ������-1
	}
	else door = 4;            //����door������Ϊ4����������ʧ��
	return door;
}