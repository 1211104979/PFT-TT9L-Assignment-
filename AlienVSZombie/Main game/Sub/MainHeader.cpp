#include "MainHeader.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;
//namespace gf
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
			system("cls");
			system("color A");
			cout <<  " -------------------------- " << endl;
			cout <<  " |     Alien VS Zombie     |" << endl;
			cout <<  " -------------------------- " << endl;
			cout <<  " 	PLAY      	            " << endl;
			cout << " 	INSTRUCTIONS	        " << endl;
			cout << " 	QUIT			        " << endl;
			cout << endl;
			cout << ">>> CHOICE:		            " << endl;
			char op = getche();
			
			switch(op) {
				case '1':
					//modes();
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
		system("cls");
		cout << "\n\n\t\t\tGAME OVER.";
		getch();
	}


	void instructions() {
		system("cls");
		cout << endl;
		cout <<  " --------------------------------------------- " << endl;
		cout <<  "|               Alien VS Zombie               |" << endl;
		cout <<  " --------------------------------------------- " << endl;
		cout << endl;
		cout <<  "                  INSTRUCTION                  " << endl;          
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

// int main() 
// {
// 	getMenu();
// }