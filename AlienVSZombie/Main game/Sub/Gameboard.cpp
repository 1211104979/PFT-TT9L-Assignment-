#include "MainHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include <conio.h>

using namespace std;

GameBoard::GameBoard(int dimX, int dimY, int zomb)
{
    init(dimX, dimY, zomb);
}

void GameBoard::init(int dimX, int dimY, int zomb = 1)
{
    dimX_ = dimX;
    dimY_ = dimY;
    zomB_ = zomb;

    char objects[] = {'<', '^', '>', 'v', 'h', 'p', 'r', ' ', ' ', ' '};
    char zomBie[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // le
    int noOfObjects = 10;                                          // number of objects in the objects array

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

    // put random zombies into the vector array // le
    for (int i = 0; i < zomB_; ++i)
    {

        int randY = rand() % dimY_;
        int randX = rand() % dimX_;
        map_[randY][randX] = zomBie[i];
    }

    int y = dimY_ / 2;
    int x = dimX_ / 2;
    char Alien[] = {"A"};
    map_[y][x] = Alien[0];

    char Zombie[] = {};
}

void GameBoard::display()
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
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
    cout << endl
         << endl;
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

int GameBoard::setZomB(int z) // le -> add new function
{
    zomB_ = z;
    return zomB_;
}

int GameBoard::getDimX() const
{
    return dimX_;
}

int GameBoard::getDimY() const
{
    return dimY_;
}

int GameBoard ::getZomB() const // le -> add new function
{
    return zomB_;
}

char GameBoard::getObject(int x, int y) const
{
    return map_[dimY_ - y][x - 1];
}

void changesetting()
{
    GameBoard board;
    int x, y, z;  // le
    cout << endl; // le -> next line when input 'y/n' entered
    cout << " Enter rows => ";
    cin >> y;
    cout << endl;
    cout << " Enter columns => ";
    cin >> x;
    cout << endl;
    cout << " Enter zombies => "; // le
    cin >> z;
    cout << endl;

    if (x % 2 == 0 || y % 2 == 0) // le -> //restriction for only accepting odd numbers and range of zombies within 1 until 9
    {
        cout << "Rows and Columns must be odd numbers.\n\n";
    }

    else
    {
        if (z < 1 || z > 9)
        {
            cout << "Zombies can only within the range of 1 until 9. " << endl;
        }

        else
        {
            board.setDimX(x);
            board.setDimY(y);
            board.setZomB(z); // le

            board.init(x, y, z); // le
            board.display();
        }
    }
}

void Board()
{
    GameBoard board;
    // system("cls");
    board.display();
}

int main()
{
    Board();
}