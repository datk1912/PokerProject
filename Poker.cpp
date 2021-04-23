#include"typecard.h"

int Player[10][5];
int PlayerD[5][8];
Data a[52];
int po[10];
int Dealer[8];

int main()
{
	srand((int)time(0));
//	system("color 12");
	int** deck;
	deck = new int*[4];
	for (int i = 0; i < 4; i++)
		deck[i] = new int[13];
	int display, b, point = 0;
	char y;
	deck = new int*[4];
	for (int i = 0; i < 4; i++)
		deck[i] = new int[13];
	int i = 0;
	do
	{
		do
		{
			cout << "=================================================== POKER ==============================================================" << endl;
			cout << "=================================================Kha Vinh Dat===========================================================" << endl;
			cout << "=============================================== Nguyen Quoc Su =========================================================" << endl;
			cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
			cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
			cout << "\t\t\t\t\t  ==============================" << endl;
			cout << "\t\t\t\t\t  | (1) create Hand Test       |" << endl;
			cout << "\t\t\t\t\t  | (2) Play with 1 player     |" << endl;
			cout << "\t\t\t\t\t  | (3) Play with n player     |" << endl;
			cout << "\t\t\t\t\t  | (4) Play with Dealer       |" << endl;
			cout << "\t\t\t\t\t  | (5) Quit                   |"<< endl;
			cout << "\t\t\t\t\t  ==============================" << endl;
			cin >> display;
			switch (display)
			{
			case 1:

				do
				{
					system("cls");
					cout << "=================================================== POKER ==============================================================" << endl;
					cout << "=================================================Kha Vinh Dat===========================================================" << endl;
					cout << "=============================================== Nguyen Quoc Su =========================================================" << endl;
					cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
					cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
					
					khoitao(a, deck);
					output(a);
					createHandTest(a);
					cout << endl;
					cout << "\t\t\t  =================================" << endl;
					cout << "\t\t\t  | Do you want play again? (y/n) |" << endl;
					cout << "\t\t\t  =================================" << endl;
					cin >> y;
				} while (y == 'y');
				break;

			case 2:

				do
				{
					system("cls");
					cout << "=================================================== POKER ==============================================================" << endl;
					cout << "=================================================Kha Vinh Dat===========================================================" << endl;
					cout << "=============================================== Nguyen Quoc Su =========================================================" << endl;
					cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
					cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
					//Chơi 1 mình ( so lonely :(((((( )
					khoitao(a, deck);
					shuffleCards(deck);
					sort(a, deck);
					dealingforHand(a, Player[0]);
					cout << endl;

					cout << "\t\t\t  =================================" << endl;
					cout << "\t\t\t  | Do you want play again? (y/n) |" << endl;
					cout << "\t\t\t  =================================" << endl;
					cin >> y;
				} while (y == 'y');
				break;

			case 3:

				do
				{
					system("cls");
					cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
					cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
					i = 1;
					do
					{
						cout << "So van dau ( >0 ) : ";
						cin >> b;
					} while (b < 0);

					int *ans;
					ans = new int[10];
					int am;
					for (int j = 0; j < 10; j++)
						ans[j] = 0;

					do
					{
						cout << "input the number of player(2-10): ";
						cin >> am;
					} while (am < 2 || am > 10);

					do
					{
						khoitao(a, deck);

						shuffleCards(deck);
						sort(a, deck);

						cout << "Van thu: " << i << endl;
						dealingForHands(a, Player, am, ans);
						cout << endl;
						i++;
					} while (i != b + 1);

					cout << endl << endl;
					cout << "==========TONG DIEM ===========" << endl;
					for (int i = 0; i < am; i++)
						cout << "- Player " << i + 1 << ": " << ans[i] << endl;

					delete[] ans;

					cout << "\t\t\t  =================================" << endl;
					cout << "\t\t\t  | Do you want play again? (y/n) |" << endl;
					cout << "\t\t\t  =================================" << endl;
					cin >> y;
				} while (y == 'y');
				break;
			case 4:
				do
				{
					int level;
					do
					{
						system("cls");
						cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
						cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
						cout << "Input the level of game: " << endl;
						cout << "(1). Easy" << endl;
						cout << "(2). Normal" << endl;
						cout << "(3). Hard" << endl;
						cin >> level;
					} while (level != 1 && level != 2 && level != 3);
					system("cls");
					int display_4;

					khoitao(a, deck);

					shuffleCards(deck);
					sort(a, deck);

					int m;
					do
					{
						cout << "\t ===============================" << endl;
						cout << "\t  Enter the number players(1-5): " << endl; 
						cout << "\t ===============================" << endl;
						cin >> m;
					} while (m > 5 || m < 1);
					system("cls");
					dealer(a, Dealer, PlayerD, m+1,level);
					cout << "\t\t\t  =================================" << endl;
					cout << "\t\t\t  | Do you want play again? (y/n) |" << endl;
					cout << "\t\t\t  =================================" << endl;
					cin >> y;
				} while (y == 'y');
				break;

			}
		} while (display < 1 || display > 5);

			if (display == 5)
			{
				cout << "=========================================Thank you and see you again!!!================================================= ";
				break;
			}
			system("cls");
			cout << "=================================================== POKER ==============================================================" << endl;
			cout << "=================================================Kha Vinh Dat===========================================================" << endl;
			cout << "=============================================== Nguyen Quoc Su =========================================================" << endl;
			cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << " - Do you want go to menu ? (y/n)" << endl;
			cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cin >> y;

			if (y != 'y')
			{
				system("cls");
				cout << "=========================================Thank you and see you again!!!================================================= ";
			}
			else
				system("cls");
		
	} while (y == 'y');

	deletee(deck);
	
	return 0;
}
