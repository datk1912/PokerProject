#include"typecard.h"

using namespace std;

const char* number[]{ "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
const char* suits[] = { "\3", "\4", "\5", "\6" };

bool check(int** a, int x)
{
	int s = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			if (x == a[i][j]) s++;
	if (s <= 1) return 1;
	return 0;
}

void shuffleCards(int** deck)
{
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			deck[i][j] = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
			do
			{
				deck[i][j] = rand() % 52;
			} while (check(deck, deck[i][j]) == 0);
	}
}

void deletee(int** deck)
{
	for (int i = 0; i < 4; i++)
		delete[] deck[i];
	delete[] deck;
}

void printCardsShuffling(Data a[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << a[i * 13 + j].s << "-" << a[i * 13 + j].P << "\0";
			if (i * 13 + j < 10) cout << " ";
			cout << "|";
		}
		cout << endl;
	}
}

void khoitao(Data a[52], int** deck)
{
	int k = 0;
	string s;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			a[i * 13 + j].P = k++;
			s = suits[i];
			a[i * 13 + j].s = number[j];
			a[i * 13 + j].s += s;
		}
}

void sort(Data a[], int** deck)
{
	int* c = new int[52];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			c[i * 13 + j] = deck[i][j];
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			if (a[j].P == c[i])
			{
				swap(a[i], a[j]);
			}
	delete[] c;
}

//================== kiem tra bai ============================

bool isStraightFlush(int Player[5])       //Thung pha sanh
{
	int s = Player[0] / 13;
	for (int i = 1; i < 5; i++)
		if (Player[i] / 13 != s) return 0;

	int* c = new int[5];
	for (int i = 0; i < 5; i++)
		c[i] = Player[i] % 13;

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (c[i] > c[j]) swap(c[i], c[j]);

	for (int i = 0; i < 4; i++)
		if (abs(c[i] - c[i + 1]) != 1) return 0;
	delete[] c;
	return 1;
}

bool isFourOfAKind(int Player[5])            //Tứ quý
{
	int d = 0, max = 0;
	for (int i = 0; i < 2; i++)
	{
		d = 0;
		for (int j = i + 1; j < 5; j++)
			if (Player[i] % 13 == Player[j] % 13) d++;
		if (max < d)
			max = d;
	}
	if (max == 3) return 1;
	return 0;
}

bool isFullHouse(int Player[5])           //Cù lũ
{
	int c1 = 0, c2 = 0, * c;
	c = new int[5];
	for (int i = 0; i < 5; i++)
		c[i] = Player[i] % 13;

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (c[i] > c[j]) swap(c[i], c[j]);

	for (int i = 0; i < 5; i++)
	{
		if (c[0] == c[i + 1]) c1++;
		if (c[4] == c[4 - i - 1]) c2++;
	}
	delete[]c;
	if (c1 == 2 && c2 == 1 || c2 == 2 && c1 == 1) return 1;
	return 0;
}

bool isFlush(int Player[5])               //Thùng
{
	int s = Player[0] / 13;
	for (int i = 1; i < 5; i++)
		if (Player[i] / 13 != s) return 0;

	if (!isStraight(Player)) return 1;
	return 0;
}

bool isStraight(int Player[5])            //Sảnh
{
	int* c = new int[5];
	for (int i = 0; i < 5; i++)
		c[i] = Player[i] % 13;

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (c[i] > c[j]) swap(c[i], c[j]);

	for (int i = 0; i < 4; i++)
		if (abs(c[i] - c[i + 1]) != 1) return 0;

	int s = 0;
	for (int i = 1; i < 5; i++)
		if (Player[i] / 13 == Player[0] / 13) s++;
	delete[]c;
	if (s == 4) return 0;
	return 1;
}

bool isThreeOfAKind(int Player[5])           //Sám cô
{
	if (isFullHouse(Player)) return 0;

	for (int i = 0; i < 4; i++)
	{
		int c = 0;
		for (int j = i + 1; j < 5; j++)
			if (Player[i] % 13 == Player[j] % 13) c++;
		if (c == 2) return 1;
	}
	return 0;
}

