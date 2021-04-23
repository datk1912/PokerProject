#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<string.h>
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
extern int PlayerD[5][8];
extern Data a[52];
extern int po[10];
extern int Dealer[8];


bool check(int** a, int x);
void shuffleCards(int** deck);  // xao bai
void deletee(int** deck);
void output(Data a[]);  // in ra bo bai
void khoitao(Data a[52], int** deck);  // khoi tao mang 1 chieu bo bai
void sort(Data a[], int** deck);	

void dealingforHand(Data a[], int Player[5]);  // chia bai cho 1 nguoi choi
void printHand(Data a[]);  // in bai
void createHandTest(Data a[]);  // chon 5 la bai trong bo bai chua sap xep va kiem tra
bool isStraightFlush(int Player[5]);  // Thung pha sanh
bool isFourOfAKind(int Player[5]);	// Tu quy
bool isFullHouse(int Player[5]);  // Cu lu
bool isFlush(int Player[5]);  // Thung
bool isStraight(int Player[5]);	// Sanh
bool isThreeOfAKind(int Player[5]);	// Sam co
bool isTwoPairs(int Player[5]);	 // Thu
bool isPair(int Player[5]);  // Doi
int getHighestCard(int Player[5]); // la bai lon nhat

void dealingForHands(Data a[], int Player[10][5], int am, int *&ans);  // chia bai cho nhieu nguoi
int  getStatusOfHand(int Player[5]);  // check bai
void rankingHands(int po[], int n, Data a[]);  // in ra thu hang cua nguoi choi
int* evaluateHands(int po[], int n, int *&a); // tong diem sau m van dau

void dealer(Data a[], int Dealer[8], int Player[5][8], int n,int level); 