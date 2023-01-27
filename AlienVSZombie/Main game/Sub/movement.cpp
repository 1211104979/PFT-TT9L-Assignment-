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

//Alien move
// get vector of the alien

    int movement::setalienX_(int x)
    {
        return AlienX_;
    }

    int movement::setalienY_(int y)
    {
        return AlienY_;
    }

    void movement::move_up() // problem
    {
        GameBoard board;
        int defx = AlienX_;
        int x = board.getDimX();
        char trail[] = {'.'};
        board.setmap(AlienY_, AlienX_, trail[0]);
        std::cout << x - AlienX_ << std::endl;
        for(int i = 0; i< x - AlienX_; ++i)
        {
            board.setmap(AlienX_, i, '.');
        }
        AlienX_ = defx + (x - AlienX_);
        board.setmap(AlienY_, AlienX_, 'A');
        setalienX_(AlienX_);

    }

    void movement::move_down()
    {
 
    }

    void movement::move_left()
    {
 
    }

    void movement::move_right()
    {

    }

    void movement::move_arrow()
    {

    }

    void movement::get_arrow()
    {

    }
