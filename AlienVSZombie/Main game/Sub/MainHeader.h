// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN // 
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //
#include <vector> 

#ifndef MAINHEADER_H
#define MAINHEADER_H

// Global--------------------------------------------------------------------------------------- 
    int ClearScreen(); // (from tutorial)
    int Pause(); // (from tutorial)
         
    void getMenu(); // Afiq
    void controls(); // Afiq
    void help(); // Afiq
    void gameover(); // Afiq
    void playmenu(); // Afiq
    void changesetting(); // liEn
    void Board(); // liEn
    void zombiestat(int no); // Afiq 
    void alienstat(); // Afiq 

    void defplay();
    void play();
// Global---------------------------------------------------------------------------------------

//Class-----------------------------------------------------------------------------------------
class GameBoard // liEn & Afiq (from tutorial)
{
    private:
        std::vector<std::vector<char>> map_; // convention to put trailing underscore
        int dimX_, dimY_;   // to indicate private data // liEn 

    public:
        int zomB_; // Afiq 
        char Alien_;

        GameBoard(int dimX = 9, int dimY = 3, int zomb = 1); // liEn 

        void init(int dimX, int dimY, int zomb); // liEn 
        void display(); // liEn & Afiq (from tutorial)
        //void settings(); // liEn & Afiq (from tutorial)
        int setDimX(int x); // liEn 
        int setDimY(int y); // liEn 
        int setZomB(int z); // liEn 

        int getDimX() const; // Afiq 
        int getDimY() const; // Afiq 
        int getZomB() const; // liEn 
        char getAlien(int dimY_, int dimX_);
        char getObject(int dimX, int dimY) const; // Afiq 
};

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
//Class-----------------------------------------------------------------------------------------

#endif