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

void alienstat() // Shows Alien stats
{
    int alhp_ = 100;
    int alatk_ = 0;
    cout << "  Alien    :";
    cout << "  Health point " << alhp_ ;
    cout << ", Attack :" << alatk_ << endl;
}

void Enemy::zombiegen(int no)
{
    int b = no;

    for (int i = 0; i < b; i++)
    {
        int randhp = rand() % 2 + 1;
        int randatk = rand() % 2 + 1;
        int randrng = rand() % 5 + 1;
        int ZombieHp = 100 + (randhp * 50);
        int ZombieAtk = 5 + (randatk  * 5);
        int ZombieRange = randrng ;
        ZombHpVec.push_back(ZombieHp);
        ZombAtkVec.push_back(ZombieAtk);
        ZombRngVec.push_back(ZombieRange);
        std::cout << '\n' << "  Zombie " << i + 1 << " : Health point " << ZombieHp << ", Attack  " << ZombieAtk << ", Range " << ZombieRange;
        cout << endl;
    }
}


//------------------------------------------------------------------------