bool isTwoPairs(int Player[5])          //Thú
{
	int c1 = 0, c2 = 0;
	int* c = new int[5];
	for (int i = 0; i < 5; i++)
		c[i] = Player[i] % 13;

	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (c[i] > c[j]) swap(c[i], c[j]);
	if (c[0] != c[1] || c[4] != c[3])
	{
		if (c[0] != c[1])
		{
			for (int i = 2; i < 5; i++)
			{
				if (c[1] == c[i])
					c1++;
				if (c[4] == c[4 - i + 1])
					c2++;
			}
		}
		else
			if (c[4] != c[3])
			{
				for (int i = 1; i < 4; i++)
				{
					if (c[0] == c[i])
						c1++;
					if (c[3] == c[3 - i])
						c2++;
				}
			}
	}
	if (c[0] == c[1] && c[4] == c[3])
	{
		for (int i = 0; i < 5; i++)
		{
			if (c[0] == c[i])
				c1++;
			if (c[4] == c[5 - i - 1])
				c2++;
		}
	}
	if (c1 != 1 && c2 != 1)
		return 0;
	if (c1 == 1 && c2 != 1 || c1 != 1 && c2 == 1)
		return 0;
	return 1;
}

bool isPair(int Player[5])
{
	int count = 0;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (Player[i] % 13 == Player[j] % 13)
				count++;
	if (count == 1)
		return 1;
	return 0;
}

// ======================================================

int  getStatusOfHand(int Player[5]) // tinh diem
{
	if (isStraightFlush(Player))
		return 8;
	if (isFourOfAKind(Player))
		return 7;
	if (isFullHouse(Player))
		return 6;
	if (isFlush(Player))
		return 5;
	if (isStraight(Player))
		return 4;
	if (isThreeOfAKind(Player))
		return 3;
	if (isTwoPairs(Player))
		return 2;
	if (isPair(Player))
		return 1;
	return 0;
}

void printHand(Data a[])
{
	for (int i = 0; i < 5; i++)
		cout << a[i].s << " ";
	cout << endl;
}

void dealingForHand(Data a[], int Player[5]) // chia bai cho 1 nguoi
{
	for (int i = 0; i < 5; i++)
		Player[i] = a[i].P;
	cout << "Your Cards: " << endl;
	printHand(a);
	int p = getStatusOfHand(Player);
	cout << "Your Point:  " << p << endl;
	cout << "the Highest Card: " << number[getHighestCard(Player) % 13] << suits[getHighestCard(Player) / 13] << endl;

}

void createHandTest(Data a[]) // chon 5 la de kiem tra
{
	int t[5];
	bool fl[52] = { 0 };
	cout << endl;
	cout << "choose whatever 5 cards you want: " << endl;
	for (int i = 0; i < 5; i++)
		while (true)
		{
			cout << "card " << i + 1 << ": ";
			cin >> t[i];
			if (fl[t[i]] == 0)
			{
				fl[t[i]] = 1;
				break;
			}
			else if (fl[t[i]] == 1 || t[i] > 51 || t[i] < 1) cout << "card " << i + 1 << " error!" << endl;

		}


	cout << "Your Cards: " << endl;
	for (int i = 0; i < 5; i++)
		cout << a[t[i]].s << " ";
	cout << endl;
	int point = getStatusOfHand(t);
	cout << "Your Point: " << point << endl;
	cout << "The Highest Card: " << number[getHighestCard(t) % 13] << suits[getHighestCard(t) / 13] << endl;

}

void rankingHands(int po[], int n, Data a[])
{
	int c[10];
	for (int i = 0; i < n; i++)
		c[i] = i + 1;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (po[i] < po[j])
			{
				swap(po[i], po[j]);
				swap(c[i], c[j]);
			}
		}

	int k = 1;
	cout << "==== top " << k << " ==== " << endl;
	cout << "player " << c[0] << ": ";

	for (int i = 0; i < 5; i++)
		cout << a[c[0] - 1 + i * n].s << "  ";
	cout << "- point: " << po[0] << endl;

	for (int i = 1; i < n; i++)
	{
		if (po[i] != po[i - 1]) cout << "==== top " << ++k << " ==== " << endl;;
		cout << "player " << c[i] << ": ";

		for (int j = 0; j < 5; j++)
			cout << a[c[i] - 1 + j * n].s << "  ";

		cout << "- point: " << po[i] << endl;
	}

}

