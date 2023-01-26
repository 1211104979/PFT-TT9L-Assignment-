// **************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year  : Trimester 1, 2022/23 (T2215) 
// Lab   : TT9L 
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN  
// IDs   : 1211104335                    | 1211104979 
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my 
// Phones: 011-1026 0985                 | 011-3174 2235 
// **************************************************************************

//Afiq--------------------------------------------------------------------
#include "MainHeader.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> // for system() 
#include <ctime> // for time() in srand( time(NULL) ); 
#include <iomanip> // for setw() 
#include <conio.h>

int Zombie::hpgen(int* hp) // Health point for zombies
{
    int ranhp  = rand() % noobj;
    hp_ = hp[ranhp];
    return hp_;
}

int Zombie::atkgen(int* atk) // Attack point for zombies
{
    int ranatk = rand() % noobj;
    atk_ = atk[ranatk];
    return atk_;
}

int Zombie::rnggen(int* rng) // Range for zombies
{
    int ranrng = rand() % noobj;
    rng_ = rng[ranrng];
    return rng_;
}

void Zombie::data() // Shows zombie stats
{
    std::cout << "  Health point :" << hp_ ;
    std::cout << "  Attack :" << atk_ ;
    std::cout << "  Range :" << rng_ << std::endl;
}

void alienstat() // Shows Alien stats
{
    int alhp_ = 100;
    int alatk_ = 0;
    std::cout << " Alien    :";
    std::cout << "  Health point :" << alhp_ ;
    std::cout << "  Attack :" << alatk_ << std::endl;
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
        std::cout << " Zombie " << i+1 << " :"; 
        entity[i].data();
    }

}

//------------------------------------------------------------------------

