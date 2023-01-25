#include <vector> 
#ifndef MAINHEADER_H
#define MAINHEADER_H

using namespace std;

    // Global 
    int ClearScreen(); // (from tutorial)
    int Pause(); // (from tutorial)
         
    void getMenu(); // Afiq
    void instructions(); // Afiq
    void gameover(); // Afiq
    void playmenu(); // Afiq
    void changesetting(); // liEn
    void Board(); // liEn
    void zombiestat(int no); // Afiq 
    void alienstat(); // Afiq 

class GameBoard // liEn & Afiq (from tutorial)
{
    private:
        vector<vector<char>> map_; // convention to put trailing underscore
        int dimX_, dimY_;   // to indicate private data // liEn 

    public:
        int zomB_; // Afiq 

        GameBoard(int dimX = 9, int dimY = 3, int zomb = 1); // liEn 

        void init(int dimX, int dimY, int zomb); // liEn 
        void display(); // liEn & Afiq (from tutorial)
        void settings(); // liEn & Afiq (from tutorial)
        int setDimX(int x); // liEn 
        int setDimY(int y); // liEn 
        int setZomB(int z); // liEn 

        int getDimX() const; // Afiq 
        int getDimY() const; // Afiq 
        int getZomB() const; // liEn 

        char getObject(int dimX, int dimY) const; // Afiq 
}
class Zombie : public GameBoard // Afiq 
{
    public:
        int hp_; // Afiq 
        int atk_; // Afiq 
        int rng_; // Afiq 
        int noobj = 3; // Afiq 

        void data(); // Afiq 
        int hpgen(int* hp); // Afiq 
        int atkgen(int* atk); // Afiq 
        int rnggen(int* rng); // Afiq 
};

#endif