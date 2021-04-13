#include"typecard.h"

int Player[10][5];
Data a[52];
int po[10];

int main()
{
	int** deck;
	int d;
	int b, i = 1;
	deck = new int*[4];
	for (int i = 0; i < 4; i++)
		deck[i] = new int[13];
	do{
		cout << "(1) createHandTest" << endl;
		cout << "(2) Play with 1 player" << endl;
		cout << "(3) Play with n player" << endl;
		cout << "quit" << endl;
		cin >> d;
		switch (d)
			{
				case 1:
					khoitao(a, deck);
					output(a);
					createHandTest(a);
					break;

				case 2:
					do {
						cout << "So van dau ( > 0) : ";
						cin >> b;
					} while (b < 0);
					do {
						int** deck;
						deck = new int*[4];
						for (int i = 0; i < 4; i++)
							deck[i] = new int[13];

						khoitao(a, deck);
						shuffleCards(deck);
						sort(a, deck);

						cout << "Van thu: " << i << endl;
						dealingforHand(a, Player[0]);
						deletee(deck);
						cout << endl;
						i++;
					} while (i != b + 1);
					break;

				case 3:
					do {
						cout << "So van dau ( > 0) : ";
						cin >> b;
					} while (b < 0);
					do {
						khoitao(a, deck);
						srand((int)time(0));

						shuffleCards(deck);
						sort(a, deck);

						cout << "Van thu: " << i << endl;
						dealingForHands(a, Player);
						cout << endl;
						i++;
					} while (i != b + 1);
					break;
			}
		}while (d < 1 || d > 3);
		deletee(deck);
}