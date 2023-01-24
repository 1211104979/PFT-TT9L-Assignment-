#include "MainHeader.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> // for system() 
#include <ctime> // for time() in srand( time(NULL) ); 
#include <iomanip> // for setw() 
#include <conio.h>

using namespace std; 


GameBoard::GameBoard(int dimX, int dimY) 
{ 
    init(dimX, dimY); 
} 

void GameBoard::init(int dimX, int dimY)
{ 
    dimX_ = dimX; 
    dimY_ = dimY; 
    
    char objects[] = {'<', '^', '>', 'v', 'h', 'p', 'r', ' ', ' ', ' '}; 
    int noOfObjects = 10; // number of objects in the objects array 
    
    // create dynamic 2D array using vector 
    map_.resize(dimY_); // create empty rows 
    for (int i = 0; i < dimY_; ++i)
    { 
        map_[i].resize(dimX_); // resize each row 
    } 
    
    // put random characters into the vector array 
    for (int i = 0; i < dimY_; ++i) 
    { 
        for (int j = 0; j < dimX_; ++j) 
        { 
            int objNo = rand() % noOfObjects; 
            map_[i][j] = objects[objNo]; 
        } 
    }
    int y = dimY_/2;
    int x = dimX_/2;
    char Alien[] = {"A"};
    map_[y][x] = Alien[0];

    char Zombie[] = {};
}

void GameBoard::display() 
{ 
    // comment this out during testing 
    //system("cls"); // OR system("clear"); for Linux / MacOS 
    cout << " --__--__--__--__--__--__--__--_" << endl; 
    cout << " =       Alien vs Zombie       =" << endl; 
    cout << " __--__--__--__--__--__--__--__-" << endl; 
    
    // for each row 
    for (int i = 0; i < dimY_; ++i) 
    { 
        // display upper border of the row 
        cout << " "; 
        for (int j = 0; j < dimX_; ++j) 
        { 
            cout << "+-"; 
        } 
        cout << "+" << endl; 
        
        // display row number 
        cout << setw(2) << (dimY_ - i); 
        // display cell content and border of each column 
        for (int j = 0; j < dimX_; ++j) 
        { 
            cout << "|" << map_[i][j]; 
        } 
        cout << "|" << endl; 
    } 
    
    // display lower border of the last row 
    cout << " "; 
    for (int j = 0; j < dimX_; ++j) 
    { 
        cout << "+-"; 
    } 
    cout << "+" << endl; 
    
    // display column number 
    cout << " "; 
    for (int j = 0; j < dimX_; ++j) 
    { 
        int digit = (j + 1) / 10; 
        cout << " "; 
        if (digit == 0) 
            cout << " "; 
        else 
            cout << digit; 
    } 
    cout << endl; 
    cout << "  "; 
    for (int j = 0; j < dimX_; ++j) 
    { 
        cout << " " << (j + 1) % 10; 
    } 
    cout << endl << endl; 
}

int GameBoard::setDimX(int x)
{
    dimX_ = x;
    return dimX_;
}

int GameBoard::setDimY(int y)
{
    dimY_ = y;
    return dimY_;
}

int GameBoard::getDimX() const
{
    return dimX_;
}

int GameBoard::getDimY() const
{
    return dimY_; 
}

char GameBoard::getObject(int x, int y) const 
{ 
    return map_[dimY_-y][x-1]; 
}

void changesetting()
{
    GameBoard board;
    int x, y;
    cout << " Enter rows => ";
    cin >> y;
    cout << endl;
    cout << " Enter columns => ";
    cin >> x;
    cout << endl;
    board.setDimX(x);
    board.setDimY(y);
    board.init(x,y);
    board.display();
}

void Board() 
{ 
    GameBoard board; 
    //system("cls");
    board.display();

}
