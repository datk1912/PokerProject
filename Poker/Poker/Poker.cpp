#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

struct Data
{
	int P; // giu vi tri tren bang number va suit
	string s; // ten cua quan bai
};

const string number[]{ "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
const string suit[]{ "Hearts","Diamonds","Clubs","Spades" };

bool check(int** a, int x) // kiem tra so random co bi trung` khong
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
	srand((int)time(0));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			do
			{
				deck[i][j] = rand() % 52 + 1; // tron bai tu stt 1 -> 52
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
		cout << a[i].s << endl;
	}
}

void khoitao(Data a[52], string number[], string suit[])
{
	int k = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			a[i * 13 + j].P = k++;
			a[i * 13 + j].s = number[j] + ' ' + suit[i];
		}
	// khoi tao mang bo bai 1 chieu
}

void sort(Data a[], int** deck)
{
	int* c = new int[52];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			c[i * 13 + j] = deck[i][j]; // bien bo bai thanh mang 1 chieu

	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			if (a[j].P == c[i])
			{
				swap(a[i], a[j]); // doi struct thanh bo bai da xao tron
				break;
			}
	delete[] c;
}

void Oneplayer(Data a[])
{

}

int main()
{
	int** deck;
	deck = new int*[4];
	for (int i = 0; i < 4; i++)
		deck[i] = new int[13];

	shuffleCards(deck);
	Data a[52];

	khoitao(a, number, suit);

	sort(a, deck);
	//output(a);
	deletee(deck);
	return 0;
}