void dealingForHands(Data a[], int Player[10][5], int am, int*& ans)
{


	for (int i = 0; i < am; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Player[i][j] = a[i + j * am].P;
		}
		po[i] = getStatusOfHand(Player[i]);

	}

	ans = evaluateHands(po, am, ans);
	rankingHands(po, am, a);
}

int getHighestCard(int Player[5])
{
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (Player[i] % 13 > max % 13) max = Player[i];
	}
	return max;
}

int* evaluateHands(int po[], int n, int*& a)
{
	for (int i = 0; i < n; i++)
		a[i] += po[i];
	return a;
}

int checkbai(int Player[8], int n)
{
	int max = 0, a[5];
	for (int i1 = 0; i1 < n - 5 + 1; i1++)
		for (int i2 = i1 + 1; i2 < n - 5 + 2; i2++)
			for (int i3 = i2 + 1; i3 < n - 5 + 3; i3++)
				for (int i4 = i3 + 1; i4 < n - 5 + 4; i4++)
					for (int i5 = i4 + 1; i5 < n - 5 + 5; i5++)
					{
						a[0] = Player[i1]; a[1] = Player[i2]; a[2] = Player[i3]; a[3] = Player[i4]; a[4] = Player[i5];
						if (max < getStatusOfHand(a)) max = getStatusOfHand(a);
					}
	return max;
}



void dealer(Data a[], int Dealer[8], int Player[5][8], int n, int level)
{
	int nP = 5, nD = 5;
	if (level == 1) nP = 8;
	else if (level == 3) nD = 8;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < nP; j++)
			Player[i][j] = a[i + j * n].P;
		po[i] = checkbai(Player[i], nP);
	}

	for (int i = 0; i < nD; i++)
		Dealer[i] = a[n - 1 + i * n].P;
	po[n - 1] = checkbai(Dealer, nD);

	int c[10];
	for (int i = 0; i < n; i++)
		c[i] = i + 1;

	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			cout << "Player " << i + 1 << endl;
			for (int j = 0; j < nP; j++)
				cout << a[i + j * n].s << " ";
			cout << endl;
			cout << "point : " << po[c[i] - 1] << endl << endl;
		}
		else
		{
			cout << "Dealer " << endl;
			for (int j = 0; j < nD; j++)
				cout << a[i + j * n].s << " ";
			cout << endl;
			cout << "point : " << po[i] << endl << endl;
		}
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (po[i] < po[j])
			{
				swap(po[i], po[j]);
				swap(c[i], c[j]);
			}
		}



	if (po[n - 1] == po[0]) cout << "===== Tie! =====" << endl;
	else
	{
		cout << "===== The Winner =====" << endl;

		for (int i = 0; i < n; i++)
			if (po[i] == po[0])
				if (c[i] == n) cout << "- Dealer" << endl;
				else cout << "- Player " << c[i] << endl;

	}
	cout << endl;

}

void poker()
{
	int n = 0, m = 12;
	do {
		switch (n)
		{
		case 0:
			system("cls");
			for (int i = 0; i < 9; i++)
				cout << endl;
			SetColor(11);
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			SetColor(7);
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**    **" << endl;
			break;
		case 1:
			system("cls");
			for (int i = 0; i < 9; i++)
				cout << endl;
			SetColor(14);
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			SetColor(11);
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			SetColor(7);
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**    **" << endl;
			break;
		case 2:
			system("cls");
			for (int i = 0; i < 9; i++)
				cout << endl;
			SetColor(6);
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			SetColor(14);
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			SetColor(11);
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**  **" << endl;
			SetColor(7);
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**    **" << endl;
			break;
		case 3:
			system("cls");
			for (int i = 0; i < 9; i++)
				cout << endl;
			SetColor(4);
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			SetColor(6);
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			SetColor(14);
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**  **" << endl;
			SetColor(11);
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**    **" << endl;
			break;
		}
		Sleep(200);
		n++;
		n %= 4;
		m--;
	} while (m != 0);
}

