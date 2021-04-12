#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<math.h>

using namespace std;

bool Straight_Flush(int Player[5])
{
	int s = Player[0] / 13;
	for (int i = 1; i < 5; i++)
		if (Player[i] / 13 != s) return 0;

	for (int i = 0; i < 5; i++)
		Player[i] %= 13;

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (Player[i] > Player[j]) swap(Player[i], Player[j]);

	for (int i = 0; i < 4; i++)
		if (abs(Player[i] - Player[i+1]) != 1) return 0;

	return 1;
}

bool Four_of_a_kind(int Player[5])
{
	int d = 0;
	for (int i = 0; i < 4; i++)
		if (Player[i] % 13 == Player[i + 1] % 13) d++;

	if (d == 3) return 1;
	return 0;
}

bool Fullhouse(int Player[5])
{
	int c1=0, c2=0;
	for (int i = 0; i < 4; i++)
		Player[i] %= 13;
	
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (Player[i] > Player[j]) swap(Player[i], Player[j]);

	for (int i = 0; i < 4; i++)
	{
		if (Player[1] == Player[i + 1]) c1++;
		if (Player[4] == Player[4 - i - 1]) c2++;
	}

	if (c1 == 3 && c2 == 2 || c2 == 3 && c1 == 2) return 1;
	return 0;
}

bool Straight(int Player[5])
{
	for (int i = 0; i < 5; i++)
		Player[i] %= 13;

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (Player[i] > Player[j]) swap(Player[i], Player[j]);

	for (int i = 0; i < 4; i++)
		if (abs(Player[i] - Player[i+1]) != 1) return 0;

	int s = 0;
	for (int i = 1; i < 5; i++)
		if (Player[i] / 13 == Player[0] / 13) s++;

	if (s == 4) return 0;
	return 1;
}

bool Flush(int Player[5])
{
	int s = Player[0] / 13;
	for (int i = 1; i < 5; i++)
		if (Player[i] / 13 != s) return 0;

	if (!Straight(Player)) return 1;
	return 0;
}


bool Three_of_a_kind(int Player[5])
{
	if (Fullhouse(Player)) return 0;
	
	for (int i = 0; i < 4; i++)
	{
		int c = 0;
		for (int j = i + 1; j < 5; j++)
			if (Player[i] % 13 == Player[j] % 13) c++;
		if (c == 3) return 1;
	}
	return 0;
}

bool TwoPair(int Player[5])
{

}