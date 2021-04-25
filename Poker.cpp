#include"typecard.h"

int Player[10][5];
int PlayerD[5][8];
Data a[52];
int po[10];
int Dealer[8];

int main()
{
	DisableResizeWindow();
	ShowScrollbar(0);
	ShowCur(0);
	srand((int)time(0));
	int** deck;
	deck = new int*[4];
	for (int i = 0; i < 4; i++)
		deck[i] = new int[13];
	int display=1, b, point = 0;
	char y;
	deck = new int*[4];
	for (int i = 0; i < 4; i++)
		deck[i] = new int[13];
	int i = 0;
	animation();
	Sleep(1000);
	do
	{
		do
		{
			system("cls");
			SetColor(11);
			poker();
			SetColor(15);
			cout << "=================================================";
			SetColor(13);
			cout << "Kha Vinh Dat";
			SetColor(15);
			cout << "========================================================== " << endl;
			cout << "================================================";
			SetColor(14);
			cout << "Nguyen Quoc Su";
			SetColor(15);
			cout <<"========================================================= " << endl;
			cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
			cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;

			ShowCur(0);
			cout << "\t\t\t\t\t  ==============================" << endl;
			cout << "\t\t\t\t\t  |     Create Hand Test       |" << endl;
			cout << "\t\t\t\t\t  |     Play with 1 player     |" << endl;
			cout << "\t\t\t\t\t  |     Play with n player     |" << endl;
			cout << "\t\t\t\t\t  |     Play with Dealer       |" << endl;
			cout << "\t\t\t\t\t  |     Quit                   |"<< endl;
			cout << "\t\t\t\t\t  ==============================" << endl;
			choice(display);
			Beep(523, 100);
			switch (display)
			{
			case 1:

				do
				{
					system("cls");
					SetColor(11);
					poker();
					SetColor(15);
					cout << "=========================================================================================================\n";
					cout << "=========================================================================================================\n";
				
					cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
					cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
					khoitao(a, deck);
					printCardsShuffling(a);
					createHandTest(a);
					cout << endl;
					cout << "\t\t\t  =================================" << endl;
					cout << "\t\t\t  | Do you want play again? (y/n) |" << endl;
					cout << "\t\t\t  =================================" << endl;
					ShowCur(1);
					cin >> y;
				} while (y == 'y');
				break;

			case 2:

				do
				{
					system("cls");
					SetColor(11);
					poker();
					SetColor(15);
					cout << "======================================================================================================================" << endl;
					cout << "======================================================================================================================" << endl;
					cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
					cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
					//Chơi 1 mình ( so lonely :(((((( )
					khoitao(a, deck);
					shuffleCards(deck);
					sort(a, deck);
					dealingForHand(a, Player[0]);
					cout << endl;

					cout << "\t\t\t  =================================" << endl;
					cout << "\t\t\t  | Do you want play again? (y/n) |" << endl;
					cout << "\t\t\t  =================================" << endl;
					ShowCur(1);
					cin >> y;
				} while (y == 'y');
				break;

			case 3:

				do
				{
					system("cls");
					SetColor(11);
					poker();
					SetColor(15);
					cout << "======================================================================================================================" << endl;
					cout << "======================================================================================================================" << endl;
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
					ShowCur(1);
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
						SetColor(11);
						poker();
						SetColor(15);
						cout << "======================================================================================================================" << endl;
						cout << "======================================================================================================================" << endl;
						cout << "(0)High Card      (1)Pair         (2)2 Pairs           (3)Three Of A Kind       (4)Straight" << endl;
						cout << "(5)Flush          (6)FullHouse    (7)Four Of A Kind    (8)StraightFlush" << endl << endl;
						cout << "Input the level of game: " << endl;
						cout << "(1). Easy" << endl;
						cout << "(2). Normal" << endl;
						cout << "(3). Hard" << endl;
						cin >> level;
					} while (level != 1 && level != 2 && level != 3);
					system("cls");

					khoitao(a, deck);

					shuffleCards(deck);
					sort(a, deck);

					int m;
					ShowCur(1);
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
				system("cls");
				SetColor(15);
				cout << "=========================================Thank you and see you again!!!================================================= ";
				break;
			}
			system("cls");
			SetColor(11);
			poker();
			SetColor(15);
			cout << "======================================================================================================================" << endl;
			cout << "======================================================================================================================" << endl;
			cout << " \t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << " \t\t\t\t\t Do you want go to menu ? (y/n)" << endl;
			cout << " \t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			GoTo(71, 11);
			ShowCur(1);
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
