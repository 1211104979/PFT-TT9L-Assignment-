// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN // 
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //
//Afiq--------------------------------------------------------------------
#include "MainHeader.h"
#include <iostream> 

using namespace std;

int Zombie::hpgen(int* hp) // Health point for zombies (pointer for hp array)
{
    int ranhp  = rand() % noobj;
    hp_ = hp[ranhp];
    return hp_;
}

int Zombie::atkgen(int* atk) // Attack point for zombies (pointer for atk array)
{
    int ranatk = rand() % noobj;
    atk_ = atk[ranatk];
    return atk_;
}

int Zombie::rnggen(int* rng) // Range for zombies (pointer for rng array)
{
    int ranrng = rand() % noobj;
    rng_ = rng[ranrng];
    return rng_;
}

void Zombie::data() // Shows zombie stats
{
    cout << "  Health point :" << hp_ ;
    cout << "  Attack :" << atk_ ;
    cout << "  Range :" << rng_ << endl;
}

void alienstat() // Shows Alien stats
{
    int alhp_ = 100;
    int alatk_ = 0;
    cout << " Alien    :";
    cout << "  Health point :" << alhp_ ;
    cout << "  Attack :" << alatk_ << endl;
}

void zombiestat(int no) // show each zombie stats
{
    Zombie entity[9];
    
    int b = no;

    int hp[3] = {100, 150, 200};
    int atk[3] = {5, 10, 15};
    int rng[3] = {1, 2, 3};

    for (int i = 0; i < b; ++i)
    {
        int hp_  = entity[i].hpgen(hp);
        int atk_ = entity[i].atkgen(atk);
        int rng_ = entity[i].rnggen(rng);
    }
    
    for (int i = 0; i < b; ++i)
    {
        cout << " Zombie " << i+1 << " :"; 
        entity[i].data();
    }

}

//------------------------------------------------------------------------

