#include"typecard.h"

int Player[10][5];
Data a[52];
int po[10];

int main()
{
	srand((int)time(0));
	int** deck;
	deck = new int* [4];
	for (int i = 0; i < 4; i++)
		deck[i] = new int[13];
	int display, b, point = 0;
	char y;
	deck = new int* [4];
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
			cout << "\t\t\t\t\t  (1) create Hand Test" << endl;
			cout << "\t\t\t\t\t  (2) Play with 1 player" << endl;
			cout << "\t\t\t\t\t  (3) Play with n player" << endl;
			cout << "\t\t\t\t\t  (4) quit" << endl;
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
					khoitao(a, deck);
					output(a);
					createHandTest(a);
					cout << endl;
					cout << " - Do you want play again? (y/n)" << endl;
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
					cout << "\t\t\t\t\t  (1) Play just only you" << endl;
					cout << "\t\t\t\t\t  (2) Play with dealer" << endl;
					int display_2;
					do
					{
						cout << " - Choose whatever play style you want (1 or 2)" << endl;
						cin >> display_2;
					} while (display_2 != 1 && display != 2);

					switch (display_2)
					{
					case 1:                           //Chơi 1 mình ( so lonely :(((((( )
						i = 1;
						do
						{
							cout << "So van dau ( > 0) : ";
							cin >> b;
							cout << endl;
						} while (b < 0);

						do
						{
							khoitao(a, deck);
							shuffleCards(deck);
							sort(a, deck);

							cout << "Van thu: " << i << endl;
							dealingforHand(a, Player[0]);

							cout << endl;

							point += Point(Player[0]);
							if (i == b)
								cout << "Diem tong cua ban la : " << point << endl;
							cout << endl;
							i++;
						} while (i != b + 1);
						break;
						//case 2:                        //Chơi 1 mình ( so lonely again :(((((( )
							//break;
					}
					cout << " - Do you want play again? (y/n)" << endl;
					cin >> y;
				} while (y == 'y');
				break;

			case 3:

				do
				{
					system("cls");
					cout << "=================================================== POKER ==============================================================" << endl;
					cout << "=================================================Kha Vinh Dat===========================================================" << endl;
					cout << "=============================================== Nguyen Quoc Su =========================================================" << endl;
					cout << "\t\t\t\t\t  (1) Play with no dealer" << endl;
					cout << "\t\t\t\t\t  (2) Play with dealer" << endl;
					int display_3;
					do
					{
						cout << " - Choose whatever play style you want (1 or 2)" << endl;
						cin >> display_3;
					} while (display_3 != 1 && display != 2);

					switch (display_3)
					{
					case 1:                                   //Chơi k có dealer
						i = 1;
						do
						{
							cout << "So van dau ( > 0) : ";
							cin >> b;
						} while (b < 0);

						do
						{
							khoitao(a, deck);

							shuffleCards(deck);
							sort(a, deck);

							cout << "Van thu: " << i << endl;
							dealingForHands(a, Player);
							cout << endl;
							i++;
						} while (i != b + 1);
						break;
					}
					cout << " - Do you want play again? (y/n)" << endl;
					cin >> y;
				} while (y == 'y');
				break;

			}

		} while (display < 1 || display > 4 );
		
		system("cls");

		if (display == 4)
		{
			cout << "=========================================Thank you and see you again!!!================================================= ";
			break;
		}

		cout << "=================================================== POKER ==============================================================" << endl;
		cout << "=================================================Kha Vinh Dat===========================================================" << endl;
		cout << "=============================================== Nguyen Quoc Su ==============================================================" << endl;
		cout << " - Do you want go to menu ? (y/n)" << endl;
		cin >> y;

		if (y != 'y')
			cout << "=========================================Thank you and see you again!!!================================================= ";
		else
			system("cls");

	} while (y == 'y');

	deletee(deck);

	return 0;
}
