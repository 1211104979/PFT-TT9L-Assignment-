// ************************************************************************** //
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                   //
// Year  : Trimester 1, 2022/23 (T2215)                                       //
// Lab   : TT9L                                                               //
// Names : CHUA LI EN                    | MUHAMMAD AFIQ IKHWAN BIN AMINUDDIN // 
// IDs   : 1211104335                    | 1211104979                         //
// Emails: 1211104335@student.mmu.edu.my | 1211104979@student.mmu.edu.my      //
// Phones: 011-1026 0985                 | 011-3174 2235                      //
// ************************************************************************** //


// Youtube video : https://youtu.be/_INcX8hO_GQ

// TODO: Fill in the missing information above and delete this line.

//Game Commands 
    //Movement (up, down, left, right)
    //Change direction of arrow (arrow)
    //Display user commands (help)===
    //Save game (save)
    //Load game (load)
    //Quit game (quit)===

//Board setting (must be odd numbers)
    //Board size and config ===
    //Random generated Objects ("h"=health pack, "r"=rock/block, "<"/"^"/">"/"v"= direction pad, " "= empty space)===

//Graphic on board
    //Zombie setting (number of zombie, denoted as int/number)===
    //Alien (denoted as A)===

//Stats
    //Alien stat (Life, Attack)===
    //Zombie stat (Life, Attack, Range)===

//Spawn
    //Alien (position will initially be at the middle)===
    //Zombie (random)===

//Turns
    //Display (who turn it is)

//AI movement program
    //Move towards Alien
    //Attack when in range

#include "Sub/MainHeader.h"
#include <iostream>

using namespace std;

Enemy zombie;

vector<vector<char>> map_; // convention to put trailing underscore
int dimX_ = 9, dimY_ = 3, zomB_ = 1;   // to indicate private data // liEn

char h, x;

void init(int dimX, int dimY, int zomb) // liEn & Afiq (from tutorial)
{
    dimX_ = dimX;
    dimY_ = dimY;
    zomB_ = zomb;

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
			h = randomiseItems(x);
            map_[i][j] = h;
        }
    }

    // put random zombies into the vector array // liEn 
    for (int i = 0; i < zomB_; ++i)
    {
        int randY = rand() % dimY_;
        int randX = rand() % dimX_;
        map_[randY][randX] = zomBie[i];
    }

    int y = dimY_ / 2;
    int x = dimX_ / 2;
    char Alien[] = "A";
    map_[y][x] = Alien[0];

}

void display() // liEn & Afiq (from tutorial)
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " ****************************** " << endl;
    cout << " *    .:'Alien vs Zombie':.   * " << endl;
    cout << " ****************************** " << endl;

    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        std::cout << " ";
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

int setDimX(int x)
{
    dimX_ = x;
    return dimX_;
}

int setDimY(int y)
{
    dimY_ = y;
    return dimY_;
}

vector<vector<char>> setmap(int y, int x, char obj)
{
    map_[y][x] = obj;
    return map_;
}

int setZomB(int z) // liEn -> add new function
{
    zomB_ = z;
    return zomB_;
}

int getDimX() 
{
    return dimX_;
}

int getDimY() 
{
    return dimY_;
}

int getZomB()  // le -> add new function
{
    return zomB_;
}

char getObject(int x, int y) 
{
    return map_[dimY_-y][x-1];
}

void changesetting() // liEn & Afiq
{
    int x, y, z;  // liEn 
    cout << endl; // liEn  -> next line when input 'y/n' entered
    cout << " Enter rows => ";
    cin >> y;
    cout << endl;
    cout << " Enter columns => ";
    cin >> x;
    cout << endl;
    cout << " Zombie Settings " << endl;
    cout << "-----------------" << endl;
    cout << " Enter number of zombies => "; // liEn 
    cin >> z;
    cout << endl;

    if (x % 2 == 0 || y % 2 == 0) // liEn  -> //restriction for only accepting odd numbers and range of zombies within 1 until 9
    {
        cout << "Rows and Columns must be odd numbers.\n\n";
    }

    else
    {
        if (z < 1 || z > 9)
        {
            cout << "Zombies can only within the range of 1 until 9. " << std::endl;
        }

        else
        {  
            setDimX(x);
            setDimY(y);
            setZomB(z); // liEn 
            cout << "z " ;
            cout << z << endl;
            
            init(x, y, z); // liEn
            display(); 
            int no = getZomB(); // Afiq
            alienstat(); // Afiq
			zombie.zombiegen(no); 
			play();
        }
    }
}

void Board()
{
    srand(1);
    display();
    int no = getZomB(); // Afiq
    alienstat(); // Afiq  
	zombie.zombiegen(no); 
	play();
}

void zomdisplay(int no)
{
    int b = no;

    for (int i = 0; i < b; i++)
    {
        cout << '\n' << "  Zombie " << i + 1 << " : Health point " << zombie.ZombHpVec[i] << ", Attack  " << zombie.ZombAtkVec[i] << ", Range " << zombie.ZombRngVec[i];
    }
    cout << endl;
}

int main() 
{
	init(dimX_, dimY_, zomB_);
	getMenu();
}

//execution < g++ Sub\*.cpp main.cpp >