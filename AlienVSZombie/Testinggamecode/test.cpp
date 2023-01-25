#include <iostream>

using namespace std;


// class Zombie
// {
// public:
    int hp_;
    int atk_;
    int rng_;

    // Zombie (int hp_, int atk_,int rng_);
    // void d();

// };

// Zombie::Zombie(int hp, int atk,int rng)
// {
//     hp_ = hp;
//     atk_ = atk;
//     rng_ = rng;
// }

void d()
{
    int zomB = 9;
    int hp[3] = {100, 150, 200};
    int atk[3] = {5, 10, 15};
    int rng[3] = {1, 2, 3};
    int noobj = 3;
    for (int i = 0; i < zomB; ++i)
    {
        int ranhp  = rand() % noobj;
        hp_ = hp[ranhp];
        int ranatk = rand() % noobj;
        atk_ = atk[ranhp];
        int ranrng = rand() % noobj;
        rng_ = rng[ranhp];

        cout << " Zombie " << i+1 ; 
        cout << "  Health point :" << hp_ ;
        cout << "  Attack :" << atk_ ;
        cout << "  Range :" << rng_ << endl;

    }
};

int main()
{
    // Zombie Zombie1;
    d();
}
