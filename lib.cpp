#include"typecard.h"

using namespace std;

const char* number[]{ "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

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

void output(Data a[])
{
	for (int i = 0; i < 52; i++)
	{
		cout << a[i].s << " (" << a[i].P << ")" << "\0" << endl;
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
			a[i * 13 + j].s += " " + s;
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

bool Straight_Flush(int Player[5])       //Thung pha sanh
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

bool Four_of_a_kind(int Player[5])            //Tứ quý
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

bool Fullhouse(int Player[5])           //Cù lũ
{
	int c1 = 0, c2 = 0, *c;
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

bool Flush(int Player[5])               //Thùng
{
	int s = Player[0] / 13;
	for (int i = 1; i < 5; i++)
		if (Player[i] / 13 != s) return 0;

	if (!Straight(Player)) return 1;
	return 0;
}

bool Straight(int Player[5])            //Sảnh
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

bool Three_of_a_kind(int Player[5])           //Sám cô
{
	if (Fullhouse(Player)) return 0;

	for (int i = 0; i < 4; i++)
	{
		int c = 0;
		for (int j = i + 1; j < 5; j++)
			if (Player[i] % 13 == Player[j] % 13) c++;
		if (c == 2) return 1;
	}
	return 0;
}

bool TwoPair(int Player[5])          //Thú
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

bool Pair(int Player[5])
{
	int count = 0;
	for (int i = 0; i < 4; i++)
		if (Player[i] % 13 == Player[i + 1] % 13)
			count++;
	if (count == 1)
		return 1;
	return 0;
}

// ======================================================

int Point(int Player[5]) // tinh diem
{
	if (Straight_Flush(Player))
		return 8;
	if (Four_of_a_kind(Player))
		return 7;
	if (Fullhouse(Player))
		return 6;
	if (Flush(Player))
		return 5;
	if (Straight(Player))
		return 4;
	if (Three_of_a_kind(Player))
		return 3;
	if (TwoPair(Player))
		return 2;
	if (Pair(Player))
		return 1;
	return 0;
}

void dealingforHand(Data a[], int Player[5]) // chia bai cho 1 nguoi
{
	for (int i = 0; i < 5; i++)
		Player[i] = a[i].P;
	cout << "Bai cua ban:" << endl;
	for (int i = 0; i < 5; i++)
		cout << a[i].s << " ";
	cout << endl;
	int p = Point(Player);
	cout << "Diem cua ban la : " << p << endl;
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
			cout << "card " << i << ": ";
			cin >> t[i];
			if (fl[t[i]] == 0)
			{
				fl[t[i]] = 1;
				break;
			}
			else if (fl[t[i]] == 1 || t[i] > 51 || t[i] < 1) cout << "card " << i << " error!" << endl;

		}


	cout << "Bai cua ban:" << endl;
	for (int i = 0; i < 5; i++)
		cout << a[t[i]].s << " ";
	cout << endl;
	int point = Point(t);
	cout << "Diem cua ban la : " << point << endl;
}

void sortP(int P[], int n)
{
	int c[10];
	for (int i = 0; i < n; i++)
		c[i] = i + 1;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (P[i] < P[j])
			{
				swap(P[i], P[j]);
				swap(c[i], c[j]);
			}
		}
	if (po[n] == po[0]) cout << "Everyone are Tie!";
	else
	{
		cout << "-- The Winner --" << endl;
		for (int i = 0; i < n; i++)
			if (po[i] == po[0]) cout << "player " << c[i] << endl;

	}
}

void  getStatusOfHand(Data a[], int n, int po[])
{
	cout << "player " << n + 1 << " point: " << po[n] << endl;
	for (int i = 0; i < 5; i++)
		cout << a[n + i * n].s << "  ";
}

void dealingForHands(Data a[], int Player[10][5])
{
	int n;
	do
	{
		cout << "input the number of player(2-10): ";
		cin >> n;
	} while (n < 2 || n > 10);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			Player[i][j] = a[i + j * n].P;

		po[i] = Point(Player[i]);

		getStatusOfHand(a, i, po);
		
		cout << endl << endl;
	}
	sortP(po, n);
}
