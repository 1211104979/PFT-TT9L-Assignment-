// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN // 
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cfenv>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()

#ifndef MAINHEADER_H
#define MAINHEADER_H

using namespace std;
// Global--------------------------------------------------------------------------------------- 

    
    int ClearScreen(); // (from tutorial)
    int Pause(); // (from tutorial)
    // int move_up();

    extern vector<vector<char>> map_;
    extern vector<int> ZomY_;
    extern vector<int> ZomX_;
    extern vector<vector<int>> ZB_atrr;
    void emptymap(int dX, int dY);
    void emptyZomvec(int Zom);
    void getMenu(); // Afiq
    void controls(); // Afiq
    void help(); // Afiq
    void gameover(); // Afiq
    void playmenu(); // Afiq
    char randObject(char x);
    char refreshObj(char x);
    void ranobjupdate();
    void rockobjupdate(int y, int x);
    void changesetting(); // liEn
    void Board(); // liEn
    void zomdisplay(int no);
    void zomturndisplay(int no, int num);
    void play();


        void init(int dimX, int dimY, int zomb); // liEn 
        void display(); // liEn & Afiq (from tutorial)
        int setDimX(int x); // liEn 
        int setDimY(int y); // liEn 
        int setZomB(int z); // liEn 
        int setZomY(int num, int newnum);
        int setZomX(int num, int newnum);
        void setZomHP(int num, int Zhp);

        std::vector<std::vector<char>> setmap(int y, int x, char obj);

        int getDimX();  // Afiq 
        int getDimY();  // Afiq 
        int getZomB();  // liEn 
        int getZomY(int num);
        int getZomX(int num);
        int getZHP(int num);
        int getZATK(int num);
        int getZRNG(int num);
        char getObject(int dimX, int dimY);  // Afiq 

    int *getZomHP(int num);
    int *getZomAtk(int numZom);
    int *getZomRge(int numofZ);
    int fileExist();
    void loadmap();
    int GetLoad();
    int GetAlienX();
    int GetAlienY();
    int GetAlienHP();
    int GetAlienATK();
    void saveHP(int hp);
    void saveATK(int atk);
// Global---------------------------------------------------------------------------------------
//Class-----------------------------------------------------------------------------------------

class Enemy // Afiq 
{
    public:
        vector<int> ZHpVec;
        vector<int> ZAtkVec;     
        vector<int> ZRngVec;
        void zombiegen(int no);

};

class movement : public Enemy
{
    public:
        int alhp_ = 100;
        int alatk_ = 0;
        int AlienX_;
        int AlienY_;
        vector<int> zomXVec;
        vector<int> zomYVec;

        void Alienturn();
        void Zombieturn(int num);
        void alienturndisplay();
        void aliendisplay();
        int getalhp_();
        int setplusalhp_(int hp);
        int setminusalhp_(int hp);
        int getalatk_();
        int setalatk_(int atk);
        int resetatk_();
        void podatk(int podY, int podX);
        void subalatk(int num);
        void Alienattack(char obj);

        int setalienX_(int x);
        int setalienY_(int y);
        int getalienX_() const;
        int getalienY_() const;

        void move_up();
        void move_down();
        void move_left();
        void move_right();
        void move_arrow(int y, int x, string z);
        void zommove();
};

//Class-----------------------------------------------------------------------------------------

#endif
