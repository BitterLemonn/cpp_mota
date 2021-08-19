#include<bits/stdc++.h>
#include <conio.h> 

using namespace std;

void jump(char map[10][26], int& i, int& j, int level)
{
	switch (level)
	{
		case 1: {i = 5; j = 12; break; }
		case 2: {i = 8; j = 2; break; }
		case 3: {i = 2; j = 24; break; }
		case 4: {i = 1; j = 5; break; }
		case 5: {i = 8; j = 2; break; }
		case 6: {i = 8; j = 23; break; }
		case 7: {i = 1; j = 7; break; }
		case 8: {i = 2; j = 24; break; }
		case 9: {i = 8; j = 2; break; }
		case 10: {i = 1; j = 20; break; }
		case 11: {i = 4; j = 12; break; }
		case 12: {i = 6; j = 12; break; }
		case 13: {i = 1; j = 23; break; }
		case 14: {i = 8; j = 6; break; }
		case 15: {i = 1; j = 12; break; }
		case 16: {i = 3; j = 22; break; }
		case 17: {i = 8; j = 8; break; }
		case 18: {i = 8; j = 10; break; }
		case 19: {i = 1; j = 1; break; }
		case 20: {i = 1; j = 24; break; }
		case 21: {i = 8; j = 6; break; }
		case 22: {i = 2; j = 24; break; }
		case 23: {i = 8; j = 8; break; }
		case 24: {i = 1; j = 24; break; }
		case 25: {i = 1; j = 24; break; }
	}
	return;
}