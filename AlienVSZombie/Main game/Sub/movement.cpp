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

int validity = 0;
// Shows Alien stats
void movement::alienturndisplay()
{
    if (GetLoad() == 1 && validity == 0)
    {
        alhp_ = GetAlienHP();
        alatk_ = GetAlienATK();
        validity++;
    }

    cout << "> Alien    ";
    cout << "| Health point :" << alhp_ << "| Attack :" << alatk_;
    saveHP(alhp_);
    saveATK(alatk_);
}

void movement::aliendisplay()
{
    if (GetLoad() == 1 && validity == 0)
    {
        alhp_ = GetAlienHP();
        alatk_ = GetAlienATK();
    }

    cout << "  Alien    ";
    cout << "| Health point :" << alhp_ << "| Attack :" << alatk_;
    saveHP(alhp_);
    saveATK(alatk_);
}

int movement::getalhp_()
{
    return alhp_;
}

int movement::setplusalhp_(int hp)
{
    if (alhp_ < 100)
    {
        alhp_ = alhp_ + hp;
    }
    return alhp_;
}

int movement::setminusalhp_(int hp)
{
    alhp_ = alhp_ - hp;
    if (alhp_ <= 0)
    {
        alhp_ = 0;
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

void movement::chkAlien_hp()
{
    if (getalhp_() == 0)
    {
        gameover();
        playagain();
    }
}

void movement::chkZomB_hp()
{
    int number = getZomB();
    int k = 0;
    for (int i = 0; i < number; i++)
    {
        int chkHP = getZHP(i);
        if (chkHP == 0)
        {
            k++;
        }
    }
    if (k == number) // means all zombies' hp is 0
    {
        winGame();
        playagain();
    }
}

//====================================================
// Gui
// Alien turn
void movement::Alienturn()
{
    int no = getZomB();
    alienturndisplay();
    zomdisplay(no);
}

void movement::Aldisplayupdate()
{
    display();
    Alienturn();
    Pause();
}

// Zombie turn
void movement::Zombieturn(int num)
{
    int no = getZomB();
    aliendisplay();
    zomturndisplay(no, num);
}

void movement::Zomdisplayupdate(int num)
{
    display();
    Zombieturn(num);
    Pause();
}
//====================================================
// Alien movement function
void movement::move_up()
{

    int y = getDimY() - 1; // 3 - 1 = 2,
    char trail[] = {'.'};
    int AlX = AlienX_;
    for (int i = AlienY_; i > 0; --i) // 2 - 1 = 1
    {
        int temp = i;
        setmap(temp, AlienX_, trail[0]);
        char obj = getObject(temp - 1, AlienX_);
        if (obj == 'h') // Health (+20 health to Alien)
        {
            cout << "Gained 20 Health." << endl;
            Pause();
            getalhp_();
            setplusalhp_(20);
            AlienY_ = i - 1;     // good
            setalienY_(AlienY_); // good
        }
        else if (obj == 'v') // move down by 1 and stop
        {
            cout << "Alien finds an arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl;
            Pause();
            setalatk_(20);
            AlienY_ = i - 1;
            setalienY_(AlienY_);
            setmap(AlienY_, AlienX_, 'A');
            Aldisplayupdate();
            move_down();
            break;
        }
        else if (obj == '^') // move up by 1 and stop
        {
            cout << "Alien finds an arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl;
            Pause();
            setalatk_(20);
            AlienY_ = i - 1;
            setalienY_(AlienY_);
        }
        else if (obj == '<') // move to the left by 1 and stop
        {
            cout << "Alien finds an arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl;
            Pause();
            setalatk_(20);
            AlienY_ = i - 1;
            setalienY_(AlienY_);
            setmap(AlienY_, AlienX_, 'A');
            Aldisplayupdate();
            move_left();
            break;
        }
        else if (obj == '>') // move to the right by 1 and stop
        {
            cout << "Alien finds an arrow." << endl;
            cout << "Alien's attack is increased by 20." << endl;
            Pause();
            setalatk_(20);
            AlienY_ = i - 1;
            setalienY_(AlienY_);
            setmap(AlienY_, AlienX_, 'A');
            Aldisplayupdate();
            move_right();
            break;
        }
        else if (obj == 'p') // attack nearby Zombie
        {
            cout << "Pod detected, searching Zombie to attack." << endl;
            Pause();
            int podY = temp - 1;
            int podX = AlienX_;
            podatk(podY, podX);
            cout << "Zombie received 10 damage." << endl;
            Pause();
            AlienY_ = i - 1;     // good
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
            Pause();
            Alienattack(obj);
            Pause();
            char obj2 = getObject(temp - 1, AlienX_);
            if (obj2 == ' ')
            {
                AlienY_ = i - 1;
                setalienY_(AlienY_);
            }
            else
            {
                AlienY_ = i;
                setalienY_(AlienY_);
                i = 0;
            }
        }
        else
        {
            cout << "Alien finds an empty space." << endl;
            Pause();
            AlienY_ = i - 1;
            setalienY_(AlienY_);
        }
        setmap(AlienY_, AlienX_, 'A');
        Aldisplayupdate();
    }
    ranobjupdate();
    display();
    resetatk_();
    Alienturn();
    saveHP(alhp_);
    saveATK(alatk_);
    chkAlien_hp();
    chkZomB_hp();
}

void movement::move_down()
{
    int y = getDimY() - 1; // 3 -1 = 2 , Alien = 1
    char trail[] = {'.'};
    int AlX = AlienX_;
    for (int i = AlienY_; i < y; ++i)
    {
        int temp = i;
        setmap(temp, AlienX_, trail[0]);
        char obj = getObject(temp + 1, AlienX_);
        if (obj == 'h')
        {
            cout << "Gained 20 Health." << endl;
            Pause();
            getalhp_();
            setplusalhp_(20);
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
            Aldisplayupdate();
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
            Aldisplayupdate();
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
            Aldisplayupdate();
            move_right();
            break;
        }
        else if (obj == 'p') // attack nearby Zombie
        {
            cout << "Pod detected, searching Zombie to attack." << endl;
            Pause();
            int podY = temp + 1;
            int podX = AlienX_;
            podatk(podY, podX);
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
            Pause();
            Alienattack(obj);
            Pause();
            char obj2 = getObject(temp + 1, AlienX_);
            if (obj2 == ' ')
            {
                AlienY_ = i + 1;
                setalienY_(AlienY_);
            }
            else
            {
                AlienY_ = i;
                setalienY_(AlienY_);
                i = y;
            }
        }
        else
        {
            cout << "Alien finds an empty space." << endl;
            Pause();
            AlienY_ = i + 1;
            setalienY_(AlienY_);
        }
        setmap(AlienY_, AlienX_, 'A');
        Aldisplayupdate();
    }
    ranobjupdate();
    display();
    resetatk_();
    Alienturn();
    saveHP(alhp_);
    saveATK(alatk_);
    chkAlien_hp();
    chkZomB_hp();
}

void movement::move_left()
{
    int x = getDimX() - 1; // 9 - 1 = 8,
    char trail[] = {'.'};
    int AlY = AlienY_;
    for (int i = AlienX_; i > 0; --i) // 8 - 4 = 4
    {
        int temp = i;
        setmap(AlienY_, temp, trail[0]);
        char obj = getObject(AlienY_, temp - 1);
        if (obj == 'h') // Health (+20 health to Alien)
        {
            cout << "Gained 20 Health." << endl;
            Pause();
            getalhp_();
            setplusalhp_(20);
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
            Aldisplayupdate();
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
            Aldisplayupdate();
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
            setalatk_(20);
            AlienX_ = i - 1;
            setalienX_(AlienX_);
            setmap(AlienY_, AlienX_, 'A');
            Aldisplayupdate();
            move_right();
            break;
        }
        else if (obj == 'p') // attack nearby Zombie
        {
            cout << "Pod detected, searching Zombie to Attack" << endl;
            Pause();
            int podY = AlienY_;
            int podX = temp - 1;
            podatk(podY, podX);
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
            rockobjupdate(AlienY_, temp - 1);
            AlienX_ = i;
            setalienX_(AlienX_);
            i = 0;
        }
        else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
        {
            cout << "Attacking Zombie." << endl;
            Pause();
            Alienattack(obj);
            Pause();
            char obj2 = getObject(AlienY_, temp - 1);
            if (obj2 == ' ')
            {
                AlienX_ = i - 1;
                setalienX_(AlienX_);
            }
            else
            {
                AlienX_ = i;
                setalienX_(AlienX_);
                i = 0;
            }
        }
        else
        {
            cout << "Alien finds an empty space." << endl;
            Pause();
            AlienX_ = i - 1;
            setalienX_(AlienX_);
        }
        setmap(AlienY_, AlienX_, 'A');
        Aldisplayupdate();
    }
    ranobjupdate();
    display();
    resetatk_();
    Alienturn();
    saveHP(alhp_);
    saveATK(alatk_);
    chkAlien_hp();
    chkZomB_hp();
}

void movement::move_right()
{
    int x = getDimX() - 1;
    char trail[] = {'.'};
    int AlY = AlienY_;
    for (int i = AlienX_; i < x; ++i)
    {
        int temp = i;
        setmap(AlienY_, temp, trail[0]);
        char obj = getObject(AlienY_, temp + 1);
        if (obj == 'h') // Health (+20 health to Alien)
        {
            cout << " Gained 20 Health. " << endl;
            Pause();
            getalhp_();
            setplusalhp_(20);
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
            Aldisplayupdate();
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
            Aldisplayupdate();
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
            Aldisplayupdate();
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
            cout << "Pod detected, searching Zombie to attack." << endl;
            Pause();
            int podY = AlienY_;
            int podX = temp + 1;
            podatk(podY, podX);
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
            rockobjupdate(AlienY_, temp + 1);
            AlienX_ = i;
            setalienX_(AlienX_);
            i = x;
        }
        else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
        {
            cout << "Attacking Zombie." << endl;
            Pause();
            Alienattack(obj);
            Pause();
            char obj2 = getObject(AlienY_, temp + 1);
            if (obj2 == ' ')
            {
                AlienX_ = i + 1;
                setalienX_(AlienX_);
            }
            else
            {
                AlienX_ = i;
                setalienX_(AlienX_);
                i = x;
            }
        }
        else
        {
            cout << "Alien finds an empty space." << endl;
            Pause();
            AlienX_ = i + 1;
            setalienX_(AlienX_);
        }
        setmap(AlienY_, AlienX_, 'A');
        Aldisplayupdate();
    }
    ranobjupdate();
    display();
    resetatk_();
    Alienturn();
    saveHP(alhp_);
    saveATK(alatk_);
    chkAlien_hp();
    chkZomB_hp();
}

void movement::move_arrow(int x, int y, string z)
{

    int ary = getDimY() - y;
    int arx = x - 1;
    string dir = z;
    Pause();
    if (dir.compare("up") == 0)
    {
        setarrow(ary, arx, '^');
        display();
        Alienturn();
    }
    else if (dir.compare("down") == 0)
    {
        setarrow(ary, arx, 'v');
        display();
        Alienturn();
    }
    else if (dir.compare("left") == 0)
    {
        setarrow(ary, arx, '<');
        display();
        Alienturn();
    }
    else if (dir.compare("right") == 0)
    {
        setarrow(ary, arx, '>');
        display();
        Alienturn();
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
        float DisTemp = pow(DisY, 2) + pow(DisX, 2);
        float Distance = llrint(sqrt(DisTemp));
        int Zhp = getZHP(i);
        int Zatk = getZATK(i);
        int Zrng = getZRNG(i);

        int ZtoAY = abs(DisY);
        int ZtoAX = abs(DisX);
        display();
        Zombieturn(i);
        cout << "  Zombie " << i + 1 << " is making a move." << endl;
        Pause();
        if (Distance <= Zrng)
        {
            int dmg = Zatk;
            setminusalhp_(dmg);
            cout << "Alien in range" << endl;
            Pause();
            cout << "Alien take " << Zatk << " damage from zombie " << i + 1 << endl;
            Pause();
            cout << "Zombie recover " << Zatk << " Health from attacking Alien " << endl;
            Zhp = Zhp + Zatk;
            setZomHP(i, Zhp);
            Zomdisplayupdate(i);
            if (alhp_ == 0)
            {
                cout << " Alien health have reached " << alhp_ << endl;
                Pause();
                cout << " Alien is struggling to live..... " << endl;
                Pause();
                cout << " Alien was eaten by Zombies " << endl;
                Pause();
                Zomdisplayupdate(i);
            }
            else
            {
                cout << " Alien health have reached " << alhp_ << endl;
                Pause();
                cout << " Alien survive the attack " << endl;
                Pause();
                Zomdisplayupdate(i);

            }
        }
        else if (ZtoAX > ZtoAY)
        {
            cout << "  Zombie " << i + 1 << " cannot find Alien in range." << endl;
            Pause();
            cout << "  Zombie " << i + 1 << " is moving towards Alien." << endl;
            Pause();
            if (DisX < 0)
            {
                // zomright
                char obj = getObject(Zy, Zx + 1);
                if (obj == 'h') // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    setmap(Zy, Zx, ' ');
                    Zx = Zx + 1;
                    setZomX(i, Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
                }
                else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
                {
                    cout << "Other Zombie in the way." << endl; 
                    Pause();
                    cout << " Zombie " << i+1 << " cannot move." << endl; 
                    Pause();
                    Zomdisplayupdate(i);
                }
                else
                {
                    setmap(Zy, Zx, ' ');
                    Zx = Zx + 1;
                    setZomX(i, Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
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
                    setmap(Zy, Zx, ' ');
                    Zx = Zx - 1;
                    setZomX(i, Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
                }
                else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
                {
                    cout << "Other Zombie in the way." << endl; 
                    Pause();
                    cout << " Zombie " << i+1 << " cannot move." << endl; 
                    Pause();
                    Zomdisplayupdate(i);
                }
                else
                {
                    setmap(Zy, Zx, ' ');
                    Zx = Zx - 1;
                    setZomX(i, Zx);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
                }
            }
        }
        else
        {
            cout << "  Zombie " << i + 1 << " cannot find Alien in range." << endl;
            Pause();
            cout << "  Zombie " << i + 1 << " is moving towards Alien." << endl;
            Pause();
            if (DisY < 0)
            {
                // zomdown
                char obj = getObject(Zy + 1, Zx);
                if (obj == 'h') // Health (+20 health to Alien)
                {
                    cout << " Zombie Gained 20 Health " << endl;
                    Pause();
                    Zhp = Zhp + 20;
                    setZomHP(i, Zhp);
                    setmap(Zy, Zx, ' ');
                    Zy = Zy + 1;
                    setZomY(i, Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
                }
                else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
                {
                    cout << "Other Zombie in the way." << endl; 
                    Pause();
                    cout << " Zombie " << i+1 << " cannot move." << endl; 
                    Pause();
                    Zomdisplayupdate(i);
                }
                else
                {
                    setmap(Zy, Zx, ' ');
                    Zy = Zy + 1;
                    setZomY(i, Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
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
                    setmap(Zy, Zx, ' ');
                    Zy = Zy - 1;
                    setZomY(i, Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
                }
                else if (obj == '1' || obj == '2' || obj == '3' || obj == '4' || obj == '5' || obj == '6' || obj == '7' || obj == '8' || obj == '9')
                {
                    cout << "Other Zombie in the way." << endl; 
                    Pause();
                    cout << " Zombie " << i+1 << " cannot move." << endl; 
                    Pause();
                    Zomdisplayupdate(i);
                }
                else
                {
                    setmap(Zy, Zx, ' ');
                    Zy = Zy - 1;
                    setZomY(i, Zy);
                    setmap(Zy, Zx, Zombody[i]);
                    Zomdisplayupdate(i);
                }
            }
        }
    }
    Aldisplayupdate();
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
        float DisTemp = pow(DisY, 2) + pow(DisX, 2);
        float Distance = llrint(sqrt(DisTemp));
        Dispod[i] = Distance;
    }
    int near = Dispod[0];
    int zomnum = 0;
    for (int i = 0; i < no; ++i)
    {
        if (Dispod[i] < near)
        {
            near = Dispod[i];
            zomnum = i;
        }
    }
    int Zhp = getZHP(zomnum); // problem
    Zhp = Zhp - 10;
    setZomHP(zomnum, Zhp);
    chkZomB_hp();
}

void movement::subalatk(int num)
{
    int Zy_ = getZomY(num);
    int Zx_ = getZomX(num);

    int ZomHp_ = getZHP(num);
    int Alatk_ = getalatk_();
    ZomHp_ = ZomHp_ - Alatk_;
    cout << " Alien, attack Zombie " << num + 1 << " with " << Alatk_ << " damage. " << endl;
    Pause();
    if (ZomHp_ <= 0)
    {
        ZomHp_ = 0;
        setZomHP(num, ZomHp_);
        setmap(Zy_, Zx_, ' ');
        Aldisplayupdate();
        cout << " Zombie " << num + 1 << ", defeated." << endl;
        Pause();
        chkZomB_hp();
    }
    else
    {
        setZomHP(num, ZomHp_);
        Aldisplayupdate();
        cout << " Checking whether Zombie " << num + 1 << " is still alive." << endl;
        Pause();
        cout << " Zombie " << num + 1 << " is alive." << endl;
        Pause();
        chkZomB_hp();
    }
}

void movement::Alienattack(char obj)
{
    if (obj == '1')
    {
        int num = 0;
        subalatk(num);
    }
    else if (obj == '2')
    {
        int num = 1;
        subalatk(num);
    }
    else if (obj == '3')
    {
        int num = 2;
        subalatk(num);
    }
    else if (obj == '4')
    {
        int num = 3;
        subalatk(num);
    }
    else if (obj == '5')
    {
        int num = 4;
        subalatk(num);
    }
    else if (obj == '6')
    {
        int num = 5;
        subalatk(num);
    }
    else if (obj == '7')
    {
        int num = 6;
        subalatk(num);
    }
    else if (obj == '8')
    {
        int num = 7;
        subalatk(num);
    }
    else if (obj == '9')
    {
        int num = 8;
        subalatk(num);
    }
}


