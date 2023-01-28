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
void movement::move_up() 
    {

        int y = getDimY() - 1;
        char trail[] = {'.'};
        for(int i = y - AlienY_; i > 0; --i)
        {
            setmap(i, AlienX_, trail[0]);
        }
        AlienY_ = 0;
        setalienY_(AlienY_);
        setmap(AlienY_, AlienX_, 'A');
        display(); 
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
    }

    void movement::move_down()
    {
        int y = getDimY() - 1;
        char trail[] = {'.'};
        for(int i = 0; i < AlienY_ + y; ++i)
        {
            setmap(i, AlienX_, trail[0]);
        }
        AlienY_ =  y;
        setalienY_(AlienY_);
        setmap(AlienY_, AlienX_, 'A');
        display(); 
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
    }

    void movement::move_left()
    {
        int x = getDimX() - 1;
        char trail[] = {'.'};
        for(int i = x - AlienX_; i > 0; --i)
        {
            setmap(AlienY_, i, trail[0]);
        }
        AlienX_ = 0;
        setalienX_(AlienX_);
        setmap(AlienY_, AlienX_, 'A');
        display(); 
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
    }

    void movement::move_right()
    {
        int x = getDimX() - 1;
        char trail[] = {'.'};
        for(int i = 0; i < x - AlienX_; ++i)
        {
            setmap(AlienY_, i, trail[0]);
        }
        AlienX_ = x;
        setalienX_(AlienX_);
        setmap(AlienY_, AlienX_, 'A');
        display(); 
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);

    }

    void movement::move_arrow()
    {

    }

    void movement::get_arrow()
    {

    }
