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
         
    void getMenu(); // Afiq
    void controls(); // Afiq
    void help(); // Afiq
    void gameover(); // Afiq
    void playmenu(); // Afiq
    char randObject(char x);
    void changesetting(); // liEn
    void Board(); // liEn
    void alienstat(); // Afiq 
    void zomdisplay(int no);
    void play();


        void init(int dimX, int dimY, int zomb); // liEn 
        void display(); // liEn & Afiq (from tutorial)
        int setDimX(int x); // liEn 
        int setDimY(int y); // liEn 
        int setZomB(int z); // liEn 
        std::vector<std::vector<char>> setmap(int y, int x, char obj);

        int getDimX();  // Afiq 
        int getDimY();  // Afiq 
        int getZomB();  // liEn 
        // char getObject(int dimX, int dimY);  // Afiq 

    int *getZomHP(int num);
    int *getZomAtk(int numZom);
    int *getZomRge(int numofZ);
    int fileExist();
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

class movement 
{
    public:
        int AlienX_;
        int AlienY_;

        int setalienX_(int x);
        int setalienY_(int y);
        int getalienX_() const;
        int getalienY_() const;

        void move_up();
        void move_down();
        void move_left();
        void move_right();
        void move_arrow();
        void get_arrow();

};

//Class-----------------------------------------------------------------------------------------

#endif
