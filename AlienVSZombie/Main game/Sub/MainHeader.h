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
    void changesetting();
    void Board();

class GameBoard 
{ 
private: 
    vector< vector<char> > map_; // convention to put trailing underscore 
    int dimX_, dimY_;            // to indicate private data 
    
public: 
    GameBoard(int dimX = 9, int dimY = 3); 

    void init(int dimX, int dimY); 
    void display() ; 
    void settings();
    int setDimX(int x);
    int setDimY(int y);

    int getDimX() const;
    int getDimY() const;

    char getObject(int dimX, int dimY) const;
}; 


#endif