void P()
{
	cout << "\t\t\t\t" << " ******" << endl;
	cout << "\t\t\t\t" << "**    **" << endl;
	cout << "\t\t\t\t" << "**    **" << endl;
	cout << "\t\t\t\t" << "*******" << endl;
	cout << "\t\t\t\t" << "**" << endl;
	cout << "\t\t\t\t" << "**" << endl;
	cout << "\t\t\t\t" << "**" << endl;
	cout << "\t\t\t\t" << "**" << endl;
}

void O()
{
	cout << "\t\t\t\t\t" << "     *****" << endl;
	cout << "\t\t\t\t\t" << "   **     **" << endl;
	cout << "\t\t\t\t\t" << "  **       **" << endl;
	cout << "\t\t\t\t\t" << "  **       **" << endl;
	cout << "\t\t\t\t\t" << "  **       **" << endl;
	cout << "\t\t\t\t\t" << "  **       **" << endl;
	cout << "\t\t\t\t\t" << "   **     **" << endl;
	cout << "\t\t\t\t\t" << "     *****" << endl;
}

void K()
{
	cout << "\t\t\t\t\t\t" << "       **   **" << endl;
	cout << "\t\t\t\t\t\t" << "       **  **" << endl;
	cout << "\t\t\t\t\t\t" << "       ** **" << endl;
	cout << "\t\t\t\t\t\t" << "       ****" << endl;
	cout << "\t\t\t\t\t\t" << "       ****" << endl;
	cout << "\t\t\t\t\t\t" << "       ** **" << endl;
	cout << "\t\t\t\t\t\t" << "       **  **" << endl;
	cout << "\t\t\t\t\t\t" << "       **   **" << endl;
}

void E()
{
	cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
	cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
}

void R()
{
	cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << " **  **" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << " **    **" << endl;
}

