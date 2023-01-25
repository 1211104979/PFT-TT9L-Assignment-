#include "MainHeader.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> // for system() 
#include <ctime> // for time() in srand( time(NULL) ); 
#include <iomanip> // for setw() 
#include <conio.h>

using namespace std; 

int Zombie::hpgen(int* hp)
{
    int ranhp  = rand() % noobj;
    hp_ = hp[ranhp];
    return hp_;
}

int Zombie::atkgen(int* atk)
{
    int ranatk = rand() % noobj;
    atk_ = atk[ranatk];
    return atk_;
}

int Zombie::rnggen(int* rng)
{
    int ranrng = rand() % noobj;
    rng_ = rng[ranrng];
    return rng_;
}

void Zombie::data()
{
    cout << "  Health point :" << hp_ ;
    cout << "  Attack :" << atk_ ;
    cout << "  Range :" << rng_ << endl;
}

int main()
{
    //GameBoard zombie;
    int b = 4;//zombie.getZomB();
    Zombie entity[9];

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
        cout << " Zombie " << i+1; 
        entity[i].data();
    }

}


