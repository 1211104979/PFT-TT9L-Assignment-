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

using namespace std;

//Alien move
// get vector of the alien

    int movement::setalienX_(int x)
    {
        return AlienX_ = x;
    }

    int movement::setalienY_(int y)
    {
        return AlienY_ = y;
    }

    int movement::getalienX_() const
    {
        return AlienX_;
    }

    int movement::getalienY_() const
    {
        return AlienY_;
    }
//====================================================
void movement::move_up2() // problem
    {
        GameBoard board2;

        int y = board2.getDimY() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        // board.setmap(AlienY_, AlienX_, trail[0]);
        for(int i = y - AlienY_; i > 0; --i)
        {
            board2.setmap(i, AlienX_, trail[0]);
        }
        AlienY_ = 0;
        setalienY_(AlienY_);
        board2.setmap(AlienY_, AlienX_, 'A');
        board2.display(); 
        int no = board2.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_down2()
    {
        GameBoard board2;

        int y = board2.getDimY() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        for(int i = 0; i < AlienY_ + y; ++i)
        {
            board2.setmap(i, AlienX_, trail[0]);
        }
        AlienY_ =  y;
        setalienY_(AlienY_);
        board2.setmap(AlienY_, AlienX_, 'A');
        board2.display(); 
        int no = board2.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_left2()
    {
        GameBoard board2;

        int x = board2.getDimX() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        for(int i = x - AlienX_; i > 0; --i)
        {
            board2.setmap(AlienY_, i, trail[0]);
        }
        AlienX_ = 0;
        setalienX_(AlienX_);
        board2.setmap(AlienY_, AlienX_, 'A');
        board2.display(); 
        int no = board2.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_right2()
    {
        GameBoard board2;

        int x = board2.getDimX() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        for(int i = 0; i < x - AlienX_; ++i)
        {
            board2.setmap(AlienY_, i, trail[0]);
        }
        AlienX_ = x;
        setalienX_(AlienX_);
        board2.setmap(AlienY_, AlienX_, 'A');
        board2.display(); 
        int no = board2.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_arrow2()
    {

    }

    void movement::get_arrow2()
    {

    }
//====================================================

    void movement::move_up() // problem
    {
        GameBoard board;

        int y = board.getDimY() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        // board.setmap(AlienY_, AlienX_, trail[0]);
        for(int i = y - AlienY_; i > 0; --i)
        {
            board.setmap(i, AlienX_, trail[0]);
        }
        AlienY_ = 0;
        setalienY_(AlienY_);
        board.setmap(AlienY_, AlienX_, 'A');
        board.display(); 
        int no = board.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_down()
    {
        GameBoard board;

        int y = board.getDimY() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        for(int i = 0; i < AlienY_ + y; ++i)
        {
            board.setmap(i, AlienX_, trail[0]);
        }
        AlienY_ =  y;
        setalienY_(AlienY_);
        board.setmap(AlienY_, AlienX_, 'A');
        board.display(); 
        int no = board.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_left()
    {
        GameBoard board;

        int x = board.getDimX() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        for(int i = x - AlienX_; i > 0; --i)
        {
            board.setmap(AlienY_, i, trail[0]);
        }
        AlienX_ = 0;
        setalienX_(AlienX_);
        board.setmap(AlienY_, AlienX_, 'A');
        board.display(); 
        int no = board.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_right()
    {
        GameBoard board;

        int x = board.getDimX() - 1;
        char trail[] = {'.'};
        char Alien[] = {'A'};
        for(int i = 0; i < x - AlienX_; ++i)
        {
            board.setmap(AlienY_, i, trail[0]);
        }
        AlienX_ = x;
        setalienX_(AlienX_);
        board.setmap(AlienY_, AlienX_, 'A');
        board.display(); 
        int no = board.getZomB(); // Afiq
        alienstat(); // Afiq
        zombiestat(no); // Afiq
    }

    void movement::move_arrow()
    {

    }

    void movement::get_arrow()
    {

    }