void animation()
{
	int k = 0, n = 20, a = 1;
	do
	{
		system("cls");
		for (int i = 0; i < k; i++)
			cout << endl;
		P();
		k++;
		Sleep(n);
		n -= 1;
	} while (k != 10);
	n = 20;
	k = 0;
	do
	{
		system("cls");
		if (k < 2)
		{
			if (k != 2)
			{
				for (int i = 0; i < k; i++)
				{
					if (k >= 2)
						break;
					else
						cout << endl;
				}
				O();
			}
			if (k == 0)
				cout << endl;
			P();
			Sleep(n);
		}

		if (k == 2)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t\t" << "     *****" << endl;
			cout << "\t\t\t\t\t" << "   **     **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "   **     **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << endl;
			cout << "\t\t\t\t" << "**    **" << endl;
			cout << "\t\t\t\t" << "**    **" << endl;
			cout << "\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			Sleep(n);
		}

		if (k == 3)
		{
			system("cls");
			cout << endl << endl << endl;
			cout << "\t\t\t\t\t" << "     *****" << endl;
			cout << "\t\t\t\t\t" << "   **     **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t" << " ******" << "  " << "  **     **" << endl;
			cout << "\t\t\t\t" << "**    **" << "   " << "  *****" << endl;
			cout << "\t\t\t\t" << "**    **" << endl;
			cout << "\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			Sleep(n);
		}

		if (k == 4)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t\t" << "     *****" << endl;
			cout << "\t\t\t\t\t" << "   **     **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t" << " ******" << " " << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << " " << "  **     **" << endl;
			cout << "\t\t\t\t" << "**    **" << "   " << "  *****" << endl;
			cout << "\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			Sleep(n);
		}

		if (k == 5)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t" << "     *****" << endl;
			cout << "\t\t\t\t\t" << "   **     **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t" << " ******" << " " << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << "" << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << " " << "  **     **" << endl;
			cout << "\t\t\t\t" << "*******" << "    " << "  *****" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			Sleep(n);
		}

		if (k == 6)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t" << "     *****" << endl;
			cout << "\t\t\t\t\t" << "   **     **" << endl;
			cout << "\t\t\t\t\t" << "  **       **" << endl;
			cout << "\t\t\t\t" << " ******" << " " << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << "" << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << "" << "  **       **" << endl;
			cout << "\t\t\t\t" << "*******" << "  " << "  **     **" << endl;
			cout << "\t\t\t\t" << "**" << "         " << "  *****" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			Sleep(n);
		}

		if (k == 7)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t" << "     *****" << endl;
			cout << "\t\t\t\t\t" << "   **     **" << endl;
			cout << "\t\t\t\t" << " ******" << " " << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << "" << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << "" << "  **       **" << endl;
			cout << "\t\t\t\t" << "*******" << " " << "  **       **" << endl;
			cout << "\t\t\t\t" << "**" << "       " << "  **     **" << endl;
			cout << "\t\t\t\t" << "**" << "         " << "  *****" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			Sleep(n);
		}

		if (k == 8)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t" << "     *****" << endl;
			cout << "\t\t\t\t" << " ******" << " " << "   **     **" << endl;
			cout << "\t\t\t\t" << "**    **" << "" << "  **       **" << endl;
			cout << "\t\t\t\t" << "**    **" << "" << "  **       **" << endl;
			cout << "\t\t\t\t" << "*******" << " " << "  **       **" << endl;
			cout << "\t\t\t\t" << "**" << "      " << "  **       **" << endl;
			cout << "\t\t\t\t" << "**" << "       " << "  **     **" << endl;
			cout << "\t\t\t\t" << "**" << "         " << "  *****" << endl;
			cout << "\t\t\t\t" << "**" << endl;
			Sleep(n);
		}

		if (k == 9)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
		}
		n -= 1;
		k++;
	} while (k != 10);
	n = 20;
	k = 0;
	do
	{
		system("cls");
		if (k < 2)
		{
			if (k != 2)
			{
				for (int i = 0; i < k; i++)
				{
					if (k >= 2)
						break;
					else
						cout << endl;
				}
				K();
			}
			if (k == 0)
				cout << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 2)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t\t\t" << "       **   **" << endl;
			cout << "\t\t\t\t\t\t" << "       **  **" << endl;
			cout << "\t\t\t\t\t\t" << "       ** **" << endl;
			cout << "\t\t\t\t\t\t" << "       ****" << endl;
			cout << "\t\t\t\t\t\t" << "       ****" << endl;
			cout << "\t\t\t\t\t\t" << "       ** **" << endl;
			cout << "\t\t\t\t\t\t" << "       **  **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 3)
		{
			system("cls");
			cout << endl << endl << endl;
			cout << "\t\t\t\t\t\t" << "       **   **" << endl;
			cout << "\t\t\t\t\t\t" << "       **  **" << endl;
			cout << "\t\t\t\t\t\t" << "       ** **" << endl;
			cout << "\t\t\t\t\t\t" << "       ****" << endl;
			cout << "\t\t\t\t\t\t" << "       ****" << endl;
			cout << "\t\t\t\t\t\t" << "       ** **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**  **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 4)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t" << "       **   **" << endl;
			cout << "\t\t\t\t\t\t" << "       **  **" << endl;
			cout << "\t\t\t\t\t\t" << "       ** **" << endl;
			cout << "\t\t\t\t\t\t" << "       ****" << endl;
			cout << "\t\t\t\t\t\t" << "       ****" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "** **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 5)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t" << "       **   **" << endl;
			cout << "\t\t\t\t\t\t" << "       **  **" << endl;
			cout << "\t\t\t\t\t\t" << "       ** **" << endl;
			cout << "\t\t\t\t\t\t" << "       ****" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "****" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "** **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "**  **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 6)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t" << "       **   **" << endl;
			cout << "\t\t\t\t\t\t" << "       **  **" << endl;
			cout << "\t\t\t\t\t\t" << "       ** **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "****" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "****" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 7)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t" << "       **   **" << endl;
			cout << "\t\t\t\t\t\t" << "       **  **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "** **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "****" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 8)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t" << "       **   **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**  **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "** **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << endl;
			Sleep(n);
		}

		if (k == 9)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}
		k++;
		n -= 1;
	} while (k != 10);
	n = 20;
	k = 0;
	do
	{
		system("cls");
		if (k < 2)
		{
			if (k != 2)
			{
				for (int i = 0; i < k; i++)
				{
					if (k >= 2)
						break;
					else
						cout << endl;
				}
				E();
			}
			if (k == 0)
				cout << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 2)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 3)
		{
			system("cls");
			cout << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "*******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 4)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "*******" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 5)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 6)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "*******" << endl;;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 7)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "**" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "*******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "*******" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 8)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t" << "*******" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "*******" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << endl;
			Sleep(n);
		}

		if (k == 9)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}
		k++;
		n -= 1;
	} while (k != 10);
	n = 20;
	k = 0;

	do
	{
		system("cls");
		if (k < 2)
		{
			if (k != 2)
			{
				for (int i = 0; i < k; i++)
				{
					if (k >= 2)
						break;
					else
						cout << endl;
				}
				R();
			}
			if (k == 0)
				cout << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 2)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **  **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**    **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 3)
		{
			system("cls");
			cout << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **  **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**    **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 4)
		{
			system("cls");
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**  **" << endl;;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**    **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 5)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**  **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "**    **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 6)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**  **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "**    **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 7)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " **   **" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "******" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**    **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 8)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << " ******" << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "******" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**    **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << endl;
			Sleep(n);
		}

		if (k == 9)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**  **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
			cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**    **" << endl;
			Sleep(500);
		}
		k++;
		n -= 1;
	} while (k != 10);
	system("cls");
	poker();
	cout << endl;
	SetColor(7);
}

