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

void Enemy::zombiegen(int no)
{
    int b = no;

    for (int i = 0; i < b; i++)
    {
        int randhp = rand() % 2 + 1;
        int randatk = rand() % 2 + 1;
        int randrng = rand() % 4 + 1;
        int ZHp = 100 + (randhp * 50);
        int ZAtk = 5 + (randatk  * 5);
        int ZRng = randrng ;
        ZHpVec.push_back(ZHp);
        ZAtkVec.push_back(ZAtk);
        ZRngVec.push_back(ZRng);
        cout << '\n' << "  Zombie " << i + 1 << " | Health point :" << ZHp << "| Attack :" << ZAtk << "| Range :" << ZRng;
    }
    cout << endl;
}


//------------------------------------------------------------------------

