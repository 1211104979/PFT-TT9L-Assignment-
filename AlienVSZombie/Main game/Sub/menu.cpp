// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN //
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //

#include "MainHeader.h"

using namespace std;

void getMenu()
{
	do
	{
		ClearScreen();
		resetLoad();
		emptymap(9, 3);
		init(9, 3, 1);
		
		cout << " -------------------------- " << endl;
		cout << " |     Alien VS Zombie     |" << endl;
		cout << " -------------------------- " << endl;
		cout << " 1.	     PLAY      	     " << endl;
		cout << " 2.	   CONTINUE      	 " << endl;
		cout << " 3.	   CONTROLS	         " << endl;
		cout << " 4.	     QUIT			 " << endl;
		cout << endl;
		cout << ">>> CHOICE:		         " << endl;
		char op;
		cin >> op;

		switch (op)
		{
		case '1':
			playmenu();
			break;
		case '2':
			loadmap();
			break;
		case '3':
			controls();
			break;
		case '4':
			exit(0);
			break;
		default:
			cout << "Invalid! Try again";
			break;
		}

	} while (1);
}

void controls()
{
	ClearScreen();
	cout << endl;
	cout << " --------------------------------------------- " << endl;
	cout << "|               Alien VS Zombie               |" << endl;
	cout << " --------------------------------------------- " << endl;
	cout << endl;
	cout << "                  CONTROLS                     " << endl;
	cout << "| up    ||Alien to move up.                   |" << endl;
	cout << "| down  ||Alien to move down.                 |" << endl;
	cout << "| left  ||Alien to move left.                 |" << endl;
	cout << "| right ||Alien to move right.                |" << endl;
	cout << "| arrow ||Switch the direction of             |" << endl;
	cout << "|       ||an arrow object in the game board.  |" << endl;
	cout << "| help  ||List and describe the commands      |" << endl;
	cout << "|       ||that the player can use in the game.|" << endl;
	cout << "| save  ||Save the current game to a file.    |" << endl;
	cout << "| load  ||Load a saved game from a file.      |" << endl;
	cout << "| menu  ||Return back to the menu.            |" << endl;
	cout << "| quit  ||Quit the game while still in play.  |" << endl;
	cout << endl;
	Pause();
}

void help()
{
	ClearScreen();
	cout << endl;
	cout << "     Commands     " << endl;
	cout << endl;
	cout << " up    - Move up. " << endl;
	cout << " down  - Move down. " << endl;
	cout << " left  - Move left. " << endl;
	cout << " right - Move right. " << endl;
	cout << " arrow - Switch the direction of an arrow. " << endl;
	cout << " help  - Display user commands. " << endl;
	cout << " save  - Save the game. " << endl;
	cout << " load  - Load a game. " << endl;
	cout << " menu  - Return back to the menu. " << endl;
	cout << " quit  - Quit the game. " << endl;
	cout << endl;
}

void playmenu() // edit the same as in gameMenu()
{
	ClearScreen();
	do
	{
		cout << "     Game Settings     " << endl;
		cout << "-----------------------" << endl;
		cout << " Board Rows     : " << getDimY() << endl;
		cout << " Board Columns  : " << getDimX() << endl;
		cout << " Zombie Count   : " << getZomB() << endl;
		cout << endl;
		cout << " Do you wish to change the game settings (y/n)? =>" << endl;
		cout << "<== Go back to menu (b)" << endl;
		char input;
		cin >> input;

		switch (input)
		{
		case 'n':
			Board();
			break;
		case 'y':
			changesetting();
			break;
		case 'b':
			getMenu();
			break;
		default:
			cout << "Invalid! Try again" << endl;
			Pause();
			break;
		}
	} while (1);
}

void gameover()
{
	cout << "\n\n\t\t\tGAME OVER." << endl;
	Pause();
	// cout << "Press again to go to the Main Menu" << endl;
	// Pause();
	// getMenu();
}

void winGame()
{
	cout << "Alien escaped the area successfully !" << endl;
	Pause();
}

void playagain()
{
	char respond;
	resetLoad();
	map_.clear();
	cout << "\tPlay Again? (Y/N) --> ";
	cin >> respond;

	if (respond == 'Y' || respond == 'y')
	{
		playmenu();
	}

	else if (respond == 'N' || respond == 'n')
	{
		getMenu();
	}
}
