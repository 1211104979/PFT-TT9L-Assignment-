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
#include <iostream>
#include <string>
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()

void play()
{
    //ClearScreen();
    movement move;
    GameBoard board;

    initalien();
    board.display(); 
    int no = board.getZomB(); // Afiq
    alienstat(); // Afiq
    zombiestat(no); // Afiq
    int x = board.getDimX()/2;
    int y = board.getDimY()/2;
    move.setalienX_(x);
    move.setalienY_(y);

    while(1)
    {

        std::string con;
        std::cout << " Command " ;
        std::cin >> con ;

        if (con == "up")
        {
            move.move_up();
        }

        if (con == "down")
        {
            move.move_down();
        }

        if (con == "left")
        {
            move.move_left();
        }

        if (con == "right")
        {
            move.move_right();
        }

        if (con == "help")
        {
            help();
        }

        if (con == "save")
        {
            //save();
        }

        if (con == "load")
        {
            //load();
        }

        if (con == "quit")
        {
            exit(0);
        }

        // else
        // {
        //     std::cout << "invalid input" << std::endl;
            
        // }
    }
}
