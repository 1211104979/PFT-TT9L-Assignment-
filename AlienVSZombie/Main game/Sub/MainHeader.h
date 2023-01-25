#include <vector> 
#ifndef MAINHEADER_H
#define MAINHEADER_H

using namespace std;

    // Global 
    int ClearScreen();
    int Pause();
         
    void getMenu();
    void instructions();
    void gameover();
    void playmenu();
    void changesetting();
    void Board();
    void zombiestat();

class GameBoard
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;   // to indicate private data //le

public:
    int zomB_;

    GameBoard(int dimX = 9, int dimY = 3, int zomb = 1); // le

    void init(int dimX, int dimY, int zomb); // le
    void display();
    void settings();
    int setDimX(int x);
    int setDimY(int y);
    int setZomB(int z); // le

    int getDimX() const;
    int getDimY() const;
    int getZomB() const; // le

    char getObject(int dimX, int dimY) const;
};

class Zombie : public GameBoard
{
    public:
        int hp_;
        int atk_;
        int rng_;
        // int hp[3] = {100, 150, 200};
        // int atk[3] = {5, 10, 15};
        // int rng[3] = {1, 2, 3};
        int noobj = 3;

        void data();
        int hpgen(int* hp); 
        int atkgen(int* atk);
        int rnggen(int* rng);
};

#endif