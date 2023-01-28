// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN // 
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //

#include "MainHeader.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()

using namespace std;

GameBoard::GameBoard(int dimX, int dimY, int zomb) // liEn & Afiq (from tutorial)
{
    init(dimX, dimY, zomb);
}

void GameBoard::init(int dimX, int dimY, int zomb) // liEn & Afiq (from tutorial)
{
    dimX_ = dimX;
    dimY_ = dimY;
    zomB_ = zomb;

    char objects[] = {'<', '^', '>', 'v', 'h', 'p', 'r', ' ', ' ', ' '};
    char zomBie[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // liEn 
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

    // put random zombies into the vector array // liEn 
    for (int i = 0; i < zomB_; ++i)
    {

        int randY = rand() % dimY_;
        int randX = rand() % dimX_;
        map_[randY][randX] = zomBie[i];
    }
    // initzombie();

    int y = dimY_ / 2;
    int x = dimX_ / 2;
    // initalien(y, x);
    char Alien[] = "A";
    map_[y][x] = Alien[0];

}

void GameBoard::display() // liEn & Afiq (from tutorial)
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    std::cout << " --__--__--__--__--__--__--__--_" << std::endl;
    std::cout << " =       Alien vs Zombie       =" << std::endl;
    std::cout << " __--__--__--__--__--__--__--__-" << std::endl;

    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        std::cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            std::cout << "+-";
        }
        std::cout << "+" << std::endl;

        // display row number
        std::cout << std::setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            std::cout << "|" << map_[i][j];
        }
        std::cout << "|" << std::endl;
    }

    // display lower border of the last row
    std::cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        std::cout << "+-";
    }
    std::cout << "+" << std::endl;

    // display column number
    std::cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        std::cout << " ";
        if (digit == 0)
            std::cout << " ";
        else
            std::cout << digit;
    }
    std::cout << std::endl;
    std::cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        std::cout << " " << (j + 1) % 10;
    }
    std::cout << std::endl
         << std::endl;
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

std::vector<std::vector<char>> GameBoard::setmap(int y, int x, char obj)
{
    map_[y][x] = obj;
    return map_;
}

int GameBoard::setZomB(int z) // liEn -> add new function
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
    return map_[dimY_-y][x-1];
}

void changesetting() // liEn & Afiq
{
    GameBoard board;
    int x, y, z;  // liEn 
    std::cout << std::endl; // liEn  -> next line when input 'y/n' entered
    std::cout << " Enter rows => ";
    std::cin >> y;
    std::cout << std::endl;
    std::cout << " Enter columns => ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << " Zombie Settings " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << " Enter number of zombies => "; // liEn 
    std::cin >> z;
    std::cout << std::endl;

    if (x % 2 == 0 || y % 2 == 0) // liEn  -> //restriction for only accepting odd numbers and range of zombies within 1 until 9
    {
        std::cout << "Rows and Columns must be odd numbers.\n\n";
    }

    else
    {
        if (z < 1 || z > 9)
        {
            std::cout << "Zombies can only within the range of 1 until 9. " << std::endl;
        }

        else
        {   GameBoard board2 = GameBoard(x, y, z);
            board2.setDimX(x);
            board2.setDimY(y);
            board2.setZomB(z); // liEn 
            std::cout << "z " ;
            std::cout << z << std::endl;
            
            board2.init(x, y, z); // liEn
            board2.display(); 
            int no = board.getZomB(); // Afiq
            alienstat(); // Afiq
            zombiestat(no); // Afiq
        }
    }
}

void Board()
{
    GameBoard board;
    srand(1);
    board.display();
    int no = board.getZomB(); // Afiq
    alienstat(); // Afiq   
    zombiestat(no); // Afiq
}

