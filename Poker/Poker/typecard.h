#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<math.h>
#include<string>

using namespace std;

//extern const char* number[]{ "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
//extern const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

struct Data
{
	int P;
	string s;
};

extern int Player[10][5];
extern Data a[52];
extern int po[10];

bool check(int** a, int x);
void shuffleCards(int** deck);
void deletee(int** deck);
void output(Data a[]);
void khoitao(Data a[52], int** deck);
void sort(Data a[], int** deck);
bool Straight_Flush(int Player[5]);       //Thung pha sanh
bool Four_of_a_kind(int Player[5]);           //Tứ quý
bool Fullhouse(int Player[5]);           //Cù lũ
bool Flush(int Player[5]);               //Thùng
bool Straight(int Player[5]);            //Sảnh
bool Three_of_a_kind(int Player[5]);           //Sám cô
bool TwoPair(int Player[5]);          //Thú
bool Pair(int Player[5]);
int Point(int Player[5]);
void dealingforHand(Data a[], int Player[5]); 
void createHandTest(Data a[]);
void dealingForHands(Data a[], int Player[10][5]);
void sortP(int P[], int n, int **Player);