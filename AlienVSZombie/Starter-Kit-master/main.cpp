// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year  : Trimester 1, 2022/23 (T2215) 
// Lab   : TT9L 
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN  
// IDs   : 1211104335                    | 1211104979 
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my 
// Phones: 011-1026 0985                 | 011-3174 2235 
// ********************************************************* 

// Youtube video : https://youtu.be/_INcX8hO_GQ

// TODO: Fill in the missing information above and delete this line.

//Game Commands 
    //Movement (up, down, left, right)
    //Change direction of arrow (arrow)
    //Display user commands (help)
    //Save game (save)
    //Load game (load)
    //Quit game (quit)

//Board setting (must be odd numbers)
    //Board size and config
    //Random generated Objects ("h"=health pack, "r"=rock/block, "<"/"^"/">"/"v"= direction pad, " "= empty space)

//Graphic on board
    //Zombie setting (number of zombie, denoted as int/number)
    //Alien (denoted as A)

//Stats
    //Alien stat (Life, Attack)
    //Zombie stat (Life, Attack, Range)

//Spawn
    //Alien (position will initially be at the middle)
    //Zombie (random)

//Turns
    //Display (who turn it is)

//AI movement program
    //Move towards Alien
    //Attack when in range


#include "pf/helper.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    pf::Pause();
}