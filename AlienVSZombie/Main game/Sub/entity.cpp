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
#include <cstdlib>

void initalien(int y, int x)
{
    GameBoard board;

    char Alien[] = {'A'};
    board.setmap(y, x, Alien[0]);
}

void initzombie()
{
    GameBoard board;

    char zomBie[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int zomB_ = board.getZomB();
    int y = board.getDimY();
    int x = board.getDimX();
    for (int i = 0; i < zomB_; ++i)
    {
        int randY = rand() % y;
        int randX = rand() % x;
        board.setmap(randY, randX, zomBie[i]);
    }
}