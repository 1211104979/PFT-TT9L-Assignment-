// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN //
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //

//Afiq--------------------------------------------------------------------

#include "MainHeader.h"
#include <iostream>
#include <cstdlib>

using namespace std;

    int ClearScreen()
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system("clear");
        #endif
    }

    int Pause()
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }

	void getMenu() 
	{
		do {
			ClearScreen();
			cout <<  " -------------------------- " << endl;
			cout <<  " |     Alien VS Zombie     |" << endl;
			cout <<  " -------------------------- " << endl;
			cout <<  " 1.	PLAY      	          " << endl;
			cout <<  " 2.	INSTRUCTIONS	      " << endl;
			cout <<  " 3.	QUIT			      " << endl;
			cout << std::endl;
			cout <<  ">>> CHOICE:		          " << endl;
			char op;
			cin >> op;
			
			switch(op) {
				case '1':
					playmenu();
					break;
				case '2':
					controls();
					break;
				case '3':
					exit(0);
					break;
				default:
					cout << "Invalid! Try again";
					break;
			}
			
		} while (1);

	}

	void gameover() {
		ClearScreen();
		cout << "\n\n\t\t\tGAME OVER.";
		Pause();
	}

	void controls() {
		ClearScreen();
		cout << endl;
		cout <<  " --------------------------------------------- " << endl;
		cout <<  "|               Alien VS Zombie               |" << endl;
		cout <<  " --------------------------------------------- " << endl;
		cout << endl;
		cout <<  "                  CONTROLS                     " << endl;          
		cout <<  "| up    //Alien to move up.                   |" << endl;
		cout <<  "| down  //Alien to move down.                 |" << endl; 
		cout <<  "| left  //Alien to move left.                 |" << endl; 
		cout <<  "| right //Alien to move right.                |" << endl; 
		cout <<  "| arrow //Switch the direction of             |" << endl; 
		cout <<  "|       //an arrow object in the game board.  |" << endl;
		cout <<  "| help  //List and describe the commands      |" << endl; 
		cout <<  "|       //that the player can use in the game.|" << endl;
		cout <<  "| save  //Save the current game to a file.    |" << endl; 
		cout <<  "| load  //Load a saved game from a file.      |" << endl; 
		cout <<  "| quit  //Quit the game while still in play.  |" << endl; 
		cout << endl;
		Pause();
	}

	void help()
	{
		cout << endl;
		cout <<  " Commands " << endl;
		cout << endl;         
		cout <<  " up    - Move up. " << endl;
		cout <<  " down  - Move down. " << endl; 
		cout <<  " left  - Move left. " << endl; 
		cout <<  " right - Move right. " << endl; 
		cout <<  " arrow - Switch the direction of an arrow. " << endl;
		cout <<  " help  - Display user commands. " << endl; 
		cout <<  " save  - Save the game. " << endl; 
		cout <<  " load  - Load a  game. " << endl; 
		cout <<  " quit  - Quit the game. " << endl; 
		cout << endl;
		Pause();
	}

//Afiq--------------------------------------------------------------------

//LiEn--------------------------------------------------------------------
	void playmenu()  // edit the same as in gameMenu()
	{ 
		do 
		{
			ClearScreen();
			cout << "     Game Settings     " << endl;
			cout << "-----------------------" << endl;
			cout << " Board Rows     : " << getDimY() << endl; 
			cout << " Board Columns  : " << getDimX() << endl; 
			cout << " Zombie Count   : " << getZomB() << endl; 
			cout << endl;
			cout << " Do you wish to change the game settings (y/n)? =>" << endl;
			cout << "<== Go back to menu (b)" << endl;
			char input;
			cin>> input;

			switch(input) 
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
//LiEn--------------------------------------------------------------------