void move(int x)
{
	if (x == 1) cout << "Create Hand Test";
	else if (x == 2) cout << "Play with 1 player";
	else if (x == 3) cout << "Play with n player";
	else if (x == 4) cout << "Play with Dealer";
	else if (x == 5) cout << "Quit";
}

void choice(int& i)
{
	char k = 0;
	while (k != 13)
		if (_kbhit())
		{
			k = _getch();
			if (k == 80)
			{
				Beep(523, 100);
				SetColor(15);
				GoTo(46, i + 13);
				cout << "  ";
				move(i);
				i++;
				if (i > 5) i = 1;
				GoTo(46, i + 13);
				SetColor(5);
				cout << "->";
				SetColor(3);
				move(i);

			}
			else if (k == 72)
			{
				Beep(523, 100);
				SetColor(15);
				GoTo(46, i + 13);
				cout << "  ";
				move(i);
				i--;
				if (i < 1) i = 5;
				GoTo(46, i + 13);
				SetColor(5);
				cout << "->";
				SetColor(3);
				move(i);
			}
		}

}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void Poker()
{
	SetColor(4);
	cout << "\t\t\t\t" << " ******" << "   " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "******" << endl;
	cout << "\t\t\t\t" << "**    **" << "  " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
	SetColor(6);
	cout << "\t\t\t\t" << "**    **" << "  " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**   **" << endl;
	cout << "\t\t\t\t" << "*******" << "   " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
	SetColor(14);
	cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "****" << "     " << "*******" << "  " << "******" << endl;
	cout << "\t\t\t\t" << "**" << "        " << "**       **" << "  " << "** **" << "    " << "**" << "       " << "**  **" << endl;
	SetColor(11);
	cout << "\t\t\t\t" << "**" << "        " << " **     **" << "   " << "**  **" << "   " << "**" << "       " << "**   **" << endl;
	cout << "\t\t\t\t" << "**" << "        " << "   *****" << "     " << "**   **" << "  " << "*******" << "  " << "**    **" << endl;
}