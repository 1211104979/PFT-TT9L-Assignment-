#pragma once
#include <vector> 
#ifndef MAINHEADER_H
#define MAINHEADER_H

    // Global 
    int ClearScreen();
    int Pause();
         
    void getMenu();
    void instructions();
    void gameover();


class GameBoard 
{ 
private: 
    vector< vector<char> > map_; // convention to put trailing underscore 
    int dimX_, dimY_;            // to indicate private data 
    
public: 
    GameBoard(int dimX = 3, int dimY = 5); 

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