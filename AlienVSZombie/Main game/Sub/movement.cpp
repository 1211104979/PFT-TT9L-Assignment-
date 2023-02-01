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

using namespace std;

//Alien move
// obj detection and effect

void movement::alienstat() // Shows Alien stats
    {
        cout << "  Alien    ";
        cout << "| Health point :" << alhp_ << "| Attack :" << alatk_;
    }

int movement::getalhp_()
    {
        return alhp_;
    }

int movement::setalhp_(int hp)
    {
        alhp_ = alhp_ + hp;
        return alhp_;
    }

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

        int y = getDimY() - 1; // 3 - 1 = 2,
        cout << "y = " ;
        cout << y << endl;
        char trail[] = {'.'};
        cout << "AlienY_ = " ;
        cout << AlienY_ << endl;
        for(int i = AlienY_; i > 0; --i) // 2 - 1 = 1
        {
            int temp = i;
            // cout << "temp = " ;
            // cout << temp << endl;
            char obj = getObject(temp - 1, AlienX_);
            // cout << "obj" ;
            // cout << obj << endl;
            // cout << "i = " ;
            // cout << i << endl;
            if (obj == 'h') // Health (+20 health to Alien)
            {
                cout << " Gained 20 Health " << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                break;
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                AlienY_ = i ;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else if (obj == '^') // move up by 1 and stop
            {
                if (i-2>=0)
                {
                    AlienY_ = i - 2;
                    setalienY_(AlienY_);
                    i = y;
                    break;
                }
                else
                {
                    AlienY_ = i - 1;
                    setalienY_(AlienY_);
                    i = y;
                    break;
                }
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                AlienX_ = AlienX_ - 1;
                setalienX_(AlienX_);
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                AlienX_ = AlienX_ + 1;
                setalienX_(AlienX_);
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching for alien to attack" << endl;
                Pause();
                break;

            }
            else if (obj == 'r')
            {
                AlienY_ = i;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else 
            {
                setmap(temp, AlienX_, trail[0]);
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                // break;
            }
        }
        // AlienY_ = 0;
        // setalienY_(AlienY_);
        Pause();
        setmap(AlienY_, AlienX_, 'A');
        display(); 
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
    }

    void movement::move_down()
    {
        int y = getDimY() - 1; // 3 -1 = 2 , Alien = 1
        char trail[] = {'.'};
        cout << "y = " ;
        cout << y << endl;
        for(int i = AlienY_; i < y; ++i)
        {
            int temp = i;
            char obj = getObject(temp + 1, AlienX_);
            // cout << "obj" ;
            // cout << obj << endl;
            // cout << "i = " ;
            // cout << i << endl;
            if (obj == 'h') // Health (+20 health to Alien)
            {
                cout << " Gained 20 Health " << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                break;
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                if (i+2 <= y)
                {
                    AlienY_ = i + 2;
                    setalienY_(AlienY_);
                    i = y;
                    break;
                }
                else
                {
                    AlienY_ = i + 1;
                    setalienY_(AlienY_);
                    i = y;
                    break;
                }
            }
            else if (obj == '^') // move up by 1 and stop
            {
                AlienY_ = i ;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                AlienX_ = AlienX_ - 1;
                setalienX_(AlienX_);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                AlienX_ = AlienX_ + 1;
                setalienX_(AlienX_);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching for alien to attack" << endl;
                Pause();
                break;

            }
            else if (obj == 'r')
            {
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                i = y;
                break;
            }
            else 
            {
                setmap(temp, AlienX_, trail[0]);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                // break;
            }
        }
        // AlienY_ =  y;
        // setalienY_(AlienY_);
        Pause();
        setmap(AlienY_, AlienX_, 'A');
        display(); 
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
    }

    void movement::move_left()
    {
        int x = getDimX() - 1; // 9 - 1 = 8, 
        char trail[] = {'.'};
        cout << "AlienY_ =" << AlienY_ << endl;
        for(int i = AlienX_; i > 0; --i) // 8 - 4 = 4
        {
            int temp = i;
            // cout << "temp = " ;
            // cout << temp << endl;
            // cout << "AlienY_ =" << AlienY_ << endl;
            char obj = getObject(AlienY_ , temp - 1);
            // cout << "obj" ;
            // cout << obj << endl;
            // cout << "i = " ;
            // cout << i << endl;
            // cout << "AlienY_ = " ;
            // cout << AlienY_ << endl;
            if (obj == 'h') // Health (+20 health to Alien)
            {
                cout << " Gained 20 Health " << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                break;
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                AlienY_ = AlienY_ + 1;
                setalienY_(AlienY_);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else if (obj == '^') // move up by 1 and stop
            {
                AlienY_ = AlienY_ - 1;
                setalienY_(AlienY_);
                AlienX_ = i - 1 ;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                if (i-2>=0)
                {
                    AlienX_ = AlienX_ - 2;
                    setalienX_(AlienX_);
                    i = 0;
                    break;
                }
                else 
                {
                    AlienX_ = AlienX_ - 1;
                    setalienX_(AlienX_);
                    i = 0;
                    break;
                }
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                AlienX_ = AlienX_;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching for alien to attack" << endl;
                Pause();
                break;

            }
            else if (obj == 'r')
            {
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else 
            {
                setmap(AlienY_, temp, trail[0]);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                // break;
            }
        }
        Pause();
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
        cout << "AlienY_ =" << AlienY_ << endl;
        for(int i = AlienX_; i < x; ++i)
        {
            int temp = i;
            // cout << "temp = " ;
            // cout << temp << endl;
            // cout << "AlienY_ =" << AlienY_ << endl;
            char obj = getObject(AlienY_ , temp + 1);
            // cout << "obj" ;
            // cout << obj << endl;
            // cout << "i = " ;
            // cout << i << endl;
            // cout << "AlienY_ = " ;
            // cout << AlienY_ << endl;
            if (obj == 'h') // Health (+20 health to Alien)
            {
                cout << " Gained 20 Health " << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                break;
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                AlienY_ = AlienY_ + 1;
                setalienY_(AlienY_);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else if (obj == '^') // move up by 1 and stop
            {
                AlienY_ = AlienY_ - 1;
                setalienY_(AlienY_);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                AlienX_ = AlienX_;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                if (i+2 <= x)
                {
                    AlienX_ = AlienX_ + 2;
                    setalienX_(AlienX_);
                    i = 0;
                    break;
                }
                else
                {
                    AlienX_ = AlienX_ + 1;
                    setalienX_(AlienX_);
                    i = 0;
                    break;
                }

            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching for alien to attack" << endl;
                Pause();
                break;

            }
            else if (obj == 'r')
            {
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                i = 0;
                break;
            }
            else 
            {
                cout << "AlienY_ =" << AlienY_ << endl;
                setmap(AlienY_, temp, trail[0]);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                // break;
            }
        }
        Pause();
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
        // return map_[dimY_-y][x-1];
    }
