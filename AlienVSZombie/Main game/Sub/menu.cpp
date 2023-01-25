// Afiq

#include "MainHeader.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

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
			//ClearScreen();
			system("color A");
			cout <<  " -------------------------- " << endl;
			cout <<  " |     Alien VS Zombie     |" << endl;
			cout <<  " -------------------------- " << endl;
			cout <<  " 1.	PLAY      	          " << endl;
			cout <<  " 2.	INSTRUCTIONS	      " << endl;
			cout <<  " 3.	QUIT			      " << endl;
			cout << endl;
			cout <<  ">>> CHOICE:		          " << endl;
			char op = getche();
			
			switch(op) {
				case '1':
					playmenu();
					break;
				case '2':
					instructions();
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
		getch();
	}


	void instructions() {
		//ClearScreen();
		cout << endl;
		cout <<  " --------------------------------------------- " << endl;
		cout <<  "|               Alien VS Zombie               |" << endl;
		cout <<  " --------------------------------------------- " << endl;
		cout << endl;
		cout <<  "                  CONTROLS                  " << endl;          
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
		cout <<  "Press any key to continue";
		getch();
	}

	void playmenu()  // edit the same as in gameMenu()
{ 
    GameBoard board;
    do {
        //ClearScreen();
        cout << " Default Game Settings " << endl;
        cout << "-----------------------" << endl;
        cout << " Board Rows     : " << board.getDimY() << endl; 
        cout << " Board Columns  : " << board.getDimX() << endl; 
        cout << " Zombie Count   : " << endl; // add zombie in the game
        cout << endl;
        cout << " Do you wish to change the game settings (y/n)? =>" << endl;
        cout << "<== Go back to menu (b)" << endl;
        char input = getche();

        switch(input) {
            case 'y':
                changesetting();
                break;
             case 'n':
                 srand(1);
                 Board();
                 break;
            case 'b':
                getMenu();
                break;
            default:
                cout << "Invalid! Try again" << endl;
                break;
        }
    } while (1);
}
