#include "MainHeader.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> // for system() 
#include <ctime> // for time() in srand( time(NULL) ); 
#include <iomanip> // for setw() 
#include <conio.h>

using namespace std; 

Zombie::Zombie(int hp, int atk, int rng)
{
    hp_  = hp;
    atk_ = atk;
    rng_ = rng;
}


Zombie zombie1 = Zombie(100, 15, 2);
Zombie zombie2 = Zombie(200, 5, 1);
Zombie zombie3 = Zombie(150, 10, 3);


// zombie stat
// hp[3] = {100, 150, 200}
// atk[3] = {5, 10, 15}
// rng[3] = {1, 2, 3}
// noobj = 3
// for (int i = 0; i < zomB; ++i)
//     {
//          ranhp  = rand() % noobj;
//          hp_ = hp[ranhp]
//          ranatk = rand() % noobj;
//          atk_ = atk[ranhp]
//          ranrng = rand() % noobj;
//          rng_ = rng[ranhp]
//     }

