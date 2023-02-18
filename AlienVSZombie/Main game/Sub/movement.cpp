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

// Shows Alien stats
void movement::alienstat()
{
    if (GetLoad() == 1)
    {
        alhp_ = GetAlienHP();
        alatk_ = GetAlienATK();
    }

    cout << "> Alien    ";
    cout << "| Health point :" << alhp_ << "| Attack :" << alatk_;
    saveHP(alhp_);
    saveATK(alatk_);
}

int movement::getalhp_()
    {
        return alhp_;
    }

int movement::setalhp_(int hp)
    {
        if (alhp_ < 100)
        {
            alhp_ = alhp_ + hp;
        }
        return alhp_;
    }
int movement::resetatk_()
    {
        return alatk_ = 0;
    }  

int movement::getalatk_()
    {
        return alatk_;
    }

int movement::setalatk_(int atk)
    {
        alatk_ = alatk_ + atk;
        return alatk_;
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

// Zombie stat

// int movement::getzomhp_()
//     {
//         return 0;
//     }

// int movement::setzomhp_(int hp)
//     {
//         zomhp_ = zomhp_ + hp;
//         return zomhp_;
//     }

// int movement::setzomX_(int x)
//     {
//         return zomX_ = x;
//     }

// int movement::setzomY_(int y)
//     {
//         return zomY_ = y;
//     }

// int movement::getzomX_() const
//     {
//         return zomX_;
//     }

// int movement::getzomY_() const
//     {
//         return zomY_;
//     }
//====================================================
// Gui
// Alien turn
void movement::Alienturn()
{
    int no = getZomB();
    alienstat(); 
    zomdisplay(no);
}

//====================================================
// Alien movement function
void movement::move_up() 
    {

        int y = getDimY() - 1; // 3 - 1 = 2,
        char trail[] = {'.'};
        int AlX = AlienX_;
        for(int i = AlienY_; i > 0; --i) // 2 - 1 = 1
        {
            int temp = i;
            setmap(temp, AlienX_, trail[0]);
            char obj = getObject(temp - 1, AlienX_);
            if (obj == 'h') // Health (+20 health to Alien)
            {
                cout << "Gained 20 Health." << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                AlienY_ = i - 1; // good
                setalienY_(AlienY_); // good
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_down();
                break;
            }
            else if (obj == '^') // move up by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                AlienY_ = i - 1;
                setalienY_(AlienY_);
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_left();
                break;
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                AlienY_ = i - 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_right();
                break;
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching nearby Zombie to attack." << endl;
                Pause();
                int podY = temp - 1;
                int podX = AlienX_;
                podatk(podY , podX);
                cout << "Zombie received 10 damage." << endl;
                Pause();
                AlienY_ = i - 1; // good
                setalienY_(AlienY_); // good
            }
            else if (obj == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockobjupdate(temp - 1, AlienX_);
                AlienY_ = i;
                setalienY_(AlienY_);
                i = 0;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                cout << "Attacking Zombie." << endl;
                // 
                Pause();
                AlienY_ = i;
                setalienY_(AlienY_);
                i = y;
            }
            else 
            {
                cout << "Alien finds an empty space." << endl;
                Pause();
                AlienY_ = i - 1;
                setalienY_(AlienY_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranobjupdate();
        display(); 
        resetatk_();
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_down()
    {
        int y = getDimY() - 1; // 3 -1 = 2 , Alien = 1
        char trail[] = {'.'};
        int AlX = AlienX_;
        for(int i = AlienY_; i < y; ++i)
        {
            int temp = i;
            setmap(temp, AlienX_, trail[0]);
            char obj = getObject(temp + 1, AlienX_);
            if (obj == 'h')
            {
                cout << "Gained 20 Health." << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            else if (obj == '^') // move up by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_up();
                break;
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_left();
                break;
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienY_ = i + 1;
                setalienY_(AlienY_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_right();
                break;
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching neraby Zombie to attack." << endl;
                Pause();
                int podY = temp + 1;
                int podX = AlienX_;
                podatk(podY , podX);
                cout << "Zombie received 10 damage." << endl;
                Pause();
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            else if (obj == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockobjupdate(temp + 1, AlienX_);
                AlienY_ = i;
                setalienY_(AlienY_);
                i = y;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                cout << "Attacking Zombie." << endl;
                // 
                Pause();
                AlienY_ = i;
                setalienY_(AlienY_);
                i = y;
            }
            else 
            {
                cout << "Alien finds an empty space." << endl;
                Pause();
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranobjupdate();
        display(); 
        resetatk_();
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_left()
    {
        int x = getDimX() - 1; // 9 - 1 = 8, 
        char trail[] = {'.'};
        int AlY = AlienY_;
        for(int i = AlienX_; i > 0; --i) // 8 - 4 = 4
        {
            int temp = i;
            setmap(AlienY_, temp, trail[0]);
            char obj = getObject(AlienY_ , temp - 1);
            if (obj == 'h') // Health (+20 health to Alien)
            {
                cout << "Gained 20 Health." << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_down();
                break;
            }
            else if (obj == '^') // move up by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_up();
                break;
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = AlienX_ - 1;
                setalienX_(AlienX_);
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                AlienX_ = i - 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_right();
                break;
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching nearby Zombie to Attack" << endl;
                Pause();
                int podY = AlienY_;
                int podX = temp - 1;
                podatk(podY , podX);
                cout << "Zombie received 10 damage." << endl;
                Pause();
                AlienX_ = i - 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockobjupdate(AlienY_ , temp - 1);
                AlienX_ = i;
                setalienX_(AlienX_);
                i = 0;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                cout << "Attacking Zombie." << endl;
                // 
                Pause();
                AlienX_ = i;
                setalienX_(AlienX_);
                i = 0;
            }
            else 
            {
                cout << "Alien finds an empty space." << endl;
                Pause();                
                AlienX_ = i - 1;
                setalienX_(AlienX_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranobjupdate();
        display(); 
        resetatk_();
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_right()
    {
        int x = getDimX() - 1;
        char trail[] = {'.'};
        int AlY = AlienY_;
        for(int i = AlienX_; i < x; ++i)
        {
            int temp = i;
            setmap(AlienY_, temp, trail[0]);
            char obj = getObject(AlienY_ , temp + 1);
            if (obj == 'h') // Health (+20 health to Alien)
            {
                cout << " Gained 20 Health. " << endl;
                Pause();
                getalhp_();
                setalhp_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'v') // move down by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_down();
                break;
            }
            else if (obj == '^') // move up by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_up();
                break;
            }
            else if (obj == '<') // move to the left by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
                setmap(AlienY_, AlienX_, 'A');
                display();
                Alienturn();
                Pause();
                move_left();
                break;
            }
            else if (obj == '>') // move to the right by 1 and stop
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack is increased by 20." << endl;
                Pause();
                setalatk_(20);
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'p') // attack nearby Zombie
            {
                cout << "Pod detected, searching nearby Zombie to attack." << endl;
                Pause();
                int podY = AlienY_;
                int podX = temp + 1;
                podatk(podY , podX);
                cout << "Zombie received 10 damage." << endl;
                Pause();
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            else if (obj == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Breaking the rock." << endl;
                Pause();
                rockobjupdate(AlienY_ , temp + 1);
                AlienX_ = i;
                setalienX_(AlienX_);
                i = x;
            }
            else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
            {
                AlienX_ = i;
                setalienX_(AlienX_);
                cout << "Attacking Zombie." << endl;
                // 
                Pause();
                i = x;
            }
            else 
            {
                cout << "Alien finds an empty space." << endl;
                Pause();
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            setmap(AlienY_, AlienX_, 'A');
            display();
            Alienturn();
            Pause();
        }
        ranobjupdate();
        display(); 
        resetatk_();
        int no = getZomB(); // Afiq
        alienstat(); // Afiq
        zomdisplay(no);
        saveHP(alhp_);
        saveATK(alatk_);
    }

    void movement::move_arrow(int x, int y, string z)
    {

        int ary = getDimY() - y;
        int arx = x - 1;
        string dir = z;
        Pause();
        if ( dir.compare("up") == 0)
        {
            setmap(ary, arx, '^');
            display(); 
            int no = getZomB(); // Afiq
            alienstat(); // Afiq
            zomdisplay(no);
        }
        else if ( dir.compare("down") == 0)
        {
            setmap(ary, arx, 'v');
            display(); 
            int no = getZomB(); // Afiq
            alienstat(); // Afiq
            zomdisplay(no);
        }
        else if ( dir.compare("left") == 0)
        {
            setmap(ary, arx, '<');
            display(); 
            int no = getZomB(); // Afiq
            alienstat(); // Afiq
            zomdisplay(no);
        }
        else if ( dir.compare("right") == 0)
        {
            setmap(ary, arx, '>');
            display(); 
            int no = getZomB(); // Afiq
            alienstat(); // Afiq
            zomdisplay(no);
        }

    }

// Zombie movement
void movement::zommove()
{
    int no = getZomB();
    for (int i = 0; i < no; ++i)
    {
        fesetround(FE_UPWARD);
        char Zombody[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int Zy = getZomY(i);
        int Zx = getZomX(i);
        int Ay = getalienY_();
        int Ax = getalienX_();

        int DisY = Zy - Ay;
        int DisX = Zx - Ax;
        float DisTemp = pow(DisY,2) + pow(DisX,2);
        float Distance = llrint(sqrt(DisTemp));
        int Zhp  = getZHP(i);
        int Zatk = getZATK(i);     
        int Zrng = getZRNG(i);

        int ZtoAY = abs(DisY);
        int ZtoAX = abs(DisX);
        if (Distance <= Zrng)
        {
            getalhp_();
            setalhp_(-1*Zatk);
            cout << "Alien in range" << endl;
            Pause();
            cout << "Alien take " << Zatk << " damage from zombie "<< i << endl;
            Pause();
            cout << "Zombie recover " << Zatk << " Health from attacking Alien "<< i << endl;
            Pause();
        }
        else if (ZtoAX > ZtoAY)   
        {        
            if(DisX<0)    
            {
                // zomright
                char obj = getObject(Zy, Zx + 1);
                if (obj == 'h') // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    Zx = Zx + 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                }

                else 
                {
                    Zx = Zx + 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                }
            }
            else 
            {
                // zomleft
                char obj = getObject(Zy, Zx - 1);
                if (obj == 'h') // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    Zx = Zx - 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                }

                else 
                {
                    Zx = Zx - 1; 
                    setZomX(i,Zx);
                    setmap(Zy, Zx, Zombody[i]);
                }
            }
        }
        else 
        {
            if (DisY<0)
            {
                // zomdown
                char obj = getObject(Zy + 1, Zx);
                if (obj == 'h') // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    Zy = Zy + 1; 
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                }

                else 
                {
                    Zy = Zy + 1;
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                }
            }
            else 
            {
                // zomup
                char obj = getObject(Zy - 1, Zx);
                if (obj == 'h') // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    Zy = Zy - 1; 
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                }

                else 
                {
                    Zy = Zy - 1;
                    setZomY(i,Zy);
                    setmap(Zy, Zx, Zombody[i]);
                }
            }
        }
    }
}

void movement::podatk(int podY, int podX)
{
    int no = getZomB();
    int Dispod[] = {};
    for (int i = 0; i < no; ++i)
    {
        fesetround(FE_UPWARD);
        int Zy = getZomY(i);
        int Zx = getZomX(i);
        int DisY = Zy - podY;
        int DisX = Zx - podX;
        float DisTemp = pow(DisY,2) + pow(DisX,2);
        float Distance = llrint(sqrt(DisTemp));
        Dispod[i] = Distance;
    }
    int near = Dispod[0];
    int zomnum = 0;
    for (int i = 0; i < no; ++i)
    {
        if(Dispod[i] < near)
        {
            near = Dispod[i];
            zomnum = i;
        }
    }
    int Zhp  = getZHP(zomnum); // problem
    Zhp = Zhp - 10;
    setZomHP(zomnum, Zhp);
}