#pragma once
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
void changesetting(); // liEn 
void Board(); // liEn 

class GameBoard // liEn & Afiq (from tutorial)
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_, zomB_;   // to indicate private data //liEn

public:
    GameBoard(int dimX = 9, int dimY = 3, int zomb = 1); // liEn

    void init(int dimX, int dimY, int zomb); // liEn
    void display(); // liEn & Afiq (from tutorial)
    void settings(); // liEn & Afiq (from tutorial)
    int setDimX(int x); // liEn (from tutorial)
    int setDimY(int y); // liEn (from tutorial)
    int setZomB(int z); // liEn

    int getDimX() const; // Afiq (from tutorial)
    int getDimY() const; // Afiq (from tutorial)
    int getZomB() const; // liEn

    char getObject(int dimX, int dimY) const; // liEn & Afiq (from tutorial)
};

#endif