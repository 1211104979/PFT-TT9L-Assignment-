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
#include <conio.h> // getch()

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
			std::cout <<  " -------------------------- " << std::endl;
			std::cout <<  " |     Alien VS Zombie     |" << std::endl;
			std::cout <<  " -------------------------- " << std::endl;
			std::cout <<  " 1.	PLAY      	           " << std::endl;
			std::cout <<  " 2.	INSTRUCTIONS	       " << std::endl;
			std::cout <<  " 3.	QUIT			       " << std::endl;
			std::cout << std::endl;
			std::cout <<  ">>> CHOICE:		           " << std::endl;
			char op;
			std::cin >> op;
			
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
					std::cout << "Invalid! Try again";
					break;
			}
			
		} while (1);

	}

	void gameover() {
		ClearScreen();
		std::cout << "\n\n\t\t\tGAME OVER.";
		Pause();
	}

	void controls() {
		ClearScreen();
		std::cout << std::endl;
		std::cout <<  " --------------------------------------------- " << std::endl;
		std::cout <<  "|               Alien VS Zombie               |" << std::endl;
		std::cout <<  " --------------------------------------------- " << std::endl;
		std::cout << std::endl;
		std::cout <<  "                  CONTROLS                     " << std::endl;          
		std::cout <<  "| up    //Alien to move up.                   |" << std::endl;
		std::cout <<  "| down  //Alien to move down.                 |" << std::endl; 
		std::cout <<  "| left  //Alien to move left.                 |" << std::endl; 
		std::cout <<  "| right //Alien to move right.                |" << std::endl; 
		std::cout <<  "| arrow //Switch the direction of             |" << std::endl; 
		std::cout <<  "|       //an arrow object in the game board.  |" << std::endl;
		std::cout <<  "| help  //List and describe the commands      |" << std::endl; 
		std::cout <<  "|       //that the player can use in the game.|" << std::endl;
		std::cout <<  "| save  //Save the current game to a file.    |" << std::endl; 
		std::cout <<  "| load  //Load a saved game from a file.      |" << std::endl; 
		std::cout <<  "| quit  //Quit the game while still in play.  |" << std::endl; 
		std::cout << std::endl;
		Pause();
	}

	void help()
	{
		std::cout << std::endl;
		std::cout <<  " Commands " << std::endl;
		std::cout << std::endl;         
		std::cout <<  " up    - Move up. " << std::endl;
		std::cout <<  " down  - Move down. " << std::endl; 
		std::cout <<  " left  - Move left. " << std::endl; 
		std::cout <<  " right - Move right. " << std::endl; 
		std::cout <<  " arrow - Switch the direction of an arrow. " << std::endl;
		std::cout <<  " help  - Display user commands. " << std::endl; 
		std::cout <<  " save  - Save the game. " << std::endl; 
		std::cout <<  " load  - Load a  game. " << std::endl; 
		std::cout <<  " quit  - Quit the game. " << std::endl; 
		std::cout << std::endl;
		Pause();
	}

//Afiq--------------------------------------------------------------------

//LiEn--------------------------------------------------------------------
	void playmenu()  // edit the same as in gameMenu()
	{ 
		GameBoard board;
		do 
		{
			ClearScreen();
			std::cout << " Default Game Settings " << std::endl;
			std::cout << "-----------------------" << std::endl;
			std::cout << " Board Rows     : " << board.getDimY() << std::endl; 
			std::cout << " Board Columns  : " << board.getDimX() << std::endl; 
			std::cout << " Zombie Count   : " << board.getZomB() << std::endl; 
			std::cout << std::endl;
			std::cout << " Do you wish to change the game settings (y/n)? =>" << std::endl;
			std::cout << "<== Go back to menu (b)" << std::endl;
			char input;
			std::cin>> input;

			switch(input) 
			{
				case 'y':
					play();
					break;
				case 'n':
					defplay();
					break;
				case 'b':
					getMenu();
					break;
				default:
					std::cout << "Invalid! Try again" << std::endl;
					break;
			}
		} while (1);
	}
//LiEn--------------------------------------------------------------------
